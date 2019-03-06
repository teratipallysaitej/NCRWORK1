#include<iostream>
#include<queue>
using namespace std;
struct node {
	int data;
	node* l;
	node* r;
};
node* create(int y) {
	node* temp = new node();
	temp->data = y;
	temp->l = NULL;
	temp->r = NULL;
	return temp;
}
void inorder(node* temp) {
	if (temp == NULL) {
		return;
	}
	inorder(temp->l);
	cout << temp->data << endl;
	inorder(temp->r);
}
node* insert(node* head, int data) {
	//node* temp;
	if (head == NULL) {
		head = create(data);
		return head;
	}
	else if (head->data >= data) {
		head->l = insert(head->l, data);
	}
	else if (head->data < data) {
		head->r = insert(head->r, data);
	}
	return head;
}
node* min(node* node1) {
	node* n = node1;
	while (n->l != NULL) {
		n = n->l;
	}
	return n;
}
node* search(node* head, int key) {
	if (head == NULL) {
		return NULL;
	}
	if (head->data == key) {
		return head;
	}
	else if (head->data >= key) {
		search(head->l, key);
	}
	else {
		search(head->r, key);
	}
}

node* delete1(node* temp, int key) {
	//node* temp;
	if (temp == NULL) {
		//cout<<"no element exists:";
		return temp;
	}
	if (temp->data > key) {
		temp->l = delete1(temp->l, key);
	}
	else if (temp->data < key) {
		temp->r = delete1(temp->r, key);
	}
	else {
		if (temp->r == NULL) {
			node* node = temp->l;
			delete temp;
			return node;
		}
		else if (temp->l == NULL) {
			node* node = temp->r;
			delete temp;
			return node;
		}

		node* node = min(temp->r);
		temp->data = node->data;
		temp->r = delete1(temp->r, temp->data);
	}
	return temp;

}
int height(node* temp, int hl, int hr) {
	if (temp == NULL) {
		return 0;
	}
	else if (temp->l == NULL && temp->r == NULL) {
		return 1;
	}
	hl = height(temp->l, hl, hr);
	hr = height(temp->r, hl, hr);
	return hl + hr;
}
void levelorder(node* temp) {
	queue<node*> q;
	q.push(temp);
	while (!q.empty()) {
		node* t1;
		t1 = q.front();
		cout << t1->data << endl;
		if (t1->l != NULL) {
			q.push(t1->l);
		} if (t1->r != NULL) {
			q.push(t1->r);
		}
		q.pop();
	}
}
int main() {
	node* root = NULL;
	root = insert(root, 5);
	insert(root, 6);
	insert(root, 7);
	insert(root, 23);
	insert(root, 45);
	insert(root, 4);
	insert(root, 14);
	//levelorder(root);
	int h = height(root, 0, 0);
	cout << h;
	//delete1(root,5);
	//node* temp=search(root,45);
	//cout<<temp->data;
	//inorder(root);
	system("pause");
	return 0;
}