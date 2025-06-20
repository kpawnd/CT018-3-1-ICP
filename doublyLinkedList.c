#include <stdio.h>

/*
A doubly linked-list.

1) Setup a doubly linked-list (With n members).
2) Traverse through it.
*/

typedef struct entry {

	/*
	For a doubly linked-list, you need
	a head and tail, i.e *next & *prev
	*/

	int	value;
	struct  entry *next;
	struct  entry *prev;
} Entry;


int main(void) {

	Entry n1,n2,n3;
	Entry *head;
	Entry *tail;

	head = &n1;
	tail = &n3;

	n1.value = 100;
	n2.value = 200;
	n3.value = 300;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;

	n1.prev = NULL;
	n2.prev = &n1;
	n3.prev = &n2;

	Entry *curr = head;
	while (curr != NULL) {
		printf("%d\n", curr->value);
		curr = curr->next;
	}

	curr = tail;
	while (curr != NULL) {
		printf("%d\n", curr->value);
		curr = curr->prev;
	}

	return 0;
}
