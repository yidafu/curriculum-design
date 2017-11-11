//
// Created by yidafu on 2017/11/5.
//
#include "../library.h"
#include "logic.h"
#include "stdio.h"
#include <string.h>
int identity() {
    printf("\n\tAre you admin or student?\n");
    char identity[100];
    char id1[]="admin";
    char id2[]="student";
    printf("\t->>");
    scanf( "%s", identity );
    if ( stricmp( identity, id1 ) == 0 ) {
        return 1;
    } else if ( stricmp( identity, id2 ) == 0 ) {
        return 2;
    }
    return false;
}
