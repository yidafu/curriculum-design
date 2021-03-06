// io.c -- 这是一个 IO 库文件，主要负责将文件中的
// 数据读取到链表以及把链表中的数据写入文件。
// author: yidafu
// change by:

#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
#include "../library.h"
#include "../linklist/phpstr.h"
#include "../linklist/link_list_stu.h"
#include "../linklist/link_list_history.h"
#include "io.h"
#include "../linklist/link_list_book.h"

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
        fgets(line,80,fp);
        /// !!! IMPORTENT 文件里面不能有空行
        int cutPos = strpos(line , ',',0);
        char stu_no[5];
        char *stu_name;
        int tmp   = cutPos - 1;
        strncpy(stu_no,line,(size_t) tmp );
        stu_name          = substr(line,cutPos,0);
        int stu_no_insert = atoi(stu_no);
        student to_insert = { stu_no_insert,
                              stu_name
                            };

        list_append_stu( stu_list, &to_insert);
    }
    // 修正读取会重复读取最后一行的 bug
    node_stu *p = stu_list->head->next;
    while( p->next->next ) {
        p = p->next;
    }
    node_stu *q = p->next;
    p->next = NULL;
    stu_list->tail = p;
    free( q );
    fclose(fp);
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
        history_id          = substr(line, 0, cut_len ); // 长度定死了
        int history_id_int  = strtol( history_id, NULL, 10 );
        int cut_pos2        = strpos( line, ',', cut_pos1 );
        cut_len             = cut_pos2 - cut_pos1 - 1;
        char *name          = substr(line, cut_pos1, cut_len);


        int cut_pos3      = strpos( line, ',', cut_pos2 );
        cut_len           = cut_pos3 - cut_pos2 - 1;
        char *borrow_time = substr(line, cut_pos3, cut_len);

        int cut_pos4    = strpos( line, ',', cut_pos3 );
        cut_len = cut_pos4 - cut_pos3 - 1;
        char *return_time = substr(line, cut_pos3, cut_len );


        char *book_name = substr(line, cut_pos4, 0 );

        history to_append = {history_id_int,name, borrow_time, return_time, book_name};
        list_append_history( history_list, &to_append);
    }
    // 修正读取会重复读取最后一行的 bug
    node_history *p = history_list->head->next;
    while( p->next->next ) {
        p = p->next;
    }
    node_history *q = p->next;
    p->next = NULL;
    history_list->tail = p;
    free( q );
    fclose(fp);
    return true;
}
/**
 * 时间解析函数，将时间字符串，转换 my_time 格式的结构体
 * @param time_str 要转换时间字符串
 * @return my_time 类型的结构体指针
 */
my_time parse_time( char *time_str ) {
    my_time return_time_stc;

    int time_pos1 = strpos( time_str, '/',0);
    int time_cut_len = time_pos1 - 1;
    char *year_str = substr( time_str, 0, time_cut_len );
    int year = (int)strtol( year_str, NULL, 10 );
    return_time_stc.year = year;

    int time_pos2 = strpos( time_str, '/', time_pos1);
    time_cut_len = time_pos2 - time_pos1 - 1 ;
    char *month_str = substr( time_str, time_pos1, time_cut_len);
    int month = strtol( month_str, NULL, 10 );
    return_time_stc.month = month;

    char *day_str = substr( time_str, time_pos2, 0 );
    int day = strtol( day_str, NULL, 10 );
    return_time_stc.day = day;

    return return_time_stc;
}

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
        char *can_borrow = substr( line, cut_pos3, cut_len );
        bool borrow_bool = ! strcmp( "yes", can_borrow ) ? true : false;

        int cut_pos5  = strpos( line, ',', cut_pos4);
        cut_len       = cut_pos5 - cut_pos4 - 1;
        char *price   = substr(line, cut_pos4, cut_len);
        int price_int = (int)strtol(price,NULL,10);

        int cut_pos6     = strpos( line, ',', cut_pos5 );
        cut_len          = cut_pos6 - cut_pos5 - 1;
        char *remain   = substr( line, cut_pos5, cut_len );
        int remain_int = (int)strtol(remain,NULL,10);

        char *press  = substr(line, cut_pos6, 0);

        book to_append = { book_id_int,
                           book_name,
                           category_int,
                           price_int,
                           borrow_bool,
                           remain_int,
                           press
                        };

        list_append_book( book_list, &to_append);
    }
    // 修正读取会重复读取最后一行的 bug
    node_book *p = book_list->head->next;
    while( p->next->next ) {
        p = p->next;
    }
    node_book *q = p->next;
    p->next = NULL;
    book_list->tail = p;
    free( q );
    fclose(fp);
    return true;
}

