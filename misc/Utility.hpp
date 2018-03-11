/*
 * Utility.hpp
 *
 *  Created on: Mar 9, 2018
 *      Author: daniel
 */

#ifndef SRC_MISC_UTILITY_HPP_
#define SRC_MISC_UTILITY_HPP_

#include "../input/Input.hpp"
#include "Pixel.hpp"

using namespace pixelgames::input;


namespace pixelgames {
namespace misc {

class Utility {
  public:
    static Pixel getNextPosition(Pixel const & cur_position, Input const input){
      Pixel new_position;

      new_position.setColumn(
          cur_position.getColumn() + (input == Input::LEFT ? (-1) : input == Input::RIGHT ? 1 : 0)
      );

      new_position.setRow(
          cur_position.getRow() + (input == Input::UP ? (-1) : input == Input::DOWN ? 1 : 0)
      );

      return new_position;
    }

    static bool pixelOutOfRange(Pixel const & pixel, uint32_t const display_columns, uint32_t const display_rows){
      return (pixel.getColumn() >= display_columns || pixel.getRow() >= display_rows);
    }

    static bool isPixelPositionTaken(PlayingField const & playing_field, Pixel const & pos) {
      if(Utility::pixelOutOfRange(pos, playing_field.kNumColumns, playing_field.kNumRows))
        throw out_of_range(pos.toString() + " position out of range, range is " + playing_field.toString());

      return playing_field.getField()[pos.getRow()][pos.getColumn()] > 0;
    }
  private:
    Utility();
};

} /* namespace misc */
} /* namespace pixelgames */




#endif /* SRC_MISC_UTILITY_HPP_ */
