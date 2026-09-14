#include "../headers/Library.h"
#include "../headers/Librarian.h"

using namespace LibrarySystem;

int main() {
    Library lib;
    int choice;

    Person* p = new Librarian(1, "Admin", "0000000000", 1, 25000);
    p->displayInfo();
    delete p;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add New Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Search Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Register Member\n";
        cout << "6. Remove Member\n";
        cout << "7. Search Member\n";
        cout << "8. Display All Members\n";
        cout << "9. Issue Book\n";
        cout << "10. Return Book\n";
        cout << "11. View Overdue Books\n";
        cout << "12. Save Data\n";
        cout << "13. Load Data\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1: lib.addBook(); break;
                case 2: lib.removeBook(); break;
                case 3: lib.searchBook(); break;
                case 4: lib.displayBooks(); break;
                case 5: lib.addMember(); break;
                case 6: lib.removeMember(); break;
                case 7: lib.searchMember(); break;
                case 8: lib.displayMembers(); break;
                case 9: lib.issueBook(); break;
                case 10: lib.returnBook(); break;
                case 11: lib.viewOverdue(); break;
                case 12: lib.saveData(); break;
                case 13: lib.loadData(); break;
                case 0: cout << "Program ended." << endl; break;
                default: cout << "Invalid choice." << endl;
            }
        }
        catch (LibraryException& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 0);

    return 0;
}
