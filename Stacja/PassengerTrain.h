#pragma once
#include <iostream>
#include "Train.h"

using namespace std;

/**
 * @brief Klasa reprezentuj¹ca poci¹g pasa¿erski.
 */
class PassengerTrain : public Train
{
    int numberOfSeats; /**< Liczba miejsc w poci¹gu pasa¿erskim. */

public:

    /**
     * @brief Konstruktor domyœlny.
     */
    PassengerTrain();

    /**
     * @brief Konstruktor z parametrami.
     *
     * @param name Nazwa poci¹gu.
     * @param source Miejsce pocz¹tkowe poci¹gu.
     * @param destination Miejsce docelowe poci¹gu.
     * @param status Status poci¹gu.
     * @param delay OpóŸnienie poci¹gu.
     * @param departureHour Godzina odjazdu poci¹gu.
     * @param departureMinutes Minuty odjazdu poci¹gu.
     * @param numberOfSeats Liczba miejsc w poci¹gu pasa¿erskim.
     */
    PassengerTrain(const string& name, const string& source, const string& destination, const string& status, int delay, int departureHour, int departureMinutes, int numberOfSeats);

    /**
     * @brief Konstruktor z danymi binarnymi.
     *
     * @param inData Dane binarne poci¹gu pasa¿erskiego.
     */
    PassengerTrain(char* inData);

    /**
     * @brief Destruktor.
     */
    ~PassengerTrain();

    /**
     * @brief Ustawia liczbê miejsc w poci¹gu pasa¿erskim.
     *
     * @param numberOfSeats Nowa liczba miejsc.
     */
    void setNumberOfSeats(int numberOfSeats);

    /**
     * @brief Zwraca liczbê miejsc w poci¹gu pasa¿erskim.
     *
     * @return Liczba miejsc w poci¹gu pasa¿erskim.
     */
    int getNumberOfSeats() const;

    /**
     * @brief Wirtualna metoda wyœwietlaj¹ca informacje o poci¹gu pasa¿erskim.
     */
    void printInfo() const override;

    void readFromStream(istream& stream) override;
    /**
     * @brief Wirtualna metoda konwertuj¹ca dane poci¹gu pasa¿erskiego do formatu binarnego.
     *
     * @return WskaŸnik do danych binarnych.
     */

    char* toBinary() override;

    /**
     * @brief Przeci¹¿ony operator strumieniowy wejœcia dla klasy PassengerTrain.
     *
     * @param stream Strumieñ wejœciowy.
     * @param passengerTrain Referencja do obiektu klasy PassengerTrain.
     * @return Strumieñ wejœciowy.
     */
    friend istream& operator>>(istream& stream, PassengerTrain& passengerTrain);
};




