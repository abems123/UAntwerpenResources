# H7 Exam Prep — Only the Most Important Exercises

**Chapter:** H7 — Functies van meerdere veranderlijken  
**Goal:** do only the exercises that prepare you for the real exam-style H7 questions.  
**Based on:** H7 course exercises, 2018–2024 exams, and the 2019 H7 model questions.

---

## 1. What the exam pattern says

H7 is very predictable. In the previous exams, the same types keep returning:

| Exam type | How often it appears | Similar previous exam questions |
|---|---:|---|
| Continuity / partial differentiability / directional differentiability / differentiability at `(0,0)` | Very often | 2019 z2 Q7, 2020 z1 Q7, 2021 z1 Q13, 2022 z2 Q13, 2024 z2 Q14, model H7 Q2/Q6/Q9 |
| Directional derivative | Very often | 2018 z1 Q13, 2019 z1 Q7, 2022 z1 Q13, 2023 z2 Q13, 2024 z1 Q13, model H7 Q4/Q10 |
| Chain rule / Jacobian of a composition | Very often | 2018 z2 Q13, 2021 z2 Q13, 2022 z2 Q14, 2023 z2 Q14, 2024 z2 Q13, model H7 Q3 |
| Critical points and extrema | Almost always | 2018 z1 Q14, 2018 z2 Q14, 2021 z1 Q14, 2021 z2 Q14, 2022 z1 Q14, 2023 z1 Q14, 2024 z1 Q14, model H7 Q5/Q11 |
| Second derivative matrix / Taylor / tangent plane | Less often, but possible | 2023 z1 Q13, model H7 Q1/Q7/Q8 |

So the best strategy is **not** to do random H7 exercises. Focus on the repeated exam templates.

---

## 2. The must-do exercise list

Do these in this order. This order goes from most exam-relevant to less frequent but still possible.

---

## A. Continuity and differentiability at the origin

These are extremely important because the exam often asks:  
“Is the function continuous, partially differentiable, directionally differentiable, differentiable?”

### 1. `7A-16.1`

**What it trains:** full classification at `(0,0)` for a piecewise function.

**Why it is important:** this is exactly the style of the repeated exam question where you must check several properties separately. Students often make the mistake: “partial derivatives exist, so differentiable.” That is false.

**Similar exam questions:**

- 2019 z2 Q7
- 2020 z1 Q7
- 2021 z1 Q13
- 2022 z2 Q13
- 2024 z2 Q14
- Model H7 Q2/Q6/Q9

**What to pay attention to:**

- First check continuity using paths or estimates.
- Then check partial derivatives from the definition.
- Then check directional derivatives from the definition if needed.
- Differentiability implies continuity, so if it is not continuous, it cannot be differentiable.

---

### 2. `7A-16.4`

**What it trains:** harder powers in a piecewise function at `(0,0)`.

**Why it is important:** the real exams love functions with powers like `x^5 y^5 / (x^4 + y^4)` or `x^7 y^7 / (x^6 + y^6)`. This exercise trains exactly that kind of reasoning.

**Similar exam questions:**

- 2022 z2 Q13
- 2024 z2 Q14
- Model H7 Q6/Q9

**What to pay attention to:**

- Do not only try the paths `y = x` and `y = 0`.
- If you need to prove the limit is `0`, use an inequality/bounding argument.
- If you need to prove the limit does not exist, find two paths with different outcomes.

---

### 3. `7A-16.7`

**What it trains:** a very exam-like piecewise function where the numerator and denominator have almost the same total degree.

**Why it is important:** this is one of the best exercises for learning the difference between continuity, directional differentiability, and differentiability.

**Similar exam questions:**

- 2019 z2 Q7
- 2020 z1 Q7
- 2021 z1 Q13
- 2024 z2 Q14

**What to pay attention to:**

- Try polar coordinates if the expression contains `x^4 + y^4` or powers of the same degree.
- Watch out: having all directional derivatives does **not** automatically mean the function is differentiable.

---

### 4. `7A-5.3`

**What it trains:** proving that a two-variable limit does not exist by choosing good paths.

**Why it is important:** this is the mini-version of the continuity questions. If you cannot kill a limit using paths, the full piecewise exam questions become much harder.

**Similar exam questions:**

- Model H7 Q2/Q6/Q9
- 2019 z2 Q7
- 2020 z1 Q7

**What to pay attention to:**

- Try `y = mx`.
- If the answer depends on `m`, the limit does not exist.

---

### 5. `7A-5.5`

**What it trains:** path testing with quadratic numerator and denominator.

**Why it is important:** this type teaches you to see quickly when a limit depends on the slope of the path.

**Similar exam questions:**

- Model H7 Q2/Q6/Q9
- 2019 z2 Q7
- 2021 z1 Q13

**What to pay attention to:**

- Along `y = mx`, simplify completely.
- Do not stop after one path.

---

## B. Directional derivatives and gradients

These are also very high priority. The exam often asks for a directional derivative in a point and direction.

### 6. `7A-12.3`

