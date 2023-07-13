//
// Created by prate on 13/07/2023.
//

#include "gtest/gtest.h"
#include "../Collection.h"

class CollectionSuite : public ::testing::Test{
protected:
    virtual void SetUp(){
        c.getNotes().emplace_back("cosa portare", "ombrellone, asciugamani");
    }

    Collection c = Collection("mare", new Application());
};

TEST_F(CollectionSuite, TestIsLocked) {
    ASSERT_EQ(false, c.isLocked("cosa portare"));
}


