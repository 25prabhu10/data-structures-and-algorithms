#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void create_list(int A[], int n)
{
    int i;
    struct Node *temp, *last;

    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;

    last = head;

    for (i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void print_list(struct Node *n)
{
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }

    printf("\n");
}

void print_list_recursive(struct Node *n)
{
    if (n != NULL)
    {
        printf("%d\n", n->data);
        print_list_recursive(n->next);
    }

    printf("\n");
}

int print_list_count(struct Node *n)
{
    int count = 0;

    while (n != NULL)
    {
        count++;
        n = n->next;
    }

    return count;
}

int print_list_count_recursive(struct Node *n)
{
    if (n == NULL)
        return 0;

    return print_list_count_recursive(n->next) + 1;
}

int search_element(struct Node *n, int x)
{
    int index = 1;

    while (n != NULL)
    {
        return 1;
        if (n->data == x)
            return index;

        index++;
        n = n->next;
    }

    return -1;
}

struct Node *search_element_move_to_front(struct Node *n, int x)
{
    struct Node *p = NULL;

    while (n != NULL)
    {
        if (n->data == x)
        {
            p->next = n->next;
            n->next = head;
            head = n;
            return n;
        }

        p = n;
        n = n->next;
    }

    return NULL;
}

void insert_at_start(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = x;
    temp->next = head;
    head = temp;
}

void insert_at_nth_index(int x, int index)
{
    // Errors not handled
    int i;
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));

    temp1->data = x;
    temp1->next = NULL;

    if (index == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    struct Node *temp2 = head;

    for (i = 0; i < index - 2; i++)
        temp2 = temp2->next;

    temp1->next = temp2->next;
    temp2->next = temp1;
}

void insert(struct Node *n, int x, int index)
{

    struct Node *new;
    int i = 0;

    // comment after || if index larger than the Linked list count should inserted at last index
    if (index < 0 || index > print_list_count(n))
        return;

    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = x;

    if (index == 0)
    {
        new->next = head;
        head = new;
    }
    else
    {
        for (i = 0; i < index - 1; i++) // && n->next != NULL
            n = n->next;

        new->next = n->next;
        n->next = new;

        // while (n != NULL && i != index)
        // {
        //     p = n;
        //     n = n->next;
        //     i++;
        // }

        // if (n == NULL)
        // {
        //     new->data = x;
        //     new->next = NULL;
        //     p->next = new;
        // }
        // else
        // {
        //     new->data = x;
        //     new->next = p->next;
        //     p->next = new;
        // }
    }
}

void insert_element_sorted(struct Node *n, int x)
{
    struct Node *temp;
    struct Node *p = NULL;

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (head == NULL)
        head = temp;
    else
    {
        while (n != NULL && n->data < x)
        {
            p = n;
            n = n->next;
        }

        if (n == head)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            temp->next = p->next;
            p->next = temp;
        }
    }
}

int delete_at_index(struct Node *n, int index)
{
    struct Node *p = NULL;
    int x = -1, i;

    if (index < 1 || index > print_list_count(n))
        return x;

    if (index == 1)
    {
        p = head;
        x = head->data;
        head = head->next;
        free(p);
        return x;
    }

    for (i = 0; i < index - 1; i++)
    {
        p = n;
        n = n->next;
    }

    p->next = n->next;
    x = n->data;
    free(n);
    return x;
}

int is_linked_list_sorted(struct Node *n)
{
    int x = -32768;

    while (n != NULL)
    {
        if (x > n->data)
            return 0;

        x = n->data;
        n = n->next;
    }

    return 1;
}

void remove_duplicates(struct Node *n)
{
    struct Node *q;

    q = n->next;

    while (q != NULL)
    {
        if (n->data != q->data)
        {
            n = q;
            q = n->next;
        }
        else
        {
            n->next = q->next;
            free(q);
            q = n->next;
        }
    }
}

void reversing_links_linked_list(struct Node *n)
{
    struct Node *p = n;
    struct Node *q = NULL;
    struct Node *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    head = q;
}

void reversing_links_linked_list_recursion(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        reversing_links_linked_list_recursion(p, p->next);
        p->next = q;
    }

    head = q;
}

int is_loop(struct Node *n)
{
    struct Node *p, *q;
    p = q = n;

    do
    {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : q;
    } while (p != NULL && q != NULL && p != q);

    if (p == q)
        return 1;

    return 0;
}

int main()
{
    // int A[] = {5, 6, 9, 1, 3, 2, 1};
    int A[] = {10, 11, 15, 15, 20, 20, 20, 25};

    // struct Node *second = NULL;
    // struct Node *third = NULL;

    // head = (struct Node *)malloc(sizeof(struct Node));
    // second = (struct Node *)malloc(sizeof(struct Node));
    // third = (struct Node *)malloc(sizeof(struct Node));

    // head->data = 10;
    // head->next = second;

    // second->data = 25;
    // second->next = third;

    // third->data = 100;
    // third->next = NULL;

    create_list(A, 8);

    print_list(head);
    // print_list_recursive(head);

    printf("\nCount: %d\n", print_list_count(head));
    // printf("CountR: %d\n", print_list_count_recursive(head));

    // printf("Found 1 at: %d\n", search_element(head, 1));

    // struct Node *temp = NULL;

    // temp = search_element_move_to_front(head, 1);
    // printf("\nFound: %d\n\n", temp->data);

    // print_list(head);

    // insert_element_sorted(head, 12);

    print_list(head);

    // printf("--> %d\n", delete_at_index(head, 3));
    // remove_duplicates(head);
    reversing_links_linked_list_recursion(NULL, head);

    print_list(head);

    // printf("\nSorted --> %d\n", is_linked_list_sorted(head));

    // int **pp = (int **)malloc(sizeof(int *));
    // int *qq = (int *)malloc(sizeof(int));

    // *qq = 44;
    // *pp = qq;

    // printf("\n\n%d\n", **pp);

    return 0;
}