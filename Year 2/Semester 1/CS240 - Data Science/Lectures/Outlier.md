---
type: lecture
title: "Outliers & Data Normalization"
class: CS240
semester: Year 2 Semester 1
week: 5
tags:
  - data-science
  - data-cleaning
  - outliers
  - normalization
  - z-score
  - cstu40
description: "Outlier detection, Min-Max normalization, Z-score standardization, and box plot distribution bounds."
created: 2026-09-11
updated: 2026-09-15
parent: "CS240"
---

# Outliers & Data Normalization

> **Related Notes:** [[CS240]] | [[Data Cleaning]] | [[Statistical Analysis]] | [[Exploratory Data Analysis]]

---

## 1. Outlier Definition & Impact

In statistics, **outliers** are extreme values that lie outside the overall pattern of the rest of the data.

- Outliers can reveal important domain insights about the underlying phenomena being studied (e.g., fraud detection, rare events).
- However, outliers may also arise from measurement errors, sensor malfunctions, data entry mistakes, or natural high-variance data fluctuations.

---

## 2. Feature Normalization Strategies

Feature scaling prevents features with large absolute ranges from dominating algorithms sensitive to Euclidean distances or gradient updates.

### A. Min-Max Normalization (Rescaling)
Scales a continuous variable into a fixed bounded range, typically between $[0, 1]$.

$$
x_{\text{norm}} = \frac{x - x_{\min}}{x_{\max} - x_{\min}}
$$

> [!note] **Min-Max Characteristics**
> - The minimum value of the feature gets transformed into $0$.
> - The maximum value gets transformed into $1$.
> - All other values are mapped to a decimal value in $(0, 1)$.
> - **Caution:** Highly sensitive to outliers; a single extreme outlier compresses all normal values into a very tight cluster.

### B. Z-Score Standardization
Transforms the distribution to have a mean $\mu = 0$ and standard deviation $\sigma = 1$.

$$
z = \frac{x - \mu}{\sigma}
$$

> [!note] **Z-Score Normalization Characteristics**
> - Avoids the extreme bound-compression problem of Min-Max scaling.
> - An observation exactly equal to the mean is normalized to $0$.
> - Values below the mean map to negative $z$-scores; values above the mean map to positive $z$-scores.
> - Outliers typically lie beyond $|z| > 3$.

---

## 3. Box Plot Distribution Bounds (IQR Method)

```text
			┌────────────────────────┬──────────────────────────┐
			│                        │                          │
			│           Q1           │            Q3            │
│     *     │       (25th %)         │         (75th %)         │     *     │
│  (Outlier)│                        │                          │  (Outlier)│
├───────────┤                        │                          ├───────────┤
│    Lower  │                        │  Median                  │   Upper   │
│    Fence  │                        │  (Q2)                    │   Fence   │
            │                        │                          │           
			│                        │                          │
			└────────────────────────┴──────────────────────────┘
```

- **Interquartile Range:** $\text{IQR} = Q_3 - Q_1$
- **Lower Whisker / Fence:** $Q_1 - 1.5 \times \text{IQR}$
- **Upper Whisker / Fence:** $Q_3 + 1.5 \times \text{IQR}$
- Points falling outside $[\text{Lower Fence}, \text{Upper Fence}]$ are classified as potential outliers.
