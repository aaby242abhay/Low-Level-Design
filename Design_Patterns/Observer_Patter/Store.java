package Design_Patterns.Observer_Patter;

import Design_Patterns.Observer_Patter.Observable.IpohoneObservableImpl;
import Design_Patterns.Observer_Patter.Observable.StockObserable;
import Design_Patterns.Observer_Patter.Observer.EmailAlertObserverImpl;
import Design_Patterns.Observer_Patter.Observer.MobileAlertObserverImpl;
import Design_Patterns.Observer_Patter.Observer.NotificationAlertObserver;

public class Store {
    public static void main(String[] args) {

        StockObserable iphoneStockObservable = new IpohoneObservableImpl();

        NotificationAlertObserver user1 = new EmailAlertObserverImpl("user1@gmail.com", iphoneStockObservable);
        NotificationAlertObserver user2 = new EmailAlertObserverImpl("user2@gmail.com", iphoneStockObservable);
        NotificationAlertObserver user3 = new EmailAlertObserverImpl("user3@gmail.com", iphoneStockObservable);

        NotificationAlertObserver user4 = new MobileAlertObserverImpl("1234123412", iphoneStockObservable);
        NotificationAlertObserver user5 = new MobileAlertObserverImpl("1234123413", iphoneStockObservable);

        iphoneStockObservable.add(user1);
        iphoneStockObservable.add(user2);
        iphoneStockObservable.add(user3);
        iphoneStockObservable.add(user4);
        iphoneStockObservable.add(user5);

        iphoneStockObservable.remove(user1);

        iphoneStockObservable.setStockCount(10);
    }

}
