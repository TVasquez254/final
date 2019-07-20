/***********************************************************
Name: Tomas Vasquez 
Assignment: Final
Purpose: 
Notes:   
***********************************************************/

#ifndef DATA_H
#define DATA_H

#include <string>
using std::string;


struct Node {
    int name;
    int weight;
    Node(int n, int w)
    {name=n; weight = w;}
};

#endif /* DATA_H */