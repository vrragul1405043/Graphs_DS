  
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>&result, vector<int>&visited, vector<vector<int>>&adjacency_list){
    visited[node]=1;
    result.push_back(node);
    for(int& child : adjacency_list[node]){
        if(!visited[child]){
            dfs(child,result,visited,adjacency_list);
        }//end if
    }//end for
}

vector<int>dfsOfGraph(vector<vector<int>>&adjacency_list){
    int N = adjacency_list.size();
    vector<int>visited(N,0);
    vector<int>result;
    for(int i=1;i<N;i++){
        if(!visited[i]){
            dfs(i,result,visited,adjacency_list);
        }
    }//end for
    return result;
}


int main()
{
    //directed graph
    // vector<vector<int>> adjacency_list = {
    //     {},
    //     {2},
    //     {3},
    //     {4,6},
    //     {5},
    //     {},
    //     {5},
    //     {2,8},
    //     {9},
    //     {7}
    // };
    
    //undirected_graph
    vector<vector<int>> adjacency_list = {
        {},
        {2},
        {1,3,7},
        {2,5},
        {6},
        {3,7},
        {4},
        {2,5}
    };
    
    vector<int>result = dfsOfGraph(adjacency_list);
    for(int& num : result)cout<<num<<"\t";
    
    return 0;
}
