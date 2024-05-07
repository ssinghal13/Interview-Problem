//
// Created by singh on 07-05-2024.
//

#ifndef PENDINGSYSTEM_ENTITY_H
#define PENDINGSYSTEM_ENTITY_H
#include <vector>

#include "Tag.h"

using namespace std;

class Entity {
    int id;
    vector<Tag*> tags;
public:
    Entity(int id, const vector<Tag *> &tags) : id(id), tags(tags) {}

    int getId() const {
        return id;
    }

    void setId(int id) {
        Entity::id = id;
    }

    const vector<Tag *> &getTags() const {
        return tags;
    }

    void setTags(const vector<Tag *> &tags) {
        Entity::tags = tags;
    }
};

#endif //PENDINGSYSTEM_ENTITY_H
