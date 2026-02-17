/*Да се напише програма во која ќе се дефинира структура за претставување на комплексни
броеви. Потоа да се напишат функции за собирање, одземање и множење на два комплексни
броја. Програмата треба да се тестира со внесување на два комплексни броја. */
#include <stdio.h>
#include <math.h>
struct Kompleksen
{
    int real;
    int imag;
};
typedef struct Kompleksen Kompleksen;
    /* дефинирање на прототип на функции */
Kompleksen soberi(Kompleksen a, Kompleksen b);
Kompleksen odzemi(Kompleksen *p1, Kompleksen *p2);
void mnozhi(Kompleksen a, Kompleksen b, Kompleksen *c);
void pechati(const Kompleksen *p);

int main()
{
    Kompleksen k[2], rez;
    int i;
    printf("Vnesete dva кompleksni broja:\n"); fflush(stdout);
    for (i = 0; i < 2; i++)
    {
        printf("Realen:"); fflush(stdout);
        scanf("%d", &k[i].real);
        printf("Imaginaren:"); fflush(stdout);
        scanf("%d", &k[i].imag);
    }
    printf("Gi vnesovte broevite:\n"); fflush(stdout);
        pechati(&k[0]);
        pechati(&k[1]);
    printf("Nivniot zbir e:\n"); fflush(stdout);
        rez = soberi(k[0], k[1]);
        pechati(&rez);
    printf("Nivnata razlika e:\n"); fflush(stdout);
        rez = odzemi(&k[0], &k[1]);
        pechati(&rez);
    printf("Nivniot proizvod e:\n"); fflush(stdout);
        mnozhi(k[0], k[1], &rez);
        pechati(&rez);
    return 0;
}
void pechati(const Kompleksen *p) /* променливата p е константна, што значи дека 
нејзината вредност не смее да биде променета во оваа функција */
    {
        printf("%4d", p->real);
        p->imag >= 0 ? printf("+j%-4d\n", p->imag) : printf("-j%-4d\n", abs(p->imag)); /*тернарен оператор */
    } 
Kompleksen soberi(Kompleksen a, Kompleksen b) /* пренос по вредност, се креираат локални копии во функцијата */
    {
        Kompleksen c = a;
        c.real += b.real;
        c.imag += b.imag;
        return c;
    }
Kompleksen odzemi(Kompleksen *p1, Kompleksen *p2) /* преносот по покажувач заштедува меморија */
    {
        Kompleksen c = *p1;
        c.real -= (*p2).real;
        c.imag -= (*p2).imag;
        return c;
    }
void mnozhi(Kompleksen a, Kompleksen b, Kompleksen *c) /* третиот аргумент се пренесува
по покажувач, за вредноста која ќе ја добие во оваа функција, да може да се искористи
онаму каде е повикана функцијата */
    {
        c->real = a.real * b.real - a.imag * b.imag;
        c->imag = a.real * b.imag + a.imag * b.real;
    } 