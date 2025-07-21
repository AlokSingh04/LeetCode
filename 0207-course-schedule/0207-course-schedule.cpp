class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> indegree(numCourses);
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }

        vector<int> res;
        queue<int> que;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 0) que.push(i);
        }

        while(!que.empty()){
            int temp = que.front();
            que.pop();
            res.push_back(temp);
            for(auto it : adj[temp]){
                indegree[it]--;
                if(indegree[it] == 0) que.push(it);
            }
        }

        return res.size() == numCourses;
    }
};