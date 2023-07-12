//
// Created by prate on 11/07/2023.
//

#ifndef LABPROGRAMMAZIONE_APPLICATION_H
#define LABPROGRAMMAZIONE_APPLICATION_H


#include <vector>
#include "Collection.h"
#include "Subject.h"

class Application : public Subject{
private:
    std::vector<Observer*> collections;

    void notify(const std::string & title, const std::string & text, const std::string &collName) override;

public:
    Application();

    void addToCollection(const std::string & title, const std::string & text, const std::string &collName);

    void newCollection(const std::string name);

    void registerO(Observer* const obs) override;
    void removeO(Observer* const obs) override;
    ~Application() override;
};


#endif //LABPROGRAMMAZIONE_APPLICATION_H
