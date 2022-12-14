class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> output;
        if(intervals.size()) output.push_back(intervals[0]);
        for(auto& i: intervals)
            if(i[0]<=output.back()[1])  output.back()[1] = max(i[1],output.back()[1]);
            else    output.push_back(i);
        return output;
    }

};
