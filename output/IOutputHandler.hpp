/*
 * IOutputHandler.hpp
 *
 *  Created on: Mar 7, 2018
 *      Author: daniel
 */

#ifndef IOUTPUTHANDLER_HPP_
#define IOUTPUTHANDLER_HPP_

#include <vector>
#include <stdint.h>

using namespace std;

class IOutputHandler
{
	public:
		virtual ~IOutputHandler(){};
		virtual void operator<<(vector<vector<uint32_t>> const & vect) = 0;

		template <typename T>
		static bool checkDimensions(vector<vector<T>> const & vect, uint32_t display_height, uint32_t display_width)
		{
			bool correctDimensions = true;
			if(vect.size() != display_height){ correctDimensions = false; }

			for(auto row : vect){
				if (row.size() != display_width){
					correctDimensions = false;
				}
			}

			return correctDimensions;
		}
};

#endif /* IOUTPUTHANDLER_HPP_ */
