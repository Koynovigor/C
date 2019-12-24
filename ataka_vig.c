#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *res_str(int n);
void print_str(char *str, int n);

int main()
{
    int len_str = 100;
    char *str = res_str(len_str);

    printf("Введите зашифрованную строку: ");
    fgets(str, len_str, stdin);
    len_str = strlen(str) - 1;

    char *str_end = res_str(len_str);

    char *key = res_str(9);

    while ()
return 0;
}

char *res_str(int n)
{
    char *str = calloc(n, sizeof(char));
    if (str == NULL)
    {
        perror("Ошибка");
        return NULL;
    }
return str;
}

void print_str(char *str, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", str[i]);
    }
    puts("");
}
