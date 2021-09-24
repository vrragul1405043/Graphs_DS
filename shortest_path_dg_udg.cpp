  
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void shortest_path_udg(vector<vector<int>>&adjacency_list, int source, vector<int>&distance){
    queue<int>Q;
    Q.push(source);
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        for(int neighbour : adjacency_list[node]){
            if(distance[neighbour]>1+distance[node]){
                distance[neighbour]=1+distance[node];
                Q.push(neighbour);
            }
        }//end for
    }//end while
}//end func

void shortest_path_dg(vector<vector<pair<int,int>>>&adjacency_list, int source, vector<int>&distance){
    queue<int>Q;
    Q.push(source);
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        for(auto& neighbour : adjacency_list[node]){
            if(distance[neighbour.first]>neighbour.second + distance[node]){
                distance[neighbour.first] = neighbour.second + distance[node];
                Q.push(neighbour.first);
            }
        }
    }
}


int main()
{
    //undirected_graph
    vector<vector<int>> adjacency_list_udg = {
        {1,3},
        {0,2,3},
        {1,6},
        {0,4,1},
        {3,5},
        {4,6},
        {2,5,7,8},
        {6,8},
        {6,7}
    };
    
    vector<vector<pair<int,int>>> adjacency_list_dg = {
        {{1,2}, {4,1}},
        {{2,3}},
        {{3,6}},
        {{}},
        {{2,2}, {5,4}},
        {{3,1}}
    };
    
    
    vector<int>distance_udg(adjacency_list_udg.size(), INT_MAX);
    vector<int>distance_dg(adjacency_list_dg.size(), INT_MAX);
    distance_udg[0]=0;
    distance_dg[0]=0;
    shortest_path_udg(adjacency_list_udg,0,distance_udg);
    shortest_path_dg(adjacency_list_dg,0,distance_dg);
    
    cout<<"Undirected Graph :: "<<endl;
    for(int i=0;i<distance_udg.size();i++) cout<<" 0 -> "<<i<<" of distance "<<distance_udg[i]<<endl; 
    
    cout<<"Directed Graph :: "<<endl;
    for(int i=0;i<distance_dg.size();i++) cout<<" 0 -> "<<i<<" of distance "<<distance_dg[i]<<endl;
    return 0;
}

