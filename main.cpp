/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

struct Node{
    string name;
    int ticketNumber;
    Node* next;
    
    Node(string n, int t) : name(n), ticketNumber(t), next(nullptr) {}
};

class LinkedList{
    private:
        Node* head;
        
    public:
        LinkedList(): head(nullptr) {}
        
        bool isEmpty() const {
            return head == nullptr;
        }
        void removeFront(){
            if(isEmpty()){
                cout << "Seznam je prazdny. Neni co odebrat." << endl;
                return;
            }
            
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            
            cout << "[Info] Prvni prvek byl smazan." << endl;
        }
        void append(string name, int ticket){
            Node* newNode = new Node(name, ticket);
            if(isEmpty()){
                head = newNode;
                return;
            }
            Node* current = head;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }
        void printList() const {
            if(isEmpty()){
                cout << "Fronta je prazdna." << endl;
                return;
            }
            Node* current = head;
            cout << "Fronta: ";
            while(current != nullptr) {
                cout << "[" << current->name << "(" << current->ticketNumber << ")] ";
                current = current->next;
            }
            cout << endl;
        }
        // Ukol 8.2. vymazani objektu podle urciteho data
        void removeByTicket(int ticket){
            if(isEmpty()){
                return;
            }
            if(head->ticketNumber == ticket){
                removeFront();
                return;
            }
            Node* prev = head;
            Node* current = head->next;
            while(current->ticketNumber == ticket){
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
        // Ukol 8.3. destruktor
        ~LinkedList() {
            while(head != nullptr){
                Node* nextNode = head->next;
                delete head;
                head = nextNode;
            }
            cout << "[Destruktor] Seznam uklizen." << endl;
        }
};


int main()
{
    LinkedList fronta;
    
    fronta.append("Alice", 1);
    fronta.append("Bob", 2);
    fronta.append("Charlie", 3);
    
    cout << "--- Puvodni fronta ---" << endl;
    fronta.printList();
    cout << "Konec bloku se blizi" << endl;
    cout << "Konec programu" << endl;
    
    /*cout << "Odebiram Boba (2)" << endl;
    fronta.removeByTicket(2);
    
    fronta.removeFront();
    
    
    
    cout << "--- Konecna fronta ---" << endl;
    fronta.printList();*/

    return 0;
}
