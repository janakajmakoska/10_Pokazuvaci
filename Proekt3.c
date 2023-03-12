#include <stdio.h>

#define STUDENTS 5
#define SUBJECTS 5

void pecatiNiza(int oceni[][SUBJECTS], int brStudenti) {
    for (int i = 0; i < brStudenti; i++) {
        printf("Ocenite na studentot %d: ", i + 1);
        for (int j = 0; j < SUBJECTS; j++) {
            printf("%d ", oceni[i][j]);
        }
        printf("\n");
    }
}

void max(int oceni[][SUBJECTS], int brStudenti) {
    for (int i = 0; i < brStudenti; i++) {
        int maxOcena = oceni[i][0];
        for (int j = 1; j < SUBJECTS; j++) {
            if (oceni[i][j] > maxOcena) {
                maxOcena = oceni[i][j];
            }
        }
        printf("Najvisoka ocena na studentot %d e %d\n", i + 1, maxOcena);
    }
}

void min(int oceni[][SUBJECTS], int brStudenti) {
    for (int i = 0; i < brStudenti; i++) {
        int minOcena = oceni[i][0];
        for (int j = 1; j < SUBJECTS; j++) {
            if (oceni[i][j] < minOcena) {
                minOcena = oceni[i][j];
            }
        }
        printf("Najniska ocena na studentot %d e %d\n", i + 1, minOcena);
    }
}

void prosek(int oceni[][SUBJECTS], int brStudenti) {
    for (int i = 0; i < brStudenti; i++) {
        int suma = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            suma += oceni[i][j];
        }
        float avg = (float) suma / SUBJECTS;
        printf("Prosekot na studentot %d e %.2f\n", i + 1, avg);
    }
}

int main() {
    int oceni[STUDENTS][SUBJECTS] = {
        {8, 7, 6, 9, 8},
        {6, 5, 6, 7, 9},
        {10, 9, 10, 9, 10},
        {7, 8, 6, 7, 9},
        {9, 9, 9, 10, 8}
    };
    int izbor;
    void (*obrabotiOceni[4])(int oceni[][SUBJECTS], int brStudenti) = {pecatiNiza, max, min, prosek};
    do {
        printf("Vnesi izbor:\n");
        printf("0 Ispecati ja nizata so oceni\n");
        printf("1 Najdi ja maksimalnata ocena\n");
        printf("2 Najdi ja minimalnata ocena\n");
        printf("3 Ispecati ja prosechnata ocena za sekoja student\n");
        printf("4 Kraj\n");
        scanf("%d", &izbor);
        if (izbor >= 0 && izbor <= 3) {
            (*obrabotiOceni[izbor])(oceni, STUDENTS);
        } else if (izbor != 4) {
            printf("Nevaliden izbor!\n");
        }
    } while (izbor != 4);
    return 0;
}
