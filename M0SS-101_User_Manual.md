M0SS-101 User Manual

1. Introduction
1.1. Connections
1.2. Extra Resources
2. Getting Started
2.1. How to Use the Interface
2.1.1. Editing Selectors
2.1.2. Editing Faders
2.1.3. Editing Switches
2.1.4. Numbered Settings
2.1.5. Preset Save/Load
2.1.6. MIDI Learn
2.1.7. Hidden and Service Controls
3. General Description
3.1. Front Panel Overview
3.2. Oscillators
3.2.1. OSC 1
3.2.2. OSC 2
3.2.3. XOR
3.3. MXR Mixer
3.4. NSE Noise
3.5. VCF Filter
3.6. LFO
3.7. ENV Envelope
3.7.1. ENV Inversion
3.8. Modulation Routing
3.9. VCA and Output Level
3.10. Delay
3.11. Tuning and Performance Controls
3.12. MIDI Implementation
3.13. Learnable Control List
4. Firmware Updates
5. Glossary

1. Introduction

The M0SS-101 is the first synthesizer in the M0SS family. It is a compact east-coast style monophonic synthesizer built around virtual analog subtractive synthesis. It starts with bright oscillator tones, mixes in noise and XOR textures, then shapes the result with a resonant filter, an amplifier, an envelope, and a delay.

East-coast synthesis is often associated with Bob Moog and classic subtractive synthesizers. A typical patch starts with harmonically rich waveforms like sawtooth and square waves, then removes or emphasizes parts of that spectrum with a voltage-controlled filter. The M0SS-101 follows that tradition, but uses digital synthesis running on a BL616 microcontroller and a small button-and-encoder interface instead of a large panel of knobs.

The M0SS-101 feature set includes:

Two oscillators with square, sawtooth, and stacked square-plus-saw waveforms
Octave control for both oscillators
Pulse width control for both oscillators
Detune for OSC 2
An XOR source derived from the two oscillator square waves
An MXR mixer for OSC 1, OSC 2, XOR, and noise
White or pink noise
A resonant filter with high-pass, low-pass, and band-pass modes
Optional key tracking for the filter
An LFO with triangle, square, and random waveforms
An ADSR envelope with adjustable curves
Virtual modulation routing from the LFO and envelope
A VCA with an envelope inversion mode
Glide, pitch bend range, fine tune, and transpose controls
A simple delay with time, feedback, and mix
TRS MIDI, USB MIDI host, MIDI thru, and MIDI learn
17 preset slots

The goal of the M0SS-101 is to put a complete subtractive monosynth in a small, portable form factor while keeping the important patching gestures visible on the panel.

1.1. Connections

The M0SS-101 is powered by a standard guitar-pedal style DC barrel jack. It takes 9V center negative power. The unit boots as soon as power is connected; there is no power switch.

Audio out is a standard mono unbalanced 1/4 inch line-level output. It is intended for an audio interface, mixer, amplifier, or pedal input. It is not intended to drive headphones directly.

There are two MIDI input options: TRS MIDI type A and USB host. The TRS input is for standard 1/8 inch type A MIDI connections. The USB host port can receive MIDI from a class-compliant USB MIDI controller and can power a small connected controller.

The M0SS-101 also includes TRS MIDI type A thru. MIDI received by the unit can be passed on to another device for daisy-chaining.

1.2. Extra Resources

Ultrapalace Youtube Channel: https://www.youtube.com/@ultrapalace
M0SS Discord Server: https://discord.gg/SX8BX6Hhq4
Ultrapalace Website: https://www.ultrapalace.com

2. Getting Started

Using a standard 9V center-negative guitar pedal power supply, plug in your M0SS-101. Connect a MIDI controller through either TRS MIDI or USB, then connect the audio output to a line input, mixer, or amplifier.

By default, the device responds to all MIDI channels (Omni). Press a key on your controller and you should hear the current patch. If no sound is heard, check that at least one MXR source is turned up, that the filter cutoff is not fully closed, that the master volume is up, and that the VCA is being opened by the envelope, LFO, or ENV inversion behavior.

