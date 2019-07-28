/***********************************************************
Name: Tomas Vasquez 
Assignment: Final
Purpose: 
Notes:   
***********************************************************/

#include "main.h"

using namespace std;
bool displaySize(int argc, char** argv);
int main(int argc, char *argv[])
{
    srand(time(NULL));          // Time 
    int h=0;                    //ARGV counter
    h = argc-1;                 // maintenance counter control
    bool loca2=false;                   //determine if graph is weighted
    

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
                cout<<"files doesnt exist"<<endl;
            } else if(infile.eof())
            {
                cout<<"nothing there"<<endl;
                
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
                        if (number>1)
                        {
                            loca2=true;
                        }
                        
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
                /*
                *  Generating test data numbers to conduct tests
                */

                int size2 =20;                      //Testing past failure
                int num1 = rand() % size;           
                int num2 = rand() % size;
                int num3 = rand() % size2;
                int edgeWeight = rand() % size2;
                int DFSnum = rand() % size;
                cout<<endl;
                            //*************************************************************
                            //   Main Data Test-Checking for error & failure              *
                            //*************************************************************  

                cout << endl << endl;
                g.print(hasLables);
                cout<<endl;

                cout << "Testing Adding Edge NOT from Adjacency list" << endl;
                cout << "==============================================" << endl;                
                cout<<"Adding edge (0,5): "<<endl;  
                g.addEdge(0,5) ? cout << "added" << endl : cout << "failed" << endl;
                cout<<endl; 

                cout << "Testing Adding Vertex NOT from Adjacency list" << endl;
                cout << "==============================================" << endl;                
                cout<<"Adding vertex 10: "<<endl;
                g.addVertice(10) ? cout << "added" << endl : cout << "failed" << endl;
                cout<<endl; 

                cout << "Testing Adding Duplicate Edge from Adjacency list" << endl;
                cout << "==============================================" << endl;                
                cout<<"Adding edge (0,1): "<<endl;
                g.addEdge(0,1) ? cout << "added" << endl : cout << "failed--It already exists" << endl;
                cout<<endl; 

                cout << "Testing Removing RANDOM Edge from Adjacency list (part1)" << endl;
                cout << "==============================================" << endl;                
                cout<<"Removing ("<<num1<<","<<num2<<") edge: "<<endl; 
                g.removeEdge(num1,num2) ? cout << "removed" << endl : cout << "failed" << endl;
                cout<<endl;


                if (g.removeEdge(num1,num2))
                {
                    cout<<"Is the graph Connected: "<<endl;
                    g.isConnected() ? cout << "Yes" << endl : cout << "No" << endl;
                    cout<<endl;
                }

                /*
                *  Resetting a new number 
                */

                




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
