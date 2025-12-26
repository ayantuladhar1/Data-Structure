/**
 * This is a comparator class which has one member function -
 * isLessThan. This member function can be used to compare
 * Rectangles by their area.
 * Author: Ayan Tuladhar
 * Version: 08/30/20
 */
#include "Rectangle.h"
#ifndef HW2_RECTANGLEAREACOMPARATOR_H
#define HW2_RECTANGLEAREACOMPARATOR_H

class RectangleAreaComparator {
public:

    /**
     * This function can be used to compare two Rectangles based
     * on their area. It will return true if area of left
     * Rectangle is less than the area of right Rectangle
     * @param lhs Rectangle object
     * @param rhs Rectangle object
     * @return true if left Rectangle < right Rectangle, otherwise
     * it will return false
     */


    bool isLessThan(const Rectangle& lhs, const Rectangle& rhs)
    {
        //Write the code needed to compare Rectangle based on their area

        int LeftArea = (lhs.getLength() * lhs.getWidth());
        int RightArea = (rhs.getLength() * rhs.getWidth());
        if (LeftArea < RightArea)
            return true;
        else
            return false;
    }
};


#endif //HW2_RECTANGLEAREACOMPARATOR_H
#pragma once
