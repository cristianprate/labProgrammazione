//
// Created by prate on 11/07/2023.
//

#ifndef LABPROGRAMMAZIONE_SUBJECT_H
#define LABPROGRAMMAZIONE_SUBJECT_H


#include <string>
#include "Observer.h"

class Subject {
public:
    virtual void notify() = 0;

    virtual void registerO(Observer *obs) = 0;

    virtual void removeO(Observer *obs) = 0;

    virtual ~Subject() {}
};


#endif //LABPROGRAMMAZIONE_SUBJECT_H
