#include <iostream>       // f¸r ostream
using namespace std ;


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
    long long _zaehler, _nenner ;

    // stelle Datenformat des Objekts her
    void _formatiere () ;

public:
/***  Konstruktoren  ***/


/***  get-Methoden  ***/


/***  Interaktionsmethoden, z.B. Vergleiche  ***/


/***  Rechenmethoden  ***/
    Bruch operator=(int i);

    Bruch operator*(Bruch& bruch);

} ;  // class Bruch


/***  globale Funktionen  ***/

