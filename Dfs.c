#include <stdio.h>

int n, G[10][10],visited[10];

void dfs(int i)

{

 int j;
 printf("%d",i);
 visited[i]=1;
 for(j=0;j<n;j++)
 {if(!visited[j]&&G[i][j]==1)
 dfs(j);
 }

}

void main()

{

 int i,j;

 printf("Enter the number of vertices: ");

 scanf("%d", &n);

 for (i = 0; i < n; i++)

 {

 visited[i] = 0;

 }

 printf("Enter graph data in matrix form: \n");

 for (i = 0; i <n; i++)

 for (j = 0; j < n; j++)

 scanf("%d", &G[i][j]);

 for(i=0;i<n;i++)
   visited[i]=0;

dfs(0);

}
