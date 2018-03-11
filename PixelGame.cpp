/*
 * PixelGame.cpp
 *
 *  Created on: Mar 9, 2018
 *      Author: daniel
 */

#include <random>
#include <exception>
#include "PixelGame.hpp"
#include "misc/Utility.hpp"

using namespace pixelgames::misc;

namespace pixelgames {

vector<Color> const PixelGame::player_colors = { Color::red, Color::blue, Color::green, Color::yellow, Color::magenta,
    Color::cyan };

PixelGame::PixelGame(uint32_t display_columns, uint32_t display_rows, uint32_t refresh_rate,
    unique_ptr<IInputHandler> input_handler, unique_ptr<IOutputHandler> output_handler)
    : display_columns_ { display_columns }, display_rows_ { display_rows }, refresh_rate_ { refresh_rate }, input_handler_ {
        move(input_handler) }, output_handler_ { move(output_handler) }, players_ { }, playing_field_ { display_columns,
        display_rows } {
}

PixelGame::~PixelGame() {
}

tuple<bool, Player> PixelGame::registerPlayer() {
  bool registrationSuccessful = false;
  Player new_player(0, Pixel(), Input::COUNT, Color::black);

  if (num_players_ >= 6) {
    //throw runtime_error("Cannot register new Player. Max number of players " + to_string(kMaxNumPlayers));
    return {registrationSuccessful, new_player};
  }

  uint32_t player_id = num_players_ + 1;
  Color color = PixelGame::player_colors.at(player_id - 1);
  Pixel start_position;
  Input initial_input;

  registrationSuccessful = getPlayerStartParams(start_position, initial_input);

  if (registrationSuccessful) {
    new_player = Player(player_id, start_position, initial_input, color);
    players_.push_back(new_player);
    num_players_++;
  }

  return {registrationSuccessful, new_player};
}

void PixelGame::start() {
  // not implemented yet!
}

string PixelGame::toString() const {
  return "PixelGame(" + to_string(display_columns_) + ", " + to_string(display_rows_) + ", " + to_string(refresh_rate_)
      + ")";
}

bool PixelGame::getPlayerStartParams(Pixel & start_position, Input & initial_input) const {
  bool startParamsFound = false;
  int numTries = 0;

  PlayingField tmp_playing_field(display_columns_, display_rows_);
  for (auto player : players_) {
    Pixel player_pos = player.getPositions()[0];
    tmp_playing_field.updateField(player_pos, player.getId());
    tmp_playing_field.updateField(Utility::getNextPosition(player_pos, player.getLastInput()), player.getId());
  }

  random_device rd;  //Will be used to obtain a seed for the random number engine
  mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  uniform_int_distribution<> column_dis(0, display_columns_ - 1);
  uniform_int_distribution<> row_dis(0, display_rows_ - 1);
  uniform_int_distribution<> direction_dis(0, (int) Input::COUNT - 1);

  uint32_t initial_column = 0;
  uint32_t initial_row = 0;
  uint32_t initial_direction = 0;

  while (!startParamsFound && numTries < 10) {
    initial_column = column_dis(gen);
    initial_row = row_dis(gen);
    initial_direction = direction_dis(gen);

    startParamsFound = true;

    Pixel init_pos(initial_column, initial_row);
    Pixel next_pos_up = Utility::getNextPosition(Pixel(initial_column, initial_row), Input::UP);
    Pixel next_pos_down = Utility::getNextPosition(Pixel(initial_column, initial_row), Input::DOWN);
    Pixel next_pos_left = Utility::getNextPosition(Pixel(initial_column, initial_row), Input::LEFT);
    Pixel next_pos_right = Utility::getNextPosition(Pixel(initial_column, initial_row), Input::RIGHT);

    if (Utility::isPixelPositionTaken(tmp_playing_field, init_pos)
        || Utility::pixelOutOfRange(next_pos_up, display_columns_, display_rows_)
        || Utility::isPixelPositionTaken(tmp_playing_field, next_pos_up)

        || Utility::pixelOutOfRange(next_pos_down, display_columns_, display_rows_)
        || Utility::isPixelPositionTaken(tmp_playing_field, next_pos_down)

        || Utility::pixelOutOfRange(next_pos_left, display_columns_, display_rows_)
        || Utility::isPixelPositionTaken(tmp_playing_field, next_pos_left)

        || Utility::pixelOutOfRange(next_pos_right, display_columns_, display_rows_)
        || Utility::isPixelPositionTaken(tmp_playing_field, next_pos_right)) {
      startParamsFound = false;
      numTries++;
    }
  }

  if (startParamsFound) {
    start_position.setColumn(initial_column);
    start_position.setRow(initial_row);
    initial_input = Input(initial_direction);
  }

  return startParamsFound;
}

} /* namespace pixelgames */
