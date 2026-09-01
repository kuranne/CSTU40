.global maxoftwo
.text

maxoftwo:
    cmp %rdi, %rsi
    jg LGT
    jmp LLT

LGT:
    mov %rsi, %rax
    jmp EXIT
LLT:
    mov %rdi, %rax

EXIT:
    ret