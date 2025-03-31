$regfile = "m32def.dat"

$crystal = 16000000

config PORTB.0 = input
config PINA.0 = input
config PINA.1 = input
config PINA.5 = OUTPUT

mode_1 Alias PINB.7
mode_2 Alias PINA.0
mode_3 Alias PINA.1
S_input Alias PINB.3
Danger Alias PINA.5





