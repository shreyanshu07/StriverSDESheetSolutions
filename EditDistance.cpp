class Solution {
public:
    int dp[501][501];
    int minDistance(string word1, string word2) {
        //memset(dp,-1,sizeof dp);
        return eD2(word1,word2,word1.size(),word2.size());
    }
    int eD(string s1,string s2,int m,int n){
        if(m==0) return n;
        if(n==0) return m;
        if(s1[m-1]==s2[n-1]) return eD(s1,s2,m-1,n-1);
        else{
            return 1+min(eD(s1,s2,m-1,n),min(eD(s1,s2,m,n-1),eD(s1,s2,m-1,n-1)));
        }
    }
    
    int eD1(string s1,string s2,int m,int n){
        if(dp[m][n]!=-1) return dp[m][n];
        if(m==0){
            dp[m][n]=n;
        }
        else if(n==0){
            dp[m][n]=m;
        }
        else{
            if(s1[m-1]==s2[n-1]) dp[m][n]=eD(s1,s2,m-1,n-1);
            else dp[m][n]=1+min(eD(s1,s2,m-1,n),min(eD(s1,s2,m,n-1),eD(s1,s2,m-1,n-1)));
        }
        return dp[m][n];
        
    }
    int eD2(string s1,string s2,int n,int m){
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};
