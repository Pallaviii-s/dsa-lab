#include "roundrobin.h"

int main() {
    list list1;
    int choice, value, position,pos;

    do {
        cout << "\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9 Exit\nEnter choice: ";
        cin >> choice;

        switch(choice){
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list1.insert_begin(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list1.insert_end(value);
            break;
        case 3:
            cout << "Enter position : ";
            cin >> position;
            cout<<"Enter value : ";
            cin>>value;
            list1.insert_position(position, value);
            break;
        case 4:
            list1.delete_begin();
            break;
        case 5:
            list1.delete_end();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> position;
            list1.delete_position(position);
            break;
        case 7:
            cout << "Enter value: ";
            cin >> value;
            pos=list1.search(value);
            if (position != -1)
                cout << "Found. " << endl;
            else
                cout << "Not found" << endl;
            break;
        case 8:
            list1.display();
            break;
        case 9:
            cout << "Exiting..." << endl;
            break;
            
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 9);
    
    return 0;
}


