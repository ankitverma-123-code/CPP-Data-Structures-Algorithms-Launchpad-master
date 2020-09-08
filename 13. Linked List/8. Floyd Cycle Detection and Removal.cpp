#include <iostream>
using namespace std;

class node {
public:
	int data;
	node*next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

// Linked List Class (Object Oriented)
// class LinkedList{
// 	node*head;
// 	node*tail;

// public:
// 	LinkedList(){

// 	}

// 	void insert(int d){
// 		...
// 		...

// 	}
// }

// Functions (Procedural programming)

void insertAtHead(node *&head, int val) {

	if (head == NULL) {
		head = new node(val);
		return;
	}

	node *temp = new node(val);
	//(*temp).next = head;
	temp->next = head;

	head = temp;
}

int length(node*head) {
	int count = 0;
	while (head != NULL) {
		head = head->next;
		count++;
	}

	return count;

}

void insertAtTail(node *&head, int val) {
	if (head == NULL) {
		head = new node(val);
		return;
	}

	// Take curr to last node
	node *curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}

	node *temp = new node(val);
	curr->next = temp;
}

void insertAtMiddle(node *&head, int pos, int val) {

	if (head == NULL || pos == 0) {
		insertAtHead(head, val);
		return;
	} else if (pos > length(head)) {
		insertAtTail(head, val);
		return;
	}

	// take pos-1 jumps
	node *curr = head;
	for (int i = 0; i < pos - 1; i++) {
		curr = curr->next;
	}

	node *temp = new node(val);

	temp->next = curr->next;
	curr->next = temp;
}

void deleteHead(node *&head) {
	if (head == NULL) {
		return;
	}
	node *temp = head;
	head = head->next;
	delete temp;
}

void deleteTail(node *&head) {
	node *curr =  head;
	while (curr->next->next != NULL) {
		curr = curr->next;
	}

	node *temp = curr->next;
	curr->next = NULL;
	delete temp;
}

void deleteMiddle(node *&head, int pos) {

	if (head == NULL) {
		return;
	} else if (pos > length(head)) {
		deleteTail(head);
		return;
	} else if (pos == 0) {
		deleteHead(head);
		return;
	}

	node *curr = head;

	for (int i = 0; i < pos - 1; i++) {
		curr = curr->next;
	}

	node *temp = curr->next;
	curr->next = temp->next; // or curr->next->next;
	delete temp;

}

bool search(node *head, int key) {
	node *curr = head;

	while (curr != NULL) {
		if (curr->data == key) return 1;
		curr = curr->next;
	}

	return 0;
}

bool searchRecursive(node *head, int key) {

	// Base Case
	if (head == NULL) {
		return 0;
	}

	if (head->data == key) {
		return 1;
	}
	return searchRecursive(head->next, key);

}

void print(node *head) {
	while (head != NULL) {
		cout << head->data << "->";
		head = head->next;
	}
}

// Taking input

// void take_input(node *&head){
// 	// declare head pointer in the main function and then take input
// }

// From file
node* take_input_file() {
	node *head = NULL;
	int x;
	while (cin >> x) {
		insertAtTail(head, x);

	}
	return head;
}
// From console
node* take_input() {
	node* head = NULL;
	int x; cin >> x;
	while (x != -1) {
		insertAtTail(head, x);
		cin >> x;
	}
	return head;
}

// Operator Overloading
ostream& operator<<(ostream &os, node *head) {
	print(head);
	return os;
}

istream& operator>>(istream &is, node*&head) {
	head = take_input();
	return is;
}

bool detectCycle(node *head) {
	node *slow = head;
	node *fast = head;

	while (fast != NULL && fast->next != NULL) {

		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow) {

			slow = head;
			while (slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}


			return 1;
		}
	}

	return 0;
}


int main() {

	node *a;
	cin >> a;
	cout << a << endl;
	a = mergeSort(a);
	cout << a << endl;
}