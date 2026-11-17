
/**
 * Compile-time function.
 *
 * Given a natural number (i.e. x >= 0), this will return the number of bits required to represent the number.
 */
function num_bits(x: nat): nat
{
    if x / 2 == 0 then 1 else 1 + num_bits(x / 2)
}

/**
 * Runtime method.
 *
 * This multiplies two positive numbers.
 */
method Mult(a: int, b: int) returns (result: int)
    // TODO: pre-conditions
    // TODO: post-conditions
    ensures result == a * b
    requires a > 0
    requires b > 0
{
    result := 0;
    var a_current := a;
    var b_current := b;

    var g := 1;

    while(b_current > 0 || num_bits(b_current)-1 > 0)
        // TODO: invariant
        // TODO: variant
        decreases b_current
        invariant b_current >= 0
        invariant g > 0
        invariant result + a * b_current * g == a *b
     {
        result := result + a * g * (b_current % 2);

        b_current := b_current / 2;
        g := g * 2;
    }

    return result;
}
