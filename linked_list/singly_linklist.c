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

void insert_begin() {
    node *ptr, *temp;
    int item;
    ptr = create();
    if(ptr == NULL) {
        printf("OVERFLOW. INSUFFICIENT MEMORY\n");
    } else {
        printf("Enter you element.\n");
        scanf("%d", &ptr->element);
        ptr->next = head;
        head = ptr;
    }
}

void insert_end() {
    node *temp, *ptr;
    int item;

    ptr = create();
    if(ptr == NULL) 
        printf("OVERFLOW. INSUFFICIENT MEMORY\n");
    else {
        printf("Enter your element\n");
        scanf("%d", &ptr->element);
        ptr->next = NULL;

        if(head == NULL) {
            head = ptr;
            printf("Element Inserted\n");
        } else {
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            printf("Element Inserted\n");
        }
    }
}

void delete_begin() {
    node *ptr, *temp;
    ptr = head;
    if(ptr == NULL) 
        printf("Linked List empty\n");
    else {
        head = ptr->next;
        printf("[ %d ] deleted", ptr->element);
        free(ptr);
    }
}

void delete_end() {
    node *ptr, *temp;
    ptr = head;
    if(head == NULL) 
        printf("Linked List Empty\n");
    else {
        temp = ptr;
        while(ptr->next != NULL) {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        printf("[%d] deleted.", ptr->element);
        free(ptr);
    }
}

void reverse() {
    printf("Reversing......!\n");
    node *current, *next, *prev;
    current  = head;
    next = NULL;
    prev = NULL;

    if(head == NULL || head->next->next == NULL) 
        printf("Can't reverse an empty or single node linked list\n");
    else {
        while(current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    printf("Reverse Completed\n");

}

void recursive_reverse(node **head) {
    node *first, *rest;
    if(*head == NULL) 
        return;
    first = *head;
    rest = first->next;

    if(rest == NULL)
        return;
    recursive_reverse(&rest);
    first->next->next = first;
    first->next = NULL;
    *head = rest;
}
void frontBackSplit(node *head, node **front, node **back) {
    node *fast, *slow;
    fast = head->next;
    slow = head;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = head;
    *back = slow->next;
    slow->next = NULL;
}
node *sortMerge(node *a, node *b) {
    node *result = NULL;

    if(a == NULL) 
        return b;
    else if (b == NULL) 
        return a;

    if(a->element <= b->element) {
        result = a;
        result->next = sortMerge(a->next, b);
    } else {
        result = b;
        result->next = sortMerge(a, b->next);
    }
    return result;
}
void mergeSort(node **headRef) {
    node *a, *b;
    node *head = *headRef;
    if(head == NULL || head->next == NULL) 
        return;
    frontBackSplit(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortMerge(a, b);
}

int linear_search(int item) {
    node *ptr;
    int count = -1;
    if(head->element == item) {
        printf("Item Found: %d\n", head->element);
       // return head;
    } else {
        ptr = head;
        while(ptr != NULL) {
            printf("%d ==  item\n", item);
            if(ptr->element == item) {
                 printf("Item Found: %d at address = %u\n", ptr->element, ptr);
                 return ++count; 
            } else {
                ++count;
                printf("%d == count\n", count);
                ptr = ptr->next;
            }
        }
    }
}


//
node *middle(node *start, node *end) {
    node *fast, *slow;
    fast  = head->next;
    slow = head;
    start = head;
    end = NULL;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}
int binary_search(int item) {
    node *start, *end, *mid;
    mergeSort(&head);
    start = head;
    end = NULL;

    do {
        mid = middle(start, end);
        if(mid == NULL) 
            return NULL;
        if(mid->element == item) 
            return mid;
        else if(mid->element > item) 
            end = mid;
        else 
            start = mid;

    } while(end != NULL || end != start);
    return NULL;
}
void delete_random() {
    int item;
    node *ptr, *temp;
    int count;
    char choice;
    ptr = head;
        
    printf("Enter you want to delete\n");
    scanf("%d", &item);
   
    if(item) {
        printf("a. Search using binary\n");
        printf("b. Search using linear search\n");
        scanf(" %c", &choice);
    }
    
    switch(choice) {
        case 'a':
            count = linear_search(item);
            printf("%d add to be deleted \n", count);
            break;
            /*TODO */
        case 'b':
            binary_search(item);
            break;
        default:
            printf("Invalid Input\n");
    }
    if(count == 0) {
        printf("Deleting \n");
        head = ptr->next;
        free(ptr);
        printf("Element Deleted: %d\n", ptr->element);
        return;
    } 

    for(int i=0;i<count - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }

    if(ptr == NULL && ptr->next == NULL)
        return;
    
    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    printf("Element [ %d ] deleted\n", item);
    printf("*****************************************");
}
void display() {
    node *ptr;
    ptr = head;
    if(ptr == NULL) 
        printf("Linked List is empty\n");
    else {
        printf("PRINTING VALUES\n");
        printf("[ ");
        while(ptr != NULL) {
            printf(" %d", ptr->element);
            ptr = ptr->next;
        }
        printf(" ]\n");
    }
}

void main() {
    int item;
    int choice;
    while(choice != 0) {
        printf("**************MAIN MENU******************\n");
        printf("Enter your option\n");
        printf("1. Insert at the biginning of the linked list.\n");
        printf("2. Display\n");
        printf("3. Insert end\n");
        printf("4. Delete Begin\n");
        printf("5. Delete last\n");
        printf("6. Reverse a linked List\n");
        printf("7. Recursive Reverse\n");
        printf("8. Merge Sort\n");
        printf("9. Linear Search\n");
        printf("10. Delet from random position.\n");
        printf("11. Binary Search\n");
        scanf("%d", &choice);
        switch(choice) {
            
            case 1:
                insert_begin();
                break;

            case 2:
                display();
                break;
            case 3:
                insert_end();
                break;

            case 4:
                delete_begin();
                break;
            case 5:
                delete_end();
                break;

            case 6:
                reverse();
                break;

            case 7: 
                recursive_reverse(&head);
                break;
            case 8:
                mergeSort(&head);
                break;
            case 9:
                printf("Enter data you want to Search\n");
                scanf("%d", &item);
                linear_search(item);
                break;
            case 10:
                delete_random();
                break;

            case 11:
                printf("Enter data you want to Search\n");
                scanf("%d", &item);
                binary_search(item);
                break;
            default:
                printf("Invalid Input\n");
        }
    }
}