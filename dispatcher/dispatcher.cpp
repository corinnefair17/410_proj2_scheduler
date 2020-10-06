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
		PCB p = cpu->get_process_off_core();

		is_valid_job_on_cpu = p.process_number == UNINITIALIZED;

		return p;
	}

	void Dispatcher::put_on_CPU(PCB &process) {
		cpu->get_process_off_core();
		cpu->put_process_on_core(process);
		is_valid_job_on_cpu = true;
	}

	bool Dispatcher::isValidJobOnCPU() {
		return is_valid_job_on_cpu;
	}
