#include <iostream>

using namespace std;

#define DUMMY 0

class LinkedList{
	class Node{
		public:
			int data;
			Node *next;
			Node(int d, Node *n=NULL){
				data = d ;
				next = n ;
			}
	};
	Node *first, *last;
public:
	LinkedList(){	first = new Node(DUMMY);	last = NULL;	}
	int getCount() const{
		return first->data;
	}
	bool isPalindrome(){
		int *x = new int[first -> data], i=0;
		for (Node *t = first -> next ; t != NULL ; t = t->next)
			x[i++] = t -> data;
		for (i=0;i<first->data/2;i++)
			if (x[i] != x[first->data-i-1])
				return false;
		return true;
	}
	void addNodeAtStart(int d){
		Node *newNode =new Node(d);
		newNode -> next = first -> next;
		first -> next = newNode;
		first -> data ++;
		if (last == NULL)	last = newNode;
	}
	void addNodeAtEnd(int d){
		if (last == NULL)	addNodeAtStart(d);
		else{
			last -> next = new Node(d);
			first -> data ++;
			last = last -> next;
		}
	}
	void addNodeAfter(int d1, int d2){
		Node *t;
		for (t = first->next ; t != NULL && t -> data != d1; t = t -> next);
		if (t != NULL){
			Node *newNode = new Node(d2);
			newNode -> next = t -> next;
			t -> next = newNode;
			first -> data ++;
			if (t == last)	last = newNode;
		}
	}
	bool isExist(int d){
		for (Node *t = first -> next ; t != NULL ; t = t -> next )
			if (t -> data == d)
				return true;
		return false;
	}
	void addNodes(int *x, const int SIZE){
		if (SIZE == 0)	return;
		int i=0;
		if (first -> next == NULL)	{	addNodeAtStart(x[0]);	i=1;	}
		for ( ;i < SIZE ; i++ ){
			if (!isExist(x[i])){
				last -> next = new Node(x[i]);
				first -> data ++;
				last = last -> next;
			}
		}
	}
	void deleteNodeFromStart(){
		if (first->next!=NULL){
			Node *t = first -> next;
			first -> next = t -> next; //t->next may be second node or NULL
			first -> data --;
			delete t;
			if (first -> next == NULL)		last = NULL;
		}
	}
	void deleteNodeFromEnd(){
		if (last!=NULL){
			if (first -> next == last)		deleteNodeFromStart();						
			else{
				Node *t = first;
				for ( ; t->next != last; t = t -> next );//Move to second last node
				first -> data --;
				delete t->next;
				t->next = NULL;
				last = t;
			}
		}
	}
	void splitLargerNodes(){
		if (first -> next == NULL)	return;
		Node *t;
		int d1, d2;
		for (t = first->next ; t != NULL ; t = t -> next){
			d1 = d2 = t -> data / 2;
			if (t -> data > 50){
				if (t -> data %2 != 0)	d1++;
				t -> data = d1;
				Node *newNode = new Node(d2);
				first -> data ++;
				newNode -> next = t -> next;
				t -> next = newNode;
				t = t -> next;		
			}
		}
			//Check if last node is also splitted, shift last pointer
			if (last -> next != NULL)
				last = last -> next;
	}
	void removeNodesWithNegativeValues(){
		if (first -> next == NULL)	return;
		Node *t, *toDelete;
		for (t = first ; t->next != NULL ; t = t -> next)
			if (t -> next -> data < 0){
				toDelete = t -> next;
				t -> next = toDelete -> next;
				//Check if last node is deleted, shift last 
				if (toDelete == last)
					last = t;
				delete toDelete;
				first -> data --;
				//terminate loop if last node is deleted
				if (t==last)	break;
			}
	}
	void show(){
		if ( first -> next == NULL)
			cout << "List is empty\n";
		for ( Node *t = first -> next ; t != NULL ; t = t -> next )
			cout << t -> data << ' ';
		cout << '\n' ;
	}
	void showInPairs(){
		if ( first -> next == NULL || first -> next -> next == NULL)
			cout << "List is empty or have one node only\n";
		else
			for ( Node *t = first -> next ; t -> next != NULL ; t = t -> next )
				cout << t -> data << ' ' << t -> next -> data << '\n' ;
	}
};

int main(){
	LinkedList list;
	list.addNodeAtStart(23);
	list.addNodeAtStart(-31);
	list.addNodeAtStart(54);
	list.addNodeAtStart(-13);
	list.show();
	cout << "Node Count:" << list.getCount() << '\n';
	list.addNodeAtEnd(73);
	list.addNodeAtEnd(61);
	list.addNodeAtEnd(-61);
	list.show();
	cout << "Node Count:" << list.getCount() << '\n';
	list.splitLargerNodes();
	list.show();
	cout << "Node Count:" << list.getCount() << '\n';
	list.removeNodesWithNegativeValues();
	list.show();
	cout << "Node Count:" << list.getCount() << '\n';
	int a[] = {1,2,31,27,5};
	list.addNodes(a, 5);
	list.show();
	cout << "Node Count:" << list.getCount() << '\n';
	list.showInPairs();
	if (list.isPalindrome())
		cout << "List is palindrome\n";
	else
		cout << "List is not palindrome\n";
	LinkedList palindrome;
	palindrome.addNodeAtStart(23);
	palindrome.addNodeAtStart(45);
	palindrome.addNodeAtStart(61);
	palindrome.addNodeAtStart(61);
	palindrome.addNodeAtStart(45);
	palindrome.addNodeAtStart(23);
	if (palindrome.isPalindrome())
		cout << "List is palindrome\n";
	else
		cout << "List is not palindrome\n";
	return 0;
}
