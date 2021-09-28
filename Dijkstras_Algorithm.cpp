#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Dijkstras algorithm 


vector<int>dijkstrasAlgorithm(vector<vector<pair<int,int>>>&adjacencyList,int source){
    vector<int>distances(adjacencyList.size(),INT_MAX);
    distances[source] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
    min_heap.push({0,source});
    
    while(!min_heap.empty()){
        auto current = min_heap.top();
        int current_node = current.second;
        int current_distance = current.first;
        min_heap.pop();
        
        for(auto neighbour : adjacencyList[current.second]){
            int neighbour_node = neighbour.first;
            int neighbour_distance = neighbour.second;
            int computed_distance = current_distance + neighbour_distance;
            if(distances[neighbour_node]>computed_distance){
                distances[neighbour_node] = computed_distance;
                min_heap.push({computed_distance,neighbour_node});
            }//end if
        }//end for
    }//end while
    return distances;
}//end function dijkstrasAlgorithm


int main()
{
    //adjacency list
    vector<vector<pair<int,int>>> adjacencyList = {
        {{1,2}, {3,1}},
        {{0,2},{2,4},{4,5}},
        {{1,4},{3,3},{4,1}},
        {{2,3},{0,1}},
        {{1,5}, {2,1}}
    };
    
    vector<int>result = dijkstrasAlgorithm(adjacencyList,0);
    for (int i=0; i<result.size(); i++){
        cout<<"Distance 0->"<<i<<" :"<<result[i]<<endl; 
    }
    return 0;
}

