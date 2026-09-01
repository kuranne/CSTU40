.global g100
.text

g100:
    cmp $100, %rdi
    jg LT
    mov $les, %rdi
    call puts
    jmp EXIT

LT:
    mov $gre %rdi
    call puts

EXIT: 
    ret

les: .asciz "<= 100 "
gre: .asciz "> 100"