The encoder edits the selected parameter. Pressing the encoder opens the gate while it is held, which triggers the envelope and is useful for testing patches without a MIDI keyboard.

On a first boot after flash initialization, the firmware saves the factory/default state into preset slot 17 and then loads slot 17 on startup.

2.1. How to Use the Interface

The M0SS family of products has a unique way of interacting with its parameters, which is what allows us to make the devices so small. Each button on the interface corresponds to a parameter, labelled above or beside the button. To select the parameter, simply press the button. There are also shift parameters, secondary functions for buttons indicated by labels in smaller text. To access these, hold the ALT button before pressing the button you want to select.

Parameters come in four common interaction types: Selectors, Faders, Switches, and Numbered Settings.

Most parameters have LED feedback. For many signals, the corresponding LED glows green and pulses with the signal level. When the LFO is in its high range, its modulation indicators shift toward red and yellow so that the color gives a sense of the frequency range.

2.1.1. Editing Selectors

Selectors choose one value from a small set of labelled options. Repeated presses of the selector button cycle through the available options.

Selectors on the M0SS-101 include OSC 1 waveform, OSC 1 octave, OSC 2 octave, OSC 2 waveform, LFO waveform, LFO to ENV trigger, and VCF filter type.

2.1.2. Editing Faders

Fader parameters are the equivalent of knobs on most synthesizers. Once a fader parameter is selected, the bottom row of LEDs shows the current value. LEDs fill from left to right, with the brightness of the final lit LED showing the value between steps. While a fader is selected, rotate the encoder to change its value.

Faders are used for continuous controls such as cutoff, resonance, envelope times, mix levels, modulation depths, delay controls, glide, and master volume.

Encoder acceleration is enabled. Slow turns edit in small steps; faster turns move in larger jumps.

2.1.3. Editing Switches

Switches have two states. When a switch is changed, the bottom row of LEDs briefly shows the state: one side of the row indicates off, and the other side indicates on.

Switch-style controls include noise color, LFO range, filter key tracking, and ENV inversion.

2.1.4. Numbered Settings

Some hidden ALT settings are displayed with numbered LEDs rather than the fader row. Hold the relevant ALT combination and turn the encoder; the lit numbered LED shows the current value.

Numbered settings include:

MIDI channel: 1-16, plus 17 for Omni
Pitch bend up range: 1-12 semitones
Pitch bend down range: 1-12 semitones
ENV curve: 1-9

2.1.5. Preset Save/Load

The M0SS-101 stores 17 presets. Preset slots are indicated using the numbered LEDs and controls on the panel.

To save a preset, follow the steps below.

Activate save mode by pressing ALT + CTF. The current slot glows blue, free slots glow green, and occupied slots glow pink.
Press any slot to save the current settings to that slot. This can overwrite an existing slot.

To load a preset, follow the steps below.

Activate load mode by pressing ALT + RES. The current slot glows blue, and loadable slots glow green.
Press any loadable slot to load it. Current settings will be lost if they have not been saved.

MIDI program change messages can also load presets. Program changes 0-16 load preset slots 1-17.

Presets store the synth parameter values and the current MIDI learn map. The MIDI channel is a global setting in current firmware; older per-preset MIDI-channel storage is ignored for compatibility.

2.1.6. MIDI Learn

The M0SS-101 does not have a fixed default external MIDI CC map. New CC mappings start empty, and external MIDI CCs do nothing until they are learned or loaded from a preset.

To map an external MIDI CC to a parameter:

Activate MIDI learn mode by pressing ALT + ENV.PWM. The LEDs will light pink.
Select a parameter by pressing its button. To select an ALT parameter, hold ALT, press the target button, then release the target button before releasing ALT. The LEDs will light green once a parameter is selected.
On your controller, send a MIDI CC by turning the knob, moving the slider, or pressing the control you want to assign. The LEDs will light blue.
Optionally repeat the previous two steps to map more controls.
Press ALT to exit MIDI learn mode.

