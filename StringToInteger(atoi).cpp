class Solution {
public:
    int myAtoi(string s) {
        double x=0;
        int n=s.length(),i=0;
        string num=""; bool pos=true;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='-'){ pos=false;i++;}
        else if(s[i]=='+'){i++;}
        if(s[i]!='-' and s[i]!='+' and !(s[i]>47 and s[i]<58) ) return 0;
        while(i<n){
            if(s[i]>47 and s[i]<58){
                num=num+s[i];
            }
            else{
                break;
            }
            i++;
        }
        //cout<<num<<endl;
        n=num.length();
        x=0;
        for(i=0;i<n;i++){
            x=(x*10)+(int(num[i])-48);
            //cout<<x<<endl;
        }
        //cout<<n<<endl;
        if(!pos) x=-1*x;
        if(x>(2147483647)) x=2147483647;
        else if(x<(-2147483648)) x=-2147483648;
        int ans=x;
        return ans;
    }
};
