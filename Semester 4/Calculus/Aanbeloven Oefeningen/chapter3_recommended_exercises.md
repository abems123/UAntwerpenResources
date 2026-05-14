# Chapter 3 — Recommended Exercises for the Oefeningen Exam

This file is a practical H3 study guide based on the **course exercise sets 3A–3H** and the **old Calculus exams**.

The goal is not to do every H3 exercise. The goal is to do the exercises that train the same patterns that keep appearing in exam questions.

---

## Big picture

For Chapter 3, the exam pattern is very stable. You should mainly prepare these types:

1. **Hard derivative / higher derivative** questions
2. **Full sign analysis / function investigation** of rational functions
3. **Asymptotes and position with respect to the asymptote**
4. **Convexity / concavity / inflection points / inflection tangents**
5. **Polar curve investigation**
6. **One optimization problem**
7. **A possible Lagrange mean value theorem question**

The most common H3 exam role is usually **question 5 or question 6** in the old exams:

- Q5 is often a derivative or higher derivative.
- Q6 is often a sign analysis / function investigation / polar investigation.

---

## Old exam patterns I used

| Exam | H3-style questions |
|---|---|
| 2018 1e zit | Q5 derivative of `1/(x ln x)`, Q6 polar sign analysis `r^2 = cos(3θ)`, Q10 polar area connected to Q6 |
| 2018 2e zit | Q5 Lagrange mean value theorem, Q6 sign analysis of a rational function |
| 2019 1e zit | Q3 polar sign analysis `r^2 = sin(6θ)` |
| 2019 2e zit | Q3 second derivative of `ln(ln x)`, Q5 polar sketch/area |
| 2020 1e zit | Q3 complete polar function investigation of a “pindanoot” curve |
| 2021 1e zit | Q5 derivative with inverse trig and exponential, Q6 polar investigation |
| 2021 2e zit | Q5 derivative with variable exponent, Q6 rational function investigation with asymptotes |
| 2022 1e zit | Q5 convex/concave + inflection tangents, Q6 polar investigation |
| 2022 2e zit | Q5 second derivative, Q6 rational function investigation with asymptotes |
| 2023 1e zit | Q5 derivative with variable exponent, Q6 rational function investigation |
| 2023 2e zit | Q5 second derivative, Q6 polar investigation, Q10 polar area |
| 2024 1e zit | Q5 derivative with roots/logs/quotients, Q6 polar investigation |
| 2024 2e zit | Q5 third derivative, Q6 rational function investigation, Q10 polar area |

The separate H3 model questions also confirm the same pattern: derivatives, rational function investigations, polar investigations, one optimization problem, convexity/inflection tangents, and asymptotes.

---

# The only H3 exercises you really need

## 1. Derivatives and higher derivatives

These are needed because almost every year has a derivative question. The exam derivative is usually not basic; it combines chain rule, product rule, quotient rule, logarithms, inverse trig, exponentials, or variable powers.

### Do these first

| Exercise | Why it is important | Similar exam questions |
|---|---|---|
| **3A-26.3** | Inverse trig derivative with chain rule. Trains the same idea as `Bgcos(xe^x)`. | 2021 1e zit Q5, H3 model Q3/Q5 |
| **3A-26.6** | `Bgtan(...)` with chain rule. Good for inverse trig inside bigger expressions. | H3 model Q3, H3 model Q17 |
| **3A-34.7** | Derivative of `xe^x`. You need this for inverse trig + exponential compositions. | 2021 1e zit Q5 |
| **3A-36.18** | Logarithm divided by `x`. Very close to `1/(x ln x)`-type manipulation. | 2018 1e zit Q5, 2024 1e zit Q5 |
| **3A-37.1** | Derivative of `ln(ln x)`. | 2019 2e zit Q3 |
| **3A-39.2** | Variable base and variable exponent: `x^x`. This is one of the most exam-like derivative types. | 2021 2e zit Q5, 2023 1e zit Q5 |
| **3A-39.4** | Variable exponent with trig: trains logarithmic differentiation. | 2023 1e zit Q5, H3 model Q1 |
| **3A-39.9** | Variable base/exponent with trig powers. Hard but very exam-level. | 2021 2e zit Q5, 2023 1e zit Q5 |
| **3A-40.3** | Mixed product: power, trig, and log together. | H3 model Q17, 2024 1e zit Q5 |
| **3B-1.10** | Second derivative of a trig product. Good preparation for second-derivative exam questions. | 2022 2e zit Q5, H3 model Q11 |
| **3B-2.7** | Third derivative with `x^2 e^x`. | 2024 2e zit Q5 |

