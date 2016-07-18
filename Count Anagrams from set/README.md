# Question and Explanation

### Anagram

Two words are said to be anagram when one word can be __converted__ into another word by __shuffling/rearranging__ characters.

+ __Q.__ Given a set of words find the __number__ of anagram for each word in given set of words.


# Solution

## Logic

+ The Logic behind the solution is that when all __words__ are `sorted`, then __Anagrams__ will be the `same` __strings__.

+ Then we can again `sort` the __array__ of `sorted` __strings__.

+ This will make __anagram words__ to appear `together`.

+ Then we can simply __count__ the anagrams, to get our answer.

## Example

+ Lets take array `["cat", "dog", "tac", "god", "act"]`.

+ After first sorting we have `["act", "dgo", "act", "dgo", act]`.

+ Then after sorting the whole array we have `["act", "act", "act", "dgo", "dgo"]`

+ Clearly we can now count easily.
