#ifndef EXPERIMENT_HPP
#define EXPERIMENT_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <tile.hpp>
#include <channel.hpp>
#include <utils.hpp>

// Network config:  IL - HL1 - OL
//                 784 - 10  - 10

#define IL_NB 784

#define HL1_NB 10
#define HL1_HI 4
#define HL1_LO 3

#define OL_NB 10
#define OL_HI 4
#define OL_LO 3


// Delay definition
auto DelayHiddenLayer1_1 = DelayVector(IL_NB, HL1_LO);
auto DelayHiddenLayer1_2 = DelayVector(IL_NB, HL1_LO);
auto DelayHiddenLayer1_3 = DelayVector(IL_NB, HL1_HI);

auto DelayOutputLayer1  = DelayVector(HL1_NB,  OL_LO);
auto DelayOutputLayer2  = DelayVector(HL1_NB,  OL_LO);
auto DelayOutputLayer3  = DelayVector(HL1_NB,  OL_HI);


// Event definition
sc_core::sc_event   write_input1, read_input1,
                    write_input2, read_input2,
                    write_input3, read_input3,


                    write_hl1_c1_to_out_c1, read_hl1_c1_to_out_c1,
                    write_hl1_c1_to_out_c2, read_hl1_c1_to_out_c2,
                    write_hl1_c1_to_out_c3, read_hl1_c1_to_out_c3,

                    write_hl1_c2_to_out_c1, read_hl1_c2_to_out_c1,
                    write_hl1_c2_to_out_c2, read_hl1_c2_to_out_c2,
                    write_hl1_c2_to_out_c3, read_hl1_c2_to_out_c3,

                    write_hl1_c3_to_out_c1, read_hl1_c3_to_out_c1,
                    write_hl1_c3_to_out_c2, read_hl1_c3_to_out_c2,
                    write_hl1_c3_to_out_c3, read_hl1_c3_to_out_c3,


                    write_out_c1_to_decoder, read_out_c1_to_decoder,
                    write_out_c2_to_decoder, read_out_c2_to_decoder,
                    write_out_c3_to_decoder, read_out_c3_to_decoder,


                    write_output, read_output;



// Buffer Availability

bool buff_input1 = 1;
bool buff_input2 = 1;
bool buff_input3 = 1;


bool buff_hl1_c1_to_out_c1 = 1;
bool buff_hl1_c1_to_out_c2 = 1;
bool buff_hl1_c1_to_out_c3 = 1;

bool buff_hl1_c2_to_out_c1 = 1;
bool buff_hl1_c2_to_out_c2 = 1;
bool buff_hl1_c2_to_out_c3 = 1;

bool buff_hl1_c3_to_out_c1 = 1;
bool buff_hl1_c3_to_out_c2 = 1;
bool buff_hl1_c3_to_out_c3 = 1;


