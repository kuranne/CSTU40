---
type: lecture
title: General Purpose Registers & Integer Representations
course_code: CS221
week: 3
tags:
  - computer-architecture
  - registers
  - x86-64
  - assembly
  - integers
  - addressing-modes
description: Detailed study of General Purpose Integer Registers, Signed/Unsigned Two's Complement Arithmetic, x86-64 Register Architecture, Assembly Operands, and Addressing Modes.
---

# 💻 General Purpose Registers & Integer Representations

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS221]] > [[General Purpose]]
> **Related Notes:** [[Instructions]] \| [[Register Architectures]] \| [[Concurrency of CPU]] \| [[CS221]]
> **Reference:** `Private/Docs/221_02.pdf`

---

## 1. Integer Data Representation

In computer architecture, integer values are typically stored in 32-bit (4-byte) or 64-bit (8-byte) words, classified into two primary representations:

```
                              ┌───────────────────────────┐
                              │   Integer Representation  │
                              └───────────────────────────┘
                                            │
                     ┌──────────────────────┴──────────────────────┐
                     ▼                                             ▼
          Unsigned Integer                                  Signed Integer
          - Positive values and zero only                   - Two's Complement representation
          - 32-bit range: [0, 2^32 - 1]                     - 32-bit range: [-2^31, 2^31 - 1]
          - [0 to 4,294,967,295]                            - [-2,147,483,648 to 2,147,483,647]
```

### 1.1 Data Ranges by Bit Width

