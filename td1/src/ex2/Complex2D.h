#ifndef COMPLEX2D_H
#define COMPLEX2D_H

class Complex2D
{
private:
    double re, im;
public:
    Complex2D(double,double); //explicite binaire
    Complex2D(double); //explicite unaire
    Complex2D(); //default
    Complex2D( const Complex2D&) ;
    void setRe(double);
    double getRe() const;
    void setIm(double);
    double getIm() const;
    Complex2D operator+(const Complex2D) const;
    Complex2D operator-(const Complex2D) const;
    Complex2D operator*(const Complex2D) const;
    Complex2D operator/(const Complex2D) const;
    bool operator<(const Complex2D) const;
    bool operator>(const Complex2D) const;

};


#endif