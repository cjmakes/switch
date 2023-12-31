// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmac.h for the primary calling header

#include "verilated.h"

#include "Vmac__Syms.h"
#include "Vmac___024root.h"

void Vmac___024root___eval_act(Vmac___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*1:0*/, 1024> Vmac__ConstPool__TABLE_h5db3e585_0;

VL_INLINE_OPT void Vmac___024root___nba_sequent__TOP__0(Vmac___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*9:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->mac__DOT__count = (((IData)(vlSelf->mac__DOT__state) 
                                == (IData)(vlSelf->mac__DOT__next_state))
                                ? (0xffU & ((IData)(1U) 
                                            + (IData)(vlSelf->mac__DOT__count)))
                                : 0U);
    vlSelf->mac__DOT__state = vlSelf->mac__DOT__next_state;
    vlSelf->tx_data = ((2U & (IData)(vlSelf->mac__DOT__state))
                        ? ((1U & (IData)(vlSelf->mac__DOT__state))
                            ? (3U & (0xcaU >> (7U & 
                                               (((IData)(7U) 
                                                 - 
                                                 ((IData)(vlSelf->mac__DOT__count) 
                                                  << 1U)) 
                                                - (IData)(1U)))))
                            : 3U) : 1U);
    __Vtableidx1 = (((IData)(vlSelf->mac__DOT__count) 
                     << 2U) | (IData)(vlSelf->mac__DOT__state));
    vlSelf->mac__DOT__next_state = Vmac__ConstPool__TABLE_h5db3e585_0
        [__Vtableidx1];
}

void Vmac___024root___eval_nba(Vmac___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vmac___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vmac___024root___eval_triggers__act(Vmac___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmac___024root___dump_triggers__act(Vmac___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmac___024root___dump_triggers__nba(Vmac___024root* vlSelf);
#endif  // VL_DEBUG

void Vmac___024root___eval(Vmac___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vmac___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vmac___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("mac.v", 2, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                Vmac___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vmac___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("mac.v", 2, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vmac___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vmac___024root___eval_debug_assertions(Vmac___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->crs_dv & 0xfeU))) {
        Verilated::overWidthError("crs_dv");}
    if (VL_UNLIKELY((vlSelf->rx_data & 0xfcU))) {
        Verilated::overWidthError("rx_data");}
    if (VL_UNLIKELY((vlSelf->rx_err & 0xfeU))) {
        Verilated::overWidthError("rx_err");}
}
#endif  // VL_DEBUG
