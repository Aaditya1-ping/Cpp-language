#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d)
        : title(t), author(a), dueDate(d) {}

    virtual ~LibraryItem() {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

    void setTitle(string newTitle) { title = newTitle; }
    void setAuthor(string newAuthor) { author = newAuthor; }
    void setDueDate(string newDueDate) { dueDate = newDueDate; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};

class Book : public LibraryItem {
public:
    Book(string t, string a, string d) : LibraryItem(t, a, d) {}

    void checkOut() override {
        cout << "Book \"" << getTitle() << "\" checked out."<<endl;
    }

    void returnItem() override {
        cout << "Book \"" << getTitle() << "\" returned."<<endl;
    }

    void displayDetails() const override {
        cout << "[Book] Title: " << getTitle()<<endl
             << " Author: " << getAuthor()<<endl
             << " Due Date: " << getDueDate() << endl;
    }
};

class DVD : public LibraryItem {
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d), duration(dur) {}

    void checkOut() override {
        cout << "DVD \"" << getTitle() << "\" checked out."<<endl;
    }

    void returnItem() override {
        cout << "DVD \"" << getTitle() << "\" returned."<<endl;
    }

    void displayDetails() const override {
        cout << "[DVD] Title: " << getTitle()<<endl
             << " Author: " << getAuthor()<<endl
             << " Due Date: " << getDueDate()<<endl
             << " Duration: " << duration << " mins"<<endl;
    }
};

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d), issueNumber(issue) {}

    void checkOut() override {
        cout << "Magazine \"" << getTitle() << "\" checked out."<<endl;
    }

    void returnItem() override {
        cout << "Magazine \"" << getTitle() << "\" returned."<<endl;
    }

    void displayDetails() const override {
        cout << "[Magazine] Title: " << getTitle()<<endl
             << " Author: " << getAuthor()<<endl
             << " Due Date: " << getDueDate()<<endl
             << " Issue #: " << issueNumber << endl;
    }
};

void displayMenu() {
    cout <<endl<< "=== Library Menu ==="<<endl
         << "1. Add Book"<<endl
         << "2. Add DVD"<<endl
         << "3. Add Magazine"<<endl
         << "4. Display All Items"<<endl
         << "5. Check Out Item"<<endl
         << "6. Return Item"<<endl
         << "7. Exit"<<endl
         << "Choose an option: ";
}

int main() {
    LibraryItem* libraryItems[MAX_ITEMS];
    int itemCount = 0;

    int choice;
    while (true) {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();  
            cin.ignore(10000, '\n'); 
            cout << "Invalid input. Try again."<<endl;
            continue;
        }

        if (choice == 1) {
            if (itemCount >= MAX_ITEMS) {
                cout << "Catalog full."<<endl;
                continue;
            }
            string title, author, due;
            cout << "Enter title: "; cin.ignore(); getline(cin, title);
            cout << "Enter author: "; getline(cin, author);
            cout << "Enter due date: "; getline(cin, due);
            libraryItems[itemCount++] = new Book(title, author, due);
        }
        else if (choice == 2) {
            if (itemCount >= MAX_ITEMS) {
                cout << "Catalog full."<<endl;
                continue;
            }
            string title, author, due;
            int duration;
            cout << "Enter title: "; cin.ignore(); getline(cin, title);
            cout << "Enter author: "; getline(cin, author);
            cout << "Enter due date: "; getline(cin, due);
            cout << "Enter duration in minutes: "; cin >> duration;

            if (duration < 0) {
                cout << "Invalid duration."<<endl;
                continue;
            }

            libraryItems[itemCount++] = new DVD(title, author, due, duration);
        }
        else if (choice == 3) {
            if (itemCount >= MAX_ITEMS) {
                cout << "Catalog full."<<endl;
                continue;
            }
            string title, author, due;
            int issue;
            cout << "Enter title: "; cin.ignore(); getline(cin, title);
            cout << "Enter author: "; getline(cin, author);
            cout << "Enter due date: "; getline(cin, due);
            cout << "Enter issue number: "; cin >> issue;

            if (issue <= 0) {
                cout << "Invalid issue number."<<endl;
                continue;
            }

            libraryItems[itemCount++] = new Magazine(title, author, due, issue);
        }
        else if (choice == 4) {
            if (itemCount == 0) {
                cout << "No items to display."<<endl;
                continue;
            }
            for (int i = 0; i < itemCount; i++) {
                cout << i + 1 << ". ";
                libraryItems[i]->displayDetails();
            }
        }
        else if (choice == 5 || choice == 6) {
            if (itemCount == 0) {
                cout << "No items available."<<endl;
                continue;
            }
            for (int i = 0; i < itemCount; i++) {
                cout << i + 1 << ". ";
                libraryItems[i]->displayDetails();
            }
            int index;
            cout << "Enter item number: ";
            cin >> index;

            if (index < 1 || index > itemCount) {
                cout << "Invalid number."<<endl;
                continue;
            }

            if (choice == 5)
                libraryItems[index - 1]->checkOut();
            else
                libraryItems[index - 1]->returnItem();
        }
        else if (choice == 7) {
            for (int i = 0; i < itemCount; i++) {
                delete libraryItems[i];
            }
            cout << "Goodbye! All memory released."<<endl;
            break;
        }
        else {
            cout << "Invalid choice."<<endl;
        }
    }

    
}

/*
 Output:
 
=== Library Menu ===
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
7. Exit
Choose an option: 1
Enter title: MunaMadan
Enter author: Laxmi.P
Enter due date: 1939

=== Library Menu ===
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
7. Exit
Choose an option: 2
Enter title: Jhola
Enter author: Ram.P
Enter due date: 2017
Enter duration in minutes: 90

=== Library Menu ===
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
7. Exit
Choose an option: 3
Enter title: Captain
Enter author: Hari.P
Enter due date: 2019
Enter issue number: 17

=== Library Menu ===
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
7. Exit
Choose an option:
4
1. [Book] Title: MunaMadan
 Author: Laxmi.P
 Due Date: 1939
2. [DVD] Title: Jhola
 Author: Ram.P
 Due Date: 2017
 Duration: 90 mins
3. [Magazine] Title: Captain
 Author: Hari.P
 Due Date: 2019
 Issue #: 17

=== Library Menu ===
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
7. Exit
Choose an option: 5
1. [Book] Title: MunaMadan
 Author: Laxmi.P
 Due Date: 1939
2. [DVD] Title: Jhola
 Author: Ram.P
 Due Date: 2017
 Duration: 90 mins
3. [Magazine] Title: Captain
 Author: Hari.P
 Due Date: 2019
 Issue #: 17
Enter item number: 6
Invalid number.

=== Library Menu ===
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
7. Exit
Choose an option: 7
Goodbye! All memory released.


*/

           
