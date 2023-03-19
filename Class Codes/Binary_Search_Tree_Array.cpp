#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define NONODE -1

class BSTreeArray{
	int *x, size;
public:
	BSTreeArray(const int SIZE){
		size = SIZE;
		this->x = new int[size];
		for (int i=0;i<size;i++)
			x[i] = NONODE;
	}
	//Worker Function
	void insert(int index, int data){
		if (index>=size)	return;
		if (x[index] == NONODE)	{
			x[index] = data;
			return;
		}
		if (x[index]>data)	
			insert(index*2, data);
		else
			insert(index*2+1, data);
	}
	//Wrapper Function
	void insert(int data){
		insert(1, data);
	}
	int findHighest(int index){
		while (index*2+1 < size && x[index*2+1]!=NONODE)
			index = index * 2 + 1;
		return index;
	}
	int findLowest(int index){
		while (index*2 < size && x[index*2]!=NONODE)
			index = index * 2 ;
		return index;
	}
	bool isNode(int index){
		if (index<size && x[index] != NONODE)	return true;
		return false;
	}
	void deleteNode(int index, int data){
		if (index>=size)		return;
		if (x[index]== NONODE)	return;
		if (x[index]>data)	
			deleteNode(index*2, data);
		else if (x[index]<data)
			deleteNode(index*2+1, data);
		else{//data found
			if (!isNode(index*2) && !isNode(index*2+1)){
				x[index] = NONODE;
				return;
			}
			else if (!isNode(index*2)){
				int lowestIndex = findLowest(index*2+1);
				x[index] = x[lowestIndex];
				deleteNode (lowestIndex, x[lowestIndex]);
			}
			else{
				int highestIndex = findHighest(index*2);
				x[index] = x[highestIndex];
				deleteNode (highestIndex, x[highestIndex]);
			}
		}	
	}	
	void deleteNode(int data){
		deleteNode(1, data);
	}
	int findNode(int index, int data){
		if (index>=size)		return -1;
		if (x[index]== NONODE)	return -1;
		if (x[index]>data)	
			return findNode(index*2, data);
		else if (x[index]<data)
			return findNode(index*2+1, data);
		else
			return index;
	}	
	int findNode(int data){
		return findNode(1, data);
	}
	void inOrder(int i){
		if (i >= size || x[i] == NONODE)
			return;
		inOrder(2*i);
		cout << x[i] << ' ';
		inOrder(2*i+1);
	}
	void inOrder(){
		inOrder(1);
		cout << '\n';
	}
	int findHeight(int i){
		if (i>=size || x[i]==NONODE)	return -1;
		int h1 = findHeight(2*i);
		int h2 = findHeight(2*i+1);
		if (h1 > h2)	return h1+1;
		else 			return h2+1;
	}
	int findHeight(){
		return findHeight(1);
	}
	~BSTreeArray(){	delete []x;	}
};
int main(){
	srand(time(0));
	int d ;
	BSTreeArray tree(2048);
	for (int i=0;i<20;i++){
		d = rand();
		cout << d << ' '; 
		tree.insert(d);
	}
	cout << '\n';
	tree.inOrder();
	cout << "Height:" << tree.findHeight() << '\n';
	cout << "Enter node to delete:";
	cin >> d;
	tree.deleteNode(d);
	tree.inOrder();
	cout << "Enter node to delete:";
	cin >> d;
	tree.deleteNode(d);
	tree.inOrder();
	cout << "Enter node to delete:";
	cin >> d;
	tree.deleteNode(d);
	tree.inOrder();
	return 0;
}
