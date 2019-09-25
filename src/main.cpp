#include <iostream>
#include <cmath>
#include "cryptlib.h"

using namespace std;

int main(){
	long long res;

	res = powMod(2, 5, 11);
	cout << res << endl;
	
	long long x, y, gcd;
	ggcd(28, 19, x, y, gcd);
	cout << "x= " << x << " y= " << y << " gcd = " << gcd << endl;

	long long Zab, Zba;
	diffie_hellman(Zab, Zba);
	
	cout << "Zab= " << Zab << " Zba= " << Zba << endl;

	return 0;
}
