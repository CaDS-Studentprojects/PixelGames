/*
 * PlayingField.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: daniel
 */

#include "PlayingField.hpp"

namespace pixelgames {
namespace misc {

PlayingField::PlayingField(uint32_t const numColumns, uint32_t const numRows)
    : kNumColumns { numColumns }, kNumRows { numRows }, field_(numRows, vector<uint32_t>(numColumns, 0)) {
}

PlayingField::~PlayingField() {
}

void PlayingField::setField(vector<vector<uint32_t>> & field) {

}

void PlayingField::updateField(Pixel const pixel, uint32_t value) {
  field_.at(pixel.getRow()).at(pixel.getColumn()) = value;
}

vector<vector<uint32_t>> PlayingField::getField() const {
  return field_;
}

string PlayingField::toString() const {
  return "PlayingField(" + to_string(kNumColumns) + ", " + to_string(kNumRows) + ")";
}

string PlayingField::prettyPrint() const {
  string s;
    for (auto row : field_) {
      for (auto pixel : row) {
        s += to_string(pixel) + " ";
      }
      s = s + "\n";
    }
    return s;
}

} /* namespace misc */
} /* namespace pixelgames */
