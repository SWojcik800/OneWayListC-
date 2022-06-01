#include <iostream>
using namespace std;

template <class T>
class List
{
    struct Element {
        T data;
        Element* next;
    };

    Element* head;

public:

    int totalCount = 0;

    List()
    {
        head = NULL;
    }

    //Dodaje element do listy
    void add(T item)
    {
        totalCount++;
        Element* new_element = new Element;
        new_element->data = item;
        new_element->next = NULL;


        if (head == NULL)
            head = new_element;

        else
        {
            new_element->next = head;
            head = new_element;
        }
    }


    //Sprawdza czy element jest w liscie

    T elementInList(T item)
    {

        Element* temp = this->head;
        while (temp != NULL)
        {

            if (temp->data == item)
                return true;
            temp = temp->next;
        }
        return false;
    }

    //Usuwa element z listy
    void remove(T item)
    {
        totalCount--;
        if (head->data == item)
        {
            delete head;
            head = head->next;
            return;
        }


        if (head->next == NULL)
        {

            if (head->data == item)
            {
                delete head;
                head = NULL;
                return;
            }

            cout << "NULL" << endl;
            return;
        }


        Element* temp = head;
        while (temp->next != NULL)
        {

            if (temp->next->data == item)
            {
                Element* temp_ptr = temp->next->next;
                delete temp->next;
                temp->next = temp_ptr;
                return;
            }
            temp = temp->next;
        }


        cout << "NULL" << endl;
    }

    //Wyświetla elementy
    void display()
    {
        Element* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getTotalCount()
    {
        return this->totalCount;
    }
};




int main() {

    cout << "Typ: char" << endl;
    List<char>* l = new List<char>();


    l->add('a');
    l->add('b');
    l->add('c');


    cout << "Elementy: ";
    l->display();
    cout << "Element a w liscie: " << (l->elementInList('a') ? "TAK" : "NIE") << endl;
    cout << "Liczba Elementow: " << l->getTotalCount() << endl;
    cout << endl;
    cout << "Po usunieciu:" << endl;
    cout << "Element usuniety: a" << endl;
    l->remove('a');

    cout << "Element a w liscie: " << (l->elementInList('a') ? "TAK" : "NIE") << endl;
    cout << "Liczba Elementow: " << l->getTotalCount() << endl;

    cout << "--------------------------------------" << endl;

    delete l;

    cout << "Typ: int" << endl;
    List<int>* l2 = new List<int>();

    l2->add(1);
    l2->add(2);
    l2->add(3);
    cout << "Element 3 w liscie: " << (l2->elementInList(2) ? "TAK" : "NIE") << endl;
    cout << "Elementy: ";

    l2->display();


    
    cout << "Liczba Elementow: " << l2->getTotalCount() << endl;
    cout << endl;

    l2->remove(3);
    cout << "Po usunieciu:" << endl;
    cout << "Element usuniety: 3" << endl;
    cout << "Liczba Elementow: " << l2->getTotalCount() << endl;


}