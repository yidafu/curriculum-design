//
// Created by yidafu on 2017/10/12.
//
#include <stdio.h>
#include <mem.h>
#include <malloc.h>

/**
 * 这个函数时返回与查找字符相等的字符串中的字符的位置
 * @param haystcak 查找的字符串
 * @param needle   要查找的字符
 * @param offset   偏移量
 * @return 如果查询成功返回一个不小于 1 的数字，否则返回 0
 */
int strpos(char *haystcak,char needle , int offset) {
    char *p = haystcak ;
    p += offset;
    int pos = 1 + offset;
    while(*p != '\0') {
        if (*p == needle ) {
            return pos;
        }
        pos ++;
        p ++;
    }
    return 0;
}
/**
 *
 * @param string 要拷贝的字符串源
 * @param start  拷贝开始的位置，从 1 开始开始数
 * @param length 拷贝的长度，必须大于 1
 * @return char* 截取的字符串首地址，失败返回 NULL
 */
char * substr(char *string, int start, int length ) {
    char *p = string,*to_return , *q;
    to_return = q = NULL;
    // 输入值过滤
    if ( ( start < 0 && start >= strlen(string) ) ||
            length + start > strlen(string)) {
        return NULL;
    }
    int index = 0;
    while ( index < start ) {
        p ++;
        index ++;
    }
    int remain_len = strlen(p);
    to_return = q = malloc( remain_len * sizeof(char) );

    // + 1 是为 \0 留出位置
    length = length ? (length + 1) : (remain_len + 1);

    index = 1;
    while( index < length ) {
        *q = *p ++ ;
        q ++;
        index ++;
    }
    *q = '\0';
    return to_return;
}
