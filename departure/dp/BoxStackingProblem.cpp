/*
 Problem:
 You are given a set of boxes {b1, ..., bn}. Each box bj has an
 associated length lj, width wj and height hj. You wish to create
 the highest possible stack of boxes with the constraint that
 if box bi is stacked on box bj , the 2D base of bi is larger in
 both dimensions than the base of bj . You can of course, rotate
 the boxes to decide which face is the base, and you can use
 multiple instances of a box.
 */
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct Box {
    int length;
    int width;
    int height;

    Box(int length, int width, int height): length(length), width(width), height(height){}

    int area() const {
        return length * width;
    }

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

vector<Box> buildLis(const vector<Box> &array, const vector<int> &parent, int endIndex) {
    int index = endIndex;
    vector<Box> lis;
    while (parent[index] != index) {
        lis.push_back(array[index]);
        index = parent[index];
    }
    lis.push_back(array[index]);
    return lis;
}

pair<int, vector<Box> > getMaxPossibleHeight(const vector<Box> &boxes) {
    vector<int> possibleHeights(boxes.size());
    vector<int> parent(boxes.size());
    for (int i = 0; i < boxes.size(); i++) {
        possibleHeights[i] = boxes[i].height;
        parent[i] = i;
    }
    // implement lis
    pair<int, int> maxHeight = {0,0};
    for (int i = 1 ; i < boxes.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (boxes[i] < boxes[j] && possibleHeights[i] < possibleHeights[j] + boxes[i].height) {
                possibleHeights[i] = possibleHeights[j] + boxes[i].height;
                parent[i] = j;
            }
            if (maxHeight.first < possibleHeights[i]) {
                maxHeight = {possibleHeights[i], i};
            }
        }
    }
    return {maxHeight.first, buildLis(boxes, parent, maxHeight.second)};
}

pair<int, vector<Box> > getMaxHeight(const vector<Box> &givenBoxes) {
    vector<Box> boxes;
    for (auto box: givenBoxes) {
        auto rotatedBoxes = getRotationOf(box);
        boxes.insert(boxes.end(), rotatedBoxes.begin(), rotatedBoxes.end());
    }
    sort(boxes.begin(), boxes.end(),[](const Box &box1, const Box &box2) -> bool const{
        return box1.area() > box2.area();
    });
    return getMaxPossibleHeight(boxes);
}

void printBoxStack(const vector<Box> &boxes) {
    for (auto box: boxes)
        cout << box.length << " x " << box.width << " x " << box.height << endl;
}

int main() {
    vector<Box> givenBoxes = {
        Box(4, 6, 7),
        Box(1, 2, 3),
        Box(4, 5, 6),
        Box(10, 12, 32)
    };
    auto result = getMaxHeight(givenBoxes);
    cout << "Stack Height: " << result.first << endl;
    cout << "Stack looks like as below:" << endl;
    printBoxStack(result.second);
}
