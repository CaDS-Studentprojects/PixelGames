/*
 * SnakeGameController.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: daniel
 */
#include <iostream>
#include "TronGameController.hpp"

namespace pixelgames {
namespace controller {

TronGameController::TronGameController(PlayingField & player_field, vector<Player> & players)
    : playing_field_ { player_field }, players_ { players } {
}

TronGameController::~TronGameController() {
}

void TronGameController::initGame() {
  for (auto player : players_) {
    auto player_position = player.getPositions().at(0);
    playing_field_.updateField(player.getPositions().at(0), player.getColor().rbgToInt());
  }
}

bool TronGameController::processInput(Player const & player, Input const input) {
  auto cur_action = input;
  auto player_id = player.getId();
  auto last_player_action = player.getLastInput();
  auto player_positions = player.getPositions();
  auto head = player_positions.at(player_positions.size() - 1);
  auto new_head = head;
  bool inputProcessed = false;

  while (!inputProcessed) {
    if (cur_action == Input::UP) {
      if (last_player_action != Input::DOWN) {
        new_head.setRow(new_head.getRow() - 1);
        inputProcessed = true;
      } else {
        cur_action = Input::DOWN;
      }
    } else if (cur_action == Input::DOWN) {
      if (last_player_action != Input::UP) {
        new_head.setRow(new_head.getRow() + 1);
        inputProcessed = true;
      } else {
        cur_action = Input::UP;
      }
    } else if (cur_action == Input::RIGHT) {
      if (last_player_action != Input::LEFT) {
        new_head.setColumn(new_head.getColumn() + 1);
        inputProcessed = true;
      } else {
        cur_action = Input::LEFT;
      }
    } else if (cur_action == Input::LEFT) {
      if (last_player_action != Input::RIGHT) {
        new_head.setColumn(new_head.getColumn() - 1);
        inputProcessed = true;
      } else {
        cur_action = Input::RIGHT;
      }
    }
  }

  cout << "row: " << to_string(new_head.getRow()) << ", column: " << to_string(new_head.getColumn()) << endl;

  if (new_head.getRow() >= playing_field_.kNumRows || new_head.getColumn() >= playing_field_.kNumColumns) {
    // game lost, because player hit wall
    return false;
  } else {
    players_.at(player_id - 1).update(new_head, cur_action);

    auto pixel_value = playing_field_.getField().at(new_head.getRow()).at(new_head.getColumn());

    if (pixel_value > 0) {
      // game lost, because player hit other player
      return false;
    }

    playing_field_.updateField(new_head, player.getColor().rbgToInt());

    return true;
  }
}

} /* namespace controller */
} /* namespace pixelgames */
