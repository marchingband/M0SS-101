import("stdfaust.lib");

sm = ba.tau2pole(0.1);

clamp(low, high, x) = min(max( low, x), high);
log3(n) = n * n * n;

pitch = hslider("pitch[pitch]", 40, 0, 127, 1) : ba.midikey2hz : (_ * lfo_to_pitch) : (_ * env_to_pitch) : si.smooth(ba.tau2pole(glide)) : (_ * pitch_bend_ratio) : si.smooth(0.1);
pitch_ratio_440 = pitch / 440.0;
gate  = button("gate[gate]");
pitch_bend = hslider("pitch-bend[pitch-bend:0]", 8192, 0, 16383, 1); // 14bit

// CC 1-4 
attack    = hslider("attack[mod:16][midi:1]",    0.001, 0.001, 1,   0.0001) : log3 : it.remap(0.0, 1.0, 0.001, 20.0);
cutoff    = hslider("cutoff[mod:14][midi:2]",    0.5,   0,     1,   0.0001) : (_ + lfo_to_cuttoff + env_to_cutoff) : si.smooth(ba.tau2pole(0.05)) : ba.lin2LogGain : clamp(0, 1);
lfo_freq  = hslider("lfo-freq[mod:12][midi:3]",  0.3,   0.0,   1.0, 0.0001) : ba.lin2LogGain;
osc1_vol  = hslider("osc1-vol[mod:4][midi:4]",   0.5,   0,     0.5,   0.0001) : si.smooth(0.1);
osc2_vol  = hslider("osc2-vol[mod:5][midi:5]",   0.5,   0,     0.5,   0.0001) : si.smooth(0.1);

// CC 5-8
release       = hslider("release[mod:25][midi:6]",   0.001, 0.001, 1,  0.0001) : ba.lin2LogGain : it.remap(0.0, 1.0, 0.001, 20.0);
resonance     = hslider("resonance[mod:17][midi:7]", 0.001, 0.0,   1,  0.0001) : it.remap(0.0, 1.0, 0.707, 25.0);
detune        = hslider("detune[alt:2][midi:8]",     0,     0,     1, 0.0001) : ba.lin2LogGain: (_ * 1200) : ba.cent2ratio : si.smooth(0.1);
master_volume = hslider("volume[mod:23][midi:9]",    1,     0,     1,  0.001)  : si.smooth(0.1);

// selections
osc1_wavform = hslider("osc1-wavform[sel:0][midi:10]",   0, 0, 2, 1);
osc1_octave  = hslider("osc1-oct[sel:1][midi:11]",       0, 0, 2, 1);
osc2_octave  = hslider("osc2-oct[sel:2][midi:12]",       0, 0, 2, 1);
osc2_wavform = hslider("osc2-wavform[sel:3][midi:13]",   0, 0, 2, 1);
lfo_wavform  = hslider("lfo-wavform[sel:7][midi:14]",    0, 0, 2, 1);
lfo2env      = hslider("lfo-to-env[sel:9][midi:15]",     0, 0, 1, 1);
filter_type  = hslider("hp-lp-bp[sel:13][midi:16]",      1, 0, 2, 1);

// alternate selections
key_track    = hslider("key-track[alt-sel:13][midi:17]", 1, 0, 1, 1);
noise_color  = hslider("noise-color[alt-sel:7][midi:18]",0, 0, 1, 1);
lfo_range    = hslider("lfo-range[alt-sel:12][midi:19]", 0, 0, 1, 1);
env_vca_inv  = hslider("env-vca-inv[alt-sel:15][midi:20]", 1, 0, 1, 1);

// modifiers
lfo2pitch    = hslider("lfo-to-osc[mod:10][midi:21]",    0, 0, 1, 0.001) : ba.lin2LogGain;
lfo2vca      = hslider("lfo-to-vca[mod:8][midi:22]",     0, 0, 1, 0.001) ;
lfo2vcf      = hslider("lfo-to-vcf[mod:11][midi:23]",    0, 0, 1, 0.001) ;
lfo2pwm      = hslider("lfo-to-pwm[mod:6][midi:24]",     0, 0, 1, 0.001) ;

env2volume   = hslider("env-to-vca[mod:15][midi:25]",    1, 0, 1, 0.001) ;
env2cutoff   = hslider("env-to-vcf[mod:18][midi:26]",    0, 0, 1, 0.001) ;
env2pitch    = hslider("env-to-osc[mod:20][midi:27]",    0, 0, 1, 0.001) : ba.lin2LogGain;
env2pwm      = hslider("env-to-pwm[mod:24][midi:28]",    0, 0, 1, 0.001) ;

decay        = hslider("decay[mod:19][midi:29]",         0.001, 0.001, 1, 0.0001): ba.lin2LogGain : it.remap(0.0, 1.0, 0.001, 20.0);
// decay        = hslider("decay[mod:19][midi:29]",         0.01, 0.01, 1, 0.001) ;
sustain      = hslider("sustain[mod:21][midi:30]",       1,    0.001, 1, 0.001) ;

