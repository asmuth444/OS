#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
int main()
{
    FILE *f;
    char buff[50];
    f = popen("ls","r");
    fread(buff,1,50,f);
    printf("%s",buff);
    fclose(f);
}
