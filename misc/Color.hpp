/*
 * Color.hpp
 *
 *  Created on: Mar 7, 2018
 *      Author: daniel
 */

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <stdint.h>

namespace pixelgames {
namespace misc {

class Color {
  public:
    Color(uint8_t const red, uint8_t const green, uint8_t const blue)
        : kRed { red }, kGreen { green }, kBlue { blue } {
    }

    virtual ~Color() {
    }

    int getIntValue() const {
      return (kRed << 16 | kBlue << 8 | kGreen);
    }

    uint8_t const kRed;
    uint8_t const kGreen;
    uint8_t const kBlue;
};

} /* namespace misc */
} /* namespace pixelgames */

#endif /* COLOR_HPP_ */
