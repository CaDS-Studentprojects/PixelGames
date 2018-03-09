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
    : kNumColumns { numColumns }, kNumRows { numRows }, field(numRows, vector<uint32_t>(numColumns, 0)) {
}

PlayingField::~PlayingField() {
}

void PlayingField::setField(vector<vector<uint32_t>> & field) {

}

void PlayingField::updateField(Pixel const pixel, uint32_t value) {
  field.at(pixel.getRow()).at(pixel.getColumn()) = value;
}

vector<vector<uint32_t>> PlayingField::getField() const {
  return field;
}

string PlayingField::toString() const {
  string s;
  for (auto row : field) {
    for (auto pixel : row) {
      s += to_string(pixel) + " ";
    }
    s = s + "\n";
  }
  return s;
}

string PlayingField::arrayFormattedString() const {
  string s;
  int pixelIdx = 0;
  int lastPixel = kNumRows * kNumColumns - 1;

  for (auto row : field) {
    for (auto pixel : row) {
      if (pixelIdx == lastPixel) {
        s += to_string(pixel);
      } else {
        s += to_string(pixel) + ", ";
        pixelIdx++;
      }
    }
  }
  return s;
}

} /* namespace misc */
} /* namespace pixelgames */
