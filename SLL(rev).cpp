#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* link;
};

struct node* create(struct node* first) {
	struct node *nn, *temp;
	char ch;
	do {
		nn = (struct node*)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d", &nn->data);
		nn->link = NULL;
		if (first == NULL) {
			first = nn;
			temp = nn;
		}
		else {
			temp->link = nn;
			temp = nn;
		}
		printf("Continue on create: ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');
	return first;
}

void display(struct node* f) {
	if (f == NULL) {
		printf("List is empty\n");
	}
	else {
		struct node* temp = f;
		while (temp != NULL) {
			printf("%3d", temp->data);
			temp = temp->link;
		}
		printf("\n");
	}
}

struct node* reverse(struct node* head) {
	struct node *prev = NULL, *current = head, *next = NULL;
	while (current != NULL) {
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	return prev;
}

int main() {
	struct node* first = NULL;
	printf("Create a list:\n");
	first = create(first);
	printf("Content of list before reversing: ");
	display(first);
	first = reverse(first);
	printf("Content of list after reversing: ");
	display(first);
	return 0;
}