To map velocity, enter MIDI learn, select a parameter, then play a MIDI note.

To map channel pressure, enter MIDI learn, select a parameter, then send channel pressure.

Save the preset to store the MIDI learn map.

2.1.7. Hidden and Service Controls

The M0SS-101 firmware includes several controls that are not primary front-panel labels.

ALT + LFO.PWM: set the global MIDI channel. Values 1-16 select a fixed MIDI channel. Value 17 selects Omni. This setting persists globally after a short delay.

ALT + LFO.OSC: set upward pitch bend range from 1-12 semitones.

ALT + LFO.VCF: set downward pitch bend range from 1-12 semitones.

ALT + A: set the envelope curve from 1-9. Lower values are more logarithmic, 5 is closest to linear, and higher values are more exponential.

Hold ALT and turn the encoder: fine tune in cents.

Hold ALT, press the encoder, and turn the encoder: transpose in semitones.

Press the encoder: open the gate while held, triggering the envelope.

ALT + LFO.ENV + encoder press, held for one second: enter reset selection. The LEDs flash while the reset chord is being held.

Reset selection has three outcomes:

Panic reset: hold ALT + LFO.ENV + encoder for one second, then release. The LEDs show the normal on color, and the device performs a software reset when the chord is released.

CC reset: while holding the reset chord, also hold the OSC 2 waveform button for one second. The LEDs turn blue. Releasing the chord clears the current runtime MIDI learn map. Save the preset afterward if you want that preset to remember the cleared map.

Factory reset: while holding the reset chord, also hold the OSC 1 waveform and OSC 2 waveform buttons for one second. The LEDs turn red. Releasing the chord erases the global configuration and reboots; on the next boot the firmware reinitializes flash storage, including preset storage.

Boot test mode: hold ALT + VOL while powering on. In test mode, the LEDs show hardware input activity: button presses, MIDI input, and encoder direction. This mode is intended for hardware testing.

3. General Description

The M0SS-101 signal path begins with two oscillators. Each oscillator can produce square, sawtooth, or a stacked square-plus-saw waveform. The oscillators feed the MXR mixer alongside the noise generator and an XOR signal derived from the oscillators. The mixed signal then passes through the filter, the VCA, and the delay before reaching the audio output.

The main modulation sources are the LFO and the envelope. These are internally routable to oscillator pitch, pulse width, filter cutoff, and the VCA. The LFO can also trigger the envelope, allowing patches to run without an external MIDI gate.

3.1. Front Panel Overview

The front panel is divided into the following functional areas.

OSC 1 controls the first oscillator's waveform, octave, pulse width, and level into MXR.
OSC 2 controls the second oscillator's waveform, octave, pulse width, detune, and level into MXR.
MXR controls the oscillator, XOR, and noise levels feeding the filter.
XOR is a digital logic-derived sound source based on the two oscillator square waves.
NSE controls the noise source, including white or pink noise and noise level.
VCF controls cutoff, resonance, filter type, and key tracking.
LFO controls the low frequency oscillator waveform, frequency, range, and modulation depths.
ENV controls the ADSR envelope, curve, inversion mode, and modulation depths.
VCA controls the output amplitude by combining ENV and LFO VCA modulation.
DLY controls delay time, feedback, and wet mix.
VOL controls the master output level.
ALT accesses secondary parameters.
The encoder edits the currently selected parameter and can be pressed to trigger the envelope.
The lower LED row displays parameter values, numbered selections, preset slots, and mode feedback.

3.2. Oscillators

The M0SS-101 has two main oscillators, labelled OSC 1 and OSC 2. They provide the raw material for classic subtractive patches, basses, leads, drones, and sharper digital textures through the XOR section.

3.2.1. OSC 1

OSC 1 can output square, sawtooth, or a stacked square-plus-saw waveform. The square wave provides a hollow tone, the sawtooth provides a bright tone with a full harmonic series, and the stacked mode gives a stronger composite signal.

