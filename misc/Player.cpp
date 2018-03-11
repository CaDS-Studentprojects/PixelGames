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
    : id_ { id }, color_ { color }, last_input_ { action } {
  positions_.push_back(position);
}

Player::~Player() {
}

void Player::update(Pixel const & pos, Input action) {
  positions_.push_back(pos);
  last_input_ = action;
}

uint32_t Player::getId() const {
  return id_;
}

Color Player::getColor() const {
  return color_;
}

Input Player::getLastInput() const {
  return last_input_;
}

vector<Pixel> const Player::getPositions() const {
  return positions_;
}

string Player::toString() const {
  string posStr = "Positions : [";
  for(unsigned int i = 0; i < positions_.size(); i++)
    posStr += positions_[i].toString() + (i == positions_.size() - 1 ? "" : ", ");
  posStr += "]";

  return "Player(" + to_string(id_) + ", " + posStr + ", " + to_string((uint32_t)getLastInput()) + ", " + color_.toString() + ")";
}

} /* namespace misc */
} /* namespace pixelgames */
