class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int completed_courses = 0;
        vector<vector<int>>adjacency_list(numCourses);
        vector<int>indegree(numCourses,0);
        construct_adjacency_list_and_indegree(prerequisites, adjacency_list,indegree);
        queue<int>Q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0)Q.push(i);
        }
        if(Q.empty())return false;
        while(!Q.empty()){
            int node = Q.front();
            Q.pop();
            completed_courses++;
            for(int& neighbour : adjacency_list[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0)Q.push(neighbour);
            }//end for
        }//end while
        if(count == numCourses)return true;
        return false; 
    }
private:
    void construct_adjacency_list_and_indegree(vector<vector<int>>& prerequisites, vector<vector<int>>&adjacency_list, vector<int>&indegree){
        for(int i=0;i<prerequisites.size();i++){
            adjacency_list[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
    }
};