**What it trains:** directional derivative of a polynomial in two variables.

**Why it is important:** this is the same level as the classic exam directional derivative questions.

**Similar exam questions:**

- 2018 z1 Q13
- 2019 z1 Q7
- Model H7 Q4

**What to pay attention to:**

- Use the gradient method when the function is differentiable.
- In this course, check carefully whether the direction vector is used as given or normalized, depending on the definition used in your notes/exam solutions.

---

### 7. `7A-12.9`

**What it trains:** directional derivative in three variables.

**Why it is important:** the 2024 exam used a three-variable directional derivative. This exercise prepares you for that jump from `(x,y)` to `(x,y,z)`.

**Similar exam questions:**

- 2024 z1 Q13
- Model H7 Q10

**What to pay attention to:**

- Compute all three partial derivatives.
- Substitute the point only after differentiating.
- Be careful with square roots.

---

### 8. `7A-12.12`

**What it trains:** directional derivative of an exponential function in three variables.

**Why it is important:** it combines chain-rule thinking with directional derivatives.

**Similar exam questions:**

- 2024 z1 Q13
- Model H7 Q10

**What to pay attention to:**

- The gradient will contain the exponential factor.
- Do not forget to evaluate at the given point.

---

### 9. `7A-13.8`

**What it trains:** gradient of a radial function in three variables.

**Why it is important:** this is very close to the 2024 z1 directional derivative question, where the function involved a square-root expression in three variables.

**Similar exam questions:**

- 2024 z1 Q13
- Model H7 Q10

**What to pay attention to:**

- This is basically the gradient part of a directional derivative question.
- If you can do this fast, the directional derivative version becomes easy.

---

## C. Chain rule / Jacobian composition

These are very exam-relevant. The professor often explicitly says: “Use the chain rule; another method gives no points.”

### 10. `7B-5`

**What it trains:** one-variable chain rule with `z = z(x,y)`, `x = x(t)`, `y = y(t)`.

**Why it is important:** this is almost the same structure as the 2023 z2 chain-rule exam question.

**Similar exam questions:**

- 2023 z2 Q14
- Model H7 Q3

**What to pay attention to:**

Use the structure:

`z'(t) = z_x(x(t),y(t)) x'(t) + z_y(x(t),y(t)) y'(t)`

Do **not** first substitute everything into `z(t)` if the question says to use the chain rule.

---

### 11. `7B-6.1`

**What it trains:** derivative matrix of a triple composition.

**Why it is important:** this matches the exam style where you must multiply Jacobian matrices in the correct order.

**Similar exam questions:**

- 2018 z2 Q13
- 2021 z2 Q13
- 2022 z2 Q14
- 2024 z2 Q13

**What to pay attention to:**

- Write the spaces above the functions: for example `R^2 -> R^3 -> R^2`.
- Matrix dimensions must match.
- The order is not random: `D(g ∘ f)(x) = Dg(f(x)) · Df(x)`.

---

### 12. `7B-4`

**What it trains:** computing `D(g ∘ f)` without computing the composition.

**Why it is important:** this is exactly how the model questions and several real exams formulate the chain-rule question.

**Similar exam questions:**

- Model H7 Q3
- 2018 z2 Q13
- 2022 z2 Q14

**What to pay attention to:**

- First compute `Df(x,y)`.
- Then compute `Dg(u,v)`.
- Substitute `(u,v) = f(x,y)` into `Dg`.
- Multiply `Dg(f(x,y)) · Df(x,y)`.

---

### 13. `7B-2.1`

**What it trains:** partial derivatives after a coordinate transformation with two parameters.

**Why it is important:** this makes the chain rule automatic instead of something you only know for one specific shape.

**Similar exam questions:**

- 2021 z2 Q13
- 2022 z2 Q14
- 2024 z2 Q13

**What to pay attention to:**

- Keep `s` and `t` as independent variables.
- Compute `∂w/∂s` and `∂w/∂t` by summing over all intermediate variables.

---

## D. Second derivatives, Hessian, and Taylor in several variables

This appears less often than extrema/chain rule, but it is still risky to skip completely.

### 14. `7C-2.2`

**What it trains:** all second partial derivatives of a function with a square root.

**Why it is important:** 2023 z1 Q13 asked for the second derivative matrix of a function with a square-root/rational structure. This exercise is the same kind of technical work.

**Similar exam questions:**

- 2023 z1 Q13

**What to pay attention to:**

- Work cleanly with powers like `(4x^2 + y^2)^{1/2}`.
- Mixed partials should match if the function is smooth.

---

### 15. `7C-2.4`

**What it trains:** second partial derivatives in three variables.

**Why it is important:** it prepares you for more complicated derivative matrices and mixed derivatives.

**Similar exam questions:**

- 2023 z1 Q13
- Model H7 questions about higher derivatives

**What to pay attention to:**

- Make a table: first derivatives, then second derivatives.
- Do not mix up `∂²f/∂x∂y` and `∂²f/∂y∂x` while writing.

---

### 16. `7D-1.1`

