/**
 * This is a comparator class which has one member function -
 * isLessThan. This member function can be used to compare
 * Rectangles by their perimeter.
 * Author: Ayan Tuladhar
 * Version: 08/30/20
 */
#include "Rectangle.h"

#ifndef HW2_RECTANGLEPERIMETERCOMPARATOR_H
#define HW2_RECTANGLEPERIMETERCOMPARATOR_H

class RectanglePerimeterComparator {
public:
    /**
     * This function can be used to compare two Rectangles based
     * on their perimeter. It will return true if perimeter of left
     * Rectangle is less than the Perimeter of right Rectangle
     * @param lhs Rectangle object
     * @param rhs Rectangle object
     * @return true if left Rectangle < right Rectangle, otherwise
     * it will return false
     */
    bool isLessThan(const Rectangle& lhs, const Rectangle& rhs)
    {
        //Write the code needed to compare Rectangle based on their perimeter
        int LeftPerimeter = (2 * (lhs.getLength() + lhs.getWidth()));
            int RightPerimeter = (2 * (rhs.getLength() + rhs.getWidth()));
                if (LeftPerimeter < RightPerimeter)
                    return true;
                else
                    return false;
    }
};

#endif //HW2_RECTANGLEPERIMETERCOMPARATOR_H
#pragma once
