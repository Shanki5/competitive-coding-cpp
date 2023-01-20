# Overview

## Problem

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

### Input

| 1   | 1   | 1   |
| --- | --- | --- |
| 1   | 0   | 1   |
| 1   | 1   | 1   |

### Output

| 1   | 0   | 1   |
| --- | --- | --- |
| 0   | 0   | 0   |
| 1   | 0   | 1   |

## Solution

### Intuition

First let us traverse through the entire matrix and keep a track of all the row and col indices where there was a 0. We can make a second pass and set the element to 0 if that element is in a row or col that is 0

### Approach

We can use a row and col vector to store the state of the indices. Then while making the first pass, we can set the state of indices to 0, if a 0 is found.

### Time Complexity

$$O(n^2)$$

### Space Complexity

$$O(n)$$

### Code

```C++
void setZeroes(vector<vector<int>> &matrix)
{
    int m = size(matrix);
    int n = size(matrix[0]);
    vector<int> row(m, 1);
    vector<int> col(n, 1);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = col[j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] == 0 || col[j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
```
