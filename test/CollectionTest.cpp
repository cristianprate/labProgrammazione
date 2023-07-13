//
// Created by prate on 13/07/2023.
//

#include "gtest/gtest.h"
#include "../Collection.h"

TEST(Collection, LockCheck){
    Collection c = Collection("mare", new Application());
    c.getNotes().emplace_back("cosa portare", "ombrellone, asciugamani");
    ASSERT_FALSE(c.isLocked("cosa portare"));
    c.changeLock("cosa portare");
    ASSERT_TRUE(c.isLocked("cosa portare"));
}

TEST(Collection, DefaulConstructorCheck){
    Collection c = Collection("mare", new Application());
    ASSERT_EQ("mare", c.getName());
}