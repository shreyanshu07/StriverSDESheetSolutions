class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;vector<int> curr;
        check(0,candidates,curr,ans,target);
        return ans;
    }
    void check(int start,vector<int>& can,vector<int>& curr,vector<vector<int>>& ans,int target){
        if(target==0){
            ans.push_back(curr);
            
        }
        if(target<0) return;
        for(int i=start;i<can.size();i++){
            curr.push_back(can[i]);
            check(i,can,curr,ans,(target-can[i]));
            curr.pop_back();
        }
    }
};
