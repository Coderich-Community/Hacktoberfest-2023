#include <iostream>
using namespace std;

struct Term {
    int coefficient;
    int exponent;
    Term* next;
};

void insertTerm(Term*& head, int coefficient, int exponent) {
    Term* newTerm = new Term;
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = nullptr;

    if (!head) {
        head = newTerm;
    } else {
        Term* current = head;
        Term* prev = nullptr;

        while (current && current->exponent > exponent) {
            prev = current;
            current = current->next;
        }

        if (current && current->exponent == exponent) {
            current->coefficient += coefficient;
            delete newTerm;
        } else {
            newTerm->next = current;
            if (prev) {
                prev->next = newTerm;
            } else {
                head = newTerm;
            }
        }
    }
}

void displayPolynomial(Term* head) {
    Term* current = head;
    while (current) {
        cout << current->coefficient << "x^" << current->exponent;
        if (current->next) {
            cout << " + ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    Term* polynomial = nullptr;

    insertTerm(polynomial, 5, 2);
    insertTerm(polynomial, 3, 1);
    cout << "Polynomial: ";
    displayPolynomial(polynomial);
    return 0;
}
