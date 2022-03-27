#ifndef EXPERIMENT_HPP
#define EXPERIMENT_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <tile.hpp>
#include <channel.hpp>
#include <utils.hpp>

// NN definition
// Cluster7 version of 784-10-10

#define NB_NEURON_IL         784
#define NB_NEURON_HL1        10
#define NB_NEURON_OL         10

#define NB_NEURON_HL1_C1     1
#define NB_NEURON_HL1_C2     1
#define NB_NEURON_HL1_C3     1
#define NB_NEURON_HL1_C4     1
#define NB_NEURON_HL1_C5     2
#define NB_NEURON_HL1_C6     2
#define NB_NEURON_HL1_C7     2

#define NB_NEURON_OL_C1      1
#define NB_NEURON_OL_C2      1
#define NB_NEURON_OL_C3      1
#define NB_NEURON_OL_C4      1
#define NB_NEURON_OL_C5      2
#define NB_NEURON_OL_C6      2
#define NB_NEURON_OL_C7      2

// Delay definition
auto DelayHiddenLayer1_1 = DelayVector(NB_NEURON_IL, NB_NEURON_HL1_C1);
auto DelayHiddenLayer1_2 = DelayVector(NB_NEURON_IL, NB_NEURON_HL1_C2);
auto DelayHiddenLayer1_3 = DelayVector(NB_NEURON_IL, NB_NEURON_HL1_C3);
auto DelayHiddenLayer1_4 = DelayVector(NB_NEURON_IL, NB_NEURON_HL1_C4);
auto DelayHiddenLayer1_5 = DelayVector(NB_NEURON_IL, NB_NEURON_HL1_C5);
auto DelayHiddenLayer1_6 = DelayVector(NB_NEURON_IL, NB_NEURON_HL1_C6);
auto DelayHiddenLayer1_7 = DelayVector(NB_NEURON_IL, NB_NEURON_HL1_C7);

auto DelayOutputLayer1   = DelayVector(NB_NEURON_HL1, NB_NEURON_OL_C1);
auto DelayOutputLayer2   = DelayVector(NB_NEURON_HL1, NB_NEURON_OL_C2);
auto DelayOutputLayer3   = DelayVector(NB_NEURON_HL1, NB_NEURON_OL_C3);
auto DelayOutputLayer4   = DelayVector(NB_NEURON_HL1, NB_NEURON_OL_C4);
auto DelayOutputLayer5   = DelayVector(NB_NEURON_HL1, NB_NEURON_OL_C5);
auto DelayOutputLayer6   = DelayVector(NB_NEURON_HL1, NB_NEURON_OL_C6);
auto DelayOutputLayer7   = DelayVector(NB_NEURON_HL1, NB_NEURON_OL_C7);


// Event definition
sc_core::sc_event   write_input1, read_input1,
                    write_input2, read_input2,
                    write_input3, read_input3,
                    write_input4, read_input4,
                    write_input5, read_input5,
                    write_input6, read_input6,
                    write_input7, read_input7,


                    write_hl1_c1_to_out_c1, read_hl1_c1_to_out_c1,
                    write_hl1_c1_to_out_c2, read_hl1_c1_to_out_c2,
                    write_hl1_c1_to_out_c3, read_hl1_c1_to_out_c3,
                    write_hl1_c1_to_out_c4, read_hl1_c1_to_out_c4,
                    write_hl1_c1_to_out_c5, read_hl1_c1_to_out_c5,
                    write_hl1_c1_to_out_c6, read_hl1_c1_to_out_c6,
                    write_hl1_c1_to_out_c7, read_hl1_c1_to_out_c7,

                    write_hl1_c2_to_out_c1, read_hl1_c2_to_out_c1,
                    write_hl1_c2_to_out_c2, read_hl1_c2_to_out_c2,
                    write_hl1_c2_to_out_c3, read_hl1_c2_to_out_c3,
                    write_hl1_c2_to_out_c4, read_hl1_c2_to_out_c4,
                    write_hl1_c2_to_out_c5, read_hl1_c2_to_out_c5,
                    write_hl1_c2_to_out_c6, read_hl1_c2_to_out_c6,
                    write_hl1_c2_to_out_c7, read_hl1_c2_to_out_c7,

                    write_hl1_c3_to_out_c1, read_hl1_c3_to_out_c1,
                    write_hl1_c3_to_out_c2, read_hl1_c3_to_out_c2,
                    write_hl1_c3_to_out_c3, read_hl1_c3_to_out_c3,
                    write_hl1_c3_to_out_c4, read_hl1_c3_to_out_c4,
                    write_hl1_c3_to_out_c5, read_hl1_c3_to_out_c5,
                    write_hl1_c3_to_out_c6, read_hl1_c3_to_out_c6,
                    write_hl1_c3_to_out_c7, read_hl1_c3_to_out_c7,

                    write_hl1_c4_to_out_c1, read_hl1_c4_to_out_c1,
                    write_hl1_c4_to_out_c2, read_hl1_c4_to_out_c2,
                    write_hl1_c4_to_out_c3, read_hl1_c4_to_out_c3,
                    write_hl1_c4_to_out_c4, read_hl1_c4_to_out_c4,
                    write_hl1_c4_to_out_c5, read_hl1_c4_to_out_c5,
                    write_hl1_c4_to_out_c6, read_hl1_c4_to_out_c6,
                    write_hl1_c4_to_out_c7, read_hl1_c4_to_out_c7,

                    write_hl1_c5_to_out_c1, read_hl1_c5_to_out_c1,
                    write_hl1_c5_to_out_c2, read_hl1_c5_to_out_c2,
                    write_hl1_c5_to_out_c3, read_hl1_c5_to_out_c3,
                    write_hl1_c5_to_out_c4, read_hl1_c5_to_out_c4,
                    write_hl1_c5_to_out_c5, read_hl1_c5_to_out_c5,
                    write_hl1_c5_to_out_c6, read_hl1_c5_to_out_c6,
                    write_hl1_c5_to_out_c7, read_hl1_c5_to_out_c7,

                    write_hl1_c6_to_out_c1, read_hl1_c6_to_out_c1,
                    write_hl1_c6_to_out_c2, read_hl1_c6_to_out_c2,
                    write_hl1_c6_to_out_c3, read_hl1_c6_to_out_c3,
                    write_hl1_c6_to_out_c4, read_hl1_c6_to_out_c4,
                    write_hl1_c6_to_out_c5, read_hl1_c6_to_out_c5,
                    write_hl1_c6_to_out_c6, read_hl1_c6_to_out_c6,
                    write_hl1_c6_to_out_c7, read_hl1_c6_to_out_c7,

                    write_hl1_c7_to_out_c1, read_hl1_c7_to_out_c1,
                    write_hl1_c7_to_out_c2, read_hl1_c7_to_out_c2,
                    write_hl1_c7_to_out_c3, read_hl1_c7_to_out_c3,
                    write_hl1_c7_to_out_c4, read_hl1_c7_to_out_c4,
                    write_hl1_c7_to_out_c5, read_hl1_c7_to_out_c5,
                    write_hl1_c7_to_out_c6, read_hl1_c7_to_out_c6,
                    write_hl1_c7_to_out_c7, read_hl1_c7_to_out_c7,


                    write_out_c1_to_decoder, read_out_c1_to_decoder,
                    write_out_c2_to_decoder, read_out_c2_to_decoder,
                    write_out_c3_to_decoder, read_out_c3_to_decoder,
                    write_out_c4_to_decoder, read_out_c4_to_decoder,
                    write_out_c5_to_decoder, read_out_c5_to_decoder,
                    write_out_c6_to_decoder, read_out_c6_to_decoder,
                    write_out_c7_to_decoder, read_out_c7_to_decoder,


                    write_output, read_output;



