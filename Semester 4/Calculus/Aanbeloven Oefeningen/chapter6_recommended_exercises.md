# Chapter 6 — Recommended Exercises for the Oefeningen Exam

This file is a practical study guide for **H6: Rijen en reeksen**.

The goal is **not** to do every H6 exercise. The goal is to do the exercises that prepare you for the types of questions that actually appear in the old oefeningen exams.

---

## Big picture

From the old exams, Chapter 6 keeps coming back in a few clear patterns:

1. **Rekenkundige / meetkundige rijen**
   - find a sequence from given sum/product/sum of squares;
   - often there are **2 solutions**.

2. **Rijen van hogere orde + sommen**
   - use difference rows to find the general term;
   - compute the partial sum;
   - prove the answer is always an integer.

3. **Convergence/divergence of series**
   - comparison test;
   - d'Alembert;
   - Cauchy root test;
   - integral test;
   - alternating series;
   - telescoping series.

4. **Taylor and Maclaurin polynomials**
   - compute a Taylor polynomial around `0` or another point;
   - sometimes with a remainder estimate.

5. **Fourier series**
   - use even/odd symmetry;
   - compute `a_n` or `b_n` with integration by parts;
   - piecewise functions and functions like `x sin x`, `x^3`, `e^{|x|}`.

So the most important sets are: **6A, 6B, 6D, 6E, 6G**.

The least important for the oefeningen exam is **6F**. It is useful for theory, but it appears much less directly in old exercise exams.

---

# The must-do exercises

## 1. Arithmetic and geometric sequences

### Do these exercises

From **6A**:

- **6A-9.1**
- **6A-9.7**
- **6A-9.8**
- **6A-10.3**
- **6A-10.6**
- **6A-10.7**
- **6A-10.9**

From **6B**:

- **6B-5.8**
- **6B-5.9**

### Why these are important

These are the exercises where you have to determine a sequence from conditions like:

- the sum of the terms;
- the product of the terms;
- the sum of the squares;
- partial sums such as `s_2`, `s_6`, etc.

This is exactly the style used in the exams. You must be able to set up the sequence correctly, not just guess it.

For arithmetic sequences, write them symmetrically when possible:

- 3 terms: `(a - v, a, a + v)`
- 5 terms: `(a - 2v, a - v, a, a + v, a + 2v)`
- 6 terms: choose a clean middle-index form like the old exams do.

For geometric sequences, write:

`(x_1, x_1q, x_1q^2, ...)`

and use the formula for partial sums.

### Similar exam questions

- **2018 z1 — Q11**: geometric sequence of 3 terms, given a sum and a condition after adding `1` to each term.
- **2021 z1 — Q11**: arithmetic sequence of 3 terms, given sum and sum of squares.
- **2022 z1 — Q11**: arithmetic sequence of 6 terms, given sum and sum of squares.
- **2022 z2 — Q11**: geometric sequence, find `x_1` from `s_2` and `s_6`.
- **2023 z1 — Q11**: arithmetic sequence of 3 terms, given sum and product.
- **2023 z2 — Q11**: geometric sequence of 3 terms, given sum and sum of squares.
- **Modelvragen H6 — Q4, Q11, Q15**: same sequence-building style.

### Exam skill you should have after this

You should be able to see a sequence problem and immediately know whether to use:

- arithmetic form with difference `v`;
- geometric form with ratio `q`;
- symmetric notation to make the algebra shorter.

---

## 2. Higher-order arithmetic sequences and partial sums

### Do these exercises

From **6A**:

- **6A-25.1**
- **6A-25.3**
- **6A-25.4**

From **6B**:

- **6B-17.3**
- **6B-17.5**
- **6B-17.6**
- **6B-17.7**
- **6B-18**
- **6B-19.1**
- **6B-19.2**

### Why these are important

These train the exact exam pattern:

1. Make difference rows.
2. Decide the order of the sequence.
3. Write the general term as a polynomial.
4. Use `S_1(n)`, `S_2(n)`, `S_3(n)`, etc. to calculate the partial sum.
5. Prove the result is always an integer.

This is one of the most repeated H6 exam formats.

### Similar exam questions

- **Modelvragen H6 — Q1**: compute a sum using Bernoulli polynomials and prove it is always an integer.
- **Modelvragen H6 — Q6**: higher-order arithmetic sequence, find order, general term, next term, and prove natural numbers.
- **Modelvragen H6 — Q13**: higher-order arithmetic sequence, find general term and next element.
- **2021 z2 — Q11**: higher-order arithmetic sequence, find general term, partial sum, prove integer, calculate `s_100`.
- **2024 z2 — Q11**: compute a polynomial-product partial sum and prove the answer is always an integer.

### Extra important note

**6B-17.5** is extremely exam-like because it has the same structure as **2024 z2 — Q11**:

`1·2·4 + 3·4·6 + 5·6·8 + ...`

So this one is a real must-do.

---

## 3. Limits of sequences

