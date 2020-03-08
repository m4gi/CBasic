#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dirent.h>
void ReadFile()
{
    FILE *f;
    char filename[15];
    char ch;
    fflush(stdin);
    printf("Enter the filename to be opened: \n");
    scanf("%s", filename);
    f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Can't open file !!!\n");
        return;
    }
    ch = fgetc(f);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(f);
    }
    fclose(f);
}
void Copyfile()
{
    char ch, source_file[20], target_file[20];
    FILE *source, *target;
    fflush(stdin);
    printf("Enter name of file to copy\n");
    gets(source_file);

    source = fopen(source_file, "r");

    if (source == NULL)
    {
        printf("Can't open file!!!\n");
        return;
    }
    printf("Enter name of target file\n");
    gets(target_file);

    target = fopen(target_file, "w");

    if (target == NULL)
    {
        fclose(source);
        printf("Press any key to exit...\n");
        return;
    }

    while ((ch = fgetc(source)) != EOF)
        fputc(ch, target);

    printf("File copied successfully!!\n");

    fclose(source);
    fclose(target);
}
void MergeFile()
{
    FILE *f1, *f2, *ft;
    char ch, file1[20], file2[20], file3[20];
    printf("Enter name of first file: ");
    fflush(stdin);
    gets(file1);
    printf("Enter name of second file: ");
    fflush(stdin);
    gets(file2);
    printf("Enter name of file which will store contents of two files: ");
    fflush(stdin);
    gets(file3);
    f1 = fopen(file1, "r");
    f2 = fopen(file2, "r");
    if (f1 == NULL || f2 == NULL)
    {
        perror("Can't open file!!!");
        return;
    }
    ft = fopen(file3, "w");
    if (ft == NULL)
    {
        perror("Can't open file!!! ");
        return;
    }
    while ((ch = fgetc(f1)) != EOF)
        fputc(ch, ft);
    while ((ch = fgetc(f2)) != EOF)
        fputc(ch, ft);
    printf("Two files were merged into %s file successfully!!!\n", file3);
    fclose(f1);
    fclose(f2);
    fclose(ft);
}
void ListFile()
{
    struct dirent *de;
    DIR *dr = opendir(".");
    if (dr == NULL)
    {
        printf("Could not open current directory");
        return;
    }
    while ((de = readdir(dr)) != NULL)
        printf("%s\n", de->d_name);

    closedir(dr);
}
void DeleteFile()
{
    char filename[20];
    printf("Enter the name of file you wish to delete: ");
    fflush(stdin);
    gets(filename);
    if (remove(filename) == 0)
        printf("%s file deleted successfully", filename);
    else
        printf("Unable to delete the file");
}
int uChoice()
{
    int choice;
    printf("\n 1) Read file.");
    printf("\n 2) Copy files");
    printf("\n 3) Merge two files.");
    printf("\n 4) Lists file in directory.");
    printf("\n 5) Delete file.");
    printf("\n Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}
int main(int argc, char const *argv[])
{
    int choice;
    do
    {
        choice = uChoice();
        switch (choice)
        {
        case 1:
            ReadFile();
            break;
        case 2:
            Copyfile();
            break;
        case 3:
            MergeFile();
            break;
        case 4:
            ListFile();
            break;
        case 5:
            DeleteFile();
            break;
        default:
            printf("Press any key to exit!!!\n");
        }
    } while (choice >= 1 && choice <= 5);
    getch();
    return 0;
}