// Buffer Availability

bool buff_input1 = 1;
bool buff_input2 = 1;
bool buff_input3 = 1;
bool buff_input4 = 1;
bool buff_input5 = 1;
bool buff_input6 = 1;
bool buff_input7 = 1;


bool buff_hl1_c1_to_out_c1 = 1;
bool buff_hl1_c1_to_out_c2 = 1;
bool buff_hl1_c1_to_out_c3 = 1;
bool buff_hl1_c1_to_out_c4 = 1;
bool buff_hl1_c1_to_out_c5 = 1;
bool buff_hl1_c1_to_out_c6 = 1;
bool buff_hl1_c1_to_out_c7 = 1;

bool buff_hl1_c2_to_out_c1 = 1;
bool buff_hl1_c2_to_out_c2 = 1;
bool buff_hl1_c2_to_out_c3 = 1;
bool buff_hl1_c2_to_out_c4 = 1;
bool buff_hl1_c2_to_out_c5 = 1;
bool buff_hl1_c2_to_out_c6 = 1;
bool buff_hl1_c2_to_out_c7 = 1;

bool buff_hl1_c3_to_out_c1 = 1;
bool buff_hl1_c3_to_out_c2 = 1;
bool buff_hl1_c3_to_out_c3 = 1;
bool buff_hl1_c3_to_out_c4 = 1;
bool buff_hl1_c3_to_out_c5 = 1;
bool buff_hl1_c3_to_out_c6 = 1;
bool buff_hl1_c3_to_out_c7 = 1;

bool buff_hl1_c4_to_out_c1 = 1;
bool buff_hl1_c4_to_out_c2 = 1;
bool buff_hl1_c4_to_out_c3 = 1;
bool buff_hl1_c4_to_out_c4 = 1;
bool buff_hl1_c4_to_out_c5 = 1;
bool buff_hl1_c4_to_out_c6 = 1;
bool buff_hl1_c4_to_out_c7 = 1;

bool buff_hl1_c5_to_out_c1 = 1;
bool buff_hl1_c5_to_out_c2 = 1;
bool buff_hl1_c5_to_out_c3 = 1;
bool buff_hl1_c5_to_out_c4 = 1;
bool buff_hl1_c5_to_out_c5 = 1;
bool buff_hl1_c5_to_out_c6 = 1;
bool buff_hl1_c5_to_out_c7 = 1;

bool buff_hl1_c6_to_out_c1 = 1;
bool buff_hl1_c6_to_out_c2 = 1;
bool buff_hl1_c6_to_out_c3 = 1;
bool buff_hl1_c6_to_out_c4 = 1;
bool buff_hl1_c6_to_out_c5 = 1;
bool buff_hl1_c6_to_out_c6 = 1;
bool buff_hl1_c6_to_out_c7 = 1;

bool buff_hl1_c7_to_out_c1 = 1;
bool buff_hl1_c7_to_out_c2 = 1;
bool buff_hl1_c7_to_out_c3 = 1;
bool buff_hl1_c7_to_out_c4 = 1;
bool buff_hl1_c7_to_out_c5 = 1;
bool buff_hl1_c7_to_out_c6 = 1;
bool buff_hl1_c7_to_out_c7 = 1;


bool buff_out_c1_to_decoder = 1;
bool buff_out_c2_to_decoder = 1;
bool buff_out_c3_to_decoder = 1;
bool buff_out_c4_to_decoder = 1;
bool buff_out_c5_to_decoder = 1;
bool buff_out_c6_to_decoder = 1;
bool buff_out_c7_to_decoder = 1;


