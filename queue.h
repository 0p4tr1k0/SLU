#ifndef QUEUE_H
#define QUEUE_H

/* Uzel obsahuje hodnotu prvočísla p (menší z dvojčete) */
typedef struct Node {
    long long value;
    struct Node *next;
} Node;

/* Struktura FIFO fronty */
typedef struct {
    Node *head;
    Node *tail;
    int size;
} Queue;

/* Rozhraní pro práci s frontou */
void queue_init(Queue *q);
int queue_enqueue(Queue *q, long long val);
int queue_dequeue(Queue *q, long long *val);
int queue_is_empty(const Queue *q);
void queue_free(Queue *q);

// Funkce projde frontu od head po tail a na každý prvek zavolá funkci 'action'
void queue_traverse(const Queue *q, void (*action)(long long));

#endif // QUEUE_H