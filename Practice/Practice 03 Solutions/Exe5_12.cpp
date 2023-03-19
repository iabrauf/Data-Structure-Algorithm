#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void cubes(int i, int n){
	cout << i * i * i << ' ';
	if (i==n)	return;
	cubes (i+1, n);
}
void cubes(int n){
	cubes (1, n);
}
int main() {
    cubes(5);
	cout << '\n';
    return 0;
}

