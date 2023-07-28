//
// Created by prate on 13/07/2023.
//

#include "gtest/gtest.h"
#include "../Collection.h"

TEST(Collection, LockCheck){
    Collection c = Collection("mare");
    c.addNote("cosa portare", "ombrellone, asciugamani");
    ASSERT_FALSE(c.isLocked("cosa portare"));
    ASSERT_EQ(0, c.getTotBlocked());
    c.changeLock("cosa portare");
    ASSERT_TRUE(c.isLocked("cosa portare"));
    ASSERT_EQ(1, c.getTotBlocked());
}

TEST(Collection, DefaulConstructorCheck){
    Collection c = Collection("mare");
    ASSERT_EQ("mare", c.getName());
    ASSERT_EQ(0, c.getTotBlocked());
}

TEST(Collection, TotBlockedTest){
    Collection c = Collection("mare");
    c.addNote("cosa portare", "ombrellone, asciugamani");
    c.changeLock("cosa portare");
    ASSERT_EQ(1,c.getTotBlocked());
}

TEST(Collection, findNoteTest){
    Collection c = Collection("mare");
    c.addNote("cosa portare", "ombrellone, asciugamani");
    ASSERT_TRUE(c.findNote("cosa portare"));
}