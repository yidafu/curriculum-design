//
// Created by yidafu on 2017/10/19.
//

#ifndef CURRICULUM_DESIGN_LINK_LIST_BOOK_LIST_H
#define CURRICULUM_DESIGN_LINK_LIST_BOOK_LIST_H

#include "library.h"

typedef struct book{
    int book_no; // 三个字符，如：001
    char *name;
    int category;
    char *press;
    float price;
    bool can_borrow;
    int remain;
} book;


typedef struct node_book {
    book data;
    struct node_book *next;
} node_book;

typedef struct {
    node_book *head;
    node_book *tail;
    int length;
} link_list_book;

void init_list_book(link_list_book *list);
bool list_insert_book(link_list_book *l,int i,book *e);
bool list_delete_book(link_list_book *list,int i);
void clear_list_book(link_list_book *list);
void destroy_list_book(link_list_book *list);
bool list_empty_book(link_list_book *list);
int locate_list_book(link_list_book *list,book e,int(*compare)(book a,book b));
int list_length_book(link_list_book *list);
bool get_elem_book(link_list_book *list,int i,book *e);
void list_append_book(link_list_book *list,book *e);
void list_traverse_book(link_list_book list,void(*visit)(book *e));
#endif //CURRICULUM_DESIGN_LINK_LIST_BOOK_LIST_H
