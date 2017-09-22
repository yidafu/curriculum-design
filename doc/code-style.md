# 编码规范

## 变量命名

**请务必避免使用 a、b、c、i、j、m、n 类似的变量名，最好使用有实际意义的变量名，但不应超过三个单词**

变量名一律使用单词加下划线的形式，如:

```c
int list_item       = 0;
float bank_account  = 0.0;
```

## 函数命名

同变量命名，如：

```c
int test_function();
```

## 编程风格

### 空格

对于 for ，以及 while 循环中括号里的语句，请务必将每个变量，运算符用空格隔开。增加可读性。

```c
for ( i = 0 ; i < length ; i ++ );

while ( i < length ) ;
```

定义函数时，请务必在括号前后加上空格。同样的，对于参数定义依旧也要的每个变量，关键字前后加空格。

```c
int main () ;
int test_function ( int param1 , int param2 );
```
>调用时函数的括号前后不应使用空格

等号两边都应该加上空格。

```c
int num1    = 1;
int num2    = 3;
double num3 = 30.3;
num1 = num2;
```
### 大括号

本项目使用尾风格。

**函数：**
```c
int main() {
    /* code */
}
```
**循环：**
```c
 int i;
for ( i = 0; i < 10 ; i ++ ) {
    /* code */
}

while ( i < 10 ) {
    /* code */
}
```

### 缩进

**统一使用`Tab`键缩进。**

对于同时对多变量的申明的，请务必换行对齐，对多变量定义且赋值的，请务必将`=`好对齐。

```c
// case 1
int variable1,
    variable2,
    variable3;
// case2
int var_one         = 1;
int test_defined    = 999;
float gold_number   = 100;
double num          = 1.01;
```
