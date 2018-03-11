/*
 * Color.hpp
 *
 *  Created on: Mar 7, 2018
 *      Author: daniel
 */

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <stdint.h>
#include <string>

using namespace std;

namespace pixelgames {
namespace misc {

class Color {
  public:
    Color(uint8_t const red, uint8_t const green, uint8_t const blue);

    virtual ~Color();

    int rbgToInt() const;

    string toString() const;

    /* Predefined Colors */
    static Color const black;
    static Color const red;
    static Color const green;
    static Color const blue;
    static Color const yellow;
    static Color const magenta;
    static Color const cyan;
    static Color const white;

  private:
    uint8_t red_;
    uint8_t green_;
    uint8_t blue_;
};

} /* namespace misc */
} /* namespace pixelgames */

#endif /* COLOR_HPP_ */
