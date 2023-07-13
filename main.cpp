#include <iostream>
#include "Application.h"

int main() {
    Application app;
    std::string name, title, text, appo;
    int x;
    bool exit = false;
   do {
        do {
            system("cls");
            std::cout << "Welcome to your personal Notes App!" << std::endl;
            std::cout << "1. CREATE COLLECTION" << std::endl;
            std::cout << "2. CREATE NOTE" << std::endl;
            std::cout << "3. VIEW ALL COLLECTIONS" << std::endl;
            std::cout << "4. SELECT A COLLECTION" << std::endl;
            std::cout << "5. ADD TO IMPORTANT" << std::endl;
            std::cout << "6. CHANGE TEXT OF A NOTE" << std::endl;
            std::cout << "7. CHANGE LOCK OF A NOTE" << std::endl;
            std::cout << "8. EXIT" << std::endl;
            std::cin >> x;
        } while (x < 0 || x > 8);
        system("cls");
        switch (x) {
            default:
                system("cls");
            case 1:
                std::cout << "Creating a new collection......" << std::endl;
                std::cout << "Insert collection name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                app.newCollection(name);
                break;
            case 2:
                std::cout << "Creating a new note......" << std::endl;
                std::cout << "Insert note title:";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << std::endl;
                std::cout << "Type the note's text:";
                std::getline(std::cin, text);
                std::cout << std::endl;
                std::cout << "Type the note's collection name: ";
                std::getline(std::cin, name);
                app.addToCollection(title, text, name);
                break;
            case 3:
                std::cout << "Here's your collections:" << std::endl;
                app.displayCollections();
                std::cout << "Press 'a' to exit..." << std::endl;
                do{
                    std::cin.ignore();
                    std::getline(std::cin, appo);
                }while(appo!="a");
                break;
            case 4:
                std::cout << "Type the name of the collection: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Here's the notes of the " << name << " collection:" << std::endl;
                app.displayNotesFromCollection(name);
                std::cout << "Press 'a' to exit..." << std::endl;
                do{
                    std::getline(std::cin, appo);
                }while(appo!="a");
                break;
            case 5:
                std::cout << "Type the title of the note you want to add to important: "<<std::endl;
                std::cin.ignore();
                std::getline(std::cin, title);
                app.addToImportant(title);
                break;
            case 6:
                std::cout << "Changing the text of a note... "<<std::endl;
                std::cout << "Insert note title:";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Insert note's new text:";
                std::getline(std::cin, text);
                app.modifyNote(title, text);
                break;
            case 7:
                std::cout << "Changing the lock of a note... "<<std::endl;
                std::cout << "Insert note title:";
                std::cin.ignore();
                std::getline(std::cin, title);
                app.changeLock(title);
                break;
            case 8:
                exit = true;
        }
        system("cls");
    } while (!exit);

    return 0;
}
