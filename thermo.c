#include <stdio.h>
#include <math.h>

#define DXNUM 21
#define DYNUM 21
#define ERR 1.0e-8

void print_x_axis() {
    printf("   i = 0   i = 1   i = 2   i = 3   i = 4");
    printf("   i = 5   i = 6   i = 7   i = 8   i = 9");
    printf("   i = 10  i = 11  i = 12  i = 13  i = 14");
    printf("  i = 15  i = 16  i = 17  i = 18  i = 19");
    printf("  i = 20\n");
}

void print_embellishment(char* message) {
    printf("                                                            ");
    printf("==================================================\n");
    printf("                                                            ");
    printf("                       ");
    printf("%s", message);
    printf("\n                                                            ");
    printf("==================================================\n\n");
    printf("       ");
}

int main()
{
    int i, j, ii, jj;
    double residual;

    ii = DXNUM - 1;
    jj = DYNUM - 1;
    i = 0;
    j = 0;

    // initializes arrays
    double u[DXNUM][DYNUM] = { 0.0 };
    double uu[DXNUM][DYNUM] = { 0.0 };

    for (j = 1; j < jj; j++) {
        u[0][j] = 1.0;
    }

    char init[] = "初期値";

    print_embellishment(init);
    print_x_axis();

    for (j = jj; j >= 0; j--) {
        printf(" j = %d", j);
        if (j < 10) {
            printf(" ");
        }
        for (i = 0; i <= ii; i++) {
            printf("   %.3f", u[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    do {

        // point calculation
        for (j = 1; j < jj; j++) {
            for (i = 1; i < ii; i++) {
                uu[i][j] = (u[i + 1][j] + u[i - 1][j] + u[i][j + 1] + u[i][j - 1]) / 4;
            }
        }

        // residual error calculation
        residual = 0;
        for (j = 1; j < jj; j++) {
            for (i = 1; i < ii; i++) {
                residual = residual + fabs(uu[i][j] - u[i][j]);
            }
        }
        residual = residual /  (((double)ii - 1) * ((double)jj - 1));

        // updating values
        for (j = 1; j < jj; j++) {
            for (i = 1; i < ii; i++) {
                u[i][j] = uu[i][j];
            }
        }
        

    } while (residual > ERR);

    char after[] = "変化後";

    print_embellishment(after);
    print_x_axis();

    for (j = jj; j >= 0; j--) {
        printf(" j = %d", j);
        if (j < 10) {
            printf(" ");
        }
        for (i = 0; i <= ii; i++) {
            printf("   %.3f", u[i][j]);
        }
        printf("\n");
    }
    return 0;
}