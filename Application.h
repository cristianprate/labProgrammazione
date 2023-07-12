//
// Created by prate on 11/07/2023.
//

#ifndef LABPROGRAMMAZIONE_APPLICATION_H
#define LABPROGRAMMAZIONE_APPLICATION_H

#include "Collection.h"
#include "Subject.h"
#include "Observer.h"
#include <vector>

class Collection; //forward declaration to avoid circular dependency among Application and Collection headers
class Application : public Subject{
private:
    std::vector<Collection*> collections;

    void notify(const std::string & title, const std::string & text, const std::string &collName) override;

public:
    Application();

    void addToCollection(const std::string & title, const std::string & text, const std::string &collName);
    void addToImportant(const std::string & title);

    void newCollection(const std::string name);
    void displayNotesFromCollection(const std::string name);
    void displayCollections();

    void registerO(Observer* const obs) override;
    void removeO(Observer* const obs) override;
    ~Application() override;
};


#endif //LABPROGRAMMAZIONE_APPLICATION_H
