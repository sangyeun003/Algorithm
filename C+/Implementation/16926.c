#include    <stdio.h>

void rotate(int arr[][300], int start, int size_n, int size_m, int r)
{
    int temp;

    for (int rotation = 0; rotation < r; rotation++)
    {
        temp = arr[start][start];
        for (int i = start; i < start + size_m - 1; i++)
            arr[start][i] = arr[start][i + 1];
        for (int i = start; i < start + size_n - 1; i++)
            arr[i][start + size_m - 1] = arr[i + 1][start + size_m - 1];
        for (int i = start + size_m - 1; i > start; i--)
            arr[start + size_n - 1][i] = arr[start + size_n - 1][i - 1];
        for (int i = start + size_n - 1; i > start + 1; i--)
            arr[i][start] = arr[i - 1][start];
        arr[start + 1][start] = temp;
    }
}

int main(void)
{
    int arr[300][300];
    int n;
    int m;
    int r;
    int min;

    scanf("%d %d %d", &n, &m, &r);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);
    if (n < m)
        min = n;
    else
        min = m;
    for (int i = 0; i < min / 2; i++)
        rotate(arr, i, n - 2 * i, m - 2 * i, r);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    return (0);
}
