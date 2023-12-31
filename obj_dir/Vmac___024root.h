// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmac.h for the primary calling header

#ifndef VERILATED_VMAC___024ROOT_H_
#define VERILATED_VMAC___024ROOT_H_  // guard

#include "verilated.h"


class Vmac__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmac___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(crs_dv,0,0);
    VL_IN8(rx_data,1,0);
    VL_OUT8(tx_en,0,0);
    VL_OUT8(tx_data,1,0);
    VL_IN8(rx_err,0,0);
    CData/*1:0*/ mac__DOT__state;
    CData/*1:0*/ mac__DOT__next_state;
    CData/*7:0*/ mac__DOT__count;
    CData/*1:0*/ mac__DOT__tx_reg;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vmac__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmac___024root(Vmac__Syms* symsp, const char* v__name);
    ~Vmac___024root();
    VL_UNCOPYABLE(Vmac___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
