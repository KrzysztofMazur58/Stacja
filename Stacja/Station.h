#pragma once

#include "Train.h"
#include "PassengerTrain.h"
#include "CargoTrain.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Klasa reprezentuj¹ca stacjê kolejow¹.
 */
class Station
{
    vector<Train*> trains; /**< Wektor przechowuj¹cy obiekty poci¹gów. */

    /**
     * @brief Pobiera wartoœæ okreœlonego pola z obiektu poci¹gu.
     *
     * @param train Obiekt poci¹gu.
     * @param fieldName Nazwa pola.
     * @return Wartoœæ pola w formie ci¹gu znaków.
     */
    string getFieldValue(const Train* train, const string& fieldName);

public:

    /**
     * @brief Dodaje poci¹g do stacji.
     *
     * @param train Obiekt poci¹gu do dodania.
     */
    void addTrain(Train* train);

    /**
     * @brief Wyœwietla informacje o wszystkich poci¹gach na stacji.
     */
    void displayTrainsInfo() const;

    /**
     * @brief Usuwa poci¹g z stacji na podstawie indeksu.
     *
     * @param index Indeks poci¹gu do usuniêcia.
     */
    void removeTrain(int index);

    /**
     * @brief Usuwa wszystkie poci¹gi ze stacji.
     */
    void removeAllTrains();

    /**
     * @brief Zwraca liczbê poci¹gów na stacji.
     *
     * @return Liczba poci¹gów.
     */
    int getNumberOfTrains() const;

    /**
     * @brief Zwraca wskaŸnik do poci¹gu na podstawie indeksu.
     *
     * @param index Indeks poci¹gu.
     * @return WskaŸnik do obiektu poci¹gu.
     */
    Train* getTrain(int index);

    /**
     * @brief Sortuje poci¹gi na stacji wed³ug okreœlonego pola.
     *
     * @param fieldName Nazwa pola, wed³ug którego ma nast¹piæ sortowanie.
     */
    void sortByField(const string& fieldName);

    /**
     * @brief Zapisuje stan stacji do pliku.
     *
     * @param file Strumieñ wyjœciowy pliku.
     */
    void saveToFile(ofstream& file);

    /**
     * @brief Wczytuje stan stacji z pliku.
     *
     * @param file Strumieñ wejœciowy pliku.
     */
    void loadFromFile(ifstream& file);

    /**
     * @brief Filtruje poci¹gi na podstawie okreœlonego pola i nazwy.
     *
     * @param fieldName Nazwa pola, wed³ug którego ma nast¹piæ filtrowanie.
     * @param name Wartoœæ, która ma byæ u¿yta do filtrowania.
     */
    void filterTrains(const string& fieldName, const string& name);

    /**
     * @brief Filtruje poci¹gi na podstawie liczby.
     *
     * @param value Wartoœæ liczby, wed³ug której ma nast¹piæ filtrowanie.
     */
    void filterTrains(int value);

    /**
    * @brief Przeci¹¿ony operator strumieniowy wyjœcia dla klasy Station.
    *
    * @param stream Strumieñ wyjœciowy.
    * @param station Referencja do obiektu klasy Station.
    * @return Strumieñ wyjœciowy.
    */
    friend ostream& operator<<(ostream& stream, const Station& station);

    /**
     * @brief Przeci¹¿ony operator strumieniowy wejœcia dla klasy Station.
     *
     * @param stream Strumieñ wejœciowy.
     * @param station Referencja do obiektu klasy Station.
     * @return Strumieñ wejœciowy.
     */
    friend istream& operator>>(istream& stream, Station& station);

    /**
     * @brief Przeci¹¿ony operator dodawania poci¹gu do stacji.
     *
     * @param train Obiekt poci¹gu do dodania.
     */

    void operator+=(Train* train);

    /**
     * @brief Przeci¹¿ony operator indeksowania umo¿liwiaj¹cy dostêp do poci¹gu na podanym indeksie.
     *
     * @param index Indeks poci¹gu.
     * @return WskaŸnik do obiektu poci¹gu.
     */
    Train* operator[](int index);

    /**
     * @brief Przeci¹¿ony operator dekrementacji, usuwaj¹cy ostatni poci¹g ze stacji.
     */
    void operator--();

    /**
     * @brief Szablonowa metoda obliczaj¹ca sumê ostatniego pola dla poci¹gów na stacji.
     *
     * @tparam T Typ zwracanej sumy (int lub double).
     * @return Suma wartoœci okreœlonego pola dla poci¹gów na stacji.
     */
    template <typename T>
    T calculateLastField()
    {
        int sum1 = 0;
        double sum2 = 0;

        for (const auto& train : trains)
        {
            if (PassengerTrain* pt = dynamic_cast<PassengerTrain*>(train))
            {
                sum1 += pt->getNumberOfSeats();
            }
            else if (CargoTrain* ct = dynamic_cast<CargoTrain*>(train))
            {
                sum2 += ct->getCargoCapacity();
            }
        }

        if (is_same_v<T, int>)
        {
            return sum1;
        }
        else if (is_same_v<T, double>)
        {
            return sum2;
        }
    }
};





