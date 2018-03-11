/*
 * InputHandler.hpp
 *
 *  Created on: Mar 5, 2018
 *      Author: daniel
 */

#ifndef INPUTHANDLER_HPP_
#define INPUTHANDLER_HPP_

#include <iostream>
#include <thread>
#include <memory>
//#include <ncurses.h>

#include "Input.hpp"
#include "../misc/Player.hpp"

using namespace std;

namespace pixelgames {
namespace input {

class InputHandler {
  public:
    InputHandler(atomic<Input> & player_input)
        : player_input_ { player_input }, the_thread_() {
    }

    ~InputHandler() {
      isRunning_ = false;
      if (the_thread_.joinable()) the_thread_.join();
    }

    void start() {
      isRunning_ = true;
      the_thread_ = std::thread(&InputHandler::ThreadMain, this);
    }

  private:
    atomic<Input>& player_input_;
    thread the_thread_;
    bool isRunning_ = false;

    void ThreadMain() {
      //    	initscr();
      //    	printw("Hi!\n");
      //    	refresh();

      while (isRunning_) {

        char c; // = getchar();
        cin >> c;

        Input action = c == 'w' ? Input::UP : c == 's' ? Input::DOWN : c == 'a' ? Input::LEFT :
                       c == 'd' ? Input::RIGHT : Input::COUNT;

        if(action == Input::COUNT){
          isRunning_ = false;
        }

        player_input_.store(action);

        // Do something useful, e.g:
        //std::this_thread::sleep_for( std::chrono::seconds(1) );
      }
      cout << "Bye!" << endl;
    }
};

} /* namespace input */
} /* namespace pixelgames */

#endif /* INPUTHANDLER_HPP_ */
