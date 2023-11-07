#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum operation { SUM = 0, DIFFERENCE = 1, AVERAGE = 2 };

float sum(float a, float b)
{
    return a + b;
}

float dif(float a, float b)
{
    return a - b;
}

float avg(float a, float b)
{
    return (a + b) / 2;
}

typedef float (*fn)(float, float);
typedef void (*ex)(void);

char* operations_str[] = { "sum", "difference", "average" };
fn operations_fn[] = { &sum, &dif, &avg };

void ex3(void)
{
    int number;

    printf("Please insert a natural number in base 10: ");
    scanf("%d", &number);

    printf("The value of the inserted number [%d] in the {8, 10, 16} bases is: {%o %d %x}.\n",
           number, number, number, number);
}

void ex4(void)
{
    float vec[2];

    for (int i = 0; i < 2; i++) {
        printf("Please insert a real number: ");
        scanf("%f", &vec[i]);
    }

    for (int i = 0; i < 3; i++) {
        printf("The %s of the two numbers is: %.5f\n", operations_str[i],
               operations_fn[i](vec[0], vec[1]));
    }
}

void ex5(void)
{
    int n, s1 = 0, s2 = 0;

    printf("n = ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        s1 += i;
        s2 += i * i;
    }

    printf("S1 = %d\nS2 = %d\n", s1, s2);
}

void ex7(void)
{
    float nums[2];

    for (int i = 0; i < 2; i++) {
        printf("Please enter a real number: ");
        scanf("%f", &nums[i]);
    }

    if (nums[0] - nums[1] == 0.0000f)
        printf("EQ\n");
    else
        printf("NOT EQ\n");
}

ex exercises[] = { NULL, NULL, &ex3, &ex4, &ex5, NULL, &ex7 };

int main(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++) {
        int idx = atoi(argv[i]) - 1;

        if (exercises[idx] != NULL)
            exercises[idx]();
    }

    return 0;
}
