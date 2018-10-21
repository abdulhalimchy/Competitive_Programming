#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
    int id;
    char *name;
    struct st *next;
    struct st *prev;
} Node;

Node *root, *lastNode;

void insertIntoList(Node *curNode, int Id, char *Name)
{
    if(root==NULL)      //when the list empty, insert the first element in the list
    {
        root= (Node*) malloc(sizeof(Node));
        root->id=Id;
        root->name=Name;
        root->prev=NULL;
        root->next=NULL;
        lastNode=root;
    }
    else        //append the newNode at the end of the list
    {
        Node *newNode=(Node*) malloc(sizeof(Node));
        newNode->id=Id;
        newNode->name=Name;
        newNode->next=NULL;
        newNode->prev=lastNode;
        lastNode->next= newNode;
        lastNode=newNode;
    }
}

void insertAfterThisId(Node *curNode, int thisId, int Id, char *Name)
{
    Node *newNode=(Node*) malloc(sizeof(Node));
    newNode->id=Id;
    newNode->name=Name;

    while(curNode->id!=thisId)
    {
        curNode=curNode->next;
    }

    if(curNode->next==NULL)     //insert at the end of the list, if thisId is the last node
    {
        newNode->next=NULL;
        newNode->prev=curNode;
        curNode->next=newNode;
        lastNode=newNode;
    }
    else
    {
        newNode->next=curNode->next;
        newNode->prev=curNode;
        curNode->next->prev=newNode;
        curNode->next=newNode;
    }
}

void insertAtTheBeginning(int Id, char *Name)
{
    Node *newNode=(Node*) malloc(sizeof(Node));
    newNode->id=Id;
    newNode->name=Name;
    newNode->next=root;
    newNode->prev=NULL;
    root->prev=newNode;
    root=newNode;
}

void printStartToEnd(Node *curNode)
{
    while(curNode!=NULL)
    {
        printf("ID: %d\t Name: %s\n", curNode->id, curNode->name);
        curNode=curNode->next;
    }
}

void printEndToStart(Node *curNode)
{
    while(curNode!=NULL)
    {
        printf("ID: %d\t Name: %s\n", curNode->id, curNode->name);
        curNode=curNode->prev;
    }
}

void deleteNode(Node *curNode, int Id)
{
    if(root->id==Id)      // Delete the first element;
    {
        root->next->prev=NULL;
        root=root->next;
        free(curNode);      //curNode is the first node
        return;
    }

    while(curNode->id!=Id)
    {
        curNode=curNode->next;
    }
    if(curNode==lastNode)     //Delete the last node
    {
        curNode->prev->next=NULL;
        lastNode=curNode->prev;
        free(curNode);
    }
    else        //delete from middle
    {
        curNode->prev->next=curNode->next;
        curNode->next->prev=curNode->prev;
        free(curNode);
    }
}

int main()
{
    root=NULL;
    insertIntoList(root, 1, "salman");          //Appending to end of the list
    insertIntoList(root, 2, "Kobir");
    insertIntoList(root, 9, "Abir");
    insertIntoList(root, 5, "Boshir");


    insertAfterThisId(root, 5, 20, "Ashir");    //insert after the id=5
    insertAfterThisId(root, 1, 7, "Nasir");     //insert after the id=1


    insertAtTheBeginning(23, "Simon");

    deleteNode(root, 23);
    deleteNode(root, 20);
    deleteNode(root, 7);


    printStartToEnd(root);
    printf("\n\n");
    printEndToStart(lastNode);
    return 0;
}
