class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> m;
        vector<int> v;
        int n=nums.size();
        for(auto it:nums){
            m[it]++;
        }
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>floor(n/3)){
                v.push_back(it->first);
            }
        }
        return v;
    }
};
