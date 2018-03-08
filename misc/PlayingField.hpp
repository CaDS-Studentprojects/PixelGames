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

using namespace std;

namespace gamectrl {

class PlayingField {
public:
	PlayingField(uint32_t const width, uint32_t const height);
	virtual ~PlayingField();

	uint32_t const kWidth;
	uint32_t const kHeight;

	void setField(vector<vector<uint32_t>> & field);
	void updateField(uint32_t const column_index, uint32_t const row_index, uint32_t value);

	vector<vector<uint32_t>> getField() const;
	string toString() const;
	string arrayFormattedString() const;

private:
	vector<vector<uint32_t>> field;
};

} /* namespace gamectrl */

#endif /* PLAYINGFIELD_HPP_ */
