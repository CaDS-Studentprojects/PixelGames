/*
 * SnakeGameController.h
 *
 *  Created on: Mar 5, 2018
 *      Author: daniel
 */

#ifndef TRONGAMECONTROLLER_HPP_
#define TRONGAMECONTROLLER_HPP_

#include "IGameController.hpp"
#include "../input/Input.hpp"
#include "../misc/PlayingField.hpp"
#include "../misc/Player.hpp"

namespace gamectrl {

class TronGameController : public IGameController {
public:
	TronGameController(PlayingField & player_field, vector<Player> & players);
	virtual ~TronGameController();

	void initGame() override;
	bool processInput(Player const & player, Input const input) override;

private:
	PlayingField & playing_field;
	vector<Player> & players;
};

} /* namespace gamectrl */

#endif /* TRONGAMECONTROLLER_HPP_ */
