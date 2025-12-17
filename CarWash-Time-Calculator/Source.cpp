/* This is the main function. It creates a vector, queue and string for car wash.
 * It takes file arrival_time.txt and store them the number of cars that comes to our car wash as variables.
 * It combines elements form Header1.h file
 * 
 * Author: Ayan tuladhar
 * Version : 10 / 11 / 2020
*/

#include <math.h>
#include <iostream>//Use cout and cin
#include <string>
#include <vector>
#include <queue>
#include <sstream> //String stream
#include <fstream> //ifstream
#include "Header1.h"
using namespace std;


#define SIMULATION_END_TIME 540 //The #define creates a macro, which is the association of an identifier or parameterized identifier with a token string. 
#define CAR_SERVICE_START_TIME 3

//This function uses string operation and if/else statement to calculate the SIMULATION_END_TIME and display the opening and closing time in minutes and hour.


string Carwash_closingtime()
{
    string System;
    if (SIMULATION_END_TIME >= 4 * 60)
    {
        int min = (SIMULATION_END_TIME - 4 * 60) % 60, hour = (SIMULATION_END_TIME - 4 * 60) / 60;
        System = to_string(hour);
        System.append(":"); //Extends the string by appending characters at the end of its current value
        if (min < 10) 
        {
            System.append("0");
        }
        System.append(to_string(min));
        System.append("PM");
    }
    else 
    {
        
        int min = SIMULATION_END_TIME % 60, hour = SIMULATION_END_TIME / 60;
        System = to_string(hour + 8);
        System.append(":");
        if (min < 10) 
        {
            System.append("0");
        }
        System.append(to_string(min));
        System.append("AM");
    }
    return System;
}

int main() 
{   //This function includes vector and queue operations for casr wash simulation.
    //This function will read in a line of strings from the arrival_time.txt file.

    vector<Car> numberofcarservicing_wash;
    queue<Car> thequeueofcars;
    int thenumberofcars = 1;
    string line;
    ifstream infile("arrival_time.txt");

    while (getline(infile, line)) //Read a single line and store it in line.
    {
        Car c(thenumberofcars++, stoi(line));
        thequeueofcars.push(c);
    }
    
    // This function runs the simulation of car wash and displays arrival time, car wash start time, departure time, wait time and total time.
    // This function uses the queue operation to add, remove and peek the entries for cars.

    cout << "Opening Time: 8:00 AM (0 minute)\n";
    cout << "Closing Time: " << Carwash_closingtime() << " (" << SIMULATION_END_TIME << " minute)\n" ;
    cout << "Start of Simulation\n" ;
    int Carwaiting_queue_t = 0, serviceprocessing_Car_serviced = 0, start_wash = 0, please_wait_wash_in_use = 0;
    while (!thequeueofcars.empty()) //chech if queue is empty
    {
        Car job = thequeueofcars.front(); //look at the entry in queue
        if (job.Cararrival_t <= SIMULATION_END_TIME)
        {
            job.Car_serviced = true;
            if (start_wash < job.Cararrival_t) 
            {
                job.Carwash_start_t = job.Cararrival_t;
            }
            else
            {
                job.Carwash_start_t = start_wash;
            }
            start_wash = job.Carwash_start_t + CAR_SERVICE_START_TIME;
            job.Cardeparture_t = start_wash;
            job.Carwait_t = job.Carwash_start_t - job.Cararrival_t;
            job.Cartotal_t = start_wash - job.Cararrival_t;
            Carwaiting_queue_t += job.Carwait_t;
            serviceprocessing_Car_serviced++;
            please_wait_wash_in_use += CAR_SERVICE_START_TIME;
        }
        else 
        {
            job.Car_serviced = false;
        }
        thequeueofcars.pop(); //removes and ebtry in queue
        numberofcarservicing_wash.push_back(job); //adds a new element at the end of the container after its current last element.
    }
    cout << "Car Number   Arrival Time   Car Wash Start Time   Departure Time   Wait Time   Total Time\n";
    cout << "------------------------------------------------------------------------------------------\n";
    for (int a = 0; a < numberofcarservicing_wash.size(); a++) 
    {
        Car wash = numberofcarservicing_wash[a];
        if (wash.Car_serviced) 
        {
            cout << " "
                << wash.Numberofcars << "\t\t"
                << wash.Cararrival_t << "\t\t"
                << wash.Carwash_start_t << "\t\t\t"
                << wash.Carwash_start_t + CAR_SERVICE_START_TIME << "\t\t"
                << (wash.Carwash_start_t - wash.Cararrival_t) << "\t\t"
                << (wash.Carwash_start_t + CAR_SERVICE_START_TIME - wash.Cararrival_t)  << endl;
        }
        else {
            cout << " " 
                << wash.Numberofcars << "\t\t"
                << wash.Cararrival_t << "\t"
            << "Car arrived after closing time and was not served" << endl;
        }
    }

    cout << "End of Simulation\n\n";
    
    
    
    //This function displays the Statistics of the car wash simulation.

    
    float avg_Carwait_t =(float) Carwaiting_queue_t / (float)serviceprocessing_Car_serviced;

    int avg_Carwait_t_min;

    


    avg_Carwait_t_min = static_cast<int>(floor(avg_Carwait_t)); //floor() retruns the largest possible integer value which lesss than or equal to argument
    int avg_Carwait_t_seconds;

    avg_Carwait_t_seconds = static_cast<int>(floor((avg_Carwait_t - (float)avg_Carwait_t_min) * 60)); //float-defines numeric values with floating decimal points.
    cout << "Statistics:\n";
    cout << "\t" << "Total wait time:\t\t\t\t" << Carwaiting_queue_t << " minute\n";
    cout << "\t" << "average wait time:\t\t\t\t" << avg_Carwait_t_min << " minute and " << avg_Carwait_t_seconds << " seconds\n";
    cout << "\t" << "Total car wash time:\t\t\t\t" << please_wait_wash_in_use << " minute\n";
    cout << "\t" << "Percentage of time car wash was in use:\t\t" << ((float)please_wait_wash_in_use / SIMULATION_END_TIME) * 100 << "%\n";
   
    return 0;
}