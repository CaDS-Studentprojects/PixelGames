/*
 * IInputHandler.hpp
 *
 *  Created on: Mar 9, 2018
 *      Author: daniel
 */

#ifndef SRC_INPUT_IINPUTHANDLER_HPP_
#define SRC_INPUT_IINPUTHANDLER_HPP_

namespace pixelgames {
namespace input {

class IInputHandler {
  public:
    virtual ~IInputHandler() {}

    virtual void start() = 0;
};

} /* namespace input */
} /* namespace pixelgames */

#endif /* SRC_INPUT_IINPUTHANDLER_HPP_ */
