#ifndef HASM_H
#define HASM_H

#ifdef _LANGUAGE_ASSEMBLY

#define LEAF(x)                 \
    .align 2                   ;\
    .globl x                   ;\
    .type x, @function         ;\
    x:                         ;\
        .ent x, 0              ;\
        .frame $sp, 0, $ra

#define END(x)                  \
    .size x, . - x             ;\
    .end x

.macro move dst, src
    addu \dst, \src, $zero
.endm

#define LA(dst, address) \
    lui         dst, %hi(address); \
    addiu       dst, dst, %lo(address)

#endif

#define BOOT_STACK_SIZE 0x2000

#endif
