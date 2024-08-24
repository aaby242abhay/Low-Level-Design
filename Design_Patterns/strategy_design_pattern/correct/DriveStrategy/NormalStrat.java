package Design_Patterns.strategy_design_pattern.correct.DriveStrategy;

public class NormalStrat implements DriveStrat{
    @Override
    public void drive(){
        System.out.println("Normal Drive strategy...");
    }
}
