#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef void (*ex)(void);

void ex2(void)
{
    int n;

    printf("Please enter an integer: ");
    scanf("%d", &n);

    if (n % 2 == 0 || (n & 1) == 0)
        printf("%d is even.\n", n);
    else
        printf("%d is odd.\n", n);
}

void ex3(void)
{
    for (int i = 3; i >= 1; i--) {
        printf("%d\n", i);
        sleep(1);
    }

    printf("START");
}

void ex4(void)
{
    int edges[3];

    for (int i = 0; i < 3; i++) {
        printf("Please enter %ith edge length: ", i + 1);
        scanf("%d", &edges[i]);
    }

    int a = edges[0];
    int b = edges[1];
    int c = edges[2];

    if (a + b > c && a + c > b && b + c > a)
        printf("YES!\n");
    else
        printf("NO!\n");
}

void ex5(void)
{
    int n;

    printf("Please insert the number of times to generate random numbers: ");
    scanf("%d", &n);

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        printf("The generated numbers are: %d %d %d %d %d\n", (rand() % 100), (rand() % 100),
               (rand() % 100), (rand() % 100), (rand() % 100));
    }

    printf("Running this time with constant value for seed.\n");

    for (int i = 0; i < n; i++) {
        srand(0x1234);

        printf("The generated numbers are: %d %d %d %d %d\n", (rand() % 100), (rand() % 100),
               (rand() % 100), (rand() % 100), (rand() % 100));
    }
}

ex exercises[] = { NULL, &ex2, &ex3, &ex4, &ex5 };

int main(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++) {
        int idx = atoi(argv[i]) - 1;

        if (exercises[idx] != NULL)
            exercises[idx]();
    }

    return 0;
}
