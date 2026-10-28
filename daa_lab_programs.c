/* ===================== 1a) DFS - Graph Connectivity ===================== */
#include<stdio.h>
int a[20][20], reach[20], n;

void dfs(int v)
{
    int i;
    reach[v] = 1;
    for(i = 1; i <= n; i++)
    {
        if(a[v][i] && !reach[i])
        {
            printf("\n %d->%d", v, i);
            dfs(i);
        }
    }
}

void main()
{
    int i, j, count = 0;
    printf("\n Enter number of vertices:");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        reach[i] = 0;
        for(j = 1; j <= n; j++)
            a[i][j] = 0;
    }
    printf("\n Enter the adjacency matrix:\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    dfs(1);
    printf("\n");
    for(i = 1; i <= n; i++)
    {
        if(reach[i])
            count++;
    }
    if(count == n)
        printf("\n Graph is connected");
    else
        printf("\n Graph is NOT connected");
}


/* ===================== 1b) BFS ===================== */
#include<stdio.h>
int a[20][20], visited[20], q[20], n, f = 0, r = -1;

void bfs(int v)
{
    int i;
    visited[v] = 1;
    q[++r] = v;
    while(f <= r)
    {
        v = q[f++];
        printf("%d ", v);
        for(i = 1; i <= n; i++)
        {
            if(a[v][i] && !visited[i])
            {
                visited[i] = 1;
                q[++r] = i;
            }
        }
    }
}

