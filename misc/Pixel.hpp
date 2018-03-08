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
	Pixel(uint32_t row, uint32_t column)
		: pixel_position(row, column){};

	virtual ~Pixel(){};

	uint32_t getRow() const {
		return get<0>(pixel_position);
	}

	uint32_t getColumn() const {
		return get<1>(pixel_position);
	}

	void setRow(uint32_t val) {
		get<0>(pixel_position) = val;
	}

	void setColumn(uint32_t val) {
		get<1>(pixel_position) = val;
	}

private:
	tuple<uint32_t,uint32_t> pixel_position;
};


#endif /* SRC_PIXEL_HPP_ */