| Bit Width / Byte Size | Unsigned Range | Signed Range (Two's Complement) |
| :--- | :--- | :--- |
| **8-bit (1 Byte)** | $0$ to $255$ ($2^8 - 1$) | $-128$ to $+127$ ($-2^7$ to $2^7-1$) |
| **16-bit (2 Bytes - Word)** | $0$ to $65,535$ ($2^{16} - 1$) | $-32,768$ to $+32,767$ ($-2^{15}$ to $2^{15}-1$) |
| **32-bit (4 Bytes - Double Word)** | $0$ to $4,294,967,295$ | $-2,147,483,648$ to $+2,147,483,647$ |
| **64-bit (8 Bytes - Quad Word)** | $0$ to $18.44 	imes 10^{18}$ ($2^{64}-1$) | $-9.22 	imes 10^{18}$ to $+9.22 	imes 10^{18}$ |

### 1.2 Two's Complement Representation & Conversion
In Two's Complement signed representation, the Most Significant Bit (MSB) acts as the **Sign Bit** ($0 = 	ext{positive}$, $1 = 	ext{negative}$).

> [!question] Converting Positive Integers to Negative (Two's Complement Rule)
> **Rule:** Invert all bits (Bitwise NOT: $0 \rightarrow 1, 1 \rightarrow 0$) and add $1$ ($\sim x + 1 = -x$).

**Example:** Convert $+5$ (4-bit binary `0101`) to $-5$:
1. Invert all bits: `0101` $\rightarrow$ `1010` (One's Complement, value $-6$)
2. Add 1: `1010` + `0001` = `1011` (Two's Complement, value $-5$)

**8-bit Sample Values:**
| Binary Pattern | Unsigned Decimal | Signed Decimal (Two's Complement) |
| :--- | :--- | :--- |
| `0000 0000` | $0$ | $0$ |
| `0000 0001` | $1$ | $+1$ |
| `0111 1111` | $127$ | $+127$ (Maximum 8-bit positive) |
| `1000 0000` | $128$ | $-128$ (Minimum 8-bit negative) |
| `1111 1110` | $254$ | $-2$ |
| `1111 1111` | $255$ | $-1$ |

---

## 2. x86-64 General Purpose Registers (GPRs)

The x86-64 architecture features **16 General Purpose Registers**, each 64 bits wide, with backward-compatible sub-register naming for 32-bit, 16-bit, and 8-bit access:

| 64-bit Register | 32-bit (Low) | 16-bit (Low) | 8-bit (Low) | 8-bit (High) | Conventional Role & Calling Conventions |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `%rax` | `%eax` | `%ax` | `%al` | `%ah` | **Return Value**, Accumulator |
| `%rbx` | `%ebx` | `%bx` | `%bl` | `%bh` | Callee-saved Base Register |
| `%rcx` | `%ecx` | `%cx` | `%cl` | `%ch` | **4th Function Argument**, Loop Counter |
| `%rdx` | `%edx` | `%dx` | `%dl` | `%dh` | **3rd Function Argument**, I/O pointer |
| `%rsi` | `%esi` | `%si` | `%sil` | — | **2nd Function Argument**, Source Index |
| `%rdi` | `%edi` | `%di` | `%dil` | — | **1st Function Argument**, Destination Index |
| `%rbp` | `%ebp` | `%bp` | `%bpl` | — | Frame Pointer / Base Pointer (Callee-saved) |
| `%rsp` | `%esp` | `%sp` | `%spl` | — | **Stack Pointer** (Points to top of stack) |
| `%r8` | `%r8d` | `%r8w` | `%r8b` | — | **5th Function Argument** |
| `%r9` | `%r9d` | `%r9w` | `%r9b` | — | **6th Function Argument** |
| `%r10` | `%r10d` | `%r10w` | `%r10b` | — | Caller-saved Temporary |
| `%r11` | `%r11d` | `%r11w` | `%r11b` | — | Caller-saved Temporary |
| `%r12` | `%r12d` | `%r12w` | `%r12b` | — | Callee-saved |
| `%r13` | `%r13d` | `%r13w` | `%r13b` | — | Callee-saved |
| `%r14` | `%r14d` | `%r14w` | `%r14b` | — | Callee-saved |
| `%r15` | `%r15d` | `%r15w` | `%r15b` | — | Callee-saved |

---

## 3. Assembly Syntax & Operands

### 3.1 AT&T vs. Intel Syntax Comparison

| Feature | AT&T Syntax (GNU Assembler / GCC / Linux / macOS) | Intel Syntax |
| :--- | :--- | :--- |
| **Operand Order** | `OP source, destination` (Source $\rightarrow$ Destination) | `OP destination, source` (Destination $\leftarrow$ Source) |
| **Register Prefix** | Prefixed with `%` (e.g., `%rax`, `%edi`) | No prefix (e.g., `rax`, `edi`) |
| **Immediate Prefix** | Prefixed with `$` (e.g., `$10`, `$0xFF`) | No prefix (e.g., `10`, `0FFh`) |
| **Size Suffix** | Instruction suffix: `b` (byte), `w` (word), `l` (long), `q` (quad) | Size directives (`BYTE PTR`, `DWORD PTR`, `QWORD PTR`) |

### 3.2 Three Types of Operands

1. **Immediate (`$val`):** Constant literals, e.g., `$100`, `$0x20`, `$-5`.
2. **Register (`%reg`):** Values stored in CPU registers, e.g., `%rax`, `%edi`, `%cl`.
3. **Memory (`Address`):** Values stored at a memory address accessed via addressing modes.

---

## 4. Memory Addressing Modes

In AT&T syntax, the general effective address calculation formula is:

$$	ext{Effective Address} = 	ext{Imm} + 	ext{Reg}[R_b] + (	ext{Reg}[R_i] 	imes s)$$

Where:
- $	ext{Imm}$ or $D$ = Displacement (constant offset)
- $R_b$ = Base Register (e.g., `%rbp`, `%rax`)
- $R_i$ = Index Register (any GPR *except `%rsp`*)
- $s$ = Scale Factor ($1, 2, 4,$ or $8$)

| Syntax Form | Effective Address Computation | Example | Description |
| :--- | :--- | :--- | :--- |
| `Imm` | $	ext{Imm}$ | `$0x400580` | Absolute Memory Address |
| `(Rb)` | $	ext{Reg}[R_b]$ | `(%rax)` | Register Indirect (Dereferences address in `%rax`) |
| `D(Rb)` | $D + 	ext{Reg}[R_b]$ | `8(%rbp)` | Base + Displacement (Local variables / Struct offset) |
| `(Rb, Ri)` | $	ext{Reg}[R_b] + 	ext{Reg}[R_i]$ | `(%rax, %rdx)` | Base + Index |
| `D(Rb, Ri)` | $D + 	ext{Reg}[R_b] + 	ext{Reg}[R_i]$ | `4(%rax, %rdx)` | Base + Index + Displacement |
| `(Rb, Ri, s)` | $	ext{Reg}[R_b] + 	ext{Reg}[R_i] 	imes s$ | `(%rax, %rcx, 4)` | Indexed array access (4-byte elements / `int[]`) |
| `D(Rb, Ri, s)` | $D + 	ext{Reg}[R_b] + 	ext{Reg}[R_i] 	imes s$ | `8(%rax, %rcx, 8)` | Indexed array access with header displacement |

### Notable Idiomatic Instructions:
```asm
xor %rax, %rax          # XOR %rax with itself; zeroes out %rax faster than `mov $0, %rax`
movq (%rdi), %rax       # Loads 64-bit value at memory address in %rdi into %rax
movl 4(%rdi, %rsi, 4), %eax # Computes &(arr[i+1]) and loads 32-bit int into %eax
```

---

## 🔗 Related Notes & References
- [[CS221]] — Main Course Index for Computer Architecture
- [[Instructions]] — Instruction Set Architecture and instruction formats
- [[Register Architectures]] — Register-Register vs. Register-Memory models
- [[Concurrency of CPU]] — Hardware organization, pipelining, and parallelism
