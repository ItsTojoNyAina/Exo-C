#include <stdio.h>

struct heure
{
    int h;
    int min;
    int sec;
} h1, h2;

int conversion(int h, int min, int s)
{
    return s + (min * 60) + (3600 * h);
}

void reconversion(int h, int min, int s)
{
    int hours = s / 3600;
    int minutes = (s % 3600) / 60;
    double seconds = (s % 3600) % 60;
    printf("%d:%d:%.2lf\n", hours, minutes, seconds);
}

void addition(int h, int m, int s)
{
    int hours = h + h1.h;
    int minutes = m + h1.min;
    int seconds = s + h1.sec;

    if (seconds >= 60)
    {
        minutes += seconds / 60;
        seconds %= 60;
    }

    if (minutes >= 60)
    {
        hours += minutes / 60;
        minutes %= 60;
    }

    printf("%d:%d:%d\n", hours, minutes, seconds);
}

int main()
{
    printf("Entrez l'heure : ");
    scanf("%d", &h1.h);
    printf("Entrez les minutes : ");
    scanf("%d", &h1.min);
    printf("Entrez le secondes : ");
    scanf("%d", &h1.sec);

    printf("Conversion en secondes: %d\n", conversion(h1.h, h1.min, h1.sec));

    printf("Reconversion en heures: ");
    reconversion(h1.h, h1.min, h1.sec);

    printf("Entrez l'heure : ");
    scanf("%d", &h2.h);
    printf("Entrez les minutes : ");
    scanf("%d", &h2.min);
    printf("Entrez le secondes : ");
    scanf("%d", &h2.sec);

    printf("Addition des deux heures : ");
    addition(h2.h, h2.min, h2.sec);

    return 0;
}
