#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

node *createNode(int x){
    node *temp = new node;
    temp->next = NULL;
    temp->data = x;
    return temp;
}

node *addElement(node*p, int x){
	node *temp = createNode(x);
	p->next = temp;
	return temp;
}

node *addAt(node *l, int k, int x){
	node *p = l;
	for (int i = 0; i < k-1; i++){
		p = p->next;
	}
	node *temp = new node;
	temp->data = x;
	temp->next = p->next;
	p->next = temp;

	return l;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
