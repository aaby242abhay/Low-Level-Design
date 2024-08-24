package strategy_design_pattern.correct;

public class Main {
    public static void main(String args[]){
        Vehicle mazzarati = new SportsVehicle();
        Vehicle alto = new PassengerVehicle();
        Vehicle rocket = new SuperSonicVehicle();
        rocket.drive();
        alto.drive();
        mazzarati.drive();
    }
}
