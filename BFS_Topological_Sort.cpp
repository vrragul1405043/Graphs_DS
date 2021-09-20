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

void topological_sort_DFS(int N, vector<vector<int>>&adjacency_list){
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

void topological_sort_BFS(int N, vector<vector<int>>&adjacency_list, vector<int>&result){
    vector<int>inDegree(N,0);
    queue<int>Q;
    for(int i=0;i<N;i++){
        for(int neighbour : adjacency_list[i])inDegree[neighbour]++;
    }
    
    for(int i=0;i<inDegree.size();i++){
        if(inDegree[i]==0)Q.push(i);
    }
    
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        result.push_back(node);
        for(int& neighbour : adjacency_list[node]){
            inDegree[neighbour]--;
            if(inDegree[neighbour]==0)Q.push(neighbour);
        }//end for
    }//end while
}//end function



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
    
    topological_sort_DFS(adjacency_list.size(),adjacency_list);
    topological_sort_BFS(adjacency_list.size(),adjacency_list,result);
    cout<<endl;
    for(int& num : result)cout<<num<<"\t";
    return 0;
}

