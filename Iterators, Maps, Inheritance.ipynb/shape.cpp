////shape.cpp
// Example 6a - Shape with Circle and Rectangle
// (You write this!)
#include <iostream>
#include <string>

class Shape{
protected:
    std::string color;
public:
    Shape(std::string c) : color(c) {}
    void printColor() {
        std::cout << "Color: " << color << std::endl;
    }

};
class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(std::string c, double r) : Shape(c), radius(r) {}
        double area() {
            return 3.14159265 * radius * radius;
        }
};

class Rectangle :  public Shape{
    private:
        double width;
        double height;
    public:
        Rectangle(std::string c, double w,  double h) : Shape(c), width(w), height(h){} 
        double area(){
            return width * height;
        }

};

int main(){
    // TODO: write your solution here, then test it.
    Circle circle("red", 3.0);
    Rectangle rectangle("green", 4.0, 3.0);
    circle.printColor();
    std::cout << "Circle area: " << circle.area() << std::endl;
    
    rectangle.printColor();
    std::cout << "rectangle area: " << rectangle.area() << std::endl ;
    return 0;
}