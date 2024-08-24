package strategy_design_pattern.correct;

import strategy_design_pattern.correct.DriveStrategy.NormalStrat;

public class PassengerVehicle extends Vehicle{
    
    PassengerVehicle(){
        super(new NormalStrat());
    }
    
}
