The setzer runs on the Atmega644p processor.
It is controlled by midi messages -NoteOn and -NoteOff.
Works with register devices and plates purchased in the Paush-e.de store.
The current code supports 40 registers, and 256x8 (256 banks of 8 combinations) stored on the microSD card.

NoteOn, in the range from 36 (C) to 75 (es2), turns on and off the backlight of the registers and, through the decoder, switches on the electromagnets of the registers.

Further midiOn messages - control the setzer:
noteOn 76 to 83 - a combination of 1 to 8, respectively
noteOn 84 (c3) - the eraser, i.e. zero
noteOn 85 (cis3) - next ie >
noteOn 86 (d3) - prev ie <
noteOn 87 (es3) SET (press) noteOff 87 releasing the SET button
noteOn 88 (e3) - turns crescendo on (potentiometer controlled)
a noteOn 89 f3) cancels (disables) cerscendo and restores last used combination
**noteOn 90 (fis3) + SET activates Crescendo programming mode**
noteOn from 91 (g3) to 100 can be used to expand the setzer with subsequent registers

The 20 degree crescendo is programmed as follows:
Set the rotary encoder to Bank No. 1, set registers for the first stage (usually all off), and press the SET (S) button and the ProgCrescendo ( ) button.
After saving stage one, Bank will change to number 2, set the registry again, this time for stage two. and press the SET (S) and ProgCrescendo ( ) buttons again.
Proceed in this order for 20 stages, stage 20 should have the most registers on (almost all).
Once all 20 degrees of crescendo have been programmed, press the Crescendo button (C) for crescendo pedal action, or Cancel Crescendo (A) which will return the organ setting to the last used combination.

The next (>) and prev (<) buttons are used to change the combination to the next forward and backward. Next works so that after 8 combinations comes the first combination of the next bank. similarly to prev but in reverse.
Pressing SET and one of the buttons described above changes the Bank to the next one, leaving the same combination number.
turning the encoder allows you to quickly change the bank to further positions, but the new combination will only be activated after pressing the combination buttons 1 to 8.
Pressing the SET button and one of the eight combination buttons saves the current set of registers for a given combination in the currently displayed bank.


For the project to work (tested) it has Atmega32A I added in the Library the encoder in the file interrupt_pins.h in the folder C:\Users\Dell\Documents\Arduino\libraries\Encoder\utility this section:

// MightyCore (untested) #elif defined(AVR_ATmega64) || defined (AVR_ATmega32) # define CORE_NUM_INTERRUPT 2 # define CORE_INT0_PIN 10 # define CORE_INT1_PIN 11

The encoder library comes from: https://github.com/PaulStoffregen/Encoder

http://www.pjrc.com/teensy/td_libs_Encoder.html

http://www.youtube.com/watch?v=2puhLong-cs

http://www.pjrc.com/teensy/td_libs_Encoder_1.jpg


*************************** tłumaczenie na język polski*****************************
Setzer działa na procesorze Atmega644p. 
Sterowany jest komunikatami midi -NoteOn and -NoteOff.
Wspłpracuje z urządzeniami registrami i płytkami zakupionymi w sklepie Paush-e.de.
Aktualny kod obsługuje 40 registrów, i 256x8 (256 banków po 8 kombinnacji) zapisanych na karcie mikroSD.

NoteOn w zakresie od 36 (C) do 75 (es2), w ł aczaja i wyłańczają podświetlenie registrów jak i poprzez dekoder włącza elektromagnesy registrowe.

Dalsze komunikaty midiOn  - sterują setzerem:
noteOn 76 do 83 - odpowiednio kombinacja 1 do 8
noteOn 84 (c3) - kasownik czyli zero
noteOn 85 (cis3) -  next czyli >
noteOn 86 (d3)  - prev czyli <
noteOn 87 (es3) SET (naciśniecie) noteOff 87 zwolnienie przycisku SET
noteOn 88 (e3) - włącza crescendo (sterowane potenciometrem)
a noteOn 89 f3) anuluje (wyłącza) działanie cerscendo i przywraca ostatnio urzywan a kombinację
**noteOn 90 (fis3) + SET włącza tryb programowania Crescendo**
noteOn od 91 (g3) do 100 mogą być wykożystane do rozbusowy setzera o kolejne registry 

Dwudziesto stopniowe crescendo jest programowane w taki sposób:
Ustawić enkoderem obrotowym Bank nr 1, ustawić registry dla stopnia pierwszego (najcześciej wszystkie wyłączone), i nacisnąć przycisk SET (S) i przycisk ProgCrescendo ( ).
Po zapisaniu stopnia pierwszego  Bank zmieni się nr 2, znów  ustawić registry, tym razem dla stopnia drugiego. i znów nacisnąć przycisk SET (S) i ProgCrescendo ( ). 
Postępować tak kolejno dla 20 stopni, stopień dwudziesty powinien mieć włączonych najwięcej registrów (prawie wszystkie).
Po zaprogramowaniu wszystkich 20 stopni crescendo nacisnąć przycisk Crescendo (C), dla działania pedału crescenda, albo  Anuluj Crescendo (A) - które spowoduje, że ustawienie organów wróci do ostatnio używanej kombinacji.  

Przyciski next (>) oraz prev (<) służą do zmiany kombinacji na kolejną do przodu i do tyłu. Next diała tak, że po 8 kombinacji następuje pierwsza kombinacja następnego banku. podobnie prev ale w odwrotnym kierunku.
Nacisniecie SET i jednego z powyżej opisanych przycisków zmienia Bank na kolejny, pozostawiając ten sam nr kombinacji.
kręcenie enkoderem umożliwia szybką zmianę banku na dalsze pozycje, lecz nowa kombinacja włączy się dopiero po nacisniećiu przycisko kombinacji 1 do 8.
Naciśniecie przycisku SET i jednego z ośmiu  przycxisków kombinacji powoduje zapisanie aktualnego ustawienia registrów do danej kombinacji w aktoalnioe wyświetlonym banku. 

Aby projekt mógł działać (testowane) ma Atmega32A dodałem w Bibliotece enkoder w pliku interupt_pins.h
w folderze C:\Users\Dell\Documents\Arduino\libraries\Encoder\utility
tę sekcję:


// MightyCore (untested)
#elif defined(__AVR_ATmega64__) || defined(__AVR_ATmega32__)
  #define CORE_NUM_INTERRUPT	2
  #define CORE_INT0_PIN		10
  #define CORE_INT1_PIN		11

  Biblioteka enkoder pochodzi ze strony:
  https://github.com/PaulStoffregen/Encoder
  
http://www.pjrc.com/teensy/td_libs_Encoder.html

http://www.youtube.com/watch?v=2puhIong-cs

http://www.pjrc.com/teensy/td_libs_Encoder_1.jpg
