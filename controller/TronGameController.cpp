/*
 * SnakeGameController.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: daniel
 */

#include "TronGameController.hpp"

#include <iostream>

namespace gamectrl {

TronGameController::TronGameController(PlayingField & player_field, vector<Player> & players)
	: playing_field{player_field}
	, players{players}
{
	// TODO Auto-generated constructor stub

}

TronGameController::~TronGameController() {
	// TODO Auto-generated destructor stub
}

void TronGameController::initGame(){
	for(auto player : players){
		auto player_position = player.getPositions().at(0);
		playing_field.updateField(get<0>(player_position), get<1>(player_position), player.kColor.getIntValue());
	}
}

bool TronGameController::processInput(Player const & player, Input const input)
{
	auto cur_action = input;
	auto player_id = player.kId;
	auto last_player_action = player.getLastInput();
	auto player_positions = player.getPositions();
	auto head = player_positions.at(player_positions.size()-1);
	auto new_head = head;
	bool inputProcessed = false;

	if(cur_action == Input::QUIT){
		return false;
	}

	while(!inputProcessed){
		if(cur_action == Input::UP){
			if(last_player_action != Input::DOWN){
				get<1>(new_head) -= 1;
				inputProcessed = true;
			}else{
				cur_action = Input::DOWN;
			}
		}else if(cur_action == Input::DOWN){
			if(last_player_action != Input::UP){
				get<1>(new_head) += 1;
				inputProcessed = true;
			}else{
				cur_action = Input::UP;
			}
		}else if(cur_action == Input::RIGHT){
			if(last_player_action != Input::LEFT){
				get<0>(new_head) += 1;
				inputProcessed = true;
			}else{
				cur_action = Input::LEFT;
			}
		}else if(cur_action == Input::LEFT){
			if(last_player_action != Input::RIGHT){
				get<0>(new_head) -= 1;
				inputProcessed = true;
			}else{
				cur_action = Input::RIGHT;
			}
		}
	}

	cout << "column: " << to_string(get<0>(new_head)) << ", row: " << to_string(get<1>(new_head)) << endl;

	if(get<0>(new_head) >= playing_field.kWidth
		|| get<1>(new_head) >= playing_field.kHeight
	){
		// game lost, because player hit wall
		return false;
	}else{
		players.at(player_id-1).update(new_head, cur_action);

		auto pixel_value = playing_field.getField().at(get<0>(new_head)).at(get<1>(new_head));

		if(pixel_value > 0){
			// game lost, because player hit other player
			return false;
		}

		playing_field.updateField(get<0>(new_head), get<1>(new_head), player.kColor.getIntValue());

		return true;
	}
}

} /* namespace gamectrl */
