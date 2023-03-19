#include "Stack.cpp"
#include <cmath>
#include <ctime>
using namespace std;

//Tower of honoi recursive implementation
void towerOfHonoi(char s, char d, char a, int discs){
	if (discs==1)//Obvious
		cout << "Move disc from " << s << " to " << d << '\n';
	else{
		towerOfHonoi(s,a,d,discs-1);
		cout << "Move disc from " << s << " to " << d << '\n';
		towerOfHonoi(a,d,s,discs-1);		
	}
}
struct Activity{
	char source, destination, auxiliary;//auxiliary is used for intermediate transations
	int n;
	Activity(){}
	Activity(char s, char d, char a, int n){
		source = s;
		destination = d;
		auxiliary = a;
		this -> n = n; 
	}
};
//Wrapper function to call recursive function
void towerOfHonoiR(int discs){
	towerOfHonoi('A','B','C',discs);
}
//Tower of honoi iterative implementation using stack
void towerOfHonoi(int discs){
	Stack <Activity> stack(pow(2,discs)); //For n discs, 2 ^ n - 1 calls required
	Activity a('A','B','C', discs);
	stack.push(a);
	while (!stack.isEmpty()){
		a = stack.pop();
		if (a.n == 1)
			cout << "Move disc from " << a.source << " to " << a.destination << '\n';
		else{
			Activity d(a.auxiliary, a.destination, a.source, a.n-1);
			stack.push(d);
			Activity b(a.source, a.destination, a.auxiliary, 1);
			stack.push(b);
			Activity c(a.source, a.auxiliary, a.destination, a.n-1);
			stack.push(c);			
		}	
	}
}
int main(){
	time_t t1, t2;
	towerOfHonoiR(4);
	cout << "\n--------------\n";
	towerOfHonoi(4);
	return 0;
}
