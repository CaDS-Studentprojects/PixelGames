//============================================================================
// Name        : PixelGames.cpp
// Author      : Daniel
// Version     :
// Copyright   : Your copyright notice
// Description : Pixel Games
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

using namespace pixelgames::input;
using namespace pixelgames::controller;
using namespace pixelgames::output;
using namespace pixelgames::misc;

map<int, atomic<Input>> currect_action;  // shared memory

uint32_t const kNumRows = 16;
uint32_t const kNumColumns = 10;
uint32_t const kRefreshRate = 2;

void game(string output_handler_type) {
  cout << "Pixel Games" << endl << endl;

  unique_ptr<IOutputHandler> output_handler;

  if (output_handler_type.compare("grpc") == 0) {
    output_handler = make_unique<LedOutputHandler>(
        grpc::CreateChannel("raspberryRFID:50051", grpc::InsecureChannelCredentials()), kNumRows, kNumColumns);
    cout << "IOutputHandler : " << "gRPC Handler" << endl;
  } else {
    output_handler = make_unique<FileOutputHandler>("game.log");
    cout << "IOutputHandler : " << "File (Debug) Handler" << endl;
  }

  vector<Player> players;
  players.push_back(Player(1, Pixel(1, 2), Input::RIGHT, Color(255, 0, 0)));
  currect_action[1].store(Input::RIGHT);
  InputHandler input_handler(currect_action[1]);

  PlayingField playing_field(kNumColumns, kNumRows);

  TronGameController game_controller(playing_field, players);

  cout << "Starting game" << endl;

  game_controller.initGame();

  //output_handler << playing_field.getField();

  input_handler.start();

  Input cur_action;
  bool isGameLost = false;
  while ((cur_action = currect_action[1].load()) != Input::QUIT && !isGameLost) {
    printf("cur_action: %d\n", (int) cur_action);
    isGameLost = !game_controller.processInput(players.at(0), cur_action);

    if (!isGameLost) {
      (*output_handler) << playing_field.getField();
      this_thread::sleep_for(std::chrono::seconds(kRefreshRate));
    }
  }

  if (isGameLost) {
    cout << "GAME OVER!" << endl;
  }

  cout << "Good bye!" << endl;
}

void grpc_test_moves(TronGameController & game_controller, LedOutputHandler & output_handler,
    PlayingField & playing_field, Player & player, vector<Input> moves) {
  for (auto move : moves) {
    game_controller.processInput(player, move);
    output_handler << playing_field.getField();
    this_thread::sleep_for(std::chrono::seconds(kRefreshRate));
  }
}

void grpc_test() {
  cout << "Pixel Games" << endl << endl;

  LedOutputHandler output_handler(grpc::CreateChannel("raspberryRFID:50051", grpc::InsecureChannelCredentials()),
      kNumRows, kNumColumns);

  vector<Player> players;
  players.push_back(Player(1, Pixel(1, 2), Input::RIGHT, Color(255, 0, 0)));
  currect_action[1].store(Input::RIGHT);

  PlayingField playing_field(kNumColumns, kNumRows);
  TronGameController game_controller(playing_field, players);

  cout << "Starting grpc_test ..." << endl;

  game_controller.initGame();
  output_handler << playing_field.getField();
  this_thread::sleep_for(std::chrono::seconds(kRefreshRate));

  vector<Input> moves = { Input::RIGHT, Input::RIGHT, Input::DOWN, Input::DOWN, Input::RIGHT, Input::DOWN, Input::DOWN,
      Input::DOWN };
  grpc_test_moves(game_controller, output_handler, playing_field, players.at(0), moves);
}

void test() {
  vector<Player> players;
  players.push_back(Player(1, Pixel(1, 2), Input::RIGHT, Color(255, 0, 0)));
  currect_action[1].store(Input::RIGHT);

  PlayingField playing_field(kNumColumns, kNumRows);

  TronGameController game_controller(playing_field, players);
  game_controller.initGame();
  game_controller.processInput(players.at(0), Input::RIGHT);

  cout << playing_field.toString() << endl;
}

int main() {
  //game("grpc");
  game("");
  //grpc_test();

  //test();

  return 0;
}
