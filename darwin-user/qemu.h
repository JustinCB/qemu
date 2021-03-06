#ifndef GEMU_H
#define GEMU_H

#include <signal.h>
#include <string.h>

#ifndef SA_DISABLE
#define SA_DISABLE SS_DISABLE
#endif

#ifndef SA_ONSTACK
#define SA_ONSTACK SS_ONSTACK
#endif



extern unsigned long last_brk;



#include "cpu.h"

#include "thunk.h"

#include "gdbstub.h"

typedef siginfo_t target_siginfo_t;
#define target_sigaction	sigaction
#ifdef TARGET_I386
struct target_pt_regs {
	long ebx;
	long ecx;
	long edx;
	long esi;
	long edi;
	long ebp;
	long eax;
	int  xds;
	int  xes;
	long orig_eax;
	long eip;
	int  xcs;
	long eflags;
	long esp;
	int  xss;
};
struct	target_sigcontext {
    int			sc_onstack;
    int			sc_mask;
    int	sc_eax;
    int	sc_ebx;
    int	sc_ecx;
    int	sc_edx;
    int	sc_edi;
    int	sc_esi;
    int	sc_ebp;
    int	sc_esp;
    int	sc_ss;
    int	sc_eflags;
    int	sc_eip;
    int	sc_cs;
    int	sc_ds;
    int	sc_es;
    int	sc_fs;
    int	sc_gs;
};

#define __USER_CS	(0x17)
#define __USER_DS	(0x1F)

#elif defined(TARGET_PPC)
struct target_pt_regs {
	unsigned long gpr[32];
	unsigned long nip;
	unsigned long msr;
	unsigned long orig_gpr3;	/* Used for restarting system calls */
	unsigned long ctr;
	unsigned long link;
	unsigned long xer;
	unsigned long ccr;
	unsigned long mq;		/* 601 only (not used at present) */
					/* Used on APUS to hold IPL value. */
	unsigned long trap;		/* Reason for being here */
	unsigned long dar;		/* Fault registers */
	unsigned long dsisr;
	unsigned long result; 		/* Result of a system call */
};

struct target_sigcontext {
    int		sc_onstack;     /* sigstack state to restore */
    int		sc_mask;        /* signal mask to restore */
    int		sc_ir;			/* pc */
    int		sc_psw;         /* processor status word */
    int		sc_sp;      	/* stack pointer if sc_regs == NULL */
    void	*sc_regs;		/* (kernel private) saved state */
};

#endif


/* user access */

#define VERIFY_READ 0x00000010
#define VERIFY_WRITE 0x00000110 /* implies read access */

static inline int access_ok(int type, abi_ulong addr, abi_ulong size)
{
    return page_check_range((target_ulong)addr, size,
                            (type == VERIFY_READ) ? PAGE_READ : (PAGE_READ | PAGE_WRITE)) == 0;
}


typedef struct TaskState {
    struct TaskState *next;
    int used; /* non zero if used */
    uint8_t stack[0];
} __attribute__((aligned(16))) TaskState;

void syscall_init(void);
long do_mach_syscall(void *cpu_env, int num, uint32_t arg1, uint32_t arg2, uint32_t arg3,
                uint32_t arg4, uint32_t arg5, uint32_t arg6, uint32_t arg7, uint32_t arg8);
long do_thread_syscall(void *cpu_env, int num, uint32_t arg1, uint32_t arg2, uint32_t arg3,
                uint32_t arg4, uint32_t arg5, uint32_t arg6, uint32_t arg7, uint32_t arg8);
long do_unix_syscall(void *cpu_env, int num);
int do_sigaction(int sig, const struct sigaction *act,
                 struct sigaction *oact);
int do_sigaltstack(const stack_t *ss, stack_t *oss);

void gemu_log(const char *fmt, ...) GCC_FMT_ATTR(1, 2);
void qerror(const char *fmt, ...) GCC_FMT_ATTR(1, 2);

