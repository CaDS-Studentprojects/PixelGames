/*
 * Player.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: daniel
 */

#include "Player.hpp"

namespace pixelgames {
namespace misc {

Player::Player(uint32_t const id, Pixel const position, Input action, Color color)
    : kId { id }, kColor { color }, last_input { action } {
  positions.push_back(position);
}

Player::~Player() {
}

void Player::update(Pixel const & pos, Input action) {
  positions.push_back(pos);
  last_input = action;
}

Input Player::getLastInput() const {
  return last_input;
}

vector<Pixel> const Player::getPositions() const {
  return positions;
}

} /* namespace misc */
} /* namespace pixelgames */
