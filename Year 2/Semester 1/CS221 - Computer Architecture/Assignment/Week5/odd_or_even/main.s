.global main
.text
.section .rodata
    scanf_fmt:
        .string "%ld"

.text
main:
    push %rbp
    mov %rsp, %rbp
    subq $16, %rsp

    lea scanf_fmt(%rip), %rdi
    lea -8(%rbp), %rsi
    xorl %eax, %eax
    call scanf@PLT

    mov -8(%rbp), %rdi
    call assign

    xorq %rax, %rax
    leave
    ret