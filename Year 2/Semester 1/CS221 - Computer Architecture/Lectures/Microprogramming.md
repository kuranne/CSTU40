---
type: lecture
title: Microprogramming
class: CS221
week: 7, 8
tags:
  - system-architecture
description:
parent: CS221
---
# Microprogramming

- A simple technique used to implement the control units is called **hardwired control implementation**. 
- This technique has a limitation that changing a part in the datapath causes the circuit to be redesigned. 
- Another technique is called **microprogramming**. This is a technique to implement the control units by using **ROM** to ==store the collection of control signals== corresponding to the state, as well as the next state. 
- Therefore, the control unit can be changed without redesigning the entire circuit.