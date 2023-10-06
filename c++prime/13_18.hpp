

#ifndef _EMPLOYEE_H_
#define _EMPLOYRR_H_

#include<iostream>

class employee{
public:
    static int next;
    employee() = default;
    employee(const std::string &s) : id(s), num(next++) {}
    friend std::ostream& operator<<(std::ostream& os, const employee & e){
        os << e.id << ' ' << e.num << std::endl;
        return os;
    }
    ~employee() = default;

private:
    std::string id;
    int num;
};

#endif