void write_dt(void *ptr, unsigned long addr, unsigned long limit, int flags);

extern CPUState *global_env;
void cpu_loop(CPUState *env);
void init_paths(const char *prefix);
const char *path(const char *pathname);

#include "qemu-log.h"

/* commpage.c */
void commpage_init(void);
void do_commpage(void *cpu_env, int num, uint32_t arg1, uint32_t arg2, uint32_t arg3,
                uint32_t arg4, uint32_t arg5, uint32_t arg6, uint32_t arg7, uint32_t arg8);

/* signal.c */
void process_pending_signals(void *cpu_env);
void signal_init(void);
int queue_signal(int sig, target_siginfo_t *info);
void host_to_target_siginfo(target_siginfo_t *tinfo, const siginfo_t *info);
void target_to_host_siginfo(siginfo_t *info, const target_siginfo_t *tinfo);
long do_sigreturn(CPUState *env, int num);

/* machload.c */
int mach_exec(const char * filename, char ** argv, char ** envp,
			  struct target_pt_regs * regs);

/* mmap.c */
int target_mprotect(unsigned long start, unsigned long len, int prot);
long target_mmap(unsigned long start, unsigned long len, int prot,
                 int flags, int fd, unsigned long offset);
int target_munmap(unsigned long start, unsigned long len);
long target_mremap(unsigned long old_addr, unsigned long old_size,
                   unsigned long new_size, unsigned long flags,
                   unsigned long new_addr);
int target_msync(unsigned long start, unsigned long len, int flags);

/* user access */

/* XXX: todo protect every memory access */
#define REAL_UNDERSCORE_CONCATENATE(a,b) a ## _ ## b
#define UNDERSCORE_CONCATENATE(a,b) REAL_UNDERSCORE_CONCATENATE(a,b)
#define lock_user_GET_NUMARGS(first,second,third,fourth,fifth,...) fifth
#define lock_user_FIND_NUMARGS(...) lock_user_GET_NUMARGS(__VA_ARGS__, 4, 3)
#define MACRO_CALL(func,...) func(__VA_ARGS__)
#define lock_user(...) MACRO_CALL(UNDERSCORE_CONCATENATE(lock_user, lock_user_FIND_NUMARGS(__VA_ARGS__)), __VA_ARGS__)
#define lock_user_3(...) lock_user_4(0, __VA_ARGS__)
static inline void *lock_user_4(int type, abi_ulong guest_addr, long len, int copy)
{
    if (type == 0) {
        return g2h(guest_addr);
    }
    if (!access_ok(type, guest_addr, len))
        return NULL;
    return g2h(guest_addr);
}
#define unlock_user(x,y,z)

/* Mac OS X ABI arguments processing */
#ifdef TARGET_I386
static inline uint32_t get_int_arg(int *i, CPUX86State *cpu_env)
{
    uint32_t *args = (uint32_t*)(cpu_env->regs[R_ESP] + 4 + *i);
    *i+=4;
    return tswap32(*args);
}
static inline uint64_t get_int64_arg(int *i, CPUX86State *cpu_env)
{
    uint64_t *args = (uint64_t*)(cpu_env->regs[R_ESP] + 4 + *i);
    *i+=8;
    return tswap64(*args);
}
#elif defined(TARGET_PPC)
static inline uint32_t get_int_arg(int *i, CPUPPCState *cpu_env)
{
    /* XXX: won't work when args goes on stack after gpr10 */
    uint32_t args = (uint32_t)(cpu_env->gpr[3+(*i & 0xff)/4]);
    *i+=4;
    return tswap32(args);
}
static inline uint64_t get_int64_arg(int *i, CPUPPCState *cpu_env)
{
    /* XXX: won't work when args goes on stack after gpr10 */
    uint64_t args = (uint64_t)(cpu_env->fpr[1+(*i >> 8)/8]);
    *i+=(8 << 8) + 8;
    return tswap64(args);
}
#endif

#endif