bool buff_output = 1;


double t_latency = 0;

sc_core::sc_time start[1000000];
sc_core::sc_time stop[1000000];
sc_core::sc_time latency[1000000];



class MB0 : public Tile
{
    public:
        MB0() : Tile(sc_core::sc_module_name("MB0")) {};
    protected:
        void Execute();
};

void MB0::Execute()
{
    for(int i = 0; i < num_iter; i++)
    {
        //Source
#ifdef LATENCY_MODE
        start[i] =  sc_core::sc_time_stamp();
#endif

        //HiddenLayer1_1
        buff_input1 = this->ReadTokens(read_input1, write_input1, buff_input1, 1, NB_NEURON_IL, t_r_loop);
        sc_core::wait(DelayHiddenLayer1_1.GetDelay());
        buff_hl1_c1_to_out_c1 = this->WriteTokens(read_hl1_c1_to_out_c1, write_hl1_c1_to_out_c1, buff_hl1_c1_to_out_c1, 1, NB_NEURON_HL1_C1, t_r_loop);
        buff_hl1_c1_to_out_c2 = this->WriteTokens(read_hl1_c1_to_out_c2, write_hl1_c1_to_out_c2, buff_hl1_c1_to_out_c2, 0, NB_NEURON_HL1_C1, t_r_loop);
        buff_hl1_c1_to_out_c3 = this->WriteTokens(read_hl1_c1_to_out_c3, write_hl1_c1_to_out_c3, buff_hl1_c1_to_out_c3, 0, NB_NEURON_HL1_C1, t_r_loop);
        buff_hl1_c1_to_out_c4 = this->WriteTokens(read_hl1_c1_to_out_c4, write_hl1_c1_to_out_c4, buff_hl1_c1_to_out_c4, 0, NB_NEURON_HL1_C1, t_r_loop);
        buff_hl1_c1_to_out_c5 = this->WriteTokens(read_hl1_c1_to_out_c5, write_hl1_c1_to_out_c5, buff_hl1_c1_to_out_c5, 0, NB_NEURON_HL1_C1, t_r_loop);
        buff_hl1_c1_to_out_c6 = this->WriteTokens(read_hl1_c1_to_out_c6, write_hl1_c1_to_out_c6, buff_hl1_c1_to_out_c6, 0, NB_NEURON_HL1_C1, t_r_loop);
        buff_hl1_c1_to_out_c7 = this->WriteTokens(read_hl1_c1_to_out_c7, write_hl1_c1_to_out_c7, buff_hl1_c1_to_out_c7, 0, NB_NEURON_HL1_C1, t_r_loop);


        //OutputLayer1
        buff_hl1_c1_to_out_c1 = this->ReadTokens(read_hl1_c1_to_out_c1, write_hl1_c1_to_out_c1, buff_hl1_c1_to_out_c1, 1, NB_NEURON_HL1_C1, t_r_loop);
        buff_hl1_c2_to_out_c1 = this->ReadTokens(read_hl1_c2_to_out_c1, write_hl1_c2_to_out_c1, buff_hl1_c2_to_out_c1, 0, NB_NEURON_HL1_C2, t_r_loop);
        buff_hl1_c3_to_out_c1 = this->ReadTokens(read_hl1_c3_to_out_c1, write_hl1_c3_to_out_c1, buff_hl1_c3_to_out_c1, 0, NB_NEURON_HL1_C3, t_r_loop);
        buff_hl1_c4_to_out_c1 = this->ReadTokens(read_hl1_c4_to_out_c1, write_hl1_c4_to_out_c1, buff_hl1_c4_to_out_c1, 0, NB_NEURON_HL1_C4, t_r_loop);
        buff_hl1_c5_to_out_c1 = this->ReadTokens(read_hl1_c5_to_out_c1, write_hl1_c5_to_out_c1, buff_hl1_c5_to_out_c1, 0, NB_NEURON_HL1_C5, t_r_loop);
        buff_hl1_c6_to_out_c1 = this->ReadTokens(read_hl1_c6_to_out_c1, write_hl1_c6_to_out_c1, buff_hl1_c6_to_out_c1, 0, NB_NEURON_HL1_C6, t_r_loop);
        buff_hl1_c7_to_out_c1 = this->ReadTokens(read_hl1_c7_to_out_c1, write_hl1_c7_to_out_c1, buff_hl1_c7_to_out_c1, 0, NB_NEURON_HL1_C7, t_r_loop);
        sc_core::wait(DelayOutputLayer1.GetDelay());
        buff_out_c1_to_decoder = this->WriteTokens(read_out_c1_to_decoder, write_out_c1_to_decoder, buff_out_c1_to_decoder, 1, NB_NEURON_OL_C1, t_r_loop);


        //Decoder
        buff_out_c1_to_decoder = this->ReadTokens(read_out_c1_to_decoder, write_out_c1_to_decoder, buff_out_c1_to_decoder, 1, NB_NEURON_OL_C1, t_r_loop);
        buff_out_c2_to_decoder = this->ReadTokens(read_out_c2_to_decoder, write_out_c2_to_decoder, buff_out_c2_to_decoder, 0, NB_NEURON_OL_C2, t_r_loop);
        buff_out_c3_to_decoder = this->ReadTokens(read_out_c3_to_decoder, write_out_c3_to_decoder, buff_out_c3_to_decoder, 0, NB_NEURON_OL_C3, t_r_loop);
        buff_out_c4_to_decoder = this->ReadTokens(read_out_c4_to_decoder, write_out_c4_to_decoder, buff_out_c4_to_decoder, 0, NB_NEURON_OL_C4, t_r_loop);
        buff_out_c5_to_decoder = this->ReadTokens(read_out_c5_to_decoder, write_out_c5_to_decoder, buff_out_c5_to_decoder, 0, NB_NEURON_OL_C5, t_r_loop);
        buff_out_c6_to_decoder = this->ReadTokens(read_out_c6_to_decoder, write_out_c6_to_decoder, buff_out_c6_to_decoder, 0, NB_NEURON_OL_C6, t_r_loop);
        buff_out_c7_to_decoder = this->ReadTokens(read_out_c7_to_decoder, write_out_c7_to_decoder, buff_out_c7_to_decoder, 0, NB_NEURON_OL_C7, t_r_loop);
        buff_output = this->WriteTokens(read_output, write_output, buff_output, 1, NB_NEURON_OL, t_r_loop);

        //Sink
#ifdef THROUGHPUT_MODE
        stop[i] =  sc_core::sc_time_stamp();
        if(i>=1){
            latency[i] = stop[i] - stop[i-1]; // In cycles
            t_latency =  (double) latency[i].value()/1000;
            std::cout << std::fixed << t_latency << std::endl;
        }
#endif
#ifdef LATENCY_MODE
        stop[i] =  sc_core::sc_time_stamp();
        latency[i] = stop[i] - start[i]; // In cycles
        t_latency =  (double) latency[i].value()/1000;
        std::cout << std::fixed << t_latency << std::endl;
#endif
    }
}


