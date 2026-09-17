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
updated: 2026-09-17
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

> [!abstract] Multi-Cycle Control Unit FSM (CS221 Docs #4, pp. 14–15)
> Unlike single-cycle processors where control signals are combinational logic driven in one cycle, the multi-cycle Control Unit operates as a synchronous **Finite State Machine (FSM)** consisting of:
> 1. **State Register**: Holds the current execution state (step) and advances on clock edges.
> 2. **Next-State Logic (Combinational)**: Determines the next state based on the current state, instruction code (`icode`), function code (`ifun`), and branch condition evaluation (`Cnd`).
> 3. **Output / Control Signal Logic (Combinational)**: Asserts the datapath control signals (temporary register write enables, multiplexer selectors, ALU functions, memory read/write) corresponding to the current state.

### Multi-Cycle Control Signal Matrix

| Stage / State | `irWrite` | `valPWrite` | `valAWrite` | `valBWrite` | `valEWrite` | `valMWrite` | `pcWrite` | Notes |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :--- |
| **Fetch** | 1 | 1 | 0 | 0 | 0 | 0 | 0 | Reads `ir = M1[PC]`, computes `valP = PC + len` |
| **Decode** | 0 | 0 | 1 | 1 | 0 | 0 | 0 | Reads source registers into `valA`, `valB` |
| **Execute** | 0 | 0 | 0 | 0 | 1 | 0 | 0 | ALU operation / effective address calculation; evaluates `Cnd` |
| **Memory Read** | 0 | 0 | 0 | 0 | 0 | 1 | 0 | Reads memory word into temporary register `valM` |
| **Memory Write** | 0 | 0 | 0 | 0 | 0 | 0 | 0 | Writes `valA` or `valP` to memory at address `valE` |
| **Write-Back** | 0 | 0 | 0 | 0 | 0 | 0 | 0 | Writes `valE` or `valM` back to register file |
| **PC Update** | 0 | 0 | 0 | 0 | 0 | 0 | 1 | Updates `PC` with next instruction address; loops to Fetch |

### Control Unit Finite State Machine (FSM) Diagram

```mermaid
flowchart TD
    %% Styling
    classDef fetch fill:#1e293b,stroke:#38bdf8,stroke-width:2px,color:#f8fafc;
    classDef stage fill:#0f172a,stroke:#94a3b8,stroke-width:1px,color:#e2e8f0;
    classDef pc fill:#064e3b,stroke:#34d399,stroke-width:2px,color:#f0fdf4;

    %% Fetch State
    S0["<b>State 0: Fetch</b><br/>ir &larr; M[PC], valP &larr; PC + len<br/><i>irWrite=1, valPWrite=1</i>"]:::fetch

    %% Decode States
    S1_dec["<b>Decode (OPq / rmmovq)</b><br/>valA &larr; R[rA], valB &larr; R[rB]<br/><i>valAWrite=1, valBWrite=1</i>"]:::stage
    S2_dec["<b>Decode (rrmovq / cmovXX)</b><br/>valA &larr; R[rA]<br/><i>valAWrite=1</i>"]:::stage
    S3_dec["<b>Decode (mrmovq)</b><br/>valB &larr; R[rB]<br/><i>valBWrite=1</i>"]:::stage
    S4_dec["<b>Decode (pushq / popq / call / ret)</b><br/>valB &larr; R[%rsp]<br/><i>valBWrite=1</i>"]:::stage

    %% Execute States
    S_ex_irmovq["<b>Execute (irmovq)</b><br/>valE &larr; 0 + V<br/><i>valEWrite=1</i>"]:::stage
    S_ex_op["<b>Execute (OPq)</b><br/>valE &larr; valB OP valA, Set CC<br/><i>valEWrite=1</i>"]:::stage
    S_ex_cmov["<b>Execute (rrmovq / cmovXX)</b><br/>valE &larr; valA + 0, eval Cnd<br/><i>valEWrite=1</i>"]:::stage
    S_ex_addr["<b>Execute (rmmovq / mrmovq)</b><br/>valE &larr; valB + D<br/><i>valEWrite=1</i>"]:::stage
    S_ex_stack_dec["<b>Execute (pushq / call)</b><br/>valE &larr; valB - 8<br/><i>valEWrite=1</i>"]:::stage
    S_ex_stack_inc["<b>Execute (popq / ret)</b><br/>valE &larr; valB + 8<br/><i>valEWrite=1</i>"]:::stage
    S_ex_jump["<b>Execute (jXX)</b><br/>eval Cnd"]:::stage

    %% Memory States
    S_mem_write["<b>Memory Write (rmmovq)</b><br/>M[valE] &larr; valA"]:::stage
    S_mem_read["<b>Memory Read (mrmovq)</b><br/>valM &larr; M[valE]<br/><i>valMWrite=1</i>"]:::stage
    S_mem_push["<b>Memory Write (pushq / call)</b><br/>M[valE] &larr; valA (or valP)"]:::stage
    S_mem_pop["<b>Memory Read (popq / ret)</b><br/>valM &larr; M[valA]<br/><i>valMWrite=1</i>"]:::stage

    %% Write-Back States
    S_wb_reg["<b>Write-Back (irmovq / OPq / cmovXX)</b><br/>R[rB] &larr; valE"]:::stage
    S_wb_mem["<b>Write-Back (mrmovq)</b><br/>R[rA] &larr; valM"]:::stage
    S_wb_stack["<b>Write-Back (pushq / popq / call / ret)</b><br/>R[%rsp] &larr; valE (+ R[rA] &larr; valM for popq)"]:::stage

    %% PC Update State
    S_pc["<b>State: PC Update</b><br/>PC &larr; newPC (valP / dest / valM)<br/><i>pcWrite=1</i>"]:::pc

    %% Transitions from Fetch
    S0 -->|nop| S_pc
    S0 -->|irmovq| S_ex_irmovq
    S0 -->|OPq| S1_dec
    S0 -->|rmmovq| S1_dec
    S0 -->|rrmovq / cmovXX| S2_dec
    S0 -->|mrmovq| S3_dec
    S0 -->|pushq / call| S4_dec
    S0 -->|popq / ret| S4_dec
    S0 -->|jXX| S_ex_jump

    %% Transitions from Decode
    S1_dec -->|OPq| S_ex_op
    S1_dec -->|rmmovq| S_ex_addr
    S2_dec --> S_ex_cmov
    S3_dec --> S_ex_addr
    S4_dec -->|pushq / call| S_ex_stack_dec
    S4_dec -->|popq / ret| S_ex_stack_inc

    %% Transitions from Execute
    S_ex_irmovq --> S_wb_reg
    S_ex_op --> S_wb_reg
    S_ex_cmov --> S_wb_reg
    S_ex_addr -->|rmmovq| S_mem_write
    S_ex_addr -->|mrmovq| S_mem_read
    S_ex_stack_dec --> S_mem_push
    S_ex_stack_inc --> S_mem_pop
    S_ex_jump --> S_pc

    %% Transitions from Memory
    S_mem_write --> S_pc
    S_mem_read --> S_wb_mem
    S_mem_push --> S_wb_stack
    S_mem_pop --> S_wb_stack

    %% Transitions from Write-Back
    S_wb_reg --> S_pc
    S_wb_mem --> S_pc
    S_wb_stack --> S_pc

    %% Return to Fetch
    S_pc ==>|Loop to next instruction| S0
```

---
