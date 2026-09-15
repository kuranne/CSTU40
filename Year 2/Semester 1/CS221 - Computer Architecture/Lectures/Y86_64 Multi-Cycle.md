---
type: lecture
title: "Y86-64 Multi-Cycle Processor Architecture"
class: CS221
semester: Year 2 Semester 1
week: 6
tags:
  - computer-architecture
  - y86-64
  - multi-cycle
  - datapath
  - control-unit
  - cstu40
description: "Multi-cycle implementation of Y86-64 processor architecture, cycle-by-cycle stage execution, temporary registers, control signals, and control unit design."
created: 2026-09-15
updated: 2026-09-15
parent: "CS221"
---

# Y86_64 Multi-Cycle

> **Related Notes:** [[CS221]] | [[Y86_64]] | [[Instructions]] | [[Concurrency of CPU]] | [[Exercise]]

---

## 1. Single-Cycle vs. Multi-Cycle Motivation

> [!faq] Limitation of Single-Cycle Implementation
> - The single-cycle implementation is constrained to use only **one clock cycle** for every type of instruction.
> - The clock period must be sufficiently long to accommodate the worst-case critical path (covering all computation stages), even though many instructions require only a subset of these steps.
> - The performance and clock frequency of the processor can be significantly improved if we shorten the clock cycle period and execute instructions across variable numbers of cycles.
> 
> ![[Screenshot 2569-09-15 at 14.14.49.png]]

> [!note] Multi-Cycle Implementation Principles
> - The multi-cycle implementation performs only a subset of computation steps (typically one logical stage: Fetch, Decode, Execute, Memory, Write-Back, PC Update) in each cycle.
> - Consequently, the clock period is much shorter than in the single-cycle architecture.
> - Individual instructions require multiple cycles to complete, but simpler instructions finish faster than complex memory-referencing instructions.
> 
> ![[Screenshot 2569-09-15 at 14.15.22.png]]

One clock cycle is allocated for executing one stage. Different instruction types require different numbers of cycles, yielding variable execution times.

---

## 2. Datapath & Temporary Registers

To maintain intermediate values across multiple clock cycles, dedicated **temporary storage registers** are introduced into the datapath:
- Intermediate values (`ir`, `valP`, `valA`, `valB`, `valE`, `valM`, `PC`) must persist across cycle transitions.
- Control signals (e.g., `irWrite`, `valPWrite`, `valAWrite`, `valBWrite`, `valEWrite`, `valMWrite`, `pcWrite`) govern register latching:
  - Set to ==1==: Update the corresponding temporary storage register on the next clock edge.
  - Set to ==0==: Preserve the current register contents unchanged.

### Execution Trace Examples

#### A. `nop` Instruction (2 Cycles)
The `nop` instruction only requires instruction fetching and program counter advancement:

| Cycle | irWrite | valPWrite | valAWrite | valBWrite | valEWrite | valMWrite | pcWrite |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **1. Fetch** | 1 | 1 | 0 | 0 | 0 | 0 | 0 |
| **2. PC Update** | 0 | 0 | 0 | 0 | 0 | 0 | 1 |

#### B. `irmovq V, rB` Instruction (4 Cycles)
Execution breakdown for moving an immediate constant into register `rB`:

| Cycle | irWrite | valPWrite | valAWrite | valBWrite | valEWrite | valMWrite | pcWrite |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **1. Fetch** | 1 | 1 | 0 | 0 | 0 | 0 | 0 |
| **2. Execute** | 0 | 0 | 0 | 0 | 1 | 0 | 0 |
| **3. Write Back** | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| **4. PC Update** | 0 | 0 | 0 | 0 | 0 | 0 | 1 |

---

## 3. Control Unit Design

To design a finite state machine (FSM) control unit for the multi-cycle implementation:
1. Map out the exact stage sequence and cycle count for every instruction in the Y86-64 ISA.
2. Formulate truth tables for active write-enable and multiplexer selector signals at each state.
3. Advance states synchronously based on `icode` / `ifun` until `PC Update` completes, then transition back to `Fetch`.
