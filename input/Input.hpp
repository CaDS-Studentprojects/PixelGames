/*
 * Input.hpp
 *
 *  Created on: Mar 5, 2018
 *      Author: daniel
 */

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include <stdint.h>

namespace pixelgames {
namespace input {

enum class Input
  : uint32_t {QUIT, UP, RIGHT, DOWN, LEFT
};

} /* namespace input */
} /* namespace pixelgames */

#endif /* INPUT_HPP_ */
