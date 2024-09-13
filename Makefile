TARGET=main
TOP=main
OBJS+=main.v

all: ${TARGET}.bin

obj_dir/Vmac: mac_tb.cpp mac.v mak
	verilator --cc --exe --build --trace -j 0 $^

$(TARGET).json: $(OBJS)
	yosys -p "read_verilog -sv $(OBJS); synth_ecp5 -json $@ -top $(TOP)"

$(TARGET).config: $(TARGET).json $(TARGET).lpf
	nextpnr-ecp5 --25k --package CABGA256 --json $< --lpf $(TARGET).lpf --textcfg $@ --freq 100

$(TARGET).bin: $(TARGET).config
	ecppack --compress --bit $@ $<

.PHONY: prog
prog: ${TARGET}.bin
	ecpdap program --freq 5000 main.bin
	ecpdap flash unprotect
	ecpdap flash write --freq 5000 main.bin

.PHONY: clean
clean:
	rm -f *.json *.config *.bin
