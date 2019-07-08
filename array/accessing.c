#include<stdio.h>



// void array_passing(int *j, int n) {
//    for(int i=0;i<n;i++) {
//         printf("Second print address  = %u  :: %d \n", j, *j);
//         j++;
//     }

// }
void main() {
    int num[] = {24,34,12,44,56, 17};
    int s = sizeof(num)/sizeof(num[0]);
   
    int i, *j;
    j= &num[0];


    
    for(i=0;i<s;i++) {
        printf("address  = %u  :: %d or %d ", &num[i], num[i], *(num + i));
        printf("Also %d and %d\n", *(i + num), i[num]);
        j++;
    }

    // array_passing(j = &num[0], s);

}