//
// Created by yidafu on 2017/11/5.
//

#ifndef CURRICULUM_DESIGN_STUDENT_H
#define CURRICULUM_DESIGN_STUDENT_H

#include "../library.h"
#include "../linklist/link_list_book.h"
bool student_entry();
bool judge_number();
void search_out();
void borrow();
bool return_();
void display_all();
void display_by_category();
void show_book_list( link_list_book *list);

#endif //CURRICULUM_DESIGN_STUDENT_H
