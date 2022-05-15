## Legend
SR: Shift Register

## Useful infos about: 74HC595 shift register 
L'integrato 74HC595 richiedendo solo 3 pin digitali consente di gestirne fino ad 8, generando un utile complessivo di 5 pin.

Seguendo lo schema dato nella cartella "<code>/schemes</code>" per collegare 2 SR, si può generalizzare il collegamento ad <code>n</code> SR, collegandoli in cascata.

N.B:
- Il collegamento del primo SR necessita sempre di 3 pin digitali e ne genera una, complessivamente, 5.
- Il collegamento in cascata necessita di 3 pin digitali (collegamento del primo SR) e ne genera una quantità <code>x</code> data dal numero <code>n</code> di SR collegati in cascata moltiplicato per 8, il tutto meno 3. Formalmente:  <code>x:=(n*8)-3</code>
- Inoltre, collegare uno SR, il quale funziona come un array di 8 bit, in cascata con un altri SR dà origine ad un SR fittizio rappresentante di un array di <code>t:=n*8</code> bits.
