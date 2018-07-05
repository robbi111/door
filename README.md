# door
Software and hardware design for automatic chicken door

## Software
Software framework built with Atmel START

### Initialization

* Disable WDT

### Timer/Counter 2
*
* set clock source to async clock: ASSR.AS2=1
* enable TC2 Overflow interrupt: TIMSK2.TOIE2=1
* select prescaler for 32.768 kHz clock (clk/128 for 1s overfolw interrupts): TCCR2B.CS2=0b101 (0x5)
* Interrupt vector: TIMER2_OVF
* global interrupt enable: SREG.I=1 (better with function sei())
* set sleep mode "Power-save" during interrupts: SMCR.SM=0b011, SMCR.SE=1 (sleep mode entered with sleep() from application)


