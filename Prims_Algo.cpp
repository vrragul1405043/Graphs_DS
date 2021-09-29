//Prim's Algorithm

#include <iostream>
#include<bits/stdc++.h>

using namespace std;


void prims_algorithm(vector<vector<pair<int,int>>>&adjacency_list, vector<int>&distance, 
vector<int>&parent, vector<bool>&isPartOfMst){
    distance[0] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>min_heap;
    min_heap.push({0,0});
    for(int count = 0; count<adjacency_list.size()-1; count++){
        int node = min_heap.top().second;
        min_heap.pop();
        isPartOfMst[node]=true;
        for(auto neighbour_pair : adjacency_list[node]){
            int neighbour_node = neighbour_pair.first;
            int weight = neighbour_pair.second;
            if(isPartOfMst[neighbour_node] == false && weight < distance[neighbour_node]){
                distance[neighbour_node] = weight;
                parent[neighbour_node] = node;
                min_heap.push({distance[neighbour_node], neighbour_node});
            }
        }
    }
}//end function



int main()
{
    vector<vector<pair<int,int>>>adjacency_list = {
        {{1,2},{3,1},{4,4}},
        {{2,3},{0,2},{5,7},{3,3}},
        {{1,3},{3,5},{5,8}},
        {{0,1},{1,3},{2,5},{4,9}},
        {{0,4},{3,9}},
        {{1,7},{2,8}}
    };
    
    vector<int>distance(adjacency_list.size(),INT_MAX);
    vector<int>parent(adjacency_list.size(),-1);
    vector<bool>isPartOfMst(adjacency_list.size(),false);
    
    prims_algorithm(adjacency_list, distance, parent, isPartOfMst);
    for(int i=1;i<parent.size();i++)cout<<parent[i] <<" - "<<i<<endl;

    return 0;
}

