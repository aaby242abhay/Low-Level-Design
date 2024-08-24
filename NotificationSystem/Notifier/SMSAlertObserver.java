package NotificationSystem.Notifier;

import NotificationSystem.Notifiable.NotificationObservable;

public class SMSAlertObserver implements NotificationAlertObserver{

    NotificationObservable observable;
    String phoneNumber;

    public SMSAlertObserver(String phoneNumber, NotificationObservable observable){
        this.phoneNumber = phoneNumber;
        this.observable = observable;
    }
    @Override
    public void update(){
        sendSMS("1234512345", "New Stock has been Added");
    }
    public void sendSMS(String phoneNumber, String msg){
        System.out.println("SMS sent to "+phoneNumber+" with message: "+msg);
    }

}
