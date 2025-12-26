/**
 *Header for Car class. Car has six variables.
 *Numberofcars, Cararrival_t, Carwash_start_t, Carwait_t, Cartotal_t, Cardeparture_t are type int.
 *contains constructor for class Car.
 * 
 * Author: Ayan tuladhar
 * Version: 10/11/2020
 */


#include <iostream>
using namespace std;


class Car
{
public:
   

    int Numberofcars, Cararrival_t, Carwash_start_t =0, Carwait_t =0, Cartotal_t =0, Cardeparture_t =0;
    bool Car_serviced =0;

    

    Car (int car_number2 , int cararrival2_t )
    {
        Numberofcars = car_number2;
        Cararrival_t = cararrival2_t;

    }


};