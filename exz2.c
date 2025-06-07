#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 666

int main(){
	int N;
	int x;
	clock_t time_req;
	time_req = clock();
	srand(time(NULL));
	
	printf("Input count of random INT: ");
	scanf("%d", &N);
	
	FILE *f = fopen("input.txt", "w");
	for (int i = 0; i < N; i++);
		fprintf(f, "%d ", rand() % 100 + 1);
	fclose(f);
	
    f = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    while (fscanf(f, "%d", &x) == 1) {
        if (x % 5 == 0 && x % 7 == 0)
            fprintf(fout, "FIVESEVEN ");
        else if (x % 5 == 0)
            fprintf(fout, "FIVE ");
        else if (x % 7 == 0)
            fprintf(fout, "SEVEN ");
        else
            fprintf(fout, "%d ", x);
    }
    fclose(f);
    fclose(fout);
	
	f = fopen("input.txt", "r");
	int massive[MAX];
	int count = 0;
	while (fscanf(f, "%d", &massive[count]) == 1)
		count++;
	fclose(f);
	
	int n = 1;
	while (n * n <= count) n++;
	n--;
	int row_sum[MAX] = {0};
	int col_sum[MAX] = {0};
	
	printf("\n Matrix %d x %d and sum \n", n, n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			int val = massive[i * n + j];
			printf("%4d", val);
            row_sum[i] += val;
            col_sum[j] += val;
		}
		printf("| %d\n", row_sum[i]);
	}
    for (int j = 0; j < n; j++)
        printf("%4d", col_sum[j]);
    printf("\n");
	
	time_req = clock() - time_req;
    printf("\nProcessor time taken: %f "
           "seconds\n",
           (float)time_req / CLOCKS_PER_SEC);

    return 0;
}
