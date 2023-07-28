//
// Created by prate on 13/07/2023.
//

#include "gtest/gtest.h"
#include "../Collection.h"
#include "../BlockedObserver.h"

class CollectionSuite : public ::testing::Test {
protected:
    virtual void SetUp() {
        c.addNote("cosa portare", "ombrellone, asciugamani");
        c.addNote("cosa fare", "bagno, pranzo");
        BlockedObserver obs(&c);
    }

    Collection c = Collection("mare");
};

TEST_F(CollectionSuite, WrongNoteTest) {
    ASSERT_EQ(false, c.findNote("dove andare"));
}

TEST_F(CollectionSuite, NotesNumberTest) {
    ASSERT_EQ(2, c.getTotNotes());
    c.deleteNote("cosa portare");
    ASSERT_EQ(1, c.getTotNotes());
}

TEST_F(CollectionSuite, DeleteLockedNoteTest) {
    c.changeLock("cosa portare");
    ASSERT_EQ(1, c.getTotBlocked());
    c.deleteNote("cosa portare");
    ASSERT_EQ(1, c.getTotBlocked());
}


