#pragma once
#include <iostream>
#include "Train.h"

using namespace std;

/**
 * @brief Klasa reprezentuj�ca poci�g pasa�erski.
 */
class PassengerTrain : public Train
{
    int numberOfSeats; /**< Liczba miejsc w poci�gu pasa�erskim. */

public:

    /**
     * @brief Konstruktor domy�lny.
     */
    PassengerTrain();

    /**
     * @brief Konstruktor z parametrami.
     *
     * @param name Nazwa poci�gu.
     * @param source Miejsce pocz�tkowe poci�gu.
     * @param destination Miejsce docelowe poci�gu.
     * @param status Status poci�gu.
     * @param delay Op�nienie poci�gu.
     * @param departureHour Godzina odjazdu poci�gu.
     * @param departureMinutes Minuty odjazdu poci�gu.
     * @param numberOfSeats Liczba miejsc w poci�gu pasa�erskim.
     */
    PassengerTrain(const string& name, const string& source, const string& destination, const string& status, int delay, int departureHour, int departureMinutes, int numberOfSeats);

    /**
     * @brief Konstruktor z danymi binarnymi.
     *
     * @param inData Dane binarne poci�gu pasa�erskiego.
     */
    PassengerTrain(char* inData);

    /**
     * @brief Destruktor.
     */
    ~PassengerTrain();

    /**
     * @brief Ustawia liczb� miejsc w poci�gu pasa�erskim.
     *
     * @param numberOfSeats Nowa liczba miejsc.
     */
    void setNumberOfSeats(int numberOfSeats);

    /**
     * @brief Zwraca liczb� miejsc w poci�gu pasa�erskim.
     *
     * @return Liczba miejsc w poci�gu pasa�erskim.
     */
    int getNumberOfSeats() const;

    /**
     * @brief Wirtualna metoda wy�wietlaj�ca informacje o poci�gu pasa�erskim.
     */
    void printInfo() const override;

    void readFromStream(istream& stream) override;
    /**
     * @brief Wirtualna metoda konwertuj�ca dane poci�gu pasa�erskiego do formatu binarnego.
     *
     * @return Wska�nik do danych binarnych.
     */

    char* toBinary() override;

    /**
     * @brief Przeci��ony operator strumieniowy wej�cia dla klasy PassengerTrain.
     *
     * @param stream Strumie� wej�ciowy.
     * @param passengerTrain Referencja do obiektu klasy PassengerTrain.
     * @return Strumie� wej�ciowy.
     */
    friend istream& operator>>(istream& stream, PassengerTrain& passengerTrain);
};




