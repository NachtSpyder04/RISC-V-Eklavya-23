#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "convert.h"
using namespace std;

struct Instruction {
    string ins;
    string opcode;
    int rs1;
    int rs2;
    int rd;
    string funct7;
    string funct3;
    string imm = "";
    int rs1_value;
    int rs2_value;
};

ofstream outputFile("test.v");
ifstream inputfile("input_instruction.txt");

string line;
struct output_t{
    int rd;
    int pc;
    int final_output;
    vector <string> cu_states;

} output_t;

class instructions{
    public:
    Instruction inst1;
    vector<string> BinInstructions;
    void GenerateInstructions(string instr)
    {
        if(instr == "add"){
            inst1.ins = instr;
            inst1.opcode = "0110011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "000";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "sub"){
            inst1.ins = instr;
            inst1.opcode = "0110011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "000";
            inst1.funct7 = "0010100";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "xor"){
            inst1.ins = instr;
            inst1.opcode = "0110011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "100";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "or"){
            inst1.ins = instr;
            inst1.opcode = "0110011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "110";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "and"){
            inst1.ins = instr;
            inst1.opcode = "0110011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "111";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "sll"){
            inst1.ins = instr;
            inst1.opcode = "0110011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "001";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "srl"){
            inst1.ins = instr;
            inst1.opcode = "0110011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "101";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "sra"){
            inst1.ins = instr;
            inst1.opcode = "0110011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "101";
            inst1.funct7 = "0010100";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;

        }
        else if (instr == "slt"){
            inst1.ins = instr;
            inst1.opcode = "0110011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "010";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "sltu"){
            inst1.ins = instr;
            inst1.opcode = "0110011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "011";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "addi"){
            inst1.ins = instr;
            inst1.opcode = "0010011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "000";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0000000" + DecitoBin(rand() % 32);
        }
        else if (instr == "xori"){
            inst1.ins = instr;
            inst1.opcode = "0010011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "100";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0000000" + DecitoBin(rand() % 32);
        }
        else if (instr == "ori"){
            inst1.ins = instr;
            inst1.opcode = "0010011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "110";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0000000" + DecitoBin(rand() % 32);
        }
        else if (instr == "andi"){
            inst1.ins = instr;
            inst1.opcode = "0010011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "111";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0000000" + DecitoBin(rand() % 32);
        }
        else if (instr == "slli"){
            inst1.ins = instr;
            inst1.opcode = "0010011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "001";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0000000" + DecitoBin(rand() % 32);
        }
        else if (instr == "srli"){
            inst1.ins = instr;
            inst1.opcode = "0010011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "101";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0000000" + DecitoBin(rand() % 32);
        }
        else if (instr == "srai"){
            inst1.ins = instr;
            inst1.opcode = "0010011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "101";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0010100" + DecitoBin(rand() % 32);
        }
        else if (instr == "slti"){
            inst1.ins = instr;
            inst1.opcode = "0010011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "010";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0000000" + DecitoBin(rand() % 32);
        }
        else if (instr == "sltiu"){
            inst1.ins = instr;
            inst1.opcode = "0010011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "011";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0000000" + DecitoBin(rand() % 32);
        }
        else if (instr == "lb"){
            inst1.ins = instr;
            inst1.opcode = "0000011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "000";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0000000" + DecitoBin(rand() % 32);
        }
        else if (instr == "lh"){
            inst1.ins = instr;
            inst1.opcode = "0000011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "001";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0000000" + DecitoBin(rand() % 32);
        }
        else if (instr == "lw"){
            inst1.ins = instr;
            inst1.opcode = "0000011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "010";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0000000" + DecitoBin(rand() % 32);
        }
        else if (instr == "lbu"){
            inst1.ins = instr;
            inst1.opcode = "0000011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "100";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0000000" + DecitoBin(rand() % 32);
        }
        else if (instr == "lhu"){
            inst1.ins = instr;
            inst1.opcode = "0000011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.rd = rand() % 32;
            inst1.funct3 = "101";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0000000" + DecitoBin(rand() % 32);
        }
        else if (instr == "sb"){
            inst1.ins = instr;
            inst1.opcode = "0100011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.funct3 = "00";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0000000" + DecitoBin(rand() % 32);
        }
        else if (instr == "sh"){
            inst1.ins = instr;
            inst1.opcode = "0100011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.funct3 = "001";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0000000" + DecitoBin(rand() % 32);
        }
        else if (instr == "sw"){
            inst1.ins = instr;
            inst1.opcode = "0100011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.funct3 = "010";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
            inst1.imm = "0000000" + DecitoBin(rand() % 32);
        }
        else if (instr == "beq"){
            inst1.ins = instr;
            inst1.opcode = "1100011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.funct3 = "000";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "bne"){
            inst1.ins = instr;
            inst1.opcode = "1100011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.funct3 = "001";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "blt"){
            inst1.ins = instr;
            inst1.opcode = "1100011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.funct3 = "100";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "bge"){
            inst1.ins = instr;
            inst1.opcode = "1100011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.funct3 = "101";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "bltu"){
            inst1.ins = instr;
            inst1.opcode = "1100011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.funct3 = "110";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "bgeu"){
            inst1.ins = instr;
            inst1.opcode = "1100011";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = rand() % 32;
            inst1.funct3 = "111";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "jal"){
            inst1.ins = instr;
            inst1.opcode = "1101111";
            inst1.rs1 = 0;
            inst1.rs2 = 0;
            inst1.rd = rand() % 32;
            inst1.funct3 = "000";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "jalr"){
            inst1.ins = instr;
            inst1.opcode = "1100111";
            inst1.rs1 = rand() % 32;
            inst1.rs2 = 0;
            inst1.rd = rand() % 32;
            inst1.funct3 = "000";
            inst1.funct7 = "0000000";
            inst1.rs1_value = rand() % 10000;
            inst1.rs2_value = rand() % 10000;
        }
        else if (instr == "luipc"){
            inst1.ins = instr;
            inst1.opcode = "0110111";
            inst1.rs1 = 0;
            inst1.rs2 = 0;
            inst1.rd = rand() % 32;
            inst1.funct3 = "000";
            inst1.funct7 = "0000000";
            inst1.rs1_value = 0;
            inst1.rs2_value = 0;
        }
        else if (instr == "auipc"){
            inst1.ins = instr;
            inst1.opcode = "0010111";
            inst1.rs1 = 0;
            inst1.rs2 = 0;
            inst1.rd = rand() % 32;
            inst1.funct3 = "000";
            inst1.funct7 = "0000000";
            inst1.rs1_value = 0;
            inst1.rs2_value = 0;
        }
    }

