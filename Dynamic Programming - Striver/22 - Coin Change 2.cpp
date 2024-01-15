class Solution {
public:
    int solve(int idx, int target, vector<int>& coins, vector<vector<int>> &ways)
    {
        if(target == 0) return 1;
        if(idx == coins.size() - 1)
        {
            if(target % coins[idx] == 0)
            {
                return 1;
            }
            return 0;
        }
        if(ways[idx][target] != -1) return ways[idx][target];
        int notTake = solve(idx+1,target,coins,ways);
        int take = 0;
        if(coins[idx] <= target)
        {
            take = solve(idx,target - coins[idx],coins,ways);
        }
        ways[idx][target] = take + notTake;
        return ways[idx][target];
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> ways(coins.size(),vector<int>(amount+1,-1));
        return solve(0,amount,coins,ways);
    }
};