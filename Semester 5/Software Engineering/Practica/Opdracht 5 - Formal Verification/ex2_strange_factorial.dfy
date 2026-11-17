
/**
 * Compile-time function.
 *
 * Returns the factorial of n such that n! = n * (n-1) * ... * 1
 */
function fact_recursive(n: nat): nat {
    if n == 0 || n == 1 then 1 else n * fact_recursive(n-1)
}

/**
 * Runtime method.
 *
 * Returns the factorial of n such that n! = n * (n-1) * ... * 1
 */
method strange_factorial(n: nat) returns (retval: nat)
    // TODO: post-condition
{
    var R := 0;
    retval := 1;

    while (R < n || retval != fact_recursive(n))
        // TODO: invariant
        // TODO: variant
    {
        var V := retval; 

        var S := 1;
        while (S <= R || retval != (R+1) * V)
            // TODO: invariant
            // TODO: variant
        {
            retval := retval + V;
            S := S + 1;
        }

        R := R + 1;
        
    }

    return retval;
}
