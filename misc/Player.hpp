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

using namespace std;

namespace gamectrl {

class Player {
public:
	Player(uint32_t const id, tuple<uint32_t, uint32_t> const position, Input action, Color color);
	virtual ~Player();

	void update(tuple<uint32_t, uint32_t> const & pos, Input action);
	void setCurrentAction(Input action);

	Input getCurrentAction() const;
	Input getLastInput() const;
	vector<tuple<uint32_t, uint32_t>> const getPositions() const;

	uint32_t const kId;
	Color const kColor;
private:
	Input last_input;
	vector<tuple<uint32_t, uint32_t>> positions;
};

} /* namespace gamectrl */

#endif /* PLAYER_HPP_ */
