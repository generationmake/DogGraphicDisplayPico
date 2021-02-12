# DogGraphicDisplayPico
Software example for EA DOG graphic display on Raspberry Pi Pico

clone into the pico directory along side with `pico-sdk` and `pico-examples`. usually `/home/pi/pico`

## build instructions

go into directory and then:

```
mkdir build
cd build
cmake ..
make
```

this should create a `DogGraphicDisplayPico.uf2`. Flash this file onto the Pico.
