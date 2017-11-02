// linkList.c -- 这是一个链表实现的库文件。
// 负责提供链表的基本操作。
// author: yidafu
// change by: yidafu

#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include "link_list_history.h"

void init_list_history(link_list_history *list){
    list -> length = 0;
    list -> head = list -> tail = (node_history *)malloc(sizeof(node_history));
    list -> head -> next = NULL;
}

bool list_insert_history(link_list_history *list,int i,history *e){
    if( i > list->length + 1 || i < 1 )
        return false;
    node_history *p,*q;
//    p = (node_book *)malloc(sizeof(node_book));
    int k = 1;
    node_history new_node;
    q = &new_node;
    q -> data = *e;
    p = list->head;
    while( k < i ) {
        p = p -> next;
        k++;
    }
    q->next = p->next;
    p -> next = q;
    // 修正尾指针
    if(i==list->length+1)
        list->tail = q;
    return true;
}

bool list_delete_history(link_list_history *list,int i){
    node_history *p,*q;
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

void clear_list_history(link_list_history *list){
    node_history *p,*q;
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

void destroy_list_history(link_list_history *list){
    clear_list_history(list);
    free(list->head);
    list -> tail = list -> head = NULL;
}

bool list_empty_history(link_list_history *list){
    if(list->length==0)
        return true;
    return false;
}

int locate_list_history(link_list_history *list,history e,int(*compare)(history a,history b)){
    int i = 1;
    node_history *p,*q;
    p = list->head -> next;
    while(p&&compare(p->data,e)==false){
        p = p -> next;
        i++;
    }
    return i;
}

int list_length_history(link_list_history *list){
    return list->length;
}

bool get_elem_history(link_list_history *list,int i,history *e){
    if(i<1||i>list->length)
        return false;
    node_history *p;

    p = list -> head -> next;
    int k = 1;
    while(k<i){
        p = p -> next;
        k++;
    }
    e = &p -> data;
    return true;
}

void list_append_history(link_list_history *list,history *e){
    node_history *p;
    p = (node_history *)malloc(sizeof(node_history));
    p -> data = *e;
    list -> tail -> next = p;
    list -> tail = p;
    p -> next = NULL;
    list -> length ++;
}

void list_traverse_history(link_list_history *list,void(*visit)(history *e)){
    node_history *p;
    p = list->head->next;
    while(p){
        visit(&p->data);
        p = p -> next;
    }
}

