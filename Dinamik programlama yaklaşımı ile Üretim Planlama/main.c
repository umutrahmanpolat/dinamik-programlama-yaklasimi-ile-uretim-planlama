#include <stdio.h>
#include <limits.h>

#define MAX_N 100
#define MAX_M 100

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n, m;
    int i, j, k;

    int processing_time[MAX_N][MAX_M]; 
    int transition_cost[MAX_M][MAX_M]; 
    int dp[MAX_N][MAX_M];
    

    printf("Is sayisini girin: ");
    scanf("%d", &n);  
    printf("Makine sayisini girin: ");
    scanf("%d", &m);  

    printf("Islenme surelerini girin (%d x %d):\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &processing_time[i][j]);  
        }                                         
    }

    printf("Gecis maliyetlerini girin (%d x %d):\n", m, m);
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &transition_cost[i][j]);  
        }                                         
		                                         
    }

    
    for (j = 0; j < m; j++) {
        dp[0][j] = processing_time[0][j];   
    }

    
    for (i = 1; i < n; i++) {
        for (j = 0; j < m; j++) {
            dp[i][j] = INT_MAX;
            for (k = 0; k < m; k++) {
                int cost = dp[i - 1][k] + transition_cost[k][j] + processing_time[i][j];
                dp[i][j] = min(dp[i][j], cost); 
            }            
        }                
    }                    

   
    int result = INT_MAX;
    for (j = 0; j < m; j++) {
        result = min(result, dp[n - 1][j]); 
    }

    printf("Minimum toplam sure: %d\n", result);

    

    return 0;
}

