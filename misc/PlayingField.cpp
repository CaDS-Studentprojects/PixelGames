/*
 * PlayingField.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: daniel
 */

#include "PlayingField.hpp"

namespace gamectrl {

PlayingField::PlayingField(uint32_t const width, uint32_t const height)
	: kWidth{width}
	, kHeight{height}
	, field(height, vector<uint32_t>(width, 0))
{
}

PlayingField::~PlayingField() {}

void PlayingField::setField(vector<vector<uint32_t>> & field){

}

void PlayingField::updateField(uint32_t const row_index, uint32_t const column_index, uint32_t value){
	field.at(row_index).at(column_index) = value;
}

vector<vector<uint32_t>> PlayingField::getField() const {
	return field;
}

string PlayingField::toString() const {
	string s;
	for(auto row: field){
		for(auto pixel: row){
			s += to_string(pixel) + " ";
		}
		s = s + "\n";
	}
	return s;
}

string PlayingField::arrayFormattedString() const {
	string s;
	int pixelIdx = 0;
	int lastPixel = kWidth * kHeight - 1;

	for(auto row: field){
		for(auto pixel: row){
			if(pixelIdx == lastPixel){
				s += to_string(pixel);
			}else{
				s += to_string(pixel) + ", ";
				pixelIdx++;
			}
		}
	}
	return s;
}

} /* namespace gamectrl */
