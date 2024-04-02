#pragma once
#include <iostream>

using namespace std;

/**
 * @brief Abstrakcyjna klasa reprezentuj¹ca poci¹g.
 */
class Train
{
protected:

    /**
     * @brief Struktura reprezentuj¹ca czas.
     */
    struct Time
    {
        int hour; /**< Godzina. */
        int minutes; /**< Minuty. */
    };

    int delay; /**< OpóŸnienie poci¹gu. */
    string name; /**< Nazwa poci¹gu. */
    string source; /**< Miejsce pocz¹tkowe poci¹gu. */
    string destination; /**< Miejsce docelowe poci¹gu. */
    string status; /**< Status poci¹gu. */
    struct Time departureTime; /**< Czas odjazdu poci¹gu. */

    char* binData = nullptr; /**< Dane binarne poci¹gu. */

public:

    /**
     * @brief Konstruktor domyœlny.
     */
    Train();

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
     */
    Train(const string& name, const string& source, const string& destination, const string& status, int delay, int departureHour, int departureMinutes);

    /**
     * @brief Konstruktor z danymi binarnymi.
     *
     * @param inData Dane binarne poci¹gu.
     */
    Train(char* inData);

    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~Train() = 0;

    /**
     * @brief Wirtualna metoda wyœwietlaj¹ca informacje o poci¹gu.
     */
    virtual void printInfo() const;

    virtual void readFromStream(istream& stream);
    /**
     * @brief Ustawia nazwê poci¹gu.
     *
     * @param name Nowa nazwa poci¹gu.
     */

    void setName(const string& name);

    /**
     * @brief Ustawia miejsce pocz¹tkowe poci¹gu.
     *
     * @param source Nowe miejsce pocz¹tkowe poci¹gu.
     */
    void setSource(const string& source);

    /**
     * @brief Ustawia miejsce docelowe poci¹gu.
     *
     * @param destination Nowe miejsce docelowe poci¹gu.
     */
    void setDestination(const string& destination);

    /**
     * @brief Ustawia status poci¹gu.
     *
     * @param status Nowy status poci¹gu.
     */
    void setStatus(const string& status);

    /**
     * @brief Ustawia opóŸnienie poci¹gu.
     *
     * @param delay Nowe opóŸnienie poci¹gu.
     */
    void setDelay(int delay);

    /**
     * @brief Ustawia godzinê odjazdu poci¹gu.
     *
     * @param hour Nowa godzina odjazdu poci¹gu.
     */
    void setDepartureHour(int hour);

    /**
     * @brief Ustawia minuty odjazdu poci¹gu.
     *
     * @param minutes Nowe minuty odjazdu poci¹gu.
     */
    void setDepartureMinutes(int minutes);

    /**
     * @brief Zwraca nazwê poci¹gu.
     *
     * @return Nazwa poci¹gu.
     */
    string getName() const;

    /**
     * @brief Zwraca miejsce pocz¹tkowe poci¹gu.
     *
     * @return Miejsce pocz¹tkowe poci¹gu.
     */
    string getSource() const;

    /**
     * @brief Zwraca miejsce docelowe poci¹gu.
     *
     * @return Miejsce docelowe poci¹gu.
     */
    string getDestination() const;

    /**
     * @brief Zwraca status poci¹gu.
     *
     * @return Status poci¹gu.
     */
    string getStatus() const;

    /**
     * @brief Zwraca opóŸnienie poci¹gu.
     *
     * @return OpóŸnienie poci¹gu.
     */
    int getDelay() const;

    /**
     * @brief Zwraca godzinê odjazdu poci¹gu.
     *
     * @return Godzina odjazdu poci¹gu.
     */
    int getDepartureHour() const;

    /**
     * @brief Zwraca minuty odjazdu poci¹gu.
     *
     * @return Minuty odjazdu poci¹gu.
     */
    int getDepartureMinutes() const;

    /**
     * @brief Zwraca dane binarne poci¹gu.
     *
     * @return WskaŸnik do danych binarnych.
     */
    virtual char* toBinary();

    /**
     * @brief Czyœci dane binarne poci¹gu.
     */
    void clearBinData();

    /**
     * @brief Przeci¹¿ony operator strumieniowy wyjœcia dla klasy Train.
     *
     * @param stream Strumieñ wyjœciowy.
     * @param train Referencja do obiektu klasy Train.
     * @return Strumieñ wyjœciowy.
     */
    friend ostream& operator<<(ostream& stream, const Train& train);

    /**
     * @brief Przeci¹¿ony operator strumieniowy wejœcia dla klasy Train.
     *
     * @param stream Strumieñ wejœciowy.
     * @param train Referencja do obiektu klasy Train.
     * @return Strumieñ wejœciowy.
     */
     //friend istream& operator>>(istream& stream, Train& train);
};



