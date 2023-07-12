#include <iostream>
#include "Application.h"

int main() {
    Application app;
    std::string name, title, text;
    std::cout << "Welcome to your personal Notes App!" << std::endl;

    std::cout << "NEW COLLECTION! Insert name here: ";
    getline(std::cin, name);
    app.newCollection(name);
    std::cout << std::endl << std::endl;

    std::cout << "NEW COLLECTION! Insert name here: ";
    getline(std::cin, name);
    app.newCollection(name);
    std::cout << std::endl << std::endl;

    std::cout << "NEW NOTE! Insert title here: ";
    getline(std::cin, title);
    std::cout << "Insert text here: ";
    getline(std::cin, text);
    app.addToCollection(title, text, name);
    std::cout << std::endl << std::endl;

    std::cout << "YOUR COLLECTIONS:" << std::endl;
    app.displayCollections();
    std::cout << "NOTES IN " << name << " COLLECTION:"<< std::endl;
    app.displayNotesFromCollection(name);

    return 0;
}
