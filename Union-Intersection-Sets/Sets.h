/**
 * Header for Set class. Set class has two variables
 * Union and Intersection are both type int with vector
 * Author: Ayan Tuladhar
 * Version: 09/20/20
 *
 */
#ifndef Sets_H
#define Sets_H
#include <vector>
using namespace std;

class Sets {





public:

	vector<int>Union(vector<int>x, vector <int>y);

	vector <int>Intersection(vector<int>x, vector<int>y);
};

#endif