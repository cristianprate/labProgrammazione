//
// Created by prate on 11/07/2023.
//

#ifndef LABPROGRAMMAZIONE_NOTE_H
#define LABPROGRAMMAZIONE_NOTE_H


#include <string>

class Note {
private:
    std::string title;
    std::string text;
    bool lock;

public:
    Note(const std::string &title, const std::string &text);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const std::string &getText() const;

    void setText(const std::string &text);

    bool isLock() const;

    void setLock(bool lock);
};


#endif //LABPROGRAMMAZIONE_NOTE_H
