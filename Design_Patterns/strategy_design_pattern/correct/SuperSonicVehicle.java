package Design_Patterns.strategy_design_pattern.correct;

import Design_Patterns.strategy_design_pattern.correct.DriveStrategy.SuperSonicStrat;

public class SuperSonicVehicle extends Vehicle{
    SuperSonicVehicle(){
        super( new SuperSonicStrat());
    }
    
}
