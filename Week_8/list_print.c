#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};
void print(struct node *head) {
 struct node *n;
 n=head;
 while(n!=NULL)
 {
  printf("%d -> ",n->data);
  n=n->next;
 }
 printf("X\n");

    // PUT YOUR CODE HERE
}


// DO NOT CHANGE THIS FUNCTION

// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    int i;
    for (i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    print(head);

    return 0;
}


// print a linked list in this format:
// 17 -> 34 -> 51 -> 68 -> X