#ifndef EXPERIMENT_HPP
#define EXPERIMENT_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <tile.hpp>
#include <channel.hpp>
#include <utils.hpp>

// Delay definition
auto DelayHiddenLayer  = DelayVector(784, 10);
auto DelayOutputLayer  = DelayVector(10 , 10);

// Event definition
sc_core::sc_event write_input, read_input, write_hlout, read_hlout,
                  write_output, read_output;

// Buffer Availability
bool buff_input = 1;
//~ bool buff_hl1hl2 = 1;
bool buff_hlout = 1;
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

        //HIDDENLAYER1
        buff_input = this->ReadTokens(read_input, write_input, buff_input, 1, 784, t_r_loop);
        sc_core::wait(DelayHiddenLayer.GetDelay());
        buff_hlout = this->WriteTokens(read_hlout, write_hlout, buff_hlout, 0, 10, t_r_loop);
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
        //OUTPUTLAYER
        buff_hlout = this->ReadTokens(read_hlout, write_hlout, buff_hlout, 0, 10, t_r_loop);
        sc_core::wait(DelayOutputLayer.GetDelay());
        buff_output = this->WriteTokens(read_output, write_output, buff_output, 1, 10, t_r_loop);

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