class MB1 : public Tile
{
    public:
        MB1() : Tile(sc_core::sc_module_name("MB1")) {};
    protected:
         void Execute();
};

void MB1::Execute()
{

    for(int i = 0; i < num_iter; i++)
    {
        //HiddenLayer1_2
        buff_input2 = this->ReadTokens(read_input2, write_input2, buff_input2, 1, NB_NEURON_IL, t_r_loop);
        sc_core::wait(DelayHiddenLayer1_2.GetDelay());
        buff_hl1_c2_to_out_c1 = this->WriteTokens(read_hl1_c2_to_out_c1, write_hl1_c2_to_out_c1, buff_hl1_c2_to_out_c1, 0, NB_NEURON_HL1_C2, t_r_loop);
        buff_hl1_c2_to_out_c2 = this->WriteTokens(read_hl1_c2_to_out_c2, write_hl1_c2_to_out_c2, buff_hl1_c2_to_out_c2, 1, NB_NEURON_HL1_C2, t_r_loop);
        buff_hl1_c2_to_out_c3 = this->WriteTokens(read_hl1_c2_to_out_c3, write_hl1_c2_to_out_c3, buff_hl1_c2_to_out_c3, 0, NB_NEURON_HL1_C2, t_r_loop);
        buff_hl1_c2_to_out_c4 = this->WriteTokens(read_hl1_c2_to_out_c4, write_hl1_c2_to_out_c4, buff_hl1_c2_to_out_c4, 0, NB_NEURON_HL1_C2, t_r_loop);
        buff_hl1_c2_to_out_c5 = this->WriteTokens(read_hl1_c2_to_out_c5, write_hl1_c2_to_out_c5, buff_hl1_c2_to_out_c5, 0, NB_NEURON_HL1_C2, t_r_loop);
        buff_hl1_c2_to_out_c6 = this->WriteTokens(read_hl1_c2_to_out_c6, write_hl1_c2_to_out_c6, buff_hl1_c2_to_out_c6, 0, NB_NEURON_HL1_C2, t_r_loop);
        buff_hl1_c2_to_out_c7 = this->WriteTokens(read_hl1_c2_to_out_c7, write_hl1_c2_to_out_c7, buff_hl1_c2_to_out_c7, 0, NB_NEURON_HL1_C2, t_r_loop);

        //OutputLayer2
        buff_hl1_c1_to_out_c2 = this->ReadTokens(read_hl1_c1_to_out_c2, write_hl1_c1_to_out_c2, buff_hl1_c1_to_out_c2, 0, NB_NEURON_HL1_C1, t_r_loop);
        buff_hl1_c2_to_out_c2 = this->ReadTokens(read_hl1_c2_to_out_c2, write_hl1_c2_to_out_c2, buff_hl1_c2_to_out_c2, 1, NB_NEURON_HL1_C2, t_r_loop);
        buff_hl1_c3_to_out_c2 = this->ReadTokens(read_hl1_c3_to_out_c2, write_hl1_c3_to_out_c2, buff_hl1_c3_to_out_c2, 0, NB_NEURON_HL1_C3, t_r_loop);
        buff_hl1_c4_to_out_c2 = this->ReadTokens(read_hl1_c4_to_out_c2, write_hl1_c4_to_out_c2, buff_hl1_c4_to_out_c2, 0, NB_NEURON_HL1_C4, t_r_loop);
        buff_hl1_c5_to_out_c2 = this->ReadTokens(read_hl1_c5_to_out_c2, write_hl1_c5_to_out_c2, buff_hl1_c5_to_out_c2, 0, NB_NEURON_HL1_C5, t_r_loop);
        buff_hl1_c6_to_out_c2 = this->ReadTokens(read_hl1_c6_to_out_c2, write_hl1_c6_to_out_c2, buff_hl1_c6_to_out_c2, 0, NB_NEURON_HL1_C6, t_r_loop);
        buff_hl1_c7_to_out_c2 = this->ReadTokens(read_hl1_c7_to_out_c2, write_hl1_c7_to_out_c2, buff_hl1_c7_to_out_c2, 0, NB_NEURON_HL1_C7, t_r_loop);
        sc_core::wait(DelayOutputLayer2.GetDelay());
        buff_out_c2_to_decoder = this->WriteTokens(read_out_c2_to_decoder, write_out_c2_to_decoder, buff_out_c2_to_decoder, 0, NB_NEURON_OL_C2, t_r_loop);
    }
}

