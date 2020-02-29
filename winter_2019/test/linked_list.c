// 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 2

typedef struct node{
    int info;
    struct node* next;
}Node;

Node* create(int info);
int add(Node** h, Node* p, int info);
Node* find(Node* h, int info);

void main(){
    Node* h;
    add(&h, NULL, 25);
    add(&h, h, 35);

    printf("%d", h->info);
    printf("%d", h->next->info);
}

Node* find(Node* h, int info){
    Node* p = h;
    for(;p && p->info != info; p->next);
    return p; 
}

int add(Node** h, Node* p, int info){
    Node* t = create(info);
    if(t){
        if(!p){
            t->next = *h;
            *h = t;
        }else{
            t->next = p->next;
            p->next = t;
        }
        return 1;
    }else{
        return 0;
    }
}

Node* create(int info){
    Node* p = NULL;
    p = (Node*)malloc(sizeof(Node));
    if(p){
        p->info = info;
        p->next = NULL;
    }
    return p;
}



















