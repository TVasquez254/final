#include "graph.h"


//Constructor
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 

// add edge to graph 
void Graph :: addEdge ( int u, int v ) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 