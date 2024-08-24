package Design_Patterns.Observer_Patter.Observable;

import java.util.List;

import Design_Patterns.Observer_Patter.Observer.NotificationAlertObserver;

import java.util.ArrayList;

public class IpohoneObservableImpl implements StockObserable{

    public List<NotificationAlertObserver> observerList = new ArrayList<>();
    public int stockCount = 0;

    @Override
    public void add(NotificationAlertObserver observer){
        observerList.add(observer);
    }

    @Override
    public void remove(NotificationAlertObserver observer){
        observerList.remove(observer);
    }

    @Override
    public void notifySubscribers(){
        for(NotificationAlertObserver observer : observerList){
            observer.update();
        }
    }

    @Override
    public void setStockCount(int newStockAdded){
        if(stockCount == 0){
            notifySubscribers();
        }
        stockCount += newStockAdded;
    }

    @Override
    public int getStockCount(){
        return stockCount;
    }

}
