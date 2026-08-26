.global ldgt
.text

ldgt:
    mov %rdi, %rax  
    mov $10, %rcx   ; this is a register to be 
    cqto
    idiv %rcx
    mov %rdx, %rax
    ret             ; return contol at call