#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    vector<vector<int>>adjacency_list(N+1); // N number of nodes and M number of edges
    
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
    return 0;
}