**What it trains:** Taylor polynomial of degree 2 in a non-zero point.

**Why it is important:** model H7 Q1 is exactly a Taylor polynomial in several variables.

**Similar exam questions:**

- Model H7 Q1

**What to pay attention to:**

For degree 2, you need:

- the value of the function,
- first partial derivatives,
- second partial derivatives,
- and the correct `(x-a)` and `(y-b)` terms.

---

### 17. `7D-1.3`

**What it trains:** Taylor polynomial of degree 3 around `(0,0)`.

**Why it is important:** this is a harder Taylor exercise and prepares you if the exam asks the model-question style but with degree 3.

**Similar exam questions:**

- Model H7 Q1

**What to pay attention to:**

- Around `(0,0)`, simplify using known Taylor expansions when possible.
- Keep only terms up to the requested total degree.

---

## E. Tangent planes and horizontal tangent planes

These are not the most common in the real exams, but they are in the H7 model questions.

### 18. `7A-14.4`

**What it trains:** tangent plane to the graph of a two-variable function.

**Why it is important:** the model questions ask tangent planes directly.

**Similar exam questions:**

- Model H7 Q7
- Model H7 Q8

**What to pay attention to:**

Use:

`z = f(a,b) + f_x(a,b)(x-a) + f_y(a,b)(y-b)`

---

### 19. `7A-15.9`

**What it trains:** finding where the tangent plane is horizontal.

**Why it is important:** horizontal tangent planes are basically critical points before the Hessian test. This helps with extrema questions too.

**Similar exam questions:**

- 2018 z1 Q14
- 2021 z2 Q14
- 2024 z1 Q14

**What to pay attention to:**

Horizontal tangent plane means:

`f_x(x,y) = 0` and `f_y(x,y) = 0`.

That is the same first step as finding critical points.

---

## F. Critical points and extrema

This is probably the most important part of H7. It appears in many exams as the final H7 question.

### 20. `7E-1.2`

**What it trains:** basic quadratic extrema.

**Why it is important:** it is the cleanest version of the Hessian test. You should be able to do this very fast.

**Similar exam questions:**

- 2023 z1 Q14
- Model H7 Q5/Q11

**What to pay attention to:**

- Solve `f_x = 0`, `f_y = 0`.
- Use the Hessian determinant or eigenvalue sign method.

---

### 21. `7E-1.6`

**What it trains:** cubic function with an `xy` interaction term.

**Why it is important:** this is much closer to real exam difficulty than a simple quadratic.

**Similar exam questions:**

- 2021 z2 Q14
- 2018 z1 Q14
- Model H7 Q5/Q11

**What to pay attention to:**

- The system `f_x = 0`, `f_y = 0` may give several critical points.
- Classify every point separately.

---

### 22. `7E-1.12`

**What it trains:** mixed terms and a Hessian that depends on the point.

**Why it is important:** this is the kind of exercise where you can easily make a sign mistake, which is exactly what happens under exam pressure.

**Similar exam questions:**

- 2021 z1 Q14
- 2021 z2 Q14
- 2024 z1 Q14

**What to pay attention to:**

- Do not classify using only one second derivative.
- First compute the Hessian determinant, then use the sign of `f_xx` if needed.

---

### 23. `7E-1.21`

**What it trains:** cubic plus mixed term plus quadratic term.

**Why it is important:** very similar structure to real exam extrema questions.

**Similar exam questions:**

- 2021 z2 Q14
- 2022 z1 Q14
- 2024 z1 Q14

**What to pay attention to:**

- Expect multiple critical points.
- Some will be saddle points.

---

### 24. `7E-1.26`

**What it trains:** harder cubic extrema with several critical points.

**Why it is important:** this is one of the best final preparation exercises for the H7 extrema exam question.

**Similar exam questions:**

- 2022 z1 Q14
- 2024 z1 Q14
- Model H7 Q5/Q11

**What to pay attention to:**

- Be systematic: first all critical points, then Hessian, then conclusion.
- Do not stop after finding one point.

---

## 3. What I would skip if time is limited

Skip these unless you already finished the must-do list above:

- Long lists of easy partial derivatives in `7A-10`, except as warm-up.
- Most inverse-function exercises in `7B-7`, because this pattern is much less common in the exams.
- The long Laplacian coordinate proofs in `7C-5`, because they are heavy and not the repeated exam style.
- Very exotic extrema exercises in `7E-2` and `7E-3`, unless you want extra challenge.

---

## 4. Final checklist before the exam

You are ready for H7 if you can do these without help:

1. For a piecewise function at `(0,0)`, decide continuity, partial differentiability, directional differentiability, and differentiability.
2. Compute a directional derivative using the gradient.
3. Compute `D(g ∘ f)` by multiplying Jacobian matrices in the correct order.
4. Find all critical points and classify them using the Hessian test.
5. Compute a second derivative matrix for a two-variable function.
6. Write a degree 2 Taylor polynomial in two variables.
7. Write the tangent plane equation quickly.

If you can do the 24 exercises above properly, you are covering the H7 patterns that actually return in the exams.
