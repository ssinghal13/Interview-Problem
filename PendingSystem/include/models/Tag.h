//
// Created by singh on 07-05-2024.
//

#ifndef PENDINGSYSTEM_TAG_H
#define PENDINGSYSTEM_TAG_H

#include <string>

using namespace std;

enum class TagType {
    INSTRUMENT,
    STATE,
    CITY
};

class Tag {
    string tagValue;
    TagType tagType;
public:
    Tag(const string &tagValue, TagType tagType) : tagValue(tagValue), tagType(tagType) {}

    const string &getTagValue() const {
        return tagValue;
    }

    void setTagValue(const string &tagValue) {
        Tag::tagValue = tagValue;
    }

    TagType getTagType() const {
        return tagType;
    }

    void setTagType(TagType tagType) {
        Tag::tagType = tagType;
    }
};

#endif //PENDINGSYSTEM_TAG_H
