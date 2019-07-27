/***********************************************************
Name: Tomas Vasquez 
Assignment: Final
Purpose: 
Notes:   
***********************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "main.h"

using namespace std;
bool displaySize(int argc, char** argv);
int main(int argc, char *argv[])
{
    srand(time(NULL));          // Time 
    int h=0;                    //ARGV counter
    h = argc-1;                 // maintenance counter control
    

    if (h==0)
    {
        cout<<"cannot enter no arguments"<<endl;

    } else if (h>=1){
        for (int i = 1; i < argc; ++i)
        {
            ifstream infile; 
            infile.open(argv[i]);
            infile.peek();
            cout<<endl;

            if (!infile.is_open()){
                cout<<"nothing is there"<<endl;
            } else if(infile.eof())
            {
                cout<<"file doesnt exist"<<endl;
                
            }  else  ////////// File open and has data //////////////
            {
                string firstline;
                int size = 0;
                bool hasLables = false;
                getline(infile, firstline);
                int i =0;
                if(firstline[i] == 'X')
                {
                    hasLables=true;
                    i++;
                }

                for(; i<firstline.length(); i++)
                {
                    if(isalnum(firstline[i]))
                        size++;
                }

                if(!hasLables)
                    infile.seekg(0, infile.beg);


                Graph g(size, hasLables);

                char ch; // character read from the file
                int number;
                int row = 0, col = 0;
                ch = infile.peek();
                while (!infile.eof())
                {
                    //cout << ch ;
                    if (isdigit(ch))
                    {
                        
                        infile >> number;
                        
                        if(number > 0)
                        {
                            cout << "value: " << ch << '\t';
                            cout << row << ", " << col << endl;
                            g.addEdge(row,col, number);
                        }
                        col++;
                        //cout<< number;
                    }
                    else{
                        ch = infile.get();
                        if(ch == '\n')
                        {
                            row++;
                            col=0;
                        }
                        else if(ch == 'x')
                        {
                            col++;
                        }
                    }
                    
                    ch = infile.peek();
                }
        
                infile.close();
                int numPlace =20;
                int num1 = rand() % numPlace;
                int num2 = rand() % size;
                int DFSnum = rand() % size;
                cout<<endl;
                cout<<"Random values: "<<num1<< " "<<num2<<endl;
                
                cout << endl << endl << endl;
                g.print(hasLables);
                cout<<endl;

                cout << "Testing Adding Vertex NOT from Adjacency list" << endl;
                cout << "==============================================" << endl;                
                cout<<"Adding vertex 9: "<<endl;  
                g.addVertice(9) ? cout << "added" << endl : cout << "failed" << endl;
                cout<<endl;

                cout << "Testing Removing Edge from Adjacency list" << endl;
                cout << "==============================================" << endl;                
                cout<<"Remove Edge (1,3): "<<endl;  
                g.removeEdge(1,3) ? cout << "removed" << endl : cout << "failed" << endl;
                cout<<endl;

                cout << "Testing removing Vertex from Adjacency list" << endl;
                cout << "==============================================" << endl;                
                cout<<"Remove vertex "<<num2<<endl;  
                g.removeVertex(num2) ? cout << "removed" << endl : cout << "failed" << endl;
                cout<<endl;

                cout << "Testing adding SAME edge from Adjacency list" << endl;
                cout << "==============================================" << endl;                
                cout<<"Adding same edge: "<<endl;  
                g.addEdge(2,3) ? cout << "added" << endl : cout << "failed" << endl;
                cout<<endl;

                cout << "Testing adding Vorex OUTSIDE of SIZE of Adjacency list" << endl;
                cout << "==============================================" << endl;                
                cout<<"Adding large edge: "<<endl;  
                g.addVertice(10) ? cout << "added" << endl : cout << "failed" << endl;
                cout<<endl;

                cout << "Testing Adding RANDOM Vertex to Adjacency list" << endl;
                cout << "==============================================" << endl;                
                cout<<"Adding "<<num1<< " vertex: "<<endl; 
                g.addVertice(num1) ? cout << "added" << endl : cout << "failed" << endl;
                cout<<"Adding "<<num2<< " vertex: "<<endl; 
                g.addVertice(num2) ? cout << "added" << endl : cout << "failed" << endl;
                cout<<endl;

                cout << "Testing Adding RANDOM Edge to Adjacency list" << endl;
                cout << "==============================================" << endl;                
                cout<<"Adding ("<<num1<<","<<num2<<") edge: "<<endl; 
                g.addEdge(num1,num2) ? cout << "added" << endl : cout << "failed" << endl;

                cout<<"Adding ("<<num1<<","<<num2<<") edge: "<<endl; 
                g.addEdge(num1,num2) ? cout << "added" << endl : cout << "failed" << endl;
                cout<<endl;

                cout << "DFS & BFS w/ same vertex" << endl;
                cout << "==============================================" << endl;                
                cout<<"Breath first Search results: "<<endl;
                g.BFS(5);
                cout<<endl;
                cout<<"Depth first Search results:"<<endl;
                g.DFS(5);
                cout<<endl<<endl;

                cout << "DFS & BFS w/ Random vertex" << endl;
                cout << "==============================================" << endl;                
                cout<<"Breath first Search results from "<<DFSnum<<": "<<endl;
                g.BFS(DFSnum);
                cout<<endl;
                DFSnum = rand() % size;
                cout<<"Depth first Search results from "<<DFSnum<<": "<<endl;
                g.DFS(DFSnum);
                cout<<endl;

                cout<<endl<< endl << endl << endl;
                cout << "Adjacency list edge/vortex Info" << endl;
                cout << "==============================================" << endl;
                cout<<"Edge count: "<<endl;
                g.numEdges();cout<<endl;
                g.addVertice(9);
                cout<<"Vertex count: "<<endl;
                g.numVertex();
                cout<<endl;
                cout<<"Is the graph Connected: "<<endl;
                g.isConnected() ? cout << "Yes" << endl : cout << "No" << endl;
                cout<<endl;
                cout<<"List the disconnected:"<<endl;
                g.listDisconnected();

                
        
            } ///// end file read /////
            
        }
                
    } else {
        cout<<"file DNE (Does not exist)"<<endl;
    }

    return 0;
}
