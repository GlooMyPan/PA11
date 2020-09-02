#include <iostream>       // f¸r ostream

using namespace std;


/**
  * Klasse f¸r Br¸che als Quotienten ganzer Zahlen
  *
  * Datenformat:
  *		- Der Nenner ist echt positiv.
  *		- Bei Z‰hler == 0 ist Nenner == 1.
  *		- Z‰hler und Nenner sind ausgek¸rzt.
  */

class Bruch
{
/***  private Elemente ***/

    // Z‰hler und Nenner des Objekts
    long long _zaehler, _nenner;

    // stelle Datenformat des Objekts her
    void _formatiere();

public:
    friend ostream &operator<<(ostream &cout, Bruch const &bruch);
    friend Bruch &abs(Bruch &bruch);

/***  Konstruktoren  ***/
    Bruch();

    Bruch(long long l);

/***  get-Methoden  ***/
    long long getZaehler();

    long long getNenner();

/***  Interaktionsmethoden, z.B. Vergleiche  ***/
    bool operator!=(int i) const;

    bool operator==(int i) const;

    bool operator>=(int i) const;

    bool operator<(Bruch const &bruch) const;


/***  Rechenmethoden  ***/

    Bruch operator*(Bruch const &bruch);

    Bruch operator/(Bruch const &bruch);

    Bruch& operator/=(Bruch const &bruch);

    Bruch& operator-=(Bruch const &bruch);

    Bruch operator-() const;


};  // class Bruch


/***  globale Funktionen  ***/
ostream &operator<<(ostream &cout, Bruch const &bruch);

Bruch &abs(Bruch &bruch);

