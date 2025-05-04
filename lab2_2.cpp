#include <iostream>
using namespace std;

class Shape 
{
protected:
    float* length; 
public:
    Shape(float len) 
    {
        length = new float(len);
    }
    virtual ~Shape() { delete length; } 
    virtual float calculateArea() = 0; 
};

class Square : public Shape 
{
public:
    Square(float len) : Shape(len) {}
    float calculateArea() override 
    {
        return (*length) * (*length);
    }
};

class Cube : public Shape 
{
public:
    Cube(float len) : Shape(len) {}
    float calculateArea() override {
        return 6 * (*length) * (*length);
    }
};

class Rectangle : public Shape 
{
private:
    float* width;
public:
    Rectangle(float len, float wid) : Shape(len) {
        width = new float(wid);
    }
    ~Rectangle() { delete width; }
    float calculateArea() override {
        return (*length) * (*width);
    }
};

class Cuboid : public Shape 
{
private:
    float* width;
    float* height;
public:
    Cuboid(float len, float wid, float hei) : Shape(len) {
        width = new float(wid);
        height = new float(hei);
    }
    ~Cuboid() {
        delete width;
        delete height;
    }
    float calculateArea() override {
        return 2 * ((*length * *width) + (*width * *height) + (*length * *height));
    }
};

int main() 
{
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Square\n2. Cube\n3. Rectangle\n4. Cuboid\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            float len, wid, hei;

            cout << "Enter length: ";
            cin >> len;

            if (len <= 0) 
            {
                cout << "Invalid input. Length must be positive.\n";
                continue;
            }

            switch (choice) 
            {
                case 1:
                {
                    Square sq(len);
                    cout << "Area of Square: " << sq.calculateArea() << endl;
                    break;
                }
                case 2: 
                {
                    Cube cu(len);
                    cout << "Surface Area of Cube: " << cu.calculateArea() << endl;
                    break;
                }
                case 3: 
                {
                    cout << "Enter width: ";
                    cin >> wid;
                    if (wid <= 0) {
                        cout << "Invalid input. Width must be positive.\n";
                        continue;
                    }
                    Rectangle rect(len, wid);
                    cout << "Area of Rectangle: " << rect.calculateArea() << endl;
                    break;
                }
                case 4: 
                {
                    cout << "Enter width: ";
                    cin >> wid;
                    cout << "Enter height: ";
                    cin >> hei;
                    if (wid <= 0 || hei <= 0) {
                        cout << "Invalid input. Dimensions must be positive.\n";
                        continue;
                    }
                    Cuboid cub(len, wid, hei);
                    cout << "Surface Area of Cuboid: " << cub.calculateArea() << endl;
                    break;
                }
            }
        } 
        else if (choice != 5) 
        {
            cout << "Invalid choice, please try again.\n";
        }

    } while (choice != 5);

    cout << "Exiting program.\n";
    return 0;
}
