---
type: lecture
description:
---
#Week3 
# Lesson

## General Purpose Integer Register
**relate:** ![[221_02.pdf#page=5]]
### Integer

**Integer** use 32 bits or 4 bytes register size, and it has 2 versions

1. **unsigned integer:** not include negative number, start from 0 in range (**0 to 4,294,967,295**)
2. **signed integer:** include negative number from range (**-2,147,483,648 to 2,147,483,647**)
#### Binary Version of integer

**Unsigned vs Signed** (Super Short)

| bin       | dec (unsigned) | dec (signed) |
| --------- | -------------- | ------------ |
| 1000 0000 | 128            | -1           |

>[!question] How to convert from positive int to negative int

**We have 5 (0101) and we want -5:**
To do that, swap bit from ==1 -> 0== and ==0 -> 1== then add with 1 
**example** 5 is 0101 -> 1010 (equal -4) -> 1010 + 0001 = 1011 equal -5!

### Register

Register for x86_64 refer to each register with its name

![[221_02.pdf#page=7]]

## Assembly Language

In **intel/amd** assembly define:
**OP** B, A ; meaning A op B

### Operands

==Three types of operands== can used in assembly instructions
1. Register is referred by its name.
2. Constant is any numerical literal preceded with a \$.
3. Memory location can be referred to in several ways. 
	- A way to refer to a memory location is called an addressing mode.

> [!note] '0x' refer to hex  and '0b' refer to bin

![[221_02.pdf#page=11]]

From the table if we didn't add \$ in the front, that may refer to memory address instread, if course for (%rax) is meaning Mem[Data of %rax] 

**example** if %rax = 1, so ==(%rax) is address at 0x1==
```asm
xor %rax, %rax ; = 0
```
