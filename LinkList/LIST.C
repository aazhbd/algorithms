#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct listNode {
   int data;
   struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *sPtr, int value);
int del(ListNodePtr *sPtr, int value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void menu(void);

int main(){
	ListNodePtr startPtr = NULL;
	int choice;
	int item;
	clrscr();

	menu();
	printf("Enter Choice: ");
	scanf("%d", &choice);

	while(choice!=3){
		switch(choice){
			case 1:
				printf("Enter a number to insert: ");
				scanf( "\n%d", &item );
				insert(&startPtr, item);
				printList(startPtr);
			break;

			case 2:
				if(!isEmpty( startPtr)){
					printf("Enter the number to be deleted: ");
					scanf("\n%d", &item);
					if (del(&startPtr, item)){
					printf("%d deleted.\n", item);
					printList(startPtr);
				}
				else{
					printf("%d not found.\n\n", item);
				}
			}
			else{
				printf("Nothing in the list.\n\n");
			}
			break;

			default:
				printf("Invalid choice.\n\n");
				menu();
			break;
		}
		printf("Enter Choice: ");
		scanf("%d", &choice);
	}
	printf("Press any key.\n");
	getch();
	return 0;
}


void menu(void){
	printf( "Enter your choice:\n"
		"\t1 to insert an element into the list.\n"
		"\t2 to delete an element from the list.\n"
		"\t3 to end.\n");
}


void insert(ListNodePtr *sPtr, int value){
	ListNodePtr newPtr;
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	newPtr=malloc(sizeof(ListNode));

	if(newPtr!=NULL){
		newPtr->data=value;
		newPtr->nextPtr=NULL;
		previousPtr=NULL;
		currentPtr=*sPtr;
		while(currentPtr!=NULL && value>currentPtr->data){
			previousPtr=currentPtr;
			currentPtr=currentPtr->nextPtr;
		}
		if(previousPtr==NULL){
			newPtr->nextPtr=*sPtr;
			*sPtr=newPtr;
		}
		else{
			previousPtr->nextPtr=newPtr;
			newPtr->nextPtr=currentPtr;
		}
	}
	else{
		printf("%d can't be inserted.\n", value);
	}
}

int del(ListNodePtr *sPtr, int value){
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	ListNodePtr tempPtr;

	if(value==(*sPtr)->data){
		tempPtr = *sPtr;
		*sPtr = ( *sPtr )->nextPtr;
		free(tempPtr);
		return value;
	}
	else{
		previousPtr=*sPtr;
		currentPtr=(*sPtr)->nextPtr;
		while(currentPtr!=NULL && currentPtr->data!=value){
			previousPtr=currentPtr;
			currentPtr=currentPtr->nextPtr;
		}
		if(currentPtr!=NULL){
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free(tempPtr);
			return value;
		}
	}
	return 0;
}

int isEmpty(ListNodePtr sPtr){
	return sPtr == NULL;
}

void printList(ListNodePtr currentPtr){
	if(currentPtr==NULL){
		printf("Nothing in the list.\n\n");
	}
	else{
		printf("The list is:\n");
		while(currentPtr!=NULL){
			printf( "%d\t", currentPtr->data );
			currentPtr=currentPtr->nextPtr;
		}
		printf( "End\n\n" );
	}
}