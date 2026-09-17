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

## Order of Operand

| Infix                     | Postfix                 | Prefix                  |
| ------------------------- | ----------------------- | ----------------------- |
| $A \times B + (C \div D)$ | $A B \times C D \div +$ | $+ \times A B \div C D$ |
| $A \times (B + C) \div D$ | $A B C + \times D \div$ | $\div \times A + B C D$ |
| $A \times (B + C \div D)$ | $A B C D \div + \times$ | $\times A + B \div C D$ |

---

## To Estimate Expression

**Do these in order**

1. Check Balancing Parenthese
2. Parse Infix Expression into Postfix Expression
3. Calculate result from Postfix Expression

---

## Infix to Postfix, parse expression

For each character in the input expression:
`If it is ..., then ...`

1. **operand**, ==append== it to output.
2. **open parenthese**, ==push== it on the stack.
3. **close parenthese**, keep ==popping== the stack $\land$ ==append== **the popped operators** to the output until the open parenthese is popped.
4. **operator**, check these conditions:
   1. the stack is not empty.
   2. the top of stack is not an open parenthese.
   3. this character has a lower or equal precedence than the operator on the top of the stack.

-

---

## Example

**Infix:** $(A \times (B + D)) \div C$
**Postfix:** $A B D + \times C \div$

```mermaid
---
config:
layout: elk
---
flowchart TD
	subgraph TD
	end
```
