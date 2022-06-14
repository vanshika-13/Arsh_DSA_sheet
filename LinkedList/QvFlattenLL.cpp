/*Given a linked list where every node represents a linked list and contains two pointers of its type: 
(i) Pointer to next node in the main list (we call it ‘right’ pointer in the code below) 
(ii) Pointer to a linked list where this node is headed (we call it the ‘down’ pointer in the code below). 
All linked lists are sorted. See the following example  */

#include <bits/stdc++.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* bottom;

	Node(int x)
	{
		data = x;
		next = NULL;
		bottom = NULL;
	}
};

using namespace std;

void flatten(Node* root);

int main(void)
{
//this code builds the flattened linked list
//of first picture in this article ;
Node* head=new Node(5);
auto temp=head;
auto bt=head;
bt->bottom=new Node(7);
bt->bottom->bottom=new Node(8);
bt->bottom->bottom->bottom=new Node(30);
temp->next=new Node(10);

temp=temp->next;
bt=temp;
bt->bottom=new Node(20);
temp->next=new Node(19);
temp=temp->next;
bt=temp;
bt->bottom=new Node(22);
bt->bottom->bottom=new Node(50);
temp->next=new Node(28);
temp=temp->next;
bt=temp;
bt->bottom=new Node(35);
bt->bottom->bottom=new Node(40);
bt->bottom->bottom->bottom=new Node(45);

flatten(head);
cout << endl;
return 0;
}



struct mycomp {
	bool operator()(Node* a, Node* b)
	{
		return a->data > b->data;
	}
};
void flatten(Node* root)
{
	priority_queue<Node*, vector<Node*>, mycomp> p;
//pushing main link nodes into priority_queue.
	while (root!=NULL) {
		p.push(root);
		root = root->next;
	}

	while (!p.empty()) {
	//extracting min
		auto k = p.top();
		p.pop();
	//printing least element
		cout << k->data << " ";
		if (k->bottom)
			p.push(k->bottom);
	}
	
}
//this code is contributed by user_990i
