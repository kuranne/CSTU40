---
type: lecture
title: Software Development Economics & Maintenance Cost Analysis
course_code: CS261
week: 3
tags:
  - software-engineering
  - cost-of-development
  - software-maintenance
  - software-economics
  - boehm-curve
description: Economic breakdown of software lifecycle costs, development phase distributions, the 4 types of maintenance, and key cost drivers.
---

# 💰 Software Development Economics & Maintenance Cost Analysis

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS261]] > [[Cost of Development]]
> **Related Notes:** [[Introduction to Software Engineering]] \| [[Classified Software]] \| [[CS261]]

---

## 1. Drivers of Software Evolution

Software is never static; it must continuously adapt to evolving internal and external environments:
1. **Technology Advancements:** Rapid 3–5 year hardware cycles, runtime updates, compiler optimizations, and modern architectural paradigms.
2. **Legal & Regulatory Shifts:** Data privacy compliance (GDPR, PDPA), international tax laws, and industry-mandated cybersecurity standards.
3. **Business & Competitive Dynamics:** Evolving organizational strategies, competitor offerings, and continuous user demand for new features.

---

## 2. Total Cost of Ownership (TCO) & Lifecycle Economics

Over the operational lifetime of an enterprise software product, financial expenditure follows a classic **30% Development vs. 70% Maintenance** distribution:

```
┌───────────────────────────────────┬───────────────────────────────────────────────────────────────────┐
│     Initial Development (~30%)    │                      Ongoing Maintenance (~70%)                   │
└───────────────────────────────────┴───────────────────────────────────────────────────────────────────┘
```

> [!warning] Key Takeaway:
> Initial development cost is merely the "tip of the iceberg." The overwhelming majority of software expenditure is incurred post-release during long-term maintenance and evolution.

---

## 3. Development Effort Distribution by Phase

```
                            ┌───────────────────────────────┐
                            │    Development Effort (~30%)  │
                            └───────────────────────────────┘
                                            │
        ┌───────────────────────────────────┼───────────────────────────────────┐
        ▼                                   ▼                                   ▼
 1. Requirements & Design           2. Coding & Implementation          3. Testing & QA
    (~33.3%)                           (~16.7%)                            (~50.0%)
    - Domain analysis                   - Clean code construction           - Unit, Integration,
    - Architectural design              - Should **not exceed 20%**           System, & Security tests
```

- **50.0% — Testing & Quality Assurance (QA):** Defect detection, automated test suites, performance benchmarks, and security verification.
- **33.3% — Requirements Engineering & Architectural Design:** Elicitation, specification, system decomposition, and interface contracts.
- **16.7% — Coding & Implementation:** Concrete code construction, representing a relatively small fraction of total development effort (typically capped below 20%).

---

## 4. The Four Types of Software Maintenance (Lientz & Swanson Model)

```
                            ┌───────────────────────────────┐
                            │    Software Maintenance (70%) │
                            └───────────────────────────────┘
                                            │
     ┌──────────────────────┬───────────────┴───────────────┬──────────────────────┐
     ▼                      ▼                               ▼                      ▼
1. Corrective          2. Adaptive                     3. Perfective          4. Preventive
   (20% - 25%)            (15% - 20%)                     (50% - 55%)            (5% - 10%)
   Urgent bug fixing      Platform/OS adaptation          Feature enhancement    Proactive refactoring
```

| Maintenance Type | Cost Share | Primary Objective | Real-World Scenario |
| :--- | :---: | :--- | :--- |
| **1. Corrective Maintenance** | 20% – 25% | Diagnosing and repairing bugs, logic errors, and security vulnerabilities discovered in production. | Hotfixing a server memory leak triggered when concurrent requests exceed 10,000 req/s. |
| **2. Adaptive Maintenance** | 15% – 20% | Modifying software to maintain compatibility with shifting operational environments (OS, hardware, APIs). | Updating an enterprise iOS/Android app to comply with new OS permission models and PDPA laws. |
| **3. Perfective Maintenance** | 50% – 55% | Adding user-requested capabilities, enhancing computational throughput, and refining UI/UX. | Integrating a new one-click payment gateway and optimizing database queries to reduce page load latency. |
| **4. Preventive Maintenance** | 5% – 10% | Proactive code refactoring, reducing Technical Debt, and updating documentation to preempt future failures. | Modernizing legacy monolithic code into decoupled micro-modules to enhance maintainability. |

---

## 5. Major Software Cost Drivers

1. **Boehm's Cost of Change Curve:**
   - Resolving a defect during the Requirements phase has baseline cost ($\approx 1	imes$).
   - Resolving the same defect during Implementation increases cost ($\approx 5	imes - 10	imes$).
   - Resolving it post-release in Production incurs costs **50 to 100 times higher** due to data corruption recovery, urgent patch deployment, and client downtime.

2. **Brooks' Law:**
   > *"Adding manpower to a late software project makes it later."*
   Adding new personnel to a behind-schedule project exacerbates delays due to training overhead and exponential inter-person communication paths ($O(n^2)$ communication channels).

3. **High Multidisciplinary Skill Requirements:**
   - Modern software engineering demands broad competencies across distributed architecture, automated CI/CD pipelines, container orchestration, telemetry, and proactive cybersecurity.

---

## 🔗 Related Notes & References
- [[CS261]] — Main Course Index for Software Engineering
- [[Introduction to Software Engineering]] — Foundational principles and professional ethics
- [[Classified Software]] — Software classification taxonomies and ISO 25010
