#include <bits/stdc++.h>
using namespace std;
void insert(vector<int> &stupid, int val)
{
    if(stupid[stupid.size() - 1] < val)
    {
        stupid.push_back(val);
        return;
    }
    int s = 0;
    int e = stupid.size() - 1;
    int mid = (e - s)/2 + s;
    while(s<=e)
    {
        if(mid == 0 || mid == stupid.size() - 1) // THIS IS WRONG !!! Need to Handle it Better...
        {
            stupid[mid] = val; 
            return;
        }
        if(stupid[mid] >= val && stupid[mid-1] < val)
        {
            stupid[mid] = val;
            return;
        }
        else if(stupid[mid] > val)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = (e - s) / 2 + s;
    }
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> lis;
    lis.push_back(arr[0]);
    for(int i = 1; i<n ; i++)
    {
        insert(lis,arr[i]);
    }
    return lis.size();
}