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

class Collection : public Subject{
private:
    std::list<Note> notes;
    std::string name;
    int totBlocked;
    std::list<Observer*> observers;

public:
    explicit Collection( const std::string& name);
    //Class status controllers
    const std::string &getName() const;
    int getTotBlocked() const;

    //Notes controllers
    const std::string &getText(const std::string& title) const;

    bool isLocked(const std::string& title) const;
    void changeLock(const std::string& title);

    void displayNotes() const;
    bool modifyNote(const std::string& title, const std::string& newText);
    void addNote(const std::string& title, const std::string& text);
    bool findNote(const std::string& title) const;

    //Pattern Observer logic
    void notify() override;
    void registerO(Observer* obs) override;
    void removeO(Observer* obs) override;

    ~Collection() override;
};


#endif //LABPROGRAMMAZIONE_COLLECTION_H
