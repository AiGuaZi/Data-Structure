#include"Tu.h"

int main() {

	AMGraph* amg = init_Graph();
	print_AMG(amg);

	bool* visited = creat_and_init_visited(amg);
	DFS(amg, 0, visited);
	cout << endl;
	BFS(amg, 0);
	free(amg);
	free(visited);
	system("pause");
	return 0;
}


/*
5 7
A B C D E
A B 5
A E 2
B C 2
C D 3
E D 2
A D 7
B E 6

*/