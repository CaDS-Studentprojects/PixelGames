/*
 * Player.hpp
 *
 *  Created on: Mar 5, 2018
 *      Author: daniel
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <vector>
#include <tuple>

#include "../input/Input.hpp"
#include "Color.hpp"
#include "Pixel.hpp"

using namespace std;
using namespace pixelgames::input;

namespace pixelgames {
namespace misc {

class Player {
  public:
    Player(uint32_t const id, Pixel const position, Input action, Color color);

    virtual ~Player();

    void update(Pixel const & pos, Input action);

    void setCurrentAction(Input action);

    uint32_t getId() const;

    Color getColor() const;

    Input getCurrentAction() const;

    Input getLastInput() const;

    vector<Pixel> const getPositions() const;

    string toString() const;

  private:
    uint32_t id_;
    Color color_;
    Input last_input_;
    vector<Pixel> positions_;
};

} /* namespace misc */
} /* namespace pixelgames */

#endif /* PLAYER_HPP_ */
