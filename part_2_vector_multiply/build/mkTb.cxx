/*
 * Generated by Bluespec Compiler, version 2023.07-33-g1c27a41e (build 1c27a41e)
 * 
 * On Wed Feb 21 21:02:59 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkTb.h"


/* String declarations */
static std::string const __str_literal_4("", 0u);
static std::string const __str_literal_6("Expected %d for test %d", 23u);
static std::string const __str_literal_3("GOT ", 4u);
static std::string const __str_literal_2("STARTING TEST FOR VECTOR DOT PRODUCT DIM 16... index %d",
					 55u);
static std::string const __str_literal_5("Test %d passed", 14u);
static std::string const __str_literal_1("v3.hex", 6u);


/* Constructor */
MOD_mkTb::MOD_mkTb(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_ctr(simHdl, "ctr", this, 32u, 0u, (tUInt8)0u),
    INST_going(simHdl, "going", this, 1u, (tUInt8)1u, (tUInt8)0u),
    INST_i(simHdl, "i", this, 2u, (tUInt8)0u, (tUInt8)0u),
    INST_mma(simHdl, "mma", this),
    INST_tests(simHdl, "tests", this, __str_literal_1, 2u, 32u, (tUInt8)0u, (tUInt8)3u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 8u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTb::init_symbols_0()
{
  init_symbol(&symbols[0u], "ctr", SYM_MODULE, &INST_ctr);
  init_symbol(&symbols[1u], "going", SYM_MODULE, &INST_going);
  init_symbol(&symbols[2u], "i", SYM_MODULE, &INST_i);
  init_symbol(&symbols[3u], "mma", SYM_MODULE, &INST_mma);
  init_symbol(&symbols[4u], "RL_inc_ctr", SYM_RULE);
  init_symbol(&symbols[5u], "RL_resp", SYM_RULE);
  init_symbol(&symbols[6u], "RL_start", SYM_RULE);
  init_symbol(&symbols[7u], "tests", SYM_MODULE, &INST_tests);
}


/* Rule actions */

void MOD_mkTb::RL_inc_ctr()
{
  tUInt32 DEF_ctr_PLUS_1___d2;
  tUInt32 DEF_b__h75;
  DEF_b__h75 = INST_ctr.METH_read();
  DEF_ctr_PLUS_1___d2 = DEF_b__h75 + 1u;
  INST_ctr.METH_write(DEF_ctr_PLUS_1___d2);
}

void MOD_mkTb::RL_start()
{
  DEF_i__h583 = INST_i.METH_read();
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s,2", &__str_literal_2, DEF_i__h583);
  INST_going.METH_write((tUInt8)0u);
  INST_mma.METH_start((tUInt8)16u, DEF_i__h583);
}

void MOD_mkTb::RL_resp()
{
  tUInt8 DEF_x__h630;
  tUInt8 DEF_NOT_mma_response_0_EQ_tests_sub_i_1_2___d13;
  tUInt8 DEF_NOT_i_EQ_3_4___d15;
  tUInt8 DEF_i_EQ_3___d14;
  tUInt8 DEF_mma_response_0_EQ_tests_sub_i_1___d12;
  tUInt32 DEF_x__h584;
  tUInt32 DEF_v__h463;
  tUInt32 DEF_AVMeth_mma_response;
  DEF_i__h583 = INST_i.METH_read();
  DEF_x__h584 = INST_tests.METH_sub(DEF_i__h583);
  DEF_i_EQ_3___d14 = DEF_i__h583 == (tUInt8)3u;
  DEF_NOT_i_EQ_3_4___d15 = !DEF_i_EQ_3___d14;
  DEF_x__h630 = (tUInt8)3u & (DEF_i__h583 + (tUInt8)1u);
  DEF_AVMeth_mma_response = INST_mma.METH_response();
  DEF_v__h463 = DEF_AVMeth_mma_response;
  DEF_mma_response_0_EQ_tests_sub_i_1___d12 = DEF_v__h463 == DEF_x__h584;
  DEF_NOT_mma_response_0_EQ_tests_sub_i_1_2___d13 = !DEF_mma_response_0_EQ_tests_sub_i_1___d12;
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    dollar_display(sim_hdl, this, "s,32,s", &__str_literal_3, DEF_v__h463, &__str_literal_4);
    if (DEF_mma_response_0_EQ_tests_sub_i_1___d12)
      dollar_display(sim_hdl, this, "s,2", &__str_literal_5, DEF_i__h583);
    if (DEF_NOT_mma_response_0_EQ_tests_sub_i_1_2___d13)
      dollar_display(sim_hdl, this, "s,32,2", &__str_literal_6, DEF_x__h584, DEF_i__h583);
  }
  INST_going.METH_write((tUInt8)1u);
  if (!(PORT_RST_N == (tUInt8)0u))
    if (DEF_i_EQ_3___d14)
      dollar_finish(sim_hdl, "32", 1u);
  if (DEF_NOT_i_EQ_3_4___d15)
    INST_i.METH_write(DEF_x__h630);
}


/* Methods */


/* Reset routines */

void MOD_mkTb::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_mma.reset_RST_N(ARG_rst_in);
  INST_i.reset_RST(ARG_rst_in);
  INST_going.reset_RST(ARG_rst_in);
  INST_ctr.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTb::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTb::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_ctr.dump_state(indent + 2u);
  INST_going.dump_state(indent + 2u);
  INST_i.dump_state(indent + 2u);
  INST_mma.dump_state(indent + 2u);
  INST_tests.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTb::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 6u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "i__h583", 2u);
  num = INST_ctr.dump_VCD_defs(num);
  num = INST_going.dump_VCD_defs(num);
  num = INST_i.dump_VCD_defs(num);
  num = INST_tests.dump_VCD_defs(num);
  if (levels != 1u)
  {
    unsigned int l = levels == 0u ? 0u : levels - 1u;
    num = INST_mma.dump_VCD_defs(l);
  }
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTb::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTb &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
  if (levels != 1u)
    vcd_submodules(dt, levels - 1u, backing);
}

void MOD_mkTb::vcd_defs(tVCDDumpType dt, MOD_mkTb &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 2u);
  }
  else
    if (dt == VCD_DUMP_CHANGES)
    {
      if ((backing.PORT_RST_N) != PORT_RST_N)
      {
	vcd_write_val(sim_hdl, num, PORT_RST_N, 1u);
	backing.PORT_RST_N = PORT_RST_N;
      }
      ++num;
      if ((backing.DEF_i__h583) != DEF_i__h583)
      {
	vcd_write_val(sim_hdl, num, DEF_i__h583, 2u);
	backing.DEF_i__h583 = DEF_i__h583;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_i__h583, 2u);
      backing.DEF_i__h583 = DEF_i__h583;
    }
}

void MOD_mkTb::vcd_prims(tVCDDumpType dt, MOD_mkTb &backing)
{
  INST_ctr.dump_VCD(dt, backing.INST_ctr);
  INST_going.dump_VCD(dt, backing.INST_going);
  INST_i.dump_VCD(dt, backing.INST_i);
  INST_tests.dump_VCD(dt, backing.INST_tests);
}

void MOD_mkTb::vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mkTb &backing)
{
  INST_mma.dump_VCD(dt, levels, backing.INST_mma);
}
