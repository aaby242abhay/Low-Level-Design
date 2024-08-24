package Design_Patterns.NotificationSystem.Notifiable;
import java.util.*;

import Design_Patterns.NotificationSystem.Notifier.NotificationAlertObserver;

public class IphoneNotificationObservable implements NotificationObservable{

    List<NotificationAlertObserver> observersList = new ArrayList<>();
    public int itemCount = 0;

    @Override
    public void add(NotificationAlertObserver observer){
        observersList.add(observer);
    }

    @Override
    public void remove(NotificationAlertObserver observer){
        observersList.remove(observer);
    }

    @Override
    public void notifySubscribers(){
        for(NotificationAlertObserver obj : observersList){
            obj.update();
        }
    }

    @Override
    public void setItemCount(int newCountAdded){
        if(itemCount == 0){
            notifySubscribers();
        }
        itemCount += newCountAdded;
    }

    @Override
    public int getItemCount(){
        return itemCount;
    }


}
