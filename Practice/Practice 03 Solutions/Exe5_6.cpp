#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string putCommas(int i, string s, int n){
	if (i==0)	return s;
	s = (char)(i % 10 + '0') + s ;
	if (n%3==0)	s = "," + s;
	return putCommas(i/10, s, n+1);
}
string putCommas(int i){
	string s="";
	return putCommas(i, s, 1);
}
int main() {
    cout << putCommas(12345423) << '\n';
    return 0;
}

