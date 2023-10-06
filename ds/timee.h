
#ifndef _TIME_H_
#define _TIME_H_


class timee{
private:
    int hour, mins;
public:
    timee();
    timee(const int& h, const int& m = 0);
    void addm(const int &m);
    void addh(const int &h);
    void reset(const int &h, const int &m);
    void operator+(const timee &t);
    void operator=(const timee &t);
    timee operator*(const int & t ) const   ; //��������ز�����Ĭ�Ϻ��� 
    friend timee operator*(const int& m, const timee& t) { return t * m;  } // ��Ԫд�����ڲ�Ĭ��inline
    friend std::ostream & operator<<( std::ostream& os, const timee& t);
    friend std::istream& operator<<(std::istream& is, const timee& t);
    void show() const;
};
    
#endif