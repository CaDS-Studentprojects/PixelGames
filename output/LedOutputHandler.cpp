/*
 * LedOutputHandler.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: daniel
 */

#include "LedOutputHandler.hpp"

namespace pixelgames {
namespace output {

LedOutputHandler::LedOutputHandler(shared_ptr<Channel> channel, uint32_t rows, uint32_t columns)
    : stub_(WS2801_Display::NewStub(channel)), numRows_ { rows }, numColums_ { columns } {
}

LedOutputHandler::~LedOutputHandler() {
}

void LedOutputHandler::operator<<(vector<vector<uint32_t>> const & vect) {
  if (!IOutputHandler::checkDimensions(vect, numRows_, numColums_)) {
    throw length_error(
        "2D-Vector dimensions are invalid. Should be " + to_string(numRows_) + "rows and " + to_string(numColums_)
            + "columns.");
  }

  DISPLAY_MSG request;
  request.set_version(1);
  request.set_typ(1);
  request.set_dim_x(numColums_);
  request.set_dim_y(numRows_);
  request.set_pixel_list(vectToString(vect));

  DISPLAY_RESPONSE response;

  ClientContext context;

  Status status = stub_->DISPLAY_CHANGE(&context, request, &response);

  // Act upon its status.
  if (status.ok()) {
    cout << response.success() << endl;
  } else {
    cout << status.error_code() << ": " << status.error_message() << std::endl;
  }
}

string LedOutputHandler::vectToString(vector<vector<uint32_t>> const & vect) {
  string s;
  int pixelIdx = 0;
  int lastPixel = numRows_ * numColums_ - 1;

  for (uint32_t x = 0; x < numColums_; x++) {
    for (uint32_t y = 0; y < numRows_; y++) {
      if (pixelIdx == lastPixel) {
        s += to_string(vect.at(y).at(x));
      } else {
        s += to_string(vect.at(y).at(x)) + ", ";
        pixelIdx++;
      }
    }
  }
  return s;
}

} /* namespace output */
} /* namespace pixelgames */
