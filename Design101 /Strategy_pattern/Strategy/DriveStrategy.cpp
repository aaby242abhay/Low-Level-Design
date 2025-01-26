#include <bits/stdc++.h>
using namespace std;

class DriveStrategy {
public:
    virtual void drive() = 0;
    virtual ~DriveStrategy() = default;     //defaulted virtual contructor
};

class NormalDriveStrategy : public DriveStrategy {
public:
    void drive() override{
        cout<<"Normal Driving"<<endl;
    }
};

class SpecialDriveStrategy : public DriveStrategy {
public:
    void drive() override{
        cout << "Special Driving" << endl;
    }
};

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

class OffRoadVehicle : public Vehicle{
public:
    OffRoadVehicle() : Vehicle(new SpecialDriveStrategy()){
        cout << "OffRoadVehicle constructor" << endl;
    }
};

class SportsVehicle : public Vehicle{
public:
    SportsVehicle() : Vehicle(new SpecialDriveStrategy()){
        cout << "SportsVehicle constructor" << endl;
    }
};

class Alto : public Vehicle{
public:
    Alto() : Vehicle(new NormalDriveStrategy()){
        cout << "Alto constructor" << endl;
    }
};

int main(){
    Vehicle* v1 = new OffRoadVehicle();
    Vehicle* v2 = new SportsVehicle();
    Vehicle* v3 = new Alto();
    v1->drive();
    v2->drive();
    v3->drive();
    return 0;
}


