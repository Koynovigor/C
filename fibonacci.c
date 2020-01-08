#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long int fifth_leg(long long int n);
double even(long long int q);
long long int odd(long long int q);

int main()
{
    long long int b, a = 1; double s; printf("Какое число тебе нужно? (максимум, что я могу посчитать - это 92) ");
    if(scanf("%lld", &b) != 1) {l: puts("Кажется, ты ошибся)) )"); return b;}
    a = fifth_leg(b);
    if (a == 2) return a;
    if (a); else {a++; goto p;}
    if (b&1<<0) {s = even(b); a = s; goto p;}
    if (b&1<<0); else a = odd(b-1); 
    p: if (a == -9223372036854775808) goto l;
    printf("Вот, держи: %lld\n", a);
}

long long int fifth_leg(long long int n)
{
    long long int a = 0;
    for (int i = 0; i < 64; i++) if (n&1<<i) a++;
    if (a); else {j: puts("Кажется, ты ошибся)) )"); return 2;}
    if (n&1<<63); else if ((a == 1)&(n&1<<1)) return 0;
    if (n&1<<63); else if ((a == 1)&(n&1<<0)) return 0;
    if (a) if (n&1<<63) goto j;
return 1;
}

double even(long long int q)
{
    double w = pow(5.0, (1.0/2.0)),a = 1, b = 1, s;
    for (int i = 0; i < q; i++) a = a * ((1 + w)/2); 
    for (int i = 0; i < q; i++) b = b * ((1 - w)/2); 
    s = 1/w*(a - b); 
return s;
}

long long int odd(long long int q)
{
    double *n = calloc(2, sizeof (double*));
    n[1] = even(q); n[2] = even (q/q*2+q); q = n[2] - n[1]; 
    free(n);
return q;
}
