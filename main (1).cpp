#include <iostream>
using namespace std;

struct Tstruct{
    int value;
    Tstruct* next;
    Tstruct* prev;
};


class List {
    private:
        Tstruct* HEAD;
        Tstruct* TAIL;
    public:
        List() : HEAD(nullptr), TAIL(nullptr) {}
        
        ~List(){
            Tstruct* current = HEAD;
            while(current != nullptr){
                Tstruct* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
        
        void add(int VALUE){
            Tstruct* node = new Tstruct{VALUE, nullptr, TAIL};
            if(TAIL == nullptr){
                HEAD = node;
            } else {
                TAIL->next = node;
            }
            TAIL = node;
        }
        
        void display(){
            for(Tstruct* p = HEAD; p!= nullptr; p = p->next){
                cout << p->value << " ";
            }
            cout << endl;
        }
        
        void remove(int VALUE){
            Tstruct* p = HEAD;
            
            while(p !=nullptr && p->value != VALUE){
                p = p->next;
            }
            if(p == nullptr) return;
            
            if(p->prev != nullptr) p->prev->next = p->next;
            else HEAD = p->next;
            
            if(p->next != nullptr) p->next->prev = p->prev;
            else TAIL = p->prev;
            
            delete p;
        }
        
        bool contains(int VALUE){
            for(Tstruct* p = HEAD; p!=nullptr; p = p->next){
                if(p->value == VALUE) return true;
            }
            return false;
        }
        
        int count(){
            int n = 0;
            for(Tstruct* p = HEAD; p !=nullptr; p = p->next){
                n++;
            }
            return n;
        }
};


int main(){
    List list;
    
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(20);
    
    cout << "Po pridani: ";
    list.display();
    
    cout << "Pocet prvku: " << list.count() << endl;
    
    cout << "Obsahuje 20?" << (list.contains(20) ? " ano" : " ne") << endl;
    cout << "Obsahuje 99?" << (list.contains(99) ? " ano" : " ne") << endl;
    
    list.remove(20);
    
    cout << "Po remove(20): ";
    list.display();
    
    list.remove(10);
    
    list.remove(20);
    
    list.remove(99);
    
    cout << "Po dalsich remove: ";
    list.display();
    
    cout << "Pocet prvku: " << list.count() << endl;
    
    return 0;
}





/*int sum(int array[], int size){
    int total = 0;
    for (int i = 0; i < size; i++){
        total += array[i];
    }
    return total;
}

double average(int array[], int size){
    return 1.0 * sum(array, size) / size;
}


int main()
{
    const int SIZE = 5;
    int numbers[SIZE];
    
    cout << "Zadej " << SIZE << " celych cisel: " << endl;
    for (int i = 0; i < SIZE; i++){
        cout << "Cislo " << i+1 << ": ";
        cin >> numbers[i];
    }

    int even = 0, odd = 0;
    bool hasZero = false;
    for(int i = 0; i < SIZE; i++){
        if(numbers[i] % 2 ==0) even++;
        else odd++;
        if(numbers[i] == 0) hasZero = true;
    }
    
    cout << "Sudych cisel: " << even << endl;
    cout << "Lichych cisel: " << odd << endl;
    cout << (hasZero ? "Pole obsahuje nulu." : "Pole neobsahuje nulu.") << endl;
    
    
    cout << "Cisla v poli: ";
    for (int i = 0; i < SIZE; i++){
        cout << numbers[i] << " ";
    }
    
    cout << "Soucet: " << sum(numbers,SIZE) << endl;
    cout << "Prumer: " << average(numbers, SIZE) << endl;
    
    return 0;
}*/