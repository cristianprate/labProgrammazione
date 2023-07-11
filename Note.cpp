//
// Created by prate on 11/07/2023.
//

#include "Note.h"

const std::string &Note::getTitle() const {
    return title;
}

void Note::setTitle(const std::string &title) {
    Note::title = title;
}

const std::string &Note::getText() const {
    return text;
}

void Note::setText(const std::string &text) {
    Note::text = text;
}

bool Note::isLock() const {
    return lock;
}

void Note::setLock(bool lock) {
    Note::lock = lock;
}
