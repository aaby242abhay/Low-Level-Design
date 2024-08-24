package Design_Patterns.Observer_Patter.Observer;

import Design_Patterns.Observer_Patter.Observable.StockObserable;

public class MobileAlertObserverImpl implements NotificationAlertObserver{
    String phoneNo;
    StockObserable observable;

    public MobileAlertObserverImpl(String phoneNo, StockObserable observable){
        this.phoneNo = phoneNo;
        this.observable = observable;
    }

    @Override
    public void update(){
        sendMsgOnMobile(phoneNo, "Stock is back");
    }
    public void sendMsgOnMobile(String phoneNo, String msg){
        System.out.println("SMS sent to "+phoneNo+" with message: "+msg);
    }
}
