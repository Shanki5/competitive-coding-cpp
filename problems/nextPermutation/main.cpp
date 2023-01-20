#include <vector>
#include <algorithm>

using namespace std;

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