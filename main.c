#include <stdio.h>
#include <stdlib.h>
#include "queue.h"



#define OUTPUT_FILE "output.txt"

/*
 * Test prvocisla metodou trial division.
 * Opraveno: Nepouziva <math.h> ani double, cimz predchazi ztrate presnosti.
 */
int is_prime(long long n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

/*
 * Nalezeni m nejmensich prvociselnych dvojcat > n.
 */
void find_twin_primes(long long start, int m, Queue *q) {
    long long candidate = (start % 2 == 0) ? start + 1 : start + 2;
    int found = 0;

    while (found < m) {
        if (is_prime(candidate) && is_prime(candidate + 2)) {
            queue_enqueue(q, candidate);
            found++;
        }
        candidate += 2;
    }
}

/*
 * Nacteni parametru z prikazove radky.
 */
int read_input(int argc, char *argv[], int *m, long long *n) {
    if (argc != 3) {
        fprintf(stderr, "Pouziti: %s <m> <n>\n", argv[0]);
        return 0;
    }
    *m = atoi(argv[1]);
    *n = atoll(argv[2]);

    if (*m < 3 || *n <= 1000) {
        fprintf(stderr, "Chyba: m musi byt >= 3 a n > 1000\n");
        return 0;
    }
    return 1;
}

/*
 * Zapis do souboru pres rozhrani ADT (odebiranim prvku).
 */
void write_output(Queue *q, const char *filename) {
    FILE *out = fopen(filename, "w");
    if (out == NULL) {
        fprintf(stderr, "Chyba: nelze otevrit soubor '%s'\n", filename);
        return;
    }
    
    long long val;
    // Postupne odebira prvky z fronty a zapisuje je
    while (queue_dequeue(q, &val)) {
        fprintf(out, "%lld\n", val);
        //printf("  (%lld, %lld)\n", val, val + 2); // Rovnou vypisujeme i na konzoli
    }
    
    fclose(out);
    printf("Vysledky zapsany do souboru: %s\n", filename);
}

// Funkce, kterou podstrčíme traversu
void print_to_console(long long value) {
    printf("  (%lld, %lld)\n", value, value + 2);
}

int main(int argc, char *argv[]) {
    int m;
    long long n;

    if (!read_input(argc, argv, &m, &n)) {
        return EXIT_FAILURE;
    }

    printf("Hledam %d prvociselnych dvojcat > %lld...\n", m, n);

    Queue q;
    queue_init(&q);

    find_twin_primes(n, m, &q);

    printf("\nNalezena prvociselna dvojcata:\n");
    
    queue_traverse(&q, print_to_console);
    // write_output zaroven vyprazdni frontu
    write_output(&q, OUTPUT_FILE);

    // Pro jistotu zavolame queue_free, i kdyz by fronta mela byt nyni prazdna
    queue_free(&q);

    return 0;
}