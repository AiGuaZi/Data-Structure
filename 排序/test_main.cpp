#include"Sort.h"

int main() {

	SqList num_list_1;
	Init_Sqlist(&num_list_1);
	/*Î´ÉèÖÃÉÚ±ø*/
	creat_Sqlist(&num_list_1);
	//insert_sort_direct(&num_list_1);
	insert_sort_bin(&num_list_1);
	print_Sqlist(num_list_1);

	/*ÉèÖÃÉÚ±ø*/
	SqList num_list_2;
	Init_Sqlist(&num_list_2);
	set_sentry(&num_list_2);
	creat_Sqlist(&num_list_2);
	//insert_sort_direct(&num_list_2);
	insert_sort_bin(&num_list_2);
	print_Sqlist(num_list_2);
	return 0;
}

/*
29
38 2 45 1 67 54 80 61 42 68 11 74 62 81 24 87 88 3000 100 103 107 3 113 46 120 123 33 130 200
*/