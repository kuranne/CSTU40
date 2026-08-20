---
type: lecture
title: Register Architectures & ISA Models
course_code: CS221
week: 2
tags:
  - computer-architecture
  - register-architectures
  - load-store
  - cisc-vs-risc
  - assembly
description: Comparative analysis of Register-Register (Load-Store), Register-Memory, Accumulator, and Stack Architectures with detailed execution traces and exercise solutions.
---

# 🏗️ Register Architectures & ISA Models

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS221]] > [[Register Architectures]]
> **Related Notes:** [[Instructions]] \| [[General Purpose]] \| [[Concurrency of CPU]] \| [[CS221]]

---

## 1. Register Architecture Classifications

Instruction Set Architectures (ISAs) are classified by how operands are specified in arithmetic and logic instructions:

```
                         ┌─────────────────────────────┐
                         │       ISA Architecture      │
                         └─────────────────────────────┘
                                        │
        ┌───────────────────────┬───────┴───────────────┬────────────────────────┐
        ▼                       ▼                       ▼                        ▼
1. Stack Architecture   2. Accumulator         3. Register-Memory       4. Register-Register
   - Zero-address          Architecture           (CISC - e.g. x86)        (Load-Store / RISC)
   - Implicit Top of       - 1-address            - 2-address              - 3-address
     Stack                 - Implicit AC          - Memory can be direct   - ALU operations on
                                                    operand                  registers only
```

### 1.1 Register-Register Architecture (Load-Store / RISC - e.g., ARM, MIPS, RISC-V)
- **Key Characteristics:** ALU operations (`add`, `sub`, `mul`) accept **only register operands**.
- **Memory Access:** Restricted exclusively to explicit `load` and `store` instructions.
- **Instruction Format (3 Operands):** `OP Dest, Src1, Src2`

```asm
load M, R1          # R1 = Mem[M]
store R1, M         # Mem[M] = R1
add R1, R2, R3      # R3 = R1 + R2 (or Dest = Src1 + Src2 depending on syntax)
sub R1, R2, R3      # R3 = R2 - R1
```

### 1.2 Register-Memory Architecture (CISC - e.g., Intel x86)
- **Key Characteristics:** ALU instructions allow one operand to be a **direct memory address** while the other is a register.
- **Advantage:** Compact instruction counts; avoids explicit prior load instructions for simple operations.
- **Instruction Format (2 Operands):** `OP Dest, Src`

```asm
load M, R1          # R1 = Mem[M]
store R1, M         # Mem[M] = R1

add R1, R2          # R2 = R2 + R1 (Register-to-Register)
add M, R1           # R1 = R1 + Mem[M] (Memory-to-Register)
add R1, M           # Mem[M] = Mem[M] + R1 (Register-to-Memory)

sub R1, R2          # R2 = R2 - R1
sub M, R1           # R1 = R1 - Mem[M]
```

---

## 2. Worked Quizzes & Expression Tracing

### 📌 Exercise 1: Computing $A = (A + B) - (C + D) - E$

#### Solution 1.1: Register-Register Architecture (Load-Store)
```asm
# Compute (A + B)
load A, R1          # R1 = A
load B, R2          # R2 = B
add R1, R2, R1      # R1 = A + B

# Compute (C + D)
load C, R2          # R2 = C
load D, R3          # R3 = D
add R2, R3, R2      # R2 = C + D

# Subtract (C + D) and E from (A + B)
load E, R3          # R3 = E
sub R2, R1, R1      # R1 = (A + B) - (C + D)
sub R3, R1, R1      # R1 = (A + B) - (C + D) - E

# Store result back into memory
store R1, A         # Mem[A] = R1
```

#### Solution 1.2: Register-Memory Architecture
```asm
load A, R1          # R1 = A
add B, R1           # R1 = A + B

load C, R2          # R2 = C
add D, R2           # R2 = C + D

sub R2, R1          # R1 = (A + B) - (C + D)
sub E, R1           # R1 = (A + B) - (C + D) - E
store R1, A         # Mem[A] = R1
```

---

### 📌 Exercise 2: $A = (A + B) - (C + D + E) + F$ on Accumulator Architecture ($\le$ 7 Instructions)

> [!tip] **Algebraic Expansion:**
> $$A = A + B - C - D - E + F$$

```asm
1. load A           # AC = A
2. add B            # AC = A + B
3. sub C            # AC = (A + B) - C
4. sub D            # AC = (A + B - C) - D
5. sub E            # AC = (A + B - C - D) - E
6. add F            # AC = (A + B - C - D - E) + F
7. store A          # Mem[A] = AC (Exactly 7 instructions)
```

---

### 📌 Exercise 3: Converting Accumulator Assembly to Mathematical Formula

**Assembly Code:**
```asm
load A
sub B
add C
store A
```

**Step-by-Step Analysis:**
1. `load A` $\rightarrow 	ext{AC} = A$
2. `sub B`  $\rightarrow 	ext{AC} = A - B$
3. `add C`  $\rightarrow 	ext{AC} = (A - B) + C$
4. `store A` $\rightarrow 	ext{Mem}[A] = A - B + C$

**Result:** $$A = A - B + C$$

---

### 📌 Exercise 4: Converting Stack Assembly to Mathematical Formula

**Assembly Code:**
```asm
push A
push B
push C
sub
sub
pop A
```

**Stack State Trace:**
1. `push A` $\rightarrow 	ext{Stack: } [A]$ (TOS = $A$)
2. `push B` $\rightarrow 	ext{Stack: } [A, B]$ (TOS = $B$)
3. `push C` $\rightarrow 	ext{Stack: } [A, B, C]$ (TOS = $C$)
4. `sub`    $\rightarrow 	ext{Pop } C, B \rightarrow 	ext{Compute } (B - C) \rightarrow 	ext{Stack: } [A, (B - C)]$
5. `sub`    $\rightarrow 	ext{Pop } (B - C), A \rightarrow 	ext{Compute } A - (B - C) \rightarrow 	ext{Stack: } [A - (B - C)]$
6. `pop A`  $\rightarrow 	ext{Mem}[A] = A - (B - C) = A - B + C$

**Result:** $$A = A - (B - C) = A - B + C$$

---

## 🔗 Related Notes & References
- [[CS221]] — Main Course Index for Computer Architecture
- [[Instructions]] — ISA categories, machine instructions, and comparison matrix
- [[General Purpose]] — GPRs, integer representations, and addressing modes
- [[Concurrency of CPU]] — Hardware pipelining and levels of parallelism