### Do these exercises

From **6C**:

- **6C-4.10**
- **6C-4.12**
- **6C-4.15**
- **6C-6**

### Why these are important

These are not the most common direct exam questions, but they support the series chapter. They train:

- `lim x_n`;
- adherence values;
- `liminf` and `limsup`;
- alternating behavior;
- recursive sequence convergence.

You should not spend too much time here, but you should not skip it completely.

### Similar exam questions

There are fewer direct recent exam questions purely about sequence limits, but the same thinking appears inside convergence questions, especially when checking whether the general term goes to `0` or when using Cauchy/d'Alembert.

### Exam skill you should have after this

You should be able to quickly decide whether a sequence:

- converges to a finite number;
- goes to `+∞` or `-∞`;
- oscillates;
- has different limit points.

---

## 4. Series convergence and divergence

This is the biggest H6 exam block besides Fourier and Taylor.

### Do these exercises

From **6D**, do the following groups.

#### A. Telescoping / partial sums

- **6D-9.1**
- **6D-9.2**
- **6D-9.3**
- **6D-9.6**
- **6D-10.5**

These prepare you for series where you must compute partial sums directly.

#### B. d'Alembert / ratio test

- **6D-20.3**
- **6D-20.6**
- **6D-20.8**
- **6D-20.10**
- **6D-20.12**
- **6D-21.5**
- **6D-21.8**
- **6D-21.11**
- **6D-21.14**
- **6D-21.17**

These are important because exam series often contain factorials, exponentials, or products where d'Alembert is the cleanest method.

#### C. Cauchy root test

- **6D-22.1**
- **6D-22.3**
- **6D-22.4**
- **6D-23**

These prepare you for terms with an `n`-th power.

#### D. Comparison / integral / condensation

- **6D-24.3**
- **6D-24.4**
- **6D-24.8**
- **6D-24.9**
- **6D-24.10**
- **6D-26.2**
- **6D-29**

These prepare you for logarithmic and hyperharmonic series, which appear a lot.

#### E. Alternating and absolute convergence

- **6D-25.1**
- **6D-25.4**
- **6D-25.6**

These prepare you for questions where you must say whether the series is:

- divergent;
- convergent but not absolutely convergent;
- absolutely convergent.

#### F. Mixed exam drill

Do these from the big mixed convergence exercise:

- **6D-31.3**
- **6D-31.4**
- **6D-31.5**
- **6D-31.6**
- **6D-31.9**
- **6D-31.14**
- **6D-31.15**
- **6D-31.29**
- **6D-31.45**
- **6D-31.46**
- **6D-31.48**

These are the best “random exam style” convergence drills.

### Why these are important

The exam often gives one series and expects you to choose the correct test yourself. So do not only practise one criterion. You must know which test fits which shape.

Use this quick recognition table:

| Shape of the term | First test to think of |
|---|---|
| factorial `n!` | d'Alembert |
| exponential like `a^n` | d'Alembert or Cauchy |
| something to the power `n` | Cauchy root test |
| rational expression in `n` | comparison / limit comparison |
| logs like `ln n / n^p` | comparison or integral test |
| alternating `(-1)^n` | Leibniz + absolute convergence check |
| telescoping form | partial sums |

### Similar exam questions

- **Modelvragen H6 — Q2**: convergence of a logarithmic series.
- **Modelvragen H6 — Q7**: convergence with `arctan` and `n^2`.
- **Modelvragen H6 — Q9**: convergence with exponential/geometric behavior.
- **Modelvragen H6 — Q12**: convergence using d'Alembert.
- **2018 z2 — Q11**: parameter series, find for which `x` the series converges.
- **2021 z1 — Q12**: compare with a hyperharmonic series.
- **2021 z2 — Q12**: telescoping logarithmic series.
- **2024 z1 — Q11**: convergence of a series with exponential decay; d'Alembert, Cauchy, integral test and comparison all work.

### Exam skill you should have after this

You should not just know the tests separately. You should be able to look at a series and quickly say:

> “This is probably d'Alembert.”

or

> “This is probably comparison with a p-series.”

That is what saves time on the exam.

---

## 5. Taylor and Maclaurin polynomials

### Do these exercises

From **6E**:

- **6E-1.1**
- **6E-1.3**
- **6E-1.6**
- **6E-2.1**
- **6E-2.2**
- **6E-2.3**
- **6E-5.2**
- **6E-8.1**
- **6E-8.2**
- **6E-8.3**
- **6E-10**

### Why these are important

Taylor questions appear very often. The exam usually asks for a Taylor polynomial like:

- `T_3(f;0)(x)`;
- `T_4(f;0)(x)`;
- `T_5(f;0)(x)`;
- sometimes with a remainder estimate.

The most important skill is not just differentiating. It is organizing the derivatives cleanly:

| Step | What to do |
|---|---|
| 1 | Write `f(x)` |
| 2 | Compute derivatives up to the requested order |
| 3 | Evaluate each derivative in the center point |
| 4 | Put everything into the Taylor formula |
| 5 | Simplify carefully |

