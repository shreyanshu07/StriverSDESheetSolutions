class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int,greater<int>> mp;
        vector<int> v;
        int n=nums.size();
        for(int i=0;i<k;i++) mp[nums[i]]++;
        auto it=mp.begin();
        v.push_back(it->first);
        for(int i=k;i<n;i++){
            mp[nums[i]]++;
            auto it=mp.find(nums[i-k]);
            it->second--;
            if(it->second==0) mp.erase(nums[i-k]);
            it=mp.begin();
            v.push_back(it->first);
        }
        return v;
    }
};