OSC 1 octave selects 0, -1, or -2 octaves relative to the incoming pitch.

ALT + OSC 1 waveform selects OSC 1 pulse width. In current firmware the adjustable range is narrow, from 0.1 to 0.5, with the default at 0.5.

OSC 1 level is controlled in the MXR section.

3.2.2. OSC 2

OSC 2 can output square, sawtooth, or a stacked square-plus-saw waveform. OSC 2 octave selects 0, -1, or -2 octaves relative to the incoming pitch.

ALT + OSC 2 waveform selects OSC 2 pulse width. In current firmware the adjustable range is 0.1 to 0.5, with the default at 0.5.

ALT + OSC 2 octave selects detune. Detune offsets OSC 2 upward by as much as 1200 cents, useful for unison beating, fifth-like offsets, and thickened two-oscillator patches.

OSC 2 level is controlled in the MXR section.

3.2.3. XOR

The XOR source is created by applying a digital XOR operation to the OSC 1 and OSC 2 square waves. It produces a sharper and more synthetic tone than simply mixing the oscillators together.

XOR is especially useful when the two oscillators are tuned apart, because changes in their relationship create strong changes in the XOR tone.

XOR level is controlled with ALT + OSC 1 level in the MXR section.

3.3. MXR Mixer

MXR is the input mixer before the filter. It combines four sources:

OSC 1 level
OSC 2 level
XOR level
NSE noise level

The normal MXR controls set OSC 1 and OSC 2 levels. The ALT functions on those same controls set XOR level and noise level. Turning all four sources down will silence the synth before the filter and VCA.

3.4. NSE Noise

The noise generator can produce white or pink noise. White noise is brighter and more even across the spectrum. Pink noise has more low-frequency energy and often sounds smoother.

Noise color is selected with an ALT switch. Noise level is controlled in MXR.

Noise can be used for percussion, wind-like textures, attacks, or thickening oscillator sounds before the filter.

3.5. VCF Filter

The filter is one of the central parts of the M0SS-101 sound. It has three modes: high-pass, low-pass, and band-pass.

CTF controls cutoff. LFO.VCF and ENV.VCF are added to the cutoff value before smoothing and scaling.

RES controls resonance. Higher resonance settings make the filter more pronounced and can create whistling or ringing tones.

Low-pass mode removes high frequencies and is the classic subtractive synthesizer filter shape. It is useful for basses, leads, plucks, and most traditional patches.

High-pass mode removes low frequencies. It is useful for thinner sounds, sweeps, and patches that need to leave room for bass instruments.

Band-pass mode emphasizes a range around the cutoff frequency while reducing frequencies above and below that range. It is useful for narrow, vocal, or resonant tones.

K-T enables key tracking. With key tracking active, the low-pass filter cutoff follows incoming MIDI pitch, so higher notes have a higher cutoff and lower notes have a lower cutoff.

ALT + CTF activates save mode. ALT + RES activates load mode.

3.6. LFO

The LFO can produce triangle, square, or random waveforms. The triangle waveform moves smoothly up and down. The square waveform jumps between two values. The random waveform acts like a sample-and-hold source derived from the noise generator.

FRQ controls LFO frequency. In low range, the frequency spans approximately 0.01 Hz to 20 Hz. In high range, it spans approximately 20 Hz to 10 kHz.

LFO range is selected with ALT + FRQ. In high range, the LFO modulation LEDs use red/yellow temperature-style feedback rather than the normal green signal display.

LFO.ENV selects whether the envelope is triggered by MIDI gate or by the LFO square wave. With LFO.ENV enabled, the LFO square wave triggers the envelope, allowing repeating or self-running patches.

LFO modulation depth controls are:

LFO.PWM: LFO to oscillator pulse width
LFO.VCA: LFO to VCA
LFO.OSC: LFO to oscillator pitch
LFO.VCF: LFO to filter cutoff

3.7. ENV Envelope

