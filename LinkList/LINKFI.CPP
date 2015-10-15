#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct listNode {
   int data;
   struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *NodePtr;

void insert(NodePtr *sPtr, int value);
int isEmpty(NodePtr sPtr);
void printList(NodePtr currentPtr);
void menu(void);

int main(){
	NodePtr startPtr = NULL;
	int choice, item;
	clrscr();

	menu();
	scanf( "%d", &choice );

	while ( choice != 2 ) {
		switch(choice) {
			case 1:
				printf( "Enter the number to insert: " );
				scanf( "\n%d", &item );
				insert( &startPtr, item );
				printList( startPtr );
			break;

			default:
				printf( "Invalid choice.\n\n" );
				menu();
			break;
		}
		printf( "? " );
		scanf( "%d", &choice );
	}
	printf("Press any key");
	getch();
	return 0;
}

void menu(void){
   printf( "Enter your choice:\n"
      "\t1 to insert an element into the list.\n"
      "\t2 to end.\n" );
}

void insert(NodePtr *sPtr, int value){
	NodePtr newPtr;
	NodePtr previousPtr;
	NodePtr currentPtr;
	newPtr =(ListNode *) malloc( sizeof( ListNode ) );

	if(newPtr!=NULL){
		newPtr->data = value;
		newPtr->nextPtr = NULL;
		previousPtr = NULL;
		currentPtr = *sPtr;

		while (currentPtr != NULL && value > currentPtr->data){
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		if (previousPtr == NULL){
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else{
		printf( "%c not inserted.\n", value );
	}
}


int isEmpty(NodePtr sPtr){
	return sPtr == NULL;
}

void printList(NodePtr currentPtr){
	if (currentPtr == NULL){
		printf( "List is empty.\n\n" );
	}
	else{
		printf( "The list is:\n" );
		while ( currentPtr != NULL ){
			printf( "%d \t", currentPtr->data );
			currentPtr = currentPtr->nextPtr;
		}
		printf( "NULL\n\n" );
	}
}