class MB2 : public Tile
{
    public:
        MB2() : Tile(sc_core::sc_module_name("MB2")) {};
    protected:
         void Execute();
};

void MB2::Execute()
{
    for(int i = 0; i < num_iter; i++)
    {
        //HiddenLayer1_3
        buff_input3 = this->ReadTokens(read_input3, write_input3, buff_input3, 1, NB_NEURON_IL, t_r_loop);
        sc_core::wait(DelayHiddenLayer1_3.GetDelay());
        buff_hl1_c3_to_out_c1 = this->WriteTokens(read_hl1_c3_to_out_c1, write_hl1_c3_to_out_c1, buff_hl1_c3_to_out_c1, 0, NB_NEURON_HL1_C3, t_r_loop);
        buff_hl1_c3_to_out_c2 = this->WriteTokens(read_hl1_c3_to_out_c2, write_hl1_c3_to_out_c2, buff_hl1_c3_to_out_c2, 0, NB_NEURON_HL1_C3, t_r_loop);
        buff_hl1_c3_to_out_c3 = this->WriteTokens(read_hl1_c3_to_out_c3, write_hl1_c3_to_out_c3, buff_hl1_c3_to_out_c3, 1, NB_NEURON_HL1_C3, t_r_loop);
        buff_hl1_c3_to_out_c4 = this->WriteTokens(read_hl1_c3_to_out_c4, write_hl1_c3_to_out_c4, buff_hl1_c3_to_out_c4, 0, NB_NEURON_HL1_C3, t_r_loop);
        buff_hl1_c3_to_out_c5 = this->WriteTokens(read_hl1_c3_to_out_c5, write_hl1_c3_to_out_c5, buff_hl1_c3_to_out_c5, 0, NB_NEURON_HL1_C3, t_r_loop);
        buff_hl1_c3_to_out_c6 = this->WriteTokens(read_hl1_c3_to_out_c6, write_hl1_c3_to_out_c6, buff_hl1_c3_to_out_c6, 0, NB_NEURON_HL1_C3, t_r_loop);
        buff_hl1_c3_to_out_c7 = this->WriteTokens(read_hl1_c3_to_out_c7, write_hl1_c3_to_out_c7, buff_hl1_c3_to_out_c7, 0, NB_NEURON_HL1_C3, t_r_loop);

        //OutputLayer3
        buff_hl1_c1_to_out_c3 = this->ReadTokens(read_hl1_c1_to_out_c3, write_hl1_c1_to_out_c3, buff_hl1_c1_to_out_c3, 0, NB_NEURON_HL1_C1, t_r_loop);
        buff_hl1_c2_to_out_c3 = this->ReadTokens(read_hl1_c2_to_out_c3, write_hl1_c2_to_out_c3, buff_hl1_c2_to_out_c3, 0, NB_NEURON_HL1_C2, t_r_loop);
        buff_hl1_c3_to_out_c3 = this->ReadTokens(read_hl1_c3_to_out_c3, write_hl1_c3_to_out_c3, buff_hl1_c3_to_out_c3, 1, NB_NEURON_HL1_C3, t_r_loop);
        buff_hl1_c4_to_out_c3 = this->ReadTokens(read_hl1_c4_to_out_c3, write_hl1_c4_to_out_c3, buff_hl1_c4_to_out_c3, 0, NB_NEURON_HL1_C4, t_r_loop);
        buff_hl1_c5_to_out_c3 = this->ReadTokens(read_hl1_c5_to_out_c3, write_hl1_c5_to_out_c3, buff_hl1_c5_to_out_c3, 0, NB_NEURON_HL1_C5, t_r_loop);
        buff_hl1_c6_to_out_c3 = this->ReadTokens(read_hl1_c6_to_out_c3, write_hl1_c6_to_out_c3, buff_hl1_c6_to_out_c3, 0, NB_NEURON_HL1_C6, t_r_loop);
        buff_hl1_c7_to_out_c3 = this->ReadTokens(read_hl1_c7_to_out_c3, write_hl1_c7_to_out_c3, buff_hl1_c7_to_out_c3, 0, NB_NEURON_HL1_C7, t_r_loop);
        sc_core::wait(DelayOutputLayer3.GetDelay());
        buff_out_c3_to_decoder = this->WriteTokens(read_out_c3_to_decoder, write_out_c3_to_decoder, buff_out_c3_to_decoder, 0, NB_NEURON_OL_C3, t_r_loop);
    }
}

class MB3 : public Tile
{
    public:
        MB3() : Tile(sc_core::sc_module_name("MB3")) {};
    protected:
         void Execute();
};

