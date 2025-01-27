//getting the type of the instance of the class
#include<bits/stdc++.h>
using namespace std;

class Shape{
public:
    virtual void draw() const = 0;
};

class Rectangle : public Shape{
public:
    void draw() const override {
        cout << "This is a rectangle" << endl;
    }
};

class Square : public Shape{
public:
    void draw() const override{
        cout << "This is a square" << endl;
    }
};

class Circle : public Shape{
public:
    void draw() const override{
        cout << "This is a circle" << endl;
    }
};

enum class ShapeType{
    Circle,
    Rectangle,
    Square,
    Unknown
};
ShapeType getShapeType(const string& input){
    if(input == "Circle") return ShapeType :: Circle;
    if(input == "Rectangle") return ShapeType :: Rectangle;
    if(input == "Square") return ShapeType :: Square;
    return ShapeType ::Unknown;
}

class ShapeFactory{
public:
    Shape* getShape(string input){

        ShapeType type = getShapeType(input);

        switch (type) {
            case ShapeType::Circle :
            return new Circle();
            break;
            case ShapeType::Rectangle :
            return new Rectangle();
            break;
            case ShapeType::Square :
            return new Square();
            break;
            default:
            return nullptr;
            break;
        }
    }
};


int main(){
    ShapeFactory* ShapeFactoryObj = new ShapeFactory();
    Shape* myCircle = ShapeFactoryObj->getShape("Circle");
    Shape* myRect = ShapeFactoryObj->getShape("Rectangle");
    Shape* mySquare = ShapeFactoryObj->getShape("Square");
    myCircle->draw();
    myRect->draw();
    mySquare->draw();

    return 0;
}
