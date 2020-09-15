# Target file name (without extension).
TARGET ?= gherkin32

# Directory common source filess exist
TMK_DIR ?= ../../tmk_core

# Directory keyboard dependent files exist
TARGET_DIR ?= .

# project specific files
SRC ?=	keymap_gherkin.c \
	matrix.c \
	led.c

CONFIG_H ?= config.h


# MCU name
MCU ?= atmega32

# Defines needed to use correct registers for the atmega32
OPT_DEFS += -DNO_CLKPR -DTIMER0_COMP -DTIMER_PRESCALER=1024

# Processor frequency.
#     This will define a symbol, F_CPU, in all source code files equal to the
#     processor frequency in Hz. You can then use this symbol in your source code to
#     calculate timings. Do NOT tack on a 'UL' at the end, this will be done
#     automatically to create a 32-bit value in your source code.
#
#     This will be an integer division of F_USB below, as it is sourced by
#     F_USB after it has run through any CPU prescalers. Note that this value
#     does not *change* the processor frequency - it should merely be updated to
#     reflect the processor speed set externally so that the code can use accurate
#     software delays.
F_CPU ?= 16000000

# Input clock frequency.
#     This will define a symbol, F_USB, in all source code files equal to the
#     input clock frequency (before any prescaling is performed) in Hz. This value may
#     differ from F_CPU if prescaling is used on the latter, and is required as the
#     raw input clock is fed directly to the PLL sections of the AVR for high speed
#     clock generation for the USB and other AVR subsections. Do NOT tack on a 'UL'
#     at the end, this will be done automatically to create a 32-bit value in your
#     source code.
#
#     If no clock division is performed on the input clock inside the AVR (via the
#     CPU clock adjust registers or the clock division fuses), this will be equal to F_CPU.
F_USB ?= $(F_CPU)

# Interrupt driven control endpoint task(+60)
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT


# Boot Section Size in *bytes*
#   Teensy halfKay   512
#   Teensy++ halfKay 1024
#   Atmel DFU loader 4096
#   LUFA bootloader  4096
#   USBaspLoader     2048
BOOTLOADER_SIZE ?= 2048
OPT_DEFS += -DBOOTLOADER_SIZE=$(BOOTLOADER_SIZE)


# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE ?= yes	# Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE ?= yes	# Mouse keys(+4700)
EXTRAKEY_ENABLE ?= yes	# Audio control and System control(+450)
CONSOLE_ENABLE ?= no	# Console for debug disabled, disables also UART RX
COMMAND_ENABLE ?= yes	# Commands for debug and configuration
SLEEP_LED_ENABLE ?= no	# Breathing sleep LED during USB suspend
NKRO_ENABLE ?= no	# USB Nkey Rollover
ACTIONMAP_ENABLE ?= no	# Use 16bit action codes in keymap instead of 8bit keycodes
NO_UART = yes 		# UART for debugging


# Optimize size but this may cause error "relocation truncated to fit"
#EXTRALDFLAGS = -Wl,--relax

# Search Path
VPATH += $(TARGET_DIR)
VPATH += $(TMK_DIR)

include $(TMK_DIR)/protocol.mk
include $(TMK_DIR)/common.mk
include $(TMK_DIR)/protocol/vusb.mk
include $(TMK_DIR)/rules.mk


#---------------- Programming Options (avrdude) ----------------

AVRDUDE ?= avrdude

# Programming hardware, type: avrdude -c ?
# to get a full listing.
#
# This setting asumes, that you flashed the bootloader first
AVRDUDE_PROGRAMMER ?= usbasp

# com1 = serial port. Use lpt1 to connect to parallel port.
AVRDUDE_PORT ?=  /dev/ttyACM0   # programmer connected to serial device

AVRDUDE_WRITE_FLASH ?= -U flash:w:$(TARGET).hex
#AVRDUDE_WRITE_EEPROM ?= -U eeprom:w:$(TARGET).eep

# Brown-out detection level at VCC=2.7 V; [BODLEVEL=1]
# Ext. Crystal Osc.; High Frequency; Start-up time PWRDWN/RESET: 1024 clk + 64 ms; [CKSEL=1111 SUT=00]
# Boot Reset vector Enabled (Jump to bootloader first)
# Serial program downloading (SPI) enabled; [SPIEN=0]
# Watch-dog Timer disabled; [WDTON=0]
# Self Programming disabled; [SELFPRGEN=0]
AVRDUDE_FUSEBITS ?= -U lfuse:w:0x8F:m -U hfuse:w:0xC8:m


# Uncomment the following if you want avrdude's erase cycle counter.
# Note that this counter needs to be initialized first using -Yn,
# see avrdude manual.
#AVRDUDE_ERASE_COUNTER ?= -y

# Uncomment the following if you do /not/ wish a verification to be
# performed after programming the device.
#AVRDUDE_NO_VERIFY ?= -V

# Increase verbosity level.  Please use this when submitting bug
# reports about avrdude. See <http://savannah.nongnu.org/projects/avrdude>
# to submit bug reports.
#AVRDUDE_VERBOSE ?= -v -v

AVRDUDE_FLAGS ?= -p $(MCU) -P $(AVRDUDE_PORT) -c $(AVRDUDE_PROGRAMMER)
AVRDUDE_FLAGS += $(AVRDUDE_NO_VERIFY)
AVRDUDE_FLAGS += $(AVRDUDE_VERBOSE)
AVRDUDE_FLAGS += $(AVRDUDE_ERASE_COUNTER)

#============================================================================

# Program the device.
program: $(TARGET).hex $(TARGET).eep
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH) $(AVRDUDE_WRITE_EEPROM) $(AVRDUDE_FUSEBITS)

# Set fuses.
fuse:
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_FUSEBITS)

# Listing of phony targets.
.PHONY : all sizebefore sizeafter gccversion \
build elf hex eep lss sym coff extcoff \
clean program fuse
