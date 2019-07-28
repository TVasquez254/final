/***********************************************************
Name: Tomas Vasquez 
Assignment: 
Purpose: 
Notes:   
***********************************************************/
#include "graph.h"

//Constructor
Graph::Graph(int size, bool directionalUnweighted) 
{ 
    this->directionalUnweighted = directionalUnweighted;
    this-> size= size; 
    adj = new list<Node>[size]; 
    weighted = false;
    vertices = new bool [size];
    for(int i=0;i<size; i++)
    {
        vertices[i] = false;
    } 
}

//Destructor
Graph::~Graph()
{
    delete [] vertices;     //release memory 

    for (int i=0; i<size; i++)
    {
        adj[i].clear(); // deletes each node in the adj Node array.
    }
    delete [] adj;
}

//Function to add edge
bool Graph::addEdge(int v, int w, int weight) 
{ 
    if ((v<0 )|| (w<0 )|| (v>=size) || (w>= size))     //validation   
    {
        return false;
    }
    for (list<Node>::iterator it = adj[v].begin(); it != adj[v].end(); ++it){
        if (it->name==w)
        {
            return false; 
        }
    }

    addVertice(v);
    
    addVertice(w);
    Node tp(w,weight);
    adj[v].push_back(tp);
    if(weight > 1)
    {
        weighted = true;
    }
    numEdgeCount++;

    return true;
} 


//Function to add vertex
bool Graph::addVertice(int v)
{
    if (v<0)
    {
        return false;
    }
    if(!vertices[v])
    {
        vertices[v]=true; //add vertix if no edges
        numVertexCount++;
        return true;
    }
    return false;
}

//Function to remove vertex
bool Graph::removeVertex(int v)
{
    if(v<0)      //within bounds
    {
        cout<<"value does not exist"<<endl;
    }

    if(!vertices[v])     //checks for value in vertices array
    {
        cout<<"value doesnt exist"<<endl;
        return false;
        
    }
    
    if ((v >=size)||(v<0))
    {
        cout<<"Vertex does not exist in graph"<<endl;
        return false;
    }else 
    {
        adj[v].clear(); // removes all in location. Vertex has no edges. 
        vertices[v]=false; // vertex is not there 
        for (int i = 0; i<size; i++)
        {
            for (auto j =adj[i].begin(); j!=adj[i].end();)
            {
                if(j->name==v)
                {
                    j = adj[i].erase(j); // j is going to reset after completion
                }else 
                {
                    j++; 
                }
            }
        }
        numVertexCount--;
    }
    return true;
}

