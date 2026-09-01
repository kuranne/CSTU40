---
type: lecture
title: Assembly Language Compilation & Toolchain Pipeline
course_code: CS221
week: 2, 4
tags:
  - computer-architecture
  - assembly
  - x86-64
  - compilation-pipeline
  - elf64
  - cstu40
description: x86_64 assembly compilation pipeline from source assembly to machine instructions, linking with standard libraries, and executable binary generation.
---

# ⚙️ Assembly Program

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS221]] > [[Assembly]]
> **Related Notes:** [[Instructions]] | [[General Purpose]] | [[Register Architectures]] | [[Exercise]] | [[CS221]] | [[CS102]]

---

## 1. Specification & Target Architecture
- **Architecture Specification:** ==Intel / AMD64 (x86_64)==
- **Binary / Object Format:** `ELF64` (Executable and Linkable Format, 64-bit)

---

## 2. Compilation & Linking Toolchain

```mermaid
flowchart TD
	AssemblySource["Assembly Source (*.s / *.asm)"] --> Assembler["Assembler (as / nasm / gcc)"]
	Assembler --> MachineInstructions["Relocatable Object File (*.o)"]
	MachineInstructions --> Linker["Linker (ld)"]
	StandardLib["Standard Libraries / Runtime (libc)"] --> Linker
	Linker --> ExecutableProgram["ELF64 Executable Binary (a.out)"]
```

> [!note] **Toolchain Stages:**
> 1. **Assembler (`as`):** Translates human-readable mnemonic assembly source code into binary machine instructions and relocatable object files (`.o`).
> 2. **Linker (`ld`):** Combines object files with system runtimes and standard shared/static libraries to resolve external symbol references and generate the final runnable executable.
> 3. **Connection to C Foundations:** Connects to compilation concepts from [[CS102]] and low-level memory layout in [[CS213#Memory Management]].
