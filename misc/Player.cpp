/*
 * Player.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: daniel
 */

#include "Player.hpp"

namespace gamectrl {

Player::Player(uint32_t const id, tuple<uint32_t,  uint32_t> const position, Input action, Color color)
	: kId{id}
	, kColor{color}
	, last_input{action}
{
	positions.push_back(position);
}

Player::~Player() {}


void Player::update(tuple<uint32_t, uint32_t> const & pos, Input action)
{
	positions.push_back(pos);
	last_input = action;
}

Input Player::getLastInput() const
{
	return last_input;
}


vector<tuple<uint32_t, uint32_t>> const Player::getPositions() const
{
	return positions;
}

} /* namespace gamectrl */
