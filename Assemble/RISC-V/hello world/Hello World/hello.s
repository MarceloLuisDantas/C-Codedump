.global _start
.section .text
_print:
    li a7, 64
    ecall
    jr ra  
    
_exit:
    li a0, 0
    li a7, 93
    ecall

_start: 
    li t1, 1 
    la a1, hello 
    li a2, 13
    jal _print

    j _exit    

.section .data
hello: .ascii "Hello World\n"
