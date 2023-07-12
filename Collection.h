//
// Created by prate on 11/07/2023.
//

#ifndef LABPROGRAMMAZIONE_COLLECTION_H
#define LABPROGRAMMAZIONE_COLLECTION_H


#include <vector>
#include "Observer.h"
#include "Note.h"
#include "Subject.h"

class Collection : public Observer{
private:
    std::string name;
    std::vector<Note> notes;
    int totNotes;
    Subject* subject;

    void addNote(const std::string& title, const std::string& text);

public:
    explicit Collection( const std::string& name, Subject *subject);

    std::string getText(const std::string& title);

    bool isLocked(const std::string& title);
    void changeLock(const std::string& title);

    void displayNotes();

    const std::string &getName() const;

    void update(const std::string& title, const std::string& text) override;
    ~Collection() override;
};


#endif //LABPROGRAMMAZIONE_COLLECTION_H
