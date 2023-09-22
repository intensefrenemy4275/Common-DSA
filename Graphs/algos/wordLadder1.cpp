//link - https://practice.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        if(st.find(startWord) != st.end())
        {
            st.erase(startWord);
        }
        q.push(make_pair(startWord,1));
        while(!q.empty())
        {
            string frontal = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(frontal == targetWord)
                return lvl;
            for(int i=0;i<frontal.length();i++)
            {
                char toChange = frontal[i];
                for(char ch = 'a';ch<='z';ch++)
                {
                    frontal[i] = ch;
                    if(st.find(frontal) != st.end())
                    {
                        st.erase(frontal);
                        q.push(make_pair(frontal,lvl+1));
                    }
                }
                frontal[i] = toChange;
            }
        }
        return 0;
    }
};
