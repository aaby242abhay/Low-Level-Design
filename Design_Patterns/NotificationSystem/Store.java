package Design_Patterns.NotificationSystem;

import Design_Patterns.NotificationSystem.Notifiable.IphoneNotificationObservable;
import Design_Patterns.NotificationSystem.Notifiable.MacbookNotificationObservable;
import Design_Patterns.NotificationSystem.Notifier.EmailAlertObserver;
import Design_Patterns.NotificationSystem.Notifier.NotificationAlertObserver;
import Design_Patterns.NotificationSystem.Notifier.SMSAlertObserver;

public class Store {
    public static void main(String[] args) {
        System.out.println("Welcome to the Notification System");

        IphoneNotificationObservable iphoneObservable = new IphoneNotificationObservable();

        MacbookNotificationObservable macBookObservable = new MacbookNotificationObservable();

        NotificationAlertObserver iphoneUser1 = new EmailAlertObserver("aaby242abhay@gmail.com", iphoneObservable);
        NotificationAlertObserver iphoneUser2 = new SMSAlertObserver("0804102423", iphoneObservable);

        NotificationAlertObserver macUser1 = new EmailAlertObserver("abhay242pratap@gmail.com", macBookObservable);
        NotificationAlertObserver macUser2 = new SMSAlertObserver("4274819423", macBookObservable);

        iphoneObservable.add(iphoneUser1);
        iphoneObservable.add(iphoneUser2);

        macBookObservable.add(macUser1);
        macBookObservable.add(macUser2);

        iphoneObservable.setItemCount(10);
        macBookObservable.setItemCount(22);        
    }
}
