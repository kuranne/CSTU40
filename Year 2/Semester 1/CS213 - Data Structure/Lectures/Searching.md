---
type: lecture
title: Searching Algorithms (Binary Search)
course_code: CS213
semester: Year 2 Semester 1
week: 5
tags:
  - algorithms
  - searching
  - binary-search
  - complexity-analysis
  - cstu40
description: "Binary search mechanics on sorted arrays, midpoint index calculations, search space reduction, and logarithmic time complexity analysis."
created: 2026-09-03
updated: 2026-09-05
---

# 🔍 Searching Algorithms

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS213]] > [[Searching]]
> **Related Notes:** [[CS213]] | [[Introduction to Data Structure]] | [[Linked List]]

---

Meaning to search index in array.

## Binary Search Method

Binary search uses the attribute of an ordered (sorted) data set. The method will query from the middle; then if the middle element is the target, return that index. If not, check if the index's value is smaller than the target, so the target must be to the right of middle; then $	ext{next} = \frac{	ext{middle} + 	ext{high}}{2}$ to find the new index. Of course, if the index's value is larger than the target, $	ext{next} = \frac{	ext{low} + 	ext{middle}}{2}$. (The limit of index is middle to high or low to middle, depending on where the target is).

```
                                              v
         +------------------------------------+  7<14
         |                                    :
         v                                    :
+--------+  7>6                               :
|        |                                    :
:        +--------+                           :
:        |        |                           :
:        :        v  7<8                      :
:        +---+    :                           :
:            |    :                           :
:            v    :                           :
:        :   :    :                           :
:        :   :    :                           :
+--------+---+----+----+----+----+----+---+---+----+----+----+----+----+----+---+
|   1    | 3 |  4 |  6 |  7 |  8 | 10 | 13| 14| 18 | 19 | 21 | 24 | 37 | 40 |45 |
+--------+---+----+----+----+----+----+---+---+----+----+----+----+----+----+---+
|0       |1  |2   |3   |4   |5   |6   |7  |8  |9   |10  |11  |12  |13  |14  |15 |
+--------+---+----+----+----+----+----+---+---+----+----+----+----+----+----+---+
```

> [!tip] Time Complexity
> This method has Big-O complexity of $\mathcal{O}(\log n)$.
