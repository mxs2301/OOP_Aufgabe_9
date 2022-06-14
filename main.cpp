#include<stdio.h>
#include<cassert>

class Vehicle{

protected:
	int wheels;
	int maxSpeed;
	int currentSpeed;
	int position;

public:
	int getWheels(){
		return wheels;
	}

	int getMaxSpeed(){
		return maxSpeed;
	}

	int getCurrentSpeed(){
		return currentSpeed;
	}

	int getPosition(){
		return position;
	}

	void setSpeed(int input){
		if(input<=maxSpeed)
		currentSpeed = currentSpeed + input;
		else
		currentSpeed = maxSpeed;
	}

	void move(int time){
			position = position + (currentSpeed * time)/60;
	}

	Vehicle(int wheels, int maxSpeed, int currentSpeed, int position):
	wheels(wheels),
	maxSpeed(maxSpeed),
	currentSpeed(currentSpeed),
	position(position)
	{}
};

class Car : public Vehicle{
protected:
	Car(int maxSpeed): Vehicle(4, maxSpeed, 0, 0){}
	Car(): Vehicle(4, 140, 0, 0){}
};

class Ambulance : public Car{
private:
	bool BlueLightOn = false;

public:
	Ambulance():Car(140){}

	bool isBlueLightOn(){
		return BlueLightOn;
	}

	void switchBlueLight(){
		if(BlueLightOn == true)
			BlueLightOn = false;
		else
			BlueLightOn = true;
	}
};

class PassengerCar : public Car{

public:
	PassengerCar():Car(140){}
};

class RacingCar : public Car{
public:
	RacingCar():Car(200){}
};

class Bicycle : public Vehicle{
public:
	Bicycle():Vehicle(2, 20, 0, 0){}
};

int main(){


  printf("starting\n");
  
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
	assert(Corolla_GR.getMaxSpeed()>Honda_Civic.getMaxSpeed());
	Corolla_GR.setSpeed(300);
	Honda_Civic.setSpeed(300);
	assert(Corolla_GR.getMaxSpeed()>Honda_Civic.getMaxSpeed());
	printf("Test Racing Car\t...passed\n");
	Bicycle Rad;
	assert(Rad.getWheels() == 2 && Rad.getWheels()< Honda_Civic.getWheels());
	assert(Rad.getMaxSpeed() < Corolla_GR.getMaxSpeed() && Rad.getMaxSpeed() < Honda_Civic.getMaxSpeed());
	Rad.setSpeed(Rad.getMaxSpeed());
	Corolla_GR.move(60);
	Rad.move(180);
	assert(Rad.getPosition()<Corolla_GR.getPosition());
	printf("Test Bicycle\t...passed\n");
  printf("Finished\n");
  return 0;
}