class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n=prices.size(),maxi=INT_MIN,mini=INT_MAX;
        vector<int> maxR(n,0);
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,prices[i]);
            maxR[i]=maxi;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int s=maxR[i]-prices[i];
            if(s>0) ans=max(ans,s);
        }
        return ans;
    }
};
