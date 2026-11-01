/******************************************************************************
vector3d.cpp
******************************************************************************
 Name: Tauseen Ahmed
******************************************************************************
 AI conversation links (Step 2 and/or Step 3):
All I converstaions will be placed on 5b
https://chatgpt.com/share/69ea9efa-f858-83ea-917e-3f8d8f3231ca
https://chatgpt.com/share/69eaa71e-1d68-83ea-8504-138f0f1b13de

******************************************************************************
 Overall notes (not to replace inline comments):


*/

#include<iostream> // no other headers should be added

class Vector3D
{
    /* Write the class definition */
    private:
        double x;
        double y;
        double z;
    public:
    //Constructor
    Vector3D(double xVal = 0.0, double yVal = 0.0, double zVal = 0.0){
        x = xVal;
        y = yVal;
        z = zVal;
    }
    //Accessor methods
    double getX() const{ return x;}
    double getY() const{ return y;}
    double getZ() const {return z;}
    
    //Overload + operator
    Vector3D operator+(const Vector3D& other) const{
        return Vector3D(x + other.x, y + other.y, z + other.z);
    } 
    //

    //Overload - operator
    Vector3D operator-(const Vector3D& other ) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    //Overload * operator scalar
    Vector3D operator*(double scalar) const {
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }

    //Overload * operator( product between two vectors)
    double operator*(const Vector3D& other) const{
        return(x * other.x) + (y * other.y) + (z * other.z);
    }
    //Overload == operator
    bool operator==(const Vector3D& other) const{
        return(x == other.x) && (y == other.y) && (z == other.z);
    }

// 6b
    //Overload +=
    Vector3D& operator+=(const Vector3D& other){
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    //Overload -=
    Vector3D& operator-=(const Vector3D& other){
        x-= other.x;
        y-= other.y;
        z-= other.z;
        return *this;
    }

    //Cross product
    Vector3D cross(const Vector3D& other) const{
        return Vector3D(
            (y * other.z) - (z * other.y),
            (z * other.x) - (x * other.z),
            (x * other.y) - (y * other.x)

        );
    }

    //friend declarations
    friend Vector3D operator*(double scalar, const Vector3D& v);
    friend std::ostream& operator <<(std::ostream& out, const Vector3D& v);
    friend std::istream& operator >>(std::istream& in, Vector3D& v);

};

//friend function scalar multi
Vector3D operator*(double scalar, const Vector3D& v){
    return Vector3D(scalar * v.x, scalar * v.y, scalar * v.z);
}

//friend function output stream
std::ostream& operator<<(std::ostream& out, const Vector3D& v){
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;

}

//friend function input stream
std::istream& operator>>(std::istream& in, Vector3D& v){
    in >> v.x >> v.y >> v.z;
    return in;
}


// ============================================================
// TESTER CODE — uncomment sections as you implement each part.
// Remove or comment out main() before submitting to Gradescope.
// ============================================================

/*
int main()
{
    // --- Part (a): Arithmetic and comparison operators ---

    Vector3D p1(1.0, 2.0, 3.0);
    std::cout << p1.getX() << " " << p1.getY() << " " << p1.getZ() << "\n";
    // Expected: 1 2 3

    Vector3D p2(2.0, 4.0, 7.0);
    std::cout << p2.getX() << " " << p2.getY() << " " << p2.getZ() << "\n";
    // Expected: 2 4 7

    Vector3D p3 = p1 + p2;
    std::cout << p3.getX() << " " << p3.getY() << " " << p3.getZ() << "\n";
    // Expected: 3 6 10

    Vector3D p4 = p1 - p2;
    std::cout << p4.getX() << " " << p4.getY() << " " << p4.getZ() << "\n";
    // Expected: -1 -2 -4

    Vector3D p5 = p1 * 2;
    std::cout << p5.getX() << " " << p5.getY() << " " << p5.getZ() << "\n";
    // Expected: 2 4 6

    double dot_prod = p1 * p2;
    std::cout << dot_prod << "\n";
    // Expected: 31

    bool check1 = (p1 == p2);
    std::cout << check1 << "\n";
    // Expected: 0

    Vector3D p7(1.0, 2.0, 3.0);
    bool check2 = (p1 == p7);
    std::cout << check2 << "\n";
    // Expected: 1

    // --- Part (b): Friend functions, compound assignment, and more ---

    // Vector3D p6 = 2 * p2;  // scalar * vector (friend)
    // std::cout << p6.getX() << " " << p6.getY() << " " << p6.getZ() << "\n";
    // Expected: 4 8 14

    // Vector3D v1(1, 2, 3);
    // Vector3D v2(4, 5, 6);
    // v1 += v2;
    // std::cout << v1.getX() << " " << v1.getY() << " " << v1.getZ() << "\n";
    // Expected: 5 7 9

    // Vector3D v3(10, 20, 30);
    // Vector3D v4(3, 7, 11);
    // v3 -= v4;
    // std::cout << v3.getX() << " " << v3.getY() << " " << v3.getZ() << "\n";
    // Expected: 7 13 19

    // Vector3D c1(1, 0, 0);
    // Vector3D c2(0, 1, 0);
    // Vector3D c3 = c1.cross(c2);
    // std::cout << c3.getX() << " " << c3.getY() << " " << c3.getZ() << "\n";
    // Expected: 0 0 1

    // std::cout << p1 << "\n";
    // Expected: (1, 2, 3)

    // std::cout << p3 << "\n";
    // Expected: (3, 6, 10)

    // Vector3D p8;
    // std::cin >> p8;
    // std::cout << p8 << "\n";
    // Expected: the coordinate form of the numbers you entered

    return 0;
}
*/
