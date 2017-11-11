// test.c -- 这是一个注释示例文件
// author: yidafu
// change by: XX，YY

#include "../library.h"
#include "link_list_book.h"
#include "link_list_history.h"
#include <stdio.h>
#include <malloc.h>
#include <mem.h>

void list_set_book(link_list_book *list,int i,book *e){
    if(i<1||i>list->length)
        return;
    node_book *p,*q;
    int k = 1;
    q = (node_book *)malloc(sizeof(node_book));
    q->data = *e;
    p = list->head;
    while(k<i){
        p = p->next;
        k++;
    }
    q->next = p->next->next;
    free(p->next);
    p->next = q;
}

bool get_by_category( int category, link_list_book *srcrose, link_list_book  *get_list) {
    node_book *traveler = srcrose->head->next;
    while ( traveler != NULL) {
        if ( traveler->data.category == category ) {
            book new_book;
            new_book = traveler->data;
            list_append_book( get_list, &new_book );
        }
        traveler = traveler->next;
    }
}
bool like( char *srcrose, char *target ) {
    char *q = srcrose, *p = target;
    while( *q != '\0' ) {
        if( *q != *p ) {
            q ++;
        } else {
            p ++;
        }
        if( *p == '\0' ) {
            return true;
        }
    }
    return false;
}
void search(char *name,link_list_book *srcrose, link_list_book *get_list ) {
    node_book *traveler = srcrose->head->next;
    while ( traveler != NULL ) {
        if ( like( traveler->data.name , name ) ) {
            book new_book;
            new_book = traveler->data;
            list_append_book( get_list, &new_book );
        }
        traveler = traveler->next;
    }
}


int book_equal(book a,book b){
    int i;
    for( i = 0; a.name[i]!='\0'&&b.name[i]!='\0';i++) {
        if(a.name[i]!=b.name[i]) {
            return false;
        }
    }
    if(a.name[i]!=b.name[i]) {
        return false;
    }

    return true;
}

bool borrow_book(char* name, link_list_book *book_pass,link_list_history *history_pass) {
    extern char stu_name_g[10];
    node_book *p = book_pass->head->next;
    while ( p ) {
        if ( ! strcmp(p->data.name,name) ) {
            if ( p->data.remain > 0 ) {
                p->data.remain --;
            } else {
                printf("fail to borrow book!\b");
                return false;
            }
            char book_name[20];
            char *ch = book_name;
            int len = strlen( p->data.name );
            strcpy( book_name, p->data.name );
            book_name[len] = '\n';
            book_name[ len + 1 ] = '\0';
            history history_i ;
            history_i.history_id = 0;
            history_i.borrow_by = stu_name_g;
            history_i.borrow_by[ strlen( history_i.borrow_by ) - 1 ] = '\0';
            history_i.borrow_time = "2017/11/16";
            history_i.return_time =  "2017/12/16";
            history_i.book_name = ch;
//            = { 0 , stu_name,"2017/11/16", "2017/12/16", p->data.name };
            list_append_history( history_pass, &history_i );
            return true;
        }
        p = p->next;
    }
    return false;
}

bool return_book(char *name,link_list_book *book_pass,link_list_history *history_pass) {
//    extern char stu_name_g[10];
    node_book *p = book_pass->head->next;
    while ( p ) {
        if ( ! strcmp( p->data.name, name ) ) {
            if ( p->data.remain > 0 ) {
                p->data.remain ++;
                node_history *q = history_pass->head;
                char book_name[20];
                strcpy( book_name, name );
                int len = strlen( book_name );
                book_name[ len ] = '\n';
                book_name[ len + 1 ] = '\0';
                while ( q->next ) {
                    if ( ! strcmp( q->next->data.book_name, book_name ) ) {
                        node_history *to_free = q->next;
                        q->next = q->next->next;
                        free( to_free );
                        return true;
                    }
                    q = q->next;
                }
                printf("\t\treturn failed!");
                return false;
            } else {
                printf("\t\tthis book remain 0\n");
                return false;
            }
        }
        p = p->next;
    }
    return false;
}