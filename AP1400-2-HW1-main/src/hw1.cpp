#include "hw1.h"

#include<random>
#include<ctime>

Matrix algebra::zeros(const size_t &n, const size_t & m ) const {
    Matrix ret(n, std::vector<double>(m, 0));
    return ret;
}

Matrix algebra::ones(size_t n, size_t m ){
    Matrix ret(n, std::vector<double>(m, 0));
    return ret;
}

Matrix algebra::random(size_t n, size_t m, double min, double max ){
    std::default_random_engine dre{std::random_device{}()};
    dre.seed(time(NULL));
    std::uniform_real_distribution<double> ran(min, max);
    Matrix ret(n, std::vector<double>(m));
    for(auto &i : ret){
        for(auto & j : i){
            j = ran();
        }
    }
    return ret;
}

void algebra::show( const Matrix& matrix) const{
    std::cout << std::endl;
    for(const auto & i: matrix ){
        for( const auto & j : i ){
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    }
}

Matrix algebra::multiply(const Matrix& matrix, double c ){
    Matrix ret(matrix);
    for( auto& i : ret){
        for(auto &j : i){
            j *= c;
        }
    }
    return ret;
}

Matrix algebra::multiply(const Matrix& matrix1, const Matrix& matrix2 ){
    int n = matrix1.size(), m = matrix2[0].size(), t = matrix2.size();
    Matrix ret(n, std::vector<double>(m,0) );
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++ ){
            for (int k = 0; k < t; k++){
                ret[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return ret;
}

Matrix algebra::sum( const Matrix& matrix, double c ){
    Matrix ret(matrix);
    for(auto & i: matrix ){
        for( auto & j : i){
            j += c;
        }
    }
    return ret;
}

Matrix algebra::sum(const Matrix & matrix1, const Matrix & matrix2){
    Matrix ret(matrix1);
    for (int i = 0; i < matrix1.size(); i++){
        for (int j = 0; j < matrix1[0].size(); j++){
            ret[i][j] += matrix2[i][j];
        }
    }
    return ret;
}

Matrix algebra::transpose(const Matrix& matrix){
    Matrix ret(Matrix[0].size(), std::vector<double>(matrix.size()));
    
}