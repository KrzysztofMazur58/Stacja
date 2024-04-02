#include "CargoTrain.h"
#include <iostream>

using namespace std;

CargoTrain::CargoTrain()
	:Train("X", "A", "B", "-", 0, 0, 0), cargoCapacity(0)
{

}

CargoTrain::CargoTrain(const string& name, const string& source, const string& destination, const string& status, int delay, int departureHour, int departureMinutes, double cargoCapacity)
	:Train(name, source, destination, status, delay, departureHour, departureMinutes), cargoCapacity(cargoCapacity)
{

}

CargoTrain::CargoTrain(char* inData)
{
	memcpy(&delay, inData, sizeof(delay)); inData += sizeof(delay);

	memcpy(&departureTime.hour, inData, sizeof(departureTime.hour));
	inData += sizeof(departureTime.hour);

	memcpy(&departureTime.minutes, inData, sizeof(departureTime.minutes));
	inData += sizeof(departureTime.minutes);

	// Pomiñ dwukropek
	inData++;
	name = inData; inData += name.size() + 1;
	source = inData; inData += source.size() + 1;
	destination = inData; inData += destination.size() + 1;
	status = inData; inData += status.size() + 1;

	memcpy(&cargoCapacity, inData, sizeof(cargoCapacity));
}

CargoTrain::~CargoTrain()
{
}

void CargoTrain::setCargoCapacity(double cargoCapacity)
{
	this->cargoCapacity = cargoCapacity;
}

double CargoTrain::getCargoCapacity() const
{
	return cargoCapacity;
}

void CargoTrain::printInfo() const
{
	Train::printInfo();
	cout << cargoCapacity << endl;
}

void CargoTrain::readFromStream(istream& stream)
{
	Train::readFromStream(stream);

	cout << "Podaj pojemnosc poci¹gu: ";
	stream >> cargoCapacity;
}

char* CargoTrain::toBinary()
{
	char* commonData = Train::toBinary();
	int commonSize;

	commonData[4] = 2;

	memcpy(&commonSize, commonData, sizeof(int));
	int size = commonSize + sizeof(double);

	try
	{
		char* temp = new char[size] {};
		memcpy(temp, commonData, commonSize);

		delete[] commonData;
		binData = temp;
	}
	catch (const std::bad_alloc& e)
	{
		// Obs³uga b³êdu alokacji pamiêci
		cerr << "B³¹d alokacji pamiêci: " << e.what() << std::endl;
	}

	memcpy(binData + commonSize, &cargoCapacity, sizeof(cargoCapacity));
	memcpy(binData, &size, sizeof(int));

	return binData;
}

/*istream& operator>>(istream& stream, CargoTrain& cargoTrain)
{
	stream >> static_cast<Train&>(cargoTrain);

	cout << "Podaj pojemnosc pociagu: ";
	stream >> cargoTrain.cargoCapacity;

	return stream;
}*/

