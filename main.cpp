/***********************************************************
Name: Tomas Vasquez 
Assignment: Final
Purpose: 
Notes:   
***********************************************************/

#include "main.h"
int main(int argc, char *argv[])
{
    srand(time(NULL));                  // Time 
    int h=0;                            //ARGV counter
    h = argc-1;                         // maintenance counter control
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
                cout<<"file doesnt exist"<<endl;
            } else if(infile.eof())
            {
                cout<<"nothing is there"<<endl;
                
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


                    // Reconfiguring size to account for diff test cases!
                    //size = size+2;


                Graph g(size, hasLables);

                /*
                *  Displaying list 
                */
                cout << "Testing Dispaying Adjacency list" << endl;
                cout << "==============================================" << endl;
                char ch;                        // character read from the file
                int number;                     //number reader
                int row = 0, col = 0;           //column counter
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
                g.print(hasLables);             //Printing table for visual reference 
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

                num2 = rand() % size; 

                cout << "Testing Removing RANDOM Vertex from Adjacency list" << endl;
                cout << "==============================================" << endl;
                cout<<"Remove vertex "<<num2<<": "<<endl;
                g.removeVertex(num2) ? cout << "removed" << endl : cout << "failed" << endl;
                cout<<endl;

                if(g.removeVertex(num2))
                {
                    cout<<"Is the graph Connected: "<<endl;
                    g.isConnected() ? cout << "Yes" << endl : cout << "No" << endl;
                    cout<<endl;
                }

                cout << "Testing removing Vortex OUTSIDE of SIZE of Adjacency list" << endl;
                cout << "==============================================" << endl;                
                cout<<"Removing out of scope edge: "<<endl;  
                g.removeVertex(11) ? cout << "removed" << endl : cout << "failed" << endl;
                cout<<endl;

                cout << "Testing Adding 3 Vertex to Adjacency list" << endl;
                cout << "==============================================" << endl; 
                num1 = rand() % size;       //resetting to generate diff test case 
                num2 = rand() % size;       //resetting to generate diff test case
                int num4 =3;
                int num5 = rand()%size2;

                for (int i=0; i<num4; i++)
                {
                    num5 = rand() % size2;
                    cout<<"Adding "<<num5<< " vertex: "<<endl; 
                    g.addVertice(num5) ? cout << "added" << endl : cout << "failed" << endl;
                    cout<<endl;
                }

                cout << "Testing Removing RANDOM number of edges to Adjacency list" << endl;
                cout << "==============================================" << endl; 
                 for (int i=0; i<num4; i++)
                {
                    num1 = rand() % size;
                    num2 = rand() % size;
                    cout<<"Removing ("<<num1<<","<<num2<<") edge: "<<endl; 
                    g.removeEdge(num1,num2) ? cout << "removed" << endl : cout << "failed" << endl;
                    cout<<endl;
                }

                cout << "Testing Adding RANDOM Edge to Adjacency list" << endl;
                cout << "==============================================" << endl;   
                num1 = rand() % size;       //resetting to generate diff test case 
                num2 = rand() % size;       //resetting to generate diff test case
                num3 = rand() % size2;

                if(loca2)
                {
                    cout<<"Testing adding RANDOM number of edges with WEIGHTS"<<endl;
                    for (int i =0; i<num3; i++)
                    {
                        num1 = rand() % size;       //resetting during each iteration 
                        num2 = rand() % size; 
                        edgeWeight = rand() % size2;
                        cout<<endl<<endl;
                        cout<<num1<<","<<num2<<","<<edgeWeight<<endl;
                        g.addEdge(num1,num2,num3) ? cout << "added" << endl : cout << "failed-- already exists" << endl;
                        cout<<endl;
                    }
                } else
                {
                    cout<<"Testing adding RANDOM number of edges"<<endl;
                    for (int i =0; i<num3; i++)
                    {
                        num1 = rand() % size;       //resetting during each iteration 
                        num2 = rand() % size;       

                        cout<<"Adding ("<<num1<<","<<num2<<") edge: "<<endl; 
                        g.addEdge(num1,num2) ? cout << "added" << endl : cout << "failed-- already exists" << endl;
                    }

                }

                cout << "DFS & BFS w/ same vertex" << endl;
                cout << "==============================================" << endl;                
                cout<<"Breath first Search results: "<<endl;
                g.BFS(5);
                cout<<endl;
                cout<<"Depth first Search results:"<<endl;
                g.DFS(5);
                cout<<endl<<endl;

                /*
                *  To account for connected but disjointed graphs that are from original graph 
                */

                cout << "DFS & BFS w/ Random vertex" << endl;
                cout << "==============================================" << endl;                
                cout<<"Breath first Search results from "<<DFSnum<<": "<<endl;
                g.BFS(DFSnum);
                cout<<endl;
                DFSnum = rand() % size;
                cout<<"Depth first Search results from "<<DFSnum<<": "<<endl;
                g.DFS(DFSnum);
                cout<<endl;

                cout << "DFS & BFS w/ Random vertex and Random number of times" << endl;
                cout << "==============================================" << endl; 
                for (int i=0;i<num2;i++)
                {
                    cout<<"Breath first Search results from "<<DFSnum<<": "<<endl;
                    g.BFS(DFSnum);
                    cout<<endl;
                    DFSnum = rand() % size;
                    cout<<"Depth first Search results from "<<DFSnum<<": "<<endl;
                    g.DFS(DFSnum);
                    cout<<endl<<endl;

                }       
                cout <<"Adjacency list edge/vortex Info" << endl;
                cout <<"==============================================" << endl;
                cout<<"Edge count: "<<g.numEdges()<<endl;
                cout<<"Vertex count: "<<g.numVertex()<<endl;
                cout<<"Is the graph Connected: "<<endl;
                g.isConnected() ? cout << "Yes" << endl : cout << "No" << endl;
                cout<<endl;
                if(!g.isConnected())
                {
                    cout<<"List the disconnected:"<<endl;
                    g.listDisconnected();
                }

                cout << endl << endl; 





           



        
            } ///// end file read /////
            
        }                       //left off here****************************************************************
                
    } else {
        cout<<"file DNE (Does not exist)"<<endl;
    }

    return 0;
}
