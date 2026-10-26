#include <iostream>
#include "Matrix.hpp"

int main() {
    try {
        std::cout << "--- Test MatrixNumerical avec int ---" << std::endl;
        MatrixNumerical<int> mat1({{1, 2}, {3, 4}});
        MatrixNumerical<int> mat2({{2, 0}, {1, 2}});

        std::cout << "Matrice 1 :" << std::endl;
        mat1.Display();
        
        std::cout << "Matrice 2 :" << std::endl;
        mat2.Display();

        std::cout << "\nAddition (mat1 + mat2) :" << std::endl;
        MatrixNumerical<int> sum = mat1 + mat2;
        sum.Display();

        std::cout << "\nMultiplication (mat1 * mat2) :" << std::endl;
        MatrixNumerical<int> prod = mat1 * mat2;
        prod.Display();

        std::cout << "\nDeterminant de Matrice 1 : " << mat1.getDeterminant() << std::endl;

        std::cout << "\nInverse de Matrice 1 :" << std::endl;
        MatrixNumerical<double> invMat1 = mat1.getInverse();
        invMat1.Display();
        
        std::cout << "\n--- Test Matrice Identite ---" << std::endl;
        MatrixNumerical<double> id = MatrixNumerical<double>::getIdentity(3);
        id.Display();

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}