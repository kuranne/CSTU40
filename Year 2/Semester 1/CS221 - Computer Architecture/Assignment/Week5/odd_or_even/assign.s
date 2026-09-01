.global assign
.text

assign:
    // 1.
    mov %rdi, %rax
    //
    // 2.
    cqto
    //
    // 3.
    mov $2, %r10
    //
    idiv %r10

    // 4.
    cmp $1, %rdx
    //
    je EQUAL
    mov $even, %rdi
    call puts
    // 5.
    jmp EXIT
    //

EQUAL:
    mov $odd, %rdi
    call puts

EXIT:
    ret

odd:    .asciz "It is an odd."
even:   .asciz "It is an even."