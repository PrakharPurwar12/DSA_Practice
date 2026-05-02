#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // prev2 represents dp[i-2], prev1 represents dp[i-1]
    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n; i++) {
        // Option 1: Include current element (nums[i] + sum from i-2)
        int pick = nums[i] + prev2;
        
        // Option 2: Exclude current element (sum remains same as i-1)
        int nonPick = prev1;

        int cur = max(pick, nonPick);
        
        // Update pointers for the next iteration
        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;
}