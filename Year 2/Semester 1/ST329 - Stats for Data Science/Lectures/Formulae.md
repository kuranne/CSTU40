---
type: lecture
title: ST329 - Statistical & Probability Formulae Reference Sheet
course_code: ST329
semester: Year 2 Semester 1
tags:
  - statistics
  - probability
  - formulae
  - distributions
  - random-variables
  - multivariate
  - cstu40
description: "สรุปสูตรสำคัญและคำอธิบายกระชับ รายวิชา ST329 สถิติสำหรับวิทยาการข้อมูล ครอบคลุมบทที่ 1 ถึง 5 จากเอกสารประกอบการสอน (Private/Docs/)"
created: 2026-08-21
updated: 2026-09-05
---

# 📐 ST329 — สรุปสูตรสถิติและความน่าจะเป็น (Formulae Reference Sheet)

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[ST329]] > [[Formulae]]
> **Related Notes:** [[ST329]] | [[Random Variables]] | [[Distribution]] | [[CS240]]
> **Source Documents:** `Private/Docs/ST329-บทที่ 1 ความน่าจะเป็น.pdf` ถึง `บทที่ 5 การแจกแจงหลายตัวแปร.pdf`

---

## 📌 บทที่ 1: ความน่าจะเป็นและการนับ (Probability & Combinatorics)

### 1. หลักการนับเบื้องต้น (Counting Principles)
- **กฎการคูณ (Multiplication Rule):**
  $$n_{	ext{total}} = n_1 	imes n_2 	imes \dots 	imes n_k$$
  *คำอธิบาย:* ทำงาน $k$ ขั้นตอน แต่ละขั้นตอนมี $n_i$ วิธี จำนวนวิธีทั้งหมดคือผลคูณของแต่ละขั้นตอน
- **การเรียงสับเปลี่ยนสิ่งของต่างกันทั้งหมด (Permutation of $n$ distinct items):**
  $$P_n = n!$$
  *คำอธิบาย:* นำสิ่งของที่แตกต่างกัน $n$ ชิ้นมาจัดเรียงในแนวตรงทั้งหมด
- **การเรียงสับเปลี่ยน $n$ สิ่ง เลือกมา $r$ สิ่ง ($r$-permutations of $n$ items):**
  $$P(n, r) = {}_n P_r = \frac{n!}{(n - r)!}$$
  *คำอธิบาย:* จัดเรียงสิ่งของ $n$ ชิ้นที่ต่างกัน โดยเลือกมาเรียงเป็นลำดับคราวละ $r$ ชิ้น (ลำดับมีความสำคัญ)
- **การเรียงสับเปลี่ยนเชิงวงกลม (Circular Permutation):**
  $$P_{	ext{circle}} = (n - 1)!$$
  *คำอธิบาย:* นำสิ่งของต่างกัน $n$ ชิ้นมาจัดเรียงเป็นวงกลม (หมุนแล้วซ้ำกัน)
- **การเรียงสับเปลี่ยนสิ่งของที่มีของซ้ำกัน (Permutation with Repetitions):**
  $$\frac{n!}{n_1! n_2! \dots n_k!}, \quad 	ext{โดยที่ } \sum_{i=1}^k n_i = n$$
  *คำอธิบาย:* จัดเรียงสิ่งของ $n$ ชิ้น โดยมีสิ่งของเหมือนกันกลุ่มละ $n_1, n_2, \dots, n_k$ ชิ้น
- **การจัดหมู่ (Combination):**
  $$\binom{n}{r} = {}_n C_r = \frac{n!}{r!(n - r)!}$$
  *คำอธิบาย:* การเลือกสิ่งของ $r$ ชิ้นจาก $n$ ชิ้นที่ต่างกัน โดยไม่คำนึงถึงลำดับก่อนหลัง

---

### 2. กฎและสมบัติของความน่าจะเป็น (Probability Rules)
- **ความน่าจะเป็นแบบคลาสสิก (Classical Probability):**
  $$P(A) = \frac{n(A)}{n(S)}$$
  *คำอธิบาย:* สัดส่วนจำนวนจุดตัวอย่างในเหตุการณ์ $A$ ต่อจำนวนผลลัพธ์ทั้งหมดในปริภูมิตัวอย่าง $S$ (แต่ละจุดมีโอกาสเกิดเท่ากัน)
- **สัจพจน์ความน่าจะเป็น (Axioms of Probability):**
  $$0 \le P(A) \le 1, \quad P(S) = 1, \quad P(\emptyset) = 0$$
