#include <stdio.h>
#include <stdlib.h>

//learn about function
void printMenu();
int Square(int side);
int Triangle(int bottom, int height);
int Rectangle(int width, int breadth);

int main(){
    
    int choice;
    int num1, num2;
    int area;

    do{
        printMenu();

        printf("select a number: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the bottom: ");
                scanf("%d", &num1);
                printf("\nEnter the height: ");
                scanf("%d", &num2);
                
                area = Triangle(num1, num2);
                printf("The area of the triangle is %d", area);
            break;
            case 2:
                printf("\nEnter the side: ");
                scanf("%d", &num1);
                
                area = Square(num1);
                printf("The area of the square is %d", area);
                break;
            case 3:
                printf("\nEnter the width: ");
                scanf("%d", &num1);
                printf("\nEnter the breadth: ");
                scanf("%d", &num2);

                area = Rectangle(num1, num2);
                printf("The area of the rectangle is %d", area);
                break;
            case 4:
                break;
            default:
                printf("Please choose one of the options above");
                break;
        }
    }while(choice != 4);
    

    printf("thank you for using this calculator");
    return 0;
}

void printMenu(){
    printf("\n\tMenu\n");
    printf("1.Triangle\n");
    printf("2.Square\n");
    printf("3.Rectangle\n");
    printf("4. EXIT\n");
}

int Square(int side){
    int num = side * side;
    return num;
}

int Triangle(int bottom, int height){
    int num = bottom * height / 2;
    return num;
}

int Rectangle(int width, int breadth){
    int num = width * breadth;
    return num;
}