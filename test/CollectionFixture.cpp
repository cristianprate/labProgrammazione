//
// Created by prate on 13/07/2023.
//

#include "gtest/gtest.h"
#include "../Collection.h"
#include "../BlockedObserver.h"

class CollectionSuite : public ::testing::Test{
protected:
    virtual void SetUp(){
        c.addNote("cosa portare", "ombrellone, asciugamani");
        BlockedObserver obs(&c);
    }

    Collection c = Collection("mare");
};

TEST_F(CollectionSuite, WrongNoteTest) {
    ASSERT_EQ(false, c.findNote("dove andare"));
}


