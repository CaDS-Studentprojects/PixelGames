/*
 * Pixel.hpp
 *
 *  Created on: Mar 7, 2018
 *      Author: daniel
 */

#ifndef SRC_PIXEL_HPP_
#define SRC_PIXEL_HPP_

#include <stdint.h>
#include <tuple>

using namespace std;

class Pixel {
public:
	Pixel(uint32_t column_idx, uint32_t row_idx)
		: pixel_position(column_idx, row_idx){};

	virtual ~Pixel(){};

	uint32_t getColumn() const {
		return get<0>(pixel_position);
	}

	uint32_t getRow() const {
		return get<1>(pixel_position);
	}

	void setColumn(uint32_t val) {
		get<0>(pixel_position) = val;
	}

	void setRow(uint32_t val) {
		get<1>(pixel_position) = val;
	}

private:
	tuple<uint32_t,uint32_t> pixel_position;
};


#endif /* SRC_PIXEL_HPP_ */
