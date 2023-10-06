#include<iostream>
#include<vector>
// 数组指针 int (*p) [];


auto func(int i) -> int (*)[10];

constexpr int func() { return 0; }
constexpr int a = 1;
constexpr int b = a + 1;
constexpr int d = func();

inline isshorter(const std::string & s1, const std::string & s2){
    return s1.size() < s2.size();
}

int f(int a, int b);

int (*ff)(int a, int b) = f;

std::vector<ff> x;
int main(void){
    int x = 1;
    const int *px1 = &x; // 底层const 
    int y = 0;
    px1 = &y;
    std::cout << *px1 << std::endl;
    int *const px2 = &x;
    *px2 = 11;
    std::cout << x;
    return 0;
}

int f(int a, int b) { return 0; }