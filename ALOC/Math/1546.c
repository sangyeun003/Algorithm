#include    <stdio.h>

double subject[1000];

int main(void)
{
    int     n;
    double  max;
    double  sum;

    scanf("%d", &n);
    max = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &subject[i]);
        if (subject[i] > max)
            max = subject[i];
    }
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        subject[i] = subject[i] / max * 100;
        sum += subject[i];
    }
    printf("%lf\n", sum / n);
    return (0);
}
