#include <stdio.h>
#define VMAX 21     // 시력의 최댓값

typedef struct {
	char name[20];
	int height;
	double vision;
} PhysCheck; 

double ave_height(const PhysCheck dat[], int n) {
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += dat[i].height;

	return sum / n;
}

void dist_vision(const PhysCheck dat[], int n, int dist[]) {
	for (int i = 0; i < VMAX; i++) 
		dist[i] = 0;

	for (int i = 0; i < n; i++) 
		if (dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0) 
			dist[(int)(dat[i].vision * 10)]++;
}

void Physical() {
	PhysCheck x[] = {
		{"황승수", 180, 0.5},
		{"김주완", 175, 0.6}
	};

	int nx = sizeof(x) / sizeof(x[0]);
	int vdist[VMAX];
	puts("이름\t\t키\t\t시력\t");

	for (int i = 0; i < nx; i++)
		printf("%-18.18s%4d%5.1f\n", x[i].name, x[i].height, x[i].vision);
	printf("\n평균 키: %5.1fcm\n", ave_height(x, nx));
	
	dist_vision(x, nx, vdist);
	printf("\n시력 분포\n");
	for (int i = 0; i < VMAX; i++)
		printf("%3.1f ~ : %2d명\n", i / 10.0, vdist[i]);

}