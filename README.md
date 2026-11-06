# M0SS-101 firmware

Firmware for BL616.

## Build environment (macOS)

Install Git, Make, CMake 3.x (3.15 or newer), and the T-Head RISC-V toolchain
(the local setup uses Xuantie v2.8.1 / GCC 10.4.0). Add the toolchain's `bin`
directory to `PATH` so `riscv64-unknown-elf-gcc` is available. See the SDK's
[toolchain setup](https://github.com/bouffalolab/bouffalo_sdk/tree/9a267ff0f9c40fce3efcd4c92a726349381a9b31#toolchain).

Clone the SDK at the exact commit used for this project, then clone this repo
inside it so the existing Makefile can find the SDK:

```sh
git clone https://github.com/bouffalolab/bouffalo_sdk.git
cd bouffalo_sdk
git checkout 9a267ff0f9c40fce3efcd4c92a726349381a9b31
git clone https://github.com/marchingband/M0SS-101.git
git apply M0SS-101/bouffalo-sdk.patch
cd M0SS-101
make CHIP=bl616 BOARD=bl616dk
```

[bouffalo-sdk.patch](bouffalo-sdk.patch) contains the local SDK board, macOS
tool selection, and bundled CherryUSB changes. CherryUSB and FreeRTOS are
included in the SDK at the pinned commit; no separate clones are needed.
The generated DSP header `m0s.h` is included, so Faust is not needed to build.

The firmware binary is `build/build_out/m0ss_bl616.bin`.

## Flash

Replace the serial port with your device's port:

```sh
make flash CHIP=bl616 COMX=/dev/cu.usbmodem1101
```
