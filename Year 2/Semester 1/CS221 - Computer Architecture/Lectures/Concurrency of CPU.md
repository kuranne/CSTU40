---
description: Learning about Concurrency of Parallelism, Hardware Organize, Computer Architecture
---

#Week1

# Lesson

## Concurrency of Parallelism

```pdf
We highlight three levels here, working from the highest to the lowest
level in the system hierarchy.
1. Thread-Level Concurrency
2. Instruction-Level Parallelism
3. Single-Instruction, Multiple-Data (SIMD) Parallelism
```

In past, they want computer to do multi-function at once.
These must includes:

1. Allow multiple control flows executing within a single process
2. Allow multiple instruction at the same time.
3. Allow a single instruction to cause multiple sperations to be performed in parallel.

#### Aim to "1. Thread-Level Parallelism"

In one process (corp cycle), there would including **fetch, decode, e, n, w**

**for example:** we have 3 process.

> the process 1st will fetch first then goto decode step, and in the same time the fetch step of 2nd will fetch while 1st process is in decoding step.

## Hardware Organization of a System

In core of cpu, we split as many of thread so in one core will manage much more tasks than normal.

```pdf
1. Multi-core processors have several CPUs (referred to as “cores”)
integrated onto a single integrated-circuit chip.
2. Hyperthreading, sometimes called simultaneous multi-threading, is a
technique that allows a single CPU to execute multiple flows of control.
3. As an example, the Intel Corei7 processor can have each core executing
two threads, and so a four-core system can actually execute eight
threads in parallel.
```

## Computer Architecture

```pdf
1. Computer architecture refers to those attributes of a system visible to
a programmer.
2. A term that is often used interchangeably with computer architecture
is instruction set architecture (ISA).
3. Computer organization refers to the operational units and their
interconnections that realize the architectural specifications.
--- Example
o Architectural design issue: a computer will have a multiply
instruction whether or not.
o Organizational issue: the multiply instruction will be implemented
by a special multiply unit or by a mechanism that makes repeated
use of the add unit of the system.

```

Computer Architecture or refer to **Instruction Set Architecture** (ISA)
`mal A, B` — multiple A with B, then store at A address.

Can divide into 2 group:

1. **The Von Neumann Machine** (can be found inside first electronic computer "EDVAC")
   Share instruction and data in the same memory. It can read either an instruction or a word of data at one time. This problem is called the Von Neumann bottleneck.
2. **Non-Von Neumann Machine**
   - Harvard Architecture (can be found inside "MARK I 1944")
   - Modified Harvard Architecture
     Cache is referred to a faster memory which stores copies of the contents of the main memory.
