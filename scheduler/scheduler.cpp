/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content
#include "../includes/scheduler.h"

	void Scheduler::add(PCB p) {
		ready_q->push(p);
	}

	PCB Scheduler::getNext() {
		return ready_q->front();
	}

	bool Scheduler::isEmpty() {
		return ready_q->size() == 0;
	}

	bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {
		return (&p.remaining_cpu_time <= 0 || (preemptive && tick_count > time_slice));
	}
