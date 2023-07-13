//
// Created by prate on 11/07/2023.
//

#include <iostream>
#include "Collection.h"

void Collection::update(const std::string& title, const std::string& text) {
    addNote(title, text);
    totNotes++;
}

void Collection::addNote(const std::string& title, const std::string& text) {
    Note n(title, text);
    notes.push_back(n);
}

std::string Collection::getText(const std::string &title) {
    for(auto & note : notes){
        if(note.getTitle() == title){
            return note.getText();
        }
    }
    return "";
}

bool Collection::isLocked(const std::string &title) {
    for(auto & note : notes){
        if(note.getTitle() == title){
            return note.isLock();
        }
    }
    return false;
}

void Collection::changeLock(const std::string& title) {
    for(auto & note : notes){
        if(note.getTitle() == title){
            if(note.isLock())
                note.setLock(false);
            else
                note.setLock(true);
        }
    }
}

void Collection::displayNotes() {
    for(auto & note : notes){
        std::cout<<"-----------------------"<<note.getTitle()<<"---------------------"<<std::endl<<std::endl;
        std::cout<<note.getText()<<std::endl;
        std::cout<<"----------------------------------------------------------"<<std::endl<<std::endl;
    }

}

Collection::Collection( const std::string& name, Subject *subject) :Observer(name), subject(subject), totNotes(0) {
    subject->registerO(this);
}

Collection::~Collection() {
    subject->removeO(this);
}

const std::vector<Note> &Collection::getNotes() const {
    return notes;
}

void Collection::modifyNote(const std::string &title, const std::string &newText) {
    for (Note &n: notes) {
        if(n.getTitle()==title){
            n.setText(newText);
        }
    }
}





