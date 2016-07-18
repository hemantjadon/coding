## Logic

+ The helper function `convert()` just converts the `integer` argument to a
corresponding `ascii` character and returns it. If the input is outside the bounds
of `1-26` the it returns a `NULL` character.

+ The main function uses __recursion__.

  + __Arguments__

    + The arguments of the function are `numeral_string str`,`integer index`,  `output_string output`.

    + The output string is default to `""`(blank string);

    + The index is default to `0`.

  + __Base Case__

    + The base case is quite simple, when __index__ is equal to __length__ of __str__

      + __print__ the output_string.

      + return.

  + __Loop__

    + The loop is of the __gap__ ie. the length of the string to take into account for conversion.

    + This loop starts with __diff=0__ and goes until __index+diff < length of string__. This ensures diff is
    never out of bound.

    + Then we take out the part of `numeral_string` which we need to convert. We do so by
    using another loop starting from __index__ upto the __diff__ ie. current diff value.

    + We convert the string generated from the above loop using the `stoi()` function. __REMEMBER : stoi()__

    + Then we convert the integer to corresponding alphabet using `convert()`.

    + Check the `converted_alphabet`.

      + If `converted_alphabet` is __NULL__ then we just don't do anything and `continue` the loop.

      + Else we __append__ the alphabet to the output_string.

    + Then we call for recursion with __incremented index__.
