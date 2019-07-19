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
#include<iostream> directed graph 

// Adjacency list representation of graph 
class Graph 
{ 
    int V;                          // No. of vertices 
    std::list<int> *adj;        // Pointer to an array containing adjacency lists 

public : 
    Graph(int V); 
    void addEdge (int u, int v ) ;      // function to add an edge to graph 
    int countEdges();                   // function to count # of edge 
    int countVertex();                  // function to count # of vertecies 
    bool isConnected();                 // function to determine if graph is connected
    bool removeEdge();                  // function to remove edge 
    bool removeVertex();                // function to remove edge 
    void BFS(int s);                    // prints a directed graph BFS traversal from point s 
    void DFS(int v);                    // prints a directed graph DFS traversal from point s
    void DFSUtil(int v, bool visited[]);
    void listDisconnected();
}; 


#endif //GRAPH_H