#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
    FILE *f;
    char buff[50];
    sprintf(buff,"Hello World");
    f = popen("wc -c","w");
    fwrite(buff,1,50,f);
    fclose(f);
}
