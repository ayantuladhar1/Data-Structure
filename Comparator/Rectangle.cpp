/**
 * Header for Rectangle class. Rectangle class has two variables
 * length and width both of type int. Rectangle class has two constructors
 * one is no parameter constructor which sets the length and width to 1.
 * The second constructor takes two arguments len to set the length and
 * wid to set the width.
 * Note: There is no getArea or getPerimeter method.
 *
 * Use this file as it. Do not make any changes.
 *
 * Author: Ayan Tuladhar
 * Version: 08/30/20
 *
 */

#include "Rectangle.h"

 /**
  * No argument constructor which sets the length and width to 1.
  */
Rectangle::Rectangle()
{
    length = 1;
    width = 1;
}

/**
 * Constructor for Rectangle which takes two arguments
 * @param len - length of the Rectangle
 * @param wid - width of the Rectangle
 */
Rectangle::Rectangle(int len, int wid)
{
    length = len;
    width = wid;
}

/**
 * @return length of the Rectangle
 */
int Rectangle::getLength() const
{
    return length;
}

/**
 *
 * @return width of the rectangle
 */
int Rectangle::getWidth() const
{
    return width;
}
