#include<iostream>
#include <cstdlib>
#include<vector>
#include<random>
#include<ctime>

int main(){
    /*
    //std::random_device rd;  // Will be used to obtain a seed for the random number engine
    //rd.seed(0);
    //std::mt19937 gen(rd());
    std::default_random_engine dre{ std::random_device{}()};
    dre.seed(time(NULL));
    std::uniform_real_distribution<double> ran(0, 1);
    std::vector<std::vector<double>> v(3, std::vector<double>( 3 , ran(dre) ) );

    for( auto i : v){
        for(auto j : i){
            j = ran(dre);
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    }
    */
    return 0;
}