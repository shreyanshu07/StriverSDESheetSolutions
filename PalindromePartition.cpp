class Solution {
public:
    bool isPal(string &s , int low ,int high)
    {
        while(low < high)
        {
            if(s[low++] != s[high--])return false;
        }
        return true;
    }
    
    void dfs(vector<vector<string>> &res , string &s , int start , vector<string> curr)
    {
        if(start == s.size()) res.push_back(curr);
        
        for(int end = start ; end < s.size() ; end++)
        {
            if(isPal(s,start,end))
            {
                curr.push_back(s.substr(start,end - start + 1));
                dfs(res,s,end+1,curr);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        dfs(res,s,0,curr);
        return res;
    }
};
