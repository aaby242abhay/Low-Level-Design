package Design_Patterns.strategy_design_pattern.correct;

import Design_Patterns.strategy_design_pattern.correct.DriveStrategy.NormalStrat;

public class PassengerVehicle extends Vehicle{
    
    PassengerVehicle(){
        super(new NormalStrat());
    }
    
}
