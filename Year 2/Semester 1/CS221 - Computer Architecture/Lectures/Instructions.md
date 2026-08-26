---
type: lecture
title: Instruction Set Architecture (ISA) & Machine Instructions
course_code: CS221
week: 1, 2
tags:
  - computer-architecture
  - instruction-set
  - isa
  - stack-architecture
  - accumulator
description: In-depth exploration of Instruction Set Architecture (ISA), Machine Code representation, Temporary Storage models (Accumulator, Stack, General-Purpose Registers), and instruction execution tracing.
---

# 📜 Instruction Set Architecture (ISA) & Machine Instructions

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS221]] > [[Instructions]]
> **Related Notes:** [[Register Architectures]] \| [[General Purpose]] \| [[Concurrency of CPU]] \| [[CS221]]

---

## 1. Instruction Set Architecture (ISA) Components

An **Instruction Set Architecture (ISA)** is the abstract boundary between CPU hardware and system software, defining:
1. **Instruction Formats & Opcodes:** Binary layout and operation encodings.
2. **Data Types & Sizes:** Byte (8b), Word (16b), Doubleword (32b), Quadword (64b).
3. **Addressing Modes:** Mechanisms for specifying memory operand addresses.
4. **Temporary Storage Models:** Registers, accumulator, and hardware stack.
5. **Exception & Interrupt Handling:** Trap mechanisms and system interrupts.

### Machine Code vs. Assembly Representation

| ISA | Machine Code Representation | Assembly Language | Description |
| :--- | :--- | :--- | :--- |
| **ARM (RISC)** | `1110 0010 1000 0110 0110 0000 0000 0001` (32-bit Fixed) | `add r6, r6, #1` | Add immediate 1 to register `r6` |
| **x86 / IA-32 (CISC)** | `0100 0000` (1-byte Variable length) | `inc %eax` | Increment register `%eax` by 1 |

---

## 2. Temporary Storage Models in Processors

Processors are categorized into four major architectures based on where operands are stored:

```
                            ┌─────────────────────────────┐
                            │    Temporary Storage Models │
                            └─────────────────────────────┘
                                           │
         ┌──────────────────┬──────────────┴──────────────┬──────────────────┐
         ▼                  ▼                             ▼                  ▼
  1. Accumulator         2. Stack                      3. Register-       4. Register-
     Architecture           Architecture                  Memory             Register
     - 1 Address            - 0 Address                   - 2 Address        - 3 Address
     - Implicit AC          - Top of Stack                - CISC (x86)       - RISC (ARM)
```

---

### 2.1 Accumulator Architecture (1-Address Machine)
- **Principle:** Uses a single dedicated **Accumulator Register (AC)**. All arithmetic/logic instructions implicitly use AC as one operand and the destination.
- **Basic Instructions:**
  - `load M`:$AC \leftarrow 	Mem[M]$
  - `store M`: $Mem[M] \leftarrow 	AC$
  - `add M`: $AC \leftarrow 	AC + 	Mem[M]$
  - `sub M`: $AC \leftarrow 	AC - 	Mem[M]$

---

### 2.2 Stack Architecture (0-Address Machine)
- **Principle:** Operands are maintained in a **Last-In, First-Out (LIFO) Stack**, with a **Stack Pointer (SP)** tracking the Top of Stack (TOS). Arithmetic instructions operate implicitly on values popped from TOS (0-Address instructions).
- **Basic Instructions:**
  - `push M`: $Stack[	top] \leftarrow 	Mem[M]$
  - `pop M`: $Mem[M] \leftarrow 	Stack[	top]$
  - `add`: Pops top two elements, adds them, and pushes result back onto stack.
  - `sub`: Pops top two elements ($Top-1 - 	Top$), subtracts them, and pushes result back onto stack.
- *Examples:* Java Virtual Machine (JVM Bytecode), PostScript, Forth.

**Example: Evaluating $C = A + B$ on Stack:**
```asm
push A              # Stack: [A]
push B              # Stack: [A, B] (B is on top)
add                 # Pops B, A -> Pushes (A + B) -> Stack: [A + B]
pop C               # Mem[C] = A + B
```

---

### 2.3 General-Purpose Register (GPR) Architectures
- **Register-Memory (Intel x86):** Instructions can reference both registers and memory locations.
- **Register-Register (ARM, MIPS, RISC-V):** ALU operations accept registers only; memory is accessed via explicit `load`/`store`.

---

## 3. Step-by-Step Expression Tracing

### 📌 Problem: Implement $A = (A + B) - (C + D) - E$

#### Method 1: Accumulator Architecture (Direct Approach)
```asm
load A              # AC = A
add B               # AC = A + B
store A             # Mem[A] = A + B (Temporary save)

load C              # AC = C
add D               # AC = C + D
store C             # Mem[C] = C + D (Temporary save)

load A              # AC = (A + B)
sub C               # AC = (A + B) - (C + D)
sub E               # AC = (A + B) - (C + D) - E
store A             # Mem[A] = AC
```

