#define REPORT_DEFINE_GLOBALS

#include <tlm.h>
#include <systemc.h>
#include <cstdlib>

#include <iostream>

#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <sharedmemory.hpp>
#include <bus.hpp>
#include <channel.hpp>
#include <delayvector.hpp>
#include <chrono>
#include <ctime>
#include "monitor.hpp"

int pCount, wCount, rCount;
int num_iter = 100;

sc_core::sc_time readdelay(18, sc_core::SC_NS);  // \_ per token
sc_core::sc_time writedelay(14, sc_core::SC_NS); // /

int startCounter, stopCounter;


// Select&Enable one mode only at a time! Comment the others.
// THROUGHPUT_MODE : END TO END LATENCY
// LATENCY_MODE : START TO END LATENCY - EXECUTION TIME
//
// For detailed trace modes, please rely on the trace enabled scenarios instead (see below)

//~ #define THROUGHPUT_MODE
#define LATENCY_MODE


//
// SCENARIO
// Note: Uncomment the file corresponding to the scenario to evaluate.
//

// Scenario for SAMOS"22 paper, Table 1 (Comparison and validation)

// MNIST T2 - 784-10-10 topology

//~ #include <experiments/mnist_t2/mnist_cluster1_1.hpp>
//~ #include <experiments/mnist_t2/mnist_cluster1_2.hpp>
//~ #include <experiments/mnist_t2/mnist_cluster3_1.hpp>
//~ #include <experiments/mnist_t2/mnist_cluster3_3.hpp>
//~ #include <experiments/mnist_t2/mnist_cluster3_7.hpp>
//~ #include <experiments/mnist_t2/mnist_cluster7_1.hpp>
//~ #include <experiments/mnist_t2/mnist_cluster7_7.hpp>

// MNIST T1 - 784-32-16-10 topology

//~ #include <experiments/mnist_t1/mnist_cluster1_1.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster1_3.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster3_1.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster3_3.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster3_7.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster7_1.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster7_7.hpp>

// MNIST T2 - 784-10-10 topology

//~ #include <experiments/mnist_t2_trace/mnist_cluster1_1.hpp>
//~ #include <experiments/mnist_t2_trace/mnist_cluster1_2.hpp>
//~ #include <experiments/mnist_t2_trace/mnist_cluster3_1.hpp>
//~ #include <experiments/mnist_t2_trace/mnist_cluster3_3.hpp>
//~ #include <experiments/mnist_t2_trace/mnist_cluster3_7.hpp>
//~ #include <experiments/mnist_t2_trace/mnist_cluster7_1.hpp>
#include <experiments/mnist_t2_trace/mnist_cluster7_7.hpp>

// MNIST T1 - 784-32-16-10 topology

//~ #include <experiments/mnist_t1_trace/mnist_cluster1_1.hpp>
//~ #include <experiments/mnist_t1_trace/mnist_cluster1_3.hpp>
//~ #include <experiments/mnist_t1_trace/mnist_cluster3_1.hpp>
//~ #include <experiments/mnist_t1_trace/mnist_cluster3_3.hpp>
//~ #include <experiments/mnist_t1_trace/mnist_cluster3_7.hpp>
//~ #include <experiments/mnist_t1_trace/mnist_cluster7_1.hpp>
//~ #include <experiments/mnist_t1_trace/mnist_cluster7_7.hpp>


// Misc
//
//~ #include <experiments/mnist_t1/mnist_cluster1_1.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster1_1_trace.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster1_2_paral.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster1_3_paral.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster1_2_stream.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster1_3.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster1_4_stream.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster1_5_stream.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster2_1.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster2_2.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster2_2_stream.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster2_3_stream.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster2_4_stream.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster2_4_stream_other.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster2_5_stream.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster2_6_stream.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster2_2_trace.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster3_1.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster3_1_stream.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster3_1_trace.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster3_2.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster3_3.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster3_3_stream.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster3_3_trace.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster3_4.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster3_4_stream.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster3_5_stream.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster3_5_stream_config2.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster3_6.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster3_7.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster4_1.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster4_2.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster4_3.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster4_4.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster4_4_trace.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster4_6.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster5_1.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster5_2.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster5_3.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster5_4.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster5_5.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster6_1.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster6_2.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster6_3.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster6_4.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster6_5.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster6_6.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster6_7.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster7_1_trace.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster7_1.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster7_2.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster7_3.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster7_4.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster7_5.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster7_6.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster7_7.hpp>
//~ #include <experiments/mnist_t1/mnist_cluster7_7_trace.hpp>







int sc_main(int argc, char *argv[])
{
    auto begin = std::chrono::system_clock::now();
    // Create Architecture Components
    MB0 mb0;
    MB1 mb1;
    MB2 mb2;
    MB3 mb3;
    MB4 mb4;
    MB5 mb5;
    MB6 mb6;

    SharedMemory sharedmemory("SharedMemory", 0x1000, 32*1024,
            readdelay, writedelay);
    Bus bus("AXIBus");

    // Build Architecture
    bus << mb0;
    bus << mb1;
    bus << mb2;
    bus << mb3;
    bus << mb4;
    bus << mb5;
    bus << mb6;
    bus << sharedmemory;

    // Initialize simulation
    std::srand(0); // 0 is the seed - this is not very random but OK in this case

    // Start simulation
    //~ mon_observer* obs = local_observer::createInstance(1,  &mb0);
    sc_core::sc_start();

    //~ auto end = std::chrono::system_clock::now();

    //~ std::chrono::duration<double> elapsed_seconds = end-begin;
    //~ std::time_t begin_time = std::chrono::system_clock::to_time_t(begin);
    //~ std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    //~ std::cout << "Start Simulation at " << std::ctime(&begin_time);
    //~ std::cout << "End Simulation at " << std::ctime(&end_time)
              //~ << "Simulation time: " << elapsed_seconds.count() << "s\n";
    return 0;
}

