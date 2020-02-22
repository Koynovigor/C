#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>


int main ()
{  
    char adr[] = "/home/users/s94-8/lab";
    DIR* direct = opendir(adr);
    struct dirent* entey;
    if (direct == NULL)
    {
        perror("Каталог не открыт!");
        return 1;
    }
    while (entey == readdir(direct))
    {
        snprintf
    }
    int status = closedir (direct);
    if (status == -1)
    {
        perror("Каталог не закрыт!");
        return 1;
    }
return 0;
}
