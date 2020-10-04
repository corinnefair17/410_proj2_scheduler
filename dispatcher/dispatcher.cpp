/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content
#include "../includes/dispatcher.h"
#include "../includes/constants.h"

	PCB Dispatcher::get_from_CPU() {
		if (cpu->get_process_off_core().isEmpty()) {
			return cpu->get_COPY_of_Current_Process();
		}
		PCB *p = new PCB();
		p->reset();

		return *p;
	}

	void Dispatcher::put_on_CPU(PCB &process) {
		cpu->put_process_on_core(process);
	}

	bool Dispatcher::isValidJobOnCPU() {
		return is_valid_job_on_cpu;
	}
