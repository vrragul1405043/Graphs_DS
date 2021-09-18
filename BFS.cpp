#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void display_result(vector<int>&result){
    for(int& node : result)cout<<node<<"\t";
}

vector<int> compute_bfs(int N, vector<vector<int>>&adjacency_list){
    vector<bool>visited(N+1,false);
    vector<int>bfs;
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            queue<int>Q;
            Q.push(i);
            visited[i] = true;
            while(!Q.empty()){
                int node = Q.front();
                Q.pop();
                bfs.push_back(node);
                for(auto neighbour : adjacency_list[node]){
                    if(!visited[neighbour]){
                        Q.push(neighbour);
                        visited[neighbour] = true;
                    }//end if visited
                }//end for
            }//end while
        }//end if
    }//end for
    return bfs;
}

int main()
{
    int N,M;
    cin>>N>>M;
    vector<vector<int>>adjacency_list(N+1);// N number of nodes and M number of edges
    vector<int>bfs;
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
    
    //getting the pair of M edges
    for(int i=0;i<M;i++){
        int u,v;
        cout<<"Enter u and v "<<endl;
        cin>>u>>v;
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }
    
    //here it is undirected graph
    cout<<"Printing the Graph :: "<<endl;
    for(int i=1;i<adjacency_list.size();i++){
        cout<<"The nodes connected to "<<i<<" are"<<"\t";
        for(int j=0;j<adjacency_list[i].size();j++){
            cout<<adjacency_list[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    bfs = compute_bfs(adjacency_list.size()-1,adjacency_list);
    cout<<"The BFS traversal result is ::"<<endl;
    display_result(bfs);
    return 0;
}

