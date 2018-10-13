#include <cstdio>

const int SIZE = 5;

bool is_sink(int (*m)[SIZE], int num, int index) {
	bool flag = true;
	for(int k = 0; k < num - 1; ++k) {
		if(m[index][k] == 1) flag = false;
		// printf("%d %d\n", flag, m[index][k]);
	}
	for(int k = 0; k < num; ++k) {
		if(k != index && m[k][index] == 0) flag = false;
		// printf("%d %d\n", flag, m[k][index]);
	}
	return flag;
}
// time: theta(V)
int universal_sink(int (*m)[SIZE], int num) {
    int i = 0, j = 0;
	
	while(j < num) {
		// printf("i=%d,j=%d,m[i][j]=%d\n", i, j, m[i][j]);
		if(m[i][j] == 1) {
			if(j == num - 1) {
                if(is_sink(m, num, num-1)) return num-1;
				else return -1;
			}

			i = j++;
		} else if(m[i][j] == 0) {
			if(j == num - 1) {
                if(is_sink(m, num, i)) return i;
				else return -1;
			}
			++j;
		}
	}
	return -1;
}

int main() {
	int g0[SIZE][SIZE] = {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
	};
	int g1[SIZE][SIZE] = {
		{0, 1, 0, 1, 1},
		{0, 0, 1, 1, 1},
		{0, 1, 0, 1, 0},
		{0, 0, 0, 0, 0}, // universal sink
		{1, 1, 0, 1, 0},
	};
	int g2[SIZE][SIZE] = {
		{0, 1, 0, 1, 1},
		{0, 0, 1, 1, 1},
		{0, 1, 0, 1, 0},
		{0, 0, 1, 0, 0}, 
		{1, 1, 0, 1, 0},
	};
	int g3[SIZE][SIZE] = {
		{0, 1, 0, 1, 1},
		{1, 0, 1, 1, 1},
		{0, 1, 0, 1, 1},
		{1, 0, 1, 0, 1},
		{0, 0, 0, 0, 0}, // universal sink
	};
	int g4[SIZE][SIZE] = {
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0}, // universal sink
	};

	printf("universal sink: %d\n", universal_sink(g0, SIZE));
	printf("universal sink: %d\n", universal_sink(g1, SIZE));
	printf("universal sink: %d\n", universal_sink(g2, SIZE));
	printf("universal sink: %d\n", universal_sink(g3, SIZE));
	printf("universal sink: %d\n", universal_sink(g4, SIZE));
    return 0;
}
