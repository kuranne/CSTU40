---
type: lecture
title: System Engineering Principles & Lifecycle Methods
course_code: CS261
week: 2
tags:
  - software-engineering
  - system-engineering
  - system-lifecycle
  - cstu40
description: Core components of system engineering, functional partitioning, component interactions, and the 7-phase system engineering lifecycle.
---

# 🏗️ System Engineering

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS261]] > [[System Engineer]]
> **Related Notes:** [[Introduction to Software Engineering]] | [[Software Process]] | [[Cost of Development]] | [[CS261]]

---

## 1. Core Components of System Engineering

System engineering encompasses five fundamental activities:
1. **Purpose of System Definitions:** Clearly defining system goals, mission objectives, and stakeholder expectations.
2. **Frame of System Definitions:** Establishing system boundaries, operational environment constraints, and interfaces.
3. **Partitioning:** Splitting the system into multiple partitions/sub-systems based on architectural properties or functional usage.
4. **Component Relationships:** Analyzing interactions, dependencies, and communication protocols between sub-systems.
5. **I/O & Processing Definitions:** Formally defining Inputs, Outputs, Transformation Processes, and Result specifications.

---

## 2. System Engineering Lifecycle Methods

```mermaid
flowchart LR;
	A[Requirement Definitions] ---> B[System Design]
	B ---> C[Sub-system Development]
	C ---> D[System Integration]
	D ---> E[System Installation]
	E ---> F[System Evolution]
	F --> G[System Decommission]
```

> [!note] **Phase Breakdown:**
> 1. **Requirement Definitions:** Elicit and specify functional and operational requirements.
> 2. **System Design:** Architectural modeling, component breakdown, and interface definition.
> 3. **Sub-system Development:** Independent engineering and unit testing of sub-modules.
> 4. **System Integration:** Assembling sub-systems into a unified operational system.
> 5. **System Installation:** Deployment to target hardware environments and user acceptance.
> 6. **System Evolution:** Continuous maintenance, enhancement, and adaptation to changing requirements.
> 7. **System Decommission:** Phased retirement, data migration, and hardware/software disposal.
