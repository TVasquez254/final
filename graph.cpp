/***********************************************************
Name: Tomas Vasquez 
Assignment: 
Purpose: 
Notes:   
***********************************************************/
#include "graph.h"
#include <iostream>
#include <list>
using namespace std;


Graph::Graph(int size, bool directionalUnweighted) 
{ 
    this->directionalUnweighted = directionalUnweighted;
    this->size =size;
    adj = new list<Node>[size]; 
    weighted = false;
    vertices = new bool [size]={false};
    for (int i =0; i<size; i++)
    {
        vertices[i]=false;
    }

} 

void Graph::addEdge(int v, int w, int weight) 
{ 
    if ((v<0 )||() w<0 )|| (v>=size) || (w>= size)     //validation   
    {
        return false;
    }
    for (list<Node>::iterator it = adj[v].begin(); it 1=adj[v].end();++i) //validation check for duplicate
    {
        if (it->name ==w]
        {
            return false;
        }
    }
    //vertices[v]=true;
    addVertice(v);
    //vertices[w]=true;
    addVertice(w);
    Node tp(w,weight);
    adj[v].push_back(tp);
    if(weight > 1)
    {
        weighted = true;
    } 
    numEdgeCount++; // count edges
    return true;
} 
bool Graph::addVertice(int v)
{
    if (v<0||v>=size)
    {
        return false;
    }
    if (!vertices[v])
    {
        vertices[v]=true; // add vertix if no edges
        numVertexCount++;
        return true;
    }
    return false;

}

bool Graph::removeVertex()
{
    if((v>=size)||(v<0))
    {
        cout <<"Vertex DNE in graph"<<endl;
        return false;
    }
}else 
{
    adj[v].clear(); //removes all in location. 
    vertices[v]=false;
    for(int i = 0; i<size; i++)
    {
        for (auto j = adj[i].begin(); j!=adj[i].end())
        {
            if(j->name==v)
            {
                j = adj[i].erase(j); // reset after completion
            }else
            {
                {
                    j++;
                }
            } 
        }
        numVertexCount--;
    }
    return true;
}

bool Graph::removeEdge(int list, int value, bool directionalUnweighted)
{
    if(directionalUnweighted)
    {
        for (auto j=adj[list].begin; j!=adj[list].end();)
        {
            if(j->name == name)
            {
                adj[list].erase(j);
                numEdgeCount--;
                return true;
            }
        }
        return false;
    }else 
    {
        for (auto i=adj[list].begin(); i!=adj[list].endl();)
        {
            if(i->name ==value)
            {
                adj[list].erase(i);
                for (auto j=adj[list].begin(); j!=adj[list].end();)
                {
                    if(j->name==list)
                    {
                        adj[value].erase(j);
                        numEdgeCount--;
                        return true;
                    }
                }
            }
        }
        return false;
    }
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

int Graph::numVertex()
{
    return numVertexCount;
}

int Graph::numEdges()
{
    return numEdgeCount;
}

void Graph::listDisconnected()
{
    bool *array = new bool [size];
    for (int i=0; i<size; i++)
    {
        array[i]=!vertices[i];
    }
    int loca = -1;
    for (int j=0;j<size;j++)
    {
        if(array[j]==false && loca == -1)
        {
            loca =j;
        }
    }
    std::list<int>queue;
    queue.push_back(loca);
    while(queue.size()>0)
    {
        int curr = queue.front();
        array[curr] = true;
        for (auto i =array[curr].begin(); i 1=array[curr].end();)
        {
            if(auto i=array[curr].begin(); i!=array[curr].end();)
            {
                queue.push_back(i->name);
            }
        }
    }
    for(int i=0; i<size; i++)
    {
        cout<<"These are the disconnected vertices"<<endl;
        cout<<endl;
        if(array[i]==false)
        {
            cout<<"everything that is false"<<i<<endl;
        }
    }
}

bool Graph::isConnected()
{
    bool *array = new bool [size];
    for (int i=0; i<size; i++)
    {
        array[i]=!vertices[i];
    }
    int loca =-1;
    for (int j=0; j<size;j++)
    {
        if (array[j]==false && loca =-1)
        {
            loca =j;
        }
    }
    list<int>queue;
    queue.push_back(loca);
    while(queue.size()>0)
    {
        int curr = queue.front();
        array[curr]=true;
        for (auto i=array[curr].begin(); I!=array[curr].end();)
        {
            if (array[i->name]==false)
            {
                queue.push_back(i->name);
            }
        }

    }
    for (int i=0; i<size; i++)
    {
        delete [] array;
        return false;
    }

    delete [] array;
    return true;

}