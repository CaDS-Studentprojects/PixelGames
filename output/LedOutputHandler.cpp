/*
 * LedOutputHandler.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: daniel
 */

#include "LedOutputHandler.hpp"

LedOutputHandler::LedOutputHandler(shared_ptr<Channel> channel, uint32_t display_width, uint32_t display_height)
	: stub(WS2801_Display::NewStub(channel))
	, display_width{display_width}
	, display_height{display_height}
{}

LedOutputHandler::~LedOutputHandler()
{}

void LedOutputHandler::operator<<(vector<vector<uint32_t>> const & vect)
{
	if(! IOutputHandler::checkDimensions(vect, display_height, display_width)){
		throw length_error("2D-Vector dimensions are invalid. Should be "
				+ to_string(display_height) + "x"
				+ to_string(display_width) + ".");
	}

	DISPLAY_MSG request;
	request.set_version(1);
	request.set_typ(1);
	request.set_dim_x(display_width);
	request.set_dim_y(display_height);
	request.set_pixel_list(vectToString(vect));

	DISPLAY_RESPONSE response;

	ClientContext context;

	Status status = stub->DISPLAY_CHANGE(&context, request, &response);

	// Act upon its status.
	if (status.ok()) {
	  cout << response.success() << endl;
	} else {
	  cout << status.error_code() << ": " << status.error_message()
		   << std::endl;
	}
}

string LedOutputHandler::vectToString(vector<vector<uint32_t>> const & vect)
{
	string s;
		int pixelIdx = 0;
		int lastPixel = display_width * display_height - 1;

		for(auto row: vect){
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