- **กฎส่วนเติมเต็ม (Complement Rule):**
  $$P(A^c) = 1 - P(A)$$
  *คำอธิบาย:* ความน่าจะเป็นที่เหตุการณ์ $A$ จะไม่เกิดขึ้น
- **กฎการบวก (Addition Rule):**
  $$P(A \cup B) = P(A) + P(B) - P(A \cap B)$$
  *คำอธิบาย:* สำหรับ 2 เหตุการณ์ใดๆ (ถ้าไม่เกิดร่วมกัน $A \cap B = \emptyset$ จะได้ $P(A \cup B) = P(A) + P(B)$)
- **กฎการบวกสำหรับ 3 เหตุการณ์:**
  $$P(A \cup B \cup C) = P(A) + P(B) + P(C) - P(A \cap B) - P(A \cap C) - P(B \cap C) + P(A \cap B \cap C)$$

---

### 3. ความน่าจะเป็นแบบมีเงื่อนไขและทฤษฎีเบยส์ (Conditional Probability & Bayes' Theorem)
- **ความน่าจะเป็นแบบมีเงื่อนไข (Conditional Probability):**
  $$P(B \mid A) = \frac{P(A \cap B)}{P(A)}, \quad 	ext{เมื่อ } P(A) > 0$$
  *คำอธิบาย:* โอกาสเกิดเหตุการณ์ $B$ เมื่อทราบว่าเหตุการณ์ $A$ ได้เกิดขึ้นแล้ว
- **กฎการคูณความน่าจะเป็น (Multiplication Rule for Probability):**
  $$P(A \cap B) = P(A) P(B \mid A) = P(B) P(A \mid B)$$
- **ความเป็นอิสระต่อกัน (Independence of Events):**
  $$A 	ext{ และ } B 	ext{ เป็นอิสระต่อกัน} \iff P(A \cap B) = P(A)P(B) \iff P(B \mid A) = P(B)$$
  *คำอธิบาย:* การเกิดขึ้นของเหตุการณ์หนึ่งไม่มีผลต่อความน่าจะเป็นที่จะเกิดอีกเหตุการณ์หนึ่ง
- **ทฤษฎีความน่าจะเป็นรวม (Law of Total Probability):**
  $$P(A) = \sum_{i=1}^n P(B_i) P(A \mid B_i)$$
  *คำอธิบาย:* เมื่อ $B_1, \dots, B_n$ เป็นผลแบ่งกั้น (Partition) ของปริภูมิตัวอย่าง $S$ ที่ไม่เกิดร่วมกันและรวมกันได้ $S$
