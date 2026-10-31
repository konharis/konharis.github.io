/*
Άσκηση 3 

Το πρόγραμμα διαβάζει έναν αριθμό και μία επιλογή:
p: ελέγχει αν ο αριθμός είναι πρώτος.
g: βρίσκει δύο πρώτους που έχουν άθροισμα τον αριθμό.

*/

#include <stdio.h>

// Επιστρέφει 1 αν ο αριθμός n είναι πρώτος, αλλιώς 0
int is_prime(long long n) {
    long long i;

    if (n < 2) {
        return 0;
    }

    if (n == 2) {
        return 1;
    }

    if (n % 2 == 0) {
        return 0;
    }

    // Εξετάζουμε περιττούς διαιρέτες μέχρι τη ρίζα του n
    for (i = 3; i <= n / i; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Εύρεση αναπαράστασης Goldbach με τον μικρότερο πρώτο p
void goldbach(long long n) {
    long long p, q;

    // Εξετάζουμε τους πιθανούς πρώτους από τον μικρότερο προς τον μεγαλύτερο
    for (p = 2; p <= n / 2; p++) {
        q = n - p;

        if (is_prime(p) && is_prime(q)) {
            printf("%lld = %lld + %lld\n", n, p, q);
            return;
        }
    }
}

int main(void) {
    long long n;
    char choice;
    int result;

    while (1) {
        printf("Give me a number: ");
        fflush(stdout);

        // Διαβάζουμε έναν ακέραιο και ελέγχουμε το αποτέλεσμα της scanf
        result = scanf("%lld", &n);

        if (result == EOF) {
            printf("EOF detected, exiting\n");
            return 0;
        }

        if (result != 1) {
            fprintf(stderr, "Invalid input: expected an integer\n");
            return 1;
        }

        // Ελέγχουμε αν ο αριθμός είναι στο επιτρεπτό διάστημα
        if (n < 0 || n > 10000000000LL) {
            fprintf(stderr, "Number should be in the range [0, 10000000000]\n");
            return 1;
        }

        printf("Choose how to test %lld - ('p' for prime, 'g' for goldbach) ", n);
        fflush(stdout);

        // Το κενό πριν από το %c αγνοεί κενά και αλλαγές γραμμής
        result = scanf(" %c", &choice);

        if (result == EOF) {
            printf("EOF detected, exiting\n");
            return 0;
        }

        if (choice != 'p' && choice != 'g') {
            fprintf(stderr, "Invalid choice: expected 'p' or 'g'\n");
            return 1;
        }

        if (choice == 'p') {
            if (is_prime(n)) {
                printf("%lld is prime\n", n);
            } else {
                printf("%lld is not prime\n", n);
            }
        } else {
            if (n <= 2 || n % 2 != 0) {
                printf("Goldbach's conjecture is applicable only to even numbers greater than 2!\n");
            } else {
                goldbach(n);
            }
        }
    }

    return 0;
}

