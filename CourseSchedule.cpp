class Solution {
public:
    bool isCyclic(int n, vector<vector<int>> adj) {
        // code here
        int indegree[n];
        memset(indegree,0,sizeof(indegree));
        for(int i=0;i<n;i++){
            for(auto it:adj[i]) indegree[it]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!indegree[i]) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
            cnt++;
        }
        cout<<cnt;
        if(cnt==n) return false;
        else return true;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> v(n);
	    for(auto it:p){
	        v[it[0]].push_back(it[1]);
	        
	    }
	    return !(isCyclic(n,v));
    }
};
