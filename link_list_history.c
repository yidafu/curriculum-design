// linkList.c -- 这是一个链表实现的库文件。
// 负责提供链表的基本操作。
// author: yidafu
// change by: yidafu

#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include "link_list_history.h"

void init_list_history(link_list_history *l){
    l -> length = 0;
    l -> head = l -> tail = (node_history *)malloc(sizeof(node_history));
    l -> head -> next = NULL;
}

bool list_insert_history(link_list_history *l,int i,history *e){
    if(i>=l->length+1||i<1)
        return false;
    node_history *p,*q;
    p = (node_history *)malloc(sizeof(node_history));
    int k = 1;
    node_history new_node;
    q = &new_node;
    q -> data = *e;
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

bool list_delete_history(link_list_history *l,int i){
    node_history *p,*q;
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

void clear_list_history(link_list_history *l){
    node_history *p,*q;
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

void destroy_list_history(link_list_history *l){
    clear_list_history(l);
    free(l->head);
    l -> tail = l -> head = NULL;
}

bool list_empty_history(link_list_history *l){
    if(l->length==0)
        return true;
    return false;
}

int locate_list_history(link_list_history *l,history e,int(*compare)(history a,history b)){
    int i = 1;
    node_history *p,*q;
    p = l->head -> next;
    while(p&&compare(p->data,e)==false){
        p = p -> next;
        i++;
    }
    return i;
}

int list_length_history(link_list_history *l){
    return l->length;
}

bool get_elem_history(link_list_history *l,int i,history *e){
    if(i<1||i>l->length)
        return false;
    node_history *p;

    p = l -> head -> next;
    int k = 1;
    while(k<i){
        p = p -> next;
        k++;
    }
    e = &p -> data;
    return true;
}

void list_append__history(link_list_history *l,history *e){
    node_history *p;
    p = (node_history *)malloc(sizeof(node_history));
    p -> data = *e;
    l -> tail -> next = p;
    l -> tail = p;
    p -> next = NULL;
    l -> length ++ ;
}

void list_traverse_history(link_list_history l,void(*visit)(history e)){
    node_history *p;
    p = l.head;
    while(p){
        visit(p->data);
        p = p -> next;
    }
}

