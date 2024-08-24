package Design_Patterns.NotificationSystem.Notifier;

import Design_Patterns.NotificationSystem.Notifiable.NotificationObservable;

public class EmailAlertObserver implements NotificationAlertObserver{

    NotificationObservable observable;
    String emailId;

    public EmailAlertObserver(String emailId, NotificationObservable observable){
        this.emailId = emailId;
        this.observable = observable;
    }

    public void update(){
        sendEmails(emailId, "New stock has been added");
    }

    public void sendEmails(String emailId, String message){
        System.out.println("Email sent to: " + emailId + " with message: " + message);
    }
}
