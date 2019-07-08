

/*
    Find Minimum and Maximun element from array using TOURNAMENT METHOD (DIVIDE & CONQUER).
*/



#include <stdio.h>

int max, min;
void findMinMax(int [], int s, int left, int right);
void main() {
    int a[] = { 3,2,1,5,4,7,6};
    int *largest_el, *smallest_el;
    int size = sizeof(a)/sizeof(a[0]); // # of elements  = 7
    int left = 0; // 0
    int  right = size - 1; // 7 - 1 = 6  (left and right are the beginning and end of the array index.)
    findMinMax(a, size, left, right);
    printf("Max: %d\nMin: %d\n", max, min);
}

void findMinMax(int a[], int s, int left, int right) {
  int max_1, min_1, mid;
  if(left == right) min = max = a[left]; // if array has only 1 element.
  else if (left+1 == right) { // if array has only two elements
      if(a[left] > a[right]) {
          min = a[right];
          max = a[left];
      } else {
          min = a[left];
          max = a[right];
      }
  }
  else { // if array has more than 2 elements
      mid = (left + right)/2; 
      findMinMax(a, s, left, mid);
      max_1 = max;
      min_1 = min;
      findMinMax(a, s, mid+1, right);
      max = max > max_1 ? max : max_1;
      min = min < min_1 ? min : min_1;
  }
}

/*
    Time Complexity:
        Array with one element = Theta(0).
        Array with two element = Theta(1).
        Array with more than element then,
        use BINARY SEARCH  RECURSIVELY to search min & max on both sides.  

        so, Complexity  = Theta(n)
        No. of comparisons = (3n/2) - 2  ( n = even )
        and (3n/2) (n = odd)

*/