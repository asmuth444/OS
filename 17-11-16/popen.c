#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
int main()
{
    FILE *f;
    char buff[50];
    sprintf(buff,"Hello World");
    f = popen("wc -c","w");
    fwrite(buff,1,strlen(buff),f);
    fclose(f);
}
