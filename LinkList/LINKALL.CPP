#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct listNode {
   int data;
   struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert( ListNodePtr *sPtr, char value );
char del( ListNodePtr *sPtr, char value );
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
void menu();

int main(){
	clrscr();
	ListNodePtr startPtr = NULL;
	int choice;
	char item;
	menu();
	printf("Enter: ");
	scanf("%d", &choice);

	while(choice!= 3){
		switch(choice){
			case 1:
				printf( "Enter data: " );
				scanf( "\n%d", &item );
				insert( &startPtr, item );
				printList( startPtr );
			break;
			case 2:
				if(!isEmpty(startPtr)){
					printf("Enter data to be deleted: ");
					scanf("\n%d", &item);
					if(del(&startPtr, item)){
						printf("%d deleted.\n", item);
						printList(startPtr);
					}
					else {
						printf( "%d not found.\n\n", item );
					}
				}
				else {
					printf("Nothing in the list.\n\n");
				}
			break;
			default:
				printf( "Invalid choice.\n\n" );
				menu();
			break;
		}
		printf( "Enter " );
		scanf( "%d", &choice );
	}
	getch();
	return 0;
}

void menu(){
	printf( "Enter your choice:\n"
	"1. Insert an element into the list.\n"
	"2. Delete an element from the list.\n"
	"3. End program.\n" );
}

void insert(ListNodePtr *sPtr, int value){
	ListNodePtr newPtr;
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	newPtr=(ListNode *)malloc(sizeof(ListNode));

	if(newPtr!=NULL){
		newPtr->data = value;
		newPtr->nextPtr = NULL;
		previousPtr = NULL;
		currentPtr = *sPtr;
		while(currentPtr!=NULL&&value>currentPtr->data){
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		if(previousPtr==NULL){
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else{
		printf( "OverFlow. can't insert %d. There is no memory.\n", value );
	}
}

char del(ListNodePtr *sPtr, int value){
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
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		if(currentPtr!=NULL){
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free( tempPtr );
			return value;
		}
	}
	return '\0';
}

int isEmpty(ListNodePtr sPtr){
	return sPtr == NULL;
}

void printList(ListNodePtr currentPtr){
	if(currentPtr==NULL){
		printf( "List is empty.\n\n" );
	}
	else{
		printf( "The list is:\n" );
		while(currentPtr!=NULL){
			printf( "%c\t", currentPtr->data );
			currentPtr = currentPtr->nextPtr;
		}
		printf( "NULL\n\n" );
	}
}