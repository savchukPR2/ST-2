// Copyright 2024 Savchuk Anton

#include "tasks.h"
#include "circle.h"

double calculateGap(double earthRadius, double addedLength) {
    Circle earth(earthRadius);
    double originalFerence = earth.getFerence();
    earth.setFerence(originalFerence + addedLength);
    double newRadius = earth.getRadius();
    return newRadius - earthRadius;
}

double calculateTotalCost(double poolRadius, double walkwayWidth) {
    Circle pool(poolRadius);
    Circle poolWithWalkway(poolRadius + walkwayWidth);
    double poolArea = pool.getArea();
    double poolWithWalkwayArea = poolWithWalkway.getArea();
    double walkwayArea = poolWithWalkwayArea - poolArea;
    double walkwayCost = walkwayArea * 1000;
    double poolFerence = pool.getFerence();
    double poolWithWalkwayFerence = poolWithWalkway.getFerence();
    double fenceLength = poolWithWalkwayFerence - poolFerence;
    double fenceCost = fenceLength * 2000;
    return walkwayCost + fenceCost;
}
