package Design_Patterns.strategy_design_pattern.correct;

import Design_Patterns.strategy_design_pattern.correct.DriveStrategy.SportsStrat;

public class OffRoadVehicle extends Vehicle{
    OffRoadVehicle(){
        super(new SportsStrat());               //doing constructor injetion --> passing the object to the parent class
                                                        //so the child class could initialise the type of object they wanna call
    }
    
}
