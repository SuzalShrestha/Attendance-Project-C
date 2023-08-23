#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stuName[20][30];
int presentAttendance[20] = {0};
int absentAttendance[20] = {0};
int indexNumber = 0;

void checkAttendance()
{
    int i;
    printf("\n+----------------------+----------------------+----------------------+\n");
    printf("|         Name         |    Total Present     |     Total Absent     |\n");
    printf("+----------------------+----------------------+----------------------+\n");
    for (i = 0; i < indexNumber; i++)
    {
        printf("| %-20s     | %-20d  | %-20d  |\n", stuName[i], presentAttendance[i], absentAttendance[i]);
    }
    printf("+----------------------+----------------------+----------------------+\n");
}
void addStudent()
{
    int i, num, add;
    if (indexNumber == 0)
    {
        printf("Enter how many students you want to add: ");
        scanf("%d", &num);
        getchar(); // Clear the newline character from the previous input
        for (i = 0; i < num; i++)
        {
            printf("\nEnter %d student name to add in attendance register: ", i + 1);
            fgets(stuName[i], sizeof(stuName[i]), stdin);
            indexNumber++;
        }
    }
    else
    {
        printf("Enter how many students you want to add: ");
        scanf("%d", &num);
        getchar(); // Clear the newline character from the previous input
        add = indexNumber + num;
        for (i = indexNumber; i < add; i++)
        {
            printf("\nEnter %d student name to add in attendance register: ", i + 1);
            fgets(stuName[i], sizeof(stuName[i]), stdin);
            indexNumber++;
        }
    }
}

void takeAttendance()
{
    int i;
    char ch;
    printf("\nEnter Y for present and N for absent\n");
    for (i = 0; i < indexNumber; i++)
    {
    repeat:
        printf("%d. %s is present: ", i + 1, stuName[i]);
        scanf(" %c", &ch); // Leave a space before %c to consume the newline character
        getchar();         // Clear the newline character from the previous input
        if (ch == 'Y' || ch == 'y')
        {
            presentAttendance[i] += 1;
        }
        else if (ch == 'N' || ch == 'n')
        {
            absentAttendance[i] += 1;
        }
        else
        {
            printf("Invalid character. Try again\n");
            goto repeat;
        }
    }
}

int main()
{
    int choose;
    do
    {
        printf("\n**********Main Menu***********\n");
        printf("Enter 1 for add student\n");
        printf("Enter 2 for take attendance\n");
        printf("Enter 3 for check attendance\n");
        printf("Enter 4 for exit\n");
        printf("Please choose any menu: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            addStudent();
            break;
        case 2:
            takeAttendance();
            break;
        case 3:
            checkAttendance();
            break;
        case 4:
             exit(0);
            break;           
        }
    } while (choose != 4);

    return 0;
}