// alts
osc_1_pw     = hslider("osc-1-pw[alt:0][midi:31]",      0.5,   0.1,   0.9,  0.001) : si.smooth(sm);
osc_2_pw     = hslider("osc-2-pw[alt:3][midi:32]",      0.5,   0.1,   0.9,  0.001) : si.smooth(sm);
xor_volume   = hslider("xor-vol[alt:4][midi:33]",       0,     0,     1,    0.001) : si.smooth(0.1);
noise_volume = hslider("noise-vol[alt:5][midi:34]",     0,     0,     1,    0.001) : si.smooth(0.1);
glide        = hslider("glide[alt:23][midi:35]",        0.001, 0.001, 0.99, 0.001);
delay_time   = hslider("d_time[alt:19][midi:36]",       2^10,  2^10,  2^13, 0.001);
delay_fb     = hslider("d_fb[alt:21][midi:37]",         0,     0,     1,    0.001);
delay_wet    = hslider("d_wet[alt:25][midi:38]",        0,     0,     0.5,  0.001);

// assignables
midi_chan       = hslider("midi-chan[asb:6]", 1, 1, 16, 1) <: attach(vbargraph("dummy", 0 , 1));
pitch_bend_up   = hslider("pbend-up[asb:10][midi:39]", 2, 0, 12, 1);
pitch_bend_down = hslider("pbend-dn[asb:11][midi:40]", 2, 0, 12, 1);
adsr_bias       = hslider("adsr-bias[asb:16][midi:41]", 5, 1, 9, 1);

// noise
w_noise = no.noise;
p_noise = no.no.pink_noise * 3;
noise = w_noise,p_noise : ba.selectn(2, noise_color);
noise_out = noise * noise_volume;

// xor
xor_raw = osc1_square xor osc2_square;
xor_out = xor_raw * xor_volume;

// lfo
lfo_freq_low = lfo_freq : it.remap(0.0, 1.0, 0.01, 20.0);
lfo_freq_hi = lfo_freq : it.remap(0.0, 1.0, 20.0, 10000.0);
lfo_frequency = lfo_freq_low, lfo_freq_hi : ba.selectn(2, lfo_range);
lfo_tri = os.lf_trianglepos(lfo_frequency);
lfo_sq = os.lf_squarewavepos(lfo_frequency);
lfo_sh = noise / 2 + 0.5 : ba.latch(lfo_sq);
lfo = lfo_tri, lfo_sq, lfo_sh : ba.selectn(3, lfo_wavform) <: attach(vbargraph("lfo[lfo:0]", 0 , 1));
lfo_to_pitch   = (lfo - 0.5) * lfo2pitch * 100 * 127 : ba.cent2ratio;
lfo_to_cuttoff = lfo * lfo2vcf;
lfo_to_volume  = (lfo * lfo2vca) + 1;

// osc 1
osc1_pw = osc_1_pw * (1 - (lfo2pwm * lfo)) * (1 - env2pwm); // mod pulse wav duty

osc1_freq   = pitch, pitch / 2, pitch / 4 : ba.selectn(3, osc1_octave);
osc1_square = os.pulsetrain(osc1_freq, osc1_pw);
osc1_saw    = os.sawNp(2, osc1_freq, osc1_pw);
osc1        = osc1_square, osc1_saw, (osc1_square, osc1_saw :> _)  : ba.selectn(3, osc1_wavform) : (_ * osc1_vol);

// osc 2
osc2_freq   = pitch, pitch / 2, pitch / 4 : ba.selectn(3, osc2_octave) : (_ * detune);
osc2_square = os.pulsetrain(osc2_freq, osc_2_pw);
osc2_saw    = os.sawNp(2, osc2_freq, osc_2_pw);
osc2        = osc2_square, osc2_saw, (osc2_square, osc2_saw :> _) : ba.selectn(3, osc2_wavform) : (_ * osc2_vol);

// vcf
kt_cutoff = cutoff, cutoff * pitch_ratio_440 : ba.selectn(2, key_track) : clamp(0, 1);
lpf = ve.moogLadder(kt_cutoff, resonance);
hpf = ve.korg35HPF(cutoff, resonance / 3);
bpf = ve.oberheimBPF(cutoff, resonance);
vcf = _ <: hpf, lpf, bpf : ba.selectn(3, filter_type) ;

// env
bias_f = adsr_bias / 10;
env_trig = gate, lfo_sq : ba.selectn(2, lfo2env);
env = en.adsr_bias(attack, decay, sustain, release, 1.0 - bias_f, bias_f, bias_f, 1, env_trig) <: attach(vbargraph("env[env:0]", 0 , 1));
vca = env_to_volume * lfo_to_volume <: attach(vbargraph("vca[vca:0]", 0 , 1));

env_to_pitch  = env * env2pitch * 100 * 127 : ba.cent2ratio;
env_to_volume_norm = (env * env2volume);
env_to_volume_inv = 1 - ((1-env) * env2volume);
env_to_volume = env_to_volume_norm, env_to_volume_inv : ba.selectn(2, env_vca_inv);
env_to_cutoff = env * env2cutoff;

volume = vca * master_volume;
pitch_bend_float = pitch_bend / 8192.0 - 1;
pitch_bend_ratio = ba.if(pitch_bend_float > 0.0, pitch_bend_float * pitch_bend_up, pitch_bend_float * pitch_bend_down) : ba.semi2ratio : si.smoo;

dry = osc1, osc2, noise_out, xor_out :> vcf : (_ * volume);

delay_intrp  = 100 * ma.SR/1000.0;

wet = dry <: (+ : de.sdelay(int(2^13), delay_intrp, delay_time)) ~ *(delay_fb);
process = dry * (1 - delay_wet), wet * delay_wet :> _ ;
