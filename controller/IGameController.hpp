/*
 * IGameController.hpp
 *
 *  Created on: Mar 7, 2018
 *      Author: daniel
 */

#ifndef SRC_CONTROLLER_IGAMECONTROLLER_HPP_
#define SRC_CONTROLLER_IGAMECONTROLLER_HPP_

#include <stdint.h>
#include "../input/Input.hpp"
#include "../misc/Player.hpp"

using namespace pixelgames::misc;

namespace pixelgames {
namespace controller {

class IGameController {
  public:
    virtual ~IGameController() {
    }
    ;

    virtual void initGame() = 0;
    virtual bool processInput(Player const & player, Input const input) = 0;
};

} /* namespace controller */
} /* namespace pixelgames */

#endif /* SRC_CONTROLLER_IGAMECONTROLLER_HPP_ */
