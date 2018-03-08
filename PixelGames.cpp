//============================================================================
// Name        : PixelGames.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include <atomic>
#include <chrono>
#include <stdint.h>

#include "controller/TronGameController.hpp"
#include "input/InputHandler.hpp"
#include "misc/Player.hpp"
#include "misc/PlayingField.hpp"
#include "output/IOutputHandler.hpp"
#include "output/FileOutputHandler.hpp"
#include "output/LedOutputHandler.hpp"

using namespace std;
using namespace gamectrl;

map<int,atomic<Input>> currect_action;  // shared memory

uint32_t const kWidth = 16;
uint32_t const kHeight = 10;
uint32_t const kRefreshRate = 2;

void game(){
	cout << "Pixel Games" << endl << endl;

	unique_ptr<IOutputHandler> output_handler = make_unique<FileOutputHandler>("game.log");

	vector<Player> players;
	players.push_back(Player(1, tuple<int32_t,int32_t>(1,2), Input::RIGHT, Color(255,0,0)));
	currect_action[1].store(Input::RIGHT);
	InputHandler input_handler(currect_action[1]);

	PlayingField playing_field(kWidth,kHeight);
	TronGameController game_controller(playing_field, players);

	cout << "Starting game" << endl;

	game_controller.initGame();
	cout << "arrayFormattedString: " << playing_field.arrayFormattedString() << endl;

	(*output_handler) << playing_field.getField();

	input_handler.start();

	Input cur_action;
	bool isGameLost = false;
	while((cur_action = currect_action[1].load()) != Input::QUIT && !isGameLost){
		printf("cur_action: %d\n", (int)cur_action);
		isGameLost = !game_controller.processInput(players.at(0), cur_action);
		(*output_handler) << playing_field.getField();

		this_thread::sleep_for(std::chrono::seconds(kRefreshRate));
	}

	cout << "Good bye!" << endl;
}

void grpc_test_moves(
	TronGameController & game_controller,
	LedOutputHandler & output_handler,
	PlayingField & playing_field,
	Player & player,
	vector<Input> moves)
{
	for(auto move : moves){
		game_controller.processInput(player, move);
		output_handler << playing_field.getField();
		this_thread::sleep_for(std::chrono::seconds(kRefreshRate));
	}
}

void grpc_test(){
	cout << "Pixel Games" << endl << endl;

	LedOutputHandler output_handler(
		grpc::CreateChannel("raspberryRFID:50051", grpc::InsecureChannelCredentials())
		, kWidth
		, kHeight
	);

	vector<Player> players;
	players.push_back(Player(1, tuple<int32_t,int32_t>(1,2), Input::RIGHT, Color(255,0,0)));
	currect_action[1].store(Input::RIGHT);

	PlayingField playing_field(kWidth,kHeight);
	TronGameController game_controller(playing_field, players);

	cout << "Starting grpc_test ..." << endl;

	game_controller.initGame();
	output_handler << playing_field.getField();
	this_thread::sleep_for(std::chrono::seconds(kRefreshRate));

	vector<Input> moves = {Input::RIGHT, Input::RIGHT, Input::DOWN, Input::DOWN, Input::RIGHT};
	grpc_test_moves(game_controller, output_handler, playing_field, players.at(0), moves);
}

int main() {
	//game();
	grpc_test();

	return 0;
}
