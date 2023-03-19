#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int binomialCoeff(int n, int k){
	if (k==0 || k==n)	return 1;
	return binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k);
}
int main() {
    cout << binomialCoeff(6,4) << '\n';
    return 0;
}

