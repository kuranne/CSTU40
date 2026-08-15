// Author: Kuranne Maisa
// Design for macOS arm64
// File name: secret_payload.asm

.global _main
.align 2

.text
_main:
    adrp x0, msg@PAGE
    add x0, x0, msg@PAGEOFF

    mov x1, #0
    mov x2, #0xAA           ; XOR key

_stage1_loop:
    ldrb w3, [x0, x1]
    eor w3, w3, w2          ; Decrypt: w3 ^= 0xAA
    strb w3, [x0, x1]
   
    add x1, x1, #1
    cmp x1, #18
    b.ne _stage1_loop       ; Loop { ... } while i != 18

    mov x1, #0

_stage2_loop:
    ldrb w2, [x0, x1]       ; Load decrypted prefix byte to use as key
    add x3, x1, #18         ; Skip 18 bytes
    ldrb w4, [x0, x3]
    eor w4, w4, w2          ; Decrypt: msg[i + 18] ^= msg[i]
    strb w4, [x0, x3]       ; Store decrypted flag byte back into memory
    
    add x1, x1, #1
    cmp x1, #10
    b.ne _stage2_loop       ; Loop { ... } while i != 10

    mov x0, #1              ; Stdout
    adrp x1, msg@PAGE
    add x1, x1, msg@PAGEOFF
    mov x2, #18
    ldr x16, =0x2000004
    svc #0

    mov x0, #0
    ldr x16, =0x2000001
    svc #0

// Place .data here