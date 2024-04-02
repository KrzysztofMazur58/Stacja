#include "PassengerTrain.h"
#include <iostream>

using namespace std;

PassengerTrain::PassengerTrain()
	:Train("X", "A", "B", "-", 0, 0, 0), numberOfSeats(0)
{

}

PassengerTrain::PassengerTrain(const string& name, const string& source, const string& destination, const string& status, int delay, int departureHour, int departureMinutes, int numberOfSeats)
	:Train(name, source, destination, status, delay, departureHour, departureMinutes), numberOfSeats(numberOfSeats)
{

}

PassengerTrain::PassengerTrain(char* inData)
{
	memcpy(&delay, inData, sizeof(delay)); inData += sizeof(delay);
	memcpy(&departureTime.hour, inData, sizeof(departureTime.hour));
	inData += sizeof(departureTime.hour);

	memcpy(&departureTime.minutes, inData, sizeof(departureTime.minutes));
	inData += sizeof(departureTime.minutes);

	//dwukropek
	inData++;
	name = inData; inData += name.size() + 1;
	source = inData; inData += source.size() + 1;
	destination = inData; inData += destination.size() + 1;
	status = inData; inData += status.size() + 1;

	memcpy(&numberOfSeats, inData, sizeof(numberOfSeats));
}

PassengerTrain::~PassengerTrain()
{

}

void PassengerTrain::setNumberOfSeats(int numberOfSeats)
{
	this->numberOfSeats = numberOfSeats;
}

int PassengerTrain::getNumberOfSeats() const
{
	return numberOfSeats;
}

void PassengerTrain::printInfo() const
{
	Train::printInfo();
	cout << numberOfSeats << endl;
}

void PassengerTrain::readFromStream(istream& stream)
{
	Train::readFromStream(stream);

	cout << "Podaj liczbê miejsc w poci¹gu pasa¿erskim: ";
	stream >> numberOfSeats;
}

char* PassengerTrain::toBinary()
{
	char* commonData = Train::toBinary();
	int commonSize;

	commonData[4] = 1; //koretka typu poci¹gu

	memcpy(&commonSize, commonData, sizeof(int));
	int size = commonSize + sizeof(int);

	try
	{
		char* temp = new char[size] {};
		memcpy(temp, commonData, commonSize);

		delete[] commonData;
		binData = temp;
	}
	catch (const bad_alloc& e)
	{
		// Obs³uga b³êdu alokacji pamiêci
		cerr << "B³¹d alokacji pamiêci: " << e.what() << std::endl;
	}

	memcpy(binData + commonSize, &numberOfSeats, sizeof(numberOfSeats));
	memcpy(binData, &size, sizeof(int));

	return binData;
}

//istream& operator>>(istream& stream, PassengerTrain& passengerTrain)
//{   
	//stream >> static_cast<Train&>(passengerTrain);

	//cout << "Podaj ilosc miejsc: ";
	//stream >> passengerTrain.numberOfSeats;

	//return stream;
//}

