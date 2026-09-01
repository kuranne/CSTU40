.global exercise2
.text

exercise2:
    // rdi, rsi, rdx
    // rdx + 2 * (rdi + rsi) - (rsi + 2 * rdx)

    mov %rdi, %rax
    add %rsi, %rax
    imul $2, %rax

    mov %rdx, %rcx  ; rcx = rdx
    imul $2, %rdx
    add %rsi, %rdx

    add %rcx, %rax
    sub %rdx, %rax
    
    ret