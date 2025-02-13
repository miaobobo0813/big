#include "big.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void big::intw(int n)
{
    size = 0;
    while (n)
    {
        num[++size] = n%10;
        n /= 10;
    }
}

void big::stringw(string n)
{
    size = n.size();
    for (int i = 1; i <= size; i++)
    {
        num[i] = n[size-i] - '0';
    }
}

void big::print()
{
    for (int i = size; i >= 1; i--)
    {
        cout << num[i];
    }
    cout << endl;
}

bool big::combig(big b)
{
    if (size != b.size)
    {
        return size > b.size;
    }
    for (int i = size; i >= 1; i--)
    {
        if (num[i] != b.num[i])
        {
            return num[i] > b.num[i];
        }
    }
    return true;
}

bool big::comint(int c)
{
    big b;
    b.intw(c);
    if (size != b.size)
    {
        return size > b.size;
    }
    for (int i = size; i >= 1; i--)
    {
        if (num[i] != b.num[i])
        {
            return num[i] > b.num[i];
        }
    }
    return true;
}


bool big::eqbig(big b)
{
    if (size != b.size)
    {
        return false;
    }
    for (int i = size; i >= 1; i--)
    {
        if (num[i] != b.num[i])
        {
            return false;
        }
    }
    return true;
}

bool big::eqint(int c)
{
    big b;
    b.intw(c);
    if (size != b.size)
    {
        return false;
    }
    for (int i = size; i >= 1; i--)
    {
        if (num[i] != b.num[i])
        {
            return false;
        }
    }
    return true;
}

big big::plusbig(big b)
{
    int up = 0;
    big c(max(size, b.size));
    for (int i = 1; i <= c.size; i++)
    {
        int tmp = num[i] + b.num[i] + up;
        c.num[i] = tmp % 10;
        up = tmp / 10;
    }
    if (up)
    {
        c.num[++c.size] = up;
    }
    return c;
}

big big::subbig(big b)
{
    if (!combig(b))
    {
        throw runtime_error("The answer is negative number.");
    }
    int down = 0;
    big c(max(size, b.size));
    for (int i = 1; i <= c.size; i++)
    {
        int tmp = num[i] - b.num[i] - down;
        if (tmp < 0)
        {
            down = 1;
            c.num[i] = tmp + 10;
        }
        else
        {
            down = 0;
            c.num[i] = tmp;
        }
    }
    while (c.num[c.size] == 0 && c.size > 1)
    {
        c.size--;
    }
    return c;
}

big big::mulint(int b)
{
    int up = 0;
    big c(size);
    for (int i = 1; i <= c.size; i++)
    {
        int tmp = num[i]*b + up;
        c.num[i] = tmp % 10;
        up = tmp / 10;
    }
    while (up)
    {
        c.num[++c.size] = up % 10;
        up /= 10;
    }
    return c;
}

big big::diviint(int b)
{
    big c(size);
    int r = 0;
    for (int i = c.size; i >= 1; i--)
    {
        int tmp = r*10+num[i];
        c.num[i] = tmp / b;
        r = tmp % b;
    }
    while (c.num[c.size] == 0 && c.size > 1)
    {
        c.size--;
    }
    return c;
}


big big::remint(int b)
{
    big c=diviint(b);
    big tmp=c.mulint(b);
    big ans = subbig(tmp);
    return ans;
}
