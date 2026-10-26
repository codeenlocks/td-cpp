#include <iostream>
#include "Complex2D.h"

using namespace std;
using C = Complex2D;

int main(){
    //Initialisation d'instance de  test de Complex2D
    C z0 = Complex2D() ;
    C z1 = Complex2D(1,2) ;
    C z2 = Complex2D(2) ;
    C z3 = Complex2D(z1) ;

    cout << "Affichage des nombres complexes" 
    << endl  << "z0 = " << z0.getRe() << " + " << z0.getIm()<< "i" 
    << endl  << "z1 = " << z1.getRe() << " + " << z1.getIm()<< "i"
    << endl  << "z2 = " << z2.getRe() << " + " << z2.getIm()<< "i"
    << endl  << "z3 = " << z3.getRe() << " + " << z3.getIm()<< "i";

    /*
    Opérations sur les Complex2D
    1. z_ij= zi + zj
    2. z_i_j= zi - zj
    3. zizj= zi * zj
    4. zi_zj= zi / zj
    */
    C z_12= z1 + z2 ;
    C z_1_2= z1 - z2 ;
    C z1z2= z1 * z2 ; 
    C z1_z2= z1 / z2 ;

    cout << endl << "\nAffichage des cpérations complexes" 
    << endl  << "z1 + z2 = " << z_12.getRe()<< " + " << z_12.getIm() << "i" 
    << endl  << "z1 - z2 = " << z_1_2.getRe() << " + " << z_1_2.getIm() << "i" 
    << endl  << "z1 × z2 = " << z1z2.getRe() << " + " << z1z2.getIm() << "i" 
    << endl  << "z1 ÷ z2 = " << z1_z2.getRe() << " + "  << z1_z2.getIm() << "i" ;


    cout << endl << "\nAffichage des comparaisons complexes" 
    << endl  << "z1 < z2 : " << ((z1 < z2)?"True":"False")
    << endl  << "z1 > z2  : " << ((z1 > z2)?"True":"False")
    << endl  << "z1 ==  z2 : " << (!((z1 < z2)||(z1 > z2))?"True":"False")
    << endl  << "z0 ==  z0 : " << (!((z0 < z0)||(z0 > z0))?"True":"False")
    << endl  << "z1 ==  z0 : " << (!((z1 < z0)||(z1 > z0))?"True":"False")
    << endl  << "z1 ==  z3 : " << (!((z1 < z3)||(z1 > z3))?"True":"False")
    << endl << "Fin de la démonstration" << endl ;

    return 0;
}