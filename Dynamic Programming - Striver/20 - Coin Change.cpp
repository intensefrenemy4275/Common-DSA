class Solution {
public:
    int solve(int idx, int target, vector<int>& coins, vector<vector<int>> &ways)
    {
        if(target == 0) return 0;
        if(idx == coins.size() - 1)
        {
            if(target % coins[idx] == 0)
                return target / coins[idx];
                return 1e9;
        }
        if(ways[idx][target] != -2)
        {
            return ways[idx][target];
        }
        int notTake = solve(idx+1,target,coins,ways);
        int take = 1e9;
        if(coins[idx] <= target)
        {
            take = 1 + solve(idx,target - coins[idx],coins,ways);
        }
        ways[idx][target] = min(take,notTake);
        return ways[idx][target];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<vector<int>> ways(coins.size(),vector<int>(amount+1,-2));
        // return 0;
        int a = solve(0,amount,coins,ways);
        if(a != 1e9) return a;
        return -1;
    }
};