# Chapter 2 — Most Important Exercises for the Exam

This file is a practical study guide for **H2: Continuïteit en limieten in R**.

The goal is **not** to do every exercise from H2. The goal is to do the exercises that are closest to the old exam questions and that train the exact patterns that keep coming back.

Chapter 2 in the course notes contains:

- **2A**: functions, domain, continuity
- **2B**: cyclometric functions: Bgsin, Bgcos, Bgtan, Bgcot
- **2C**: formal definitions of limits
- **2D**: calculating limits
- **2E**: exponential and logarithmic functions/equations
- **2F**: hyperbolic functions

## Big picture: what actually comes back in exams?

The old exams show a very clear pattern for H2:

1. **Limit calculation without l’Hôpital**
   - This is the most important part.
   - Almost every recent exam has a question like this.
   - The question usually contains 3 smaller limits:
     - one rational limit,
     - one trigonometric limit,
     - one limit at infinity or one special exponential-type limit.

2. **Exponential or logarithmic equations**
   - Very common as a full 10-point question.
   - Usually solved by a smart substitution, or by rewriting logarithms carefully.
   - You must always check the domain for logarithmic equations.

3. **Cyclometric identities**
   - Especially Bgtan/arctan sum formulas.
   - These appear as proof questions.

4. **Formal limit definitions**
   - Less common, but it has appeared.
   - You must be able to translate an epsilon/delta-type statement into a limit.

5. **Continuity/domain questions**
   - Useful foundation, but less likely as a big exam calculation question.

6. **Hyperbolic functions**
   - Lowest priority for a direct H2 exam question.
   - Still useful because sinh/cosh can appear later in derivatives/Taylor questions.

---

# Priority 1 — You really need these

These are the exercises I would do first if the exam is close.

## 1. Limits: rational functions and one-sided limits

Do:

- **2D-6.1, 2D-6.2, 2D-6.3, 2D-6.8**
- **2D-10.3, 2D-10.5, 2D-10.8, 2D-10.10, 2D-10.12, 2D-10.14, 2D-10.18, 2D-10.20**

Why these are important:

These train the standard exam pattern where you get a rational expression and must factor, cancel, or decide whether the limit is finite, +infinity, -infinity, or different from the left and right.

You need to be able to:

- factor numerator and denominator;
- cancel only when allowed;
- make a sign table when the denominator goes to 0;
- split into left and right limits when needed;
- handle limits at infinity by comparing leading terms.

Similar exam questions:

- **2019 1e zit, question 2**: limits of a rational function in several points, including one-sided limits.
- **2019 2e zit, question 2(b)**: rational limit.
- **2022 1e zit, question 4(a)**: rational limit.
- **2022 2e zit, question 4(a)**: rational limit.
- **2023 1e zit, question 4(a)**: rational limit.
- **2023 2e zit, question 4(a)**: rational limit.
- **2024 1e zit, question 4(a)**: rational limit.
- **2024 2e zit, question 4(a)**: rational limit.
- **Modelvragen hoofdstuk 2, question 1(a), 1(g), 1(n), 1(q)**.

Exam feeling:

If you can do these exercises fluently, then the rational-limit part of the exam should feel familiar.

---

## 2. Limits with roots and conjugates

Do:

- **2D-11.2, 2D-11.7, 2D-11.10, 2D-11.12, 2D-11.15, 2D-11.22, 2D-11.23, 2D-11.25**
- **2D-12.8, 2D-12.11, 2D-12.14, 2D-12.17, 2D-12.18**

Why these are important:

The professor likes limits where direct substitution gives an indeterminate form, and you have to use conjugates or root identities.

You need to recognize quickly when to:

- multiply by the conjugate;
- use the difference of squares;
- use the cube-root identity;
- compare leading terms under square roots at infinity.

Similar exam questions:

- **2018 2e zit, question 3**: limit with a square root expression at infinity.
- **2019 2e zit, question 2(c)**: root limit.
- **2021 1e zit, question 4**: difference of two square roots divided by x - 1.
- **2024 2e zit, question 4(c)**: root-type limit.
- **Modelvragen hoofdstuk 2, question 1(b), 1(e), 1(h), 1(j), 1(o), 1(r)**.