The envelope is an ADSR envelope generator with attack, decay, sustain, and release controls. Attack controls how quickly the envelope rises, decay controls how quickly it falls to the sustain level, sustain controls the held level, and release controls how long it takes to fall after the note ends.

Envelope times range from extremely fast percussive shapes to long fades. Attack, decay, and release cover approximately 1 ms to 20 seconds after their internal scaling.

ALT + A controls the envelope curve from 1-9. Lower values are more logarithmic, 5 is closest to linear, and higher values are more exponential.

Envelope modulation depth controls are:

ENV.VCA: envelope to VCA
ENV.VCF: envelope to filter cutoff
ENV.OSC: envelope to oscillator pitch
ENV.PWM: envelope to oscillator pulse width

ALT + ENV.PWM activates MIDI learn mode.

3.7.1. ENV Inversion

ENV inversion changes how the ENV to VCA amount behaves. It is active by default.

With ENV inversion active, turning down ENV.VCA raises the minimum VCA level instead of simply reducing the maximum envelope level. This makes it possible to leave the VCA open for drones or to let the filter and other modulation sources define more of the audible shape.

With ENV inversion inactive, ENV.VCA behaves more intuitively: turning it down lowers the maximum envelope amount sent to the VCA.

A useful patch is to leave ENV inversion active, set ENV.VCA to 0 so the VCA stays open, set the low-pass filter cutoff low, then send ENV.VCF up. In this patch, the envelope shapes the sound by opening and closing the filter rather than by opening and closing the VCA.

3.8. Modulation Routing

The M0SS-101 has virtual patch points with gain controls. These route the LFO and envelope to important destinations without requiring patch cables.

LFO.OSC and ENV.OSC modulate oscillator pitch. Their pitch modulation is exponential, so higher amounts create wider pitch movement.

LFO.PWM and ENV.PWM modulate pulse width. Both oscillators are affected by the PWM routing.

LFO.VCF and ENV.VCF modulate filter cutoff.

LFO.VCA and ENV.VCA are added together, clipped between 0 and 1, and then multiplied by master volume.

3.9. VCA and Output Level

The VCA controls amplitude before the delay. In a typical patch, ENV.VCA is up so MIDI notes open the sound. LFO.VCA can be added for tremolo or chopped rhythmic effects.

VOL is the master output level after VCA calculation and before the final dry/delay mix.

If the VCA is open without envelope modulation, the synth can drone continuously. This is useful when shaping the sound with the filter or with LFO modulation rather than with MIDI gate.

3.10. Delay

The delay sits after the VCA. It has three ALT controls: D-TM, D-FB, and D-MX.

D-TM sets the delay time. Short delay times can create thickening or chorus-like effects, while longer times are heard as echoes.

D-FB sets how much delayed signal is fed back into the delay. Low settings create a single repeat or a small number of repeats. Higher settings create longer trails and can approach sustained echoes.

D-MX sets the wet mix of the delay in the final output. At 0, the delay is not heard. Higher values bring in more delayed signal. In current firmware the maximum wet amount is 50 percent.

3.11. Tuning and Performance Controls

GLIDE adds portamento to incoming MIDI notes. With glide turned up, pitch slides between notes instead of jumping immediately.

Pitch bend is received as standard 14-bit MIDI pitch bend. Upward and downward ranges are set separately with ALT + LFO.OSC and ALT + LFO.VCF.

The MIDI channel is global. Use ALT + LFO.PWM to select channel 1-16 or 17 for Omni. The firmware stores this global setting after a short debounce delay, and also writes it when saving a preset.

Hold ALT and turn the encoder for fine tune in cents.

Hold ALT, press the encoder, and turn the encoder for transpose in semitones.

The M0SS-101 uses last-note priority for held notes. If multiple MIDI notes are held, releasing the current note returns pitch to the most recent still-held note.

3.12. MIDI Implementation

The M0SS-101 receives MIDI note on, note off, pitch bend, control change, channel pressure, velocity, and program change messages. It can receive MIDI through TRS type A or USB host.

