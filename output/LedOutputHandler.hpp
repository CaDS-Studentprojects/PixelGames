/*
 * LedOutputHandler.hpp
 *
 *  Created on: Mar 7, 2018
 *      Author: daniel
 */

#ifndef SRC_OUTPUT_LEDOUTPUTHANDLER_HPP_
#define SRC_OUTPUT_LEDOUTPUTHANDLER_HPP_

#include <memory>
#include <string>
#include <grpc++/grpc++.h>
#include "grpc/display_server.grpc.pb.h"
#include "IOutputHandler.hpp"

using namespace std;

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using LED_display::DISPLAY_MSG;
using LED_display::DISPLAY_RESPONSE;
using LED_display::WS2801_Display;

class LedOutputHandler: public IOutputHandler {
public:
	LedOutputHandler(shared_ptr<Channel> channel, uint32_t rows, uint32_t columns);
	virtual ~LedOutputHandler();

	void operator<<(vector<vector<uint32_t>> const & vect) override;

	string vectToString(vector<vector<uint32_t>> const & vect);
private:
	unique_ptr<WS2801_Display::Stub> stub;
	uint32_t const kNumRows;
	uint32_t const kNumColums;
};

#endif /* SRC_OUTPUT_LEDOUTPUTHANDLER_HPP_ */
