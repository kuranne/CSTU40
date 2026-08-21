---
type: lecture
title: Introduction to Data Science & Analytics Maturity
course_code: CS240
week: 1
tags:
  - data-science
  - analytics-maturity
  - dikw-pyramid
  - machine-learning
description: Fundamental concepts of Data Science, Data vs Information (DIKW Pyramid), Data Science Venn Diagram, and the 4 Levels of Analytics Maturity.
---

# 📊 Introduction to Data Science & Analytics Maturity

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS240]] > [[The Data Science]]
> **Related Notes:** [[Data Science Process]] \| [[CS240]]
> **Reference:** `Private/Docs/CS240_Week1_Principle_of_Data_Science.pdf`

---

## 1. Foundational Questions & Definitions

### ❓ 1. What is Data Science?
**Data Science** is an interdisciplinary field that applies scientific methods, mathematical processes, algorithms, and computing systems to extract knowledge, actionable insights, and verifiable facts from structured and unstructured data to drive evidence-based decision-making.

---

### ❓ 2. The DIKW Hierarchy (Data $\rightarrow$ Information $\rightarrow$ Knowledge $\rightarrow$ Wisdom)

```
                            ┌───────────────┐
                            │    Wisdom     │  (Strategic action & evaluated understanding)
                            ├───────────────┤
                            │   Knowledge   │  (Understanding patterns, context & synthesis)
                            ├───────────────┤
                            │  Information  │  (Structured, contextualized, meaningful data)
                            ├───────────────┤
                            │     Data      │  (Raw unorganized facts and signals)
                            └───────────────┘
```

| Level | Definition | Concrete Example |
| :--- | :--- | :--- |
| **Data** | Raw, unformatted facts, signals, or measurements lacking contextual meaning. | The raw number `38.5`. |
| **Information** | Data organized, structured, and contextualized to convey meaning. | Body temperature measured at `38.5 °C` (fever state). |
| **Knowledge** | Understanding relationships, patterns, and causal rules learned from information. | A body temperature of $38.5\ ^\circ	ext{C}$ accompanied by cough indicates a respiratory infection. |
| **Wisdom** | Evaluated understanding applied to strategic decision-making and preventative action. | Ordering specific diagnostic lab tests and prescribing targeted antipyretics to prevent complications. |

---

### ❓ 3. Data Science vs. Data Analytics vs. Machine Learning

```
┌───────────────────────────────────────────────────────────────┐
│                          Data Science                         │
│                                                               │
│   ┌───────────────────────────┐   ┌───────────────────────┐   │
│   │       Data Analytics      │   │   Machine Learning    │   │
│   │ (Historical analysis/KPIs)│   │ (Predictive modeling) │   │
│   └───────────────────────────┘   └───────────────────────┘   │
│                 ┌───────────────────────────┐                 │
│                 │      Data Engineering     │                 │
│                 │   (Pipelines & databases) │                 │
│                 └───────────────────────────┘                 │
└───────────────────────────────────────────────────────────────┘
```

- **Data Analytics:** Focuses on inspecting, transforming, and modeling historical datasets to address specific diagnostic and business questions.
- **Machine Learning:** Develops statistical algorithms and predictive models capable of generalizing and learning autonomously from training data.
- **Data Science:** The end-to-end discipline spanning problem formulation, data engineering, statistical modeling, machine learning, and data storytelling.

---

## 2. The Data Science Venn Diagram (Drew Conway's Model)

Modern Data Science sits at the convergence of three foundational domains:

```
                      ┌──────────────────────┐
                      │   Computer Science   │
                      │  & Hacking Skills    │
                      └──────────┬───────────┘
                                 │
                   ┌─────────────┼─────────────┐
                   ▼             ▼             ▼
              ┌─────────┐   Machine    ┌─────────┐
              │ Danger  │   Learning   │Traditional
              │  Zone   │              │Research │
              └─────────┘              └─────────┘
                   ▲             ▲             ▲
                   │             │             │
        ┌──────────┴──────────┐  │  ┌──────────┴──────────┐
        │   Business / Domain │◄─┼─►│ Math & Statistics   │
        │      Knowledge      │  │  │      Knowledge      │
        └─────────────────────┘  │  └─────────────────────┘
                                 ▼
                         ╔═══════════════╗
                         ║ DATA SCIENCE  ║
                         ╚═══════════════╝
```

1. **Computer Science & Hacking Skills:** Programming proficiency (Python, R, SQL), algorithmic data structures, data engineering, and Big Data technologies.
2. **Math & Statistics Knowledge:** Probability theory, linear algebra, multivariable calculus, hypothesis testing, and optimization algorithms.
3. **Substantive Expertise / Domain Knowledge:** Industry-specific context (e.g., healthcare, finance, retail) essential for formulating meaningful questions and validating hypotheses.

---

## 3. Four Levels of Analytics Maturity (Gartner Model)

The Gartner Analytics Maturity Model classifies data capabilities across increasing value and implementation complexity:

```
Value  ▲
       │                                                      [4. Prescriptive]
       │                                                     (What should we do?)
       │                                         [3. Predictive]
       │                                      (What will happen?)
       │                           [2. Diagnostic]
       │                        (Why did it happen?)
       │             [1. Descriptive]
       │          (What happened?)
       └─────────────────────────────────────────────────────────────► Difficulty
```

| Analytics Level | Guiding Question | Techniques & Tooling | Real-World Application |
| :--- | :--- | :--- | :--- |
| **1. Descriptive Analytics** | *What happened?* | Summary statistics, aggregation queries, BI dashboards (Tableau, PowerBI) | Quarterly regional sales and revenue breakdown. |
| **2. Diagnostic Analytics** | *Why did it happen?* | Drill-down analysis, root cause discovery, correlation matrices, anomaly detection | Investigating why product returns surged after a recent supply chain alteration. |
| **3. Predictive Analytics** | *What will happen?* | Supervised Machine Learning (Regression, Classification), Time Series Forecasting (ARIMA, Prophet) | Forecasting customer churn risk and next-quarter inventory demands. |
| **4. Prescriptive Analytics** | *What should we do?* | Linear programming, optimization algorithms, simulation models, recommendation engines | Automated real-time dynamic pricing based on surging market demand. |

---

## 🔗 Related Notes & References
- [[CS240]] — Main Course Index for Data Science
- [[Data Science Process]] — End-to-end CRISP-DM lifecycle and methodologies
