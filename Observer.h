//
// Created by prate on 11/07/2023.
//

#ifndef LABPROGRAMMAZIONE_OBSERVER_H
#define LABPROGRAMMAZIONE_OBSERVER_H


class Observer {
public:
    virtual void update() =0;
    virtual ~Observer() =0;

};


#endif //LABPROGRAMMAZIONE_OBSERVER_H
