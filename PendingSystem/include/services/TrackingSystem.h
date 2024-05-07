//
// Created by singh on 07-05-2024.
//

#ifndef PENDINGSYSTEM_TRACKINGSYSTEM_H
#define PENDINGSYSTEM_TRACKINGSYSTEM_H

#include <vector>
#include <stdexcept>
#include "iostream"

#include "../models/Entity.h"
#include "../models/Tag.h"
#include "../models/TagNode.h"

using namespace std;

class TrackingSystem {
    unordered_map<int, Entity*> idToEntity;
    TagNode* root;
    int tagsLength;

    void freeNodes(TagNode* root) {
        if(!root) {
            return;
        }
        for(auto &child : root->getChildren()) {
            freeNodes(child.second);
        }
        delete root;
    }
public:
    TrackingSystem(int tagsLength) {
        this->tagsLength = tagsLength;
        root = new TagNode();
    }

    virtual ~TrackingSystem() {
        freeNodes(root);
    }

    void startTracking(int id, vector<Tag*> &tags) {
        try {
            if(idToEntity.find(id) != idToEntity.end()) {
                throw runtime_error("Invalid ID");
                return;
            }
            if(tags.size() != tagsLength) {
                return;
            }
            Entity* entity = new Entity(id, tags);
            idToEntity[id] = entity;
            TagNode* current = root;
            for(auto tag : tags) {
                auto children = current->getChildren();
                auto tagValue = tag->getTagValue();
                if((children).find(tagValue) != children.end()) {
                    current = (children).at(tagValue);
                    current->updateCount(1);
                } else {
                    TagNode* node = new TagNode();
                    current->addChild(tagValue, node);
                    current = node;
                    current->updateCount(1);
                }
            }
            cout << "Started Tracking for ID " << id << endl;
        } catch (exception &e) {
            cerr << "Error" << e.what();
        }
    }
    void stopTracking(int id) {
        try {
            if(idToEntity.find(id) == idToEntity.end()) { // Changed condition to check for invalid ID
                throw runtime_error("Invalid ID");
            }
            // If ID is valid, proceed with stopping tracking
            TagNode* current = root;
            Entity* entity = idToEntity[id];
            for(auto tag : entity->getTags()) {
                auto tagValue = tag->getTagValue();
                // also check later if tag type is similar to hierarchical tags
                current = (current->getChildren()).at(tagValue);
                current->updateCount(-1);
            }
            idToEntity.erase(id);
            cout << "Stopped Tracking for ID " << id << endl;
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl; // Added a space after "Error:"
        }
    }
    void getCounts(vector<Tag*> tags) {
        try {
            if(tags.size() > tagsLength) {
                throw runtime_error("Tag Length exceeds the alloted length");
            }
            int count = 0;
            TagNode* current = root;
            for(auto tag : tags) {
                auto tagValue = tag->getTagValue();
                if(current->getChildren().find(tagValue) == current->getChildren().end()) {
                    return; // Invalid tags
                }
                current = current->getChildren().at(tagValue);
                count = current->getCount();
            }
            cout << "Count is " << count << endl;
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl; // Added a space after "Error:"
        }
    }

};

#endif //PENDINGSYSTEM_TRACKINGSYSTEM_H
