# Question and Explanation

+ An element in a sorted array can be found in `O(log n)` time via __binary search__.

+ But suppose we __rotate__ an ascending order sorted array at some __pivot__ _unknown_ to you beforehand.

+ So for instance, `1 2 3 4 5` might become `3 4 5 1 2`.

+ Devise a way to find an element in the __rotated array__ in `O(log n)` time.


# Solution

+ Solution consists of two parts

  + __Find__ the `pivot`.

  + Use __Standard Binary Search__.


### Finding Pivot

+ The main _observation_ while finding out the pivot is that, Pivot is the point in the array
where the `__next element < pivot element__`.

+ So we can start by simply dividing the array in two halves.

  + `mid = (low + high)/2`

  + If `arr[mid+1]` is _lesser_ than `arr[mid]`. Then simply __mid__ is the `pivot`.

  + Else if `arr[mid-1]` is _greater_ than `arr[mid]`.Then by same logic __mid-1__ is the `pivot`.

  + Else `pivot` can either in `left subarray` or `right subarray`.

    + We can now compare `arr[0]` with `arr[mid]`.

    + If `arr[0] > arr[mid]` ie. we can see that _mid_ is located somewhere in __Rotated part__ of the array.
    And `pivot` will be found in `left subarray`.

    + Else if `arr[0] < arr[mid]`, _mid_ lies in __non-rotated__ part of the arrat.
    And  `pivot` will be found in `right subarray`.

  + As the base case we can think as If `low > high`, we have crossed the bounds, and `pivot` __does not exist__.


### Searching For Element.

+ Once `pivot` has been found.

+ We can find required `element` by following steps:

  + Requires element will either be in _left_ of `pivot` or in _right_ of `pivot`.

  + If `element > arr[0]` then element will be in __non-rotated__ part __(left)__ of `pivot`.

  + Else If `element < arr[0]` then it must be in __rotated__ part __(right)__ of `pivot`.

  + Both these parts are __individually sorted__. Thus Simple __Binary Search__ can be used to find the `element`.
