/*
 Problem:
 You are given a set of boxes {b1, ..., bn}. Each box bj has an
 associated length lj, width wj and height hj. You wish to create
 the highest possible stack of boxes with the constraint that
 if box bi is stacked on box bj , the 2D base of bi is larger in
 both dimensions than the base of bj . You can of course, rotate
 the boxes to decide which face is the base, but you can use each
 box only once.
 */

// Solution using Backtracking

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct Box {
    int length;
    int width;
    int height;

    Box(int length, int width, int height): length(length), width(width), height(height){}

    bool operator<(const Box &other) const {
        return this->length < other.length && this->width < other.width;
    }

    bool operator==(const Box &other) const {
        return this->length == other.length && this->width == other.width && this->height == other.height;
    }
};

Box configureBase(const Box &box) {
    auto tempBox = box;
    if (box.length < box.width)
        swap(tempBox.length, tempBox.width);
    return tempBox;
}

vector<Box> getRotationOf(const Box &box) {
    vector<Box> result;
    auto tempBox = box;
    result.push_back(configureBase(tempBox));
    swap(tempBox.length, tempBox.height);
    result.push_back(configureBase(tempBox));
    swap(tempBox.width, tempBox.height);
    result.push_back(configureBase(tempBox));
    return result;
}

pair<int, vector<Box> > placeBoxesOn(const Box &baseBox, deque<Box> restOfBoxes) {
    int height = 0;
    vector<Box> boxStackAboveBase;
    if (restOfBoxes.empty()) {
        return make_pair(height, boxStackAboveBase);
    }
    Box base = restOfBoxes.front();
    bool isAnyBoxPlacedOnBase = false;
    for (int i = 0; i < restOfBoxes.size(); i++) {
        Box box = restOfBoxes.front();
        restOfBoxes.pop_front();
        auto boxRoations = getRotationOf(box);
        for (auto rotatatedBox: boxRoations) {
            if (rotatatedBox < baseBox) {
                isAnyBoxPlacedOnBase = true;
                auto result = placeBoxesOn(rotatatedBox, restOfBoxes);
                if (height < result.first + rotatatedBox.height) {
                    height = result.first + rotatatedBox.height;
                    boxStackAboveBase = result.second;
                    base = rotatatedBox;
                }
            }
        }
        restOfBoxes.push_back(box);
    }
    if (isAnyBoxPlacedOnBase)
        boxStackAboveBase.push_back(base);
    return make_pair(height, boxStackAboveBase);
}

pair<int, vector<Box> > getMaxHeight(const vector<Box> &givenBoxes) {
    vector<Box> boxStack;
    int height = 0;
    if (givenBoxes.empty()) return make_pair(height, boxStack);
    deque<Box> boxes(givenBoxes.begin(), givenBoxes.end());
    Box base = boxes.front();
        // try to make every box as stack's base and choose the one with max height
    for (int i = 0; i < boxes.size(); i++) {
        Box baseBox = boxes.front();
        boxes.pop_front();
        auto boxRoations = getRotationOf(baseBox);
        for (auto rotatatedBox: boxRoations) {
            auto result = placeBoxesOn(rotatatedBox, boxes);
            if (height < result.first + rotatatedBox.height) {
                height = result.first + rotatatedBox.height;
                base = rotatatedBox;
                boxStack = result.second;
            }
        }
        boxes.push_back(baseBox);
    }
    boxStack.push_back(base);
    return make_pair(height, boxStack);
}

void printStack(const vector<Box> &boxes) {
    for (auto box: boxes)
        cout << box.length << " x " << box.width << " x " << box.height << endl;
}

int main() {
    vector<Box> givenBoxes = {
        Box(4,4,1),
        Box(1,2,3),
        Box(4,6,7),
        Box(1,2,3),
        Box(4,5,6),
        Box(10,12,32)
    };
    auto result = getMaxHeight(givenBoxes);
    cout << "Stack Height: " << result.first << endl;
    cout << "Stack looks like as below" << endl;
    printStack(result.second);
}
