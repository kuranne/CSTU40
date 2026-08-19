---
type: lecture
description:
---

#Week1  #Week2

# Lesson

C++ is super sub of C, that mean you can write as C in C++ also.
C++ has many tool which C don't has such class, auto val and other more!

Class Time

```cpp
class Time {
	public:
		Time ( int = 0, int = 0, int = 0);
		void setTime(int, int, int);
}
```

From code, we see there is no val name for Time (hr, min, sec).

## Class Interface and Implementation

Use `#include "something.h"` (Pre Processor command) to implement function/class into a source file. This mean in during compile step, the compiler will bring source code of Time.h into head(front) of obj files.

Scoop Operator: **ClassName**::member
can use `using std::cout` for only use cout instread if `using namespace std`

**Destructor** is the opposite function of Constructor which use for housekeeping before system reclaims the object's memory by using `~` in front of Class call. **Can only have one Destructor**

**example** complex class
```cpp
using namespace std;
class Complex
{
	float re, im;
	public:
		Complex(float x = 0, float y = 0) : re(x), im(y) { }
		// Overload function * (litereally mult A * B like that)
		Complex operator*(Complex rhs) const;
		float modulus() const;
		void print() const;
}
```

