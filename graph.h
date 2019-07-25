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
#include "data.h"
class Graph 
{ 
private:
    int size;    // No. of vertices 
    bool directionalUnweighted;
    bool weighted;
    
    std::list<Node> *adj;           // Pointer to an array containing adjacency lists 
    bool *vertices;
    int findWeight(int row, int col);
    int numEdgeCount = 0;       //edge count 
    int numVertexCount =0;      //vertex  count

public: 
    Graph(int size);                   // Constructor 
    ~Graph ();      //Destructor
    bool addEdge(int v, int w, int weight=0);     // Add w to v’s list
    bool addVertice(int);
    void BFS(int s);                // prints BFS traversal from a given source s
    void DFSUtil(int v, bool visited[]);
    void DFS(int v);                // DFS traversal of the vertices reachable from v   
    void print(bool hasLables);
    bool removeEdge(int, int, bool);
    bool removeVertex(int);
    int numVertex();
    int numEdges();
    int listDisconnected();
    bool isConnected();
    
}; 


#endif