#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

float addFirstNTerms(int i, int n){
	if (i>n)	return 0;
	if (i%2==0)
		return 1/(float)i+addFirstNTerms(i+1, n);
	else
		return -1/(float)i+addFirstNTerms(i+1, n);
}
float addFirstNTerms(int n){
	return 1+addFirstNTerms(2, n);
}
int main() {
    cout << addFirstNTerms(7) << '\n';
    return 0;
}

