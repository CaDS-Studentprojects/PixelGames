/*
 * PixelGame.hpp
 *
 *  Created on: Mar 9, 2018
 *      Author: daniel
 */

#ifndef SRC_PIXELGAME_HPP_
#define SRC_PIXELGAME_HPP_

#include <stdint.h>
#include <memory>
#include <vector>
#include <utility>  // pair
#include "input/IInputHandler.hpp"
#include "output/IOutputHandler.hpp"
#include "misc/Player.hpp"
#include "misc/PlayingField.hpp"
#include "misc/Color.hpp"

using namespace std;
using namespace pixelgames::input;
using namespace pixelgames::output;
using namespace pixelgames::misc;

namespace pixelgames {

class PixelGame {
  public:
    PixelGame(uint32_t const display_columns, uint32_t const display_rows, uint32_t const refresh_rate,
        unique_ptr<IInputHandler> input_handler, unique_ptr<IOutputHandler> output_handler);

    virtual ~PixelGame();

    tuple<bool,Player> registerPlayer();

    void start();

    string toString() const;

    uint32_t const kMaxNumPlayers = 6;

    static vector<Color> const player_colors;
  private:
    bool getPlayerStartParams(Pixel & start_position, Input & initial_input) const;

    uint32_t display_columns_;
    uint32_t display_rows_;
    uint32_t refresh_rate_;
    unique_ptr<IInputHandler> input_handler_;
    unique_ptr<IOutputHandler> output_handler_;

    uint32_t num_players_ = 0;
    vector<Player> players_;
    PlayingField playing_field_;

};

} /* namespace pixelgames */

#endif /* SRC_PIXELGAME_HPP_ */
