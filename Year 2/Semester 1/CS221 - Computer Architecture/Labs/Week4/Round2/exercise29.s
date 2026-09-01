.global oddoreven
.text
oddoreven:
    and $1, %rdi
    cmp $0, %rdi
    je EVEN
    jmp ODD

EVEN:
    mov $evn, %rax
    jmp EXIT
ODD:
    mov $odd, %rax
EXIT:
    ret

odd:
    .asciz "odd"
evn:
    .asciz "even"