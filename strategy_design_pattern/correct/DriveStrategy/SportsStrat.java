package strategy_design_pattern.correct.DriveStrategy;

public class SportsStrat implements DriveStrat{
    @Override
    public void drive(){
        System.out.println("Sports Drive strategy...");
    }
}
