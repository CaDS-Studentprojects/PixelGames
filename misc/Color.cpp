/*
 * Color.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: daniel
 */

#include "Color.hpp"

namespace pixelgames {
namespace misc {

Color const Color::black(0, 0, 0);
Color const Color::red(255, 0, 0);
Color const Color::green(0, 255, 0);
Color const Color::blue(0, 0, 255);
Color const Color::yellow(255, 255, 0);
Color const Color::magenta(255, 0, 255);
Color const Color::cyan(0, 255, 255);
Color const Color::white(255, 255, 255);

Color::Color(uint8_t const red, uint8_t const green, uint8_t const blue)
    : red_ { red }, green_ { green }, blue_ { blue } {
}

Color::~Color() {
}

int Color::rbgToInt() const {
  return (red_ << 16 | blue_ << 8 | green_);
}

string Color::toString() const {
  return "Color(" + to_string(red_) + ", " + to_string(green_) + ", " + to_string(blue_) + ")";
}

} /* namespace misc */
} /* namespace pixelgames */

