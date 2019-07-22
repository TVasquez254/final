#include "graph.h"
#include <iostream>
#include <list>
using namespace std;


Graph::Graph(int size, bool directionalUnweighted) 
{ 
    this->V = V;
    this->size =size;
    adj = new list<Node>[size]; 
    weighted = false;
    vertices = new bool [size]={false};
} 

void Graph::addEdge(int v, int w, int weight) 
{ 
    if ((v<0 )||() w<0 )|| (v>=size) || (w>= size)     //validation   
    {
        return false;
    }
    if (int i = 0; i<adj[v].size();i++) //validation check for duplicate
    {
        if (adj[v[i].name ==w]
        {
            return false;
        }
    }
    vertices[v]=true;
    vertices[w]=true;
    Node tp(w,weight);
    adj[v].push_back(tp);
    if(weight > 1)
    {
        weighted = true;
    } 
} 
bool Graph::addVertice(int v)
{
    if (v>0||v>=size)
    {
        return false;
    }
    vertices[v]=true; // fixed errors
    
}

int Graph::numVertex(int v)
{
    int count =0;
    for (int i = 0; i<size; i++)
    {
        if (vertices[v])
        {
            count++;
        }
    }
    return count;
    
}


int Graph::numEges()
{

}



// prints BFS traversal from a given source s
void Graph::BFS(int s) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Create a queue for BFS 
    list<int> queue; 
  
    // Mark the current node as visited and enqueue it 
    visited[s] = true; 
    queue.push_back(s); 
  
    // 'i' will be used to get all adjacent 
    // vertices of a vertex 
    //list<Node>::iterator i; 
  
    while(!queue.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
  
        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        //for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        for(const Node & i : adj[s])
        { 
            if (!visited[(i).name]) 
            { 
                visited[(i).name] = true; 
                queue.push_back((i).name); 
            } 
        } 
    } 
}


void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices adjacent 
    // to this vertex 
    // list<int>::iterator i; 
    // for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    for(const Node & i : adj[v])
        if (!visited[i.name]) 
            DFSUtil(i.name, visited); 
} 
  
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graph::DFS(int v) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
    // to print DFS traversal 
    DFSUtil(v, visited); 
} 

int Graph::findWeight(int row, int col)
{
    for(Node & n : adj[row])
        if(n.name == col)
            return n.weight;
    return -1;
}

void Graph::print(bool hasLables)
{
    char label = 'a';
    if(hasLables)
    {
        cout << "X";
        //char label = 'a';
        for(int i=0; i<V;i++)
        {
            cout << ',' << (char)(label + i);
        }
        cout << endl;
    }
    for(int row=0; row<V;row++)
    {
        if(hasLables)
            cout << (char)(label + row) << ',';
        //cout << 0;
        for(int col=0; col<V;col++)
        {
            if(col > 0)
                cout << ',';
            int weight = findWeight(row,col);
            if(weight > 0)
                cout << weight;
            else
            {
                if(row == col)
                    cout << 0;
                else if (weighted)
                    cout << 'x';
                else
                    cout << 0;
            }
        }
        cout << endl;
    }
}