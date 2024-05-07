//
// Created by singh on 07-05-2024.
//

#ifndef PENDINGSYSTEM_TAGNODE_H
#define PENDINGSYSTEM_TAGNODE_H

#include <unordered_map>
#include <string>

using namespace std;


class TagNode {
    unordered_map<string, TagNode*> children;
    int count;
public:
    TagNode() {
        this->count = 0;
    }

    const unordered_map<string, TagNode *> &getChildren() const {
        return children;
    }

    void setChildren(const unordered_map<string, TagNode *> &children) {
        TagNode::children = children;
    }

    int getCount() const {
        return count;
    }

    void setCount(int count) {
        TagNode::count = count;
    }

    void addChild(string &tag, TagNode* tagNode) {
        this->children[tag] = tagNode;
    }

    void updateCount (int count) {
        this->count += count;
    }
};

#endif //PENDINGSYSTEM_TAGNODE_H
