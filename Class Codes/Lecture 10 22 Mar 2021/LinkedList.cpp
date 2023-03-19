#include <iostream>
#include "Node.cpp"

using namespace std;

class LinkedList{
	Node *first;
public:
	LinkedList(){	first = NULL;	}
	void addNewNode(int d){
		if (first == NULL)
			first = new Node(d);
		else{
			Node *newNode = new Node(d);
			newNode -> next = first;
			first = newNode;
		}
	}
	void show(){
		for ( Node *t = first ; t != NULL ; t = t -> next )
			cout << t -> data << ' ';
		cout << '\n' ;
	}
};

int main(){
	LinkedList list;
	list.addNewNode(23);
	list.addNewNode(31);
	list.addNewNode(45);
	list.addNewNode(13);
	list.show();
	return 0;
}
