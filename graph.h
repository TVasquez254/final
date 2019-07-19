/***********************************************************
Name: Tomas Vasquez 
Assignment: Final
Purpose: 
Notes:   
***********************************************************/

#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <vector>
#include<iostream> 

// Adjacency list representation of graph 
class Graph 
{ 
    int V;                          // No. of vertices 
    std::list<int> *adj;        // Pointer to an array containing adjacency lists 

public : 
    Graph(int V); 
    void addEdge ( int u, int v ) ;     // function to add an edge to graph 
    int countEdges();           // function to count # of edge 
    int countVertex();          // function to count # of vertecies 
    bool isConnected();         // function to determine if graph is connected
    bool removeEdge();          // function to remove edge 
    bool removeVertex();          // function to remove edge 
    void BFS(int s);    // prints BFS traversal from a given source s 
    void DFS(int v);
    void DFSUtil(int v, bool visited[]);
}; 


#endif //GRAPH_H