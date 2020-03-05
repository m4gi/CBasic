#include <conio.h>
#include <stdio.h> 
#include <dirent.h> 

void ListFile()
{
    struct dirent *de; 
    DIR *dr = opendir("."); 
    if (dr == NULL)
    { 
        printf("Could not open current directory" ); 
        return; 
    }  
    while ((de = readdir(dr)) != NULL) 
            printf("%s\n", de->d_name); 
  
    closedir(dr);
}
int main(int argc, char const *argv[])
{
    ListFile();
    getch();
    return 0;
}
