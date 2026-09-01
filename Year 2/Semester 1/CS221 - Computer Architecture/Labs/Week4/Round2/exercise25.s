.global aplusbmod2
.text

aplusbmod2:
    mov %rdi, %rax
    add %rsi, %rax
    cqto

    mov $2, %rcx
    idiv %rcx
    ret