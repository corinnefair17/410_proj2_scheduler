/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

//TODO fill in content
#include "../includes/scheduler_SRTF.h"
#include <algorithm>

	bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
		sort();
		return Scheduler::time_to_switch_processes(tick_count, p);
	}

	bool sort_cpu(PCB i, PCB j) {
		return (i.remaining_cpu_time < j.remaining_cpu_time);
	}

	void Scheduler_SRTF::sort() {
		preemptive = true;
		std::vector<PCB> v;

		while (!ready_q->empty()) {
			v.push_back(ready_q->front());
			ready_q->pop();
		}

		std::sort(v.begin(), v.end(), sort_cpu);

		for (unsigned int i = 0; i < v.size(); i++) {
			ready_q->push(v.at(i));
		}
	}
