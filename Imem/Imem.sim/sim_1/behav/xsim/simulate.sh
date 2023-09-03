#!/bin/bash -f
# ****************************************************************************
# Vivado (TM) v2020.2.2 (64-bit)
#
# Filename    : simulate.sh
# Simulator   : Xilinx Vivado Simulator
# Description : Script for simulating the design by launching the simulator
#
# Generated by Vivado on Sat Sep 02 23:11:02 IST 2023
# SW Build 3118627 on Tue Feb  9 05:13:49 MST 2021
#
# Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
#
# usage: simulate.sh
#
# ****************************************************************************
set -Eeuo pipefail
# simulate design
echo "xsim imem_tb_behav -key {Behavioral:sim_1:Functional:imem_tb} -tclbatch imem_tb.tcl -view /home/saish_k/Imem/imem_tb_behav.wcfg -log simulate.log"
xsim imem_tb_behav -key {Behavioral:sim_1:Functional:imem_tb} -tclbatch imem_tb.tcl -view /home/saish_k/Imem/imem_tb_behav.wcfg -log simulate.log