#### Method 2: Accumulator Architecture (Optimized / 6 Instructions)
$$A = A + B - C - D - E$$
```asm
load A              # AC = A
add B               # AC = A + B
sub C               # AC = A + B - C
sub D               # AC = A + B - C - D
sub E               # AC = A + B - C - D - E
store A             # Mem[A] = AC
```

---

#### Method 3: Stack Architecture Execution
```asm
push A              # Stack: [A]
push B              # Stack: [A, B]
add                 # Stack: [A + B]

push C              # Stack: [A + B, C]
push D              # Stack: [A + B, C, D]
add                 # Stack: [A + B, C + D]

sub                 # Top-1 - Top -> (A + B) - (C + D), Stack: [(A + B) - (C + D)]

push E              # Stack: [(A + B) - (C + D), E]
sub                 # Top-1 - Top -> (A + B) - (C + D) - E, Stack: [Final Result]

pop A               # Store Final Result in Mem[A]
```

---

## 4. Architecture Comparison Matrix

| Architecture | Operands per ALU Inst | Code Size | Hardware Complexity | Key Advantage | Key Limitation |
| :--- | :---: | :---: | :---: | :--- | :--- |
| **Stack** | 0 | Very Short | Low | Simple compiler code generation | TOS bottleneck; lower performance |
| **Accumulator** | 1 | Medium | Very Low | Minimal hardware cost | High memory traffic |
| **Register-Memory** | 2 | Short | Medium-High | Direct memory operations in ALU | Variable-length instructions |
| **Register-Register** | 3 | Slightly Longer | Medium | Optimal pipelining & register reuse | Higher instruction count |

---

## 5. x86_64 Instructions

>[!info] 
>**S** stands for **source**, 
>**D** stands for **destination** (destination must be register)

| Operation     | Instruction | Meaning                                                                                                                                                                                  |
| ------------- | ----------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Copy**      | mov S, D    | copy source -> destination                                                                                                                                                               |
| **Add**       | add S, D    | $D = D + S$                                                                                                                                                                              |
| **Sub**       | sub S, D    | $D = D - S$                                                                                                                                                                              |
| **Negative**  | neg D       | $D = -D$                                                                                                                                                                                 |
| **Multiply**  | imul S, D   | $D = D * S$                                                                                                                                                                              |
| **Divide**    | idiv S      | $\%rax = \%rdx:\%rax / S$<br>$\%rdx = \%rdx:\%rax \% S$<br>**(S must be register)**<br><br>==Result== of Divide will store in **%rax**<br>==Remainder== of Divide will store in **%rdx** |
| **Convert**   | cqto        | Extend %rax to %rdx:%rax                                                                                                                                                                 |
| **Increment** | inc D       | D = D + 1                                                                                                                                                                                |
| **Decrement** | dec D       | D = D - 1                                                                                                                                                                                |
### To Validate Div use:
$$
\frac{(\%rdx+2^{64})+\%rax}{S}
$$
### Exercise 
**Let $\%rax = 1, \%rcx = 1024, \%rdx = 64.$
Wrtie the output of the following instructions.** 

```asm
add %rcx,%rax ; %rax = 1025
neg %rax ; %rax = 1025
idiv %rcx ; %rax = 1, %rdx = 1
```

| Operation                | Instruction | Meaning                                                                                                                   |
| ------------------------ | ----------- | ------------------------------------------------------------------------------------------------------------------------- |
| **Bitwise And**          | and S, D    | *D = D \& S*                                                                                                              |
| **Bitwise Or**           | sub S, D    | *D = D \| S*                                                                                                              |
| **Bitwise Xor**          | xor S, D    | *D = D ^ S*                                                                                                               |
| **Bitwise Not**          | not D       | *D = ~D*                                                                                                                  |
| **Left Shift**           | shl S, D    | *D = D << S*<br>from `0010` -> `0100`<br>shift 1 time is mul by 2                                                         |
| **Unsigned Right Shift** | shr S, D    | *D = D >>> S*<br>from `1001` -> `0100`<br>shift 1 time is div                                                             |
| **Signed Right Shift**   | sar S, D    | *D = D >> S*<br>from `1001` -> `1100`<br>1. copy 1st bit from left<br>2. rm last bit out<br>3. push from left with copied |
| **Push**                 | push S      | Push S on system stack                                                                                                    |
| **Pop**                  | pop D       | Pop from system stack into D                                                                                              |


---
## 🔗 Related Notes & References
- [[CS221]] — Main Course Index for Computer Architecture
- [[Register Architectures]] — Register-Register vs. Register-Memory models
- [[General Purpose]] — GPRs, integer representations, and addressing modes
- [[Concurrency of CPU]] — Hardware pipelining and levels of parallelism
