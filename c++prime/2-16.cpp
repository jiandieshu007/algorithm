#include<iostream>

int main(){
    const int a = 1;
    int const b = 2;
    const int *pa = &a; // 不允许改变 所指向对象的值 但可以改变所指的对象 故为底层const
                        /*
                            std::cout<<*pa<<endl;
                            pa = &b;
                            std::cout<<*pa;  ans: 1 2
                        */
    const int &ra = a;
                            std::cout<<ra<<endl;
                            ra = b;
                            std::cout<<ra;
    return 0;
}