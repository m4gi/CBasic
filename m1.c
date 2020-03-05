#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define filename "hotellog.txt"
#define filewrite "summary.txt"

int isExist() {
    FILE *fp;
    fp = fopen(filename, "r+");
    if (fp != NULL) {
        fclose(fp);
        return 1;
    }
    else {
        fclose(fp);
        return 0;
    }
}

void checkin(FILE *fp, FILE *fp1, int num, char lastname[][20], int roomStatus[num], int occupants[num]) {
    int isAvailable = 0; //Để kiểm tra khách sạn còn phòng trống hay không, nếu giá trị là 0 tức là không còn phòng nào trống
    int i;
    for (i = 0; i < num; i++) //Kiểm tra lần lượt từ phòng 0 đến phòng num, bắt gặp phòng nào trống đầu tiên thì đưa khách vào checkin
        if (roomStatus[i] == 0) {
            fscanf(fp, "%s ", lastname[i]);
            fscanf(fp, "%d\n", &occupants[i]);
            roomStatus[i] = 1; //Chuyển phòng i từ trạng thái trống sang trạng thái đã được checkin
            fprintf(fp1, "%s %s %d\n", lastname[i], "was checked into room", i);
            isAvailable = 1;
            break;
        }
    if (isAvailable == 0)
        fprintf(fp1, "%s %s\n", "Sorry, no room was available for", lastname[i]);
}

void checkout(FILE *fp, FILE *fp1, int num, char lastname[][20], int roomStatus[num]) {
    int exist = 0; //Kiểm tra xem tên đó có checkin chưa, nếu có trả về 1, không có trả về 0
    char tmp[20];
    fscanf(fp, "%s\n", tmp);
    for (int i = 0; i < num; i++) //Duyệt từ phòng 0 đến phòng num để tìm tên của người cần checkout
        if (strcmp(tmp, lastname[i]) == 0) {
            fprintf(fp1, "%s %s %d\n", lastname[i], "was checked out of room", i);
            roomStatus[i] = 0; //Chuyển phòng i từ trạng thái đã được checkin về trạng thái trống
            strcpy(lastname[i], ""); //Xoá tên đó khỏi mảng lastname
            exist = 1;
            break;
        }
    if (exist == 0)
        fprintf(fp1, "%s %s\n", "Sorry, there is no occupant named", tmp);
}

void search(FILE *fp, FILE *fp1, int num, char lastname[][20], int roomStatus[num]) {
    int exist = 0; //Kiểm tra xem tên đó có checkin chưa, nếu có trả về 1, không có trả về 0
    char tmp[20];
    fscanf(fp, "%s\n", tmp);
    for (int i = 0; i < num; i++) //Duyệt từ phòng 0 đến phòng num để tìm tên của người cần search
        if (strcmp(tmp, lastname[i]) == 0) {
            fprintf(fp1, "%s %s %d\n", tmp, "is currently staying in room", i);
            exist = 1;
            break;
        }
    if (exist == 0)
        fprintf(fp1, "%s %s\n", "Sorry, there is no occupant named", tmp);
}

void printoccupancy(FILE *fp, FILE *fp1, int num, char lastname[][20], int roomStatus[num], int occupants[num]) {
    fprintf(fp1, "%-15s %-15s %-20s\n", "Name", "Room number", "Number of occupants");
    for (int i = 0; i < num; i++) //Duyệt từ phòng 0 đến phòng num, kiểm tra mảng roomStatus nếu giá trị của nó là 1(tức là phòng đã được checkin) thì in ra
        if (roomStatus[i])
            fprintf(fp1, "%-15s %-15d %-20d\n", lastname[i], i, occupants[i]);
}

int main()
{
    char c;
    FILE *fp, *fp1;
    fp = fopen(filename, "r+");
    fp1 = fopen(filewrite, "w+");
    if (isExist() == 0)
        printf("No file\n");
    else {
        int num;
        int count = 0;
        char s[20];
        fscanf(fp, "%d\n", &num);
        printf("There are %d lines in the file\n", num);
        char lastname[num][20]; //Mảng này chứa tên của từng khách hàng đã checkin, chỉ số của mảng tương ứng với số phòng
        int roomStatus[num]; //Mảng này gồm num phần tử tương đương với num phòng, giá trị của phần tử là 0 thì phòng còn trống, giá trị là 1 thì phòng đã được checkin
        int occupants[num]; //Mảng này chứa số người của từng phòng
        for (int i = 0; i < num; i++) //Giả sử ban đầu tất cả các phòng đều trống
            roomStatus[i] = 0;
        do {
            fscanf(fp, "%s ", s);
            if (strcmp(s, "CHECKIN") == 0)
                checkin(fp, fp1, num, lastname, roomStatus, occupants);
            if (strcmp(s, "CHECKOUT") == 0)
                checkout(fp, fp1, num, lastname, roomStatus);
            if (strcmp(s, "SEARCH") == 0)
                search(fp, fp1, num, lastname, roomStatus);
            if (strcmp(s, "PRINTOCCUPANCY") == 0)
            printoccupancy(fp, fp1, num, lastname, roomStatus, occupants);
            count++;
        } while (count < num);
    }
    fclose(fp);
    fclose(fp1);
    printf("Writing to %s successfully", filewrite);
    getch();
}