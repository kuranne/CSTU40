---
type: lecture
title: Software Classification & Taxonomy
course_code: CS261
week: 1, 2
tags:
  - software-engineering
  - software-classification
  - enterprise-software
  - iso-25010
description: Taxonomy of software systems categorized by Target Users, Product Nature, Architectural Layers, Vertical vs Horizontal domains, and ISO 25010 Quality Model.
---

# 📦 Software Classification & Taxonomy

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS261]] > [[Classified Software]]
> **Related Notes:** [[Introduction to Software Engineering]] \| [[Cost of Development]] \| [[CS261]]

---

## 1. Classification by Target Customer / Market Segment

```
                            ┌───────────────────────────────┐
                            │    Classified by Customer     │
                            └───────────────────────────────┘
                                            │
        ┌───────────────────────────────────┼───────────────────────────────────┐
        ▼                                   ▼                                   ▼
 1. Consumer (B2C)                 2. Business (B2B)                   3. Government (B2G)
 - Mass market individual users    - Commercial enterprises            - Public sector & state agencies
 - Lower cost per user             - Moderate to high complexity       - Highest regulatory compliance
 - Focus on intuitive UX/UI        - Focus on reliability & workflow   - Strict national security standards
```

### 1.1 Individual Consumers (B2C — Business-to-Consumer)
- Targets individual everyday activities, entertainment, personal communication, and productivity.
- Low unit cost per user, relying on massive user volume (Mass Scale).
- Prioritizes usability, intuitive user experience (UX), and high responsiveness.

### 1.2 Commercial Enterprises (B2B — Business-to-Business)
Software designed to support domain-specific workflows across commercial industries:
1. **Retail & E-Commerce:** Point of Sale (POS) systems, inventory tracking, order management systems (OMS).
2. **Banking & Financial Services:** Core Banking systems, algorithmic trading engines, payment gateways.
3. **Healthcare:** Electronic Health Records (EHR), clinical diagnostic tools, medical device software complying with strict standards (e.g., HIPAA, FDA regulations).
4. **Manufacturing & Supply Chain:** Enterprise Resource Planning (ERP: SAP, Oracle), Industrial Automation & SCADA systems.
5. **Telecommunications:** Network management systems and high-throughput telecom billing engines.

### 1.3 Government & Public Sector (B2G — Business-to-Government)
- Governed by formal, regulated public procurement policies.
- Requires rigorous security clearances, auditing controls, and legal data residency compliance.
- Long lifecycle expectations; frequently involves maintaining and modernizing critical legacy infrastructure.

---

## 2. Classification by Product Nature (Generic vs. Bespoke)

| Product Type | Description | Representative Examples |
| :--- | :--- | :--- |
| **Generic / Off-the-shelf Software** | Standalone software developed for the broad open market to satisfy common needs. | Microsoft Office, Adobe Creative Cloud, Ubuntu Linux |
| **Bespoke / Custom-built Software** | Specialized software commissioned and developed specifically for a single client organization. | University Student Registration Systems, Custom Factory Assembly Control Systems |

---

## 3. Classification by Architectural Layer & Domain Scope

```
┌────────────────────────────────────────────────────────────────────────┐
│                        4. Platforms & Cloud Services                   │
│                        (SaaS, PaaS, IaaS, Mobile Apps)                 │
├────────────────────────────────────────────────────────────────────────┤
│                        3. Application Software                         │
│             ┌─────────────────────────┬─────────────────────────┐      │
│             │    Vertical Software    │   Horizontal Software   │      │
│             │  (Single Industry Focus)│  (Cross-Industry Focus) │      │
│             └─────────────────────────┴─────────────────────────┘      │
├────────────────────────────────────────────────────────────────────────┤
│                        2. Utility Software                             │
│                        (Antivirus, Disk Management, Backup)            │
├────────────────────────────────────────────────────────────────────────┤
│                        1. System Software                              │
│                        (OS, Drivers, Compilers, Containers)            │
└────────────────────────────────────────────────────────────────────────┘
```

1. **System Software:** Low-level programs providing core infrastructure and hardware control (Operating Systems: Linux, Windows, macOS; Device Drivers; Compilers; Hypervisors; Containers: Docker, Kubernetes).
2. **Utility Software:** System maintenance and optimization utilities (Antivirus engines, Firewalls, Disk Partitioning/Defragmentation tools, Backup managers).
3. **Application Software:**
   - **Vertical Software:** Specialized applications engineered for **one specific industry niche** (e.g., Dental Practice Management, Airline Flight Dispatch Systems).
   - **Horizontal Software:** General-purpose applications utilized across **diverse industry sectors** (e.g., Accounting software, Human Resource Management Systems [HRMS], Collaboration tools: Slack, Zoom).
4. **Platforms & Cloud Deployment Models:** SaaS (Software as a Service), PaaS, IaaS, Native Mobile Apps, Web Applications, Embedded/IoT systems.

---

## 4. ISO/IEC 25010 Software Quality Model

```
                            ┌───────────────────────────────┐
                            │    ISO/IEC 25010 Quality      │
                            └───────────────────────────────┘
                                            │
     ┌──────────────┬──────────────┬────────┼──────────────┬──────────────┬──────────────┐
     ▼              ▼              ▼        ▼              ▼              ▼              ▼
Functional    Performance    Compatibility Usability  Reliability    Security     Maintainability
Suitability    Efficiency                                                          & Portability
```

1. **Functional Suitability:** Degree to which software functions satisfy stated and implied user needs (Functional Completeness, Correctness, Appropriateness).
2. **Performance Efficiency:** Resource utilization, throughput, latency, and scalability under specified loads.
3. **Compatibility:** Capacity to exchange information and perform required functions while sharing hardware/software environments (Co-existence, Interoperability).
4. **Usability:** Ease of learning, operation, user error protection, and accessibility.
5. **Reliability:** Operational availability, fault tolerance, and recovery capabilities.
6. **Security:** Information confidentiality, data integrity, non-repudiation, accountability, and authenticity.
7. **Maintainability:** Modularity, reusability, analyzability, modifiability, and testability.
8. **Portability:** Adaptability, installability, and replaceability across diverse target environments.

---

## 🔗 Related Notes & References
- [[CS261]] — Main Course Index for Software Engineering
- [[Introduction to Software Engineering]] — Foundational principles and professional ethics
- [[Cost of Development]] — Software lifecycle cost distribution and maintenance models
