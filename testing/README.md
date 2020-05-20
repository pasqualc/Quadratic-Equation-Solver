README.md
License GPL 2.0 JKK Consulting 2019 

Quad solver unit tests directory. The files 'tX.c' are unit tests
for various functions defined in the quad solver program. 

NOTE: to run the following commands, set 'testing' directory to current directory.
To compile all tests use command:
$ sudo make

To run all tests use command:
$ sudo make test

To run individual tests use command:
$ sudo ./tX
where X is the unit test number you wish to run.

Below are brief descriptions of each unit test:
t0: Tests against qsolve_roots function, the function that
takes inputs (a, b, c), calculates the root(s) (if any exist),
and places the values of those roots into root variables (x1, x2).
    INCLUDED TESTS:

        QUAD HAS ONE ROOT: Verifies that the quad has only one root when 
        the descriminant is zero.

        QUAD ROOTS VALID ERROR: Veriries that the absolute difference between the expected result
        and the actual result is less than FLT_EPSILON.

        QUAD HAS NO REAL ROOTS: Verifies that the quad has no real roots when
        the descriminant is negative.

t1: Tests against the validate function, the function that reads
3 input tokens (tokens are separated by a space char in a given input string) from the command line, and determines that they are valid coefficients (normalized, not infinite, not NaN, etc.).
    INCLUCDED TESTS:
        INPUT VALID WITH INTEGERS: Verifies that 3 integers can be read from an input and pass as valid input.

        INPUT VALID WITH FLOATS: Verifies that 3 floats can be read from an input and pass as valid input.

        INPUT VALID WITH SCIENTIFIC NOTATION: Verifies that 3 numbers expressed in scientific can be read from input and pass as valid input.

        INPUT IS NOT QUADRATIC: Verifies that input is not valid when first number expressed is zero (ie a == 0 thus input does not represent quadratic function).

        INPUT HAS LESS THAN THREE NUMBERS: Verifies that when 3 numbers are not given in an input string, the input does not pass as valid.

        INPUT HAS NON NUMERIC TOKENS: Verifies that when there is a token in the input string, the input does not pass as valid.

        INPUT HAS INFINITY: Verifies that when there is an input token that evaluates to infinity, the input does not pass as valid.

        INPUT HAS NAN: Verifies that when there is an input token that evaluates to NaN, the input does not pass as valid.

        INPUT HAS SUBNORMAL: Verifies that when there is an input token that evaluates to a subnormal normal, the input does not pass as valid.

t2: Monkey tests against validate function.
    INCLUDED TESTS:
        MONKEY ONE: Monkey enters gibberish, and the system rejects it as valid input.
            
        MONKEY TWO: Monkey enters gibberish resembling 3 float numbers, and the system rejects it as valid input.

        MONKEY THREE: Monkey enters input with too many decimal points, and the system rejects it as valid input.

        MONKEY FOUR: Monkey enters more input consecutive decimal points, and the system rejects it as valid input.

t3: Boundary tests for validate function.
    INCLUDED TESTS:
        INPUT FLOAT TOO LARGE: Verifies that if an input value has number that is too large to fit in a float, the input is invalid.

        INPUT FLOAT TOO SMALL: Verifies that if an input value has number that is too small to fit in a float, the input is invalid.

        INPUT FLOAT MAX OKAY: Verifies that if an input value is the largest possible float value, the input is still valid.

        INPUT FLOAT MIN OKAY: Verifies that if an input value is the smallest possible float value, the input is still valid.

