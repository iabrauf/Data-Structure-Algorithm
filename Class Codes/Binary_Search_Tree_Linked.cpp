#include <iostream>

using namespace std;

class BTNode{
	public:
		int data;
		BTNode *left, *right;
		BTNode (int d, BTNode *left=NULL, BTNode *right=NULL){
			data = d;
			this->left = left;
			this->right = right;
		}
};
class BTree{	//Linked Implementation
	BTNode *root;
public:
	BTree(){	root = NULL;}
	BTNode* insert(int d, BTNode *temp){
		if (temp==NULL){
			BTNode *t = new BTNode(d);
			return t;
		}
		if (temp->data > d)
			temp -> left = insert (d, temp->left);
		else
			temp -> right = insert (d, temp->right);
		return temp;
	}
	//Wrapper Function
	void insert(int d){
		root = insert (d, root);
	}
	void inorder(BTNode *temp){
		if (temp!=NULL){
			inorder(temp->left);
			cout << temp -> data << ' ';
			inorder(temp->right);
		}
	}
	void inorder(){
		inorder(root);
		cout << '\n';
	}
	bool search(int d, BTNode *temp){
		if (temp==NULL)		return false;
		if (temp->data == d)	return true;
		if (temp->data > d)		return search(d, temp->left);
		return search(d, temp->right);
	}
	bool search(int d){
		return search(d, root);
	}
	//left most node address required
	BTNode* leftMost(BTNode *temp){
		if (temp->left==NULL)	return temp;
		return leftMost(temp->left);	
	}
	//Right most node address required
	BTNode* rightMost(BTNode *temp){
		if (temp->right==NULL)	return temp;
		return rightMost(temp->right);	
	}
	BTNode* deleteNode(int d, BTNode *temp){
		BTNode *next;
		if (temp==NULL)		return NULL;
		else if (temp->data>d)	temp->left = deleteNode(d, temp->left);
		else if (temp->data<d)	temp->right = deleteNode(d, temp->right);
		else{//Node found and to be deleted
			if (temp->left == NULL && temp->right == NULL){
				delete temp;
				return NULL;
			} 	
			else if (temp->left == NULL){
				next = temp->right;
				delete temp;
				temp = next;
			} 	
			else if (temp->right == NULL){
				next = temp->left;
				delete temp;
				temp = next;
			}
			else{
				next = rightMost (temp->left);
				temp->data = next->data;
				temp->left = deleteNode(next->data, temp->left);
			}
			return temp;
		}
	}
	void deleteNode(int d){
		root = deleteNode (d, root);
	}
	int findHeight(BTNode *temp){
		if (temp==NULL)	return -1;
		int lh = findHeight(temp->left);
		int rh = findHeight(temp->right);
		if (lh>rh)	return lh+1;
		else		return rh+1;
	}
	int findHeight(){
		return findHeight(root);
	}
};

int main(){
	BTree tree;
	tree.insert(45);
	tree.insert(35);
	tree.insert(25);
	tree.insert(95);
	tree.insert(15);
	tree.insert(65);
	tree.insert(85);
	tree.insert(5);
	/*tree.insert(5);
	tree.insert(15);
	tree.insert(25);
	tree.insert(35);
	tree.insert(45);
	tree.insert(65);
	tree.insert(85);
	tree.insert(95);*/
	tree.inorder();
	cout << "Height:"	<< tree.findHeight() << '\n';
	tree.deleteNode(45);
	tree.inorder();
	return 0;
}
