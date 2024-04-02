#pragma once

#include "Train.h"
#include "PassengerTrain.h"
#include "CargoTrain.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Klasa reprezentuj�ca stacj� kolejow�.
 */
class Station
{
    vector<Train*> trains; /**< Wektor przechowuj�cy obiekty poci�g�w. */

    /**
     * @brief Pobiera warto�� okre�lonego pola z obiektu poci�gu.
     *
     * @param train Obiekt poci�gu.
     * @param fieldName Nazwa pola.
     * @return Warto�� pola w formie ci�gu znak�w.
     */
    string getFieldValue(const Train* train, const string& fieldName);

public:

    /**
     * @brief Dodaje poci�g do stacji.
     *
     * @param train Obiekt poci�gu do dodania.
     */
    void addTrain(Train* train);

    /**
     * @brief Wy�wietla informacje o wszystkich poci�gach na stacji.
     */
    void displayTrainsInfo() const;

    /**
     * @brief Usuwa poci�g z stacji na podstawie indeksu.
     *
     * @param index Indeks poci�gu do usuni�cia.
     */
    void removeTrain(int index);

    /**
     * @brief Usuwa wszystkie poci�gi ze stacji.
     */
    void removeAllTrains();

    /**
     * @brief Zwraca liczb� poci�g�w na stacji.
     *
     * @return Liczba poci�g�w.
     */
    int getNumberOfTrains() const;

    /**
     * @brief Zwraca wska�nik do poci�gu na podstawie indeksu.
     *
     * @param index Indeks poci�gu.
     * @return Wska�nik do obiektu poci�gu.
     */
    Train* getTrain(int index);

    /**
     * @brief Sortuje poci�gi na stacji wed�ug okre�lonego pola.
     *
     * @param fieldName Nazwa pola, wed�ug kt�rego ma nast�pi� sortowanie.
     */
    void sortByField(const string& fieldName);

    /**
     * @brief Zapisuje stan stacji do pliku.
     *
     * @param file Strumie� wyj�ciowy pliku.
     */
    void saveToFile(ofstream& file);

    /**
     * @brief Wczytuje stan stacji z pliku.
     *
     * @param file Strumie� wej�ciowy pliku.
     */
    void loadFromFile(ifstream& file);

    /**
     * @brief Filtruje poci�gi na podstawie okre�lonego pola i nazwy.
     *
     * @param fieldName Nazwa pola, wed�ug kt�rego ma nast�pi� filtrowanie.
     * @param name Warto��, kt�ra ma by� u�yta do filtrowania.
     */
    void filterTrains(const string& fieldName, const string& name);

    /**
     * @brief Filtruje poci�gi na podstawie liczby.
     *
     * @param value Warto�� liczby, wed�ug kt�rej ma nast�pi� filtrowanie.
     */
    void filterTrains(int value);

    /**
    * @brief Przeci��ony operator strumieniowy wyj�cia dla klasy Station.
    *
    * @param stream Strumie� wyj�ciowy.
    * @param station Referencja do obiektu klasy Station.
    * @return Strumie� wyj�ciowy.
    */
    friend ostream& operator<<(ostream& stream, const Station& station);

    /**
     * @brief Przeci��ony operator strumieniowy wej�cia dla klasy Station.
     *
     * @param stream Strumie� wej�ciowy.
     * @param station Referencja do obiektu klasy Station.
     * @return Strumie� wej�ciowy.
     */
    friend istream& operator>>(istream& stream, Station& station);

    /**
     * @brief Przeci��ony operator dodawania poci�gu do stacji.
     *
     * @param train Obiekt poci�gu do dodania.
     */

    void operator+=(Train* train);

    /**
     * @brief Przeci��ony operator indeksowania umo�liwiaj�cy dost�p do poci�gu na podanym indeksie.
     *
     * @param index Indeks poci�gu.
     * @return Wska�nik do obiektu poci�gu.
     */
    Train* operator[](int index);

    /**
     * @brief Przeci��ony operator dekrementacji, usuwaj�cy ostatni poci�g ze stacji.
     */
    void operator--();

    /**
     * @brief Szablonowa metoda obliczaj�ca sum� ostatniego pola dla poci�g�w na stacji.
     *
     * @tparam T Typ zwracanej sumy (int lub double).
     * @return Suma warto�ci okre�lonego pola dla poci�g�w na stacji.
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





