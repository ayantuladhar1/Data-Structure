#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;



int Expression(string);
int Expression(string air)
{
    //This helps to initiate an empty stack in the function
    stack<int> airthmatic;
    //This helps to move the expression
    for (int x = 0; x < air.length(); x++)
    {
        //The following if/else function helps to notice if it is operand or operator, if it is an operand then it pushes to the stack
        if (air[x] >= '0' && air[x] <= '9')
        {
            //push inserts new item at top of the stack
            airthmatic.push(air[x] - '0');
        }
        else if (air[x] == ' ')
            continue;
        else if (airthmatic.size() < 2)
            return -1;
        //The following contains pop function which pops elements from the stack


        else
        {
            //In Postfix operation each binary operator appears after its operands
            //For example:ab+
            //pop removes an item from the top of the stack
            int a = airthmatic.top();
            airthmatic.pop();
            int b = airthmatic.top();
            airthmatic.pop();
            if (air[x] == '+')
                airthmatic.push(b + a);
            else if (air[x] == '-')
                airthmatic.push(b - a);
            else if (air[x] == '*')
                airthmatic.push(b * a);
            else if (air[x] == '/')
                airthmatic.push(b / a);
            else
                return -2;
        }

    }
    if (airthmatic.size() > 1)
    {

        return -2;

    }
    return airthmatic.top();

}
//Main function
int main()
{
    //Display an input messgae where user can input the postfix expression
    cout << "Enter the postfix airthmetic expression :" << endl;
    string air;
    getline(cin, air);
    int c = Expression(air);
    //Display an error message if there is an error in the given expression
    if (c == -1)
        cout << "Missing operand Missing operand" << endl;
    else if (c == -2)
        cout << "Missing operator" << endl;

    //Display the result
    else
    {
        cout << "The result is: " << endl;
        cout << c;
    }

    return 0;
}