#include <cassert>
#include <stdio.h>
#include <unordered_map>
#include <string>

class Vehicle {

protected:
  int wheels;
  int maxSpeed;
  int currentSpeed;
  double position;

public:
  int getWheels() { return wheels; }

  int getMaxSpeed() { return maxSpeed; }

  int getCurrentSpeed() { return currentSpeed; }

  int getPosition() { return position; }

  void setSpeed(int input) {
    if (input <= maxSpeed)
      currentSpeed = currentSpeed + input;
    else
      currentSpeed = maxSpeed;
  }

  void move(double time) { position = position + (currentSpeed * time) / 60; }

  Vehicle(int wheels, int maxSpeed, int currentSpeed, int position)
      : wheels(wheels), maxSpeed(maxSpeed), currentSpeed(currentSpeed),
        position(position) {}
};

class Car : public Vehicle {
protected:
  Car(int maxSpeed) : Vehicle(4, maxSpeed, 0, 0) {}
  Car() : Vehicle(4, 140, 0, 0) {}
};

class Ambulance : public Car {
private:
  bool BlueLightOn = false;

public:
  Ambulance() : Car(140) {}

  bool isBlueLightOn() { return BlueLightOn; }

  void switchBlueLight() {
    if (BlueLightOn == true)
      BlueLightOn = false;
    else
      BlueLightOn = true;
  }
};

class PassengerCar : public Car {

public:
  PassengerCar() : Car(140) {}
  PassengerCar(int tempo): Car(tempo){}
};

class RacingCar : public Car {
public:
  RacingCar() : Car(200) {}
};

class Bicycle : public Vehicle {
public:
  Bicycle() : Vehicle(2, 20, 0, 0) {}
};

void Race(){
	std::unordered_map<std::string, Vehicle> table;
	Bicycle Guy;
	PassengerCar VW(150);
	RacingCar Rimac;
	Ambulance ambulance;
	table.emplace("RacingCar", Rimac);
	table.emplace("Bicycle", Guy);
	table.emplace("Ambulance",ambulance);
	table.emplace("PassengerCar", VW);
	table.at("Bicycle").setSpeed(20);
	table.at("PassengerCar").setSpeed(150);
	table.at("RacingCar").setSpeed(200);
	table.at("Ambulance").setSpeed(80);
	table.at("Bicycle").move(240);
	printf("%d\n", table.at("PassengerCar").getCurrentSpeed());
	for(int i = 0; i<4; i++){
		table.at("Bicycle").move(15);
		table.at("PassengerCar").move(15);
		table.at("Ambulance").move(15);
		table.at("RacingCar").move(15);
		printf("position of ambulance: %d\n", table.at("Ambulance").getPosition());
		printf("position of bicycle: %d\n", table.at("Bicycle").getPosition());
		printf("position of passenger car: %d\n", table.at("PassengerCar").getPosition());
		printf("position of racing car: %d\n\n", table.at("RacingCar").getPosition());
	}
	

}


int main() {

  printf("starting\n");
  Race();
  Ambulance ambulance;
  assert(ambulance.getWheels() == 4);
  assert(ambulance.getMaxSpeed() == 140);
  assert(ambulance.getCurrentSpeed() == 0);
  assert(ambulance.getPosition() == 0);
  ambulance.setSpeed(100);
  assert(ambulance.getCurrentSpeed() == 100);
  ambulance.move(60);
  ambulance.move(60);
  assert(ambulance.getPosition() == 200);
  ambulance.setSpeed(200);
  assert(ambulance.getCurrentSpeed() == ambulance.getMaxSpeed());
  assert(!ambulance.isBlueLightOn());
  ambulance.switchBlueLight();
  assert(ambulance.isBlueLightOn());
  printf("Test Ambulance\t...passed\n");
  PassengerCar Honda_Civic;
  assert(Honda_Civic.getWheels() == 4);
  assert(Honda_Civic.getMaxSpeed() == 140);
  Honda_Civic.setSpeed(120);
  Honda_Civic.move(50);
  assert(Honda_Civic.getPosition() == 100);
  printf("Test Passenger Car\t...passed\n");
  RacingCar Corolla_GR;
  assert(Corolla_GR.getMaxSpeed() > Honda_Civic.getMaxSpeed());
  Corolla_GR.setSpeed(300);
  Honda_Civic.setSpeed(300);
  assert(Corolla_GR.getMaxSpeed() > Honda_Civic.getMaxSpeed());
  printf("Test Racing Car\t...passed\n");
  Bicycle Rad;
  assert(Rad.getWheels() == 2 && Rad.getWheels() < Honda_Civic.getWheels());
  assert(Rad.getMaxSpeed() < Corolla_GR.getMaxSpeed() &&
         Rad.getMaxSpeed() < Honda_Civic.getMaxSpeed());
  Rad.setSpeed(Rad.getMaxSpeed());
  Corolla_GR.move(60);
  Rad.move(180);
  assert(Rad.getPosition() < Corolla_GR.getPosition());
  printf("Test Bicycle\t...passed\n");
  printf("Finished\n");
  return 0;
}