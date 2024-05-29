// Copyright 2024 Savchuk Anton

#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, Constructor) {
    Circle circle(5.0);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 5.0);
}

TEST(CircleTest, SetRadius) {
    Circle circle(5.0);
    circle.setRadius(10.0);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 10.0);
}

TEST(CircleTest, SetFerence) {
    Circle circle(5.0);
    circle.setFerence(20.0);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 20.0);
    EXPECT_NEAR(circle.getRadius(), 3.183098861837907, 0.00001);
}

TEST(CircleTest, SetArea) {
    Circle circle(5.0);
    circle.setArea(78.53981633974483);
    EXPECT_DOUBLE_EQ(circle.getArea(), 78.53981633974483);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 5.0);
}

TEST(CircleTest, ZeroRadius) {
    Circle circle(0.0);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), 0.0);
}

TEST(CircleTest, NegativeRadius) {
    Circle circle(-5.0);
    EXPECT_DOUBLE_EQ(circle.getRadius(), -5.0);
    EXPECT_DOUBLE_EQ(circle.getFerence(), -2 * M_PI * 5.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), M_PI * 5.0 * 5.0);
}

TEST(CircleTest, LargeRadius) {
    Circle circle(1e6);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 1e6);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * M_PI * 1e6);
    EXPECT_DOUBLE_EQ(circle.getArea(), M_PI * 1e6 * 1e6);
}

TEST(TasksTest, ZeroGap) {
    double earthRadius = 6371.0;
    double addedLength = 0.0;
    EXPECT_DOUBLE_EQ(calculateGap(earthRadius, addedLength), 0.0);
}

TEST(TasksTest, CalculateTotalCost) {
    double poolRadius = 5.0;
    double walkwayWidth = 2.0;
    double expectedWalkwayCost = (M_PI * (poolRadius + walkwayWidth)
    * (poolRadius + walkwayWidth) - M_PI * poolRadius * poolRadius) * 1000;
    double expectedFenceCost = (2 * M_PI *
    (poolRadius + walkwayWidth) - 2 * M_PI * poolRadius) * 2000;
    double expectedTotalCost = expectedWalkwayCost + expectedFenceCost;
    EXPECT_DOUBLE_EQ(calculateTotalCost(poolRadius, walkwayWidth)
    , expectedTotalCost);
}

TEST(TasksTest, ZeroCost) {
    double poolRadius = 0.0;
    double walkwayWidth = 0.0;
    EXPECT_DOUBLE_EQ(calculateTotalCost(poolRadius, walkwayWidth), 0.0);
}

TEST(CircleTest, SetAndGetFerence) {
    Circle circle(5.0);
    circle.setFerence(20.0);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 20.0);
}

TEST(CircleTest, SetAndGetArea) {
    Circle circle(5.0);
    circle.setArea(78.53981633974483);
    EXPECT_DOUBLE_EQ(circle.getArea(), 78.53981633974483);
}

TEST(TasksTest, LargeWalkway) {
    double poolRadius = 5.0;
    double walkwayWidth = 1e6;
    double expectedWalkwayCost = (M_PI * (poolRadius + walkwayWidth)
    * (poolRadius + walkwayWidth) - M_PI * poolRadius * poolRadius) * 1000;
    double expectedFenceCost = (2 * M_PI *
    (poolRadius + walkwayWidth) - 2 * M_PI * poolRadius) * 2000;
    double expectedTotalCost = expectedWalkwayCost + expectedFenceCost;
    EXPECT_DOUBLE_EQ(calculateTotalCost(poolRadius, walkwayWidth),
    expectedTotalCost);
}

TEST(CircleTest, UpdateFerenceAfterRadiusChange) {
    Circle circle(5.0);
    circle.setRadius(10.0);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * M_PI * 10.0);
}

TEST(CircleTest, UpdateAreaAfterRadiusChange) {
    Circle circle(5.0);
    circle.setRadius(10.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), M_PI * 10.0 * 10.0);
}

TEST(CircleTest, LargeArea) {
    Circle circle(1e6);
    EXPECT_DOUBLE_EQ(circle.getArea(), M_PI * 1e6 * 1e6);
}

TEST(TasksTest, NonZeroCost) {
    double poolRadius = 10.0;
    double walkwayWidth = 5.0;
    double expectedWalkwayCost = (M_PI * (poolRadius + walkwayWidth)
    * (poolRadius + walkwayWidth) - M_PI * poolRadius * poolRadius) * 1000;
    double expectedFenceCost = (2 * M_PI *
    (poolRadius + walkwayWidth) - 2 * M_PI * poolRadius) * 2000;
    double expectedTotalCost = expectedWalkwayCost + expectedFenceCost;
    EXPECT_DOUBLE_EQ(calculateTotalCost(poolRadius, walkwayWidth),
    expectedTotalCost);
}

TEST(CircleTest, ZeroFerence) {
    Circle circle(0.0);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 0.0);
}

TEST(CircleTest, NegativeFerence) {
    Circle circle(-5.0);
    EXPECT_DOUBLE_EQ(circle.getFerence(), -2 * M_PI * 5.0);
}

TEST(CircleTest, ZeroArea) {
    Circle circle(0.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), 0.0);
}
