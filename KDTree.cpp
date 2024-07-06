#include "KDTree.h"
#include <algorithm>
#include <iostream>

KDTree::KDNode::KDNode(const std::vector<float> &pt) : point(pt), left(nullptr), right(nullptr) {}

KDTree::KDTree() : root(nullptr) {}

KDTree::~KDTree() {
    clear(root);
}

void KDTree::clear(KDNode* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

bool KDTree::arePointsEqual(const std::vector<float> &point1, const std::vector<float> &point2) {
    for (size_t i = 0; i < point1.size(); ++i) {
        if (point1[i] != point2[i])
            return false;
    }
    return true;
}

KDTree::KDNode* KDTree::insertRec(KDNode* node, const std::vector<float> &point, unsigned depth) {

}

void KDTree::insert(const std::vector<float> &point) {

}

KDTree::KDNode* KDTree::findMinRec(KDNode* node, unsigned dim, unsigned depth) {

}

KDTree::KDNode* KDTree::deleteRec(KDNode* node, const std::vector<float> &point, unsigned depth) {

}

void KDTree::deletePoint(const std::vector<float> &point) {
    root = deleteRec(root, point, 0);
}
