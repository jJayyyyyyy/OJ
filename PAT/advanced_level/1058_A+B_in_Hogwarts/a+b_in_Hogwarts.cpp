#include <cstdio>
using namespace std;

int main(){
	long long galleonA, sicklesA, knutsA;
	long long galleonB, sicklesB, knutsB;
	scanf( "%lld.%lld.%lld", &galleonA, &sicklesA, &knutsA );
	scanf( "%lld.%lld.%lld", &galleonB, &sicklesB, &knutsB );

	long long sigmaA = galleonA*17*29 + sicklesA*29 + knutsA;
	long long sigmaB = galleonB*17*29 + sicklesB*29 + knutsB;

	long long sigma = sigmaA + sigmaB;
	long long galleon = sigma/29/17;
	sigma -= galleon*29*17;
	long long sickles = sigma/29;
	long long knuts = sigma % 29;
	printf("%lld.%lld.%lld", galleon, sickles, knuts); 

	return 0;
}