//Function to remove edge
bool Graph::removeEdge(int list, int value)  //use value from constructor
{
    if (directionalUnweighted)
    {
        
        for (auto j =adj[list].begin(); j!=adj[list].end();j++)
        {
            
            if(j->name == value) // looking in list to find value
            {
                
                adj[list].erase(j);
                numEdgeCount--;
                return true;
            }
        }
        return false;
    }else 
    {
        
        for (auto i =adj[list].begin(); i!=adj[list].end();i++)
        {
            
            if (i->name ==value)
            {
                adj[list].erase(i);
                for (auto j =adj[value].begin(); j!=adj[value].end();j++) //looping looking at back
                {
                    
                    if (j->name==list)   // looking in list to find value
                    {
                        adj[value].erase(j);
                        numEdgeCount--;
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }

}


// prints BFS traversal from a given source s
void Graph::BFS(int s) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[size]; 
    for(int i = 0; i < size; i++) 
        visited[i] = false; 
  
    // Create a queue for BFS 
    list<int> queue; 
  
    // Mark the current node as visited and enqueue it 
    visited[s] = true; 
    queue.push_back(s); 
  
    // 'i' will be used to get all adjacent vertices of a vertex 
    while(!queue.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
  
        // Get all adjacent vertices of the dequeued vertex s. If a adjacent has not been visited,  
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

//Utility used by DFS to determine if it was visited
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices adjacent to this vertex 
    // list<int>::iterator i; 
    // for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    for(const Node & i : adj[v])
        if (!visited[i.name]) 
            DFSUtil(i.name, visited); 
} 
  
// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil() 
void Graph::DFS(int v) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[size]; 
    for (int i = 0; i < size; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function to print DFS traversal 
    DFSUtil(v, visited); 
} 

//find the weight of edges
int Graph::findWeight(int row, int col)
{
    for(Node & n : adj[row])
        if(n.name == col)
            return n.weight;
    return -1;
}

//Print the adjaceny list
void Graph::print(bool hasLables)
{
    ofstream fout;
    fout.open("example.txt");
    char label = 'a';
    if(hasLables)
    {
        fout << "X";
        //char label = 'a';
        for(int i=0; i<size;i++)
        {
            fout << ',' << (char)(label + i);
        }
        fout << endl;
    }
    for(int row=0; row<size;row++)
    {
        if(hasLables)
            fout << (char)(label + row) << ',';
        //cout << 0;
        for(int col=0; col<size;col++)
        {
            if(col > 0)
                fout << ',';
            int weight = findWeight(row,col);
            if(weight > 0)
                fout << weight;
            else
            {
                if(row == col)
                    fout << 0;
                else if (weighted)
                    fout << 'x';
                else
                    fout << 0;
            }
        }
        fout << endl;
    }
    fout.close();
}

//Returns vertex count
int Graph::numVertex()
{
    return numVertexCount;
}

//Returns edge count
int Graph::numEdges()
{
    return numEdgeCount;
}

//Prints out the values if the graph is disconnected
void Graph::listDisconnected()
{
    bool *array = new bool [size];
    for (int i=0; i<size; i++)
    {
        array[i]=!vertices[i];   //if exists then dont check
    }
    int loca =-1;
    for (int j=0;j<size;j++)
    {
        if(array[j]==false && loca ==-1)     // there is no vertex there.
        {
            loca =j; //location of first false. once set not changing
        }
    }
    list<int>queue; //
    queue.push_back(loca);
    array[loca]= true;  //pushing first and makring it. visted that vertice and connected
    while (queue.size()>0)
    {
        int curr = queue.front();           //removed from stack
        queue.pop_front();      // actually removing. It never gets to zero in size
        
        for (auto i =adj[curr].begin(); i!=adj[curr].end();i++)  //looping for that vertice
        {
            if (array[i->name]==false) //if true we dont want to visit and infinite loop. 
            {
                array[i->name]=true;
                queue.push_back(i->name);    //this location is false and not visited. We are checking 
            }
        }//pushed any not checked. One at a time true if anything false its disconnected

    }
    cout<<"These are the disconnected vertices"<<endl;
    cout<<endl;
    for (int i=0; i<size; i++)
    {
        
        if (array[i]==false) //could use ! to sub for the false
        {
            cout<<"Nodes "<<i<<endl;
        }
    }
}

//Function that checks if all the nodes are connected
bool Graph::isConnected()
{
    //cout << "first" << endl;
    bool *array = new bool [size];
    //cout << "*array declared" << endl;
    for (int i =0; i<size; i++)
    {
        // cout << "vertices[" <<i<<"] is "<< vertices[i] << endl;
        array[i]=!vertices[i];   //if exists then dont check
    }
    int loca =-1;
    // cout << "first loop done" << endl;
    for (int j=0;j<size;j++)
    {
        if(array[j]==false && loca ==-1)
        {
            loca =j; //location of first false
        }
    }
    // cout << "second loop done" << endl;
    list<int>queue; //
    queue.push_back(loca);
    array[loca]= true;  //pushing first and makring it. visited that vertice and connected
    while (queue.size()>0)
    {
        int curr = queue.front();           //removed from stack
        queue.pop_front();      // actually removing. It never gets to zero in size
        
        for (auto i =adj[curr].begin(); i!=adj[curr].end();i++)  //looping for that vertice
        {
            if (array[i->name]==false) //if true we dont want to visit and infinite loop. 
            {
                array[i->name]=true;
                queue.push_back(i->name);    //this location is false and not visited. We are checking 
            }
        }//pushed any not checked. One at a time true if anything false its disconnected

    }
    // cout << "third loop done" << endl;
    for (int i=0; i<size; i++)
    {
        if (array[i]==false) //could use ! to sub for the false
        {
            delete[] array;     // free the allocated to prevent memory leak
            return false;
        }
    }
    // cout << "forth loop done" << endl;
    delete[] array;     // free the allocated to prevent memory leak
    return true;

}