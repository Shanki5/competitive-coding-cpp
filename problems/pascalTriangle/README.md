# Pascal's Triangle

## Problem Description

Given an integer N, return the first N rows of Pascal’s triangle.
In Pascal’s triangle, each number is the sum of the two numbers directly above it as shown in the figure below:

https://lh5.googleusercontent.com/SGqPaM5UefpH-NP2uVMvPGu2XpdlRSgesdFQEP_W_6v5rbdw8S0gKXKgi0NIGtY5xjoHlLDEtgc7ICZN8PQDzpr2RPG1ebLqj_gzN_K2gQqZn3ju8dz0WSccoZnTzid22-j-_SJq=s1600

https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif

## Solution

### Intuition

There are 3 properties of the pascal's triangle we need to make a note of.

1. Each row has index number of elements. 1st Row has 1 element, 2nd row has 2 elements and so on.
2. The border elements of each row are always 1.
3. All the other elements are simply the sum of triangle[i-1][j-1]+triangle[i-1][j] elements.

### Approach

1. We can create an empty vector of vectors.
2. While iterating through we can resize based on the loop's iteration (property 1).
3. In each row we set first and last element to 1.
4. Run a loop to set the other elements of each row.

### Time Complexity

$$O(n^2)$$

### Space Complexity

$$O(n)$$

### Code

```C++
vector<vector<int>> pascalsTriangle(int n)
{
    vector<vector<int>> result(n);

    for (int i = 0; i < n; i++)
    {
        result[i].resize(i + 1);
        result[i][0] = result[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }

    return result;
}
```
