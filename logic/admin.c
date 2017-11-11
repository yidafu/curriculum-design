//
// Created by asus on 2017/10/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "../library.h"
#include "admin.h"
#include "logic.h"
#include "string.h"
#include "../view/view.h"
bool admin_entry() {
    int loop_admin = 1;  //执行循环的条件
    while( loop_admin ) {
        bool password_flag = judge_password();
        if( password_flag == 1 ) {
            loop_admin = 0;
            welcome_admin();
            int state_flag = 1;
            while ( state_flag ) {
                int cmd_num = 0;
                system("cls");
                show_admin_menu();
                scanf( "%d", &cmd_num );
                switch( cmd_num ) {
                    case 1 :
                        check_lending();
                        system("pause");
                        break;
                    case 2 :
                        buy_book();
                        system("pause");
                        break;
                    case 3 :
                        is_borrowed();
                        system("pause");
                        break;
                    case 4:
                        analyze();
                        system("pause");
                        break;
                    case 5 :
                        state_flag = 0;
                        break;
                    default:
                        system("cls");
                        show_admin_menu();
                }
            }
        } else {
            printf("\t\tYour password is wrong,please input password again!\n");
        }
    }
}

void check_lending () {
    extern link_list_book list_book;
    node_book *p = list_book.head->next;
    printf("\b\t\tbook_name\tcategory\tpress\n");
    while ( p ) {
        char category[3];
        itoa( p->data.category, category, 10 );
        printf("\t%s\t\t%s\t\t%s", p->data.name, category, p->data.press );
        p = p->next;
    }
    printf("\n");
}

bool buy_book(){
    extern link_list_book list_book;
    int book_id = 0;
    char book_name[20];
    int category = 0;
    int price = 0;
    bool can_borrow = true;
    int remain = 10;
    char press[20];
    printf("\n\t\tplace type the book info:");
    scanf("%d %s %d %d %d %s",
          &book_id, book_name, &category, &price, &remain, press);
    int len = strlen( press );
    press[ len ] = '\n';
    press[ len + 1 ] = '\0';
    book book_to_buy = { book_id,
                         book_name,
                         category,
                         price,
                         can_borrow,
                         remain,
                         press
                    };
    list_append_book( &list_book, &book_to_buy );
}
void is_borrowed() {
    printf("\t\ttype the book name you want to know:");
    char book_name[20];
    scanf( "%s", book_name );
    extern link_list_book list_book;
    node_book *p = list_book.head->next;
    while ( p ) {
        if( ! strcmp( p->data.name, book_name)  ){
            if( p->data.can_borrow ) {
                printf("\n\t\tthis book can been borrow!\n");
            } else {
                printf("\n\t\tthis book can't been borrow!\n");
            }
            return;
        }
        p = p->next;
    }
    printf("\n\t\tsorry, this book isn't in the list!\n");
}

void analyze() {
    printf("\n\t\tthis function not come true now!\n");
}
bool judge_password(){
    char str[20];
    scanf("%s",str);//获取输入的密码
    if( ! strcmp( str, "password" ) ) {
        return true;        //密码正确，允许进入
    } else {
        return false;      //密码错误，重新输入
    }
}