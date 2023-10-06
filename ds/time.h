
#ifndef _TIME_H_
#define _TIME_H_


class time{
private:
    int hour, mins;
public:
    time();
    time(const int& h, const int& m = 0);
    void addm(const int &m);
    void addh(const int &h);
    void reset(const int &h, const int &m);
//    void operator+(const time &t);
//    void operator=(const time &t);
    void show() const;
};

#endif