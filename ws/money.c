    #include <stdio.h>
    int main(int argc, char const *argv[])
    {

        int amt, total;
        printf("Input the amount: ");
        scanf("%d", &amt);
        //Note(s) of 100
        total = (int)amt / 100; 
        printf("There are: ");
        printf("\n%d Note(s) of 100.00\n", total);
        //Note(s) of 50
        amt = amt - (total * 100);
        total = amt / 50;
        printf("%d Note(s) of 50.00\n", total);
        amt = amt - (total * 50);
        total = amt / 20;
        printf("%d Note(s) of 20.00\n", total);
        //Note(s) of 10
        amt = amt - (total * 20);
        total = amt / 10;
        printf("%d Note(s) of 10.00\n", total);
        //Note(s) of 5
        amt = amt - (total * 10);
        total = amt / 5;
        printf("%d Note(s) of 5.00\n", total);
        //Note(s) of 2
        amt = amt - (total * 5);
        total = amt / 2;
        printf("%d Note(s) of 2.00\n", total);
        //Note(s) of 1
        amt = amt - (total * 2);
        total = amt;
        printf("%d Note(s) of 1.00\n", total);
        getch();
        return 0;
    }