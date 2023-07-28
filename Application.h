//
// Created by prate on 11/07/2023.
//

#ifndef LABPROGRAMMAZIONE_APPLICATION_H
#define LABPROGRAMMAZIONE_APPLICATION_H

#include "Collection.h"
#include "Subject.h"
#include "Observer.h"
#include <vector>

class Collection; //forward declaration to avoid circular dependency among Application and Collection headers(both have class A and B members attribute)
class Application {
private:
    std::vector<Collection *> collections;
    std::list<Observer *> collectionsObs;

public:
    Application();

    //Collections methods
    bool newCollection(const std::string &name);
    int getCollectionsNumber() const;

    void displayCollections() const;

    //Notes methods
    void addToCollection(const std::string &title, const std::string &text, const std::string &collName);
    bool addToImportant(const std::string &title);

    bool modifyNote(const std::string &collTitle, const std::string &title, const std::string &newText);

    bool deleteNote(const std::string &collTitle, const std::string &title);

    bool changeLock(const std::string &collTitle, const std::string &title);

    void displayNotesFromCollection(const std::string &name) const;

    ~Application();
};


#endif //LABPROGRAMMAZIONE_APPLICATION_H
