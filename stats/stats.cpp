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
		}

		av_response_time = total_response_times / vec->size();
		av_turnaround_time = total_turnaround_times / vec->size();
		av_wait_time = total_wait_times / vec->size();
	}
