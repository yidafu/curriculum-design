//
// Created by yidafu on 2017/10/18.
//

#ifndef CURRICULUM_DESIGN_IO_H
#define CURRICULUM_DESIGN_IO_H

#include "link_list_stu.h"
#include "link_list_history.h"
#include "link_list_book.h"

bool io_input_student(link_list_stu *stu_list);
bool io_input_histroy( link_list_history *history_list);
bool io_input_book_list( link_list_book *book_list);

void io_output_student( link_list_stu *stu_list );
#endif //CURRICULUM_DESIGN_IO_H
