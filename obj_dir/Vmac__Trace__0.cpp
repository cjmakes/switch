// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmac__Syms.h"


void Vmac___024root__trace_chg_sub_0(Vmac___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vmac___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root__trace_chg_top_0\n"); );
    // Init
    Vmac___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmac___024root*>(voidSelf);
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vmac___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vmac___024root__trace_chg_sub_0(Vmac___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->mac__DOT__state),2);
        bufp->chgCData(oldp+1,(vlSelf->mac__DOT__next_state),2);
        bufp->chgCData(oldp+2,(vlSelf->mac__DOT__count),8);
    }
    bufp->chgBit(oldp+3,(vlSelf->clk));
    bufp->chgBit(oldp+4,(vlSelf->crs_dv));
    bufp->chgCData(oldp+5,(vlSelf->rx_data),2);
    bufp->chgBit(oldp+6,(vlSelf->tx_en));
    bufp->chgCData(oldp+7,(vlSelf->tx_data),2);
    bufp->chgBit(oldp+8,(vlSelf->rx_err));
}

void Vmac___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root__trace_cleanup\n"); );
    // Init
    Vmac___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmac___024root*>(voidSelf);
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
