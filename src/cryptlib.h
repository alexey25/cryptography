#ifndef CRYPTLIB_H
#define CRYPTLIB_H

#include <iostream>


using namespace std;

long long powMod(long long a, long long b, long long p);
void ggcd(long long a, long long b, long long &x, long long &y, long long &gcd);
void diffie_hellman(long long &Zab, long long &Zba);

#endif
