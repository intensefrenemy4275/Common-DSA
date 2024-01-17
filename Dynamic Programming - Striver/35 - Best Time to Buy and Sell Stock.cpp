#include <bits/stdc++.h> 
using namespace std;
int maximumProfit(vector<int> &prices){
    int profit = 0;
    int mini = prices[0];
    for(auto i : prices)
    {
        profit = max(profit, i - mini);
        mini = min(mini, i);
    }
    return profit;
}