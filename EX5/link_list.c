#include "myDS.h"
#include "basic.h"
// HEAD is point to FOODPAPA (id: 0)
void my_insert(struct node* HEAD, int ID, char *Name, int node_id){
	struct node* current = HEAD;
	while(current != NULL){
		if(current->id == ID){
			struct node* toInsert = malloc(sizeof(struct node));
			strcpy(toInsert->name,Name);
			toInsert->id = node_id;
			toInsert->next = current->next;
			current->next = toInsert;
			return;
		}
		current = current->next;
	}
	printf("INVALID OPERATION\n");
}
void my_delete(struct node* HEAD, char *Name){
	struct node* current = HEAD;
	while(current->next != NULL){
		if(strcmp(current->next->name,Name)==0){
			struct node* toDelete = current->next;
			current->next = toDelete->next;
			free(toDelete);
			return;
		}
		current = current->next;
	}
	printf("INVALID OPERATION\n");
	// Delete the node which store the Name.
	// If it doesn’t exit such Name, print “INVALID OPERATION”.

}
void my_swap(struct node *HEAD, char *Name1, char *Name2){
	struct node* current1 = HEAD;
	struct node* current2 = HEAD;
	while(current1->next != NULL){
		if(strcmp(current1->next->name,Name1)==0){
			break;
		}
		current1 = current1->next;
	}
	while(current2->next != NULL){
		if(strcmp(current2->next->name,Name2)==0){
			break;
		}
		current2 = current2->next;
	}
	if(current1->next == NULL || current2->next == NULL){
		printf("INVALID OPERATION\n");
		return;
	}
	else{
		struct node* temp = current1->next;
		current1->next = current2->next;
		current2->next = temp;
		temp = current1->next->next;
		current1->next->next = current2->next->next;
		current2->next->next = temp;
		return;
	}
	// Swap the node which store Name1 and Name2
	// If either of the node doesn’t exit, print “INVALID OPERATION”
	// NOTICE: don't just swap the node's value
	// You need to break the link and recombine it
}
void my_print_id(struct node *HEAD, char *Name){
	struct node* current = HEAD;
	while(current != NULL){
		if(strcmp(current->name,Name)==0){
			printf("%d\n",current->id);
			return;
		}
		current = current->next;
	}
	printf("INVALID OPERATION\n");
	return;
	// Print the id of the corresponding Name.
	// If Name doesn’t exit, print “INVALID OPERATION”
}
void my_print_name(struct node *HEAD, int ID){
	struct node* current = HEAD;
	while(current != NULL){
		if(current->id == ID){
			printf("%s\n",current->name);
			return;
		}
		current = current->next;
	}
	printf("INVALID OPERATION\n");
	return;
	// Print the name of the corresponding ID
	// If ID doesn’t exit, print “INVALID OPERATION”
}
void my_result(struct node* HEAD){
	struct node* current = HEAD;
	while(current != NULL){
		printf("%d %s\n",current->id,current->name);
		current = current->next;
	}
	return;
	// Print out all the information in the linked list orderly
	// in the format “ID NAME”. (start from HEAD)
}