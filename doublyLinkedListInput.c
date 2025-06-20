#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int 	    value;
	struct node *next; // two self relational structs
	struct node *prev;

}Node;



int main(void) {

	/*
	Obtain number of nodes from user.
	*/

	int n;
	printf("How many nodes?\n");
	scanf("%d", &n);

	if ( n <= 0 ) {
		printf("Invalid number of nodes.\n");
		return 1;
	}

	/*
	Since there is nothing init yet, we set
	to NULL.
	*/

	Node *head = NULL;
	Node *tail = NULL;
	Node *newNode, *prevNode = NULL;

	for (int i = 0; i < n; i++) {

		/*
		Create a memory block for newNode.
		*/

		newNode = (Node *)malloc(sizeof(Node));

		if (newNode == NULL) {
			perror("Error allocating memory.");
			return 1;
		}

		printf("Input value for node %d\n", i+1);
		scanf("%d", &newNode->value);

		/*
		We do not know what's next, so
		next node assigned NULL,

		for the first iteration previous node is
		assigned prevNode which is  NULL.

		second iteration it will point to the previously
		created node.
		*/

		newNode->next = NULL;
		newNode->prev = prevNode;

		if (prevNode != NULL) {
		prevNode->next = newNode;
		} else {
			head = newNode;
		}
		
		prevNode = newNode;
	}


	tail = prevNode;
	printf("\nForward traversal:\n");
	Node *curr = head;
	while (curr != NULL) {
	printf("%d ", curr->value);
	curr = curr->next;
	}

	// Backward traversal
	printf("\nBackward traversal:\n");
	curr = tail;
	while (curr != NULL) {
	printf("%d ", curr->value);
	curr = curr->prev;
	}

	// Free memory
	curr = head;
	while (curr != NULL) {
	Node *temp = curr;
	curr = curr->next;
	free(temp);
	}

	return 0;
}

