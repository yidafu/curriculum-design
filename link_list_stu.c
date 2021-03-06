// linkList.c -- 这是一个链表实现的库文件。
// 负责提供链表的基本操作。
// author: 颜胜
// change by:

#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "link_list_stu.h"
#include "link_list_history.h"

void init_list_stu(link_list_stu *list){
    list -> length = 0;
    list -> head = list -> tail = (node_stu *)malloc(sizeof(node_stu));
    list -> head -> next = NULL;
}

bool list_insert_stu(link_list_stu *list,int i,student *e){
    if( i > list->length + 1 || i < 1 )
        return false;
    node_stu *p,*q;
//    p = (node_book *)malloc(sizeof(node_book));
    int k = 1;
    node_stu new_node;
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

bool list_delete_stu(link_list_stu *list,int i){
    node_stu *p,*q;
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

void clear_list_stu(link_list_stu *list){
    node_stu *p,*q;
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

void destroy_list_stu(link_list_stu *list){
    clear_list_stu(list);
    free(list->head);
    list -> tail = list -> head = NULL;
}

bool list_empty_stu(link_list_stu *list){
    if(list->length==0)
        return true;
    return false;
}

int locate_list_stu(link_list_stu *list,student e,int(*compare)(student a,student b)){
    int i = 1;
    node_stu *p,*q;
    p = list->head -> next;
    while(p&&compare(p->data,e)==false){
        p = p -> next;
        i++;
    }
    return i;
}

int list_length_stu(link_list_stu list){
    return list.length;
}

bool get_elem_stu(link_list_stu *list,int i,student *e){
    if(i<1||i>list->length)
        return false;
    node_stu *p;
    p = list -> head -> next;
    int k = 1;
    while(k<i){
        p = p -> next;
        k++;
    }
    *e = p -> data;
    return true;
}

void list_append_stu(link_list_stu *list,student *e){
    node_stu *p;
    p = (node_stu *)malloc(sizeof(node_stu));
    p -> data = *e;
    list -> tail -> next = p;
    list -> tail = p;
    p -> next = NULL;
    list -> length ++;
}

void list_traverse_stu(link_list_stu *list,void(*visit)(student *e)){
    node_stu *p;
    p = list->head->next;
    while(p){
        visit( &p->data );
        p = p -> next;
    }
}

