class Node{
	public:
		int data;
		Node *next;//TO point to next node, null otherwise
		//Constructor
		Node (int d, Node *n=NULL){
			data = d;
			next = n;
		}
};