### What you should be able to do after this section

You should be able to differentiate expressions like:

- inverse trig of a composed function,
- logarithms inside logarithms,
- products like polynomial times exponential or trig,
- expressions of the form `u(x)^v(x)`, using logarithmic differentiation,
- second and third derivatives without getting lost.

Do **not** spend too much time on very basic 3A derivative exercises like simple polynomials. They are useful as warm-up, but they are below exam level.

---

## 2. Lagrange / Rolle / mean value theorem

This is less frequent than derivatives and function investigation, but it appeared clearly in an old exam.

| Exercise | Why it is important | Similar exam questions |
|---|---|---|
| **3C-4** | This is almost exactly the exam style: find the point where the tangent is parallel to a chord. | 2018 2e zit Q5 |
| **3C-1** | Rolle theorem in the simplest useful form. | Supports 2018 2e zit Q5 |
| **3C-5** | Word-problem version of the mean value theorem. Good if a theory-style application appears. | Similar reasoning to 2018 2e zit Q5 |

### What you should know

For Lagrange:

`f'(c) = (f(b) - f(a)) / (b - a)`

So your exam steps should be:

1. Compute the slope of the chord.
2. Compute `f'(x)`.
3. Solve `f'(c) = chord slope` with `c` inside the interval.
4. If asked, write the tangent line.

---

## 3. Stijgen/dalen and local extrema

These exercises train the sign table of the first derivative. They are the basis for the bigger function investigations in 3G.

| Exercise | Why it is important | Similar exam questions |
|---|---|---|
| **3D-2.7** | Rational function with a vertical problem point. Good first step before full function investigation. | 2018 2e zit Q6, 2019 H3 model Q10 |
| **3D-2.8** | Very exam-like rational function with possible extrema. | 2018 2e zit Q6, 2021 2e zit Q6, 2022 2e zit Q6 |
| **3D-2.5** | Polynomial with multiple critical points. | 2019 H3 model Q18 |
| **3D-7.1** | `x^x` and extrema. This also supports logarithmic differentiation. | 2021 2e zit Q5, 2023 1e zit Q5 |

### What you must master here

For every function:

1. Find the domain.
2. Compute `f'(x)`.
3. Find zeros and poles of `f'(x)`.
4. Make a sign table.
5. Decide where the function increases/decreases.
6. Decide local minimum/maximum from sign changes.

---

## 4. Convexity, concavity, inflection points, and inflection tangents

This appeared very directly in the exams. Do not skip this.

| Exercise | Why it is important | Similar exam questions |
|---|---|---|
| **3D-8.3** | Polynomial convexity with inflection points. Very close to the standard exam style. | 2022 1e zit Q5, H3 model Q12 |
| **3D-8.4** | Rational function convexity. Harder and useful for full function investigations. | 2021 2e zit Q6, 2022 2e zit Q6, 2023 1e zit Q6 |
| **3D-8.7** | Trig convexity. Good because trig function investigations appear in the H3 model questions. | H3 model Q2 |

### What you must be able to write

For inflection points:

1. Compute `f''(x)`.
2. Solve `f''(x) = 0` and also check undefined points if relevant.
3. Make a sign table of `f''(x)`.
4. Only call it an inflection point if the sign of `f''` changes.
5. For the inflection tangent, use:

`y - f(a) = f'(a)(x - a)`

---

## 5. Asymptotes

This is one of the most important parts of H3. In recent exams, the full function investigation usually explicitly says: “including asymptotes and their position”.

