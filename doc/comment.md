# 注释说明

+   文件第一行应有文件名和源码的简要介绍的内容
+   第二行应有作者姓名
+   第三行因该是修改者的署名，并在署名下写出具体修改内容（在修改内容后面加上时间和名字。格式如下所示。）
+   每一个函数上都应该有一下信息：
    +   函数功能描述
    +   参数说明
    +   返回值说明
    +   给函数调用的函数列表
    +   调用的该函数的函数列表
+   在一些关键的语句应该加上一定的注释说明
+   对于函数内部变量应该由一行注释说明

**例：**

```c
// test.c -- 这是一个注释示例文件
// author: yidafu
// change by: XX，YY
// 一些修改说明
// |-- XX --|-- 17/9/22 17:49 --|
// 另一些修改说明
// |-- YY --|-- 17/9/22 17:50 --|

#include <stdio.h>

/**
* 这是一个测试函数，主要将两个参数相加返回。
* @param int param1 传入的要相加的第一个数
* @param int param2 传入的要相加的第二个数
* @return int       两数相加的结果
* calling:
* called: main()
*/
int test_function ( int param1, int param2 ) {
    // 假设这是关键步骤
    // 将两数相加并返回
    return param1 + param2 ;
}
/**
* 这个是主函数。
* @param void
* @return int 0
* calling: test_function()
* called:
*/
int main () {
    // 两个相加的数之一
    int test_num1 = 3;
    // 两个相加的数之一
    int test_num2 = 4;
    test_function( test_num1 , test_num2 );
}
```
