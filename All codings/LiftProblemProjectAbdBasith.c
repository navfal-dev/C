#include<stdio.h>
#include<windows.h>

// Global Declaration
static int currentFloor = 0;
static int firstLift=9, secondLift=7, thirdLift=5;


// Functions Created And Declared
void checkClosest();
void travelAgent(int floorNumber);
void driver();
void liftsChangePositions();



// Driver Program
void main(){

    int choice;

    printf("\n\nWhat would you like to do?\
            \nPress 1 to travel \nPress 2 to check the currentFloor\
            \nPress 3 to check the Lift Positions \nPress 4 to work in office\
            \nPress 5 to exit console\n\n");

    scanf("%d", &choice);

    if(choice==1){
            travel();
    }
    else if(choice==2){
            if(currentFloor==0)
                printf("\nYou are in the Ground floor");
            else
                printf("\nYou are in %d floor", currentFloor);
            main();
    }
    else if(choice==3){
            checkLiftPositions();
    }
    else if(choice==4){
            liftsChangePositions();
    }
    else if(choice==5){
            exit(0);
    }
    else{
        printf("\nInvalid Input");
        main();
    }
}

// Go To The Required Floor Program
void travel(){
    int floorNumber;
    printf("\nSelect the floor you wanna reach (1-9) : ");
    scanf("%d", &floorNumber);
    if(floorNumber > 9)
        printf("Invalid floor number..try again!");
    else
        travelAgent(floorNumber);
}


// When we leave a lift for a while, the lifts change positions
void liftsChangePositions(){
    if(firstLift!=9)
        thirdLift = firstLift+1;
    else
        thirdLift = firstLift-1;
    if(secondLift!=9)
        firstLift = secondLift+1;
    else
        firstLift = secondLift-1;
    if(thirdLift!=9)
        secondLift = thirdLift+1;
    else
        secondLift = thirdLift-1;
    main();
}



// Finds the closest lift
void checkLiftPositions(){
    printf("\nFirst lift is at %d floor", firstLift);
    printf("\nSecond lift is at %d floor", secondLift);
    printf("\nThird lift is at %d floor", thirdLift);
    main();
}



// Takes Care of the travel completely

void travelAgent(int floorNumber){

    // Checks which lift is closest to the currentFloor and it arrives to you

    int delayTime, i, liftUsed;
    int newDelayTime = floorNumber - currentFloor;

    int test1 = firstLift - currentFloor;
    if(test1<0) test1 *= -1;
    int test2 = secondLift - currentFloor;
    if(test2<0) test2 *= -1;
    int test3 = thirdLift - currentFloor;
    if(test3<0) test3 *= -1;

    if((test1<test2)&&(test1<test3)){
        printf("\n1st Lift is Arriving\n");
        printf("\n Please wait...\n");
        delayTime = firstLift - currentFloor;
        if(delayTime<0) delayTime *= -1;
        Sleep((1000*delayTime));

        liftUsed = 1;


        firstLift = currentFloor;

        printf("\n1st Lift has arrived to %d Floor", currentFloor);
    }

    else if((test2<test1)&&(test2<test3)){
        printf("\n2nd Lift is Arriving\n");
        printf("\n Please wait...\n");
        delayTime = secondLift - currentFloor;
        if(delayTime<0) delayTime *= -1;
        Sleep((1000*delayTime));

        liftUsed = 2;

        secondLift = currentFloor;
        printf("\n2nd Lift has arrived to %d Floor", currentFloor);
    }

    else if((test3<test1)&&(test3<test2)){
        printf("\n3rd Lift is Arriving\n");
        printf("\n Please wait...\n");
        delayTime = thirdLift - currentFloor;
        if(delayTime<0) delayTime *= -1;
        Sleep((1000*delayTime));

        liftUsed = 3;

        thirdLift = currentFloor;
        printf("\n3rd Lift has arrived to %d Floor", currentFloor);
    }
    else{
        printf("\n1st Lift is Close\n");
        printf("\n Please wait...\n");
        delayTime = firstLift - currentFloor;
        if(delayTime<0) delayTime *= -1;
        Sleep((1000*delayTime));

        liftUsed = 1;

        firstLift = currentFloor;
        printf("\n1st Lift has arrived to %d Floor", currentFloor);
    }


    if(liftUsed == 1){
        currentFloor = floorNumber;
        firstLift = floorNumber;
    }

    else if(liftUsed == 2){
        currentFloor = floorNumber;
        secondLift = floorNumber;
    }

    else if(liftUsed == 3){
        currentFloor = floorNumber;
        thirdLift = floorNumber;
    }
    else{
        printf("\nInvalid processing\n");
    }

    printf("\n");
    Sleep(3000);
    printf("\nGoing to floor number %d\n", floorNumber);

    // After arriving, the lift will go to the required floor

    if(newDelayTime<0) newDelayTime *= -1;

    Sleep((1000*newDelayTime));

    printf("\nYou have arrived to the %d floor\n", currentFloor);

    main();
}
