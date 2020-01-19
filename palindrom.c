#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int clean(char* msg, int lenmsg);
int chekc(char* msg, int lenmsg);

int main ()
{
    printf("Введеите предложение: ");
    char* msg = calloc(1024, sizeof(char));
    if (msg == NULL)
    {
        perror("Ошибочка вышла");
        return 1;
    }
    fgets(msg, 1023, stdin);
    int lenmsg = strlen(msg) - 1;
    lenmsg = clean(msg, lenmsg);
    if (chekc(msg, lenmsg) == 1)
    {
        puts("Это палиндром!");
    }
    else
    {
        puts("Это не палиндром!");
    }
    free (msg);
return 0;
}
int clean(char* msg, int lenmsg)
{
    char str[] = " .,!?-:";
    int lenstr = strlen(str);
    char ABC[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int lenABC = strlen(ABC);
    for (int i = 0; i < lenmsg; i++)
    {
        for (int j = 0; j < lenstr; j++)
        {
            if (msg[i] == str[j])
            {
                for (int k = i; k < (lenmsg-1); k++)
                {
                    msg[k] = msg[k+1];
                }
                lenmsg--;
                msg[lenmsg] = 0;
                i--;
            }
        }
        for (int j = 0; j < lenABC; j++)
        {
            if (msg[i] == ABC[j])
            {
                msg[i] += 32;
            }
        }
    }
return lenmsg;
}

int chekc(char* msg, int lenmsg)
{
    for (int i = 0; i < lenmsg; i++)
    {
        if (msg[i] != msg[lenmsg-i-1])
        {
            return 0;
        }
    }
return 1;
}
