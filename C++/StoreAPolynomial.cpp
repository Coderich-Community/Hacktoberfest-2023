// Storing a Polynomial using Linked List

#include <iostream>
using namespace std;

// Structure to represent a term in the polynomial
struct Term {
    int coefficient;
    int exponent;
    Term* next;
};

class Polynomial {
private:
    Term* head; // Pointer to the first term in the polynomial

public:
    Polynomial() {
        head = nullptr;
    }

    // Function to insert a new term into the polynomial
    void insertTerm(int coefficient, int exponent) {
        Term* newTerm = new Term;
        newTerm->coefficient = coefficient;
        newTerm->exponent = exponent;
        newTerm->next = nullptr;

        if (head == nullptr || exponent > head->exponent) {
            newTerm->next = head;
            head = newTerm;
        } else {
            Term* current = head;
            while (current->next != nullptr && current->next->exponent >= exponent) {
                current = current->next;
            }
            newTerm->next = current->next;
            current->next = newTerm;
        }
    }

    // Function to display the polynomial
    void displayPolynomial() {
        Term* current = head;
        while (current != nullptr) {
            cout << current->coefficient << "x^" << current->exponent;
            if (current->next != nullptr) {
                cout << " + ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Polynomial p;

    p.insertTerm(5, 2);
    p.insertTerm(3, 1);
    p.insertTerm(7, 4);
    p.insertTerm(2, 3);

    cout << "Polynomial: ";
    p.displayPolynomial();

    return 0;
}

// Output: 
// Polynomial: 7x^4 + 2x^3 + 5x^2 + 3x^1