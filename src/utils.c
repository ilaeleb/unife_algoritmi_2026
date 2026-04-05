#include "utils.h"

void push_end(node_t *head, long double val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->count = 1;
    current->next->next = NULL;
}

void push_head(node_t *head, long double val) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->count = 1;
    new_node->next = head;
    head = new_node;
}

void ordered_insert(node_t *head, long double val) {
    node_t * current = head;

    // più grande del primo valore della lista
    if (current->val > val) {
        push_head(head, val);
        return;
    }

    while (current != NULL) {
    
        if (current->val == val) {
            current->count += 1;
            break; 
        }

        if (current->next != NULL) {
            if (current->next->val > val) {
                node_t * new_node;
                new_node = (node_t *) malloc(sizeof(node_t));  
                
                new_node->val = val;
                new_node->count = 1;
                new_node->next = current->next;

                current->next = new_node; 
                break;               
            }
        } else {
            push_end(head, val);
            break;            
        }
        current = current->next;
    }
}

void print_list(node_t *head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%Lf\n", current->val);
        current = current->next;
    }
}