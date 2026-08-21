---
type: lecture
title: Types of Data & Measurement Scales
course_code: CS240
week: 3
tags:
  - data-science
  - data-types
  - measurement-scales
  - statistics
description: Comprehensive classification of data by Structure (Structured, Semi-Structured, Unstructured) and Scales of Measurement (Nominal, Ordinal, Interval, Ratio) with statistical properties.
---

# 📊 Types of Data & Measurement Scales

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS240]] > [[Type Of Data]]
> **Related Notes:** [[The Data Science]] | [[Data Science Process]] | [[CS240]] | [[ST329]]

---

## 1. Classification by Data Structure

In Data Science, datasets are categorized by their organizational format and schema rigidity:

```
                            ┌───────────────────────────────┐
                            │      Data Structure Types     │
                            └───────────────────────────────┘
                                            │
        ┌───────────────────────────────────┼───────────────────────────────────┐
        ▼                                   ▼                                   ▼
 1. Structured Data                 2. Semi-Structured Data             3. Unstructured Data
 - Strict tabular schema            - Partial self-describing tags      - No pre-defined data model
 - Rows and columns                 - Flexible, nested hierarchy        - Heavy volume, media, text
 - SQL, CSV, Excel                  - JSON, XML, YAML                   - Images, Audio, Video, PDF
```

| Type | Definition | Common Formats / Sources | Querying & Processing Tools |
| :--- | :--- | :--- | :--- |
| **Structured Data** | Data stored in a standardized, tabular format with strict rows, columns, and data types. Highly organized and easily searchable. | Relational Databases (PostgreSQL, MySQL), CSV files, Excel spreadsheets. | SQL, Pandas DataFrames, Spark SQL. |
| **Semi-Structured Data** | Data containing organizational markers, key-value pairs, or tags without conforming to a rigid relational schema. | JSON, XML, YAML, NoSQL document stores (MongoDB). | NoSQL query languages, JSON parsers, `pd.json_normalize()`. |
| **Unstructured Data** | Data lacking any predefined conceptual data model or schema. Represents the majority (~80-90%) of real-world enterprise data. | Text documents, survey open-text, audio recordings, images, video streams. | NLP models, Computer Vision (CNNs), Embeddings, Vector Databases. |

---

## 2. Qualitative vs. Quantitative Data

```
                              ┌───────────────────────────┐
                              │     Data Nature / Types   │
                              └───────────────────────────┘
                                            │
                     ┌──────────────────────┴──────────────────────┐
                     ▼                                             ▼
          Qualitative / Categorical                     Quantitative / Numerical
          (Descriptive qualities, labels)               (Measurable numeric quantities)
          ├── 1. Nominal (No order)                     ├── 3. Interval (No true zero)
          └── 2. Ordinal (Ranked order)                 └── 4. Ratio (Has true zero)
```

---

## 3. Four Levels of Measurement (Stevens' Scales)

Stanley Smith Stevens (1946) classified data into four fundamental measurement scales with increasing mathematical properties:

1. **Nominal Scale (Labels & Names):**
   - Mutually exclusive categories with **no intrinsic order** or quantitative value.
   - *Examples:* Gender, Blood type (A, B, AB, O), Marital status, ZIP codes, eye color.
   - *Valid Operations:* Equality ($=$), Frequency counts, Mode.

2. **Ordinal Scale (Rank & Sequence):**
   - Categorical data with a **meaningful order or ranking**, but the mathematical distances between adjacent ranks are unequal or unknown.
   - *Examples:* Education level (High School, Bachelor's, Master's, PhD), Satisfaction ratings (Poor, Fair, Good, Excellent), Likert scales (1–5).
   - *Valid Operations:* Greater/Less than ($>, <$), Median, Percentiles, Rank correlation (Spearman's $\rho$).

3. **Interval Scale (Equal Spacing, No True Zero):**
   - Quantitative numerical data where the **difference between values is meaningful and constant**, but there is **no absolute / true zero point** (zero is an arbitrary baseline).
   - *Examples:* Temperature in Celsius or Fahrenheit ($0\ ^\circ	ext{C}$ does not mean "absence of heat"), Calendar years, IQ test scores.
   - *Valid Operations:* Addition ($+$), Subtraction ($-$), Mean, Standard deviation. *Multiplication/Division ratios are invalid* (e.g., $20\ ^\circ	ext{C}$ is not "twice as hot" as $10\ ^\circ	ext{C}$).

4. **Ratio Scale (Equal Spacing with True Zero):**
   - Quantitative numerical data featuring equal intervals and an **absolute, non-arbitrary true zero point** (where zero represents complete absence of the measured quantity).
   - *Examples:* Weight, Height, Age, Salary/Income, Distance, Temperature in Kelvin ($0	ext{ K} = 	ext{Absolute Zero}$).
   - *Valid Operations:* Addition ($+$), Subtraction ($-$), Multiplication ($	imes$), Division ($\div$), Ratios, Geometric Mean, Coefficient of Variation.

---

## 4. Summary of Data Measurement Scales

The table below summarizes the operational and statistical capabilities provided by each measurement scale:

| Provides: | Nominal | Ordinal | Interval | Ratio |
| :--- | :---: | :---: | :---: | :---: |
| **The "order" of values is known** | | ✓ | ✓ | ✓ |
| **"Counts," aka "Frequency of Distribution"** | ✓ | ✓ | ✓ | ✓ |
| **Mode** | ✓ | ✓ | ✓ | ✓ |
| **Median** | | ✓ | ✓ | ✓ |
| **Mean** | | | ✓ | ✓ |
| **Can quantify the difference between each value** | | | ✓ | ✓ |
| **Can add or subtract values** | | | ✓ | ✓ |
| **Can multiply and divide values** | | | | ✓ |
| **Has "true zero"** | | | | ✓ |

---

## 5. Machine Learning & Feature Engineering Implications

Understanding the measurement scale directly dictates how variables should be preprocessed in Data Science pipelines:

```
┌──────────────┬───────────────────────────────────────────┬───────────────────────────────────────────┐
│ Scale        │ Recommended Encoding / Preprocessing      │ Permissible Statistical Tests / Models    │
├──────────────┼───────────────────────────────────────────┼───────────────────────────────────────────┤
│ **Nominal**  │ One-Hot Encoding, Target Encoding         │ Chi-Square test, Mode, Non-parametric     │
│ **Ordinal**  │ Ordinal Encoding, Integer Mapping         │ Spearman correlation, Mann-Whitney U      │
│ **Interval** │ Standardization (Z-Score), Normalization  │ T-test, ANOVA, Pearson $r$, Linear Reg   │
│ **Ratio**    │ Log Transform, Min-Max Scaling, Robust    │ All Parametric & Non-parametric models    │
└──────────────┴───────────────────────────────────────────┴───────────────────────────────────────────┘
```

---

## 🔗 Related Notes & References
- [[CS240]] — Main Course Index for Data Science
- [[The Data Science]] — Introduction to Data Science, DIKW hierarchy, and Analytics Maturity
- [[Data Science Process]] — Full CRISP-DM / OSEMN lifecycle and EDA workflows
- [[ST329]] — Statistics for Data Science and Probability Theory
