// io.c -- 这是一个 IO 库文件，主要负责将文件中的
// 数据读取到链表以及把链表中的数据写入文件。
// author: yidafu
// change by:

#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
#include "library.h"
#include "phpstr.h"
#include "test.h"
#include "link_list_stu.h"
#include "link_list_history.h"
#include "io.h"

void file_test() {
    link_list_history list_history;
    init_list_history(&list_history);
    io_input_histroy( &list_history );
}

bool io_input_student( link_list_stu *stu_list) {
    FILE *fp;
    if( (fp = fopen("../data/student.txt","r") ) == NULL ) {
//        printf("fail to open file!");
        return false;
    }
    char line[80];
    while ( !feof(fp) ) {
        fgets(line,80,fp) ;
        /// !!! IMPORTENT 文件里面不能有空行
        int cutPos = strpos(line , ',',0);
        char stu_no[5];
        char *stu_name;
        int tmp = cutPos - 1;
        strncpy(stu_no,line,tmp );
        stu_name = substr(line,cutPos,0);
        int stu_no_insert = atoi(stu_no);
        student to_insert = { stu_no_insert,stu_name};

        list_append_stu( stu_list,to_insert);
    }
    return true;
}


bool io_input_histroy( link_list_history *history_list) {
    FILE *fp;
    if( (fp = fopen("../data/history.txt","r") ) == NULL ) {
//        printf("fail to open file!");
        return false;
    }
    /*
     * 假设一行不超过 80 个字符
     */
    char line[80];
    while ( !feof(fp) ) {
        fgets(line,80,fp) ;
        /// !!! IMPORTENT 文件里面不能有空行
        int cut_len = 0;
        int cut_pos1 = strpos(line , ',',0);
        char *history_id;
        cut_len = cut_pos1 - 1;
        history_id = substr(line, 0, cut_len );// 长度定死了
        int history_id_int = atoi(history_id);
        int cut_pos2 = strpos(line, ',', cut_pos1);
        cut_len = cut_pos2 - cut_pos1 - 1;
        char *name = substr(line, cut_pos1, cut_len);

        int cut_pos3 = strpos( line, ',', cut_pos2 );
        cut_len = cut_pos3 - cut_pos2 - 1;
        char *book_name = substr(line, cut_pos2, cut_len);

        int cut_pos4 = strpos( line, ',', cut_pos3 );
        cut_len = cut_pos4 - cut_pos3 - 1;
        char *borrow_time = substr(line, cut_pos3, cut_len);

        char *return_time = substr(line, cut_pos4, 0);

        history to_append = {history_id_int,name, book_name};
        list_append_history( history_list, &to_append);
        int haha = 0;
    }
    return true;
}