/**
 * linked.c
 *
 * week 7 section
 * fall 2013
 *
 * practice using linked lists
 */

#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

// typedef a node for the linked list
typedef struct node
{
    int n;
    struct node* next;
}
node;

// function prototypes
bool insert_node(int value);
void print_nodes(node* list);
void free_nodes(node* list);

// global variable for the head of the list
node* head = NULL;

int main(void)
{
    // offer the user two options
    while (true)
    {
        printf("Please choose an option (0, 1, 2): ");
        int option = GetInt();

        switch (option)
        {
            // quit
            case 0:
                free_nodes(head);
                printf("Goodbye!\n");
                return 0;

            // insert int into linked list
            case 1:
                printf("Please enter an int: ");
                int v = GetInt();
                char* success = insert_node(v) ? "was" : "was not";
                printf("The insert %s successful.\n", success);
                break;

            // print all ints
            case 2:
                print_nodes(head);
                break;

            default:
                printf("Not a valid option.\n");
                break;
        }
    }
}

/**
 * Create a new node for a given value and insert it into a list.
 */
bool insert_node(int value)
{
    // create a new node
    node* new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        return false;
    }
    // init new node
    new_node->n = value;
    new_node->next = NULL;


    // for an empty list
    if(head == NULL){
        head = new_node;
        return true;
    }
    // create prev and current pointers
    node* prev = NULL;
    node* curr = head;

    // go through list
    while(curr != NULL){

        // else value == node
        if(value == curr->n)
        {
            // duplicate exist, free the node
            free(new_node);
            // return false
            return false;
        }
        // if value < node
        else if(value < curr->n)
        {
            break;
        }
        // else if value > node
        else if(value > curr->n)
        {
            // update pointers
            prev = curr;
            curr = curr->next;
            // go next node, will be next loop use
        }

    }
    // through the list, value is larger than anyone
    // so go to the end of list, and exit the while loop
    // put the node to the end of list

    // must be at end of list
    new_node->next = NULL;
    if(prev == NULL)
    {
        head = new_node;
    }
    else
    {
        prev->next = new_node;
    }
    // base return
    return true;
}
/**
 * Print out all of the ints in a list.
 */
void print_nodes(node* list)
{
    node* curr = list;

    while(curr != NULL){
        printf(" %d ", curr->n);
        curr = curr->next;
    }
}

/**
 * Frees all of the nodes in a list upon exiting the program.
 */
void free_nodes(node* list)
{
    // don't lose the rest of the list
    node* prev = NULL;
    node* curr = head;

    while (curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
}
