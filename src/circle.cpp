// Copyright 2024 Savchuk Anton

#include "circle.h"
#include <cmath>

Circle::Circle(double radius) {
    setRadius(radius);
}

void Circle::setRadius(double radius) {
    this->radius = radius;
    updateFerence();
    updateArea();
}

void Circle::setFerence(double ference) {
    this->ference = ference;
    radius = ference / (2 * M_PI);
    updateArea();
}

void Circle::setArea(double area) {
    this->area = area;
    radius = sqrt(area / M_PI);
    updateFerence();
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}

void Circle::updateFerence() {
    ference = 2 * M_PI * radius;
}

void Circle::updateArea() {
    area = M_PI * radius * radius;
}
