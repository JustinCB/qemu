#ifndef _QEMU_DISAS_H
#define _QEMU_DISAS_H

#include "qemu-common.h"

#ifdef NEED_CPU_H
/* Disassemble this for me please... (debugging). */
void disas(FILE *out, void *code, unsigned long size);
void target_disas(FILE *out, target_ulong code, target_ulong size, int flags);

void monitor_disas(Monitor *mon, CPUState *env,
                   target_ulong pc, int nb_insn, int is_physical, int flags);

/* Look up symbol for debugging purpose.  Returns "" if unknown. */
const char *lookup_symbol(target_ulong orig_addr);
#endif

struct syminfo;
struct elf32_sym;
struct elf64_sym;


/* XXX: in an include */

struct nlist_extended
{
    union {
        char *n_name;
        long  n_strx;
    } n_un;
    unsigned char n_type;
    unsigned char n_sect;
    short st_desc;
    unsigned long st_value;
    unsigned long st_size;
};


#if defined(CONFIG_USER_ONLY)
typedef const char *(*lookup_symbol_t)(struct syminfo *s, target_ulong orig_addr);
#else
typedef const char *(*lookup_symbol_t)(struct syminfo *s, target_phys_addr_t orig_addr);
#endif

struct syminfo {
    lookup_symbol_t lookup_symbol;
    unsigned int disas_num_syms;
    union {
      struct elf32_sym *elf32;
      struct elf64_sym *elf64;
      struct nlist_extended *mach;
    } disas_symtab;
    const char *disas_strtab;
    struct syminfo *next;
};

/* Filled in by elfload.c.  Simplistic, but will do for now. */
extern struct syminfo *syminfos;

#endif /* _QEMU_DISAS_H */