Exam feeling:

These are often not hard, but they are easy to mess up if you do not immediately see the algebra trick.

---

## 3. Trigonometric limits

Do:

- **2D-14.3, 2D-14.5, 2D-14.8, 2D-14.10, 2D-14.12, 2D-14.18, 2D-14.20, 2D-14.22**
- **2D-16.10, 2D-16.13, 2D-16.14**
- **2D-19.1, 2D-19.3, 2D-19.5**

Why these are important:

This is probably the second most repeated limit type after rational limits. The old exams often include a trig limit as part (b) of the limit question.

You need to know how to use:

- sin x / x -> 1;
- tan x / x -> 1;
- 1 - cos x tricks;
- cos a - cos b formulas;
- rewriting around x -> pi/2 or x -> pi;
- substitution when the angle is not simply x.

Similar exam questions:

- **2022 1e zit, question 4(b)**: trigonometric limit with tan and cos.
- **2022 2e zit, question 4(b)**: trigonometric limit with cos x - cos 3x.
- **2023 1e zit, question 4(b)**: trigonometric limit with sine sums.
- **2023 2e zit, question 4(b)**: limit with 1 - cos terms.
- **2024 1e zit, question 4(b)**: trig limit with cos 2x - 1 and sine sums.
- **2024 2e zit, question 4(b)**: limit with 1 - cos 3x and 1 - cos 5x.
- **Modelvragen hoofdstuk 2, question 1(c), 1(i), 1(m)**.

Exam feeling:

For this exam, do not only memorize formulas. You must be able to rewrite the expression until the standard limit appears.

---

## 4. Limits with absolute values and different behavior from left/right

Do:

- **2D-20.2, 2D-20.6, 2D-20.8, 2D-20.12, 2D-20.13, 2D-20.15**

Why these are important:

Absolute values often force you to split the problem into cases. This is exactly the kind of thing the exam instruction means when it says: “maak waar nodig onderscheid tussen linker- en rechterlimiet.”

You need to be able to:

- replace |x| correctly depending on the sign of x;
- replace |x - a| correctly near a from the left or right;
- decide whether the two one-sided limits agree.

Similar exam questions:

- **Modelvragen hoofdstuk 2, question 1(d)**.
- This also supports the full exam limit questions where they explicitly ask for left/right distinction.

Exam feeling:

These exercises are not always long, but they train one of the most common mistakes: treating |x - a| as if it were always x - a.

---

## 5. Special exponential-type limits

Do:

- **2E-4.7, 2E-4.8, 2E-4.13, 2E-4.19, 2E-4.21, 2E-4.22**
- **2E-5.3, 2E-5.7, 2E-5.10, 2E-5.12**
- **2E-6.1, 2E-6.2, 2E-6.3, 2E-6.4**

Why these are important:

The exams often include limits that secretly use the famous idea behind e, such as expressions of the form:

- (1 + something)^something
- something tending to 1, raised to something tending to infinity

You need to be comfortable converting these to an exponential limit.

Similar exam questions:

- **Modelvragen hoofdstuk 2, question 1(f), 1(p), 1(s)**.
- **2022 1e zit, question 4(c)**: exponential-type limit at infinity.
- **2023 1e zit, question 4(c)**: same style.
- **2024 1e zit, question 4(c)**: same style.

Exam feeling:

This is the part where many students lose points because they try to “plug in infinity.” Instead, you should rewrite it to an e-limit.

---

## 6. Exponential equations with substitution

Do:

- **2E-10.2, 2E-10.4, 2E-10.5, 2E-10.8, 2E-10.10, 2E-10.12, 2E-10.14, 2E-10.17, 2E-10.18, 2E-10.20, 2E-10.21, 2E-10.22, 2E-10.23, 2E-10.27**

Why these are important:

This is one of the most exam-like parts of H2. The typical method is:

