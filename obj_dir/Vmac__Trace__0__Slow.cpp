// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmac__Syms.h"


VL_ATTR_COLD void Vmac___024root__trace_init_sub__TOP__0(Vmac___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+5,"clk", false,-1);
    tracep->declBit(c+6,"crs_dv", false,-1);
    tracep->declBus(c+7,"rx_data", false,-1, 1,0);
    tracep->declBit(c+8,"tx_en", false,-1);
    tracep->declBus(c+9,"tx_data", false,-1, 1,0);
    tracep->declBit(c+10,"rx_err", false,-1);
    tracep->pushNamePrefix("mac ");
    tracep->declBit(c+5,"clk", false,-1);
    tracep->declBit(c+6,"crs_dv", false,-1);
    tracep->declBus(c+7,"rx_data", false,-1, 1,0);
    tracep->declBit(c+8,"tx_en", false,-1);
    tracep->declBus(c+9,"tx_data", false,-1, 1,0);
    tracep->declBit(c+10,"rx_err", false,-1);
    tracep->declBus(c+1,"state", false,-1, 1,0);
    tracep->declBus(c+2,"next_state", false,-1, 1,0);
    tracep->declBus(c+3,"count", false,-1, 7,0);
    tracep->declBus(c+11,"data", false,-1, 7,0);
    tracep->declBus(c+4,"tx_reg", false,-1, 1,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vmac___024root__trace_init_top(Vmac___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root__trace_init_top\n"); );
    // Body
    Vmac___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vmac___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vmac___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vmac___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vmac___024root__trace_register(Vmac___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vmac___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vmac___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vmac___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vmac___024root__trace_full_sub_0(Vmac___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vmac___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root__trace_full_top_0\n"); );
    // Init
    Vmac___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmac___024root*>(voidSelf);
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vmac___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vmac___024root__trace_full_sub_0(Vmac___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->mac__DOT__state),2);
    bufp->fullCData(oldp+2,(vlSelf->mac__DOT__next_state),2);
    bufp->fullCData(oldp+3,(vlSelf->mac__DOT__count),8);
    bufp->fullCData(oldp+4,(vlSelf->mac__DOT__tx_reg),2);
    bufp->fullBit(oldp+5,(vlSelf->clk));
    bufp->fullBit(oldp+6,(vlSelf->crs_dv));
    bufp->fullCData(oldp+7,(vlSelf->rx_data),2);
    bufp->fullBit(oldp+8,(vlSelf->tx_en));
    bufp->fullCData(oldp+9,(vlSelf->tx_data),2);
    bufp->fullBit(oldp+10,(vlSelf->rx_err));
    bufp->fullCData(oldp+11,(0x33U),8);
}
