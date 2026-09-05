---
type: lecture
title: Cumulative Distribution Function & Survival Function
course_code: ST329
semester: Year 2 Semester 1
week: 2, 3
tags:
  - statistics
  - probability
  - cdf
  - survival-function
  - continuous-distributions
  - discrete-distributions
  - cstu40
description: "Cumulative Distribution Function (CDF), Survival Function, definitions for discrete and continuous random variables, and mathematical limit properties."
created: 2026-09-02
updated: 2026-09-05
---

# 📊 Cumulative Distribution Function & Survival Function

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[ST329]] > [[Distribution]]
> **Related Notes:** [[ST329]] | [[Random Variables]] | [[Formulae]] | [[CS240]]

---

## 1. Cumulative Distribution Function (CDF) & Survival Function

> [!note] **Cumulative Distribution Function (CDF):**
> $$F(x) = P(X \le x)$$

### Survival Function $S(x)$
The **Survival Function** (reliability function), widely applied in biostatistics, medical trials, and reliability engineering:

$$S(x) = 1 - F(x) = P(X > x)$$

---

## 2. Mathematical Definition

> [!abstract] **Definition 2.8:**
> The Cumulative Distribution Function $F(x) = P(X \le x)$ is defined piecewise depending on the nature of the random variable $X$:
> 
> $$
> F(x) = \begin{cases}
> \displaystyle \sum_{t \le x} f(t) & 	ext{when } X 	ext{ is a discrete random variable} \
> \
> \displaystyle \int_{-\infty}^{x} f(t) \, dt & 	ext{when } X 	ext{ is a continuous random variable}
> \end{cases}
> $$

---

## 3. Fundamental Properties of CDF

If $X$ is a random variable with cumulative distribution function $F(x)$, the following mathematical properties hold:

1. **Non-decreasing Monotonicity:**
   $$\forall x_1 < x_2 \implies F(x_1) \le F(x_2)$$

2. **Asymptotic Limits:**
   $$\lim_{x 	o -\infty} F(x) = 0 \quad 	ext{and} \quad \lim_{x 	o \infty} F(x) = 1$$

3. **Right-Continuity:**
   $$\lim_{x 	o x_0^+} F(x) = F(x_0), \quad \forall x_0 \in \mathbb{R}$$
