---
type: lecture
description:
---
# Lesson

## Register Architectures

How instruction set can refer to value
### Register-Register Architecture

allow operant only for Register, must load value from memory to register first
![[Screenshot 2026-08-13 at 13.45.12.png|221]]
```asm
load M,R ; Mem[M] -> R
store R,M ; R -> Mem[M]
add R1, R2, R3 ; R2 = R1 + R2
sub R1, R2, R3 ; R2 = R2 - R1
```

### Register-Memory Architecture

allow operant can use memory directly, or can also be regis-regis though.
```asm
load M, R ; Mem[M] -> R
store R, M ; R -> Mem[M]

add R1, R2 ; R2 = R2 + R1
add R1, M ; M = M + R1
add M, R1 ; R1 = R1 + M

sub R1, R2 ; R2 = R2 - R1
sub R1, M ; M = M - R1
sub M, R1 ; R1 = R1 - M
```

## Quiz

**exercise 1.5:** A = (A + B) - (C + D) - E
```asm
load A, R1
load B, R2
add R1, R2, R1

load C, R2
load D, R3
add R2, R3, R2

load E, R3
sub R2, R1, R1
sub R3, R1, R1
store R1, A
```

**exercise 1.6:** A = (A + B) - (C + D) - E
```asm
load A, R1
add B, R1

load C, R2
add D, R2

sub R2, R1
sub E, R1

store R1, A
```

# Exercise
1. A = (A + B) - (C + D + E) + F
	1. ใช้ Accumulator Architecture
	2. ต้องมี 7 Instruction เท่านั้น
```asm
1. load A
2. add B
3. sub C
4. sub D
5. sub E
6. add F
7. store A
```

2.  Convert from accumulator architecture into formula
```asm
load A
sub B
add C
store A
```
   **Ans:** A = A - B + C

3. Convert from this into formula
```asm
push A
push B
push C

sub
sub

pop A
```

A = A - (B - C)
