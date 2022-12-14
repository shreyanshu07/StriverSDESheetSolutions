class Solution {
public:
    bool allUnique(unordered_map<char,int> &hm){   //   to check if there are no repeating characters
        for(auto i: hm){
            if(i.second > 1)return false;
        }
     return true;
    }
    
    
    int lengthOfLongestSubstring(string s) {
       if(s.size()==0)return 0;
       unordered_map<char,int> hm; 
        hm[s[0]]=1; 
        int si = 0,ei=0,win=1;             //  initializing the window
        
        while(ei+1<s.size()){
 
            if(hm.count(s[ei+1])==0){     //  adding element after the end of window 
                hm[s[ei+1]] = 1;
            }
            else{
                hm[s[ei+1]]++;
            }
            
            if(allUnique(hm)){                // if after adding of element at end still results in unique characters
                ei++;
                win = ei-si+1;     // window size increased due to addidtion of element without changing start
            }
            else{                                  // if not the move window by 1 from front also
                hm[s[si]]--;
                si++;
                ei++;
            }
        } 
        return win;    
    }
};
