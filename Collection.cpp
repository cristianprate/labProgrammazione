//
// Created by prate on 11/07/2023.
//

#include <iostream>
#include "Collection.h"

void Collection::addNote(const std::string& title, const std::string& text) {
    Note n(title, text);
    notes.push_back(n);
}

const std::string &Collection::getText(const std::string &title) const{
    for(auto & note : notes){
        if(note.getTitle() == title){
            return note.getText();
        }
    }
    return "";
}

bool Collection::isLocked(const std::string &title) const{
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
            if(note.isLock()) {
                note.setLock(false);
                totBlocked--;
                notify();
            }
            else {
                note.setLock(true);
                totBlocked++;
                notify();
            }
        }
    }
}

void Collection::displayNotes() const{
    for(auto & note : notes){
        std::cout<<"-----------------------"<<note.getTitle()<<"---------------------"<<std::endl<<std::endl;
        std::cout<<note.getText()<<std::endl;
        std::cout<<"----------------------------------------------------------"<<std::endl<<std::endl;
    }

}

Collection::Collection( const std::string& name) :name(name), totBlocked(0) {
}

Collection::~Collection() {
    for(Observer* obs : observers){
        delete obs;
    }
}

bool Collection::modifyNote(const std::string &title, const std::string &newText) {
    bool output=false;
    for (Note &n: notes) {
        if(n.getTitle()==title){
            n.setText(newText);
            output=true;
        }
    }
    return output;
}

const std::string &Collection::getName() const {
    return name;
}

void Collection::notify() {
    for(Observer *obs : observers){
        obs->update();
    }
}

void Collection::registerO(Observer * const obs) {
    observers.push_back(obs);
}

void Collection::removeO(Observer * const obs) {
    observers.remove(obs);
}


int Collection::getTotBlocked() const {
    return totBlocked;
}

bool Collection::findNote(const std::string &title) const{
    for(const Note& n : notes){
        if(n.getTitle() == title){
            return true;
        }
    }
    return false;
}

unsigned int Collection::getTotNotes() const {
    return notes.size();
}

bool Collection::deleteNote(const std::string &title) {
    for(const Note& n : notes){
        if(n.getTitle() == title){
            if(n.isLock())
                totBlocked--;
            notes.remove(n);
            return true;
        }
    }
    return false;
}






