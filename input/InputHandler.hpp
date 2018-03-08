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

namespace gamectrl {

class InputHandler {
public:
	InputHandler(atomic<Input> & player_input)
		: player_input{player_input}
		, the_thread()
	{}

    ~InputHandler(){
         isRunning = false;
         if(the_thread.joinable()) the_thread.join();
	}

    void start(){
    	isRunning = true;
    	the_thread = std::thread(&InputHandler::ThreadMain,this);
    }

private:
    atomic<Input>& player_input;
    thread the_thread;
    bool isRunning = false;

    void ThreadMain(){
//    	initscr();
//    	printw("Hi!\n");
//    	refresh();

        while(isRunning){

            char c; // = getchar();
            cin >> c;

            Input action = c == 'w' ? Input::UP
            		: c == 's' ? Input::DOWN
            		: c == 'a' ? Input::LEFT
            		: c == 'd' ? Input::RIGHT
            		: Input::QUIT;

            player_input.store(action);

        	// Do something useful, e.g:
            //std::this_thread::sleep_for( std::chrono::seconds(1) );
        }
        cout << "Bye!" << endl;
    }
};

} /* namespace gamectrl */

#endif /* INPUTHANDLER_HPP_ */
