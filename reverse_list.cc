#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void pointer_swap(Node** a, Node** b){
	*a=(Node*)((uintptr_t)*a^(uintptr_t)*b); *b=(Node*)((uintptr_t)*a^(uintptr_t)*b); *a=(Node*)((uintptr_t)*a^(uintptr_t)*b);
}
	

struct Node * reverse_ll(struct Node * head){
  struct Node * temp = NULL;
  while(head) {
      pointer_swap(&temp,&head->next);
      pointer_swap(&temp,&head); 
  }
  return temp;
}

void printList(Node* n)
{
	while (n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
}

int main()
{
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	// allocate 3 nodes in the heap
	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 1; // assign data in first node
	head->next = second; // Link first node with second

	second->data = 2; // assign data to second node
	second->next = third;

	third->data = 3; // assign data to third node
	third->next = NULL;

	cout << endl;
	printList(head);
	Node* newhead = reverse_ll(head);
	cout << endl;
	printList(newhead);

	return 0;
}

// This is code is contributed by rathbhupendra

