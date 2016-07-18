# Question and Explanation

+ __Ques.__ Given a _number n_, find the __smallest number__ that has same set of digits as n and is __greater than n__. If x is the greatest possible number with its set of digits, then print __“not possible”__.

+ __Eg,__

  + __A.__

    + Input:  n = "218765"

    + Output: "251678"

  + __B.__

    + Input:  n = "1234"

    + Output: "1243"

  + __C.__

    + Input: n = "4321"

    + Output: "Not Possible"

  + __D.__

    + Input: n = "534976"

    + Output: "536479"


# Logic

+ The logic is quite simple. First we will process string from __right__ to __left__.

+ Find the first index `from right` which has the value __less__ than the value at its __right
index__.

+ Swap this value from anywhere in the __right side__ of this index.

+ __Sort__ the right part of the string;

+ If you are not able to find such an index then simply the Output is __Not Possible__.
