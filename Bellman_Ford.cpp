//Bellman Ford Algorithm

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void printGraph(vector<pair<pair<int,int>,int>>&edges){
    for(int i=0;i<edges.size();i++){
        auto node = edges[i];
        cout<<"Edge :: "<<node.first.first<<"->"<<node.first.second<<" Weight :: "<<node.second<<endl;
    }
}

void bellmanFord(vector<int>&distance,vector<pair<pair<int,int>,int>>&edges){
    for(auto& edge : edges){
        auto node = edge.first;
        int parent = node.first;
        int child = node.second;
        int weight = edge.second;
        if(distance[parent]!=INT_MAX && distance[parent] + weight < distance[child]){
            distance[child] = distance[parent] + weight;
        }
    }
}

bool isCycle(vector<int>&distances,vector<pair<pair<int,int>,int>>&edges){
    vector<int>temp(distances);
    bellmanFord(temp,edges);
    for(int i=0;i<temp.size();i++){
        if(distances[i] != temp[i])return true;
    }
    return false;
}


int main()
{
    vector<pair<pair<int,int>,int>>edgeList = {
        {{3,2}, 6},
        {{5,3}, 1},
        {{0,1}, 5},
        {{1,5}, -3},
        {{1,2}, -2},
        {{3,4}, -2},
        {{2,4}, 3}
    };
    int N = 6;
    vector<int>distances(N,INT_MAX);
    distances[0] = 0;
    printGraph(edgeList);
    for(int i=0;i<N-1;i++)
        bellmanFord(distances,edgeList);
    
    for(auto distance : distances)cout<<distance<<"\t";
    
    cout<<endl;
    if(isCycle(distances, edgeList))cout<<"Cycle exists"<<endl;
    else cout<<"Cycle does not exist"<<endl;
    return 0;
}

