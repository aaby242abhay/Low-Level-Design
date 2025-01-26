#include <bits/stdc++.h>
using namespace std;

class Observable;

class Observer{
public:
    Observable* observable;
    virtual void update() = 0;
};

class Observable{
public:
    virtual void addObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObservers() = 0;
    virtual void setData(int data) = 0;
    virtual void getData() = 0;
};  


class WsObservable : public Observable{
public:
    int temp = 25;
    vector<Observer*> observersList;

    void addObserver(Observer *observer) override{
        observersList.push_back(observer);
    }
    void removeObserver(Observer *observer) override{
        observersList.erase(std::remove(observersList.begin(), observersList.end(), observer), observersList.end());
    }
    void notifyObservers() override{
        for(auto observer : observersList) {
            observer->update();
        }
    }
    void setData(int currTemp) override {
        temp = currTemp;
        notifyObservers();
    }
    void getData() override{
        cout << "Temperature is: " << temp << endl;
    }
};

class MobileObserver : public Observer{
public:
    WsObservable* wsObservable;
    MobileObserver(WsObservable* wsObservable){
        this->wsObservable = wsObservable;
    }
    void update(){
        cout << "Mobile Observer : Temp is " << wsObservable->temp << endl;
        wsObservable->getData();
    }
};

class TabletObserver : public Observer{
public:
    WsObservable *wsObservable;
    TabletObserver(WsObservable *wsObservable){
        this-> wsObservable = wsObservable;
    }
    void update(){
        cout << "Tablet Observer : Temp is " << wsObservable->temp << endl;
        wsObservable->getData();
    }
};

int main(){
    WsObservable* ws = new WsObservable();

    MobileObserver* m1 = new MobileObserver(ws);
    MobileObserver* m2 = new MobileObserver(ws);
    TabletObserver* t1 = new TabletObserver(ws);    
    TabletObserver* t2 = new TabletObserver(ws);

    ws->addObserver(m1);
    ws->addObserver(m2);

    ws->notifyObservers();
    ws->setData(30);

    ws->addObserver(t1);
    ws->addObserver(t2);

    ws->setData(35); 

    return 0;
}