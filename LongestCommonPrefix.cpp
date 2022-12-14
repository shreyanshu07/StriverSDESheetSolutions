class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        int n=strs.size(),m=0;
        for(int i=1;i<n;i++){
            m=min(strs[i-1].size(),ans.size());
            for(int j=0;j<m;j++){
                if(strs[i][j]!=ans[j]){
                    ans=ans.substr(0,j);
                    break;
                }
            }
        }
        return ans;
    }
};
