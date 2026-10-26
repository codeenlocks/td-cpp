#include "Complex2D.h"

// CONSTRUCTEURS
Complex2D::Complex2D(double a,double b) : re(a), im(b){}
Complex2D::Complex2D(double x) : re(x), im(x) {} //explicite unaire
Complex2D::Complex2D() : re(0),im(0) {} //default
Complex2D::Complex2D(const Complex2D& c) : re(c.re),im(c.im) {} //copie

// ACCESSEURS
void Complex2D::setRe(double d) {re = d;}
double Complex2D::getRe() const {return re;}
void Complex2D::setIm(double d) { im = d;}
double Complex2D::getIm() const { return im ;}

// OPERATEURS ARITHMETIQUES
Complex2D Complex2D::operator+(const Complex2D z) const 
{   
    return Complex2D(
    this->getRe() + z.getRe(),
    this->getIm() + z.getIm());
}
Complex2D Complex2D::operator-(const Complex2D z) const
{
    return Complex2D(
    this->getRe() - z.getRe(),
    this->getIm() - z.getIm());
}
Complex2D Complex2D::operator*(const Complex2D z) const
{ return Complex2D(
    this->getRe() * z.getRe() - this->getIm() * z.getIm(), 
    this->getRe() * z.getIm() + this->getIm() * z.getRe());
}
Complex2D Complex2D::operator/(const Complex2D z) const
{
    double mod2 = z.getRe()*z.getRe() + z.getIm()*z.getIm() ; // dénominateur * son conjugué
    Complex2D num = (*this)* Complex2D(z.getRe(), -z.getIm()) ; // numérateur * conjugué du dénominateur
    return Complex2D(
    num.getRe()/ mod2, 
    num.getIm()/ mod2);
}

//OPERATEURS LOGIQUES
bool Complex2D::operator<(const Complex2D z) const
{
    double arg = this->getRe()*this->getRe() + this->getIm()*this->getIm() ;
    double argz = z.getRe()*z.getRe() + z.getIm()*z.getIm() ;
    return arg < argz ;
}
bool Complex2D::operator>(const Complex2D z) const
{
    double arg = this->getRe()*this->getRe() + this->getIm()*this->getIm() ;
    double argz = z.getRe()*z.getRe() + z.getIm()*z.getIm() ;
    return arg > argz ;
}

