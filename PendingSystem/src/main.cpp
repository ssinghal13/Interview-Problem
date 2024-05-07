//
// Created by singh on 05-05-2024.
//
#include <vector>

#include "../include/services/TrackingSystem.h"

using namespace std;

int main() {
    TrackingSystem* trackingSystem = new TrackingSystem(3);

    Tag* instrumentTag1 = new Tag("UPI", TagType::INSTRUMENT);
    Tag* instrumentTag2 = new Tag("WALLET", TagType::INSTRUMENT);

    Tag* stateTag1 = new Tag("Karnataka", TagType::STATE);
    Tag* stateTag2 = new Tag("Rajasthan", TagType::STATE);

    Tag* cityTag1 = new Tag("Bangalore", TagType::CITY);
    Tag* cityTag2 = new Tag("MYSORE", TagType::CITY);
    Tag* cityTag3 = new Tag("JAIPUR", TagType::CITY);


    vector<Tag*> tags1 = {instrumentTag1, stateTag1, cityTag1};
    vector<Tag*> tags2 = {instrumentTag1, stateTag1, cityTag2};
    vector<Tag*> tags3 = {instrumentTag1, stateTag2, cityTag3};
    vector<Tag*> tags4 = {instrumentTag2, stateTag1, cityTag1};
    vector<Tag*> tags5 = {instrumentTag2, stateTag1, cityTag1};


    trackingSystem->startTracking(1112, tags1);
    trackingSystem->startTracking(2451, tags2);
    trackingSystem->startTracking(3421, tags3);
    trackingSystem->startTracking(1221, tags4);


    vector<Tag*> getTags1 = {instrumentTag1};
    vector<Tag*> getTags2 = {instrumentTag1, stateTag1};
    vector<Tag*> getTags3 = {instrumentTag1, stateTag1, cityTag1};
    vector<Tag*> getTags4 = {cityTag1};

    trackingSystem->getCounts(getTags1);
    trackingSystem->getCounts(getTags2);
    trackingSystem->getCounts(getTags3);
    trackingSystem->getCounts(getTags4);

    trackingSystem->startTracking(4221, tags5);
    trackingSystem->stopTracking(1112);
    trackingSystem->stopTracking(2451);


    trackingSystem->getCounts(getTags1);
    vector<Tag*> getTags5 = {instrumentTag2};
    trackingSystem->getCounts(getTags5);
    trackingSystem->getCounts(getTags3);

    delete trackingSystem;

    return 0;
}