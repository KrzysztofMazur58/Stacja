#include <iostream>
#include <fstream>
#include "Station.h"
#include "Train.h"
#include "PassengerTrain.h"
#include "CargoTrain.h"
#define MAIN

using namespace std;
//START
#ifdef MAIN
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");

    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " <station_name>" << endl;
        return 1;
    }

    string stationName = argv[1];

    cout << "Witamy na stacji: " << stationName << endl;

    Station station;

    int choice;
    do
    {
        cout << "========== Menu ==========\n";
        cout << "1. Dodaj pociąg\n";
        cout << "2. Wyświetl informacje o pociągach\n";
        cout << "3. Usuń pociąg\n";
        cout << "4. Usuń wszystkie pociągi\n";
        cout << "5. Pobierz liczbę pociągów\n";
        cout << "6. Sortuj pociągi \n";
        cout << "7. Zapisz do pliku\n";
        cout << "8. Wczytaj z pliku\n";
        cout << "9. Filtruj pociągi po polu (string)\n";
        cout << "10. Filtruj pociągi po polu (int)\n";
        cout << "11. Oblicz ostatnie pole (int)\n";
        cout << "12. Oblicz ostatnie pole (double)\n";
        cout << "0. Wyjście\n";
        cout << "==========================\n";
        cout << "Wybierz opcję: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cin >> station;
        
            break;
        }
        case 2: {
            // Wyświetl informacje o pociągach
            station.displayTrainsInfo();
            break;
        }
        case 3: {
            // Usuń pociąg
            int index;
            cout << "Pociąg o którym numerze chcesz usunąć?" << endl;
            cin >> index;

            station.removeTrain(index - 1);
            break;
        }
        case 4: {
            // Usuń wszystkie pociągi
            station.removeAllTrains();
            break;
        }
        case 5: {
            // Pobierz liczbę pociągów
            int numTrains = station.getNumberOfTrains();
            cout << "Liczba pociągów: " << numTrains << endl;
            break;
        }
        case 6: {
            // Sortuj pociągi
            int wybor;

            cout << "1. Nazwa" << endl;
            cout << "2. Stacja początkowa" << endl;
            cout << "3. Stacja końcowa" << endl;
            cout << "4. Status" << endl;
            cout << "5. Opóźnienie" << endl;
            cout << "Wybierz kategorię sortowania: ";
            cin >> wybor;

            switch (wybor) {
            case 1:
                station.sortByField("name");
                break;
            case 2:
                station.sortByField("source");
                break;
            case 3:
                station.sortByField("destination");
                break;
            case 4:
                station.sortByField("status");
                break;
            case 5:
                station.sortByField("delay");
                break;
            default:
                cout << "Nieprawidłowy wybór." << endl;
                break;
            }

            station.displayTrainsInfo();
            break;
        }
        case 7: {
            // Zapisz do pliku
            ofstream outputFile("trains.txt");
            station.saveToFile(outputFile);
            outputFile.close();
            break;
        }
        case 8: {
            // Wczytaj z pliku
            ifstream inputFile("trains.txt");
            station.loadFromFile(inputFile);
            inputFile.close();
            break;
        }
        case 9: {
            // Filtruj pociągi po polu (string)
            int wybor;
            string key;

            cout << "1. Nazwa" << endl;
            cout << "2. Stacja początkowa" << endl;
            cout << "3. Stacja końcowa" << endl;
            cout << "4. Status" << endl;

            cout << "Wybierz kategorię filtrowania: ";
            cin >> wybor;

            cout << "Wybierz klucz filtrowania: ";
            cin >> key;

            switch (wybor) {
            case 1:
                station.filterTrains("name", key);
                break;
            case 2:
                station.filterTrains("source", key);
                break;
            case 3:
                station.filterTrains("destination", key);
                break;
            case 4:
                station.filterTrains("status", key);
                break;

            default:
                cout << "Nieprawidłowy wybór." << endl;
                break;
            }

            break;
        }
        case 10: {
            // Filtruj pociągi po polu (int)
            int value;
            cout << "Podaj wartość pola (int): ";
            cin >> value;
            station.filterTrains(value);
            break;
        }
        case 11: {
            // Oblicz ostatnie pole (int)
            int result = station.calculateLastField<int>();
            cout << "Ostatnie pole (int): " << result << endl;
            break;
        }
        case 12: {
            // Oblicz ostatnie pole (double)
            double result = station.calculateLastField<double>();
            cout << "Ostatnie pole (double): " << result << endl;
            break;
        }
        case 0: {
            // Wyjście
            cout << "Do widzenia!\n";
            break;
        }
        default: {
            cout << "Nieprawidłowy wybór. Spróbuj ponownie.\n";
            break;
        }
        }

    } while (choice != 0);

    return 0;
}
#endif


