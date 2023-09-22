//link - https://practice.geeksforgeeks.org/problems/word-ladder-ii/1
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(),wordList.end());
        if(set.find(beginWord) != set.end())
        {
            set.erase(beginWord);
        }
        queue<vector<string>> q;
        vector<string> start;
        start.push_back(beginWord);
        q.push(start);
        vector<vector<string>> ans;
        while(!q.empty())
        {
            vector<string> used;
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                vector<string> frontal = q.front();
                q.pop();
                if(frontal[frontal.size()-1] == targetWord)
                {
                    if(ans.size() == 0)
                    {
                        ans.push_back(frontal);
                    }
                    else
                    {
                        if(ans[0].size() == frontal.size())
                        {
                            ans.push_back(frontal);
                        }
                    }
                    continue;
                }
                string word = frontal[frontal.size()-1];
                for(int i=0;i<word.length();i++)
                {
                    char toChange = word[i];
                    for(char ch = 'a';ch<='z';ch++)
                    {
                        word[i] = ch;
                        if(set.find(word) != set.end())
                        {
                            frontal.push_back(word);
                            q.push(frontal);
                            frontal.pop_back();
                            used.push_back(word);
                        }
                    }
                    word[i] = toChange;
                }
            }
            for(int i=0;i<used.size();i++)
            {
                set.erase(used[i]);
            }
        }
        return ans;
    }
};
