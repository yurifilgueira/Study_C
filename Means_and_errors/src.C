#include <stdio.h>
#include <math.h>

int main()
{
    int number[9];
    int sum_for_arithmetic_average = 0, multiplication_for_geometric_mean = 1;
    double sum_for_harmonic_mean = 0, arithmetic_average, harmonic_mean, geometric_mean;
    double geometric_error, harmonic_error, average_error;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &number[i]);
        sum_for_arithmetic_average += number[i];
        sum_for_harmonic_mean += (double)1 / number[i];
        multiplication_for_geometric_mean *= number[i];
    }

    for (int i = 0; i < 10; i++)
    {
        arithmetic_average = (double)sum_for_arithmetic_average / 10;
        harmonic_mean = 10 / sum_for_harmonic_mean;
        geometric_mean = pow(multiplication_for_geometric_mean, 0.1);
    }

    harmonic_error = ((harmonic_mean - arithmetic_average) / arithmetic_average);
    geometric_error = ((geometric_mean - arithmetic_average) / arithmetic_average);
    average_error = ((geometric_error + harmonic_error) / 2) * 100;

    printf("Média aritimética é %.2lf\n", arithmetic_average);
    printf("Média harmônica é %.2lf\n", harmonic_mean);
    printf("Média geométrica é %.2lf\n", geometric_mean);
    printf("Erro médio é %.2lf %% \n", average_error);

    return 0;
}