#include "cryptlib.h"
#include <cstdlib>
#include <cmath>

//a^b mod p
long long powMod(long long a, long long b, long long p){
	long long res = 1, s = a;
	while(b) {
		if(b & 1){
			res = res * s % p;
		}
		s = s * s % p;
		b >>=1;

	}
	return res;
}

void ggcd(long long a, long long b, long long &x, long long &y, long long &gcd){
	long long u[3] = {a, 1, 0};
	long long v[3] = {b, 0, 1};
	long long t[3];
	long long q; 
	while(v[0] != 0){
		q = u[0] / v[0];
		t[0] = u[0] % v[0];
		t[1] = u[1] - q * v[1];
		t[2] = u[2] - q * v[2];
		for(int i = 0; i < 3; i++){
			u[i] = v[i];
			v[i] = t[i];
		}
	}
	x = u[1];
	y = u[2];
	gcd = u[0];
}

bool isPrime(int p){
	if(p<=1){
		return false;
	}
	int b = pow(p, 0.5); 
	for(int i=2; i<=b; ++i){
		if((p%i)==0){ 
			return false;
		} 
 	} 
 
	return true; 
 
}
void diffie_hellman(long long &Zab, long long &Zba){
	long long p = 1;
	long long q = 1;
	srand(time(0));
	while(!(isPrime(p) && isPrime(q))){
		p = rand() % 10000;
		if(isPrime(p)){
			q = (p-1) / 2;
		}
	}
	long long Xa = rand() % p;
	long long Xb = rand() % p;

	long long Ya = powMod(q, Xa, p);
	long long Yb = powMod(q, Xb, p);

	Zab = powMod(Yb, Xa, p);
	Zba = powMod(Ya, Xb, p);

}
		




		 
