#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <cmath>
#include <type_traits>

// 1. Définir la classe 'MatrixBase'
template <typename T>
class MatrixBase {
protected:
    // data, un vecteur template en 2D
    std::vector<std::vector<T>> data;
    // rows et cols, des variables 'size_t'
    size_t rows;
    size_t cols;

public:
    // 2. Définir les constructeurs
    MatrixBase(size_t r, size_t c) : rows(r), cols(c) {
        data.resize(rows, std::vector<T>(cols, T()));
    }

    MatrixBase(const std::vector<std::vector<T>>& init_data) {
        rows = init_data.size();
        cols = rows > 0 ? init_data[0].size() : 0;
        data = init_data;
    }
    
    virtual ~MatrixBase() = default;

    // 3. Définir les fonctions 'addElement' et 'getElement'
    void addElement(size_t r, size_t c, const T& val) {
        if (r >= rows || c >= cols) throw std::out_of_range("Index hors limites");
        data[r][c] = val;
    }

    T getElement(size_t r, size_t c) const {
        if (r >= rows || c >= cols) throw std::out_of_range("Index hors limites");
        return data[r][c];
    }

    // 4. Définir les fonctions 'getRows' et 'getCols'
    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    // 5. Définir la fonction 'Display'
    virtual void Display() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << std::setw(8) << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Fonction externe pour le cofacteur (Hint)
template <typename T>
std::vector<std::vector<T>> getCoFactor(const std::vector<std::vector<T>>& mat, size_t p, size_t q, size_t n) {
    std::vector<std::vector<T>> temp(n - 1, std::vector<T>(n - 1));
    size_t i = 0, j = 0;
    for (size_t row = 0; row < n; row++) {
        for (size_t col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return temp;
}

// Fonction récursive pour le déterminant
template <typename T>
T calculateDeterminant(const std::vector<std::vector<T>>& mat, size_t n) {
    T D = 0;
    if (n == 1) return mat[0][0];
    if (n == 2) return (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);

    std::vector<std::vector<T>> temp;
    int sign = 1;
    for (size_t f = 0; f < n; f++) {
        temp = getCoFactor(mat, 0, f, n);
        D += sign * mat[0][f] * calculateDeterminant(temp, n - 1);
        sign = -sign;
    }
    return D;
}

// 6. Définir la classe 'MatrixNumerical'
template <typename T>
class MatrixNumerical : public MatrixBase<T> {
    // S'assurer que T est un type arithmétique
    static_assert(std::is_arithmetic<T>::value, "Le type doit être numérique");

public:
    // 8. Définir les constructeurs
    MatrixNumerical(size_t r, size_t c) : MatrixBase<T>(r, c) {}
    MatrixNumerical(const std::vector<std::vector<T>>& init_data) : MatrixBase<T>(init_data) {}

    // 7. Définir la fonction 'getDeterminant'
    T getDeterminant() const {
        if (this->rows != this->cols) {
            throw std::invalid_argument("La matrice doit être carrée pour calculer le déterminant.");
        }
        return calculateDeterminant(this->data, this->rows);
    }

    // 9. Définir les opérateurs '+', '-' et '*'
    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const {
        if (this->rows != other.rows || this->cols != other.cols) {
            throw std::invalid_argument("Les dimensions doivent correspondre pour l'addition.");
        }
        MatrixNumerical<T> result(this->rows, this->cols);
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < this->cols; ++j) {
                result.addElement(i, j, this->data[i][j] + other.data[i][j]);
            }
        }
        return result;
    }

    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const {
        if (this->rows != other.rows || this->cols != other.cols) {
            throw std::invalid_argument("Les dimensions doivent correspondre pour la soustraction.");
        }
        MatrixNumerical<T> result(this->rows, this->cols);
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < this->cols; ++j) {
                result.addElement(i, j, this->data[i][j] - other.data[i][j]);
            }
        }
        return result;
    }

    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const {
        if (this->cols != other.rows) {
            throw std::invalid_argument("Le nombre de colonnes de la première matrice doit égaler le nombre de lignes de la seconde.");
        }
        MatrixNumerical<T> result(this->rows, other.cols);
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                T sum = 0;
                for (size_t k = 0; k < this->cols; ++k) {
                    sum += this->data[i][k] * other.data[k][j];
                }
                result.addElement(i, j, sum);
            }
        }
        return result;
    }

    // Multiplication par un scalaire pour faciliter l'inverse
    MatrixNumerical<T> operator*(const T& scalar) const {
        MatrixNumerical<T> result(this->rows, this->cols);
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < this->cols; ++j) {
                result.addElement(i, j, this->data[i][j] * scalar);
            }
        }
        return result;
    }

    // 10. Définir la fonction 'getInverse'
    MatrixNumerical<double> getInverse() const {
        if (this->rows != this->cols) {
            throw std::invalid_argument("La matrice doit être carrée.");
        }
        
        T det = getDeterminant();
        if (det == 0) {
            throw std::runtime_error("La matrice est singulière (déterminant = 0), pas d'inverse.");
        }

        size_t n = this->rows;
        MatrixNumerical<double> inv(n, n);
        
        if (n == 1) {
            inv.addElement(0, 0, 1.0 / this->data[0][0]);
            return inv;
        }

        std::vector<std::vector<T>> adj(n, std::vector<T>(n));
        
        // Calcul de la matrice adjointe
        int sign = 1;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                std::vector<std::vector<T>> temp = getCoFactor(this->data, i, j, n);
                sign = ((i + j) % 2 == 0) ? 1 : -1;
                // Transposition directe lors du stockage de l'adjointe (j, i)
                adj[j][i] = sign * calculateDeterminant(temp, n - 1);
            }
        }

        // Division par le déterminant
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                inv.addElement(i, j, static_cast<double>(adj[i][j]) / static_cast<double>(det));
            }
        }

        return inv;
    }

    // 11. Définir l'opérateur '/' (Matrice * Inverse de la seconde)
    MatrixNumerical<double> operator/(const MatrixNumerical<T>& other) const {
        // A / B = A * B^-1
        if (this->cols != other.rows) {
             throw std::invalid_argument("Dimensions incompatibles pour la division (A * B^-1).");
        }
        
        MatrixNumerical<double> invB = other.getInverse();
        
        // Conversion de this en double pour la multiplication
        MatrixNumerical<double> thisDouble(this->rows, this->cols);
        for(size_t i=0; i<this->rows; ++i)
             for(size_t j=0; j<this->cols; ++j)
                  thisDouble.addElement(i, j, static_cast<double>(this->data[i][j]));
                  
        return thisDouble * invB;
    }

    // 12. Définir la fonction statique 'getIdentity'
    static MatrixNumerical<T> getIdentity(int size) {
        if (size <= 0) throw std::invalid_argument("La taille doit être > 0");
        MatrixNumerical<T> id(size, size);
        for (int i = 0; i < size; ++i) {
            id.addElement(i, i, 1);
        }
        return id;
    }
};

#endif