void MB3::Execute()
{
    for(int i = 0; i < num_iter; i++)
    {
        //HiddenLayer1_4
        buff_input4 = this->ReadTokens(read_input4, write_input4, buff_input4, 1, NB_NEURON_IL, t_r_loop);
        sc_core::wait(DelayHiddenLayer1_4.GetDelay());
        buff_hl1_c4_to_out_c1 = this->WriteTokens(read_hl1_c4_to_out_c1, write_hl1_c4_to_out_c1, buff_hl1_c4_to_out_c1, 0, NB_NEURON_HL1_C4, t_r_loop);
        buff_hl1_c4_to_out_c2 = this->WriteTokens(read_hl1_c4_to_out_c2, write_hl1_c4_to_out_c2, buff_hl1_c4_to_out_c2, 0, NB_NEURON_HL1_C4, t_r_loop);
        buff_hl1_c4_to_out_c3 = this->WriteTokens(read_hl1_c4_to_out_c3, write_hl1_c4_to_out_c3, buff_hl1_c4_to_out_c3, 0, NB_NEURON_HL1_C4, t_r_loop);
        buff_hl1_c4_to_out_c4 = this->WriteTokens(read_hl1_c4_to_out_c4, write_hl1_c4_to_out_c4, buff_hl1_c4_to_out_c4, 1, NB_NEURON_HL1_C4, t_r_loop);
        buff_hl1_c4_to_out_c5 = this->WriteTokens(read_hl1_c4_to_out_c5, write_hl1_c4_to_out_c5, buff_hl1_c4_to_out_c5, 0, NB_NEURON_HL1_C4, t_r_loop);
        buff_hl1_c4_to_out_c6 = this->WriteTokens(read_hl1_c4_to_out_c6, write_hl1_c4_to_out_c6, buff_hl1_c4_to_out_c6, 0, NB_NEURON_HL1_C4, t_r_loop);
        buff_hl1_c4_to_out_c7 = this->WriteTokens(read_hl1_c4_to_out_c7, write_hl1_c4_to_out_c7, buff_hl1_c4_to_out_c7, 0, NB_NEURON_HL1_C4, t_r_loop);

        //OutputLayer4
        buff_hl1_c1_to_out_c4 = this->ReadTokens(read_hl1_c1_to_out_c4, write_hl1_c1_to_out_c4, buff_hl1_c1_to_out_c4, 0, NB_NEURON_HL1_C1, t_r_loop);
        buff_hl1_c2_to_out_c4 = this->ReadTokens(read_hl1_c2_to_out_c4, write_hl1_c2_to_out_c4, buff_hl1_c2_to_out_c4, 0, NB_NEURON_HL1_C2, t_r_loop);
        buff_hl1_c3_to_out_c4 = this->ReadTokens(read_hl1_c3_to_out_c4, write_hl1_c3_to_out_c4, buff_hl1_c3_to_out_c4, 0, NB_NEURON_HL1_C3, t_r_loop);
        buff_hl1_c4_to_out_c4 = this->ReadTokens(read_hl1_c4_to_out_c4, write_hl1_c4_to_out_c4, buff_hl1_c4_to_out_c4, 1, NB_NEURON_HL1_C4, t_r_loop);
        buff_hl1_c5_to_out_c4 = this->ReadTokens(read_hl1_c5_to_out_c4, write_hl1_c5_to_out_c4, buff_hl1_c5_to_out_c4, 0, NB_NEURON_HL1_C5, t_r_loop);
        buff_hl1_c6_to_out_c4 = this->ReadTokens(read_hl1_c6_to_out_c4, write_hl1_c6_to_out_c4, buff_hl1_c6_to_out_c4, 0, NB_NEURON_HL1_C6, t_r_loop);
        buff_hl1_c7_to_out_c4 = this->ReadTokens(read_hl1_c7_to_out_c4, write_hl1_c7_to_out_c4, buff_hl1_c7_to_out_c4, 0, NB_NEURON_HL1_C7, t_r_loop);
        sc_core::wait(DelayOutputLayer4.GetDelay());
        buff_out_c4_to_decoder = this->WriteTokens(read_out_c4_to_decoder, write_out_c4_to_decoder, buff_out_c4_to_decoder, 0, NB_NEURON_OL_C4, t_r_loop);
    }
}

class MB4 : public Tile
{
    public:
        MB4() : Tile(sc_core::sc_module_name("MB4")) {};
    protected:
         void Execute();
};

