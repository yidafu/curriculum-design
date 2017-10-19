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
#include "link_list_book.h"

/**
 * IO 测试函数
 * @return void
 */
void file_test() {
    link_list_stu list_stu;
    init_list_stu( &list_stu );
    io_input_student( &list_stu );

    link_list_history list_history;
    init_list_history(&list_history);
    io_input_histroy( &list_history );

    link_list_book list_book;
    init_list_book( &list_book );
    io_input_book_list( &list_book );

    io_output_student( &list_stu );

    destroy_list_book( &list_book );
    destroy_list_history( &list_history );
    destroy_list_stu( &list_stu );
}

/**
 * 读取 student.txt 里面的数据
 * @param stu_list 存放学生数据的链表
 * @return 成果返回 true，失败返回 false
 */
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
        int tmp   = cutPos - 1;
        strncpy(stu_no,line,(size_t) tmp );
        stu_name          = substr(line,cutPos,0);
        int stu_no_insert = atoi(stu_no);
        student to_insert = {
                            stu_no_insert,
                            stu_name};

        list_append_stu( stu_list,to_insert);
    }
    return true;
}

/**
 * 读取 history.txt 里面的数据
 * @param history_list 存放借阅历史的链表
 * @return 读取成果返回 true，失败返回 false
 */
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
        cut_len             = cut_pos1 - 1;
        history_id          = substr(line, 0, cut_len );// 长度定死了
        int history_id_int  = strtol( history_id, NULL, 10 );
        int cut_pos2        = strpos( line, ',', cut_pos1 );
        cut_len             = cut_pos2 - cut_pos1 - 1;
        char *name          = substr(line, cut_pos1, cut_len);

        int cut_pos3    = strpos( line, ',', cut_pos2 );
        cut_len         = cut_pos3 - cut_pos2 - 1;
        char *book_name = substr(line, cut_pos2, cut_len);

        int cut_pos4      = strpos( line, ',', cut_pos3 );
        cut_len           = cut_pos4 - cut_pos3 - 1;
        char *borrow_time = substr(line, cut_pos3, cut_len);

        char *return_time = substr(line, cut_pos4, 0);

        history to_append = {history_id_int,name, book_name};
        list_append_history( history_list, &to_append);
    }
    return true;
}


/**
 *
 * @param
 * @return
 */
/**
 * 读取 book_list.txt 里面的数据
 * @param book_list 存放书目的链表
 * @return 读取成果返回 true，失败返回 false
 */
bool io_input_book_list( link_list_book *book_list) {
    FILE *fp;
    if( (fp = fopen("../data/book_list.txt","r") ) == NULL ) {
//        printf("fail to open file!");
        return false;
    }
    char line[80];
    while ( !feof(fp) ) {
        fgets(line,80,fp) ;
        /// !!! IMPORTENT 文件里面不能有空行
        int cut_len = 0;

        int cut_pos1 = strpos(line , ',',0);
        char *history_id;
        cut_len         = cut_pos1 - 1;
        history_id      = substr(line, 0, cut_len );
        int book_id_int = (int)strtol(history_id, NULL, 10);

        int cut_pos2    = strpos(line, ',', cut_pos1);
        cut_len         = cut_pos2 - cut_pos1 - 1;
        char *book_name = substr(line, cut_pos1, cut_len);

        int cut_pos3     = strpos( line, ',', cut_pos2 );
        cut_len          = cut_pos3 - cut_pos2 - 1;
        char *category   = substr(line, cut_pos2, cut_len);
        int category_int = (int)strtol(category,NULL,10);

        int cut_pos4 = strpos( line, ',', cut_pos3 );
        cut_len      = cut_pos4 - cut_pos3 - 1;
        char *press  = substr(line, cut_pos3, cut_len);

        int cut_pos5  = strpos( line, ',', cut_pos4);
        cut_len       = cut_pos5 - cut_pos4 - 1;
        char *price   = substr(line, cut_pos4, cut_len);
        int price_int = (int)strtol(price,NULL,10);

        int cut_pos6     = strpos( line, ',', cut_pos5 );
        cut_len          = cut_pos6 - cut_pos5 - 1;
        char *can_borrow = substr( line, cut_pos5, cut_len );
        bool borrow_bool = strcmp( "yes", can_borrow ) ? true : false;

        char *remain   = substr( line, cut_pos6, 0);
        int remain_int = (int)strtol(remain,NULL,10);
        book to_append = { book_id_int,
                           book_name,
                           category_int,
                           press,
                           price_int,
                           borrow_bool,
                           remain_int };

        list_append_book( book_list, &to_append);
    }
    return true;
}
void stu_visit(student *stu ){
    extern FILE *fp_stu;
    char stu_no[5];
    itoa(stu->no,stu_no,10);
    fputs( stu_no, fp_stu );
    fputc( ',', fp_stu );
    fputs( stu->name, fp_stu );
    fputc( ',', fp_stu );
}

void io_output_student( link_list_stu *stu_list ) {
    extern FILE *fp_stu;
    if ( ( fp_stu = fopen( "../data/student.txt", "w" ) ) == NULL ) {
        printf("open file failed!");
    }
    list_traverse_stu( stu_list, stu_visit );
}