1. choose a substitution like y = 2^x, y = 3^x, y = 4^x, etc.;
2. rewrite the equation as a polynomial equation;
3. solve the polynomial;
4. translate back to x;
5. reject impossible values if needed.

Similar exam questions:

- **2018 1e zit, question 3**: exponential equation with powers of 2.
- **2021 2e zit, question 3**: exponential equation.
- **2022 1e zit, question 3**: exponential equation with 3^x and 9^x.
- **2023 1e zit, question 3**: exponential equation with 8^x and 2^x.
- **2024 1e zit, question 3**: exponential equation.
- **Modelvragen hoofdstuk 2, questions 2, 7, 8**.

Exam feeling:

These are very worth doing because they are often a full 10-point question and the structure is predictable.

---

## 7. Logarithmic equations

Do:

- **2E-26.8, 2E-26.10, 2E-26.14, 2E-26.15, 2E-26.16, 2E-26.17, 2E-26.18, 2E-26.20, 2E-26.21, 2E-26.22, 2E-26.31, 2E-26.32, 2E-26.37, 2E-26.39**

Also do these short theory/trap exercises:

- **2E-22**
- **2E-25**
- **2E-29**
- **2E-30**

Why these are important:

Log equations are common on the exam and they are dangerous because of domain restrictions.

You must always check:

- the argument of every logarithm must be positive;
- the base of every logarithm must be positive;
- the base may not be 1;
- transformations can introduce fake solutions.

Similar exam questions:

- **2020 1e zit, question 2**: logarithmic equation, with explicit warning to check solutions.
- **2023 2e zit, question 3**: logarithmic equation with changing bases.
- **2024 2e zit, question 3**: logarithmic equation with log base 1/2 and a nested logarithm.
- **Modelvragen hoofdstuk 2, questions 4 and 5**.

Exam feeling:

For logs, the calculation is only half the question. The other half is checking whether the solutions are actually allowed.

---

## 8. Cyclometric identities: especially Bgtan

Do:

- **2B-4.1, 2B-4.3, 2B-4.7**
- **2B-6.2, 2B-6.4, 2B-6.10**
- **2B-8.1, 2B-8.2**
- **2B-9.1, 2B-9.3, 2B-9.4**

Why these are important:

The exam sometimes asks you to prove identities with Bgtan or Bgsin. These are not “calculate quickly” questions; they test whether you know how inverse trig functions behave.

You need to be able to:

- set alpha = Bgtan(a) and beta = Bgtan(b);
- use tan(alpha + beta);
- check the angle interval so the final equality is valid;
- avoid blindly applying formulas without checking the range.

Similar exam questions:

- **2018 2e zit, question 4**: proof with Bgsin.
- **2021 1e zit, question 3**: Bgtan identity.
- **2022 2e zit, question 3**: Bgtan identity.
- **Modelvragen hoofdstuk 2, questions 3 and 6**.

Exam feeling:

These questions look weird at first, but the method is very repetitive. Once you know the trick, they become manageable.

---

## 9. Formal limit definitions

Do:

- **2C-9.1, 2C-9.2, 2C-9.5, 2C-9.8**
- **2C-10.1, 2C-10.2, 2C-10.5, 2C-10.6, 2C-10.7, 2C-10.9**

Why these are important:

These train the ability to translate between a formal statement and normal limit notation.

You need to recognize:

- finite limit;
- left-hand limit;
- right-hand limit;
- limit equal to +infinity or -infinity;
- limit as x -> +infinity or x -> -infinity.

Similar exam questions:

- **2018 1e zit, question 4**: “Schrijf als een limiet.”

Exam feeling:

This is not the biggest topic, but if it appears, it is usually very direct. Either you can translate the notation, or you cannot.

---

# Priority 2 — Do these if you want extra safety

These are useful, but I would only do them after Priority 1.

## 10. Continuity and domains

Do:

