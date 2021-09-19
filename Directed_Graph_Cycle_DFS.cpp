  
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool isDirectedGraphCycleDFS(int node, vector<int>&dfsVisited, vector<int>&visited, vector<vector<int>>&adjacency_list){
    visited[node]=1;
    dfsVisited[node]=1;
    for(auto child : adjacency_list[node]){
        if(!visited[child]){
            if(isDirectedGraphCycleDFS(child,dfsVisited,visited,adjacency_list))return true;
        }
        else if(dfsVisited[child])return true;
    }//end for
    dfsVisited[node]=0;
    return false;
}

bool isCyclicDFS(vector<vector<int>>&adjacency_list){
    int N = adjacency_list.size();
    vector<int>visited(N,0);
    vector<int>dfsVisited(N,0);
    for(int i=1;i<N;i++){
        if(!visited[i]){
            if(isDirectedGraphCycleDFS(i,dfsVisited,visited,adjacency_list)){
                return true;
            }
        }//end if
    }//end for
    return false;
}

int main()
{
    //directed graph
    vector<vector<int>> adjacency_list = {
        {},
        {2},
        {3},
        {4,6},
        {5},
        {},
        {5},
        {2,8},
        {9},
        {7}
    };
    
    
    if(isCyclicDFS(adjacency_list))cout<<"Graph contains cycle"<<endl;
    else cout<<"No cycle exists"<<endl;
    
    return 0;
}