Incoming USB MIDI bytes and TRS MIDI bytes are also sent to the MIDI thru output.

Note-on with velocity 0 is treated as note-off.

Velocity and channel pressure do not have fixed destinations by default, but either can be learned to any learnable parameter.

External MIDI CC mapping is learned per preset. An unlearned external CC has no effect.

Program changes 0-16 load presets 1-17.

3.13. Learnable Control List

The following controls are learnable MIDI targets. These numbers are internal target numbers used by the firmware; they are not default external CC assignments. Any external CC can be learned to any listed target.

1: ENV Attack
2: VCF Cutoff
3: LFO Frequency
4: OSC 1 Level
5: OSC 2 Level
6: ENV Release
7: VCF Resonance
8: OSC 2 Detune
9: Master Volume
10: OSC 1 Waveform
11: OSC 1 Octave
12: OSC 2 Octave
13: OSC 2 Waveform
14: LFO Waveform
15: LFO to ENV trigger
16: VCF Filter Type
17: VCF Key Tracking
18: Noise Color
19: LFO Range
20: ENV Inversion
21: LFO to OSC
22: LFO to VCA
23: LFO to VCF
24: LFO to PWM
25: ENV to VCA
26: ENV to VCF
27: ENV to OSC
28: ENV to PWM
29: ENV Decay
30: ENV Sustain
31: OSC 1 Pulse Width
32: OSC 2 Pulse Width
33: XOR Level
34: Noise Level
35: Glide
36: Delay Time
37: Delay Feedback
38: Delay Mix
39: Pitch Bend Up Semitones
40: Pitch Bend Down Semitones
41: ENV Curve
42: Fine Tune
43: Transpose

MIDI channel itself is not a learnable MIDI target in current firmware; it is controlled from the panel with ALT + LFO.PWM.

4. Firmware Updates

The M0SS line of synths is digital, and firmware can be updated to add features or fix bugs. Firmware files for the M0SS-101 are available in the M0SS-101 firmware folder on GitHub.

The easiest update path is the web flasher utility. Use a Chromium-based browser such as Chrome or Edge, because the flasher uses Web Serial to talk to the device.

To update firmware:

Download the desired M0SS-101 firmware file from the M0SS-101 firmware folder on GitHub.
Open the web flasher utility in Chrome or Edge.
Connect the M0SS-101 to the computer with a USB data cable.
Put the M0SS-101 into bootloader/flashing mode as instructed by the flasher.
In the web flasher, choose the serial port for the device.
Select the downloaded firmware file.
Start the flash process and wait for it to finish before disconnecting power or USB.
Power-cycle the M0SS-101 after flashing.

Firmware updates may change synthesis behavior, preset storage, or hidden controls. Back up important patches when possible, and check the release notes for the firmware you are installing.

If you have feature requests, bug reports, or need help updating firmware, contact Ultrapalace through the Discord server or website.

5. Glossary

OSC: Oscillator
OSC 1 or OS1: Oscillator one
OSC 2 or OS2: Oscillator two
WAV: Waveform
SQR: Square wave
SAW: Sawtooth wave
PW: Pulse width
OCT: Octave
DTN: Detune
MXR: Mixer
NSE: Noise generator
XOR: Digital logic operation used as an audio source
LFO: Low frequency oscillator
WN: White noise
PN: Pink noise
TRI: Triangle waveform
RND: Random waveform, also called sample and hold
FRQ: Frequency
LO-HI: Low or high LFO range
VCF: Voltage-controlled filter
CTF: Cutoff
RES: Resonance
HP: High-pass filter
LP: Low-pass filter
BP: Band-pass filter
K-T: Key tracking
ENV: Envelope generator
A: Attack
D: Decay
S: Sustain
R: Release
VCA: Voltage-controlled amplifier
VOL: Master volume
D-TM: Delay time
D-FB: Delay feedback
D-MX: Delay mix
ALT: Shift button for secondary parameters
OMNI: MIDI mode where the device responds to all channels
