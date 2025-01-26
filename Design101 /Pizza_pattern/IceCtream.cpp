#include<bits/stdc++.h>
using namespace std;

class IceCreamBase{
public:
    virtual double cost() = 0;
};

class MilkIceCream : public IceCreamBase{
public:
    double MilkIceCreamCost = 1000;
    double cost() override{
        return MilkIceCreamCost;
    }
};

class AlmondIceCream : public IceCreamBase{
public:
    double AlmondIceCreamCost = 2000;
    double cost() override{
        return AlmondIceCreamCost;
    }
};

class IceCreamTopping : public IceCreamBase{        //IceCreamTopping IS-A IceCreamBase
public:
    IceCreamBase *iceCream;         //IceCreamTopping HAS-A IceCreamBase
    virtual double cost() = 0;      
};

class ChocolateIceCream : public IceCreamTopping{
public:
    ChocolateIceCream(IceCreamBase* iceCream){
        this->iceCream = iceCream;
    }
    double ChocolateCost = 100;
    double cost() override{
        return this->iceCream->cost() + ChocolateCost;
    }
};

class CheeryIceCream : public IceCreamTopping{
public:
    CheeryIceCream(IceCreamBase* iceCream){
        this->iceCream = iceCream;
    }
    double CherryCost = 20;
    double cost() override{
        return this->iceCream->cost() + CherryCost;
    }
};

int main(){
    IceCreamBase* myIceCream = new ChocolateIceCream( new CheeryIceCream(new AlmondIceCream()));
    cout << "The cost of my Chocolate_Cherry_IceCream is : " << myIceCream->cost() << endl;
    return 0;
}