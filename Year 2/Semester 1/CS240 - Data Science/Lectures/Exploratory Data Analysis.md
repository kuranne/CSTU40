---
type: lecture
title: Exploratory Data Analysis (EDA)
course_code: CS240
week: 4, 5
tags:
  - data-science
  - eda
  - data-analysis
  - visualization
  - dataprep
  - cstu40
description: "Principles and processes of Exploratory Data Analysis (EDA), univariate and multivariate analysis, anomaly detection, and Python DataPrep library tools."
created: 2026-09-04
updated: 2026-09-05
---

# 🔍 Exploratory Data Analysis (EDA)

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS240]] > [[Exploratory Data Analysis]]
> **Related Notes:** [[CS240]] | [[Data Cleaning]] | [[Data Science Process]] | [[Type Of Data]]
> **Practice Labs:** `Labs/Week5/Practice_EDA_using_Pandas.ipynb`

---

## 📌 Keywords & Research Topics

- [ ] **Explainable AI**
- [ ] **EDA with Heart Disease** (example in `Private/Docs/3.EDA.pdf`)

---

## 1. Definition & Core Objectives

**Exploratory Data Analysis (EDA)** refers to the critical process of ==performing initial investigations== on data so as to discover patterns, to ==spot anomalies==, to ==test hypotheses==, and to ==check assumptions== with the help of summary statistics and graphical representations.

![[Screenshot 2569-09-04 at 10.07.10.png]]

---

## 2. EDA Process

- **Distinguish Attributes** — Select & prepare data by choosing from attributes.
- **Univariate Analysis** — Single-variable analysis to examine each attribute's individual distribution and behavior.
- **Bi-/Multivariate Analysis** — Multi-variable analysis to explore correlations, interactions, and relationships.
- **Detect Aberrant and Missing Values** — Identify nulls, corrupted entries, and structural errors.
- **Detect Outliers** — Analyze anomalies deviating from median, IQR bounds, or standard deviations.
- **Feature Engineering** — Transform or create new attributes to enrich predictive modeling.

---

## 3. DataPrep (Python Acceleration Library)

> [!tip] Accelerated Automated EDA
> **DataPrep** offers high-performance automated exploratory tools for Pandas and Dask DataFrames.

- **`DataPrep.EDA`:** The fastest and easiest EDA tool in Python. Allows data scientists to understand a Pandas/Dask DataFrame with a few lines of code in seconds.
- **`DataPrep.Clean`:** Provides a large suite of functions with a unified interface for cleaning and standardizing data across semantic types.
- **`DataPrep.Connector`:** Supports loading data from databases through SQL queries, accelerating `pandas.read_sql` by up to 10× with 3× lower memory usage.
