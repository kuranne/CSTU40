---
type: lecture
title: Concurrency, Parallelism & Computer Architecture
course_code: CS221
week: 1
tags:
  - computer-architecture
  - concurrency
  - parallelism
  - pipelining
  - von-neumann
  - harvard-architecture
description: Understanding Thread-Level Concurrency, Instruction-Level Parallelism (ILP), Hardware Organization, Multi-core Systems, and Von Neumann vs Harvard Architectures.
---

# ⚡ Concurrency, Parallelism & Computer Architecture

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS221]] > [[Concurrency of CPU]]
> **Related Notes:** [[Instructions]] \| [[Register Architectures]] \| [[General Purpose]] \| [[CS221]]

---

## 1. Levels of Parallelism in Modern Systems

To maximize performance, modern computing systems implement concurrency and parallelism across three hierarchical tiers:

```
                    ┌─────────────────────────────────────────┐
                    │          Levels of Parallelism          │
                    └─────────────────────────────────────────┘
                                         │
        ┌────────────────────────────────┼────────────────────────────────┐
        ▼                                ▼                                ▼
1. Thread-Level              2. Instruction-Level            3. SIMD / Data-Level
   Concurrency (TLP)            Parallelism (ILP)               Parallelism
   - Multiple Threads/Cores     - Pipelining & Superscalar      - Vector processing
   - Hyperthreading (SMT)       - 5-stage CPU Pipeline          - AVX, SSE, ARM NEON
```

### 1.1 Thread-Level Concurrency (TLP)
- Allows multiple control flows (threads/processes) to execute concurrently across multiple CPU cores or virtual threads.
- Enabled by **Multi-core Processors** and **Simultaneous Multi-Threading (SMT / Hyperthreading)**.

### 1.2 Instruction-Level Parallelism (ILP)
- Overlaps the execution of multiple instructions within a single core using **Instruction Pipelining** and **Superscalar Execution**.
- The classic 5-Stage RISC Pipeline executes five operational phases:
  1. **IF (Instruction Fetch):** Fetches instruction from memory/I-Cache using the Program Counter (PC).
  2. **ID (Instruction Decode):** Decodes opcode, identifies operands, and reads register file.
  3. **EX (Execute):** Performs ALU operation or computes effective memory addresses.
  4. **MEM (Memory Access):** Reads/writes operands from/to data cache/memory.
  5. **WB (Write-Back):** Writes computation results back into the register file.

```
Clock Cycle:   1    2    3    4    5    6    7
Inst 1:       [IF] [ID] [EX] [MEM][WB]
Inst 2:            [IF] [ID] [EX] [MEM][WB]
Inst 3:                 [IF] [ID] [EX] [MEM][WB]
```

### 1.3 SIMD Parallelism (Single Instruction, Multiple Data)
- Executes a single instruction simultaneously across multiple data points in packed vector registers.
- Heavily utilized in graphics processing, digital signal processing (DSP), scientific simulation, and Machine Learning kernels (Intel AVX/SSE, ARM NEON).

---

## 2. Hardware Organization of a System

### 2.1 Multi-core Processors
- Integrates multiple independent processing units (**Cores**) onto a single integrated-circuit die.
- Each core possesses dedicated L1 caches and register sets, while sharing higher-level caches (L3 Cache) and system bus interfaces.

### 2.2 Hyperthreading / Simultaneous Multi-Threading (SMT)
- Architectural technique allowing a single physical CPU core to maintain multiple architectural states, appearing to the OS as multiple **Logical Processors**.
- Interleaves thread execution dynamically to minimize pipeline bubbles caused by high-latency memory stalls.
- *Example:* A quad-core CPU with SMT can execute 8 concurrent threads.

---

## 3. Computer Architecture vs. Computer Organization

| Dimension | Computer Architecture | Computer Organization |
| :--- | :--- | :--- |
| **Definition** | System attributes visible to the assembly programmer / compiler (The ISA). | Operational units and internal hardware interconnections realizing the architectural spec. |
| **Design Focus** | Instruction set, addressing modes, register width, data type formats. | Hardware multiplier units, pipeline stage depth, branch predictor algorithms, cache hierarchy. |

---

## 4. Architectural Paradigms: Von Neumann vs. Harvard

```
  Von Neumann Architecture                 Harvard Architecture
┌───────────────────────────┐         ┌──────────────┐    ┌──────────────┐
│       CPU / Processor     │         │  Instr Mem   │    │  Data Mem    │
└─────────────┬─────────────┘         └───────┬──────┘    └──────┬───────┘
              │ (Shared Bus)                  │ (Inst Bus)       │ (Data Bus)
┌─────────────┴─────────────┐                 └───────┬───┬──────┘
│ Shared Memory (Data+Inst) │                         │CPU│
└───────────────────────────┘                         └───┘
```

### 4.1 The Von Neumann Architecture
- **Core Principle:** Program instructions and runtime data share the **same unified physical memory** and address/data bus.
- **Von Neumann Bottleneck:** Throughput is strictly constrained because the CPU cannot read an instruction and read/write data simultaneously over the shared bus.

### 4.2 The Harvard Architecture
- **Core Principle:** Physically separates instruction memory/bus from data memory/bus.
- **Advantage:** Enables simultaneous instruction fetch and operand memory access.

### 4.3 Modified Harvard Architecture (Modern Practice)
- Modern processors (Intel Core, AMD Ryzen, Apple Silicon, ARM Cortex) employ a Modified Harvard model:
  - **Level 1 Cache:** Split into dedicated **L1 Instruction Cache (I-Cache)** and **L1 Data Cache (D-Cache)** on-chip to eliminate pipeline memory stalls.
  - **Lower Memory Tiers:** Unified L2/L3 caches and main system RAM (Unified memory for cost and programming convenience).

---

## 🔗 Related Notes & References
- [[CS221]] — Main Course Index for Computer Architecture
- [[Instructions]] — ISA categories and instruction decoding
- [[Register Architectures]] — Register-Register vs. Register-Memory models
- [[General Purpose]] — GPRs, integer representation, and addressing modes
