#pragma once
#include <iostream>

using namespace std;

/**
 * @brief Abstrakcyjna klasa reprezentuj�ca poci�g.
 */
class Train
{
protected:

    /**
     * @brief Struktura reprezentuj�ca czas.
     */
    struct Time
    {
        int hour; /**< Godzina. */
        int minutes; /**< Minuty. */
    };

    int delay; /**< Op�nienie poci�gu. */
    string name; /**< Nazwa poci�gu. */
    string source; /**< Miejsce pocz�tkowe poci�gu. */
    string destination; /**< Miejsce docelowe poci�gu. */
    string status; /**< Status poci�gu. */
    struct Time departureTime; /**< Czas odjazdu poci�gu. */

    char* binData = nullptr; /**< Dane binarne poci�gu. */

public:

    /**
     * @brief Konstruktor domy�lny.
     */
    Train();

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
     */
    Train(const string& name, const string& source, const string& destination, const string& status, int delay, int departureHour, int departureMinutes);

    /**
     * @brief Konstruktor z danymi binarnymi.
     *
     * @param inData Dane binarne poci�gu.
     */
    Train(char* inData);

    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~Train() = 0;

    /**
     * @brief Wirtualna metoda wy�wietlaj�ca informacje o poci�gu.
     */
    virtual void printInfo() const;

    virtual void readFromStream(istream& stream);
    /**
     * @brief Ustawia nazw� poci�gu.
     *
     * @param name Nowa nazwa poci�gu.
     */

    void setName(const string& name);

    /**
     * @brief Ustawia miejsce pocz�tkowe poci�gu.
     *
     * @param source Nowe miejsce pocz�tkowe poci�gu.
     */
    void setSource(const string& source);

    /**
     * @brief Ustawia miejsce docelowe poci�gu.
     *
     * @param destination Nowe miejsce docelowe poci�gu.
     */
    void setDestination(const string& destination);

    /**
     * @brief Ustawia status poci�gu.
     *
     * @param status Nowy status poci�gu.
     */
    void setStatus(const string& status);

    /**
     * @brief Ustawia op�nienie poci�gu.
     *
     * @param delay Nowe op�nienie poci�gu.
     */
    void setDelay(int delay);

    /**
     * @brief Ustawia godzin� odjazdu poci�gu.
     *
     * @param hour Nowa godzina odjazdu poci�gu.
     */
    void setDepartureHour(int hour);

    /**
     * @brief Ustawia minuty odjazdu poci�gu.
     *
     * @param minutes Nowe minuty odjazdu poci�gu.
     */
    void setDepartureMinutes(int minutes);

    /**
     * @brief Zwraca nazw� poci�gu.
     *
     * @return Nazwa poci�gu.
     */
    string getName() const;

    /**
     * @brief Zwraca miejsce pocz�tkowe poci�gu.
     *
     * @return Miejsce pocz�tkowe poci�gu.
     */
    string getSource() const;

    /**
     * @brief Zwraca miejsce docelowe poci�gu.
     *
     * @return Miejsce docelowe poci�gu.
     */
    string getDestination() const;

    /**
     * @brief Zwraca status poci�gu.
     *
     * @return Status poci�gu.
     */
    string getStatus() const;

    /**
     * @brief Zwraca op�nienie poci�gu.
     *
     * @return Op�nienie poci�gu.
     */
    int getDelay() const;

    /**
     * @brief Zwraca godzin� odjazdu poci�gu.
     *
     * @return Godzina odjazdu poci�gu.
     */
    int getDepartureHour() const;

    /**
     * @brief Zwraca minuty odjazdu poci�gu.
     *
     * @return Minuty odjazdu poci�gu.
     */
    int getDepartureMinutes() const;

    /**
     * @brief Zwraca dane binarne poci�gu.
     *
     * @return Wska�nik do danych binarnych.
     */
    virtual char* toBinary();

    /**
     * @brief Czy�ci dane binarne poci�gu.
     */
    void clearBinData();

    /**
     * @brief Przeci��ony operator strumieniowy wyj�cia dla klasy Train.
     *
     * @param stream Strumie� wyj�ciowy.
     * @param train Referencja do obiektu klasy Train.
     * @return Strumie� wyj�ciowy.
     */
    friend ostream& operator<<(ostream& stream, const Train& train);

    /**
     * @brief Przeci��ony operator strumieniowy wej�cia dla klasy Train.
     *
     * @param stream Strumie� wej�ciowy.
     * @param train Referencja do obiektu klasy Train.
     * @return Strumie� wej�ciowy.
     */
     //friend istream& operator>>(istream& stream, Train& train);
};



