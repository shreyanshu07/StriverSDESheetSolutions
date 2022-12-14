class Solution {
public:
    double myPow(double x, long long n) {
        if(n==0) return 1;
        bool neg=false;
        if(n<0) neg=true;
        n=abs(n);
        long long a=log2(n);
        
        double ans=x;
        for(long long i=0;i<a;i++){
            ans*=ans;
        }
        a=pow(2,a);
        a=log2(a);
        ans=x;
        for(long long i=0;i<a;i++){
            ans*=ans;
        }
        a=pow(2,a);
        for(long long i=a;i<n;i++){
            ans*=x;
        }
        if(neg){
            ans=1/ans;

        }
        return ans;
        
    }
};
