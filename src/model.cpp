#include "../include/model.hpp"

Model::Model(float size) {
    this->size = size;
}

void Model::draw() {
    glutSolidCube(size);
}