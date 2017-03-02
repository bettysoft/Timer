//
//  timer.h
//
//  Created by Bettysoft on 16.08.15.
//  Copyright © 2015 Bettysoft. All rights reserved.
//

#ifndef H_TIMER
#define H_TIMER

#include <chrono>
#include <functional>
#include <iomanip>
#include <sstream>
#include <thread>


namespace Bettysoft{

class Timer{
private:
	const unsigned int value;
	unsigned int time;
	bool paused;
	std::function<void(const std::string)> update;
	std::function<void()> end;

	static void run(Timer *t);
public:
	void destroy();
	void pause();
	void reset();
	void resume();
	void start();

	Timer(std::function<void(const std::string)> update,std::function<void()> end,const unsigned int value = 300);
};

}

#endif