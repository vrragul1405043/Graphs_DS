#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Bellamn Ford algorithm -> Single source shortest path


//computing the topological sort using Kahn algorithm -> inDegree (Toposort because all the 
// dependencies of the node occur 
// previously itself thus computing the optimal path along the path)

vector<int>topological_sort(vector<vector<pair<int,int>>>&adjacencyList){
    vector<int>result;
    vector<int>inDegree(adjacencyList.size(),0);
    queue<int>Q;
    
    for(int i=0; i<adjacencyList.size(); i++){
        for(auto it : adjacencyList[i]){
            inDegree[it.first]++;
        }
    }
    
    for(int i=0;i<inDegree.size();i++){
        if(inDegree[i] == 0)Q.push(i);
    }
    
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        result.push_back(node);
        for(auto it : adjacencyList[node]){
            inDegree[it.first]--;
            if(inDegree[it.first]==0)Q.push(it.first);
        }//end for
    }//end while
    return result;
}

void compute_distances(vector<vector<pair<int,int>>>&adjacencyList, vector<int>&distances, queue<int>&topological_array, int source){
    distances[source] = 0;
    while(!topological_array.empty()){
        int node = topological_array.front();
        topological_array.pop();
        if(distances[node]!=INT_MAX){
            for(auto neighbour : adjacencyList[node]){
                int computed_distance = distances[node] + neighbour.second;
                distances[neighbour.first] = min(distances[neighbour.first], computed_distance);
            }//end for
        }//end if
    }//end while
}

int main()
{
    //adjacency list
    vector<vector<pair<int,int>>> adjacencyList = {
        {{1,2}, {4,1}},
        {{2,3}},
        {{3,6}},
        {},
        {{2,2}, {5,4}},
        {{3,1}}
    };
    
    vector<int>result = topological_sort(adjacencyList);
    queue<int>Q;
    for(auto node : result)Q.push(node);
    vector<int>distances(adjacencyList.size(),INT_MAX);
    compute_distances(adjacencyList, distances,Q,0);
    for(int i=0;i<distances.size();i++){
        cout<<"0->"<<i<<" of distance "<<distances[i]<<endl;
    }
    return 0;
}

