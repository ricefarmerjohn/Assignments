#include <stdio.h>

int day_of_year(int month, int day, int year){

    for(int i = 1; i < month; i++){
        switch(i){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                day += 31;
                break;
            case 4: case 6: case 9: case 11:
                day += 30;
                break;
            case 2:
                if(year % 400 == 0 || (year % 4 == 0  && year % 100 != 0)){
                    day += 29;
                    break;
                } else {
                    day += 28;
                    break;
                }
        }
    }
    return day;
}


int main(void){
    int m,d,y;
    printf("Welcome to the program that will convert what the day is in the year \n Please input into the following order given (MM/DD/YYYY): ");
    scanf("%d %d %d", &m, &d, &y);

    int day;
    day = day_of_year(m,d,y);
    printf("%d", day);
    return 0;
}

