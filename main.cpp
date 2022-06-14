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
		if(time == 60)
			position = position + currentSpeed;
	}

	Vehicle(int wheels, int maxSpeed, int currentSpeed, int position):
	wheels(wheels),
	maxSpeed(maxSpeed),
	currentSpeed(currentSpeed),
	position(position)
	{}
};

class Car : public Vehicle{
public:
	Car(): Vehicle(4, 140, 0, 0){}
	Car(): 
};

class Ambulance : public Car{
private:
	bool BlueLightOn = false;

public:
	Ambulance():Car(){}

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

  printf("Finished\n");
  return 0;
}