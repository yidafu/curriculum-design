//
// Created by asus on 2017/10/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../library.h"
#include "../view/view.h"
#include "../linklist/link_list_stu.h"
#include "../linklist/link_list_library.h"
#include "../linklist/link_list_book.h"
#include "student.h"

bool student_entry() {
    int loop_student = 1;    //执行循环的条件
    while( loop_student ) {
        printf("\n\t\tPlease input your stdent number:");
        bool number_flag = judge_number() ;
        if ( number_flag == 1 ) {
//            show_student_menu();
            welcome_student();
            int menu_flag1;
            int student_flag = 1;
            while( student_flag == 1 ) {
                system("cls");
                show_student_menu();
                scanf( "%d", &menu_flag1 );
                switch(menu_flag1){
                    case 1:
                        search_out();
                        system("pause");
                        break;
                    case 2:
                        borrow();
                        system("pause");
                        break;
                    case 3:
                        return_();
                        system("pause");
                        break;
                    case 4:
                        display_by_category();
                        system("pause");
                        break;
                    case 5:
                        display_all();
                        system("pause");
                        break;
                    case 6:
                        student_flag = 0;
                        break;
                    default:
                        system("cls");
                        show_student_menu();
                }
                loop_student=0;
            }
        } else {
            printf("\tPlease input right number\n");
            system("pause");
            system("cls");
//            loop_student = 0;
        }
    }
}
void search_out() {
    printf("\t\tplace input book name:");
    extern link_list_book list_book;
    link_list_book to_get;
    init_list_book( &to_get );
    char name[20];
    scanf( "%s", name );
    search( name, &list_book, &to_get );
    show_book_list( &to_get );
    destroy_list_book( &to_get );
}

void borrow() {
    printf("\t\tplace input book name:");
    extern link_list_book list_book;
    extern link_list_history list_history;
    char name[20];
    scanf( "%s", name );
    bool success = borrow_book( name, &list_book, &list_history );
    if ( success ) {
        printf("\t\tsuccess to borrow book!\n");
    } else {
        printf("\t\tfail to borrow book!\n");
    }
}

bool return_() {
    printf("\t\tplace input book name:");
    extern link_list_book list_book;
    extern link_list_history list_history;
    char name[20];
    scanf( "%s", name );
    bool success = return_book( name, &list_book, &list_history );
    if ( success ) {
        printf("\t\t\tsuccess to return book!\n");
    } else {
        printf("\t\t\tfail to return book!\n");
    }
}

void display_all() {
    extern link_list_book list_book;
    show_book_list( &list_book );
}
void display_by_category() {
    printf("\t\tplace input category:");
    extern link_list_book list_book;
    link_list_book to_get;
    init_list_book( &to_get );
    int category = 0;
    scanf("%d", &category );
    get_by_category( category, &list_book, &to_get );
    show_book_list( &to_get );
    destroy_list_book( &to_get );
}
bool judge_number(){
    int num;
    extern char stu_name_g[10];
    scanf("%d",&num);       //获取输入的学号
    extern link_list_stu list_stu;
    node_stu *p = list_stu.head->next;
    while( p ) {
        if(p->data.no == num ){
            strcpy( stu_name_g, p->data.name );
            system("cls");
            return true;
        }
        p=p->next;
    }
    return false;
}

void show_book_list( link_list_book *list ) {
    node_book *p = list->head->next;
    printf("\tbook_name\tcategory\tprice\tremain\tpress\n");
    while ( p ) {
        if( p->data.can_borrow ) {
            char category[3];
            itoa( p->data.category, category, 10 );
            char price[5];
            itoa( p->data.price, price, 10 );
            char remain[5];
            itoa( p->data.remain, remain, 10 );
            printf("\t%s\t\t%s\t\t%d\t%s\t%s\n", p->data.name, category, p->data.price, remain, p->data.press );

        }
        p = p->next;
    }
}