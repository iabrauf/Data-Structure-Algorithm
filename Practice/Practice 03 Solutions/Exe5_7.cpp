#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void syracuseSequence(int a){
	if (a==1){
		cout << a << '\n';
		return;
	}
	cout << a << ' ';
	if (a%2==0)
		syracuseSequence(a/2);
	else
		syracuseSequence(3*a+1);
}
int main() {
    syracuseSequence(19);
    return 0;
}

