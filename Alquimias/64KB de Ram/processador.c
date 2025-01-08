#include "stdint.h"
#include "./ram.c"

/*  Instructions
 *  nop           |- do nothing for 1 cycle 
 *  add  r1 r2 r3 |- r1 = r2 + r3 
 *  addi r1 r2 v1 |- r1 = r2 + v1 
 *  sub  r1 r2 r3 |- r1 = r2 - r3
 *  subi r1 r2 v1 |- r1 = r2 - v1
 *  mut  r1 r2 r3 |- r1 = r2 * r3 
 *  muti r1 r2 v1 |- r1 = r2 * v1
 *  div  r1 r2 r3 |- r1 = r2 / r3
 *  divi r1 r2 v1 |- r1 = r2 / v1
 *  mov  r1 r2    |- r1 = r2 
 *  j    point    |- jump to point
 *  jal  point    |- jump to point and link
 *  jr   register |- jump to the point in the register 
 *  and  r1 r2 r3 |- r1 = r2 & r3
 *  or   r1 r2 r3 |- r1 = r2 | r3
 *  sl   r1 r2 v1 |- r1 = r2 << v1
 *  sr   r1 r2 v1 |- r1 = r2 >> v1
 */
typedef struct CPU {
    /*  Registers
     *  #0        -> $zero      |- allways zero
     #  #q        -> $gp        |- global pointer
     *  #2 .. #3  -> $a0 .. $a2 |- arguments to procedures
     *  #3 .. #4  -> $v0 .. $v1 |- result from procedures
     *  #5 .. #10 -> $t0 .. $t4 |- temporary values free use
     *  #11       -> $pp        |- programe pointer
     *  #12       -> #sp        |- Stack pointer
     *  #13       -> #fp        |- Frame pointer
     *  #15       -> $ra        |- return address
     */
    int16_t zero;
    int16_t gp;
    int16_t a0, a1, a2;
    int16_t v0, v1;
    int16_t t0, t1, t2, t3, t4;
    int16_t pp;
    int16_t sp;
    int16_t fp;
    int16_t ra;
    int16_t registers[16];
} CPU;