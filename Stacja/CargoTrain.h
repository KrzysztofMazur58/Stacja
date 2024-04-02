#pragma once
#include <iostream>
#include "Train.h"

using namespace std;

/**
 * @brief Klasa reprezentuj¹ca poci¹g towarowy.
 */
class CargoTrain : public Train
{
    double cargoCapacity; /**< Pojemnoœæ ³adunku poci¹gu towarowego. */

public:

    /**
     * @brief Konstruktor domyœlny.
     */
    CargoTrain();

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
     * @param cargoCapacity Pojemnoœæ ³adunku poci¹gu towarowego.
     */
    CargoTrain(const string& name, const string& source, const string& destination, const string& status, int delay, int departureHour, int departureMinutes, double cargoCapacity);

    /**
     * @brief Konstruktor z danymi binarnymi.
     *
     * @param inData Dane binarne poci¹gu towarowego.
     */
    CargoTrain(char* inData);

    /**
     * @brief Destruktor.
     */
    ~CargoTrain();

    /**
     * @brief Ustawia pojemnoœæ ³adunku poci¹gu towarowego.
     *
     * @param cargoCapacity Nowa pojemnoœæ ³adunku.
     */
    void setCargoCapacity(double cargoCapacity);

    /**
     * @brief Zwraca pojemnoœæ ³adunku poci¹gu towarowego.
     *
     * @return Pojemnoœæ ³adunku poci¹gu towarowego.
     */
    double getCargoCapacity() const;

    /**
     * @brief Wirtualna metoda wyœwietlaj¹ca informacje o poci¹gu towarowym.
     */
    void printInfo() const override;

    void readFromStream(istream& stream) override;
    /**
     * @brief Wirtualna metoda konwertuj¹ca dane poci¹gu towarowego do formatu binarnego.
     *
     * @return WskaŸnik do danych binarnych.
     */
    char* toBinary() override;

    /**
     * @brief Przeci¹¿ony operator strumieniowy wejœcia dla klasy CargoTrain.
     *
     * @param stream Strumieñ wejœciowy.
     * @param cargoTrain Referencja do obiektu klasy CargoTrain.
     * @return Strumieñ wejœciowy.
     */
     //friend istream& operator>>(istream& stream, CargoTrain& cargoTrain);
};