- **ทฤษฎีบทของเบยส์ (Bayes' Theorem):**
  $$P(B_k \mid A) = \frac{P(B_k) P(A \mid B_k)}{\sum_{i=1}^n P(B_i) P(A \mid B_i)}$$
  *คำอธิบาย:* คำนวณความน่าจะเป็นแบบย้อนกลับ (Posterior Probability) ของสาเหตุ $B_k$ เมื่อทราบผลลัพธ์ $A$

---

## 📌 บทที่ 2: ตัวแปรสุ่ม ค่าคาดหมาย และความแปรปรวน (Random Variables)

### 1. ฟังก์ชันความน่าจะเป็น (PMF, PDF, CDF)
- **ฟังก์ชันมวลความน่าจะเป็น (PMF) — ตัวแปรสุ่มไม่ต่อเนื่อง:**
  $$f(x) = P(X = x), \quad f(x) \ge 0, \quad \sum_{x \in R_X} f(x) = 1$$
- **ฟังก์ชันความหนาแน่นความน่าจะเป็น (PDF) — ตัวแปรสุ่มต่อเนื่อง:**
  $$f(x) \ge 0, \quad \int_{-\infty}^{\infty} f(x) \, dx = 1, \quad P(a \le X \le b) = \int_a^b f(x) \, dx$$
  *(หมายเหตุ: สำหรับตัวแปรสุ่มต่อเนื่อง $P(X = c) = 0$ สำหรับทุกค่าคงที่ $c$)*
- **ฟังก์ชันการแจกแจงสะสม (CDF):**
  $$F(x) = P(X \le x) = \begin{cases} \displaystyle \sum_{t \le x} f(t) & 	ext{เมื่อ } X 	ext{ ไม่ต่อเนื่อง} \ \displaystyle \int_{-\infty}^x f(t) \, dt & 	ext{เมื่อ } X 	ext{ ต่อเนื่อง} \end{cases}$$
  *ความสัมพันธ์:* $f(x) = \frac{d}{dx} F(x)$ (กรณีต่อเนื่อง) และ $P(a < X \le b) = F(b) - F(a)$
- **ฟังก์ชันการรอดชีพ (Survival Function):**
  $$S(x) = P(X > x) = 1 - F(x)$$
  *คำอธิบาย:* ความน่าจะเป็นที่ตัวแปรสุ่มจะมีค่าเกินกว่า $x$ (นิยมใช้ในงานชีวสถิติและความเชื่อถือได้ของระบบ)

---

### 2. ค่าคาดหมายและความแปรปรวน (Expectation & Variance)
- **ค่าคาดหมาย (Expected Value / Mean $\mu$):**
  $$E(X) = \mu = \begin{cases} \displaystyle \sum_{x \in R_X} x f(x) & 	ext{เมื่อ } X 	ext{ ไม่ต่อเนื่อง} \ \displaystyle \int_{-\infty}^{\infty} x f(x) \, dx & 	ext{เมื่อ } X 	ext{ ต่อเนื่อง} \end{cases}$$
  *คำอธิบาย:* ค่าเฉลี่ยระยะยาวหรือจุดศูนย์ถ่วงของการแจกแจงความน่าจะเป็น
- **ค่าคาดหมายของฟังก์ชัน $g(X)$:**
  $$E[g(X)] = \begin{cases} \displaystyle \sum_{x} g(x) f(x) & 	ext{กรณีไม่ต่อเนื่อง} \ \displaystyle \int_{-\infty}^{\infty} g(x) f(x) \, dx & 	ext{กรณีต่อเนื่อง} \end{cases}$$
- **สมบัติของค่าคาดหมาย:**
  $$E(c) = c, \quad E(aX + b) = a E(X) + b, \quad E[g_1(X) \pm g_2(X)] = E[g_1(X)] \pm E[g_2(X)]$$
- **ความแปรปรวน (Variance $\sigma^2$):**
  $$\operatorname{Var}(X) = \sigma^2 = E[(X - \mu)^2] = E(X^2) - [E(X)]^2$$
  *คำอธิบาย:* การกระจายตัวของค่าตัวแปรสุ่มรอบค่าเฉลี่ย
- **ส่วนเบี่ยงเบนมาตรฐาน (Standard Deviation $\sigma$):**
  $$\sigma = \sqrt{\operatorname{Var}(X)}$$
- **สมบัติของความแปรปรวน:**
  $$\operatorname{Var}(c) = 0, \quad \operatorname{Var}(aX + b) = a^2 \operatorname{Var}(X), \quad \operatorname{Var}(X + c) = \operatorname{Var}(X)$$
- **อสมการของเชบีเชฟ (Chebyshev's Inequality):**
  $$P(|X - \mu| \ge k\sigma) \le \frac{1}{k^2} \quad 	ext{หรือ} \quad P(|X - \mu| < k\sigma) \ge 1 - \frac{1}{k^2}, \quad (k > 0)$$
  *คำอธิบาย:* ขอบเขตความน่าจะเป็นที่ข้อมูลจะเบี่ยงเบนออกจากค่าเฉลี่ย สำหรับการแจกแจงใดๆ ที่ทราบ $\mu$ และ $\sigma$

---

## 📌 บทที่ 3: ตัวแปรสุ่มไม่ต่อเนื่องบางชนิด (Discrete Distributions)

| การแจกแจง (Distribution) | สัญลักษณ์ | ฟังก์ชันมวลความน่าจะเป็น $f(x) = P(X = x)$ | ค่าคาดหมาย $E(X)$ | ความแปรปรวน $\operatorname{Var}(X)$ | คำอธิบายสั้นและเงื่อนไขการใช้ |
| :--- | :---: | :--- | :---: | :---: | :--- |
| **แบร์นูลลี**<br>*(Bernoulli)* | $\operatorname{Ber}(p)$ | $f(x) = p^x (1-p)^{1-x}, \quad x \in \{0, 1\}$ | $p$ | $p(1-p)$ | ทดลอง 1 ครั้ง เกิดผลได้เพียง 2 แบบ คือ สำเร็จ ($x=1$) ด้วยความน่าจะเป็น $p$ หรือ ล้มเหลว ($x=0$) |
| **ทวินาม**<br>*(Binomial)* | $B(n, p)$ | $f(x) = \binom{n}{x} p^x (1-p)^{n-x}, \quad x = 0, 1, \dots, n$ | $np$ | $np(1-p)$ | จำนวนครั้งที่สำเร็จ $x$ ครั้ง จากการทดลองแบร์นูลลีที่เป็นอิสระต่อกัน $n$ ครั้ง โดยแต่ละครั้งมีโอกาสสำเร็จ $p$ คงที่ |
| **เรขาคณิต**<br>*(Geometric)* | $\operatorname{Geo}(p)$ | $f(x) = p(1-p)^{x-1}, \quad x = 1, 2, 3, \dots$ | $\frac{1}{p}$ | $\frac{1-p}{p^2}$ | จำนวนครั้งการทดลอง $x$ จนกระทั่งเกิดความสำเร็จครั้งแรก |
| **ทวินามเชิงลบ**<br>*(Negative Binomial)* | $\operatorname{NB}(r, p)$ | $f(x) = \binom{x-1}{r-1} p^r (1-p)^{x-r}, \quad x = r, r+1, \dots$ | $\frac{r}{p}$ | $\frac{r(1-p)}{p^2}$ | จำนวนครั้งการทดลอง $x$ จนกระทั่งเกิดความสำเร็จครั้งที่ $r$ |
| **ไฮเพอร์จีโอเมตริก**<br>*(Hypergeometric)* | $\operatorname{Hyper}(N, K, n)$ | $f(x) = \frac{\binom{K}{x} \binom{N-K}{n-x}}{\binom{N}{n}}, \quad x = \max(0, n-(N-K)), \dots, \min(n, K)$ | $n \frac{K}{N}$ | $n \frac{K}{N} \left(1 - \frac{K}{N}\right) \left(\frac{N-n}{N-1}\right)$ | สุ่มหยิบ $n$ ชิ้น **แบบไม่ใส่คืน** จากประชากรขนาด $N$ ที่มีของประเภทที่สนใจอยู่ $K$ ชิ้น |
| **ปัวซง**<br>*(Poisson)* | $\operatorname{Poisson}(\lambda)$ | $f(x) = \frac{e^{-\lambda} \lambda^x}{x!}, \quad x = 0, 1, 2, \dots$ | $\lambda$ | $\lambda$ | จำนวนครั้งของเหตุการณ์ที่เกิดขึ้นในช่วงเวลาหรือพื้นที่ที่กำหนด ด้วยอัตราเฉลี่ย $\lambda$ ครั้งคงที่ ($E(X) = \operatorname{Var}(X) = \lambda$) |

---

## 📌 บทที่ 4: ตัวแปรสุ่มต่อเนื่องบางชนิด (Continuous Distributions)

| การแจกแจง (Distribution) | สัญลักษณ์ | ฟังก์ชันความหนาแน่นความน่าจะเป็น $f(x)$ | ค่าคาดหมาย $E(X)$ | ความแปรปรวน $\operatorname{Var}(X)$ | คำอธิบายสั้นและเงื่อนไขการใช้ |
| :--- | :---: | :--- | :---: | :---: | :--- |
| **เอกรูปต่อเนื่อง**<br>*(Continuous Uniform)* | $U(a, b)$ | $f(x) = \frac{1}{b-a}, \quad a \le x \le b$ | $\frac{a+b}{2}$ | $\frac{(b-a)^2}{12}$ | ตัวแปรสุ่มมีค่าบนช่วงจำกัด $[a, b]$ โดยมีความหนาแน่นสม่ำเสมอเท่ากันทุกจุด |
| **ปรกติ / ปกติ**<br>*(Normal)* | $N(\mu, \sigma^2)$ | $f(x) = \frac{1}{\sigma \sqrt{2\pi}} e^{-\frac{1}{2\sigma^2}(x-\mu)^2}, \quad -\infty < x < \infty$ | $\mu$ | $\sigma^2$ | โค้งรูประฆังคว่ำสมมาตรรอบ $\mu$ โดยความกว้างขึ้นกับ $\sigma$ เป็นการแจกแจงที่สำคัญที่สุดในงานสถิติ |
| **ปรกติมาตรฐาน**<br>*(Standard Normal)* | $Z \sim N(0, 1)$ | $\phi(z) = \frac{1}{\sqrt{2\pi}} e^{-\frac{z^2}{2}}, \quad -\infty < z < \infty$ | $0$ | $1$ | การแปลงค่ามาตรฐาน: $Z = \frac{X - \mu}{\sigma}$ เพื่อเปิดตารางค่าความน่าจะเป็นสะสม $\Phi(z) = P(Z \le z)$ |
| **เลขชี้กำลัง**<br>*(Exponential)* | $\operatorname{Exp}(\lambda)$ | $f(x) = \lambda e^{-\lambda x}, \quad x \ge 0$ | $\frac{1}{\lambda}$ | $\frac{1}{\lambda^2}$ | ระยะเวลาระหว่างเหตุการณ์ปัวซงสองครั้งติดกัน มีสมบัติไร้ความทรงจำ (Memoryless Property): $P(X > s+t \mid X > s) = P(X > t)$ |
| **แกมมา**<br>*(Gamma)* | $\operatorname{Gamma}(\alpha, \beta)$ | $f(x) = \frac{1}{\Gamma(\alpha)\beta^\alpha} x^{\alpha-1} e^{-x/\beta}, \quad x > 0$ | $\alpha\beta$ | $\alpha\beta^2$ | ระยะเวลารอคอยจนกระทั่งเกิดเหตุการณ์ปัวซงครบ $\alpha$ ครั้ง โดย $\Gamma(\alpha) = \int_0^\infty t^{\alpha-1} e^{-t} dt$ (ถ้า $\alpha \in \mathbb{N}$ จะได้ $\Gamma(\alpha) = (\alpha-1)!$) |
| **ไคกำลังสอง**<br>*(Chi-Square)* | $\chi^2(
u)$ | กรณีพิเศษของ Gamma เมื่อ $\alpha = \frac{
u}{2}, \beta = 2$ | $
u$ | $2
u$ | องศาเสรี $
u$ เป็นการแจกแจงของผลรวมกำลังสองของตัวแปรสุ่มปรกติมาตรฐานอิสระ $
u$ ตัว $\sum_{i=1}^
u Z_i^2$ |

---

## 📌 บทที่ 5: การแจกแจงหลายตัวแปร (Multivariate Distributions)

### 1. ฟังก์ชันความน่าจะเป็นร่วมและการแจกแจงตามขอบ (Joint & Marginal Distributions)
- **ฟังก์ชันมวลความน่าจะเป็นร่วม (Joint PMF):**
  $$f_{X, Y}(x, y) = P(X = x, Y = y), \quad f(x, y) \ge 0, \quad \sum_x \sum_y f_{X, Y}(x, y) = 1$$
- **ฟังก์ชันความหนาแน่นความน่าจะเป็นร่วม (Joint PDF):**
  $$f_{X, Y}(x, y) \ge 0, \quad \int_{-\infty}^{\infty} \int_{-\infty}^{\infty} f_{X, Y}(x, y) \, dx \, dy = 1, \quad P((X, Y) \in C) = \iint_C f_{X, Y}(x, y) \, dx \, dy$$
- **ฟังก์ชันการแจกแจงสะสมร่วม (Joint CDF):**
  $$F_{X, Y}(x, y) = P(X \le x, Y \le y), \quad f_{X, Y}(x, y) = \frac{\partial^2 F_{X, Y}(x, y)}{\partial x \partial y} 	ext{ (กรณีต่อเนื่อง)}$$
- **ฟังก์ชันการแจกแจงตามขอบ (Marginal Distribution):**
  - ตัวแปรสุ่มไม่ต่อเนื่อง:
    $$f_X(x) = \sum_{y} f_{X, Y}(x, y), \quad f_Y(y) = \sum_{x} f_{X, Y}(x, y)$$
  - ตัวแปรสุ่มต่อเนื่อง:
    $$f_X(x) = \int_{-\infty}^{\infty} f_{X, Y}(x, y) \, dy, \quad f_Y(y) = \int_{-\infty}^{\infty} f_{X, Y}(x, y) \, dx$$
  *คำอธิบาย:* หาการแจกแจงของตัวแปรสุ่มตัวหนึ่ง โดยรวม (integrate/sum) อิทธิพลของอีกตัวแปรออกไปทั้งหมด

---

### 2. การแจกแจงแบบมีเงื่อนไขและความเป็นอิสระ (Conditional & Independence)
- **ฟังก์ชันการแจกแจงแบบมีเงื่อนไข (Conditional Distribution):**
  $$f_{X \mid Y}(x \mid y) = \frac{f_{X, Y}(x, y)}{f_Y(y)}, \quad 	ext{เมื่อ } f_Y(y) > 0$$
  $$f_{Y \mid X}(y \mid x) = \frac{f_{X, Y}(x, y)}{f_X(x)}, \quad 	ext{เมื่อ } f_X(x) > 0$$
  *คำอธิบาย:* การแจกแจงความน่าจะเป็นของตัวแปรสุ่มตัวหนึ่ง เมื่อทราบค่าที่แน่นอนของอีกตัวแปรสุ่มหนึ่งแล้ว
- **ความเป็นอิสระต่อกันของตัวแปรสุ่ม (Independence of Random Variables):**
  $$X 	ext{ และ } Y 	ext{ เป็นอิสระต่อกัน} \iff f_{X, Y}(x, y) = f_X(x) f_Y(y) \quad \forall (x, y)$$
  $$\iff F_{X, Y}(x, y) = F_X(x) F_Y(y) \quad \forall (x, y)$$

---

### 3. ค่าคาดหมาย สหความแปรปรวน และสัมประสิทธิ์สหสัมพันธ์ (Expectation, Covariance, Correlation)
- **ค่าคาดหมายของฟังก์ชันสองตัวแปร $g(X, Y)$:**
  $$E[g(X, Y)] = \begin{cases} \displaystyle \sum_x \sum_y g(x, y) f_{X, Y}(x, y) & 	ext{กรณีไม่ต่อเนื่อง} \ \displaystyle \int_{-\infty}^{\infty} \int_{-\infty}^{\infty} g(x, y) f_{X, Y}(x, y) \, dx \, dy & 	ext{กรณีต่อเนื่อง} \end{cases}$$
- **สมบัติค่าคาดหมายของผลรวมเชิงเส้น:**
  $$E(aX + bY + c) = a E(X) + b E(Y) + c$$
  $$X, Y 	ext{ เป็นอิสระต่อกัน} \implies E(XY) = E(X) E(Y)$$
- **สหความแปรปรวน (Covariance $\operatorname{Cov}(X, Y)$ หรือ $\sigma_{XY}$):**
  $$\operatorname{Cov}(X, Y) = E[(X - \mu_X)(Y - \mu_Y)] = E(XY) - E(X)E(Y)$$
  *คำอธิบาย:* วัดทิศทางความสัมพันธ์เชิงเส้นระหว่างตัวแปรสุ่ม $X$ และ $Y$ (บวก = ไปในทิศเดียวกัน, ลบ = สวนทางกัน)
  - ถ้า $X$ และ $Y$ เป็นอิสระต่อกัน $\implies \operatorname{Cov}(X, Y) = 0$ *(บทกลับไม่จำเป็นต้องเป็นจริง)*
  - $\operatorname{Cov}(X, X) = \operatorname{Var}(X)$
  - $\operatorname{Cov}(X, Y) = \operatorname{Cov}(Y, X)$
  - $\operatorname{Cov}(aX + b, cY + d) = ac \operatorname{Cov}(X, Y)$
- **ความแปรปรวนของผลรวมและผลต่างตัวแปรสุ่ม:**
  $$\operatorname{Var}(aX + bY) = a^2 \operatorname{Var}(X) + b^2 \operatorname{Var}(Y) + 2ab \operatorname{Cov}(X, Y)$$
  $$\operatorname{Var}(aX - bY) = a^2 \operatorname{Var}(X) + b^2 \operatorname{Var}(Y) - 2ab \operatorname{Cov}(X, Y)$$
  *(ถ้า $X, Y$ เป็นอิสระต่อกัน: $\operatorname{Var}(aX \pm bY) = a^2 \operatorname{Var}(X) + b^2 \operatorname{Var}(Y)$)*
- **สัมประสิทธิ์สหสัมพันธ์ (Correlation Coefficient $\rho_{XY}$):**
  $$\rho_{XY} = \operatorname{Corr}(X, Y) = \frac{\operatorname{Cov}(X, Y)}{\sigma_X \sigma_Y}, \quad -1 \le \rho_{XY} \le 1$$
  *คำอธิบาย:* วัดระดับความสัมพันธ์เชิงเส้นแบบไร้หน่วย ($\rho = 1$ สัมพันธ์เชิงเส้นตรงสมบูรณ์ทางบวก, $\rho = -1$ ทางลบ, $\rho = 0$ ไม่มีความสัมพันธ์เชิงเส้น)
