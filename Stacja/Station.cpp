#include "Station.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

string Station::getFieldValue(const Train* train, const string& fieldName)
{
	if (fieldName == "name")
	{
		return train->getName();
	}

	else if (fieldName == "source")
	{
		return train->getSource();
	}

	else if (fieldName == "destination")
	{
		return train->getDestination();
	}

	else if (fieldName == "status")
	{
		return train->getStatus();
	}
}

void Station::addTrain(Train* train)
{
	trains.push_back(train);
}

void Station::displayTrainsInfo() const
{
	cout << "Nazwa " << "ród³o " << "Cel " << "Status " << "OpóŸnienie " << "Godzina " << "Dodatkowe" << endl;
	for (const auto& train : trains)
	{
		train->printInfo();
	}
	cout << endl;
}

void Station::removeTrain(int index)
{
	if (index < trains.size())
	{
		delete trains[index];
		trains.erase(trains.begin() + index);
	}
	else
	{
		cerr << "Niepoprawny zakres!" << endl;
	}
}

void Station::removeAllTrains()
{
	for (const auto& train : trains)
	{
		delete train;
	}
	trains.clear();
}

int Station::getNumberOfTrains() const
{
	return trains.size();
}

Train* Station::getTrain(int index)
{
	if (index < trains.size())
	{
		return trains[index];
	}

	else
	{
		return nullptr;
	}
}

void Station::sortByField(const string& fieldName)
{
	sort(trains.begin(), trains.end(), [fieldName](Train* a, Train* b)
		{
			if (fieldName == "delay")
			{
				return a->getDelay() < b->getDelay();
			}

			else if (fieldName == "name")
			{
				return a->getName() < b->getName();
			}

			else if (fieldName == "source")
			{
				return a->getSource() < b->getSource();
			}

			else if (fieldName == "destination")
			{
				return a->getDestination() < b->getDestination();
			}

			else if (fieldName == "status")
			{
				return a->getStatus() < b->getStatus();
			}

			return false;
		});
}

void Station::saveToFile(ofstream& file)
{
	char* wsk;
	int numTrains = trains.size();
	//char type;

	file.write(reinterpret_cast<char*>(&numTrains), sizeof(numTrains));

	for (const auto& train : trains)
	{
		wsk = train->toBinary();

		if (file.is_open())
		{
			file.write(wsk, wsk[0]);

			train->clearBinData();
		}
	}
	file.close();
}

void Station::loadFromFile(ifstream& file)
{
	char* wsk;

	try
	{
		if (!file.is_open())
		{
			throw runtime_error("Nie mozna otworzyc pliku");
		}
	}
	catch (const exception& e)
	{
		cerr << "Wystapil blad podczas obslugi pliku " << e.what() << endl;
	}

	int size;
	int numTrains;

	file.read((char*)&numTrains, sizeof(int));

	for (int i = 0; i < numTrains; i++)
	{
		file.read((char*)&size, sizeof(int));
		wsk = new char[size - sizeof(int)];

		file.read(wsk, size - sizeof(int));

		if (wsk[0] == 1)
		{
			PassengerTrain t(wsk + 1);
			t.printInfo();
		}

		else
		{
			CargoTrain t(wsk + 1);
			t.printInfo();
		}

		delete[] wsk;
	}

	file.close();
}

void Station::filterTrains(const string& fieldName, const string& value)
{
	vector<Train*> filteredTrains;

	for (const auto& train : trains)
	{
		if (getFieldValue(train, fieldName) == value)
		{
			filteredTrains.push_back(train);
		}
	}

	for (const auto& filteredTrain : filteredTrains)
	{
		filteredTrain->printInfo();
	}
}

void Station::operator+=(Train* train)
{
	addTrain(train);
}

Train* Station::operator[](int index)
{
	return getTrain(index);
}

void Station::operator--()
{
	if (!trains.empty())
	{
		removeTrain(trains.size() - 1);
	}
}

void Station::filterTrains(int value)
{
	vector<Train*> filteredTrains;

	for (const auto& train : trains)
	{
		if (train->getDelay() == value)
		{
			filteredTrains.push_back(train);
		}
	}

	for (const auto& filteredTrain : filteredTrains)
	{
		filteredTrain->printInfo();
	}
}

ostream& operator<<(ostream& stream, const Station& station)
{
	stream << "Stacja zawiera nastepujace pociagi: " << endl;

	for (const Train* train : station.trains)
	{
		stream << *train;
	}

	return stream;
}

istream& operator>>(istream& stream, Station& station)
{
	int numberOfTrains;
	cout << "Podaj liczbê poci¹gów: ";
	stream >> numberOfTrains;

	for (int i = 0; i < numberOfTrains; i++)
	{
		char trainType;
		cout << "Podaj typ poci¹gu (P - pasa¿erski, C - towarowy): ";
		stream >> trainType;

		Train* newTrain = nullptr;

		if (trainType == 'P')
		{
			newTrain = new PassengerTrain();
		}
		else if (trainType == 'C')
		{
			newTrain = new CargoTrain();
		}
		else
		{
			cerr << "B³¹d: Nieznany typ poci¹gu.\n";
			continue;
		}

		newTrain->readFromStream(stream);
		station.addTrain(newTrain);
	}

	return stream;
}

