---
type: lecture
title:
class:
week:
tags:
  -
description:
parent:
---
## Determind Clock Peroid

>[!faq] $\text{Length of one clock cycle} =\frac{1}{\text{clock frequency}}$

### Single - cycle Implement

The clock period (P) needs to be long enough to complete all the stages in the entire datapath.

$$
P = P_f + P_d + P_e + P_m + P_{wb} + P_{pc}
$$
### Multi - cycle Implement 

The clock period needs to be long enough to complete the longest stage in the datapath.

$$
P = max(P_f, P_d, P_e, P_m, P_{wb}, P_{pc})
$$
### Additional Formulae

$\text{Execution Time} = \text{clock cycles} \times \text{clock period}$
$\text{CPI(cycle per instruction)} \times \frac{\text{clock cycles}}{clock instructions}$
