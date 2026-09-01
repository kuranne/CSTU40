.global assign
.text
assign:
    // 1.
    mov $1, %rsi
    //
    // 2.
    mov $1, %rax
    //
    // 3.
    mov $1, %rcx
    //
LOOP:
    // 4.
    cmp %rdi, %rsi
    //
    jge DONE

    mov %rax, %rbx
    add %rcx, %rax
    mov %rbx, %rcx
    // 5.
    inc %rsi
    //
    jmp LOOP
DONE:
    ret