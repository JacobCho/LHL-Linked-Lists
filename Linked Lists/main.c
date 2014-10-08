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

void printNodes(Node node);
Node * nodeSearch(int value, Node *head);
void insertNode(int value, Node *head);
void removeNode(int value, Node *head);

int main(int argc, const char * argv[]) {
    
    Node firstNode;
    firstNode.value = 1;
    
    Node secNode;
    secNode.value = 2;
    
    Node thirdNode;
    thirdNode.value = 3;
    
    Node forthNode;
    forthNode.value = 4;
    
    Node fifthNode;
    fifthNode.value = 5;
    
    Node sixthNode;
    sixthNode.value = 6;
    
    firstNode.next = &secNode;
    secNode.next = &thirdNode;
    thirdNode.next = &forthNode;
    forthNode.next = &fifthNode;
    fifthNode.next = &sixthNode;
    sixthNode.next = NULL;
    
    printNodes(firstNode);
    
    Node *nodeToFind = nodeSearch(5, &firstNode);
    
    printf("Value of node search: %d\n", nodeToFind->value);
    
    insertNode(6, &firstNode);
    printNodes(firstNode);
    
    return 0;
}

void printNodes(Node node) {
    
    while (node.next != NULL) {
        printf("%d\n",node.value);
        node = *node.next;
    }
    printf("%d\n",node.value);
    
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
    
    Node lastNode;
    Node *newNode = &lastNode;
    newNode->value = value;
    newNode->next = NULL;
    current->next = newNode;
}

void removeNode(int value, Node *head) {
    
    Node *current = head;
    
    while (current->value != value) {
        current = current->next;
    }
    
    
    
}