void main()
{
    int i, j, v, count = 0;
    printf("\n Enter number of vertices:");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        visited[i] = 0;
    printf("\n Enter the adjacency matrix:\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("\n Enter the starting vertex:");
    scanf("%d", &v);
    printf("\n BFS traversal: ");
    bfs(v);
    for(i = 1; i <= n; i++)
    {
        if(visited[i])
            count++;
    }
    if(count == n)
        printf("\n Graph is connected");
    else
        printf("\n Graph is NOT connected");
}


/* ===================== 2a) Merge Sort ===================== */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void Merge(int a[], int low, int mid, int high)
{
    int i, j, k, temp[high - low + 1];
    i = low;
    k = 0;
    j = mid + 1;
    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while(i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    while(j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
    for(i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}

void MergeSort(int a[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

void main()
{
    int n, a[100], k;
    clock_t st, et;
    double ts;
    printf("\n Enter How many Numbers: ");
    scanf("%d", &n);
    printf("\nThe Random Numbers are:\n");
    for(k = 1; k <= n; k++)
    {
        a[k] = rand() % (100 - 50 + 1) + 50;
        printf("%d\t", a[k]);
    }
    st = clock();
    for(k = 1; k < 10000; k++)
        MergeSort(a, 1, n);
    et = clock();
    ts = (float)(et - st) / CLOCKS_PER_SEC;
    ts = ts / 10000;
    printf("\nSorted Numbers are: \n ");
    for(k = 1; k <= n; k++)
        printf("%d\t", a[k]);
    printf("\nThe time taken is %e sec", ts);
}


/* ===================== 2b) Quick Sort ===================== */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void Exch(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

int partition(int a[], int low, int high)
{
    int key = low;
    int i = low + 1;
    int j = high;
    while(i <= j)
    {
        while(a[i] <= a[key])
            i = i + 1;
        while(a[j] > a[key])
            j = j - 1;
        if(i < j)
            Exch(&a[i], &a[j]);
    }
    Exch(&a[j], &a[key]);
    return j;
}

void QuickSort(int a[], int low, int high)
{
    int j;
    if(low >= high)
        return;
    j = partition(a, low, high);
    QuickSort(a, low, j - 1);
    QuickSort(a, j + 1, high);
}

void main()
{
    int n, a[100], k;
    clock_t st, et;
    double ts;
    printf("\n Enter How many Numbers: ");
    scanf("%d", &n);
    printf("\nThe Random Numbers are:\n");
    for(k = 1; k <= n; k++)
    {
        a[k] = rand() % (100 - 50 + 1) + 50;
        printf("%d\t", a[k]);
    }
    st = clock();
    for(k = 1; k < 10000; k++)
        QuickSort(a, 1, n);
    et = clock();
    ts = (float)(et - st) / CLOCKS_PER_SEC;
    ts = ts / 10000;
    printf("\nSorted Numbers are: \n ");
    for(k = 1; k <= n; k++)
        printf("%d\t", a[k]);
    printf("\nThe time taken is %e sec", ts);
}


/* ===================== 3a) Knapsack - Brute Force ===================== */
#include<stdio.h>

void main()
{
    int n, i, j, w[20], p[20], cap, tw, tp, maxp = 0, best = 0, total;
    printf("\nEnter the number of items: ");
    scanf("%d", &n);
    printf("Enter the profit and weight of each item\n");
    for(i = 0; i < n; i++)
    {
        printf("For item no %d\n", i + 1);
        scanf("%d%d", &p[i], &w[i]);
    }
    printf("\nEnter the capacity: ");
    scanf("%d", &cap);
    total = 1 << n;
    for(i = 0; i < total; i++)
    {
        tw = 0;
        tp = 0;
        for(j = 0; j < n; j++)
        {
            if(i & (1 << j))
            {
                tw += w[j];
                tp += p[j];
            }
        }
        if(tw <= cap && tp > maxp)
        {
            maxp = tp;
            best = i;
        }
    }
    printf("\nItems included are\nItem\tweight\tprofit\n");
    for(j = 0; j < n; j++)
    {
        if(best & (1 << j))
            printf("%d\t%d\t%d\n", j + 1, w[j], p[j]);
    }
    printf("Total profit = %d\n", maxp);
}


/* ===================== 3b) Knapsack - Greedy ===================== */
#include<stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0;
    int i;
    float u;
    u = capacity;
    for(i = 0; i < n; i++)
        x[i] = 0.0;
    for(i = 0; i < n; i++)
    {
        if(weight[i] > u)
            break;
        else
        {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }
    if(i < n)
        x[i] = (u / weight[i]);
    tp = tp + (x[i] * profit[i]);
    printf("\nThe result vector is:- ");
    for(i = 0; i < n; i++)
        printf("%f\t", x[i]);
    printf("\nMaximum profit is:- %f", tp);
}

int main()
{
    float weight[20], profit[20], capacity;
    int num, i, j;
    float ratio[20], temp;
    printf("\nEnter the no. of objects:- ");
    scanf("%d", &num);
    printf("\nEnter the weights of %d objects :- ", num);
    for(i = 0; i < num; i++)
        scanf("%f", &weight[i]);
    printf("\nEnter the profits of %d objects :- ", num);
    for(i = 0; i < num; i++)
        scanf("%f", &profit[i]);
    printf("\nEnter the capacity of knapsack:- ");
    scanf("%f", &capacity);
    for(i = 0; i < num; i++)
        ratio[i] = profit[i] / weight[i];
    for(i = 0; i < num; i++)
    {
        for(j = 0; j < num - i - 1; j++)
        {
            if(ratio[j] < ratio[j + 1])
            {
                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;

                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;
            }
        }
    }
    knapsack(num, weight, profit, capacity);
    return(0);
}


/* ===================== 3c) 0/1 Knapsack - Dynamic Programming ===================== */
#include<stdio.h>
int w[10], p[10], v[10][100], n, i, j, cap, x[10] = {0};

int max(int i, int j)
{
    return ((i > j) ? i : j);
}

int knap(int i, int j)
{
    int value;
    if(v[i][j] < 0)
    {
        if(j < w[i])
            value = knap(i - 1, j);
        else
            value = max(knap(i - 1, j), p[i] + knap(i - 1, j - w[i]));
        v[i][j] = value;
    }
    return(v[i][j]);
}

void main()
{
    int profit, count = 0;
    printf("\nEnter the number of elements\n");
    scanf("%d", &n);
    printf("Enter the profit and weights of the elements\n");
    for(i = 1; i <= n; i++)
    {
        printf("For item no %d\n", i);
        scanf("%d%d", &p[i], &w[i]);
    }
    printf("\nEnter the capacity \n");
    scanf("%d", &cap);
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= cap; j++)
        {
            if((i == 0) || (j == 0))
                v[i][j] = 0;
            else
                v[i][j] = -1;
        }
    }
    profit = knap(n, cap);
    i = n;
    j = cap;
    while(j != 0 && i != 0)
    {
        if(v[i][j] != v[i - 1][j])
        {
            x[i] = 1;
            j = j - w[i];
            i--;
        }
        else
            i--;
    }
    printf("Items included are\n");
    printf("Sl.no\tweight\tprofit\n");
    for(i = 1; i <= n; i++)
    {
        if(x[i])
            printf("%d\t%d\t%d\n", ++count, w[i], p[i]);
    }
    printf("Total profit = %d\n", profit);
}


/* ===================== 4a) Prim's Algorithm ===================== */
#include<stdio.h>
int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

void main()
{
    printf("\n Enter the number of nodes:");
    scanf("%d", &n);
    printf("\n Enter the adjacency matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    visited[1] = 1;
    printf("\n");
    while(ne < n)
    {
        for(i = 1, min = 999; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] < min)
                {
                    if(visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if(visited[u] == 0 || visited[v] == 0)
        {
            printf("\n Edge %d:(%d %d) cost:%d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n Minimum cost=%d", mincost);
}


/* ===================== 4b) Kruskal's Algorithm ===================== */
#include<stdio.h>
#include<stdlib.h>
int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];
int find(int);
int uni(int, int);

void main()
{
    printf("\n\n\tImplementation of Kruskal's algorithm\n\n");
    printf("\nEnter the no. of vertices\n");
    scanf("%d", &n);
    printf("\nEnter the cost adjacency matrix\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    printf("\nThe edges of Minimum Cost Spanning Tree are\n\n");
    while(ne < n)
    {
        for(i = 1, min = 999; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if(uni(u, v))
        {
            printf("\n%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n\tMinimum cost = %d\n", mincost);
}

int find(int i)
{
    while(parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if(i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
