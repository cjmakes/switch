// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmac.h"
#include "Vmac__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vmac::Vmac(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmac__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , crs_dv{vlSymsp->TOP.crs_dv}
    , rx_data{vlSymsp->TOP.rx_data}
    , tx_en{vlSymsp->TOP.tx_en}
    , tx_data{vlSymsp->TOP.tx_data}
    , rx_err{vlSymsp->TOP.rx_err}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmac::Vmac(const char* _vcname__)
    : Vmac(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmac::~Vmac() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmac___024root___eval_debug_assertions(Vmac___024root* vlSelf);
#endif  // VL_DEBUG
void Vmac___024root___eval_static(Vmac___024root* vlSelf);
void Vmac___024root___eval_initial(Vmac___024root* vlSelf);
void Vmac___024root___eval_settle(Vmac___024root* vlSelf);
void Vmac___024root___eval(Vmac___024root* vlSelf);

void Vmac::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmac::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmac___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmac___024root___eval_static(&(vlSymsp->TOP));
        Vmac___024root___eval_initial(&(vlSymsp->TOP));
        Vmac___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmac___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmac::eventsPending() { return false; }

uint64_t Vmac::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmac::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmac___024root___eval_final(Vmac___024root* vlSelf);

VL_ATTR_COLD void Vmac::final() {
    Vmac___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmac::hierName() const { return vlSymsp->name(); }
const char* Vmac::modelName() const { return "Vmac"; }
unsigned Vmac::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vmac::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vmac___024root__trace_init_top(Vmac___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmac___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmac___024root*>(voidSelf);
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vmac___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vmac___024root__trace_register(Vmac___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmac::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmac::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmac___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
