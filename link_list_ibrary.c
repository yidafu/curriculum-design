// test.c -- 这是一个注释示例文件
// author: yidafu
// change by: XX，YY

#include "library.h"
#include "link_list_book.h"
#include <stdio.h>

bool get_by_category(int category,link_list_book *srcrose, link_list_book  *get_list) {
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