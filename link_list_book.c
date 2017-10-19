//
// Created by yidafu on 2017/10/19.
//
#include "library.h"
#include <stdio.h>
#include <malloc.h>
#include "link_list_book.h"

void init_list_book(link_list_book *list){
    list -> length = 0;
    list -> head = list -> tail = (node_book *)malloc(sizeof(node_book));
    list -> head -> next = NULL;
}

bool list_insert_book(link_list_book *list,int i,book *e){
    if(i>=list->length+1||i<1)
        return false;
    node_book *p,*q;
    p = (node_book *)malloc(sizeof(node_book));
    int k = 1;
    node_book new_node;
    q = &new_node;
    q -> data = *e;
    p = list->head;
    while(k<i){
        p = p -> next;
        k++;
    }
    p -> next = q;
    q -> next = p -> next;
    if(i==list->length+1)
        list->tail = q;
    return true;
}

bool list_delete_book(link_list_book *list,int i){
    node_book *p,*q;
    int k = 1;
    p = list->head;
    if(i>list->length||i<1)
        return false;
    while(k<i){
        p = p -> next;
        k++;
    }
    q = p -> next;
    if(q==list->tail)
        list->tail = p;
    p -> next = q -> next;
    free(q);
    return true;
}

void clear_list_book(link_list_book *list){
    node_book *p,*q;
    list->length = 0;
    p = list->head -> next;
    while(p) {
        q = p;
        p = p -> next;
        free(q);
    }
    list -> tail = list -> head;
    list-> head -> next = NULL;
}

void destroy_list_book(link_list_book *list){
    clear_list_book(list);
    free(list->head);
    list -> tail = list -> head = NULL;
}

bool list_empty_book(link_list_book *list){
    if(list->length==0)
        return true;
    return false;
}

int locate_list_book(link_list_book *list,book e,int(*compare)(book a,book b)){
    int i = 1;
    node_book *p,*q;
    p = list->head -> next;
    while(p&&compare(p->data,e)==false){
        p = p -> next;
        i++;
    }
    return i;
}

int list_length_book(link_list_book *list){
    return list->length;
}

bool get_elem_book(link_list_book *list,int i,book *e){
    if(i<1||i>list->length)
        return false;
    node_book *p;

    p = list -> head -> next;
    int k = 1;
    while(k<i){
        p = p -> next;
        k++;
    }
    e = &p -> data;
    return true;
}

void list_append_book(link_list_book *list,book *e){
    node_book *p;
    p = (node_book *)malloc(sizeof(node_book));
    p -> data = *e;
    list -> tail -> next = p;
    list -> tail = p;
    p -> next = NULL;
    list -> length ++;
}

void list_traverse_book(link_list_book list,void(*visit)(book *e)){
    node_book *p;
    p = list.head;
    while(p){
        visit( &p->data );
        p = p -> next;
    }
}

