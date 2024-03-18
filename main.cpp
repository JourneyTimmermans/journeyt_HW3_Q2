
/*************************************************************************
** Author : Journey Timmermans
** Program : hw3, q2
** Date Created : March 16, 2024
** Date Last Modified : March 17, 2024
** Usage : No command line arguments
**
** Problem:
Create a program that displays rectangles and triangles that are children
 of the polygon class given to us
*************************************************************************/

#include <iostream>
#include "Polygon.h"

class Rectangle : Polygon {
public:
    Rectangle() : Polygon() {}
    Rectangle(int newWidth, int newHeight) : Polygon(newWidth, newHeight) {}

    virtual int getArea() {
        return width * height;
    }

    virtual void draw() {
        for (int i=0; i<height; i++) {
            for (int j=0; j<width; j++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
};


class Triangle : public Polygon {
public:
    Triangle() : Polygon() {}
    Triangle(int newWidth, int newHeight) : Polygon(newWidth, newHeight) {}

    virtual int getArea() {
        return width*height / 2;
    }

    virtual void draw() {
        int numSpaces = height - 1;
        for (int i=0; i < height; i++) {
            for (int j = 0; j < numSpaces; j++) {
                std::cout << " ";
            }
            numSpaces--;

            for (int k=0; k<2*i+1; k++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
};


int main() {
    Rectangle rect(5,9);
    Triangle tri(10,5);

    std::cout << "Rectangle Area: " << rect.getArea() << std::endl;
    std::cout << "Triangle Area: " << tri.getArea() << std::endl;

    rect.draw();

    tri.draw();

    //Question 1: Polygon is an abstract class with virtual functions so it will cause a compilation error

    //Question 2: We get an error because getArea was pure virtual

    return 0;
}
