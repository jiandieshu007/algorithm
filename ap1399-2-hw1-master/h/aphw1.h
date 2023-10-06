#ifndef _APHW1_H_
#define _APHW1_H_

#include<iostream>
#include<vector>

using Matrix = std::vector<std::vector<double>>;

Matrix multiply(Matrix& a, Matrix& b){
    int n = a.size(), m = b[0].size(), p = a[0].size();
    Matrix ret = Matrix(n, std::vecotr<double>( m, 0 ) );
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            for (int k = 0; k < p; ++k){
                ret[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ret;
}

Matrix transpose(Matrix& a){
    int n = a.size(), m = a[0].size();
    Matrix ret = Matrix(m, std::vector<double>(n));
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            ret[i][j] = a[j][i];
        }
    }
    return ret;
}

double det(Matrix& a){
    
}