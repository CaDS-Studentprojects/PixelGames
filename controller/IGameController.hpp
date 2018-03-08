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

namespace gamectrl {

class IGameController {
public:
	virtual ~IGameController(){};

	virtual void initGame() = 0;
	virtual bool processInput(Player const & player, Input const input) = 0;
};

} /* namespace gamectrl */

#endif /* SRC_CONTROLLER_IGAMECONTROLLER_HPP_ */
