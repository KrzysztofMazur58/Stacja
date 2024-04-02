#pragma once
#include <iostream>
#include "Train.h"

using namespace std;

/**
 * @brief Klasa reprezentuj�ca poci�g towarowy.
 */
class CargoTrain : public Train
{
    double cargoCapacity; /**< Pojemno�� �adunku poci�gu towarowego. */

public:

    /**
     * @brief Konstruktor domy�lny.
     */
    CargoTrain();

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
     * @param cargoCapacity Pojemno�� �adunku poci�gu towarowego.
     */
    CargoTrain(const string& name, const string& source, const string& destination, const string& status, int delay, int departureHour, int departureMinutes, double cargoCapacity);

    /**
     * @brief Konstruktor z danymi binarnymi.
     *
     * @param inData Dane binarne poci�gu towarowego.
     */
    CargoTrain(char* inData);

    /**
     * @brief Destruktor.
     */
    ~CargoTrain();

    /**
     * @brief Ustawia pojemno�� �adunku poci�gu towarowego.
     *
     * @param cargoCapacity Nowa pojemno�� �adunku.
     */
    void setCargoCapacity(double cargoCapacity);

    /**
     * @brief Zwraca pojemno�� �adunku poci�gu towarowego.
     *
     * @return Pojemno�� �adunku poci�gu towarowego.
     */
    double getCargoCapacity() const;

    /**
     * @brief Wirtualna metoda wy�wietlaj�ca informacje o poci�gu towarowym.
     */
    void printInfo() const override;

    void readFromStream(istream& stream) override;
    /**
     * @brief Wirtualna metoda konwertuj�ca dane poci�gu towarowego do formatu binarnego.
     *
     * @return Wska�nik do danych binarnych.
     */
    char* toBinary() override;

    /**
     * @brief Przeci��ony operator strumieniowy wej�cia dla klasy CargoTrain.
     *
     * @param stream Strumie� wej�ciowy.
     * @param cargoTrain Referencja do obiektu klasy CargoTrain.
     * @return Strumie� wej�ciowy.
     */
     //friend istream& operator>>(istream& stream, CargoTrain& cargoTrain);
};



