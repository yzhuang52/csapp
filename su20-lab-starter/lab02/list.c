#include "list.h"

/* Add a node to the end of the linked list. Assume head_ptr is non-null. */
void append_node (node** head_ptr, int new_data) {
	/* First lets allocate memory for the new node and initialize its attributes */
	/* YOUR CODE HERE */

	/* If the list is empty, set the new node to be the head and return */
	if (*head_ptr == NULL) {
		/* YOUR CODE HERE */
		node* newnode = (node*) malloc(sizeof(struct node));
		newnode->val = new_data;
		newnode->next = NULL;
		if(*head_ptr==NULL){
			*head_ptr = newnode;
			return;
		}
		node* curr = *head_ptr;
		while(curr->next!=NULL){
			curr = curr->next;
		}
		curr->next = newnode;
		return;
	}
	node* curr = *head_ptr;
	/* Insert node at the end of the list */
	/* YOUR CODE HERE */
}

/* Reverse a linked list in place (in other words, without creating a new list).
   Assume that head_ptr is non-null. */
void reverse_list (node** head_ptr) {
	node* prev = NULL;
	node* curr = *head_ptr;
	node* next = NULL;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	/* Set the new head to be what originally was the last node in the list */
	*head_ptr = prev;
}



