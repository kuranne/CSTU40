---
type: lecture
title: x86_64 Assembly Bitwise & Shift Operations Exercises
class: CS221
week: 3, 4
tags:
  - computer-architecture
  - assembly
  - x86-64
  - bitwise-operations
  - exercises
  - cstu40
description: Practice exercises and step-by-step tracing for bitwise NOT, OR, SHL, and SHR operations on x86_64 registers %rax and %rcx.
parent: "CS221"
---

# Assembly Bitwise & Shift Exercises

> **Related Notes:** [[General Purpose]] | [[Instructions]] | [[Assembly]] | [[CS221]]

---

> [!question]+ **Problem Statement:**
> Given initial register values:
> - $\%rax = 10$ ($0	ext{xA}$ or binary $1010_2$)
> - $\%rcx = 1024$ ($0	ext{x}400$ or binary $10000000000_2$)
> 
> Trace and determine the output/state of the following instructions:

---

### 1. `not %rax` (Bitwise One's Complement)
- **Binary representation:** $10 = 0000\dots 0000\ 1010_2$
- **Operation:** Inverts every bit in the 64-bit register `%rax`.
```text
%rax (before) = 0000 ... 0000 1010
not %rax      = 1111 ... 1111 0101  (= -11 in two's complement / 0xFFFFFFFFFFFFFFF5)
```

---

### 2. `or $-1, %rax` (Bitwise Inclusive OR with Immediate)
- **Immediate operand:** $\$-1 = 1111\dots 1111_2$ ($0	ext{xFFFFFFFFFFFFFFFF}$)
- **Register operand:** $\%rax = 1010_2$
- **Operation:** Any bit ORed with 1 results in 1.
```text
$-1       = 1111 ... 1111
%rax      = 0000 ... 1010
or result = 1111 ... 1111  (= -1)
```

---

### 3. `shl $4, %rcx` (Logical Shift Left)
- **Shift count:** $4$ bits
- **Register operand:** $\%rcx = 1024 = 0100\ 0000\ 0000_2$ ($2^{10}$)
- **Operation:** Shifts bits left by 4 positions (equivalent to multiplying by $2^4 = 16$).
```text
%rcx (before) = 0000 0100 0000 0000 (1,024)
shl $4, %rcx  = 0100 0000 0000 0000 (16,384 = 1024 * 16)
```

---

### 4. `shr $4, %rcx` (Logical Shift Right)
- **Shift count:** $4$ bits
- **Register operand:** $\%rcx = 1024 = 0100\ 0000\ 0000_2$ ($2^{10}$)
- **Operation:** Shifts bits right by 4 positions (equivalent to integer division by $2^4 = 16$).
```text
%rcx (before) = 0100 0000 0000 (1,024)
shr $4, %rcx  = 0000 0100 0000 (64 = 1024 / 16; or 128 if starting from 2048)
```

---

### 5. Write the value of out and cond for the following operations. 

1. 0x70010001 + 0x20 
	**Ans.** 
	$b0111 0000 0000 0001 0000 0000 0000 0001 + b0010 0000 = b0111 0000 0001 0000 0000 0010 0001$ 
	or $0x70010021$
	**flags:** ==ZF(0), SF(0), CF(0)==

2. 0xfffffffe + 0x2 
	**Ans.**
	$b1111 1111 1111 1111 1111 1111 1111 1110 + b0010 = b0001 0000 0000 0000 0000 0000 0000 0000 0000 + b0001$ 
	or $0x0$ + $0x1$
	**flags:** ==ZF(1), SF(0), CF(1)==

3. 0x10101010 & 0xffff0000 
	**Ans.**
	$b0001 0000 0001 0000 0001 0000 0001 0000 \& b1111 1111 1111 1111 0000 0000 0000 0000 = b0001 0000 0001 0000 0000 0000 0000 0000$ or $0x10100000$
	**flags:** ==ZF(0), SF(0), CF(0)==
4. 0x10101010\^0xffff0000
	**Ans.**
	$b0001 0000 0001 0000 0001 0000 0001 0000 \land b1111 1111 1111 1111 0000 0000 0000 0000 = b1110 1111 1110 1111 0001 0000 0001 0000$
	or $0xefef1010$
	**flags:** ==ZF(0), SF(1), CF(0)==

---

### 6. Show how to execute the following program composing of two instructions as shown below.

Here, let $\%rax=4, \%rcx=0x4000, and\text{ }PC=0x0$

| Address | Assembly              | Machine Code               |
| ------- | --------------------- | -------------------------- |
| 0       | `rmmov %rax, 4(%rcx)` | `4001 0000 0000 0000 0004` |
| 10      | `irmov $8, %rcx`      | `30F1 0000 0000 0000 0008` |

| Stage      | `rmmove %rax, 4(%rcx)`                                                                               | `irmove $8, %rcx`                                                                                      |
| ---------- | ---------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------ |
| Fetch      | $icode:ifun \leftarrow 4:0$<br>$rA:rB \leftarrow 0:1$<br>$varC \leftarrow 4$<br>$varP \leftarrow 10$ | $icode:ifun \leftarrow 3:0$<br>$rA:rB \leftarrow F : 1$<br>$varC \leftarrow 8$<br>$varP \leftarrow 20$ |
| Decode     | $varA \leftarrow 4$<br>$varB \leftarrow 0x4000$                                                      | -                                                                                                      |
| Execute    | $varE \leftarrow 0x4004$<br>$ZF = 0, SF = 0, CF = 0$                                                 | $varE \leftarrow 8$                                                                                    |
| Memory     | $Mem[valE] \leftarrow 4$                                                                             | -                                                                                                      |
| Write Back | -                                                                                                    | $Reg[1] \leftarrow 8$                                                                                  |
| PC Update  | $PC <- 10 \text{ from varP}$                                                                         | $PC \leftarrow 20$                                                                                     |

---

## 7. Write the control signal

when `mrmov D(rB), rA` is executed

| Cycle         | irWrite | valPWrite | valAWrite | valBWrite | valEWrite | valMWrite | pcWrite |
| ------------- | ------- | --------- | --------- | --------- | --------- | --------- | ------- |
| 1. Fetch      | ==1==   | ==1==     | 0         | 0         | 0         | 0         | 0       |
| 2. Decode     | 0       | 0         | 0         | ==1==     | 0         | 0         | 0       |
| 3. Execute    | 0       | 0         | 0         | 0         | ==1==     | 0         | 0       |
| 4. Memory     | 0       | 0         | 0         | 0         | 0         | ==1==     | 0       |
| 5. Write Back | 0       | 0         | 0         | 0         | 0         | 0         | 0       |
| 6. PC Update  | 0       | 0         | 0         | 0         | 0         | 0         | ==1==   |

---

## 8.What is the execution time and CPI of the following program when the clock period is set to 0.5 ns?

```asm
push %rbx ; 6 cc
push %rsi ; 6 cc
irmov $0, %rbx ; 4 cc
irmov $5,%rsi ; 4 cc
add %rbx,%rsi ; 5 cc
pop %rsi ; 6 cc
pop %rbx ; 6 cc
ret ; 6 cc
```

So the execution time is $43 \times 0.5$
CPI = $43 \div 8 = 5.375$

---
