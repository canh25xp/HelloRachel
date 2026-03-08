# Say Hello in Morse code

## Prerequisite

1. Install `arduino-cli`
   ```sh
   curl -LO https://github.com/arduino/arduino-cli/releases/download/v1.4.1/arduino-cli_1.4.1-1_amd64.deb
   sudo dpkg -i arduino-cli_1.4.1-1_amd64.deb
   arduino-cli config init
   ```
2. Install arduino core
   ```sh
   arduino-cli core update-index
   arduino-cli core install arduino:avr
   ```
3. Check installation

   ```console
   $ arduino-cli core list
   ID          Installed Latest Name
   arduino:avr 1.8.7     1.8.7  Arduino AVR Boards

   $ arduino-cli board list
   Port         Protocol Type              Board Name  FQBN            Core
   /dev/ttyACM0 serial   Serial Port (USB) Arduino UNO arduino:avr:uno arduino:avr
   ```

> [!NOTE]
> **FQBN** stands for Fully Qualified Board Name.

## Connect board to PC

```console
$ arduino-cli board list
Port         Protocol Type              Board Name  FQBN            Core
/dev/ttyACM0 serial   Serial Port (USB) Arduino UNO arduino:avr:uno arduino:avr
```

## Compile and upload

```console
$ arduino-cli compile --fqbn arduino:avr:uno .
Sketch uses 2362 bytes (7%) of program storage space. Maximum is 32256 bytes.
Global variables use 362 bytes (17%) of dynamic memory, leaving 1686 bytes for local variables. Maximum is 2048 bytes.

$ arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno .
New upload port: /dev/ttyACM0 (serial)
```

## Serial monitoring

```console
$ arduino-cli monitor -p /dev/ttyACM0 -c baudrate=9600
Monitor port settings:
  baudrate=9600
  bits=8
  dtr=on
  parity=none
  rts=on
  stop_bits=1

Connecting to /dev/ttyACM0. Press CTRL-C to exit.
Arduino Morse Code
H -> ....
E -> .
L -> .-..
L -> .-..
O -> ---
R -> .-.
A -> .-
C -> -.-.
H -> ....
E -> .
L -> .-..
```

## References

- [Arduino-cli](https://docs.arduino.cc/arduino-cli/getting-started)
