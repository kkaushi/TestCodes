#include<stdio.h>

typedef struct node{
    char element [4];
    struct node * next;
}nodeType;

nodeType * push(nodeType *early){
    nodeType *nptr = (nodeType*)malloc(sizeof(nodeType)) ;
    printf("Enter three character long word: ");
    fflush(stdin);
    gets(nptr->element);

    if(early==NULL){
        nptr->next = NULL;
    }else{
        nptr->next = early;
    }
    return nptr;
}

nodeType* searchNode(nodeType*startNode){
    ///get user input
    char input[4];
    int match;
    nodeType * wnptr = NULL;

    printf("Enter the word to swap: ");
    fflush(stdin);
    gets(input);

    ///search for the word
    while(startNode!=NULL){
        if (strcmp(input, startNode->element)==0){
            if(startNode->next == NULL){
                printf("Nothing to swap with.\n");
                match = 1;
                break;
            } else {
                wnptr = startNode;
                match = 1;
                break;
            }
         } else {
            wnptr = NULL;
            match = 0;
            startNode = startNode->next;
        }
    }

    if (match == 0){
        printf("Match not found\n");
    }
    return wnptr;
}

nodeType * searchPrev(nodeType*startNode, nodeType*searchedNode){
    nodeType * prevptr = NULL;

    while(startNode!=NULL){
        if (startNode->next==searchedNode){
            prevptr = startNode;
            break;
        } else if (startNode->next!=searchedNode){
            prevptr = NULL;
            startNode = startNode->next;
        }
    }
    return prevptr;
}

void swap(nodeType**newhead ,nodeType*prev, nodeType*searchedNode){
    if(prev == NULL){
        nodeType*adjNode = searchedNode->next;
        searchedNode->next=adjNode->next;
        adjNode->next = searchedNode;
		*newhead=adjNode;
    } else {
        nodeType*adjNode = searchedNode->next;
        prev->next = adjNode;
        searchedNode->next=adjNode->next;
        adjNode->next = searchedNode;
    }
}

void printList(nodeType*start){

    nodeType*currentNode = start;

    while(currentNode!=NULL){
        printf("%s ", currentNode->element);

        currentNode=currentNode->next;
    }
    printf("\n");
}

void cleanUp (nodeType*start){

    nodeType*currentNode = start;
    nodeType*holdadd = NULL;

    while(currentNode!=NULL){
        holdadd = currentNode->next;
        free(currentNode);
        currentNode=holdadd;
    }
}
int main(){

char command[7];
char temp[4];
nodeType *head = NULL;
nodeType *swaptr = NULL;
nodeType *preptr = NULL;


    while(printf("Type command to perform:\npush\nswap\nprint\nexit\nCommand: ")){
        fflush(stdin);
        scanf("%s", command);

        if(strcmp(command, "exit")==0){
            break;
        }

        if (strcmp(command, "push")==0){
                head = push(head);
        }

        if (strcmp(command, "swap")==0){
                swaptr = searchNode(head);
                preptr = searchPrev(head, swaptr);
                swap(&head, preptr, swaptr);
        }


        if (strcmp(command, "print")==0){
            printList(head);
            printf("%u", head);
        }

    }
    cleanUp(head);
}