void MB4::Execute()
{

    for(int i = 0; i < num_iter; i++)
    {
        //HiddenLayer1_5
        buff_input5 = this->ReadTokens(read_input5, write_input5, buff_input5, 1, NB_NEURON_IL, t_r_loop);
        sc_core::wait(DelayHiddenLayer1_5.GetDelay());
        buff_hl1_c5_to_out_c1 = this->WriteTokens(read_hl1_c5_to_out_c1, write_hl1_c5_to_out_c1, buff_hl1_c5_to_out_c1, 0, NB_NEURON_HL1_C5, t_r_loop);
        buff_hl1_c5_to_out_c2 = this->WriteTokens(read_hl1_c5_to_out_c2, write_hl1_c5_to_out_c2, buff_hl1_c5_to_out_c2, 0, NB_NEURON_HL1_C5, t_r_loop);
        buff_hl1_c5_to_out_c3 = this->WriteTokens(read_hl1_c5_to_out_c3, write_hl1_c5_to_out_c3, buff_hl1_c5_to_out_c3, 0, NB_NEURON_HL1_C5, t_r_loop);
        buff_hl1_c5_to_out_c4 = this->WriteTokens(read_hl1_c5_to_out_c4, write_hl1_c5_to_out_c4, buff_hl1_c5_to_out_c4, 0, NB_NEURON_HL1_C5, t_r_loop);
        buff_hl1_c5_to_out_c5 = this->WriteTokens(read_hl1_c5_to_out_c5, write_hl1_c5_to_out_c5, buff_hl1_c5_to_out_c5, 1, NB_NEURON_HL1_C5, t_r_loop);
        buff_hl1_c5_to_out_c6 = this->WriteTokens(read_hl1_c5_to_out_c6, write_hl1_c5_to_out_c6, buff_hl1_c5_to_out_c6, 0, NB_NEURON_HL1_C5, t_r_loop);
        buff_hl1_c5_to_out_c7 = this->WriteTokens(read_hl1_c5_to_out_c7, write_hl1_c5_to_out_c7, buff_hl1_c5_to_out_c7, 0, NB_NEURON_HL1_C5, t_r_loop);

        //OutputLayer5
        buff_hl1_c1_to_out_c5 = this->ReadTokens(read_hl1_c1_to_out_c5, write_hl1_c1_to_out_c5, buff_hl1_c1_to_out_c5, 0, NB_NEURON_HL1_C1, t_r_loop);
        buff_hl1_c2_to_out_c5 = this->ReadTokens(read_hl1_c2_to_out_c5, write_hl1_c2_to_out_c5, buff_hl1_c2_to_out_c5, 0, NB_NEURON_HL1_C2, t_r_loop);
        buff_hl1_c3_to_out_c5 = this->ReadTokens(read_hl1_c3_to_out_c5, write_hl1_c3_to_out_c5, buff_hl1_c3_to_out_c5, 0, NB_NEURON_HL1_C3, t_r_loop);
        buff_hl1_c4_to_out_c5 = this->ReadTokens(read_hl1_c4_to_out_c5, write_hl1_c4_to_out_c5, buff_hl1_c4_to_out_c5, 0, NB_NEURON_HL1_C4, t_r_loop);
        buff_hl1_c5_to_out_c5 = this->ReadTokens(read_hl1_c5_to_out_c5, write_hl1_c5_to_out_c5, buff_hl1_c5_to_out_c5, 1, NB_NEURON_HL1_C5, t_r_loop);
        buff_hl1_c6_to_out_c5 = this->ReadTokens(read_hl1_c6_to_out_c5, write_hl1_c6_to_out_c5, buff_hl1_c6_to_out_c5, 0, NB_NEURON_HL1_C6, t_r_loop);
        buff_hl1_c7_to_out_c5 = this->ReadTokens(read_hl1_c7_to_out_c5, write_hl1_c7_to_out_c5, buff_hl1_c7_to_out_c5, 0, NB_NEURON_HL1_C7, t_r_loop);
        sc_core::wait(DelayOutputLayer5.GetDelay());
        buff_out_c5_to_decoder = this->WriteTokens(read_out_c5_to_decoder, write_out_c5_to_decoder, buff_out_c5_to_decoder, 0, NB_NEURON_OL_C5, t_r_loop);
    }

}

class MB5 : public Tile
{
    public:
        MB5() : Tile(sc_core::sc_module_name("MB5")) {};
    protected:
         void Execute();
};

void MB5::Execute()
{
    for(int i = 0; i < num_iter; i++)
    {
        //HiddenLayer1_6
        buff_input6 = this->ReadTokens(read_input6, write_input6, buff_input6, 1, NB_NEURON_IL, t_r_loop);
        sc_core::wait(DelayHiddenLayer1_6.GetDelay());
        buff_hl1_c6_to_out_c1 = this->WriteTokens(read_hl1_c6_to_out_c1, write_hl1_c6_to_out_c1, buff_hl1_c6_to_out_c1, 0, NB_NEURON_HL1_C6, t_r_loop);
        buff_hl1_c6_to_out_c2 = this->WriteTokens(read_hl1_c6_to_out_c2, write_hl1_c6_to_out_c2, buff_hl1_c6_to_out_c2, 0, NB_NEURON_HL1_C6, t_r_loop);
        buff_hl1_c6_to_out_c3 = this->WriteTokens(read_hl1_c6_to_out_c3, write_hl1_c6_to_out_c3, buff_hl1_c6_to_out_c3, 0, NB_NEURON_HL1_C6, t_r_loop);
        buff_hl1_c6_to_out_c4 = this->WriteTokens(read_hl1_c6_to_out_c4, write_hl1_c6_to_out_c4, buff_hl1_c6_to_out_c4, 0, NB_NEURON_HL1_C6, t_r_loop);
        buff_hl1_c6_to_out_c5 = this->WriteTokens(read_hl1_c6_to_out_c5, write_hl1_c6_to_out_c5, buff_hl1_c6_to_out_c5, 0, NB_NEURON_HL1_C6, t_r_loop);
        buff_hl1_c6_to_out_c6 = this->WriteTokens(read_hl1_c6_to_out_c6, write_hl1_c6_to_out_c6, buff_hl1_c6_to_out_c6, 1, NB_NEURON_HL1_C6, t_r_loop);
        buff_hl1_c6_to_out_c7 = this->WriteTokens(read_hl1_c6_to_out_c7, write_hl1_c6_to_out_c7, buff_hl1_c6_to_out_c7, 0, NB_NEURON_HL1_C6, t_r_loop);

        //OutputLayer6
        buff_hl1_c1_to_out_c6 = this->ReadTokens(read_hl1_c1_to_out_c6, write_hl1_c1_to_out_c6, buff_hl1_c1_to_out_c6, 0, NB_NEURON_HL1_C1, t_r_loop);
        buff_hl1_c2_to_out_c6 = this->ReadTokens(read_hl1_c2_to_out_c6, write_hl1_c2_to_out_c6, buff_hl1_c2_to_out_c6, 0, NB_NEURON_HL1_C2, t_r_loop);
        buff_hl1_c3_to_out_c6 = this->ReadTokens(read_hl1_c3_to_out_c6, write_hl1_c3_to_out_c6, buff_hl1_c3_to_out_c6, 0, NB_NEURON_HL1_C3, t_r_loop);
        buff_hl1_c4_to_out_c6 = this->ReadTokens(read_hl1_c4_to_out_c6, write_hl1_c4_to_out_c6, buff_hl1_c4_to_out_c6, 0, NB_NEURON_HL1_C4, t_r_loop);
        buff_hl1_c5_to_out_c6 = this->ReadTokens(read_hl1_c5_to_out_c6, write_hl1_c5_to_out_c6, buff_hl1_c5_to_out_c6, 0, NB_NEURON_HL1_C5, t_r_loop);
        buff_hl1_c6_to_out_c6 = this->ReadTokens(read_hl1_c6_to_out_c6, write_hl1_c6_to_out_c6, buff_hl1_c6_to_out_c6, 1, NB_NEURON_HL1_C6, t_r_loop);
        buff_hl1_c7_to_out_c6 = this->ReadTokens(read_hl1_c7_to_out_c6, write_hl1_c7_to_out_c6, buff_hl1_c7_to_out_c6, 0, NB_NEURON_HL1_C7, t_r_loop);
        sc_core::wait(DelayOutputLayer6.GetDelay());
        buff_out_c6_to_decoder = this->WriteTokens(read_out_c6_to_decoder, write_out_c6_to_decoder, buff_out_c6_to_decoder, 0, NB_NEURON_OL_C6, t_r_loop);
    }
}

