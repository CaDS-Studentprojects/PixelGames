/*
 * SnakeGameController.h
 *
 *  Created on: Mar 5, 2018
 *      Author: daniel
 */

#ifndef TRONGAMECONTROLLER_HPP_
#define TRONGAMECONTROLLER_HPP_

#include "../input/Input.hpp"
#include "../misc/PlayingField.hpp"
#include "../misc/Player.hpp"
#include "IGameController.hpp"

using namespace pixelgames::misc;

namespace pixelgames {
namespace controller {

class TronGameController: public IGameController {
  public:
    TronGameController(PlayingField & player_field, vector<Player> & players);

    virtual ~TronGameController();

    void initGame() override;

    bool processInput(Player const & player, Input const input) override;

  private:
    PlayingField & playing_field;
    vector<Player> & players;
};

} /* namespace controller */
} /* namespace pixelgames */

#endif /* TRONGAMECONTROLLER_HPP_ */
