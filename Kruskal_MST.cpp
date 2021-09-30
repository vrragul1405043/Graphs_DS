//Kruskal algorithm minimum cost spanning tree


// Enter number of nodes and edges:
// 6 9
// Enter Edges and Weight:
// 1 4 1 
// Enter Edges and Weight:
// 1 5 4
// Enter Edges and Weight:
// 5 4 9
// Enter Edges and Weight:
// 4 3 5 
// Enter Edges and Weight:
// 4 2 3 
// Enter Edges and Weight:
// 1 2 2 
// Enter Edges and Weight:
// 2 6 7 
// Enter Edges and Weight:
// 2 3 3
// Enter Edges and Weight:
// 3 6 8

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node{
    int u;
    int v;
    int weight;
    node(int first,int second,int wt){
        u = first;
        v = second;
        weight = wt;
    }
};

int findParent(int node, vector<int>&parent){
    if(parent[node] == node)return node;
    parent[node] = findParent(parent[node], parent);
    return parent[node];
}

void unionn(int u, int v, vector<int>&parent, vector<int>&rank){
    if(rank[u]>rank[v])parent[v] = u;
    else if(rank[v]>rank[u])parent[u] = v;
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    int M,N,cost = 0;
    cout<<"Enter the number of edges "<<endl;
    cin>>M;
    cout<<"Enter the number of nodes "<<endl;
    cin>>N;
    
    vector<node>edges;
    vector<pair<int,int>>kruskal;
    vector<int>parent(N+1);
    vector<int>rank(N+1);
    
    for(int i=0;i<M;i++){
        cout<<"Enter the nodes and edges :: "<<endl;
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }
    
    for(int i=0;i<N;i++){
        parent[i]=i;
    }
    
    auto comparator = [](node&a, node&b){
        return a.weight<=b.weight;
    };
    
    sort(edges.begin(), edges.end(), comparator);
    
    for(int i=0;i<M;i++){
        if(findParent(edges[i].u,parent)!=findParent(edges[i].v,parent)){
            cost+=edges[i].weight;
            kruskal.push_back({edges[i].u, edges[i].v});
            unionn(edges[i].u, edges[i].v,parent,rank);
        }
    }
    
    for(auto it : kruskal){
        cout<<it.first<<"\t"<<it.second<<endl;
    }
    
    cout<<"The total cost of the spanning tree is :: "<<cost<<endl;
    return 0;
}

