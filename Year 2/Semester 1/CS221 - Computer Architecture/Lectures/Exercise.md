---
type: lecture
description:
---
# Exercise

> [!exec] Let $\%rax = 10$ and $\%rcx = 1024$, Write the output of the following instructions.

1. **not %rax**
```
b'10' = b1010
not %rax = b1111 ... 1111 0101
```

2. **or $-1, %rax**
```
$-1 = b1111 ... 1111
%rax = b1010
or = b1111 ... 1111 = -1
```

3. **shl $4, %rcx**
```
$4 = b0100
%rcx = b0100 0000 0000
shl = b0100 0000 0000 0000 = 16,384
```

4. **shr $4, %rcx**
```
$4 = b0100
%rcx = b0100 0000 0000
shr = b0100 0000 = 128
```

---