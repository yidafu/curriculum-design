//
// Created by yidafu on 2017/11/3.
//

#ifndef CURRICULUM_DESIGN_LINK_LIST_LIBRARY_H
#define CURRICULUM_DESIGN_LINK_LIST_LIBRARY_H

#include "../library.h"
#include "link_list_book.h"
#include "link_list_history.h"

bool get_by_category(int category, link_list_book *srcrose, link_list_book  *get_list);
void search(char *name,link_list_book *srcrose, link_list_book *get_list );
bool borrow_book(char* name, link_list_book *book_pass,link_list_history *history_pass);
bool return_book(char *name,link_list_book *book_pass,link_list_history *history_pass);

#endif //CURRICULUM_DESIGN_LINK_LIST_LIBRARY_H
