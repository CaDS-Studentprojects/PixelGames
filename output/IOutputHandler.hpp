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

namespace pixelgames {
namespace output {

class IOutputHandler {
  public:
    virtual ~IOutputHandler() {
    }
    ;
    virtual void operator<<(vector<vector<uint32_t>> const & vect) = 0;

    template<typename T>
    static bool checkDimensions(vector<vector<T>> const & vect, uint32_t numRows, uint32_t numColumns) {
      bool correctDimensions = true;
      if (vect.size() != numRows) {
        correctDimensions = false;
      }

      for (auto row : vect) {
        if (row.size() != numColumns) {
          correctDimensions = false;
        }
      }

      return correctDimensions;
    }
};

} /* namespace output */
} /* namespace pixelgames */

#endif /* IOUTPUTHANDLER_HPP_ */
