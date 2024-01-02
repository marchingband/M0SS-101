import("stdfaust.lib");

genfsqrt(maximum, x) = sqrt(maximum) * sqrt(x);
genfinvsqrt(maximum, x) = pow((x / sqrt(maximum)), 2);

fsqrt = genfsqrt(1);
finvsqrt = genfinvsqrt(1);

T = ma.T;
SR = ma.SR;
AR(att, rel, trigger) = loop ~ si.bus(2) : ! , _
    with {
        loop(clockState, yState) = clock , y
            with {
                clock = ba.if(trigger != 0, 1, clockState + 1);
                timeout = clock >= (att * SR);
                T60const = 1.0 / log(1000.0);
                attT60 = att * T60const;
                relT60 = rel * T60const;
                attCoeff = exp(-T / attT60);
                relCoeff = exp(-T / relT60);
                attCurve = attCoeff * yState + (1.0 - attCoeff);
                relCurve = relCoeff * yState;
                y = ba.if(timeout, relCurve, attCurve);
            };
    };

clamp(low, high, x) = min(max( low, x), high);
log3(n) = n * n * n;

pitch = hslider("pitch[pitch]", 40, 0, 127, 1) : ba.midikey2hz : (_ * lfo_to_pitch) : (_ * env_to_pitch) : si.smooth(ba.tau2pole(glide)) : (_ * pitch_bend_ratio) : si.smooth(0.1);
pitch_ratio_440 = pitch / 440.0;
gate  = button("gate[gate]");
pitch_bend = hslider("pitch-bend[pitch-bend:0]", 8192, 0, 16383, 1); // 14bit

// TODO use [scale:log]

// CC 1-4 
// attack    = hslider("attack[midi:1]",    0.001, 0.001, 1,   0.0001);
attack    = hslider("attack[midi:1]",    0.001, 0.001, 1,   0.0001) : log3 : it.remap(0.001, 1.0, 0.001, 20.0);
cutoff    = hslider("cutoff[midi:2]",    0.5,   0,     1,   0.0001) : ba.lin2LogGain : si.smooth(ba.tau2pole(0.05)) : (_ * lfo_to_cuttoff) : (_ * env_to_cutoff) : clamp(0, 1);
lfo_freq  = hslider("lfo-freq[midi:3]",  0.3,   0.0,   1.0, 0.0001) : ba.lin2LogGain : it.remap(0.0, 1.0, 0.01, 20.0);
mix       = hslider("mix[midi:4]",       0.5,   0,     1,   0.0001) : si.smooth(0.1);

// CC 5-8
// release       = hslider("release[midi:5]",   0.001, 0.001, 1,  0.0001);
release       = hslider("release[midi:5]",   0.001, 0.001, 1,  0.0001) : ba.lin2LogGain : it.remap(0.001, 1.0, 0.001, 20.0);
resonance     = hslider("resonance[midi:6]", 0.001, 0.001, 1,  0.0001) : it.remap(0.0, 1.0, 0.707, 25.0);
detune        = hslider("detune[midi:7]",    0,     0,     1, 0.0001) : ba.lin2LogGain: (_ * 1200) : ba.cent2ratio : si.smooth(0.1);
master_volume = hslider("volume[midi:8]",    1,     0,     1,  0.001)  : si.smooth(0.1);


// selections
osc1_wavform = hslider("osc1-wavform[sel:0]",   0, 0, 2, 1);       // button 0    // GPIO 30
osc1_octave  = hslider("osc1-oct[sel:1]",       0, 0, 2, 1);       // button 1    // GPIO 29
osc2_octave  = hslider("osc2-oct[sel:2]",       0, 0, 2, 1);       // button 3    // GPIO 27
osc2_wavform = hslider("osc2-wavform[sel:3]",   0, 0, 2, 1);       // button 2    // GPIO 28
lfo_wavform  = hslider("lfo-wavform[sel:7]",    0, 0, 2, 1);       // button 5    // GPIO 20
lfo2env      = hslider("lfo-to-env[sel:9]",     0, 0, 1, 1);       // button 7    // GPIO 10 
filter_type  = hslider("hp-lp-bp[sel:13]",       1, 0, 2, 1);       // button 9    // GPIO 17
// asr_ar       = hslider("env-type[sel:1]",      0, 0, 1, 1);       // button 11   // GPIO 15

// modifiers
lfo2pitch    = hslider("lfo-to-osc[mod:10]",     0, 0, 1, 0.001) ;   // button 4    // GPIO 16
lfo2vca      = hslider("lfo-to-vca[mod:8]",     0, 0, 1, 0.001) ;   // button 6    // GPIO 12
lfo2vcf      = hslider("lfo-to-vcf[mod:11]",     0, 0, 1, 0.001) ;   // button 8    // GPIO 13
env2volume   = hslider("env-to-vca[mod:15]",    1, 0, 1, 0.001) ;   // button 10   // GPIO 3
env2cutoff   = hslider("env-to-vcf[mod:18]",    0, 0, 1, 0.001) ;   // button 12   // GPIO 1
env2pitch    = hslider("env-to-osc[mod:20]",    0, 0, 1, 0.001) ;   // button 13   // GPIO 0
decay        = hslider("decay[mod:19]",         0.001, 0.001, 1, 0.001) ;   // button 13   // GPIO 0
sustain      = hslider("sustain[mod:21]",       1, 0.001, 1, 0.001) ;   // button 13   // GPIO 0

