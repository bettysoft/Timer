//
//  timer.cpp
//
//  Created by Bettysoft on 16.08.15.
//  Copyright © 2015 Bettysoft. All rights reserved.
//

#include "timer.h"


void Bettysoft::Timer::destroy() {
	this->time = 1;
}

void Bettysoft::Timer::pause() {
	this->paused = true;
}

void Bettysoft::Timer::reset() {
	this->time = this->value;
}

void Bettysoft::Timer::resume() {
	this->paused = false;
}

void Bettysoft::Timer::run(Timer *t) {
	std::ostringstream oTimer;
	while (t->time > 0) {
		if (!t->paused){
			oTimer.str("");
			oTimer.clear();
			oTimer << t->time/60 << ":" << std::setw(2) << std::setfill('0') << t->time % 60;
			t->update(oTimer.str());
			t->time--;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	};
	t->update("");
	t->end();
	return;
}

void Bettysoft::Timer::start() {
	std::thread start(Timer::run,this);
	start.detach();
}

Bettysoft::Timer::Timer(std::function<void(const std::string)> update,std::function<void()> end,const unsigned int value) : value(value) {
	this->update = update;
	this->end = end;
	this->paused = false;
	this->time = value;
}