### Similar exam questions

- **Modelvragen H6 — Q5**: Taylor polynomial for `1/(1+x)` with remainder and approximation.
- **Modelvragen H6 — Q8**: Taylor polynomial for `e^x cos x` and error estimate.
- **Modelvragen H6 — Q14**: Taylor polynomial for `cos^2 x`.
- **2018 z1 — Q12**: Taylor polynomial of `x cos x - sin x`.
- **2022 z1 — Q12**: Taylor polynomial of `x sin(2x)`.
- **2023 z1 — Q12**: Taylor polynomial of `ln(x^2+x+1)`.
- **2024 z2 — Q12**: Taylor polynomial of `x / sqrt(1-x^2)`.

### Extra important exercises

If you are short on time, the most exam-like Taylor exercises are:

1. **6E-1.1** — because `1/(1+x)` appears in the model questions.
2. **6E-1.3** — because products with `e^x`, `sin x`, `cos x` are common.
3. **6E-8.1** and **6E-8.2** — because approximation + error is a classic format.
4. **6E-10** — because it trains using a Taylor series inside an integral.

---

## 6. Fourier series

### Do these exercises

From **6G**:

- **6G-2.4**
- **6G-2.5**
- **6G-2.6**
- **6G-2.7**
- **6G-2.8**

Also redo these old exam-style functions yourself:

- Fourier series of `x sin x`
- Fourier series of `x^3`
- Fourier series of `e^{|2x|}`

### Why these are important

Fourier questions are very common in H6 exams. The most important trick is checking symmetry first.

| Type of function | What happens |
|---|---|
| even function | all `b_n = 0`, only cosine terms |
| odd function | all `a_n = 0`, only sine terms |
| neither even nor odd | split into even and odd parts, or calculate both |

Most exam Fourier questions are not conceptually impossible, but they are long. The danger is losing time or making integration-by-parts mistakes.

### Similar exam questions

- **Modelvragen H6 — Q3**: Fourier series of a piecewise even/absolute-value type function.
- **Modelvragen H6 — Q10**: Fourier series of `e^{|x|}`.
- **Modelvragen H6 — Q16**: Fourier series of a piecewise function.
- **2018 z2 — Q12**: Fourier series of `x sin x`.
- **2019 z2 — Q6**: Fourier series of a piecewise function with `0` on one side and `2 sin x` on the other.
- **2022 z2 — Q12**: Fourier series of `x^3`.
- **2023 z2 — Q12**: Fourier series of `e^{|2x|}`.
- **2024 z1 — Q12**: Fourier series of `x sin x` again.

### Exam skill you should have after this

You should be able to start any Fourier question like this:

1. Decide if the function is even, odd, or neither.
2. Immediately write which coefficients are zero.
3. Set up the remaining integral.
4. Use integration by parts cleanly.
5. Write the final Fourier series in the correct form.

---

# Very short “if I only have 1 day” list

If you are very short on time, do only these:

## Sequences

- **6A-9.7**
- **6A-9.8**
- **6A-10.6**
- **6B-5.8**

## Higher-order sequences and sums

- **6A-25.1**
- **6A-25.3**
- **6B-17.5**
- **6B-17.6**

## Series convergence

- **6D-20.10**
- **6D-21.11**
- **6D-22.4**
- **6D-24.9**
- **6D-25.4**
- **6D-26.2**
- **6D-29**
- **6D-31.45**

## Taylor

- **6E-1.1**
- **6E-1.3**
- **6E-8.1**

## Fourier

- **6G-2.5**
- **6G-2.6**
- **6G-2.8**
- Old exam function: `x sin x`

---

# What you can skip first

If the exam is close, you can skip these at first:

- Most of **6F** — uniform convergence is more theory-style and less repeated in the old oefeningen exams.
- Very easy basic sequence exercises like **6A-1**, **6A-2**, **6A-8** unless you feel weak on definitions.
- Long story/application exercises unless they clearly match the old exam format.
- Fourier proof exercises like **6G-3** unless you want extra theory depth.

---

# Final checklist before the exam

Before the exam, make sure you can do these without looking at the solution:

- Build arithmetic sequences from sum/product/squares.
- Build geometric sequences from sum/squares or partial sums.
- Use difference rows to find the order and formula of a higher-order sequence.
- Compute partial sums using `S_1(n)`, `S_2(n)`, `S_3(n)`.
- Prove a partial sum formula is always an integer.
- Choose the correct convergence test for a series.
- Distinguish convergence from “the general term goes to zero”.
- Compute Taylor polynomials cleanly.
- Use a Taylor remainder estimate when asked.
- Start Fourier questions by checking even/odd symmetry.
- Do integration by parts for Fourier coefficients without losing signs.

If you can do the exercises in this file, you are preparing for the real exam patterns instead of wasting time on low-yield exercises.
