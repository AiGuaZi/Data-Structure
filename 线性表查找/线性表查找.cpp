#include <iostream>
#include <stdlib.h>
using namespace std;

#define ERROR -1

//创建测试数组
void creat_nums(int** nums, int nums_length);

int com(const void* a, const void* b);
int search_num(int nums[], int nums_length, int search_elem);
int search_bin_1(int nums[], int nums_length, int search_elem);
int search_bin_2(int nums[], int search_elem, int i_left, int i_right);

//分块查找

#define NO_MEMORY -18
typedef struct block {
	int date;
	int index;
}block;

//初始化所以表
int search_block(int* nums, int nums_length, int search_elem);
void block_Init(block** blo_list, size_t NumOfElememt);
void cut_Block(int* nums, int nums_length, block* blo_list, int* blo_length);
void search_IOfblock(block* blo_list, int search_elem, int blo_length, int* i_left, int* i_right);
void free_block(block* blo_list);

int main() {
	//测试数据
	/*
	14
	1 30 21 33 63 21 32 43 12 12 21 32 53 2
	*/
	cout << "输入数组长度:";
	int nums_length;
	cin >> nums_length;
	int* nums = NULL;
	creat_nums(&nums, nums_length);
	cout << "分块查找2: " << search_block(nums, nums_length, 2) << endl;
	//顺序查找
	cout << "顺序查找21:" << search_num(nums, nums_length, 21) << endl;

	//二分查找
	cout << "二分查找33：" << endl;
	cout << "非递归:" << search_bin_1(nums, nums_length,33) << endl;
	qsort(nums, 14, sizeof(nums[0]), com);
	cout << "  递归:" << search_bin_2(nums, 33,0, nums_length) << endl;

	

	return 0;
}

void creat_nums(int** nums, int nums_length) {

	if (*nums != NULL) return;

	int* temp = NULL;
	temp = (int*)malloc(sizeof(int) * nums_length);
	if (temp == NULL) exit(NO_MEMORY);

	cout << "请输入数组元素:";
	for (int i = 0; i < nums_length; i++) {
		cin >> temp[i];
	}
	*nums = temp;
}

int com(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int search_num(int nums[],int nums_length ,int search_elem) {

	if (nums_length < 1) {
		return ERROR;
	}

	int i = 0;
	//for (i = 0; nums[i] != search_elem && i < nums_length; i++);

	while (nums[i] != search_elem && i < nums_length) i++;

	return i == nums_length ? ERROR : i;
}

int search_bin_1(int nums[], int nums_length , int search_elem) {

	if (nums_length < 1) {
		return ERROR;
	}

	qsort(nums, nums_length, sizeof(nums[0]), com);

	

	int i_left = 0;
	int i_right = nums_length - 1;
	while (i_left <= i_right) {
		int i_mid = i_left + (i_right - i_left) / 2;
		if (nums[i_mid] == search_elem) return i_mid;
		else if (nums[i_mid] < search_elem) i_left = i_mid + 1;
		else i_right = i_mid - 1;
	}

	return ERROR;
}

int search_bin_2(int nums[], int search_elem,int i_left ,int i_right) {

	if (i_left == i_right && i_left > 0 && nums[i_left] == search_elem) {
		return i_left;
	}

	int i_mid = i_left + (i_right - i_left) / 2;

	nums[i_mid] < search_elem ? search_bin_2(nums, search_elem, i_mid + 1,i_right)
		                      : search_bin_2(nums, search_elem, i_left, i_mid - 1);
}

void block_Init(block** blo_list,size_t NumOfElememt) {

	if (*blo_list != NULL)return;

	*blo_list = (block*)malloc(sizeof(block) * NumOfElememt);
	if (*blo_list == NULL) exit(NO_MEMORY);
}

void cut_Block(int* nums, int nums_length, block* blo_list,int *blo_length) {

	if (nums == NULL || nums_length <= 0 || blo_list == NULL)return;

	int top_blo = 0;
	int i = 0;

	//分块
	while (i < nums_length) {

		int temp_elem = nums[i];

		blo_list[top_blo].date = temp_elem;
		blo_list[top_blo].index = i;
		top_blo++;
		i++;

		while (i < nums_length && nums[i] <= temp_elem) i++;
	}
	*blo_length = top_blo;

	cout << "分块情况:" << endl;
	for (int i = 0; i < top_blo; i++) {
		cout << blo_list[i].date << " " << blo_list[i].index << endl;
	}
	cout << endl << endl;
	//分块之后，块间元素必然有序
}

void search_IOfblock(block* blo_list, int search_elem,int blo_length,int* i_left,int *i_right) {
	
	if (blo_list == NULL) return;

	int i_Left = 0;
	int i_Right = blo_length - 1;
	
	while (i_Left < i_Right) {

		int i_mid = i_Left + (i_Right - i_Left + 1) / 2;

		if (blo_list[i_mid - 1].date >= search_elem && blo_list[i_mid].date < search_elem) break;
		else if (blo_list[i_mid].date > search_elem) i_Right = i_mid - 1;
		else i_Left = i_mid + 1;
	}
	*i_left = blo_list[i_Left].index;
	if (i_Left < i_Right) *i_right = blo_list[i_Left + 1].index;
}

int search_block(int *nums, int nums_length, int search_elem) {

	if (nums == NULL || nums_length <= 0) {
		return ERROR;
	}

	//初始化索引表
	block* i_B = NULL;
	block_Init(&i_B, nums_length);
	//进行分块
	int i_B_length = NULL;
	cut_Block(nums, nums_length, i_B, &i_B_length);
	//查找目标元素在索引表的范围
	int i_left = 0;
	int i_right = nums_length - 1;
	int ret = -1;
	search_IOfblock(i_B, search_elem, i_B_length, &i_left,&i_right);

	for (int i = i_left; i <= i_right; i++) {
		if (nums[i] == search_elem) {
			ret = i;
			break;
		}
	}
	//释放索引表
	free_block(i_B);
	//返回查找结果
	return ret;
}

void free_block(block* blo_list) {
	if (blo_list == NULL)return;

	free(blo_list);
	blo_list = NULL;
}