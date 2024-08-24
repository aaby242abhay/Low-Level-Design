package Design_Patterns.strategy_design_pattern.correct;

import Design_Patterns.strategy_design_pattern.correct.DriveStrategy.SportsStrat;

public class SportsVehicle extends Vehicle {
    SportsVehicle(){
        super( new SportsStrat());              //object of the DriveStrat was being made in the Vehicle Class
    }                                           //object of the DriveStrat is being passed in the constructor of the Vehicle Class to initialise it
    
}
