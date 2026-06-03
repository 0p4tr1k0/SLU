#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void queue_init(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

int queue_enqueue(Queue *q, long long val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Chyba: nelze alokovat pamet.\n");
        return 0;
    }
    newNode->value = val;
    newNode->next = NULL;

    if (q->tail == NULL) {
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->size++;
    return 1;
}

int queue_dequeue(Queue *q, long long *val) {
    if (q->head == NULL) {
        return 0;
    }
    Node *tmp = q->head;
    *val = tmp->value;
    q->head = tmp->next;
    
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(tmp);
    q->size--;
    return 1;
}

int queue_is_empty(const Queue *q) {
    return q->head == NULL;
}

void queue_free(Queue *q) {
    long long dummy;
    while (!queue_is_empty(q)) {
        queue_dequeue(q, &dummy);
    }
}

void queue_traverse(const Queue *q, void (*action)(long long)) {
    Node *cur = q->head;
    while (cur != NULL) {
        action(cur->value); // Zavoláme uživatelskou funkci na hodnotu uzlu
        cur = cur->next;
    }
}