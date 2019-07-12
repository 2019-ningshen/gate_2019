#include<stdio.h>
#include<stdlib.h>


typedef struct node {
    int element;
    struct node *next;
} node;
node *head;


node *create() {
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    return ptr;
}
void insert_begin(int item) {
    node *ptr, *temp;
    ptr = create();
    if(ptr != NULL) {
        ptr->element = item;
       if(head == NULL) {
           head = ptr;
           head->next = head;
       } else {
           temp = head;
            while(temp->next != head) {
                temp = temp->next;
            }
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
       }
    }   
}

void insert_end(int item) {
    node *ptr, *temp;
    ptr = create();
    ptr->element = item;
    if(ptr == NULL) 
        printf("OVERFLOW\n");
    else {
        if(head == NULL) {
            head = ptr;
            ptr->next = head;
        } else {
            temp = head;
            while(temp->next != head) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head;
        }
    }
}

void delete_begin() {
    node *ptr, *temp;
    if(head == NULL) 
        printf("Nothing to delete\n");
    else {
        temp = head;
        ptr = head;
         // update the last->next to new head;
        while(temp->next != head) {
            temp = temp->next;
        }
        head = head->next;
        temp -> next = head;
        printf("[%d] deleted\n", ptr->element);
        free(ptr);
    }
}

void delete_last() {
    node *ptr, *temp;
    if(head == NULL) 
        printf("Nothing to delete.\n");
    else {
        ptr = head;
        temp = ptr;
        while(ptr -> next != head) {
            temp = ptr;
            ptr = ptr -> next;
        } 

        temp->next  = head;
        printf("[ %d ] deleted\n", ptr->element);
        free(ptr);
    }
}

void reverse() {
    node *current, *next, *prev, *temp;
    current = head;
    prev = head;
    if(head == NULL) 
        printf("Linked list is empty\n");
    else {
        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while(current != head) ;
        current->next = prev;
        head = prev;
    }
}
void splitFrontBack(node **front, node **back) {
      printf("leaving split back and front\n");
    node *fast, *slow;

    fast = head->next;
    slow = head;

    while(fast->next != head) {
        fast = fast -> next;
        if(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // TODO: convert both part into circular link list.
    /*
        slow->prev = head;
        last->next  = back'
     */
    *front = head;
    *back = slow->next;
    slow->next  = NULL;
    printf("leaving split back and front\n");
}


node *sortMerge(node *a, node *b) {
    node *result = NULL;
    // if(a == NULL && b == NULL) 
    //     return;
    if(a == NULL) 
        return b;
    else if(b == NULL) 
        return a;
    else {
        if(a->element < b->element) {
            result = a;
            result->next = sortMerge(a->next, b);

        } else {
            result = b;
            result->next = sortMerge(a, b->next);
        }
    }
    return result;
}

void mergeSort(node **headRef) {
    printf("Entering merge sort \n");
    node *head  = *headRef;
    node *a, *b;
    if(head == NULL) {
         printf("Linked List is empty\n");
        return;
    }
       

    splitFrontBack(&a, &b);
    mergeSort(&a);
    mergeSort(&b);
    printf("HIT HTI\n");
    *headRef = sortMerge(a, b);
}

void search(int item) {
    int flag, count = -1;
    node *ptr;


    ptr = head;

    if(head == NULL) {
         printf("Linked List is empty.\n");
        return;
    }
       
    if(head->element == item) {
        printf("item found at position %d\n", count+1);
        flag = 0;
    } else {
        while(ptr->next != head) {
            if(ptr->element == item) {
                printf("element found at %d\n", count+1);
                flag = 0;
                break;
            } else {
                flag = 1;
                ptr = ptr->next;
                count++;
            }
           if(ptr->element == item) {
               printf("Element found at %d\n", count+1);
               flag = 0;
               
           }
        }
    }
     if(flag != 0) 
            printf("Item not found.\n");
}

void display() {
    node *first, *ptr;
    ptr = head;
    
    if(head == NULL) {
        printf("Noting to print \n");
        return;
    }
     else  
    {  
        printf("printing values ... \n");  
        printf("[ ");
        while(ptr -> next != head)  
        {  
          
            printf("%d ", ptr -> element);  
            ptr = ptr -> next;  
        }  
        printf("%d", ptr -> element);  
        printf(" ]\n");
    }  
 
}
void main() {
    int item;
    int choice;
    while(1) {
        printf("Enter your choice\n");
        printf("1. Insert Element at the beginning.\n");
        printf("2. Insert element at the end.\n");
        printf("3. Display the linklist.\n");
        printf("4. Delete begining of the node.\n");
        printf("5. Delete last node.\n");
        printf("6. Reverse Linked List.\n");
        printf("7. merge sort\n");
        printf("8. Search for an element.\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter element you want to push.\n");
                scanf("%d", &item);
                insert_begin(item);
                break;
            case 2:
                printf("Enter element you want to push.\n");
                scanf("%d", &item);
                insert_end(item);
                break;

            case 3:
                display();
                break;
            case 4:
                delete_begin();
                break;
            case 5:
                delete_last();
                break;

            case 6:
                reverse();
                break;
            case 7:
                mergeSort(&head);
                break;
            case 8:
                printf("Enter element you want to search.\n");
                scanf("%d", &item);
                search(item);
                break;
            default:
                printf("Invalid Input \n");
        }
    }
}