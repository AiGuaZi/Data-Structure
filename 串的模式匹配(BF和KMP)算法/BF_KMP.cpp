#include"BF_KMP.h"

int index_BF(char* seek_std, char* main_std) {

	if (seek_std == NULL || main_std == NULL) return -1;

	int seek_std_length = strlen(seek_std);
	int main_std_length = strlen(main_std);

	if (main_std_length < seek_std_length) return -1;

	int index_seek = 0;
	int index_main = 0;

	while (index_seek < seek_std_length && index_main < main_std_length) {

		if (seek_std[index_seek] == main_std[index_main]) {
			index_seek++;
			index_main++;
		}
		else {
			index_main = index_main - index_seek + 1;    //回溯
			index_seek = 0;
		}
	}

	if (index_seek == seek_std_length) return index_main - seek_std_length;

	return -1;
}

void get_next(char* modle_std, int* next) {

	//判断传入参数是否正确
	if (modle_std == NULL || next != NULL) return;

	//计算模式串的长度
	int modle_std_length = strlen(modle_std);

	//分配next数组的内存
	next = (int*)malloc(sizeof(int) * modle_std_length);
	if (!next) return;

	int i = 1;
	int j = 0;
	next[0] = 0;

	while (i < modle_std_length) {

		while()
	}


}