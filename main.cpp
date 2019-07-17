/***********************************************************
Name: Tomas Vasquez 
Assignment: Final
Purpose: 
Notes:   
***********************************************************/
#include "main.h" 
#include <fstream>
int main(int argc, char *argv[])
{
    srand(time(NULL));          // Time 
    //HashTable hashtable;        //Dynamic allocated Hashtable
    bool fileSize;              // file size evaluation
    int id;                     // id extractor 
    string word;                // file word extraction
    int h=0;                    //ARGV counter
    h = argc-1;                 // maintenance counter control

    //*************************************************************
    //   Main Data Test-Checking for opening & error checking     *
    //*************************************************************

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
            int vertices;
            int edges;
            //fileSize = displaySize(argc, argv);

            if (infile.eof()){
                cout<<"nothing is there"<<endl;
            } else if(!infile.is_open())
            {
                cout<<"file doesnt exist"<<endl;
                
            } else 
            {
                if (infile.is_open())
                {
                    infile >> vertices;
                    infile >> edges;
                    int matrix[vertices][vertices];
                    for (int j=0;j<vertices;j++)
                    {
                        for (int k=0;k<vertices;k++)
                        {
                            matrix[j][k]=0;
                        }
                    }
                                    
                }
        
                infile.close();
        
            }
            
        }
                
    } else {
        cout<<"file DNE (Does not exist)"<<endl;
    }

    return 0;
}