.global main
.text

.section .rodata
    printf_fmt:
        .string "%ld\n"
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

    lea printf_fmt(%rip), %rdi
    mov %rax, %rsi
    xorl %eax, %eax
    call printf@PLT

    xorq %rax, %rax
    leave
    ret