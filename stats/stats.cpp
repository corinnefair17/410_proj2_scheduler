/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

//TODO fill in content
#include "../includes/stats.h"

	Stats::Stats(std::vector<PCB> &finished_vector):
		vec(&finished_vector) {
		av_response_time = -1.0;
		av_turnaround_time = -1.0;
		av_wait_time = 1.0;
	}

	void Stats::showAllProcessInfo() {
		for (unsigned int i = 0; i < vec->size(); i++) {
			std::cout << &vec[i] << std::endl;
		}
	}

	float Stats::get_av_response_time() {
		return -1.0;
	}

	float Stats::get_av_turnaround_time() {
		return -1.0;
	}

	float Stats::get_av_wait_time() {
		return -1.0;
	}
