

/*
    This short program will explain you what are directive and macro-expansion.
    There are more directives than you would think. This will get you started.
*/




#include<stdio.h>
#include <sys/utsname.h>
#include <stdlib.h>

#define UPPER 10
#define PI 3.14
#define OR ||
#define AND &&
#define RANGE ((area > 0)  AND (area <= 90))    
#define RANGE2 ((input >=0) AND (input <= 100))
#define AREA(x) (PI * x * x)
#define FOUND(input) printf("The number you entered %d\n",input) 
#define OS "win32"


#ifndef  __external_file_h
    #define __external_file_h
#endif

void main() {
    struct utsname name;
	if(uname(&name)) exit(-1);
    
    #ifdef OS
        printf("Your computer's OS is %s@%s\n", name.sysname, name.release);
    #else   
        printf("Operating System....... ");
    #endif



    register int i;
    int radius = 4;
    float area;
    for(i=1;i<UPPER; i=i*2) {
        printf("i = %d\n", i);
    }
    area = AREA(radius);
    if((area > 0) AND (area < 55)){
        printf("Printing area....\n");
        printf("AREA = %f\n", area);
    }
    if(RANGE) 
        printf("Printing again......\n");
    
    int input;
    printf("ENTER SOMETHING between 0 and 100...\n");
    scanf("%d", &input);

    if(RANGE2) 
        FOUND(input);
    else 
        printf("RANGE EXCEEDED...\n");

}