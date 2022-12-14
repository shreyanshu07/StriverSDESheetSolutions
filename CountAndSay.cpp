class Solution {
public:
    string s="1";
    vector<string> v;
    string fun(string s){
        int n=s.size(),i=1,count=1;
        char c=s[0];
        string ans;
        while(i<n){
            if(c==s[i]){
                count++;
                
            }
            else{
                if(count) {ans+=(count+'0');ans+=(c);}
                count=1;

            }
            c=s[i];
            i++;
        }
        if(count) {ans+=(count+'0');ans+=(c);}
        return ans;
    }
    void store(int n){
        if(n<2){
            v[n-1]="1";
            return;
        }
        //if(v[30-n]!="") return;
        s=fun(s);
        v[n-1]=s;
        store(n-1);
        return ;
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        int i=31;
        while(i--) v.push_back("");
        store(30);
        return v[31-n];
    }
};
