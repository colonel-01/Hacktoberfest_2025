#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int ans = high + 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> ls = {1, 3, 5, 6};
    int ele = 5;
    int res = searchInsert(ls, ele);
    cout << "Target position is: " << res << endl;
    return 0;
}