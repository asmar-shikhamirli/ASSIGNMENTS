#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
 char name[256];
 struct Node * next;
};

void addToTail(struct Node** tail, char *name){ 
 (*tail) -> next = (struct Node*) malloc(sizeof(struct Node));
 (*tail) = (*tail) -> next;
 strcpy((*tail)->name, name);
 (*tail) -> next = NULL;
}

void printList(struct Node* head){
 while( head != NULL){
	printf("%s ",head->name);
	head = head->next;
 }
 printf("\n");

}


int pop(struct Node ** head) {

	struct Node* curr = *head, *next;
      		while (curr != NULL){
        		next = curr -> next;
        		free(curr);
        		curr = next;
      		}

      		*head = NULL;
}

void append(struct Node ** head, char *name){
	struct Node *last = *head;
	while (last->next != NULL){
		if (strcmp(last->name, name) == 0){
			last = last->next;
		}
		last = last->next;
	}

	last->next = (struct Node *) malloc(sizeof(struct Node));
	strcpy(last->next->name, name);
	last->next->next = NULL;
}


void luckyperson(struct Node ** head, char *name) {
	struct Node *temp = (*head), *prev;

	if(temp != NULL && strcmp(temp->name, name) == 0){
        	*head = temp->next;
    	}
	else {
		while (temp != NULL && strcmp(temp->name, name) != 0) {
            	prev = temp;
            	temp = temp->next;
        	}

        	prev->next = temp->next;
		}

    	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node*));
    	struct Node *last = *head;
    	strcpy(new_node->name, temp->name);
    	new_node->next = NULL;

    	while(last->next != NULL){
        	last = last->next;
    	}	
    	last->next = new_node;
    	free(temp);
}

int main(){
	struct Node *head = (struct Node*) malloc(sizeof(struct Node));
	strcpy( head -> name, "Turgut");

	struct Node *tail = head;

	addToTail(&tail, "Kamran");
	addToTail(&tail, "Nigar");
	addToTail(&tail, "Madina");
	addToTail(&tail, "Murad");

	printList(head);
	char input[256];
	bool quit = 0;
	while(!quit)
	{
		printf("Enter a command: ");
		scanf( "%s" , input);
		if (strcmp(input,"quit") == 0)
		{
			quit = 1;
	 	}
	  	else if (strcmp(input,"admit") == 0)
	  	{
			printf("%s is admitted\n", head->name);
			pop(&head);	

	  	}
		else if (strcmp(input,"Turgut") == 0){
	  		luckyperson(&head, input);
		}
		else if (strcmp(input,"Kamran") == 0){
			luckyperson(&head, "Kamran");
		}
		else if (strcmp(input,"Nigar") == 0){
			luckyperson(&head, "Nigar");
		}
		else if (strcmp(input,"Madina") == 0){
			luckyperson(&head, "Madina");
		}
		else if (strcmp(input,"Murad") == 0){
			luckyperson(&head, "Murad");
		}
		else{
			printf("Please enter a valid name\n");
		}
		printList(head);

	}
	
	free(head);
	head = NULL;
}
