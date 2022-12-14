class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        vector<int> l(n,0),r(n,0);
        int maxl=a[0],maxr=a[n-1];
        for(int i=1;i<n-1;i++){
            l[i]=maxl;
            maxl=max(a[i],maxl);
            cout<<l[i]<<" ";
        }
        cout<<endl;
        for(int i=n-2;i>0;i--){
            r[i]=maxr;
            maxr=max(a[i],maxr);
            cout<<r[i]<<" ";
        }
        int ans=0;
        for(int i=1;i<(n-1);i++){
            int s=(min(l[i],r[i])) - a[i];
            if(s<0) s=0;
            ans+=s;
        }
        return ans;
    }
};
