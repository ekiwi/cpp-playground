#include <iostream>
#include <cstring>

struct Vehicle
{
	Vehicle(std::string name, int w, int s) : name(name), numberOfWheels(w), speed(s) {}
	std::string name;
	int numberOfWheels;
	int speed;
	void print() {
		std::cout << name << ": speed=" << speed << "; numberOfWheels=" << numberOfWheels << std::endl;
	}
};

struct VehicleOwner
{
	VehicleOwner(std::string name, Vehicle& vehicle) : name(name), vehicle(vehicle) {}
	std::string name;
	Vehicle& vehicle;
	void print() {
		std::cout << name << ":" << std::endl;
		vehicle.print();
	}
	void setVehicleSpeed(int speed) {
		vehicle.speed = speed;
	}
};

Vehicle car("car", 4, 0);
VehicleOwner owner("owner", car);

int main()
{
	car.print();
	owner.print();
	std::cout << "owner.setVehicleSpeed(3);" << std::endl;
	owner.setVehicleSpeed(3);
	car.print();
	owner.print();
}
