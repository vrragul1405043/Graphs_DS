  
#include <iostream>
#include<bits/stdc++.h>

using namespace std;


bool isCyclePresentBFS(int N, vector<vector<int>>&adjacency_list){
    vector<bool>visited(N+1,false);
    queue<pair<int,int>>Q;
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            Q.push({i,-1});
            visited[i] = true;
            while(!Q.empty()){
                pair<int,int>node = Q.front();
                Q.pop();
                for(auto neighbour : adjacency_list[node.first]){
                    if(visited[neighbour] && node.second!=neighbour)return true;//cycle is present
                    else if(!visited[neighbour]){
                        Q.push({neighbour,node.first});
                        visited[neighbour] = true;
                    }//end if visited
                }//end for
            }//end while
        }//end if
    }//end for
    return false;//cycle does not exist
}


bool isCyclePresentDFS(int N, vector<vector<int>>&adjacency_list){
    vector<bool>visited(N+1,false);
    stack<pair<int,int>>S;
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            S.push({i,-1});
            visited[i] = true;
            while(!S.empty()){
                pair<int,int>node = S.top();
                S.pop();
                for(auto child: adjacency_list[node.first]){
                    if(visited[child] && node.second!=child)return true;//there is a cycle
                    else if(!visited[child]){
                        visited[child] = true;
                        S.push({child,node.first});
                    }//end if 
                }//end for
            }//end while
        }//end if
    }//end for
    return false;
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
        {3},
        {5},
        {1,4},
        {3},
        {2,6,8},
        {5,7},
        {6,8},
        {7,5}
    };
    
    //here it is undirected graph
    cout<<"Printing the Graph :: "<<endl;
    for(int i=1;i<adjacency_list.size();i++){
        cout<<"The nodes connected to "<<i<<" are"<<"\t";
        for(int j=0;j<adjacency_list[i].size();j++){
            cout<<adjacency_list[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    if(isCyclePresentBFS(adjacency_list.size()-1,adjacency_list)){
        cout<<"Using BFS we have found Cycle is present in the given graph "<<endl;
    }
    else cout<<"Cycle is not present "<<endl;
    
    if(isCyclePresentDFS(adjacency_list.size()-1,adjacency_list)){
        cout<<"Using DFS we have found Cycle is present in the given graph "<<endl;
    }
    else cout<<"Cycle is not present "<<endl;
    
    return 0;
}