class MB6 : public Tile
{
    public:
        MB6() : Tile(sc_core::sc_module_name("MB6")) {};
    protected:
         void Execute();
};

void MB6::Execute()
{
    for(int i = 0; i < num_iter; i++)
    {
        //HiddenLayer1_7
        buff_input7 = this->ReadTokens(read_input7, write_input7, buff_input7, 1, NB_NEURON_IL, t_r_loop);
        sc_core::wait(DelayHiddenLayer1_7.GetDelay());
        buff_hl1_c7_to_out_c1 = this->WriteTokens(read_hl1_c7_to_out_c1, write_hl1_c7_to_out_c1, buff_hl1_c7_to_out_c1, 0, NB_NEURON_HL1_C7, t_r_loop);
        buff_hl1_c7_to_out_c2 = this->WriteTokens(read_hl1_c7_to_out_c2, write_hl1_c7_to_out_c2, buff_hl1_c7_to_out_c2, 0, NB_NEURON_HL1_C7, t_r_loop);
        buff_hl1_c7_to_out_c3 = this->WriteTokens(read_hl1_c7_to_out_c3, write_hl1_c7_to_out_c3, buff_hl1_c7_to_out_c3, 0, NB_NEURON_HL1_C7, t_r_loop);
        buff_hl1_c7_to_out_c4 = this->WriteTokens(read_hl1_c7_to_out_c4, write_hl1_c7_to_out_c4, buff_hl1_c7_to_out_c4, 0, NB_NEURON_HL1_C7, t_r_loop);
        buff_hl1_c7_to_out_c5 = this->WriteTokens(read_hl1_c7_to_out_c5, write_hl1_c7_to_out_c5, buff_hl1_c7_to_out_c5, 0, NB_NEURON_HL1_C7, t_r_loop);
        buff_hl1_c7_to_out_c6 = this->WriteTokens(read_hl1_c7_to_out_c6, write_hl1_c7_to_out_c6, buff_hl1_c7_to_out_c6, 0, NB_NEURON_HL1_C7, t_r_loop);
        buff_hl1_c7_to_out_c7 = this->WriteTokens(read_hl1_c7_to_out_c7, write_hl1_c7_to_out_c7, buff_hl1_c7_to_out_c7, 1, NB_NEURON_HL1_C7, t_r_loop);

        //OutputLayer7
        buff_hl1_c1_to_out_c7 = this->ReadTokens(read_hl1_c1_to_out_c7, write_hl1_c1_to_out_c7, buff_hl1_c1_to_out_c7, 0, NB_NEURON_HL1_C1, t_r_loop);
        buff_hl1_c2_to_out_c7 = this->ReadTokens(read_hl1_c2_to_out_c7, write_hl1_c2_to_out_c7, buff_hl1_c2_to_out_c7, 0, NB_NEURON_HL1_C2, t_r_loop);
        buff_hl1_c3_to_out_c7 = this->ReadTokens(read_hl1_c3_to_out_c7, write_hl1_c3_to_out_c7, buff_hl1_c3_to_out_c7, 0, NB_NEURON_HL1_C3, t_r_loop);
        buff_hl1_c4_to_out_c7 = this->ReadTokens(read_hl1_c4_to_out_c7, write_hl1_c4_to_out_c7, buff_hl1_c4_to_out_c7, 0, NB_NEURON_HL1_C4, t_r_loop);
        buff_hl1_c5_to_out_c7 = this->ReadTokens(read_hl1_c5_to_out_c7, write_hl1_c5_to_out_c7, buff_hl1_c5_to_out_c7, 0, NB_NEURON_HL1_C5, t_r_loop);
        buff_hl1_c6_to_out_c7 = this->ReadTokens(read_hl1_c6_to_out_c7, write_hl1_c6_to_out_c7, buff_hl1_c6_to_out_c7, 0, NB_NEURON_HL1_C6, t_r_loop);
        buff_hl1_c7_to_out_c7 = this->ReadTokens(read_hl1_c7_to_out_c7, write_hl1_c7_to_out_c7, buff_hl1_c7_to_out_c7, 1, NB_NEURON_HL1_C7, t_r_loop);
        sc_core::wait(DelayOutputLayer7.GetDelay());
        buff_out_c7_to_decoder = this->WriteTokens(read_out_c7_to_decoder, write_out_c7_to_decoder, buff_out_c7_to_decoder, 0, NB_NEURON_OL_C7, t_r_loop);
    }
}

#endif
