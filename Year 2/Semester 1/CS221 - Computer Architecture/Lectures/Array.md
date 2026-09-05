---
type: lecture
title: Array Memory Addressing & Assembly Implementation
course_code: CS221
semester: Year 2 Semester 1
week: 4, 5
tags:
  - computer-architecture
  - assembly
  - x86-64
  - memory-addressing
  - cstu40
description: "Array memory representation as contiguous blocks, base-index-displacement addressing formulas, and assembly loop iteration."
created: 2026-09-01
updated: 2026-09-05
---

# 🗃️ Array Memory Addressing

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS221]] > [[Array]]
> **Related Notes:** [[CS221]] | [[General Purpose]] | [[Instructions]] | [[Y86_64]]

---

An array is a sequence of values of the same data type. It is stored in memory as a consecutive (contiguous) block of memory. For example, a C statement `long A[5];` defines an array which is composed of 5 elements. Each element is a 64-bit integer.

## Example: `sumarr.s`

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

---

## Addressing Calculation

From the instruction, we can determine that:

$$	ext{Address}(arr[n]) = 	ext{displacement} + (	ext{base} + 	ext{index} 	imes 	ext{size})$$
