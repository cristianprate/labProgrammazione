//
// Created by prate on 11/07/2023.
//

#ifndef LABPROGRAMMAZIONE_COLLECTION_H
#define LABPROGRAMMAZIONE_COLLECTION_H


#include <vector>
#include "Observer.h"
#include "Note.h"

class Collection : public Observer{
private:
    std::vector<Note> notes;
    int totNotes;

public:
    void addNote(const std::string& title, const std::string& text);

    std::string getText(const std::string& title);

    bool isLocked(const std::string& title);
    void changeLock(const std::string& title);

    void displayNotes();

    void update() override;
    ~Collection() override;
};


#endif //LABPROGRAMMAZIONE_COLLECTION_H
