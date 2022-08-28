#include"Tu.h"

int main() {

	cout << "请输入顶点数和边数:";
	int vex_count, arc_count;
	cin >> vex_count >> arc_count;
	AMGraph* amg = init_Graph(vex_count, arc_count);
	creat_Graph(&amg);
	print_AMG(amg);

	bool* visited = creat_and_init_visited(amg);
	DFS(amg, 0, visited);
	cout << endl;
	BFS(amg, 0);

	AMGraph * MST = MST_Prim(amg, 0);
	print_AMG(MST);

	free(amg);
	free(visited);
	free(MST);
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


6 10
A B C D E F
A B 6
A D 5
A C 1
B C 5
C D 5
B E 3 
C E 6
C F 4
D F 2
E F 6
*/