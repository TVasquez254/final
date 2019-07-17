/***********************************************************
Name: Tomas Vasquez 
Assignment: Final
Purpose: 
Notes:  
***********************************************************/

#include "functions.h"



bool displaySize(int argc, char** argv)
{
    int count = 0;
    int MAX_SIZE =40;
    string line;
    bool x;
    for (int i=1; i< argc; ++i)
    {
        ifstream file(argv[i]);
        file.peek();
        if (!file.eof())
        {
            int c=0;
            while (getline(file, line, ','))        //gets number of lines
            {
                c+= line.length();        
                count++;
                c = 0;
            }
             
            if (count>MAX_SIZE)
            {
                x =false;
            }
            else {
                x = true;
            }   
        }
         file.close();
        }
    return x;
}