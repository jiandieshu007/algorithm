#include<iostream>

unsigned int buf_size = 256;

int txt_size(){
    return 128;
}

int main(){
    int nums[] = {1, 2, 3, 4, 5};
    int *p = nums;
    while( p != &nums[5]){
        std::cout << *p << std::endl;
        p++;
    }
    return 0;
}