- **2A-2.2, 2A-2.3, 2A-2.5, 2A-2.6, 2A-2.8, 2A-2.9**
- **2A-8.1, 2A-8.5, 2A-8.7**
- **2A-11.8, 2A-11.10, 2A-11.11, 2A-12.13, 2A-12.16**

Why these are important:

They train the basics behind limit questions: domain, discontinuities, and where a function is allowed to exist.

Similar exam questions:

- Not often a full calculation question in the recent old exams.
- Still important for avoiding mistakes in logarithmic equations and limit questions.

Exam feeling:

Do these if you sometimes forget domain restrictions or if continuity definitions still feel vague.

---

## 11. Basic hyperbolic identities

Do:

- **2F-1**
- **2F-2**
- **2F-3.1, 2F-3.2, 2F-3.3**

Why these are important:

Direct H2 hyperbolic questions are not a big recurring exam pattern. But sinh and cosh can appear later in derivatives and Taylor questions.

Similar exam questions:

- **2019 1e zit, question 6** used sinh in a Taylor question, although the main topic there is Taylor from H6.

Exam feeling:

Do not spend too much time here unless the rest of H2 is already solid.

---

# The shortest possible H2 checklist

If you have very limited time, do only this:

1. **2D-10.3, 10.5, 10.8, 10.10, 10.12, 10.14, 10.18, 10.20**
2. **2D-11.10, 11.12, 11.15, 11.22, 11.23**
3. **2D-14.8, 14.10, 14.12, 14.18, 14.20, 14.22**
4. **2D-16.10, 16.13, 16.14**
5. **2E-4.7, 4.8, 4.13, 4.21, 4.22**
6. **2E-10.4, 10.8, 10.12, 10.14, 10.18, 10.21, 10.23**
7. **2E-26.10, 26.14, 26.16, 26.17, 26.18, 26.31, 26.37, 26.39**
8. **2B-6.2, 6.4, 6.10, 8.1, 8.2**
9. **2C-10.1, 10.2, 10.5, 10.6, 10.9**

This is the most exam-efficient list.

---

# What I would skip unless you have a lot of time

You can skip these for exam-focused preparation:

- Most of **2A-15 to 2A-18**: more theoretical/topological continuity exercises.
- Most very basic calculations in **2D-1 to 2D-5**: too easy compared with exam questions.
- Most of **2E-14 to 2E-17**: useful for log basics, but not exam-level if you already know logarithm rules.
- **2E-31 to 2E-34**: interesting applications, but not the main recurring exam style.
- **2F-4**: very specific application, low exam priority.

---

# Recommended order to study H2

## Step 1 — Main exam limits

Do:

- 2D-10
- 2D-11
- 2D-12
- 2D-14
- 2D-16
- 2D-19
- 2D-20

Focus on writing clean steps, because the exam explicitly says to write as many intermediate steps as possible.

## Step 2 — Exponential/log equations

Do:

- 2E-10
- 2E-26
- 2E-22, 2E-25, 2E-29, 2E-30

For every logarithmic equation, write the domain before solving or check it at the end.

## Step 3 — Cyclometric proofs

Do:

- 2B-6
- 2B-8
- 2B-9

Always introduce angles, for example alpha = Bgtan(a), then use the tangent addition formula.

## Step 4 — Formal definitions

Do:

- 2C-9
- 2C-10

This is mostly translation practice.

## Step 5 — Only if time remains

Do:

- selected 2A exercises for domain/continuity;
- selected 2F exercises for hyperbolic identities.

---

# Final advice

For H2, the exam preparation should be built around **speed and recognition**.

You should especially recognize these forms immediately:

- rational expression gives 0/0 -> factor and cancel;
- denominator goes to 0 but numerator not -> left/right infinite limit;
- square roots -> conjugate;
- trig limit near 0 -> rewrite to sin u / u or tan u / u;
- 1 - cos u -> use identity or rewrite with sin²;
- expression like (1 + small)^(large) -> e-limit;
- exponential equation -> substitution like y = 2^x or y = 3^x;
- logarithmic equation -> check domain carefully.

If you can do the Priority 1 exercises without help, H2 should be in good shape for the exam.
