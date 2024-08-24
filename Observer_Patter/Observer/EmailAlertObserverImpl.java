package Observer_Patter.Observer;

import Observer_Patter.Observable.StockObserable;

public class EmailAlertObserverImpl implements NotificationAlertObserver{

    String emailId;

    StockObserable observable;
    public EmailAlertObserverImpl(String emailId, StockObserable observable){
        this.emailId = emailId;
        this.observable = observable;
    }

    @Override
    public void update(){
        sendMail(emailId,"Stock is back");
    }
    public void sendMail(String emailId, String msg){
        System.out.println("Email sent to "+emailId+" with message: "+msg);
    }


}
