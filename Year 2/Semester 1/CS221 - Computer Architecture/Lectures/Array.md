---
type: lecture
description:
---
# Array

An array is sequence of values of the same data type. It is stored in the memory as a consecutive block of memory. For example, a C statement long A\[5]; defines an array which is composed of 5 elements. Each element is a 64-bit integer.

**Example:** sumarr.s

```asm
.global sumarr
.text

sumarr:
	xor %rax, %rax
	xor %rcx, %rcx
	cmp %rsi, %rcx    ; if %rcx >= %rsi then ret (for (int i = 0; i < x; i++))
	jge done
	
	add (%rdi), %rax  ; add %rax with value in address at %rdi: M[%rdi]
	inc $rcx
	addq $8, %rdi     ; add by 8 because it is a length of 64-bit register
	jmp loop
	
done:
	ret
```

From the instruction, we can determine that $arr[n] = displacement + (base + index * size)$ 


