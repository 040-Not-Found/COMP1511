#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int get_middle(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = get_middle(head);
    printf("%d\n", result);

    return 0;
}


// Return middle element of a linked list
// if list contains [6,7,8,9,10]  8 is returned
// if a list has even number of elements, first of middle two elements returned
// if list contains [1,2,3,4] 2 is returned
// list can not be empty
int get_middle(struct node *head) {
    struct node *cur_loc = head;
    int num_elements = 0;
    while (cur_loc != NULL) {
        cur_loc = cur_loc->next;
        num_elements++;
    }
    int i = 0;
    cur_loc = head;
    if (num_elements%2 == 1) {
        while (i != num_elements/2) {
            cur_loc = cur_loc->next;
            i++;
        }
    } else {
        while (i != num_elements/2 - 1) {
            cur_loc = cur_loc->next;
            i++;
        }
    }
    return cur_loc->data;

}


// DO NOT CHANGE THIS FUNCTION

// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}
