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
        
            } ///// end file read /////
            
        }
                
    } else {
        cout<<"file DNE (Does not exist)"<<endl;
    }

    return 0;
}
