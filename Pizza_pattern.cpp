//to avoid class explosion
//it has a base pizza and it itself is a base pizza
#include<bits/stdc++.h> 
using namespace std;

class BasePizza{
public:
    virtual double cost() = 0;
};

class MarghPizza : public BasePizza{
public:
    double marghCost = 100;
    double cost() override{
        return marghCost;
    }
};

class FarmHousePizza : public BasePizza{
public:
    double farmHouseCost = 200;
    double cost() override{
        return farmHouseCost;
    }
};

class VegDelightPizza : public BasePizza{
public :
    double vegDelightCost = 300;
    double cost() override{
        return vegDelightCost;
    }
};

class ToppingDecorator : public BasePizza{      //ToppingPizza IS-A BasePizza
public:
    BasePizza *basePizza;               //ToppingPizza HAS-A BasePizza
    virtual double cost() = 0;
};

class CheeseTopping : public ToppingDecorator{
public:
    double CheeseCost = 19;
    CheeseTopping(BasePizza *basePizza){
        this->basePizza = basePizza;
    }
    double cost() override{
        return this->basePizza->cost() + CheeseCost;
    }
};

class MushRoomTopping : public ToppingDecorator{
public:
    double MushroomCost = 29;
    MushRoomTopping(BasePizza *basePizza){
        this->basePizza = basePizza;
    }
    double cost() override{
        return this->basePizza->cost() + MushroomCost;
    }
};

int main(){
    //and this is how we can create a pizza with multiple toppings without class explosion
    BasePizza *mushroomCheeseMarghPizza = new MushRoomTopping(new CheeseTopping(new MarghPizza()));
    cout << "Mushroom Cheese MarghPizza cost: " << mushroomCheeseMarghPizza->cost() << endl;
    return 0;
}