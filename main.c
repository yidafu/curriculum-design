//
// Created by yidafu on 2017/10/11.
//

#include <stdio.h>
#include "library.h"
#include "test.h"
#include "io.h"

FILE *fp_stu;
FILE *fp_book;
FILE *fp_history;

int main () {
//    file_test();

    link_list_stu list_stu;
    init_list_stu( &list_stu );
    io_input_student( &list_stu );

    link_list_history list_history;
    init_list_history( &list_history );
    io_input_histroy( &list_history );

    link_list_book list_book;
    init_list_book( &list_book );
    io_input_book_list( &list_book );

    student to_append_stu = { 4, "xiangong"};
    list_append_stu( &list_stu, &to_append_stu );

    io_output_student( &list_stu );
    io_output_book( &list_book );
    io_output_history( &list_history );

    destroy_list_book( &list_book );
    destroy_list_history( &list_history );
    destroy_list_stu( &list_stu );
//    link_list_stu list_stu;
//    init_list_stu( &list_stu );
//    io_input_student( &list_stu );
//
//    link_list_history list_history;
//    init_list_history(&list_history);
//    io_input_histroy( &list_history );
//
//    link_list_book list_book;
//    init_list_book( &list_book );
//    io_input_book_list( &list_book );
//
//    destroy_list_book( &list_book );
//    destroy_list_history( &list_history );
//    destroy_list_stu( &list_stu );
    return 0;
//    bool test = true;
}