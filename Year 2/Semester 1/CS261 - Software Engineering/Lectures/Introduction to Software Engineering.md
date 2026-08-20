---
type: lecture
title: Introduction to Software Engineering & Professional Principles
course_code: CS261
week: 1
tags:
  - software-engineering
  - ieee-definition
  - software-lifecycle
  - engineering-vs-programming
description: Introduction to Software Engineering principles, IEEE definition, differences between programming and engineering, the software crisis, and core disciplines.
---

# 🛠️ Introduction to Software Engineering & Professional Principles

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS261]] > [[Introduction to Software Engineering]]
> **Related Notes:** [[Classified Software]] \| [[Cost of Development]] \| [[CS261]]

---

## 1. What is Software Engineering?

> *"Software Engineering is the application of engineering to software."*

### 1.1 IEEE Standard 610.12 Definition
> **"The application of a systematic, disciplined, quantifiable approach to the development, operation, and maintenance of software; that is, the application of engineering to software."**

- **Systematic:** Follows structured, repeatable processes from requirements analysis and architectural design to testing and deployment.
- **Disciplined:** Adheres to established engineering standards, coding conventions, architectural patterns, and professional codes of ethics.
- **Quantifiable:** Measured using concrete metrics (Defect density per KLOC, Mean Time to Repair [MTTR], test coverage percentage, project budget, and schedule variance).

> [!quote] Professional Maxim:
> **"Do as an Engineer, not just a Craftsman."**
> *(Operate with standardized, verifiable engineering processes rather than relying solely on individual craftsmanship).*

---

## 2. Programmer / Developer vs. Software Engineer

```
┌───────────────────────────────────┬───────────────────────────────────┐
│     Programmer / Developer        │        Software Engineer          │
├───────────────────────────────────┼───────────────────────────────────┤
│ • Focuses on working code syntax   │ • Focuses on complete lifecycle   │
│ • Typically works solo / small    │ • Collaborates in large teams     │
│ • Focuses on immediate function   │ • Prioritizes Security & Scale    │
│ • Manages individual components   │ • Manages risks & uncertainties   │
│ • Ad-hoc short-term solutions     │ • Designs for Maintainability     │
└───────────────────────────────────┴───────────────────────────────────┘
```

> **Formal Summary Equation:**
> $$	ext{Software Engineering} = 	ext{Programming} + 	ext{Architecture} + 	ext{Quality Assurance} + 	ext{Security} + 	ext{Project Management} + 	ext{Evolution}$$

---

## 3. The Three Dimensions of Software Engineering

```
                            ┌───────────────────────────────┐
                            │   Software Engineering Core   │
                            └───────────────────────────────┘
                                            │
                     ┌──────────────────────┼──────────────────────┐
                     ▼                      ▼                      ▼
             1. Processes            2. Methods &           3. Tools
             (Frameworks)              Practices              (Automation)
             - Waterfall, Agile,       - OOP, Clean Code,     - IDEs, Git, CI/CD,
               Scrum, DevOps             TDD, Design Patterns   Jira, Docker
```

---

## 4. Three Core Disciplines of Software Engineering Projects

1. **Development (Construction & Verification):**
   - Requirements elicitation and domain modeling.
   - Architectural design, modular decomposition, and component implementation.
   - Unit testing, static analysis, and code reviews.
2. **Management (Planning & Quality Control):**
   - Project estimation (Effort, Cost, Duration) and milestone scheduling.
   - Software Quality Assurance (SQA) audits and process improvement.
   - Risk identification, contingency planning, and change management.
3. **Support & Operations (Evolution & Maintenance):**
   - Software configuration management (SCM) and continuous delivery pipelines (DevOps).
   - Production system telemetry, incident response, and ongoing patches.

---

## 5. Project Success Criteria (The Iron Triangle & Beyond)

A successful software project satisfies four core dimensions:
1. **On Schedule:** Delivers verified milestones within agreed deadlines.
2. **Within Budget:** Operates strictly within allocated financial boundaries.
3. **Quality & Scope:** Delivers robust, scalable, and secure capabilities matching specifications.
4. **Stakeholder Satisfaction:** Delivers measurable value and satisfaction to end-users, clients, and engineering teams.

---

## 🔗 Related Notes & References
- [[CS261]] — Main Course Index for Software Engineering
- [[Classified Software]] — Software classifications, domain taxonomies, and ISO 25010
- [[Cost of Development]] — Software lifecycle economics and maintenance breakdown
