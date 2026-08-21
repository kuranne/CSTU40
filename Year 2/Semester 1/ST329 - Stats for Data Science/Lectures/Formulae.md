---
type: lecture
description: All Formulae appeared during studies ST329
---
# Formulae

<span style="font-size: 0.9rem; font-weight: bold">Probability</span> $P(A) = \frac{n(A) = Interesting\ Event}{n(S) = Sample\ Space}$ 
### Conditional Probability

$P(B|A) = \frac{P(A\cap B)}{P(A)}$

$P(A_1 \cap A_2 \cap ... \cap A_n) = P(A_1)P(A_2|A_1)...P(A_n|A_1 \cap A_2 \cap ... \cap A_{n-1})$

$P(B^c|A) = 1 - P(B|A)$

### The Theorem of Total Probability and Bayes' Rule

$P(A) = \sum_{i=1}^n P(B_i)P(A|B_i)$

Can proof when given $B_1, B_2, ..., B_n$ which each don't share same event, $\cup_{i=1}^n B_i = S$
and $P(B_1)>0$ for every single of $i=1, 2, ..., n$ and $A$ is any event

$P(B_k|A) = \frac{P(B_k)P(A|B_k)}{\sum_{i=1}^n P(B_i)P(A|B_i)}$

### Independence

$A$ and $B$ is **independence** to each other when can proofed:
- $P(B|A)=P(B)$ or $P(A|B) = P(A)$ .
- $P(A \cap B) = P(A)P(B)$

