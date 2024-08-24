package Design_Patterns.strategy_design_pattern.incorrect;

public class OffRoadVehicle extends Vehicle{
    @Override
    public void drive(){
        //different drive login in the child class
        System.out.println("Sports Drive capability");
    }
}