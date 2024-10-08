package Design_Patterns.Observer_Patter.Observable;

import Design_Patterns.Observer_Patter.Observer.NotificationAlertObserver;

public interface StockObserable {
    public void add(NotificationAlertObserver observer);

    public void remove(NotificationAlertObserver observer);

    public void notifySubscribers();

    public void setStockCount(int newStockAdded);

    public int getStockCount();
}
