//
//#include<stdlib.h>
//#include<iostream>
//using namespace std;
//
//
//int main() {
//	int a[3][4];
//
//	int num = 1;
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 4; j++) {
//			a[i][j] = num++;
//			cout << a[i][j];
//		}
//		cout << endl;
//	}
//
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 4; j++) {
//			cout << "  a[" << i << "][" << j << "]" << " = " << a[i][j];
//		}
//		cout << endl;
//	}
//	cout << *(*a + 12) << endl;
//
//
//	int** b;
//	b = (int**)malloc(sizeof(int*) * 3);
//	for (int i = 0; i < 3; i++) {
//		if(b+i)
//			*(b + i) = (int*)malloc(sizeof(int) * 4);
//	}
//
//	int num1 = 1;
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 4; j++) {
//			if (b) {
//				b[i][j] = num1++;
//				cout <<"   " << b[i][j];
//			}
//		}
//		cout << endl;
//	}
//
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 4; j++) {
//			if (b)
//				cout << "  b[" << i << "][" << j << "]" << " = " << &b[i][j];
//		}
//		cout << endl;
//	}
//	return 0;
//}