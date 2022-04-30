### Legend
SF: Shift Register

### Useful infos about: 74HC595 shift register 
L'integrato 74HC595 richiedendo solo 3 pin digitali consente di gestirne fino ad 8, generando un utile complessivo di 5 pin.

Seguendo lo schema dato nella cartella <code>/schemes</code> per collegare 2 SF, si può generalizzare il collegamento fatto tra i 2 SF ad n SF (collegamento in cascata).
N.B:
- Questo tipo di collegamento, necessitando sempre di 3 pin digitali, ne genera una quantità x data dal numero n di SF collegati in cascata moltiplicato per 8, il tutto meno 3. Formalmente x:=(n*8)-3.
- Inoltre^1, collegare uno SF, il quale funziona come un array di 8 bit, in cascata con un altri SF, dà origine ad un SF fittizio rappresentante di un array di t:=n*8 bits.