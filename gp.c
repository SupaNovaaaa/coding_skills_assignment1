#include <stdio.h>
#include <math.h>

// Method 1: Formula Method O(1)
double SumGeoSeries_Formula(double a, double r, int n) {
    if (r == 1) {
        return a * n;  // special case
    }
    return (a * (pow(r, n) - 1)) / (r - 1);
}

// Method 2: Iterative Method O(n)
double SumGeoSeries_Iterative(double a, double r, int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = sum + a;
        a = a * r;
    }
    return sum;
}

int main() {
    double a, r;
    int n;

    printf("Enter first term (a): ");
    scanf("%lf", &a);

    printf("Enter common ratio (r): ");
    scanf("%lf", &r);

    printf("Enter number of terms (n): ");
    scanf("%d", &n);

    printf("\nUsing Formula Method: %lf\n", SumGeoSeries_Formula(a, r, n));
    printf("Using Iterative Method: %lf\n", SumGeoSeries_Iterative(a, r, n));

    return 0;
}
