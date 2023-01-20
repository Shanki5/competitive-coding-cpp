#include <vector>

using namespace std;

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