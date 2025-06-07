#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 666

int main() {
    int N;
	clock_t time_req;
	time_req = clock();
	srand(time(NULL));
	int x;
	
    printf("Enter the number of random integers (N): ");
    scanf("%d", &N);

    FILE *f = fopen("input.txt", "w");
    for (int i = 0; i < N; i++)
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
    int massive[MAX], count = 0;
    while (fscanf(f, "%d", &massive[count]) == 1)
        count++;
    fclose(f);

    int n = 1;
    while (n * n <= count) n++;
    n--;
    int row_sums[MAX] = {0}
	int col_sums[MAX] = {0};	

    printf("\nMatrix %dx%d and sum:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = massive[i * n + j];
            printf("%4d", val);
            row_sums[i] += val;
            col_sums[j] += val;
        }
        printf(" | %d\n", row_sums[i]);
    }
    printf("\n");
    for (int j = 0; j < n; j++)
        printf("%4d", col_sums[j]);
    printf("\n");


    time_req = clock() - time_req;
    printf("\nProcessor time taken: %f "
           "seconds\n",
           (float)time_req / CLOCKS_PER_SEC);

    return 0;
}
