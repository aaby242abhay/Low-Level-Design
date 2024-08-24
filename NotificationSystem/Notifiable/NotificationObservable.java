package NotificationSystem.Notifiable;

import NotificationSystem.Notifier.NotificationAlertObserver;

public interface NotificationObservable {

    public void add(NotificationAlertObserver observer);
    public void remove(NotificationAlertObserver observer);

    public void notifySubscribers();

    public void setItemCount(int newCountAdded);
    public int getItemCount();

}
