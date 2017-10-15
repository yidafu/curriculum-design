// io.c -- 这是一个 IO 库文件，主要负责将文件中的
// 数据读取到链表以及把链表中的数据写入文件。
// author: yidafu
// change by:

#include <stdio.h>
#include <mem.h>
#include "library.h"
#include "phpstr.h"


void file_test() {
    FILE *fp;
    if( (fp = fopen("../data/student.txt","r") ) == NULL ) {
        printf("fail to open file!");
    }
    char line[80];
    while ( fgets(line,80,fp) != NULL || !feof(fp) ) {
//        puts(line);
        int cutPos = strpos(line , ',',0);
//        printf("%d",cutPos);
        char stu_no[5];
        char *stu_name;
        int tmp = cutPos - 1;
        strncpy(stu_no,line,tmp );
        stu_name = substr(line,cutPos,0);
//        int test = 0;
        printf("no: %s  name: %s\n",stu_no,stu_name);
    }
}