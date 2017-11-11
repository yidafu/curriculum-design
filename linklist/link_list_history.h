//
// Created by yidafu on 2017/10/18.
//
#include "../library.h"
#ifndef CURRICULUM_DESIGN_LINK_LIST_HISTORY_H
#define CURRICULUM_DESIGN_LINK_LIST_HISTORY_H

typedef struct {
    int year;
    int month;
    int day;
} my_time;

typedef struct {
    int history_id;
    char *borrow_by;
    char *borrow_time;
    char *return_time;
    char *book_name;
} history;
//typedef struct node_stu;
typedef struct node_history {
    history data;
    struct node_history *next;
} node_history;

typedef struct {
    node_history *head;
    node_history *tail;
    int length;
} link_list_history;

void init_list_history(link_list_history *list);
bool list_insert_history(link_list_history *l,int i,history *e);
bool list_delete_history(link_list_history *list,int i);
void clear_list_history(link_list_history *list);
void destroy_list_history(link_list_history *list);
bool list_empty_history(link_list_history *list);
int locate_list_history(link_list_history *list,history e,int(*compare)(history a,history b));
int list_length_history(link_list_history *list);
bool get_elem_history(link_list_history *list,int i,history *e);
void list_traverse_history(link_list_history *list,void(*visit)(history *e));
void list_append_history(link_list_history *list,history *e);

#endif //CURRICULUM_DESIGN_LINK_LIST_HISTORY_H
