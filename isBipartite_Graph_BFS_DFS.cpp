  
#include <iostream>
#include<bits/stdc++.h>

using namespace std;


bool isBipartiteBFS(int N, vector<vector<int>>&adjacency_list){
    vector<int>color(N+1,-1);
    queue<int>Q;
    for(int i=1;i<=N;i++){
        if(color[i]==-1){
            Q.push(i);
            color[i] = !color[i];
            while(!Q.empty()){
                int node = Q.front();
                Q.pop();
                for(auto neighbour : adjacency_list[node]){
                    if(color[neighbour]!=-1){
                        if(color[neighbour] == color[node])return false;//not a bipartite graph
                        else continue;
                    }
                    else{
                        Q.push(neighbour);
                        color[neighbour] = !color[node];
                    }//end if visited
                }//end for
            }//end while
        }//end if
    }//end for
    return true;//bipartite graph
}


bool isBipartiteDFS(int N, vector<vector<int>>&adjacency_list){
    vector<int>color(N+1,-1);
    stack<int>S;
    for(int i=1;i<=N;i++){
        if(color[i]==-1){
            S.push({i});
            color[i] = !color[i];
            while(!S.empty()){
                int node = S.top();
                S.pop();
                for(auto neighbour : adjacency_list[node]){
                    if(color[neighbour]!=-1){
                        if(color[neighbour] == color[node])return false;//not a bipartite graph
                        else continue;
                    }
                    else{
                        S.push(neighbour);
                        color[neighbour] = !color[node];
                    }//end if visited
                }//end for
            }//end while
        }//end if
    }//end for
    return true;//bipartite graph
}

int main()
{
    // vector<vector<int>> adjacency_list = {
    //             {},
    //             {2},
    //             {1,3,7},
    //             {2,5},
    //             {6},
    //             {3,7},
    //             {4},
    //             {2,5}
    //         };
    
    vector<vector<int>> adjacency_list = {
        {},
        {2},
        {1,3,8},
        {2,4},
        {5,3},
        {4,6,8},
        {5,7},
        {6},
        {2,5}
    };
    
    // vector<vector<int>> adjacency_list = {
    //     {},
    //     {2,4},
    //     {1,3},
    //     {2,4},
    //     {1,3}
    // };
    
    //here it is undirected graph
    cout<<"Printing the Graph :: "<<endl;
    for(int i=1;i<adjacency_list.size();i++){
        cout<<"The nodes connected to "<<i<<" are"<<"\t";
        for(int j=0;j<adjacency_list[i].size();j++){
            cout<<adjacency_list[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    // if(isCyclePresentBFS(adjacency_list.size()-1,adjacency_list)){
    //     cout<<"Using BFS we have found Cycle is present in the given graph "<<endl;
    // }
    // else cout<<"Cycle is not present "<<endl;
    
    // if(isCyclePresentDFS(adjacency_list.size()-1,adjacency_list)){
    //     cout<<"Using DFS we have found Cycle is present in the given graph "<<endl;
    // }
    // else cout<<"Cycle is not present "<<endl;
    
    if(!isBipartiteBFS(adjacency_list.size()-1,adjacency_list))cout<<"Using BFS -> It is not a bipartite graph"<<endl;
    else cout<<"BFS -> It is a bipartite graph"<<endl;
    
    if(!isBipartiteDFS(adjacency_list.size()-1,adjacency_list))cout<<"USING DFS -> It is not a bipartite graph"<<endl;
    else cout<<"DFS -> It is a bipartite graph"<<endl;
    
    return 0;
}
