---
type: lecture
description:
---
# Lesson

## Instructions Set

**including**

- Instructions
- Temporary Storage
- Address modes specifying memory locations
  **examples:** iA32, x86_64 or AMD64, ARM64v8

### Instructions

| ISA  | MC/Asm                                                                     |
| ---- | -------------------------------------------------------------------------- |
| ARM  | 1110 0010 1000 0110 0110 0000 0000 0001<br>add r6, r6, #1 ; plus r6 with 1 |
| iA32 | 0100 0000<br>inc %eax                                                      |

### Temporary Storage

Temp is used for an area in the processor, but for dev we use for store the value.
We can classify ISA to
1. [Accumulator Architecture](#### Accumulator Architecture)
2. [Stack Architecture](#### Stack Architecture)
3. [General-Purpose Register Architecture](#### General-Purpose Register Architecture)
#### Accumulator Architecture

Accumulator Register
![[Screenshot 2026-08-11 at 13.49.05.png|225]]

Instructions set of accumulator
1. load M
2. store M
3. add M
4. sub M

#### Stack Architecture

**Stack Pointer**
To add value, use push.
Another way ,use pop.
![[Screenshot 2026-08-11 at 14.16.35.png|279]]
<small>Often found in JVM</small>

Instructions set of stack
1. push M : stack[top] <- Mem[M]
2. pop M : Mem[M] <- stack[top] 
3. add : stack [top] <- stack [top] + stack [top - 1]
4. sub : stack [top] <- stack [top - 1] - stack [top] ; Must load bigger one first

**example** C = A + B
```asm
push A ; stack [A]
push B ; stack [A, B] buttom <- top
add ; stack [ B + A ]
pop C ; C = B + A 
```

#### General-Purpose Register Architecture

each register called by its name
1. Register-register architecture (ARM) *Can olny use register as operator*
2. Register-memory architecture (Intel) *Also use memory as operator*
### Quiz

1. **convert A = (A + B) - (C + D) - E to assembly**

```asm
load A
add B ; A + B
store A ; A = A + B

load C
add D ; C + D
store C ; C = C + D

load A
sub C ; A - C

sub E ; A - C - E
store A ; A = A - C - E
```

**Bangpun Model**
A = (A + B) - (C + D) - E -> A = A + B - C - D - E

```asm
load A
add B
sub C
sub D
sub E
store A
```

2. **convert A = (A + B) - (C + D) - E

```asm
push B ; stack [B]
push A ; stack [B, A]
add ; stack [A + B]
pop A ; A = A + B

push D ; stack [D]
push C ; stack [D, C]
add ; stack [C + D]
pop C ; C = C + D

push A ; stack [A]
push C ; stack [A, C]
push E ; stack [A, C, E]
sub ; stack [A, C - E]
sub ; stack [A - C - E]

pop A ; A = A - C - E
```