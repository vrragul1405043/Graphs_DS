/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void dfs(int node, vector<vector<int>>&adjacency_list, vector<int>&visited, stack<int>&S){
    visited[node]=1;
    for(int child : adjacency_list[node]){
        if(visited[child]==0){
            dfs(child,adjacency_list,visited,S);
        }
    }
    S.push(node);
}

void topological_sort(int N, vector<vector<int>>&adjacency_list){
    vector<int>visited(N,0);
    stack<int>S;
    for(int i=0;i<N;i++){
        if(!visited[i]){
            dfs(i,adjacency_list,visited,S);
        }
    }//end for
    
    while(!S.empty()){
        cout<<S.top()<<"\t";
        S.pop();
    }
    
}

int main()
{
    vector<int>result;
    vector<vector<int>>adjacency_list = {
        {},
        {},
        {3},
        {1},
        {0,1},
        {0,2}
    };
    
    topological_sort(adjacency_list.size(),adjacency_list);
    return 0;
}

