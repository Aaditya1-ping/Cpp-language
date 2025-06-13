#include <iostream>
using namespace std;


#define PI 3.14159


class Shape {
public:
    virtual float calculateArea() = 0;
    virtual void draw() = 0;
    virtual ~Shape() {}
};


class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    float calculateArea()  {
        return PI * radius * radius;
    }

    void draw()  {
        cout << "Drawing a Circle with radius " << radius << endl;
    }
};


class Rectangle : public Shape {
private:
    float width, height;

public:
    Rectangle(float w, float h) {
        width = w;
        height = h;
    }

    float calculateArea()  {
        return width * height;
    }

    void draw()  {
        cout << "Drawing a Rectangle with width " << width
             << " and height " << height << endl;
    }
};

int main() {
    float radius, width, height;

   
    cout << "Enter radius of the circle: ";
    cin >> radius;

   
    cout << "Enter width of the rectangle: ";
    cin >> width;
    cout << "Enter height of the rectangle: ";
    cin >> height;

    
    Circle userCircle(radius);
    Rectangle userRectangle(width, height);

  
    Shape* shapes[2];
    shapes[0] = &userCircle;
    shapes[1] = &userRectangle;

    
    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->calculateArea() << endl<<endl;
    }

   
}
/*
Output:
Enter radius of the circle: 7
Enter width of the rectangle: 12
Enter height of the rectangle: 7
Drawing a Circle with radius 7
Area: 153.938

Drawing a Rectangle with width 12 and height 7
Area: 84

*/


