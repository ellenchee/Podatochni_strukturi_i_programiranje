/*Напишете функција за пресметување на растојание меѓу две точки зададени со нивните
координати. Потоа напишете програма што ќе пресмета периметар на даден триаголник. */
#include <stdio.h>
#include <math.h>
struct Koordinati {
    float x;
    float y;
};
float Rastojanie(struct Koordinati a, struct Koordinati b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
int main()
{
    struct Koordinati m[3]; //низа од три парови на координати
    int i;
    float perimetar, a, b, c;
    for (i = 0; i < 3; i++)
    {
        printf("Vnesi gi koordinatite na %d-ta tocka:\n", i + 1);
        fflush(stdout);
        printf("x = "); fflush(stdout);
        scanf("%f", &m[i].x);
        printf("y = "); fflush(stdout);
        scanf("%f", &m[i].y);
    }
    a = Rastojanie(m[0], m[1]);
    b = Rastojanie(m[0], m[2]);
    c = Rastojanie(m[1], m[2]);
    perimetar = a + b + c;
        printf("Perimetarot na triagolnikot e %f\n", perimetar);
    return 0;
} 