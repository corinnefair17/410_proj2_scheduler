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
		calcStats();
	}

	void Stats::showAllProcessInfo() {
		if (vec->size() <= 0) {
			return;
		}

		for (unsigned int i = 0; i < vec->size(); i++) {
			std::cout << "Process " << i << " Required CPU time: " << vec->at(i).required_cpu_time << " start time: "
					<< vec->at(i).start_time << " finished: " << vec->at(i).finish_time << std::endl;
		}
	}

	float Stats::get_av_response_time() {
		return av_response_time;
	}

	float Stats::get_av_turnaround_time() {
		return av_turnaround_time;
	}

	float Stats::get_av_wait_time() {
		calcStats();
		return av_wait_time;
	}

	void Stats::calcStats() {
		float total_response_times = 0.0;
		float total_turnaround_times = 0.0;
		float total_wait_times = 0.0;

		for (PCB p : *vec) {
			total_response_times += (p.start_time - p.arrival_time);
			total_turnaround_times += (p.finish_time - p.arrival_time);
			total_wait_times += (p.finish_time - p.arrival_time - p.required_cpu_time);
			//std::cout << total_response_times << std::endl;
			//std::cout << ", " << std::endl;
			//std::cout << total_turnaround_times << std::endl;
			//std::cout << ", " << std::endl;
			//std::cout << total_wait_times << std::endl;
		}

		av_response_time = total_response_times / vec->size();
		av_turnaround_time = total_turnaround_times / vec->size();
		av_wait_time = total_wait_times / vec->size();
	}
