#include "Train.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

Train::Train()
	:name("X"), source("A"), destination("B"), status("-"), delay(0), departureTime{ 0,0 }
{
}

Train::Train(const string& name, const string& source, const string& destination, const string& status, int delay, int departureHour, int departureMinutes)
	:name(name), source(source), destination(destination), status(status)
{
	setDelay(delay);
	setDepartureHour(departureHour);
	setDepartureMinutes(departureMinutes);
}

void Train::printInfo() const
{
	cout << endl << name << "  " << source << "  " << destination << "  " << status << "  " << delay << "  "
		<< departureTime.hour << ":" << setw(2) << setfill('0') << departureTime.minutes << "  ";
}

void Train::readFromStream(istream& stream)
{
	getchar();
	cout << "Podaj nazwê poci¹gu: ";
	getline(stream, name);

	cout << "Podaj Ÿród³o: ";
	getline(stream, source);

	cout << "Podaj cel: ";
	getline(stream, destination);

	cout << "Podaj status: ";
	getline(stream, status);

	cout << "Podaj opóŸnienie: ";
	stream >> delay;

	cout << "Podaj godzinê odjazdu: ";
	stream >> departureTime.hour;

	cout << "Podaj minutê odjazdu: ";
	stream >> departureTime.minutes;
}

void Train::setName(const string& name)
{
	this->name = name;
}

void Train::setSource(const string& source)
{
	this->source = source;
}

void Train::setDestination(const string& destination)
{
	this->destination = destination;
}

void Train::setStatus(const string& status)
{
	this->status = status;
}

void Train::setDelay(int delay)
{
	if (delay < 3000)
	{
		this->delay = delay;
	}
	else
	{
		this->delay = 0;
	}
}

void Train::setDepartureHour(int hour)
{
	if (hour >= 0 && hour <= 23)
	{
		departureTime.hour = hour;
	}
	else
	{
		departureTime.hour = 0;
	}
}

void Train::setDepartureMinutes(int minutes)
{
	if (minutes >= 0 && minutes <= 59)
	{
		departureTime.minutes = minutes;
	}
	else
	{
		departureTime.minutes = 0;
	}
}

string Train::getName() const
{
	return name;
}

string Train::getSource() const
{
	return source;
}

string Train::getDestination() const
{
	return destination;
}

string Train::getStatus() const
{
	return status;
}

int Train::getDelay() const
{
	return delay;
}

int Train::getDepartureHour() const
{
	return departureTime.hour;
}

int Train::getDepartureMinutes() const
{
	return departureTime.minutes;
}

char* Train::toBinary()
{
	int size = 4 * sizeof(int) + (name.size() + 1) + (source.size() + 1) + (destination.size() + 1) + (status.size() + 1) + 1 + 1; //na typ poci¹gu

	try
	{
		binData = new char[size] {};
	}

	catch (const bad_alloc& e)
	{
		// Obs³uga b³êdu alokacji pamiêci
		cerr << "B³¹d alokacji pamiêci: " << e.what() << std::endl;
	}
	char* temp = binData;

	memcpy(temp, &size, sizeof(size)); temp += sizeof(size) + 1;
	binData[4] = 0;
	memcpy(temp, &delay, sizeof(delay)); temp += sizeof(delay);

	memcpy(temp, &departureTime.hour, sizeof(departureTime.hour));
	temp += sizeof(departureTime.hour);

	memcpy(temp, &departureTime.minutes, sizeof(departureTime.minutes));
	temp += sizeof(departureTime.minutes);

	*temp++ = ':';

	memcpy(temp, name.c_str(), name.size()); temp += name.size() + 1;
	memcpy(temp, source.c_str(), source.size()); temp += source.size() + 1;
	memcpy(temp, destination.c_str(), destination.size()); temp += destination.size() + 1;
	memcpy(temp, status.c_str(), status.size()); temp += status.size() + 1;

	//assert(binData + size == temp);
	return binData;
}

void Train::clearBinData()
{
	if (binData != nullptr)
	{
		delete[] binData;
		binData = nullptr;
	}
}

Train::Train(char* inData)
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
}

Train::~Train()
{
	clearBinData();
}

ostream& operator<<(ostream& stream, const Train& train)
{
	train.printInfo();
	return stream;
}

/*istream& operator>>(istream& stream, Train& train)
{
	getchar();
	cout << "Podaj nazwê poci¹gu: ";
	getline(stream, train.name);

	cout << "Podaj Ÿród³o: ";
	getline(stream, train.source);

	cout << "Podaj cel: ";
	getline(stream, train.destination);

	cout << "Podaj status: ";
	getline(stream, train.status);

	cout << "Podaj opóŸnienie: ";
	stream >> train.delay;

	cout << "Podaj godzinê odjazdu: ";
	stream >> train.departureTime.hour;

	cout << "Podaj minutê odjazdu: ";
	stream >> train.departureTime.minutes;

	return stream;
}*/


