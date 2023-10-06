#include<iostream>
#include<cstring>
using namespace std;

int main(){
    const char * s1 = "xx", *s2 = "_xx";

    char *r = new char[strlen(s1) + strlen(s2) + 1];
    strcpy(r, s1);
    strcat(r, s2);
    cout << r << endl;
    delete[] r;
    return 0;
}

