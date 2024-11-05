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

void printList(node *l){
	node *T = l;
	while (T != NULL){
		cout << T->data << " ";
		T = T->next;
	}
}

node *addElement(node*T, int x){
	node *temp = createNode(x);
	T->next = temp;
	return temp;
}

node *addAt(node *l, int k, int x){
	node *T = l;
	for (int i = 0; i < k-2; i++){
		T = T->next;
	}
	node *temp = new node;
	temp->data = x;
	temp->next = T->next;
	T->next = temp;

	return l;
}

node *deleteTail(node *l){
	node *T = l;
	while (T->next->next != NULL){
		T = T->next;
	}
	delete(T->next);
	T->next = NULL;
	return l;
}

node *deleteAt(node *l, int k){
	node *T = l;
	for (int i = 0; i < k-2; i++){
		T = T->next;
	}
	node *temp = T->next;
	T->next = T->next->next;
	delete(temp);
	return l;
}

int main()
{
    int k;
	node *l = createNode(1);
	node *T = l;
	for (int i = 2; i <= 10 ; i++){
		T = addElement(T, i);
	}
	cout<<"Mang ban dau: ";
	printList(l);

    addAt(l, 6, 100);
    cout<<"\nMang sau khi chen 100 vao phan tu thu 6: ";
    printList(l);

    deleteTail(l);
    cout<<"\nMang sau khi xoa phan tu cuoi: ";
    printList(l);

    deleteAt(l, 6);
    cout<<"\nMang sau khi xoa phan tu thu 6: ";
    printList(l);

    return 0;
}
