//
//  main.c
//  Linked Lists
//
//  Created by Jacob Cho on 2014-10-08.
//  Copyright (c) 2014 Jacob Cho. All rights reserved.
//

#include <stdio.h>


struct Node {
    
    int value;
    struct Node * next;
};

typedef struct Node Node;

void printNodes(Node *head);
Node * nodeSearch(int value, Node *head);
void insertNode(int value, Node *head);
void removeNode(int value, Node *head);
Node * newNode(int value);
void deleteList(Node *head);

int main(int argc, const char * argv[]) {
    
    Node firstNode = *newNode(1);
    
    Node secNode = *newNode(2);
    
    Node thirdNode = *newNode(3);
    
    Node forthNode =  *newNode(4);
    
    Node fifthNode = *newNode(5);
    
    Node sixthNode = *newNode(6);
    
    firstNode.next = &secNode;
    secNode.next = &thirdNode;
    thirdNode.next = &forthNode;
    forthNode.next = &fifthNode;
    fifthNode.next = &sixthNode;
    sixthNode.next = NULL;
    
    printNodes(&firstNode);
    
    Node *nodeToFind = nodeSearch(5, &firstNode);
    
    printf("Value of node search: %d\n", nodeToFind->value);
    
    insertNode(7, &firstNode);
    
    printNodes(&firstNode);
    
    removeNode(2, &firstNode);
    printNodes(&firstNode);
    
    deleteList(&firstNode);
    printNodes(&firstNode);
    
    return 0;
}

void printNodes(Node *head) {
    
    Node *current = head;
    
    printf("%d\n",current->value);
    
    while (current->next != NULL) {
        current = current->next;
        int n = current->value;
        printf("%d\n",n);
        
    }
    printf("%d\n",current->value);
    
}

Node * nodeSearch(int value, Node *head) {

    Node *current = head;
    while (current->next != NULL) {
        if (current->value == value) {
            return current;
        }
        current = current->next;
    }
    
    printf("Node not found\n");
    return NULL;
}

void insertNode(int value, Node *head) {
    
    Node *current = head;
    
    while (current->next != NULL) {
        current = current->next;
        
    }
    
    current->next = newNode(value);
    
    
}

void removeNode(int value, Node *head) {
    
    Node *current = head;
    Node *prev = head;
    
    while (current->value != value) {
        prev = current;
        current = current->next;
    }
    
    prev->next = current->next;
    
    current->next = NULL;
}

Node * newNode(int value) {
    
    Node newNode;
    newNode.value = value;
    
    Node * result = &newNode;
    
    return result;
    
}

void deleteList(Node *head) {
    
    Node *current = head;
    Node *next = head;
    
    while (current->next != NULL) {
        next = current->next;
        current->next = NULL;
        current->value = NULL;
        current = next;
    }
    
    current->next = NULL;
    current->value = NULL;
}
