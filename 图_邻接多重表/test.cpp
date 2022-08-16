#include"Tu_No.h"

int main() {

	AGraph* G = creat_AGraph();
	/*for (int i = 0; i < G->vex_count; i++) {
		cout << G->AG[i].date << endl;
		
		ArcNode* p = G->AG[i].head;

		while (p) {
			cout << p->in_vex << ":" << p->out_vex << "\t";
			p = p->in_next;
		}
		cout << endl;
		p = G->AG[i].head;
		while (p) {
			cout << p->in_vex << ":" << p->out_vex << "\t";
			p = p->out_next;
		}
		cout << endl;
	}*/
	print_info(G);

	return 0;
}

/*

5 6
A B C D E
A B 2
B C 2
B E 2
C D 2
C E 2
D A 2

5 6
A B C D E
A B 2
B D 2
A E 2
B C 2
C E 2
C D 2





*/