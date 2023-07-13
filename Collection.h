//
// Created by prate on 11/07/2023.
//

#ifndef LABPROGRAMMAZIONE_COLLECTION_H
#define LABPROGRAMMAZIONE_COLLECTION_H


#include <vector>
#include "Observer.h"
#include "Note.h"
#include "Subject.h"
#include "Application.h"

class Collection : public Observer{
private:
    std::vector<Note> notes;
    int totNotes;
    Subject* subject;

    void addNote(const std::string& title, const std::string& text);

public:
    explicit Collection( const std::string& name, Subject *subject);

    std::string getText(const std::string& title);
    std::vector<Note> &getNotes();

    bool isLocked(const std::string& title);
    void changeLock(const std::string& title);

    void displayNotes();
    void modifyNote(const std::string& title, const std::string& newText);

    void update(const std::string& title, const std::string& text) override;
    ~Collection() override;
};


#endif //LABPROGRAMMAZIONE_COLLECTION_H