| Exercise | Why it is important | Similar exam questions |
|---|---|---|
| **3F-1.6** | Contains roots and asymptote behavior. Good for non-rational asymptote practice. | H3 model Q14 |
| **3F-2.1** | Very close to the rational functions used in exam function investigations. | 2022 2e zit Q6 |
| **3F-2.4** | Schuine asymptote by Euclidean division. | 2021 2e zit Q6, 2023 1e zit Q6, 2024 2e zit Q6 |
| **3F-2.7** | Harder rational asymptote with division and position. | 2023 1e zit Q6, 2024 2e zit Q6 |

### Minimum asymptote checklist

For a rational function:

1. **Vertical asymptotes:** zeros of denominator that are not cancelled.
2. **Horizontal asymptote:** compare degrees.
3. **Slant asymptote:** if numerator degree is denominator degree + 1, use division.
4. **Position relative to asymptote:** study the sign of `f(x) - A(x)`.

This last point is very important because exams often ask for the position with respect to the graph.

---

## 6. Full function investigation

This is the biggest H3 exam type. If you can do these exercises properly, you are ready for the rational-function exam questions.

### Rational functions — highest priority

| Exercise | Why it is important | Similar exam questions |
|---|---|---|
| **3G-11.2** | Full rational function with domain, zeros, pole, asymptote, first derivative, second derivative, sketch. | 2021 2e zit Q6, 2022 2e zit Q6 |
| **3G-11.4** | Rational function with a vertical asymptote and non-trivial derivatives. | 2018 2e zit Q6, H3 model Q10 |
| **3G-11.6** | Rational function with two critical denominator points. | 2019 H3 model Q6, 2023 1e zit Q6 |
| **3G-11.9** | Two denominator zeros; very good practice for sign tables with poles. | H3 model Q6, 2024 2e zit Q6 |

### Polynomial and trig function investigations

| Exercise | Why it is important | Similar exam questions |
|---|---|---|
| **3G-7.5** | Cubic polynomial written as factors. Trains zeros, extrema, inflection point, tangents, sketch. | H3 model Q18 |
| **3G-4** | Quartic with parameter discussion. Harder than normal, but very useful for understanding graph levels. | H3 model Q18, 2022 1e zit Q5 |
| **3G-15.3** | Trig function investigation with `sin` and `sin(2x)`. | H3 model Q2 |
| **3G-15.8** | Trig function with `sin(3x) + sin(x)`. Good for period + zeros + derivative table. | H3 model Q2 |

### Full function investigation checklist

For exam answers, always structure it like this:

1. Domain
2. Symmetry / periodicity if useful
3. Zeros and poles
4. Asymptotes and position with respect to them
5. Sign table of `f`
6. Sign table of `f'`
7. Sign table of `f''`
8. Extrema
9. Inflection points
10. Sketch

For rational functions, the most common mistake is forgetting to include poles in the sign tables.

---

## 7. Optimization problems

Only one optimization problem usually appears in the H3 model questions, but it is a classic exam style. The key is converting the story into one function of one variable.

| Exercise | Why it is important | Similar exam questions |
|---|---|---|
| **3E-12** | Very close to the “choose the best path” style. Different speeds on different parts of a route. | H3 model Q7 swimmer problem |
| **3E-17** | Classic ladder optimization. Strong exam-level problem. | H3 model Q7 style |
| **3E-10** | Cost minimization with volume constraint. Good practice for constraint substitution. | H3 model Q7 style |
| **3E-7** | Maximum area with fixed fencing. Easier, but a good quick warm-up. | General H3 optimization pattern |

### Optimization checklist

1. Draw a small picture.
2. Choose one variable.
3. Write the quantity to minimize/maximize as a function of that variable.
4. Determine the interval/domain.
5. Compute derivative and critical points.
6. Check endpoints if the interval is closed.
7. Prove min/max using second derivative or sign table.

---

## 8. Polar curve investigation

This is extremely important for H3. It appears more often than students expect. You must know how to make a table for `r(θ)` and `r'(θ)`, then sketch the curve.

### Must-do polar exercises

