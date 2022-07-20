#!/usr/bin/python3

import os
import subprocess

drano_on_config="gargin_drano.cmake"
drano_off_config="gargin_drano_baseline.cmake"

def is_float(text):
    try:
        float(text)
        return True
    except:
        return False

def time_run(use_drano):
    with open("/dev/null", "w") as devnull:
        subprocess.run(['rm build -rf && mkdir build'], stdout=devnull, stderr=devnull, shell=True)
        subprocess.run(['cd build && make -j12'], stdout=devnull, stderr=devnull, shell=True)
    result = subprocess.run('cd build && cmake .. -C../host-configs/{} && /usr/bin/time -f "%U" make -j12'.format(drano_on_config if use_drano else drano_off_config),\
            stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True, executable='/bin/bash')
    if(result.returncode != 0):
        print(result.stderr.decode("utf-8"))
    assert(result.returncode == 0)
    for sample in reversed(result.stderr.decode("utf-8").split('\n')):
        if(is_float(sample)):
            return float(sample)
    assert(False)
    return seconds

class Multirun:
    def __init__(self):
        self.avg_time = None
        self.all_times = list()
    def __str__(self):
        return 'avg: {}, all: {}'.format(self.avg_time, self.all_times)


#TODO helper to average over mutliple runs
def time_over_multple_runs(use_drano, num_runs):
    result = Multirun()
    for iteration in range(num_runs):
        print('run: {}, {}/{}'.format(use_drano, iteration+1, num_runs))
        time = time_run(use_drano)
        result.all_times.append(time)
    result.avg_time = sum(result.all_times) / len(result.all_times)
    return result

#TODO fancy print
num_runs = 10
baseline_result = time_over_multple_runs(False, num_runs)
drano_result = time_over_multple_runs(True, num_runs)
print('baseline_result')
print(baseline_result)
print('drano_result')
print(drano_result)
