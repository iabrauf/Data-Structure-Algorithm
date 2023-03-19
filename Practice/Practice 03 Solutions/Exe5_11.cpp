#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int gcd(int n, int m){
	if (m<=n && n%m==0)	return m;
	if (n<m)	return gcd(m, n);
	return gcd (m, n%m);
}
int main() {
    cout << gcd(48,36) << '\n';
    cout << gcd(36,48) << '\n';    
    return 0;
}

