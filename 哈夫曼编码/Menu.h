#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

#define SEL_FALSE -1

/*
* 功能:显示进入系统菜单
* 结果:输出选择特殊编码或通用编码
*/
void menu_select_code();

/*
* 功能：选择特殊编码或通用编码
* 结果: 返回所选编码编号,失败返回-1；
*/
int select_code();

/*
* 功能：选择好后进入编码模块
* 结果：返回选择代码
*/
int Menu_Code();