//
// Created by prate on 11/07/2023.
//

#ifndef LABPROGRAMMAZIONE_COLLECTION_H
#define LABPROGRAMMAZIONE_COLLECTION_H


#include <vector>
#include <list>
#include "Observer.h"
#include "Note.h"
#include "Subject.h"
#include "Application.h"

class Collection : public Subject {
private:
    std::list<Note> notes;
    std::string name;
    std::list<Observer *> observers;
    int totBlocked;

public:
    explicit Collection(const std::string &name);

    //getters
    const std::string &getName() const;

    unsigned int getTotBlocked() const;
    unsigned int getTotNotes() const;

    //Notes methods
    void changeLock(const std::string &title);
    bool isLocked(const std::string &title) const;

    void addNote(const std::string &title, const std::string &text);
    bool modifyNote(const std::string &title, const std::string &newText);
    bool deleteNote(const std::string &title);

    bool findNote(const std::string &title) const;
    void displayNotes() const;

    const std::string &getText(const std::string &title) const;

    //Pattern Observer logic
    void notify() override;

    void registerO(Observer *obs) override;

    void removeO(Observer *obs) override;

    ~Collection() override;
};


#endif //LABPROGRAMMAZIONE_COLLECTION_H
