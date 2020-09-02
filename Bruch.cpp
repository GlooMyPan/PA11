//
// Created by Xuantong Pan on 26.08.20.
//
#include "Bruch.h"

/***  ggT  ***/
static long long ggT(long long m, long long n)
{
    while (n != 0)
    {
        long long k = m % n;
        m = n;
        n = k;
    }
    return m;
}

/***  Konstruktoren  ***/
Bruch::Bruch()
{
    this->_zaehler = 0;
    this->_nenner = 1;
}

Bruch::Bruch(long long l)
{
    this->_zaehler = l;
    this->_nenner = 1;
}

/***  get-Methoden  ***/
long long Bruch::getZaehler()
{
    return this->_zaehler;
}

long long Bruch::getNenner()
{
    return this->_nenner;
}

void Bruch::_formatiere()
{
    if (this->_nenner == 0)
    {
        cerr << "Der Nenner darf nicht = 0 sein!" << endl;
        return;
    }
    //1.
    if (this->_nenner < 0)
    {
        this->_zaehler = -this->_zaehler;
        this->_nenner = -this->_nenner;
    }
    //2.
    if (this->_zaehler == 0)
        this->_nenner = 1;
    long long ggt = ggT(abs(this->_zaehler), this->_nenner);
    this->_zaehler /= ggt;
    this->_nenner /= ggt;
}

/***  Interaktionsmethoden, z.B. Vergleiche  ***/
bool Bruch::operator!=(int i) const
{
    return this->_zaehler != i * this->_nenner;
}

bool Bruch::operator==(int i) const
{
    return this->_zaehler == i * this->_nenner;
}

bool Bruch::operator>=(int i) const
{
    return this->_zaehler >= i * this->_nenner;
}

bool Bruch::operator<(const Bruch &bruch) const
{
    return (this->_zaehler * bruch._nenner) < (bruch._zaehler * this->_nenner);
}

/***  Rechenmethoden  ***/
Bruch Bruch::operator*(Bruch const &bruch)
{
    Bruch nBruch;
    long long nZaehler = this->_zaehler * bruch._zaehler;
    long long nNenner = this->_nenner * bruch._nenner;
    long long ggt = ggT(nZaehler, nNenner);
    nZaehler /= ggt;
    nNenner /= ggt;
    nBruch._zaehler = nZaehler;
    nBruch._nenner = nNenner;
    return nBruch;
}

Bruch Bruch::operator/(const Bruch &bruch)
{
    Bruch nBruch;
    long long nZaehler = this->_zaehler * bruch._nenner;
    long long nNenner = this->_nenner * bruch._zaehler;
    long long ggt = ggT(nZaehler, nNenner);
    nZaehler /= ggt;
    nNenner /= ggt;
    if (nNenner < 0)
    {
        nNenner = -nNenner;
        nZaehler = -nZaehler;
    }
    nBruch._zaehler = nZaehler;
    nBruch._nenner = nNenner;

    return nBruch;
}

Bruch &Bruch::operator/=(const Bruch &bruch)
{
    this->_zaehler *= bruch._nenner;
    this->_nenner *= bruch._zaehler;
    _formatiere();
    return *this;
}

Bruch Bruch::operator-() const
{
    Bruch temp;
    temp._zaehler = -this->_zaehler;
    temp._nenner = this->_nenner;
    return temp;
}

Bruch& Bruch::operator-=(Bruch const &bruch)
{
    this->_zaehler = this->_zaehler * bruch._nenner - bruch._zaehler * this->_nenner;
    this->_nenner *= bruch._nenner;
    _formatiere();
    return *this;
}

/***  globale Funktionen  ***/
ostream &operator<<(ostream &cout, Bruch const &bruch)
{
    if (bruch._nenner != 1)
        cout << bruch._zaehler << "/" << bruch._nenner;
    else
        cout << bruch._zaehler;
    return cout;
}

Bruch &abs(Bruch &bruch)
{
    bruch._zaehler = abs(bruch._zaehler);
    return bruch;
}
