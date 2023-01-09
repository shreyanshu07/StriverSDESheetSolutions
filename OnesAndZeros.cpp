class Solution {
public:
 
    int findMaxForm(vector<string>& s, int m, int n) {
        int sz = s.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        int cnt[sz+1][2];
        for(int i=0;i<sz;i++){
            int c0 = count(s[i].begin(), s[i].end(),'0');
            int c1 = count(s[i].begin(), s[i].end(),'1');
            cnt[i+1][0]= c0;
            cnt[i+1][1]=c1;
        }
        for(int i=1;i <= sz;i++){
            for(int j=m;j>=0;j--){
                for(int k=n;k>=0;k--){
                    
                    if((j-cnt[i][0]) >=0 && (k-cnt[i][1]) >= 0){
                        dp[j][k] = max(dp[j][k], dp[j-cnt[i][0]][k-cnt[i][1]]+1);
                    }
                }
            }
        }
        return dp[m][n];
    }
};
