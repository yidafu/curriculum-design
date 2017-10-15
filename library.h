//
// Created by yidafu on 2017/10/11.
//

#ifndef CURRICULUM_DESIGN_LIBRARY_H
#define CURRICULUM_DESIGN_LIBRARY_H
#define false 0
#define true 1
#define elem_type int


void file_test();
//
//typedef int bool;
//
//typedef struct {
//    int no;
//    char *name;
//    int category;
//    char *press;
//    float price;
//    bool can_borrow;
//    int remain;
//} book ;
//
//typedef struct {
//    int year;
//    int month;
//    int day;
//} my_time;
//
//typedef struct {
//    int history_id;
//    char *borrow_by;
//    char *book_name;
//    my_time *borrow_time;
//    my_time *return_time;
//} borrow_history;
//
//typedef struct {
//    int no;
//    char *name;
////    int class;
//};
//
//typedef struct {
//    struct  Node *next;
//    elem_type data;
//} Node;
//
//typedef struct {
//    Node *head;
//    Node *tail;
//    int length;
//} link_list;
//
//// 界面
//void bootstrap()
//void welcome_admin();
//void show_admin_menu();
//void welcome_student(char *name);
//void show_student_menu();
//void show_list(link_list list);
////void print_*();
//void see_you();
//
//
////IO
//bool io_input_histroy(link_list history);
//bool io_input_student(link_list students);
//bool io_input_book_list(link_list book_list);
//bool io_output_histroy(link_list history);
//bool io_output_student(link_list students);
//bool io_output_book_list(link_list book_list);
//
//// 数据层
//// TODO 链表的基本操作
//bool check_stu_no(int stu_no);
//bool check_admin(char *passwd);
//bool get_by_category(int category, link_list *get_list);
//bool borrow_book(char *name);
//bool return_book(char *name);
//void search(char *name,link_list list);
//bool see_self(int stu_no, link_list list);

#endif //CURRICULUM_DESIGN_LIBRARY_H
