// linkList.c -- 这是一个链表实现的库文件。
// 负责提供链表的基本操作。
// author:
// change by: yidafu

#include "library.h"


#include <stdio.h>
#include "library.h"
#include <stdlib.h>

void init_list(link_list *l){
    l -> length = 0;
    l -> head = l -> tail = (Node *)malloc(sizeof(Node));
    l -> head -> next = NULL;
}

bool list_insert(link_list *l,int i,elem_type e){
    if(i>=l->length+1||i<1)
        return false;
    Node *p,*q;
    p = (Node *)malloc(sizeof(Node));
    int k = 1;
    q -> data = e;
    p = l->head;
    while(k<i){
        p = p -> next;
        k++;
    }
    p -> next = q;
    q -> next = p -> next;
    if(i==l->length+1)
        l->tail = q;
    return true;
}

bool list_delete(link_list *l,int i){
    Node *p,*q;
    int k = 1;
    p = l->head;
    if(i>l->length||i<1)
        return false;
    while(k<i){
        p = p -> next;
        k++;
    }
    q = p -> next;
    if(q==l->tail)
        l->tail = p;
    p -> next = q -> next;
    free(q);
    return true;
}

void clear_list(link_list *l){
    Node *p,*q;
    l->length = 0;
    p = l->head -> next;
    while(p) {
        q = p;
        p = p -> next;
        free(q);
    }
    l -> tail = l -> head;
    l-> head -> next = NULL;
}

void destroy_list(link_list *l){
    clear_list(l);
    free(l->head);
    l -> tail = l -> head = NULL;
}

bool list_empty(link_list *l){
    if(l->length==0)
        return true;
    return false;
}

int locate_list(link_list *l,elem_type e,int(*compare)(elem_type a,elem_type b)){
    int i = 1;
    Node *p,*q;
    p = l->head -> next;
    while(p&&compare(p->data,e)==false){
        p = p -> next;
        i++;
    }
    return i;
}

int list_length(link_list l){
    return l.length;
}

bool get_elem(link_list *l,int i,elem_type *e){
    if(i<1||i>l->length)
        return false;
    Node *p;
    p = l -> head -> next;
    int k = 1;
    while(k<i){
        p = p -> next;
        k++;
    }
    e = p -> data;
    return true;
}

void list_append(link_list *l,elem_type e){
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p -> data = e;
    l -> tail -> next = p;
    l -> tail = p;
    p -> next = NULL;
    l -> length ++ ;
}

void list_traverse(link_list l,void(*visit)(elem_type e)){
    Node *p;
    p = l.head;
    while(p){
        visit(p->data);
        p = p -> next;
    }
}

