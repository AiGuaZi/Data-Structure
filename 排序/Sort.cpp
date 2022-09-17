#include"Sort.h"

void Init_Sqlist(SqList* list) {

	list->date_array = (DateArrayNode*)malloc(sizeof(DateArrayNode) * INIT_SIZE);
	if (list->date_array == NULL) no_memory();
	list->length = INIT_SIZE;
	list->i_now = 0;
}

void creat_Sqlist(SqList* list) {

	if_NULL(list);

	cout << "请输入元素个数:";
	int num_count = 0;
	cin >> num_count;

	cout << "请输入排序元素:";

	while (num_count > 0) {

		if (is_full(list)) {
			extend_list(list, list->length + ADD_SIZE);
			cout << "表空间增加" << ADD_SIZE << endl;
		}
		input_date(list);
		num_count--;
	}
}

bool is_full(SqList* list) {
	
	if_NULL(list);
	bool ret = false;
	if (list->i_now == list->length) ret = true;
	return ret;
}

void no_memory() {

	cout << endl << "ERROR:" << NO_MEMORY << "内存不足!" << endl;
	exit(NO_MEMORY);

}

void if_NULL(SqList* list) {

	if (list == NULL) {
		cout << endl << "ERROR:" << ERROR << "传入参数为空指针!" << endl;
		exit(ERROR);
	}
}

void extend_list(SqList* list, int new_length) {

	if_NULL(list);
	if (new_length < 1) exit(ERROR);

	DateArrayNode* newbase = NULL;
	newbase = (DateArrayNode*)realloc(list->date_array, sizeof(DateArrayNode)*(list->length + ADD_SIZE));
	if (newbase == NULL) no_memory();
	list->date_array = newbase;
	list->length = new_length;

}

void input_date(SqList* list) {

	if_NULL(list);

	//数据输入
	cin >> list->date_array[list->i_now].date.num;                    //输入数值型数据
	

	list->i_now++;
}

void print_Sqlist(SqList list) {

	cout << "------------------------------------" << endl;
	cout << "当前表的空间大小:" << "\t\t" << list.length << endl;
	cout << "当前表的存储位置:" << "\t\t" << list.i_now << endl;
	cout << "------------------------------------" << endl;
	cout << "表内信息:" << endl;
	for (int i = 0; i < list.i_now; i++) {
		print_Date(list.date_array[i].date);
	}
	cout << "------------------------------------" << endl;
}

void print_Date(Date date) {

	cout << "num:" << "\t" << date.num 
		/*输入其他添加数据*/
		<< endl;
}

void set_sentry(SqList* list) {

	if_NULL(list);
	
	if (list->i_now > 1) {
		cout << "ERROR " << ERROR << ":设置失败!" << endl;
		return;
	}
	list->i_now = 1;

	list->date_array[0].key = CENTRY;
	memset(&list->date_array[0].date, 0, sizeof(Date));
}

void insert_sort_direct(SqList* list) {

	if_NULL(list);
	//判断排除一个元素进行排序
	if (list->i_now <= 2 && list->date_array[0].key == CENTRY) return;//以设置哨兵
	if (list->i_now <= 1 && list->date_array[0].key != CENTRY) return;//未设置哨兵

	if (list->date_array[0].key == CENTRY) {
		for (int i_sort = 2; i_sort < list->i_now; i_sort++) {

			int i_insert = i_sort - 1;

			list->date_array[0].date = list->date_array[i_sort].date;
			for (i_insert = i_sort - 1; list->date_array[0].date.num < list->date_array[i_insert].date.num; i_insert--) {
				list->date_array[i_insert + 1].date.num = list->date_array[i_insert].date.num;
			}

			list->date_array[i_insert + 1].date = list->date_array[0].date;
		}
	}
	else {
		for (int i_sort = 1; i_sort < list->i_now; i_sort++) {

			int i_insert = i_sort - 1;

			int temp_num = list->date_array[i_sort].date.num;
			for (i_insert = i_sort - 1; temp_num < list->date_array[i_insert].date.num && i_insert >= 0; i_insert--) {
				list->date_array[i_insert + 1].date.num = list->date_array[i_insert].date.num;
			}

			list->date_array[i_insert + 1].date.num = temp_num;
		}
	}
}

int bin_search_Sqlist(SqList* list, Date elem, int begin, int end) {

	if_NULL(list);

	int i_left = begin;
	int i_right = end;

	while (i_left <= i_right) {

		int i_mid = i_left + (i_right - i_left) / 2;

		if (elem.num <= list->date_array[i_mid].date.num) i_right = i_mid - 1;
		else i_left = i_mid + 1;

	}

	return i_left;
}

void insert_sort_bin(SqList* list) {

	if_NULL(list);

	if (list->i_now <= 2 && list->date_array[0].key == CENTRY) return;//以设置哨兵
	if (list->i_now <= 1 && list->date_array[0].key != CENTRY) return;//未设置哨兵

	if (list->date_array[0].key == CENTRY) {
		
		for (int i_sort = 2; i_sort < list->i_now; i_sort++) {

			int i_insert = bin_search_Sqlist(list, list->date_array[i_sort].date, 1, i_sort);

			Date temp_date = list->date_array[i_sort].date;
			for (int i = i_sort; i > i_insert; i--) {
				list->date_array[i].date = list->date_array[i - 1].date;
			}

			list->date_array[i_insert].date = temp_date;
		}
	}
	else {

		for (int i_sort = 1; i_sort < list->i_now; i_sort++) {

			int i_insert = bin_search_Sqlist(list, list->date_array[i_sort].date, 0, i_sort);

			Date temp_date = list->date_array[i_sort].date;
			for (int i = i_sort; i > i_insert; i--) {
				list->date_array[i].date = list->date_array[i - 1].date;
			}

			list->date_array[i_insert].date = temp_date;
			//print_Sqlist(*list);
		}
		
	}
}