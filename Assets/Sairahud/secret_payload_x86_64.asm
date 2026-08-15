; Author: Kuranne Maisa
; Design for System V AMD64 ABI
; File name: secret_payload_x86_64.asm

global _start

section .text

_start:
    lea rdi, [rel msg]
    xor rcx, rcx

_stage1_loop:
    mov al, byte [rdi + rcx]
    xor al, 0xAA
    mov byte [rdi + rcx], al
    
    inc rcx
    cmp rcx, 18
    jne _stage1_loop

    xor rcx, rcx

_stage2_loop:
    mov al, byte [rdi + rcx]
    mov bl, byte [rdi + rcx + 18]
    xor bl, al
    mov byte [rdi + rcx + 18], bl
    
    inc rcx
    cmp rcx, 10
    jne _stage2_loop

    mov rax, 1
    mov rdi, 1
    lea rsi, [rel msg]
    mov rdx, 18
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall

; Place .data here