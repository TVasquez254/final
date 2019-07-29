/***********************************************************
Name: Tomas Vasquez 
Assignment: 
Purpose: 
Notes:   
***********************************************************/

#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include "data.h"

using namespace std;
class Graph 
{ 
private:
    int size;                              // No. of vertices 
    bool directionalUnweighted; 
    bool weighted;
     
    std::list<Node> *adj;                       // Pointer to an array containing adjacency lists
    bool *vertices;
    int findWeight(int row, int col);
    int numEdgeCount;                         //edge count
    int numVertexCount;                      // vertex count

public: 
    Graph(int, bool);                           // Constructor 
    ~Graph();                                   // Destructor 
    bool addEdge(int v, int w, int weight=0);   // Add w to v’s list. Unweighted defaults to zero
    bool addVertice(int);   
    void BFS(int s);                            // BFS traversal from a given source s
    void DFSUtil(int v, bool visited[]);
    void DFS(int v);                            // DFS traversal of vertices reachable from v   
    void print(bool hasLables);
    bool removeEdge(int, int); 
    bool removeVertex(int);
    int numVertex();      
    int numEdges();
    void listDisconnected();  
    bool isConnected();     


    
}; 


#endif