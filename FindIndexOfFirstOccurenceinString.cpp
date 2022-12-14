class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size(),len=haystack.size();
        if(haystack=="" and needle=="") return 0;
        for(int i=0;i<=(len-n);i++){
            string ss=haystack.substr(i,n);
            //cout<<ss<<" ";
            if(ss==needle) return i;
            
        }
        return -1;
    }
};
