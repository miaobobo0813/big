#ifndef BIG_H
#define BIG_H

#include <string>
using namespace std;

class big
{
private:
    int size, num[5005];
public:
    big(): size(0){};
    big(int size): size(size){}
    void print();
    void intw(int n);
    void stringw(string n);
    bool combig(big b);
    bool comint(int c);
    bool eqbig(big b);
    bool eqint(int c);
    big plusbig(big b);
    big subbig(big b);
    big mulint(int b);
    big diviint(int b);
    big remint(int b);
};

#endif // BIG_H
