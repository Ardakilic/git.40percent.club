Compiled hex files for USBaspLoader bootloader. https://github.com/baerwolf/USBaspLoader

D+ PD2
D- PD4
Boot jumper PD7

Flash with fuses:

avrdude -p atmega32 -c usbtiny -U lfuse:w:0x1F:m -U hfuse:w:0xC0:m -U flash:w:bootloader_atmega32_16MHz.hex