#include <stdio.h>

int main(void) {
    
    int T,k=0,n;
    scanf("%d",&T);
    while(k<T){
        scanf("%d",&n);
        int a[n],c=0;
        for(int i=0;i<n;i++){
            printf("Hit %d\n", i);
            scanf("%d",&a[i]);
        }
        // printf("\n");
        // for(int i=0;i<n;i++){
        //     printf("Hit %d", a[i]);
           
        // }
        int i=0;
        while(i<n){
            int j=i+1;
            while(j<n){
                
                if((a[i]&1)==0 && (a [j]&1)==1 && i<j){
                  
                    printf("Entered i = %d and j = %d\n", a[i], a[j]);
                    c=c+1;
                }
                j=j+1;
            
            }//else
            i=i+1;
        }
        
        printf("%d\n",c);
        k=k+1;
    }    
	// your code goes here
	return 0;
}