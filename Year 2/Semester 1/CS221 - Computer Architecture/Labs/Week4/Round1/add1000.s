.global add1000
.text

add1000:
    mov %rdi, %rax          ; Bring %rdi to %rax
    add $1000, %rax         ; add val in %rax with (Const)1,000
    ret                     ; return %rax
