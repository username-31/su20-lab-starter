#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* your code here */
    node *hare = head, *turtle = head;
    while (hare != NULL)
    {
        hare = hare->next;
        if (hare == NULL) break;
        hare = hare->next;
        if (hare == NULL) break;
        turtle = turtle->next;                                                                                                     
        if (hare == turtle)
        {
            return 1;
        }
    }
    return 0;
}