#include<verilated.h>
#include<iostream>
#include<Vrisc_v.h>
using namespace std;

int main(int argc, char ** argv){

    VerilatedContext* contextp = new VerilatedContext;
      contextp->commandArgs(argc, argv);
      Vand_gate* top = new Vand_gate{contextp};

      top->clk=0;
      top->rst=0;
      top->imem_wr_en=0;
      top->imem_data_in=0;

       while (!Verilated->gotFinish()) { 
        top->clk=!top->clk;
        top->eval();
        printf("Final output is : %d\n",top->final_output);
        

        
        }
    delete top;
    delete contextp;
    return 0;
}