package Design_Patterns.NotificationSystem.Notifiable;

import Design_Patterns.NotificationSystem.Notifier.NotificationAlertObserver;

public interface NotificationObservable {

    public void add(NotificationAlertObserver observer);
    public void remove(NotificationAlertObserver observer);

    public void notifySubscribers();

    public void setItemCount(int newCountAdded);
    public int getItemCount();

}