| Exercise | Why it is important | Similar exam questions |
|---|---|---|
| **3H-8.3** | Trifolium-style flower curve. Trains period, zeros, and sketching petals. | 2018 1e zit Q6, 2019 1e zit Q3 |
| **3H-8.5** | Another three-leaf polar curve with different trig form. | 2022 1e zit Q6 |
| **3H-8.7** | Many-petal curve. Good for period and symmetry. | 2019 1e zit Q3 |
| **3H-11.4** | Lemniscate with `r^2`. Very close to `r^2 = cos(3θ)` / `r^2 = sin(6θ)` exam style. | 2018 1e zit Q6, 2019 1e zit Q3 |
| **3H-12.6** | `2 + cos(2θ)` type; very close to recent polar questions. | 2024 1e zit Q6 |
| **3H-12.8** | Exact same style as the H3 model question `r = 2 + sin^2(4θ)`. | H3 model Q8 |
| **3H-9.4** | Limacon-type curve. Trains max/min distance and sketch. | 2020 1e zit Q3 |
| **3H-10.2** | Harder because periodicity/symmetry is less direct. Good final polar test. | H3 model Q4/Q8 style |

### Polar checklist

For `r = f(θ)`:

1. Find the domain.
2. Find the period.
3. Choose one useful interval.
4. Find zeros of `r(θ)`.
5. Compute `r'(θ)`.
6. Find zeros of `r'(θ)`.
7. Make a table with `θ`, `r(θ)`, `r'(θ)`, and increasing/decreasing behavior.
8. Mark maximum and minimum values of `r`.
9. Use symmetry if possible.
10. Sketch carefully.

For `r^2 = f(θ)`:

- First find where `f(θ) >= 0`, because only there `r` is real.
- Then study the curve on that allowed interval.
- Remember that positive and negative `r` can represent points on opposite sides of the origin.

---

# Final priority list

If you have limited time, do them in this order.

## Priority 1 — absolutely necessary

1. **3A-39.2**
2. **3A-39.9**
3. **3A-26.3**
4. **3A-36.18**
5. **3B-1.10**
6. **3B-2.7**
7. **3F-2.1**
8. **3F-2.4**
9. **3G-11.2**
10. **3G-11.6**
11. **3D-8.3**
12. **3H-11.4**
13. **3H-12.8**
14. **3H-12.6**
15. **3E-12**
16. **3C-4**

## Priority 2 — strongly recommended

17. **3A-34.7**
18. **3A-37.1**
19. **3A-40.3**
20. **3D-2.8**
21. **3D-8.4**
22. **3F-2.7**
23. **3G-7.5**
24. **3G-15.3**
25. **3H-8.3**
26. **3H-8.5**
27. **3H-9.4**
28. **3E-17**

## Priority 3 — only if you want extra safety

29. **3A-26.6**
30. **3A-39.4**
31. **3D-2.7**
32. **3E-10**
33. **3G-4**
34. **3G-11.9**
35. **3G-15.8**
36. **3H-8.7**
37. **3H-10.2**

---

# What you can skip if time is short

You can skip most of these unless your basics are weak:

- Very basic derivative exercises in **3A-8, 3A-9, 3A-10**.
- Most direct “definition of derivative” drills in **3A-2**.
- Most long proof-style exercises in **3C**, except **3C-4** and maybe **3C-1**.
- Most easy polar conversion-only exercises in **3H-1** and **3H-2**, unless you still struggle with `x = r cos θ` and `y = r sin θ`.
- Most related-rate physics-style word problems in **3E**, unless your teacher specifically emphasized them.

Do **not** skip polar curves, asymptotes, full function investigation, or variable-exponent derivatives.

---

# Best “exam simulation” set

After studying, test yourself with this mini-exam:

1. **Derivative:** 3A-39.2 or 3A-39.9
2. **Higher derivative:** 3B-1.10 or 3B-2.7
3. **Asymptotes:** 3F-2.4
4. **Full rational function investigation:** 3G-11.6
5. **Convexity/inflection tangents:** 3D-8.3
6. **Polar curve investigation:** 3H-12.8
7. **Optimization:** 3E-12
8. **Lagrange:** 3C-4

If you can do these without looking at solutions, you are in a very good position for H3 exam questions.
