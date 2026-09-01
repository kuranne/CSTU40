---
type: lecture
title: x86_64 Assembly Bitwise & Shift Operations Exercises
course_code: CS221
week: 3, 4
tags:
  - computer-architecture
  - assembly
  - x86-64
  - bitwise-operations
  - exercises
  - cstu40
description: Practice exercises and step-by-step tracing for bitwise NOT, OR, SHL, and SHR operations on x86_64 registers %rax and %rcx.
---

# 📝 Assembly Bitwise & Shift Exercises

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS221]] > [[Exercise]]
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