    void Binaryinstructions()
    {
        if (inst1.opcode == "0110011"){
            BinInstructions.push_back( inst1.funct7 + DecitoBin(inst1.rs2) + DecitoBin(inst1.rs1) + inst1.funct3 + DecitoBin(inst1.rd) + inst1.opcode);
        }
        else if (inst1.opcode == "0010011" || inst1.opcode == "0000011"){
            BinInstructions.push_back( inst1.imm + DecitoBin(inst1.rs2) + DecitoBin(inst1.rs1) + inst1.funct3 + DecitoBin(inst1.rd) + inst1.opcode);
        }
        else if (inst1.opcode == "0100011"){
            BinInstructions.push_back( inst1.imm.substr(0,7) + DecitoBin(inst1.rs2) + DecitoBin(inst1.rs1) + inst1.funct3 + inst1.imm.substr(7,5) + inst1.opcode);
        }
    }

    void FileWrite(int i){
        
        if (outputFile.is_open() ) 
        {
            outputFile << "ins_mem[" + to_string(i) + "] = 32'h" + BintoHex(BinInstructions[i])<<endl;
        } 
        else 
        {
            cout << "Unable to open imem.v for writing." << endl;
        }
    }
};


int main() {
    int i = 0;
    instructions obj;
    string filename = "test.v";
    removeLastLine(filename);
    while (getline(inputfile, line)) {
        obj.GenerateInstructions(line);
        obj.Binaryinstructions();
        obj.FileWrite(i);
        i ++;
    }
    outputFile <<"  end\nendmodule";
    outputFile.close();
    inputfile.close();
    return 0;
}
