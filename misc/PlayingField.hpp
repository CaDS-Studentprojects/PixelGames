/*
 * PlayingField.hpp
 *
 *  Created on: Mar 5, 2018
 *      Author: daniel
 */

#ifndef PLAYINGFIELD_HPP_
#define PLAYINGFIELD_HPP_

#include <stdint.h>
#include <vector>
#include <string>
#include "Pixel.hpp"

using namespace std;

namespace gamectrl {

class PlayingField {
public:
	PlayingField(uint32_t const numColumns, uint32_t const numRows);
	virtual ~PlayingField();

	uint32_t const kNumColumns;
	uint32_t const kNumRows;

	void setField(vector<vector<uint32_t>> & field);
	void updateField(Pixel const pixel, uint32_t value);

	vector<vector<uint32_t>> getField() const;
	string toString() const;
	string arrayFormattedString() const;

private:
	vector<vector<uint32_t>> field;
};

} /* namespace gamectrl */

#endif /* PLAYINGFIELD_HPP_ */