bool buff_out_c1_to_decoder = 1;
bool buff_out_c2_to_decoder = 1;
bool buff_out_c3_to_decoder = 1;


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
        buff_input1 = this->ReadTokens(read_input1, write_input1, buff_input1, 1, IL_NB, t_r_loop);
        sc_core::wait(DelayHiddenLayer1_1.GetDelay());
        buff_hl1_c1_to_out_c1 = this->WriteTokens(read_hl1_c1_to_out_c1, write_hl1_c1_to_out_c1, buff_hl1_c1_to_out_c1, 0, HL1_LO, t_r_loop);
        buff_hl1_c1_to_out_c2 = this->WriteTokens(read_hl1_c1_to_out_c2, write_hl1_c1_to_out_c2, buff_hl1_c1_to_out_c2, 0, HL1_LO, t_r_loop);
        buff_hl1_c1_to_out_c3 = this->WriteTokens(read_hl1_c1_to_out_c3, write_hl1_c1_to_out_c3, buff_hl1_c1_to_out_c3, 0, HL1_LO, t_r_loop);


        //OutputLayer1
        buff_hl1_c1_to_out_c1 = this->ReadTokens(read_hl1_c1_to_out_c1, write_hl1_c1_to_out_c1, buff_hl1_c1_to_out_c1, 0, HL1_LO, t_r_loop);
        buff_hl1_c2_to_out_c1 = this->ReadTokens(read_hl1_c2_to_out_c1, write_hl1_c2_to_out_c1, buff_hl1_c2_to_out_c1, 0, HL1_LO, t_r_loop);
        buff_hl1_c3_to_out_c1 = this->ReadTokens(read_hl1_c3_to_out_c1, write_hl1_c3_to_out_c1, buff_hl1_c3_to_out_c1, 0, HL1_HI, t_r_loop);
        sc_core::wait(DelayOutputLayer1.GetDelay());
        buff_out_c1_to_decoder = this->WriteTokens(read_out_c1_to_decoder, write_out_c1_to_decoder, buff_out_c1_to_decoder, 0, OL_LO, t_r_loop);


        //Decoder
        buff_out_c1_to_decoder = this->ReadTokens(read_out_c1_to_decoder, write_out_c1_to_decoder, buff_out_c1_to_decoder, 0, OL_LO, t_r_loop);
        buff_out_c2_to_decoder = this->ReadTokens(read_out_c2_to_decoder, write_out_c2_to_decoder, buff_out_c2_to_decoder, 0, OL_LO, t_r_loop);
        buff_out_c3_to_decoder = this->ReadTokens(read_out_c3_to_decoder, write_out_c3_to_decoder, buff_out_c3_to_decoder, 0, OL_HI, t_r_loop);
        buff_output = this->WriteTokens(read_output, write_output, buff_output, 1, OL_NB, t_r_loop);

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
        buff_input2 = this->ReadTokens(read_input2, write_input2, buff_input2, 1, IL_NB, t_r_loop);
        sc_core::wait(DelayHiddenLayer1_2.GetDelay());
        buff_hl1_c2_to_out_c1 = this->WriteTokens(read_hl1_c2_to_out_c1, write_hl1_c2_to_out_c1, buff_hl1_c2_to_out_c1, 0, HL1_LO, t_r_loop);
        buff_hl1_c2_to_out_c2 = this->WriteTokens(read_hl1_c2_to_out_c2, write_hl1_c2_to_out_c2, buff_hl1_c2_to_out_c2, 0, HL1_LO, t_r_loop);
        buff_hl1_c2_to_out_c3 = this->WriteTokens(read_hl1_c2_to_out_c3, write_hl1_c2_to_out_c3, buff_hl1_c2_to_out_c3, 0, HL1_LO, t_r_loop);

        //OutputLayer2
        buff_hl1_c1_to_out_c2 = this->ReadTokens(read_hl1_c1_to_out_c2, write_hl1_c1_to_out_c2, buff_hl1_c1_to_out_c2, 0, HL1_LO, t_r_loop);
        buff_hl1_c2_to_out_c2 = this->ReadTokens(read_hl1_c2_to_out_c2, write_hl1_c2_to_out_c2, buff_hl1_c2_to_out_c2, 0, HL1_LO, t_r_loop);
        buff_hl1_c3_to_out_c2 = this->ReadTokens(read_hl1_c3_to_out_c2, write_hl1_c3_to_out_c2, buff_hl1_c3_to_out_c2, 0, HL1_HI, t_r_loop);
        sc_core::wait(DelayOutputLayer2.GetDelay());
        buff_out_c2_to_decoder = this->WriteTokens(read_out_c2_to_decoder, write_out_c2_to_decoder, buff_out_c2_to_decoder, 0, OL_LO, t_r_loop);


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
        buff_input3 = this->ReadTokens(read_input3, write_input3, buff_input3, 1, IL_NB, t_r_loop);
        sc_core::wait(DelayHiddenLayer1_3.GetDelay());
        buff_hl1_c3_to_out_c1 = this->WriteTokens(read_hl1_c3_to_out_c1, write_hl1_c3_to_out_c1, buff_hl1_c3_to_out_c1, 0, HL1_HI, t_r_loop);
        buff_hl1_c3_to_out_c2 = this->WriteTokens(read_hl1_c3_to_out_c2, write_hl1_c3_to_out_c2, buff_hl1_c3_to_out_c2, 0, HL1_HI, t_r_loop);
        buff_hl1_c3_to_out_c3 = this->WriteTokens(read_hl1_c3_to_out_c3, write_hl1_c3_to_out_c3, buff_hl1_c3_to_out_c3, 0, HL1_HI, t_r_loop);

        //OutputLayer3
        buff_hl1_c1_to_out_c3 = this->ReadTokens(read_hl1_c1_to_out_c3, write_hl1_c1_to_out_c3, buff_hl1_c1_to_out_c3, 0, HL1_LO, t_r_loop);
        buff_hl1_c2_to_out_c3 = this->ReadTokens(read_hl1_c2_to_out_c3, write_hl1_c2_to_out_c3, buff_hl1_c2_to_out_c3, 0, HL1_LO, t_r_loop);
        buff_hl1_c3_to_out_c3 = this->ReadTokens(read_hl1_c3_to_out_c3, write_hl1_c3_to_out_c3, buff_hl1_c3_to_out_c3, 0, HL1_HI, t_r_loop);
        sc_core::wait(DelayOutputLayer3.GetDelay());
        buff_out_c3_to_decoder = this->WriteTokens(read_out_c3_to_decoder, write_out_c3_to_decoder, buff_out_c3_to_decoder, 0, OL_HI, t_r_loop);
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
    }
}

#endif
