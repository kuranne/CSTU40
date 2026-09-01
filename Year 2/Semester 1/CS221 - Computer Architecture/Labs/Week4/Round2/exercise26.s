.global second_last_digit
.text

second_last_digit:
    mov %rdi, %rax
    cqto

    mov $10, %rcx
    idiv %rcx
    mov %rdx, %rsi
    cqto
    
    idiv %rcx
    mov %rsi, %rax
    ret
