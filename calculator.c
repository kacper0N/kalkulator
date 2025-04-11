#include <stdio.h>
#include <stdlib.h>

int main() {
    double a, b;
    char operator;

    printf("Witaj w kalkulatorze!\n");
    printf("Wprowadz dzialanie w formacie: <liczba> <operator> <liczba>\n");
    printf("Obslugiwane operatory: +, -, *, /\n");
    printf("Aby zakonczyc wpisz litere 'q'\n");

    while (1) {
        printf("\nPodaj dzialanie (lub 'q' aby wyjsc): ");

        // Sprawdzamy, czy użytkownik chce zakończyć (jeśli wpisze 'q')
        char ch;
        if (scanf(" %c", &ch) != 1) {
            fprintf(stderr, "Blad odczytu danych.\n");
            break;
        }
        if (ch == 'q' || ch == 'Q') {
            break;
        }
        // Jeśli nie 'q', cofamy odczytany znak do strumienia
        ungetc(ch, stdin);

        // Odczytujemy działanie: <liczba> <operator> <liczba>
        if (scanf("%lf %c %lf", &a, &operator, &b) != 3) {
            printf("Nieprawidlowy format. Sprobuj ponownie.\n");
            // Czyszczenie bufora wejścia
            while (getchar() != '\n');
            continue;
        }

        // Przetwarzanie działania
        switch (operator) {
            case '+':
                printf("Wynik: %.2lf\n", a + b);
                break;
            case '-':
                printf("Wynik: %.2lf\n", a - b);
                break;
            case '*':
                printf("Wynik: %.2lf\n", a * b);
                break;
            case '/':
                if (b == 0) {
                    printf("Blad: Dzielenie przez zero!\n");
                } else {
                    printf("Wynik: %.2lf\n", a / b);
                }
                break;
            default:
                printf("Nieobslugiwany operator: %c\n", operator);
        }
    }

    printf("Koniec dzialania kalkulatora. Do widzenia!\n");
    return 0;
}
