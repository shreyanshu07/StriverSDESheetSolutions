class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        int n=nums.size();
        int m=n/2;
        for(int x:nums) mp[x]++;
        for(auto it:mp){
            if(it.second>m) return it.first;
        }
        return 0;
    }
};
