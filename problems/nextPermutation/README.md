# Next Permutation

## Problem Description

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

-   For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

-   For example, the next permutation of arr = [1,2,3] is [1,3,2].
-   Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
-   While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
    Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

## Solution

### Intuition

If we plot the arrays we can see that, there will be peaks and valleys. Now if we observe carefully, the next permutation typically would be the array with the next highest element instead of the element that drops.

Refer [Strider's Youtube video](https://www.youtube.com/watch?v=LuLCLgMElus&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=9) for a more visual understanding.

### Approach

1. Iterate in reverse and find the element(i) where the peak drops.
2. Iterate in reverse and find the first element which is greater than i.
3. Swap the elements
4. Reverse the array from index of i.

### Time Complexity

$$O(n)$$

### Space Complexity

$$O(1)$$

### Code

```C++
void nextPermutation(vector<int> &nums)
{
    int n = size(nums);
    int k = n - 2, j = n - 1;

    while (k > 0)
    {
        if (nums[k] < nums[k + 1])
        {
            break;
        }
        k--;
    }
    if (k < 0)
        reverse(nums.begin(), nums.end());
    else
    {
        while (j > k)
        {
            if (nums[k] < nums[j])
                break;
            j--;
        }
        swap(nums[k], nums[j]);
        reverse(nums.begin() + k + 1, nums.end());
    }
}
```
