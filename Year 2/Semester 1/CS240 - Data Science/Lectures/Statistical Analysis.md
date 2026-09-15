---
type: lecture
title: "Statistical Analysis & Descriptive Statistics"
class: CS240
semester: Year 2 Semester 1
week: 5
tags:
  - data-science
  - statistics
  - descriptive-statistics
  - variance
  - covariance
  - correlation
  - cstu40
description: "Descriptive statistics, measures of central tendency (mean, median, mode), measures of dispersion (variance, standard deviation), skewness, kurtosis, covariance, and Pearson correlation."
created: 2026-09-11
updated: 2026-09-15
parent: "CS240"
---

# Statistical Analysis & Descriptive Statistics

> **Related Notes:** [[CS240]] | [[Type Of Data]] | [[Outlier]] | [[Exploratory Data Analysis]] | [[ST329]] | [[Formulae]]

---

## 1. Core Concepts

> [!question]+ What is Normal Distribution?
> A **Normal (Gaussian) Distribution** is a continuous probability distribution symmetric about its mean, fully parameterized by two parameters:
> 1. The **Mean ($\mu$)**: Governs central location.
> 2. The **Standard Deviation ($\sigma$)**: Governs dispersion/spread.

> [!question]+ What is Descriptive Statistics?
> **Descriptive Statistics** quantitatively summarize or describe features of a collection of data. They are broadly categorized into:
> - **Measures of Central Tendency:** Mean, Median, Mode.
> - **Measures of Dispersion / Variability:** Range, Interquartile Range (IQR), Variance, Standard Deviation.
> - **Measures of Shape:** Skewness, Kurtosis.
> - **Measures of Association:** Covariance, Pearson Correlation Coefficient.

---

## 2. Measures of Central Tendency

### A. Mean (Arithmetic Average)

$$
\bar{x} = \frac{1}{n} \sum_{i=1}^{n} x_i = \frac{x_1 + x_2 + \dots + x_n}{n}
$$

- A measure of the central or typical value of a dataset.
- Computed as the sum of all observed values divided by the total number of observations.
- **Limitation:** Highly sensitive to extreme outliers.

### B. Median

$$
\tilde{x} = \begin{cases}
x_{\frac{n + 1}{2}} & \text{if } n \text{ is odd} \\
\frac{x_{\frac{n}{2}} + x_{\frac{n}{2} + 1}}{2} & \text{if } n \text{ is even}
\end{cases}
$$

- The physical middle value separating the higher half from the lower half of sorted data.
- **Advantage:** Robust to extreme values and severe skewness (uninfluenced by outliers).

### C. Mode

- The most frequently occurring value in the dataset.
- Can be unimodal (1 mode), bimodal (2 modes), multimodal, or have no mode.

### Geometric Visualization of Central Tendency

![[Screenshot 2569-09-11 at 10.48.43.png|641]]

*Geometric comparison of mode (highest peak), median (equal area divider), and mean (balance point) on an asymmetric continuous probability density function.*

---

## 3. Measures of Dispersion

### A. Standard Deviation ($s$ / $\sigma$)

$$
s = \sqrt{\frac{1}{n-1}\sum_{i=1}^{n}(x_i - \bar{x})^2}
$$

- Quantifies the degree of dispersion or spread of data points around the arithmetic mean.
- **Low Standard Deviation:** Data points cluster tightly around the mean.
- **High Standard Deviation:** Data points spread out across a wide range of values.

### B. Sample Variance ($s^2$ / $\sigma^2$)

$$
s^2 = \frac{1}{n-1}\sum_{i=1}^{n}(x_i - \bar{x})^2
$$

- The average of the squared deviations from the sample mean (with Bessel's correction $n-1$ for unbiased estimation).

---

## 4. Distribution Shape Metrics

### A. Skewness

![[Screenshot 2569-09-11 at 10.55.41.png|658]]

- Measures the degree of asymmetry of a distribution around its mean.
- **Symmetric / Normal Distribution:** $\text{Skewness} = 0$.
- **Positive Skew (Right-skewed):** Tail extends to the right; $\text{Mode} < \text{Median} < \text{Mean}$.
- **Negative Skew (Left-skewed):** Tail extends to the left; $\text{Mean} < \text{Median} < \text{Mode}$.

### B. Kurtosis

![[Screenshot 2569-09-11 at 10.56.44.png|446]]

- Measures the "tailedness" and probability mass in the tails relative to the center of the distribution.
- **Mesokurtic:** Normal distribution (excess kurtosis $= 0$).
- **Leptokurtic (Heavy-tailed):** Higher peak, heavier tails (excess kurtosis $> 0$).
- **Platykurtic (Light-tailed):** Flatter peak, thinner tails (excess kurtosis $< 0$).

---

## 5. Bivariate Association Metrics

### A. Sample Covariance

![[Screenshot 2569-09-11 at 10.59.04.png|633]]

Measures the joint variability of two continuous random variables $X$ and $Y$:

$$
\operatorname{cov}(X, Y) = \frac{1}{n-1}\sum_{i=1}^{n}(x_i - \bar{x})(y_i - \bar{y})
$$

- $\operatorname{cov}(X, Y) > 0$: $X$ and $Y$ tend to increase together.
- $\operatorname{cov}(X, Y) < 0$: When $X$ increases, $Y$ tends to decrease.
- The value ranges across $(-\infty, +\infty)$ and depends on the measurement units of $X$ and $Y$.

### B. Pearson Correlation Coefficient ($r$)

A normalized, dimensionless metric of the linear relationship between two variables:

$$
r = \frac{\operatorname{cov}(X, Y)}{s_x s_y}
$$

- Bounded strictly within $[-1, +1]$:
  - $r = +1$: Perfect positive linear relationship.
  - $r = 0$: No linear relationship.
  - $r = -1$: Perfect negative linear relationship.

![[Screenshot 2569-09-11 at 11.01.44.png]]
