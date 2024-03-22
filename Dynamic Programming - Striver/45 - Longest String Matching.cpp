class Solution {
public:
    static bool f(string a, string b)
    {
        return a.size() < b.size();
    }
    bool match(string& s2, string& s1){
    if(s1.size() != s2.size() + 1) return false;
    
    int first = 0;
    int second = 0;
    
    while(first < s1.size()){
        if(second < s2.size() && s1[first] == s2[second]){
            first ++;
            second ++;
        }
        else first ++;
    }
    if(first == s1.size() && second == s2.size()) return true;
    else return false; 
}
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), f);
        // vector<vector<int>> dp(words.size()+2, vector<int>(words.size()+2,0));
        vector<int> next(words.size()+2,0);
        vector<int> curr(words.size()+2,0);
        for(int i = words.size();i>=1;i--)
        {
            for(int j = 0; j<=words.size();j++)
            {
                if(j == 0 || match(words[j-1], words[i-1]))
                {
                    curr[j] = max(next[j], next[i] + 1);
                }
                else
                {
                    curr[j] = next[j];
                }
            }
            next = curr;
        }
        return next[0];
    }
};