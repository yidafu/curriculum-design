//
// Created by yidafu on 2017/10/18.
//
#include "library.h"
#ifndef CURRICULUM_DESIGN_LINK_LIST_STU_H
#define CURRICULUM_DESIGN_LINK_LIST_STU_H
//#define node_stu node_stu
typedef struct{
    int no;
    char *name;
}  student;
//typedef struct node_stu;
typedef struct node_stu {
    student data;
    struct node_stu *next;
} node_stu;

typedef struct {
    node_stu *head;
    node_stu *tail;
    int length;
} link_list_stu;

void init_list_stu(link_list_stu *list);
bool list_insert_stu(link_list_stu *list,int i,student *e);
bool list_delete_stu(link_list_stu *list,int i);
void clear_list_stu(link_list_stu *list);
void destroy_list_stu(link_list_stu *list);
bool list_empty_stu(link_list_stu *list);
int locate_list_stu(link_list_stu *list,student e,int(*compare)(student a,student b));
int list_length_stu(link_list_stu list);
bool get_elem_stu(link_list_stu *list,int i,student *e);
void list_append_stu(link_list_stu *list,student *e);
void list_traverse_stu( link_list_stu *list, void(*visit)( student *e ) );
#endif //CURRICULUM_DESIGN_LINK_LIST_STU_H
