/*Header for Set class. Set class has two variables
 *Union and Intersection are both type int with vector
 *Contains Vector(STL) and push_back function for object
 *Author: Ayan Tuladhar
 * Version: 09/20/20
 */


#ifndef unionandintersection_H
#define unionandintersection_H
#include "Sets.h"
#include <vector>
using namespace std;
/*Constructor for Union which takes two arguments*/
vector<int>Sets::Union(vector<int>x, vector<int>y)
{
	vector<int> z;

	for (int a = 0; a < x.size(); a++)
/*adds integer at the end of the list or storing at z vector*/

		z.push_back(x.at(a));

	for (int a = 0;a < y.size();a++)
	{
		bool file = false;

		for (int b = 0; b < x.size();b++)

			if (x.at(b) == y.at(a))

				file = true;

		if(!file)
			z.push_back(y.at(a));

	}
	return z;
}	
/*Constructor for Intersection which takes two arguments*/

vector<int>Sets::Intersection(vector<int>x, vector<int>y)
{
	vector<int> z;

	for (int a = 0;a < x.size();a++)

		for (int b = 0;b < y.size();b++)

			if (y.at(b) == x.at(a))

/*adds an interger at the end of the list pf storing at z vector */
				z.push_back(y.at(b));

				return z;
}




#endif