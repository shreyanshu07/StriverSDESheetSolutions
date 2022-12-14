class Solution {
public:
    int get(char c){
        if(c=='I') return 1;
        if(c=='V') return 5;
        if(c=='X') return 10;
        if(c=='L') return 50;
        if(c=='C') return 100;
        if(c=='D') return 500;
        if(c=='M') return 1000;
        return -1;
    }
    int romanToInt(string s) {
        int n=s.size(),one=0,ans=0;
        for(int i=0;i<n;i++){
            ans+=get(s[i]);
            if(i>0 and (get(s[i-1])<get(s[i]))){
                int j=i,sum=0;
                while(j--){
                    sum+=get(s[j]);
                    if(j>0 and (get(s[j])<=get(s[j-1]))) break;
                }
                ans=ans-(2*sum);
            }
        }
        
        return ans;
    }
};
