//this is factory of factory
#include<bits/stdc++.h>
using namespace std;

enum class CarType{
    Luxury_1,
    Luxury_2,
    Normal_1,
    Normal_2
};

class Car{
public:
    string name = "MyCar";
    virtual void speed() const = 0;
};

class LuxuryCar_1 : public Car{
public:
    string name = "Luxury Car 1st";
    void speed() const override{
        cout << "This is a luxury car 1st." << endl;
    }
};
class LuxuryCar_2 : public Car{
public:
    string name = "Luxury Car 2nd";
    void speed() const override{
        cout << "This is a luxury car 2nd." << endl;
    }
};

class NormalCar_1 : public Car{
public:
    string name = "Normal Car 1st";
    void speed() const override{
        cout << "This is a normal car 1st." << endl;
    }
};
class NormalCar_2 : public Car{
public:
    string name = "Normal Car 2nd";
    void speed() const override{
        cout << "This is a normal car 2nd." << endl;
    }
};

class Factory{
public:
    virtual Car* getCar(CarType) = 0;
};

class LuxuaryFactory: public Factory{
public:
    Car* getCar(CarType type){
        switch (type)
        {
        case CarType :: Luxury_1:
            return new LuxuryCar_1();
            break;
        case CarType :: Luxury_2:
            return new LuxuryCar_2();
            break;
        default:
            return NULL;
            break;
        }
    }
};
class NormalFactory: public Factory{
public:
    Car* getCar(CarType type){
        switch (type)
        {
        case CarType :: Normal_1:
            return new NormalCar_1();
            break;
        case CarType :: Normal_2:
            return new NormalCar_2();
            break;
        default:
            return NULL;
            break;
        }
    }
};

class UltimateFactory{
public:
    Factory* getFactory(string input){
        if(input == "L") return new LuxuaryFactory();
        if(input == "N") return new NormalFactory();
        return NULL;
    }
};

int main(){
    UltimateFactory* ultimate_f = new UltimateFactory();

    Factory* lf = ultimate_f->getFactory("L");
    Factory* nf = ultimate_f->getFactory("N");

    Car* l1 = lf->getCar(CarType::Luxury_1);
    Car* l2 = lf->getCar(CarType::Luxury_2);

    Car* n1 = nf->getCar(CarType::Normal_1);
    Car* n2 = nf->getCar(CarType::Normal_2);

    l1->speed();
    l2->speed();
    n1->speed();
    n2->speed();
}