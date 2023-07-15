//
// Created by prate on 15/07/2023.
//

#ifndef LABPROGRAMMAZIONE_BLOCKEDOBSERVER_H
#define LABPROGRAMMAZIONE_BLOCKEDOBSERVER_H


#include "Observer.h"
#include "Collection.h"

class BlockedObserver : public Observer{
private:
    Collection* c;

public:
    BlockedObserver(Collection* c);

    void update() override;

    ~BlockedObserver() override;
};


#endif //LABPROGRAMMAZIONE_BLOCKEDOBSERVER_H
