`current version: 1.4`

WIP:

todo:
- test channel pressure and program change on usb
- test Prog Chang > 17

last:
- released dualenv firmware
- patched bug where toggles set the param
- staged flash changes for global persistent midi channel
- - causes a little audio glitch on change midi chan
- - adds schema version to manage firmware updates that don't wipe presets 
- env and lfo are additive not multiplicative
- global persistent midi channel
- env and lfo are additive not multiplicative
- Schema version 2, with migration
- minichord usb compat

next: 
- 11 banks of presets (use bytes for ccMap, and fit 4 per sector)
- migration v<1.2 -> v1.5