/**
 * 作为遍历函数的参数
 * 写入 stu 的数据到数据存储文件里面去
 * @param stu 要写入文件的学社数据
 */
void stu_visit(student *stu ){
    extern FILE *fp_stu;
    char stu_no[5];
    itoa( stu->no, stu_no, 10 );
    fputs( stu_no, fp_stu );
    fputc( ',', fp_stu );
    fputs( stu->name, fp_stu );
//    fputc( '\n', fp_stu );
    fflush( fp_stu );
}

/**
 * 把链表里面的学生数据写入到文件里面去
 * @param stu_list 存放学生信息的链表
 */
void io_output_student( link_list_stu *stu_list ) {
    extern FILE *fp_stu;
    if ( ( fp_stu = fopen( "../data/student.txt", "w" ) ) == NULL ) {
        printf("open student.txt failed!");
    }
    list_traverse_stu( stu_list, stu_visit );
}

/**
 * 作为链表遍历函数的参数
 * 写入 book 的数据到数据存储文件里面去
 * @param stu 要写入到文件的数据
 */
void book_visit(book *book ) {
    extern FILE *fp_book;

    char book_no[5];
    itoa( book->book_no,book_no, 10 );
    fputs( book_no, fp_book );
    fputc(',', fp_book );

    fputs( book->name, fp_book );
    fputc(',', fp_book );

    char book_category[3];
    itoa( book->category, book_category, 10 );
    fputs( book_category, fp_book );
    fputc(',', fp_book );

    char *can_borrow = book->can_borrow ? "yes" : "no";
    fputs( can_borrow, fp_book );
    fputc(',', fp_book );

    char book_price[5];
    itoa( book->price , book_price, 10 );
    fputs( book_price, fp_book );
    fputc(',', fp_book );



    char book_remain[5];
    itoa( book->remain, book_remain, 10 );
    fputs( book_remain, fp_book );
    fputc(',', fp_book );

    fputs( book->press, fp_book );
    fflush( fp_book );
}

/**
 * 把链表里面的书籍数据写入到文件里面去
 * @param book_list 存放书目信息的链表
 */
void io_output_book( link_list_book *book_list ) {
    extern FILE *fp_book;
    if ( ( fp_book = fopen("../data/book_list.txt", "w") ) == NULL ) {
        printf("open book_list.txt", "w");
    }
    list_traverse_book( book_list, book_visit);
}

/**
 * 作为链表遍历函数的参数
 * 写入 history 的数据到数据存储文件里面去
 * @param stu 要写入到文件的数据
 */
void history_visit( history *history ) {
    extern FILE *fp_history;

    char history_id_str[5];
    itoa( history->history_id, history_id_str, 10 );
    fputs( history_id_str, fp_history );
    fputc( ',', fp_history );

    fputs( history->borrow_by, fp_history );
    fputc( ',', fp_history );

    fputs( history->borrow_time, fp_history );
    fputc( ',', fp_history );

    fputs( history->return_time, fp_history );
    fputc( ',', fp_history );

    fputs( history->book_name, fp_history );
    fflush( fp_history );
}

/**
 * 把链表里面的借阅历史数据写入到文件里面去
 * @param history_list 存放借阅历史的链表
 */
void io_output_history( link_list_history *history_list ) {
    extern FILE *fp_history;
    if ( ( fp_history = fopen("../data/history.txt", "w") ) == NULL ) {
        printf("open history.txe filed");
    }
    list_traverse_history( history_list, history_visit );
}