// alts
osc_1_pw     = hslider("osc-1-pw[alt:0]",     0.5,   0.1,   0.9,  0.0001) : si.smooth(0.1);      // button 0    // GPIO 30
glide        = hslider("glide[alt:23]",        0.001, 0.001, 0.99, 0.0001);                 // button 1    // GPIO 29
osc_2_pw     = hslider("osc-2-pw[alt:3]",     0.5,   0.1,   0.9,  0.0001) : si.smooth(0.1);      // button 2    // GPIO 28
xor_volume   = hslider("xor-vol[alt:4]",      0,     0,     1,    0.0001) : si.smooth(0.1);      // button 3    // GPIO 27
noise_volume = hslider("noise-vol[alt:5]",    0,     0,     1,    0.0001) : si.smooth(0.1);      // button 5    // GPIO 20

// assignables
pitch_bend_up   = hslider("pbend_up[asb:0]", 2,  0, 24, 1);
pitch_bend_down = hslider("pbend_dn[asb:1]", 12, 0, 24, 1);

// noise
noise = no.noise;
noise_out = noise * noise_volume;

// xor
xor_raw = osc1_square xor osc2_square;
xor_out = xor_raw * xor_volume;

// lfo
lfo_tri = os.lf_triangle(lfo_freq);
lfo_sq = os.lf_squarewavepos (lfo_freq);
lfo_sh = noise : ba.latch(lfo_sq);
lfo = lfo_tri, lfo_sq, lfo_sh : ba.selectn(3, lfo_wavform) <: attach(vbargraph("lfo[lfo:0]", 0 , 1));
lfo_to_pitch   = (lfo - 0.5) * lfo2pitch * 1200 : ba.cent2ratio;
lfo_to_cuttoff = (lfo - 0.5) * lfo2vcf * 1200 : ba.cent2ratio;
lfo_to_volume  = (lfo * lfo2vca) + 1;

// osc 1
osc1_volume = mix;
osc1_freq   = pitch, pitch / 2, pitch / 4 : ba.selectn(3, osc1_octave);
osc1_square = os.pulsetrain(osc1_freq, osc_1_pw);
osc1_saw    = os.sawNp(2, osc1_freq, 0);
osc1        = osc1_square, osc1_saw, (osc1_square, osc1_saw :> _)  : ba.selectn(3, osc1_wavform) : (_ * osc1_volume);

// osc 2
osc2_volume = 1 - mix;
osc2_freq   = pitch, pitch / 2, pitch / 4 : ba.selectn(3, osc2_octave) : (_ * detune);
osc2_square = os.pulsetrain(osc2_freq, osc_2_pw);
osc2_saw    = os.sawNp(2, osc2_freq, 0);
osc2        = osc2_square, osc2_saw, (osc2_square, osc2_saw :> _) : ba.selectn(3, osc2_wavform) : (_ * osc2_volume);

// vcf
lpf = ve.moogLadder(cutoff : (_ * pitch_ratio_440), resonance);
hpf = ve.korg35HPF(cutoff, resonance / 3);
bpf = ve.oberheimBPF(cutoff, resonance);
vcf = _ <: hpf, lpf, bpf : ba.selectn(3, filter_type) ;

// env
env_trig = gate, lfo_sq : ba.selectn(2, lfo2env);
// bias = 0.7;
// asr = en.adsr_bias(attack, 0, 1, release, bias, bias, bias, 1, env_trig);
// env = en.adsr_bias(attack, decay, sustain, release, bias, bias, bias, 1, env_trig);
env = en.adsr(attack, decay, sustain, release, env_trig) <: attach(vbargraph("env[env:0]", 0 , 1));
// env = en.asre(attack, 1, release, env_trig) <: attach(vbargraph("env[env:0]", 0 , 1));
// ar_trig = env_trig : \(x).(x > x');
// ar = AR(attack, release, ar_trig);
// env = asr <: attach(vbargraph("env[env:0]", 0 , 1));
// env = asr, ar : ba.selectn(2, asr_ar) <: attach(vbargraph("env[env:0]", 0 , 1));

env_to_pitch  = env * env2pitch * 100 : ba.cent2ratio;
env_to_volume = (env * env2volume) ;
env_to_cutoff = (env * env2cutoff * 2600) : ba.cent2ratio;

volume = env_to_volume * lfo_to_volume * master_volume;
pitch_bend_float = pitch_bend / 8192.0 - 1;
pitch_bend_ratio = ba.if(pitch_bend_float > 0.0, pitch_bend_float * pitch_bend_up, pitch_bend_float * pitch_bend_down) : ba.semi2ratio : si.smoo;

process = osc1, osc2, noise_out, xor_out :> vcf : (_ * volume);