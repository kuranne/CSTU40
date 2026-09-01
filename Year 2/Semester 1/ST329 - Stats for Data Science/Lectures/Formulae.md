---
type: lecture
title: ST329 - Statistical & Probability Formulae Reference Sheet
course_code: ST329
tags:
  - statistics
  - probability
  - formulae
  - bayes-theorem
  - conditional-probability
  - cstu40
description: Comprehensive reference sheet for probability axioms, conditional probability, Bayes' Rule, and random variables.
---

# 📐 ST329 — Formulae Reference

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[ST329]] > [[Formulae]]
> **Related Notes:** [[Random Variables]] | [[ST329]] | [[CS240]]

---

## 1. Probability Foundations

### Basic Axiom of Classical Probability
$$
P(A) = \frac{n(A)}{n(S)} = \frac{	ext{Number of favorable outcomes in event } A}{	ext{Total number of outcomes in sample space } S}
$$

### Conditional Probability
$$
P(B \mid A) = \frac{P(A \cap B)}{P(A)}, \quad 	ext{where } P(A) > 0
$$

**Multiplication Rule (General Chain Rule):**
$$
P(A_1 \cap A_2 \cap \dots \cap A_n) = P(A_1) P(A_2 \mid A_1) P(A_3 \mid A_1 \cap A_2) \dots P(A_n \mid A_1 \cap \dots \cap A_{n-1})
$$

**Complement Rule for Conditional Probability:**
$$
P(B^c \mid A) = 1 - P(B \mid A)
$$

---

## 2. Total Probability Theorem & Bayes' Rule

### Theorem of Total Probability
Given a partition of the sample space $S$ into mutually exclusive and exhaustive events $B_1, B_2, \dots, B_n$ (such that $\bigcup_{i=1}^n B_i = S$ and $P(B_i) > 0$ for all $i$):
$$
P(A) = \sum_{i=1}^n P(B_i) P(A \mid B_i)
$$

### Bayes' Theorem
$$
P(B_k \mid A) = \frac{P(B_k) P(A \mid B_k)}{\sum_{i=1}^n P(B_i) P(A \mid B_i)}
$$

---

## 3. Independence

Two events $A$ and $B$ are **statistically independent** if and only if any of the following equivalent conditions hold:
- $P(B \mid A) = P(B)$
- $P(A \mid B) = P(A)$
- $P(A \cap B) = P(A) \cdot P(B)$

---

## 4. Random Variables Overview
- **Random Variable Mapping:** $X: S 	o \mathbb{R}$
- Detailed definitions, PMF/PDF, CDF, Expectation, and Variance formulas are indexed in [[Random Variables]].
