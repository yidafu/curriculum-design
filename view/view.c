// view.c -- 这是一个负责图形化输出的库文件。
// 主要负责启动页面，数据的控制台输出。
// author:
// change by:

#include <stdio.h>
#include <afxres.h>
#include<math.h>

#include "../library.h"

void show_admin_menu(){
    printf("\n    welcome to work!\n\n");
    printf("                 ");
    printf(" ****************************************** \n");
    printf("                         ");
    printf(" ************Menu************ \n\n\n");
    printf("                    ");
    printf("  1.Check the lending\n\n ");
    printf("                    ");
    printf(" 2.Buying books\n\n ");
    printf("                    ");
    printf(" 3.See if a book is being borrowed\n\n ");
    printf("                    ");
    printf(" 4.Analyze the loan situation\n\n ");
    printf("                    ");
    printf(" 5.Exit\n\n ");
    printf("                 ");
    printf(" ******************************************\n ");
    printf("                 ");
    printf(" ****************************************** \n\n\n");
    printf("           please enter a number :");



    Sleep(10000);
}


void show_student_menu(){
    printf("\n    welcome to our library!\n\n");
    printf("                 ");
    printf(" ****************************************** \n");
    printf("                         ");
    printf(" ************Menu************ \n\n\n");
    printf("                    ");
    printf("  1.search\n\n ");
    printf("                    ");
    printf(" 2.borrow book\n\n ");
    printf("                    ");
    printf(" 3.return  book\n\n ");
    printf("                    ");
    printf(" 4.display book by category\n\n ");
    printf("                    ");
    printf(" 5.display all book\n\n ");
    printf("                    ");
    printf(" 6.Exit\n\n ");
    printf("                 ");
    printf(" ******************************************\n ");
    printf("                 ");
    printf(" ****************************************** \n\n\n");
    printf("           please enter a number :");


    Sleep(10000);
}

int welcome_admin(){
    MessageBox (NULL , "Welcome to work!" , "welcome" , 0);

    return 0;
}

void welcome_main(){
    for (float y = 1.5f; y > -1.5f; y -= 0.1f) {
        for (float x = -1.5f; x < 1.5f; x += 0.05f) {
            float a = x * x + y * y - 1;
            putchar(a * a * a - x * x * y * y * y <= 0.0f ? '*' : ' ');
            Sleep(10);
        }
        putchar('\n');
    }
}

int welcome_student(){
    MessageBox (NULL , "Welcome to our library!" , "welcome" , 0);

    return 0;
}

int see_you() {
    double y;
    int x,m;
    for(y=10;y>=-10;y--) {
        m=2.5*sqrt(100-y*y); /*计算行y对应的列坐标m，2.5是屏幕纵横比调节系数因为屏幕的
                                行距大于列距，不进行调节显示出来的将是椭圆*/
        for(x=1;x<30-m;x++){
            printf(" "); /*图形左侧空白控制*/
        }
        printf("See You"); /*圆的左侧*/
        Sleep(50);

        for(;x<30+m;x++) {
            printf(" ");/*图形的空心部分控制*/
        }
        printf("See You\n"); /*圆的右侧*/
        Sleep(50);
    }
    return 0;
}