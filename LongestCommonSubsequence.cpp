#include<bits/stdc++.h>
class Solution {
public:
    int dp[1001][1001];
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        memset(dp,-1,sizeof dp);
        return lcs(text1,text2,n,m);
    }
    int lcs(string s1,string s2,int n,int m){
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
