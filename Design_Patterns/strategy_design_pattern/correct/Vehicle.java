package Design_Patterns.strategy_design_pattern.correct;

import Design_Patterns.strategy_design_pattern.correct.DriveStrategy.DriveStrat;

public class Vehicle {
    DriveStrat driveObject;          //object of the interface is being made in the Vehicle Class

    //this is known as constructor injection
    //this would not be called in this class but by the child classes of this class while calling for this function

    Vehicle(DriveStrat driveObj){
        this.driveObject = driveObj;
    }
    public void drive(){
        driveObject.drive();
    }
    
}
