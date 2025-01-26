#include <bits/stdc++.h>
using namespace std;

//strategy Interface
class DriveStrategy {
public:
    virtual void drive() = 0;
    virtual ~DriveStrategy() = default;     //defaulted virtual contructor
};

//Concrete Strategy
class NormalDriveStrategy : public DriveStrategy {
public:
    void drive() override{
        cout<<"Normal Driving"<<endl;
    }
};

//Concrete Strategy
class SpecialDriveStrategy : public DriveStrategy {
public:
    void drive() override{
        cout << "Special Driving" << endl;
    }
};


//BASE CLASS
class Vehicle{
    DriveStrategy* dv;                  //this is a pointer to the drive strategy
public:
    Vehicle(DriveStrategy* dv){
        this->dv = dv;
    }
    void drive(){
        dv->drive();
    }
};

//Derived class
class OffRoadVehicle : public Vehicle{
public:
    OffRoadVehicle() : Vehicle(new SpecialDriveStrategy()){
        cout << "OffRoadVehicle constructor" << endl;
    }
};

//Derived class
class SportsVehicle : public Vehicle{
public:
    SportsVehicle() : Vehicle(new SpecialDriveStrategy()){
        cout << "SportsVehicle constructor" << endl;
    }
};

//Derived class
class Alto : public Vehicle{
public:
    Alto() : Vehicle(new NormalDriveStrategy()){
        cout << "Alto constructor" << endl;
    }
};


//Client code
int main(){
    Vehicle* v1 = new OffRoadVehicle();
    Vehicle* v2 = new SportsVehicle();
    Vehicle* v3 = new Alto();
    v1->drive();
    v2->drive();
    v3->drive();
    return 0;
}


