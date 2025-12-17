/**
 * Header for Rectangle class. Rectangle class has two variables
 * length and width both of type int. Rectangle class has two constructors
 * one is no parameter constructor which sets the length and width to 1.
 * The second constructor takes two arguments len to set the length and
 * wid to set the width
 * Note: There is no getArea or getPerimeter method.
 *
 * Use this file as it. Do not make any changes.
 *
 * Author: Ayan Tuladhar
 * Version: 08/30/20
 *
 */


#ifndef HW2_RECTANGLE_H
#define HW2_RECTANGLE_H


class Rectangle {
private:
    int length;
    int width;

public:
    Rectangle();
    Rectangle(int len, int wid);

    int getLength() const;
    int getWidth() const;

};


#endif //HW2_RECTANGLE_H
#pragma once
