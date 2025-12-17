#include <iostream>   //Use cout and cin
#include <sstream>  //String stream
#include <string>
#include <fstream>  //ifstream
#include <vector>
#include "Sets.h"
#include <algorithm>
using namespace std;

/*
*This is the main function.It creates a vector for two sets.
* It takes two file from setInput.txt and store then into two seperate sets which are set1 and set2.
* It combine the elements from two sets and find the Union using function
* It combines the elements from two sets and find the Intersection using function
* /


/* * This function will read in a line of string from the input file,
* validate that all inputs are int, split the string using blank space
* and populate the vector */
bool getIntsFromFile(ifstream& infile, vector<int>& vec)
{
    stringstream ss;   //Use for breaking string into tokens    
    int tempInt;
    string readString;
    getline(infile, readString);  //Read a single line and store it in readString    
    ss << readString;    //Write readString into ss    
    while (!ss.eof()) // Loop as loon as there are tokens in ss    
    {
        ss >> tempInt;   //Read in one int from ss into tempInt        
        if (ss.fail())   //If input is not an int        
        {
            cout << "Input contains non-integer data" << endl;
            ss.clear();     //clear state of string stream            
            return false;
        }
        vec.push_back(tempInt);  //Add in to the vector    
    }
    return true;
}
/* * This function will display the contents of the vector */
void TheValue(vector<int> set) {
    for (int a = 0;a < set.size(); a++) {
        cout << set[a] << " ";
    }
    cout << endl;
}



int main()
{
    ifstream infile("setInput.txt");
    vector<int> Set1, Set2;
    cout << "set1" << endl;
    //This function reads the elements from Set1
    if (getIntsFromFile(infile, Set1))
    {
        TheValue(Set1);

    }
    cout << "set2" << endl;
    //This function reads the elements from Set2
    if (getIntsFromFile(infile, Set2))
    {
        TheValue(Set2);
    }
    //It creats and object program for the Sets
    //This object program helps to find the union between the two sets by combing contains and not containing the duplicate item
    Sets DR;
    vector<int> setUnion = DR.Union(Set1, Set2);
    //Prints Union of the two sets
    cout << "setUnion:" << endl;
    TheValue(setUnion);

    //This object program helps to find the intersection between the two sets by containing the entries that occurin both sets
   

    vector<int> setIntersection = DR.Intersection(Set1, Set2);
    //Prints Intersection of the two sets
    cout << "setIntersection:" << endl;
    TheValue(setIntersection);

};

    