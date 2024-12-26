#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canWin(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int pickLeft = nums[left] - canWin(nums, left + 1, right);
        int pickRight = nums[right] - canWin(nums, left, right - 1);
        return max(pickLeft, pickRight);
    }

    bool PredictTheWinner(vector<int>& nums) {
        return canWin(nums, 0, nums.size() - 1) >= 0;
    }
};
