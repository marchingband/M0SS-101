/* ------------------------------------------------------------
name: "m0ss"
Code generated with Faust 2.68.6 (https://faust.grame.fr)
Compilation options: -lang c -ct 1 -es 1 -mcd 16 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 


#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

static float mydsp_faustpower2_f(float value) {
	return value * value;
}
static float mydsp_faustpower3_f(float value) {
	return value * value * value;
}
static float mydsp_faustpower4_f(float value) {
	return value * value * value * value;
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

typedef struct {
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int iVec0[2];
	float fRec0[2];
	FAUSTFLOAT fHslider2;
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	float fConst4;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fRec6[2];
	float fVec1[2];
	FAUSTFLOAT fHslider8;
	int iRec8[2];
	float fRec9[4];
	float fRec7[2];
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fButton0;
	int iRec12[2];
	int iRec10[2];
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fHslider12;
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	int iVec2[2];
	float fRec13[2];
	FAUSTFLOAT fHslider15;
	float fRec11[2];
	FAUSTFLOAT fVbargraph1;
	float fRec5[2];
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fHslider17;
	float fRec14[2];
	FAUSTFLOAT fHslider18;
	float fConst5;
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fHslider21;
	FAUSTFLOAT fHslider22;
	FAUSTFLOAT fHslider23;
	float fRec17[2];
	float fConst6;
	FAUSTFLOAT fHslider24;
	FAUSTFLOAT fHslider25;
	FAUSTFLOAT fHslider26;
	float fConst7;
	float fRec18[2];
	FAUSTFLOAT fHslider27;
	FAUSTFLOAT fHslider28;
	float fRec16[2];
	float fRec15[2];
	float fVec3[2];
	int IOTA0;
	float fVec4[4096];
	FAUSTFLOAT fHslider29;
	float fConst8;
	float fConst9;
	float fConst10;
	FAUSTFLOAT fHslider30;
	float fRec19[2];
	FAUSTFLOAT fHslider31;
	float fRec20[2];
	float fVec5[2];
	float fVec6[8192];
	FAUSTFLOAT fHslider32;
	float fRec21[2];
	FAUSTFLOAT fHslider33;
	FAUSTFLOAT fHslider34;
	float fRec23[2];
	FAUSTFLOAT fHslider35;
	float fRec22[2];
	float fVec7[2];
	float fVec8[4096];
	FAUSTFLOAT fHslider36;
	float fRec24[2];
	float fRec25[2];
	float fVec9[2];
	float fVec10[8192];
	FAUSTFLOAT fHslider37;
	float fRec26[2];
	FAUSTFLOAT fHslider38;
	float fRec27[2];
	float fRec1[2];
	float fRec3[2];
	float fRec4[2];
	FAUSTFLOAT fHslider39;
	float fRec28[2];
	float fRec29[2];
	float fRec30[2];
	float fRec31[2];
	float fRec34[2];
	float fRec35[2];
	FAUSTFLOAT fHslider40;
	FAUSTFLOAT fHslider41;
	FAUSTFLOAT fHslider42;
	FAUSTFLOAT fVbargraph2;
	FAUSTFLOAT fHslider43;
	float fVec11[16384];
	FAUSTFLOAT fHslider44;
	float fRec37[2];
	float fRec38[2];
	float fRec39[2];
	float fRec40[2];
	float fRec36[2];
} mydsp;

mydsp* newmydsp() { 
	mydsp* dsp = (mydsp*)calloc(1, sizeof(mydsp));
	return dsp;
}

void deletemydsp(mydsp* dsp) { 
	free(dsp);
}

void metadatamydsp(MetaGlue* m) { 
	m->declare(m->metaInterface, "aanl.lib/name", "Faust Antialiased Nonlinearities");
	m->declare(m->metaInterface, "aanl.lib/version", "1.3.0");
	m->declare(m->metaInterface, "basics.lib/name", "Faust Basic Element Library");
	m->declare(m->metaInterface, "basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
	m->declare(m->metaInterface, "basics.lib/version", "1.11.1");
	m->declare(m->metaInterface, "compile_options", "-lang c -ct 1 -es 1 -mcd 16 -single -ftz 0");
	m->declare(m->metaInterface, "delays.lib/name", "Faust Delay Library");
	m->declare(m->metaInterface, "delays.lib/version", "1.1.0");
	m->declare(m->metaInterface, "envelopes.lib/adsr_bias:author", "Andrew John March and David Braun");
	m->declare(m->metaInterface, "envelopes.lib/adsr_bias:licence", "STK-4.3");
	m->declare(m->metaInterface, "envelopes.lib/author", "GRAME");
	m->declare(m->metaInterface, "envelopes.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "envelopes.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "envelopes.lib/name", "Faust Envelope Library");
	m->declare(m->metaInterface, "envelopes.lib/version", "1.3.0");
	m->declare(m->metaInterface, "filename", "m0ss.dsp");
	m->declare(m->metaInterface, "filters.lib/fir:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/fir:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/iir:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/iir:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/name", "Faust Filters Library");
	m->declare(m->metaInterface, "filters.lib/version", "1.3.0");
	m->declare(m->metaInterface, "interpolators.lib/name", "Faust Interpolator Library");
	m->declare(m->metaInterface, "interpolators.lib/remap:author", "David Braun");
	m->declare(m->metaInterface, "interpolators.lib/version", "1.3.0");
	m->declare(m->metaInterface, "maths.lib/author", "GRAME");
	m->declare(m->metaInterface, "maths.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "maths.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "maths.lib/name", "Faust Math Library");
	m->declare(m->metaInterface, "maths.lib/version", "2.7.0");
	m->declare(m->metaInterface, "misceffects.lib/cubicnl:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "misceffects.lib/cubicnl:license", "STK-4.3");
	m->declare(m->metaInterface, "misceffects.lib/name", "Misc Effects Library");
	m->declare(m->metaInterface, "misceffects.lib/version", "2.4.0");
	m->declare(m->metaInterface, "name", "m0ss");
	m->declare(m->metaInterface, "noises.lib/name", "Faust Noise Generator Library");
	m->declare(m->metaInterface, "noises.lib/version", "1.4.0");
	m->declare(m->metaInterface, "oscillators.lib/lf_sawpos:author", "Bart Brouns, revised by Stéphane Letz");
	m->declare(m->metaInterface, "oscillators.lib/lf_sawpos:licence", "STK-4.3");
	m->declare(m->metaInterface, "oscillators.lib/name", "Faust Oscillator Library");
	m->declare(m->metaInterface, "oscillators.lib/saw1:author", "Bart Brouns");
	m->declare(m->metaInterface, "oscillators.lib/saw1:licence", "STK-4.3");
	m->declare(m->metaInterface, "oscillators.lib/sawN:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "oscillators.lib/sawN:license", "STK-4.3");
	m->declare(m->metaInterface, "oscillators.lib/sawNp:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "oscillators.lib/sawNp:license", "STK-4.3");
	m->declare(m->metaInterface, "oscillators.lib/version", "1.4.0");
	m->declare(m->metaInterface, "platform.lib/name", "Generic Platform Library");
	m->declare(m->metaInterface, "platform.lib/version", "1.3.0");
	m->declare(m->metaInterface, "signals.lib/name", "Faust Signal Routing Library");
	m->declare(m->metaInterface, "signals.lib/version", "1.5.0");
	m->declare(m->metaInterface, "vaeffects.lib/korg35HPF:author", "Eric Tarr");
	m->declare(m->metaInterface, "vaeffects.lib/korg35HPF:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "vaeffects.lib/moogLadder:author", "Dario Sanfilippo");
	m->declare(m->metaInterface, "vaeffects.lib/moogLadder:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
	m->declare(m->metaInterface, "vaeffects.lib/oberheim:author", "Eric Tarr");
	m->declare(m->metaInterface, "vaeffects.lib/oberheim:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "vaeffects.lib/oberheimBPF:author", "Eric Tarr");
	m->declare(m->metaInterface, "vaeffects.lib/oberheimBPF:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "vaeffects.lib/version", "1.2.0");
}

int getSampleRatemydsp(mydsp* RESTRICT dsp) {
	return dsp->fSampleRate;
}

int getNumInputsmydsp(mydsp* RESTRICT dsp) {
	return 0;
}
int getNumOutputsmydsp(mydsp* RESTRICT dsp) {
	return 1;
}

void classInitmydsp(int sample_rate) {
}

void instanceResetUserInterfacemydsp(mydsp* dsp) {
	dsp->fHslider0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider1 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider2 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider3 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider4 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider5 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider6 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider7 = (FAUSTFLOAT)(0.3f);
	dsp->fHslider8 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider9 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider10 = (FAUSTFLOAT)(0.0f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider11 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider12 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider13 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider14 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider15 = (FAUSTFLOAT)(5.0f);
	dsp->fHslider16 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider17 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider18 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider19 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider20 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider21 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider22 = (FAUSTFLOAT)(4e+01f);
	dsp->fHslider23 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider24 = (FAUSTFLOAT)(8192.0f);
	dsp->fHslider25 = (FAUSTFLOAT)(2.0f);
	dsp->fHslider26 = (FAUSTFLOAT)(2.0f);
	dsp->fHslider27 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider28 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider29 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider30 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider31 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider32 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider33 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider34 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider35 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider36 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider37 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider38 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider39 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider40 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider41 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider42 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider43 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider44 = (FAUSTFLOAT)(1024.0f);
}

void instanceClearmydsp(mydsp* dsp) {
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; l0 < 2; l0 = l0 + 1) {
			dsp->iVec0[l0] = 0;
		}
	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; l1 < 2; l1 = l1 + 1) {
			dsp->fRec0[l1] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 2; l2 = l2 + 1) {
			dsp->fRec6[l2] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1) {
			dsp->fVec1[l3] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->iRec8[l4] = 0;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 4; l5 = l5 + 1) {
			dsp->fRec9[l5] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->fRec7[l6] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 2; l7 = l7 + 1) {
			dsp->iRec12[l7] = 0;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 2; l8 = l8 + 1) {
			dsp->iRec10[l8] = 0;
		}
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 2; l9 = l9 + 1) {
			dsp->iVec2[l9] = 0;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 2; l10 = l10 + 1) {
			dsp->fRec13[l10] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 2; l11 = l11 + 1) {
			dsp->fRec11[l11] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l12;
		for (l12 = 0; l12 < 2; l12 = l12 + 1) {
			dsp->fRec5[l12] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l13;
		for (l13 = 0; l13 < 2; l13 = l13 + 1) {
			dsp->fRec14[l13] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l14;
		for (l14 = 0; l14 < 2; l14 = l14 + 1) {
			dsp->fRec17[l14] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l15;
		for (l15 = 0; l15 < 2; l15 = l15 + 1) {
			dsp->fRec18[l15] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l16;
		for (l16 = 0; l16 < 2; l16 = l16 + 1) {
			dsp->fRec16[l16] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l17;
		for (l17 = 0; l17 < 2; l17 = l17 + 1) {
			dsp->fRec15[l17] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l18;
		for (l18 = 0; l18 < 2; l18 = l18 + 1) {
			dsp->fVec3[l18] = 0.0f;
		}
	}
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l19;
		for (l19 = 0; l19 < 4096; l19 = l19 + 1) {
			dsp->fVec4[l19] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l20;
		for (l20 = 0; l20 < 2; l20 = l20 + 1) {
			dsp->fRec19[l20] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l21;
		for (l21 = 0; l21 < 2; l21 = l21 + 1) {
			dsp->fRec20[l21] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l22;
		for (l22 = 0; l22 < 2; l22 = l22 + 1) {
			dsp->fVec5[l22] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l23;
		for (l23 = 0; l23 < 8192; l23 = l23 + 1) {
			dsp->fVec6[l23] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l24;
		for (l24 = 0; l24 < 2; l24 = l24 + 1) {
			dsp->fRec21[l24] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l25;
		for (l25 = 0; l25 < 2; l25 = l25 + 1) {
			dsp->fRec23[l25] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l26;
		for (l26 = 0; l26 < 2; l26 = l26 + 1) {
			dsp->fRec22[l26] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l27;
		for (l27 = 0; l27 < 2; l27 = l27 + 1) {
			dsp->fVec7[l27] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l28;
		for (l28 = 0; l28 < 4096; l28 = l28 + 1) {
			dsp->fVec8[l28] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l29;
		for (l29 = 0; l29 < 2; l29 = l29 + 1) {
			dsp->fRec24[l29] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l30;
		for (l30 = 0; l30 < 2; l30 = l30 + 1) {
			dsp->fRec25[l30] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l31;
		for (l31 = 0; l31 < 2; l31 = l31 + 1) {
			dsp->fVec9[l31] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l32;
		for (l32 = 0; l32 < 8192; l32 = l32 + 1) {
			dsp->fVec10[l32] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l33;
		for (l33 = 0; l33 < 2; l33 = l33 + 1) {
			dsp->fRec26[l33] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l34;
		for (l34 = 0; l34 < 2; l34 = l34 + 1) {
			dsp->fRec27[l34] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l35;
		for (l35 = 0; l35 < 2; l35 = l35 + 1) {
			dsp->fRec1[l35] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l36;
		for (l36 = 0; l36 < 2; l36 = l36 + 1) {
			dsp->fRec3[l36] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l37;
		for (l37 = 0; l37 < 2; l37 = l37 + 1) {
			dsp->fRec4[l37] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l38;
		for (l38 = 0; l38 < 2; l38 = l38 + 1) {
			dsp->fRec28[l38] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l39;
		for (l39 = 0; l39 < 2; l39 = l39 + 1) {
			dsp->fRec29[l39] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l40;
		for (l40 = 0; l40 < 2; l40 = l40 + 1) {
			dsp->fRec30[l40] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l41;
		for (l41 = 0; l41 < 2; l41 = l41 + 1) {
			dsp->fRec31[l41] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l42;
		for (l42 = 0; l42 < 2; l42 = l42 + 1) {
			dsp->fRec34[l42] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l43;
		for (l43 = 0; l43 < 2; l43 = l43 + 1) {
			dsp->fRec35[l43] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l44;
		for (l44 = 0; l44 < 16384; l44 = l44 + 1) {
			dsp->fVec11[l44] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l45;
		for (l45 = 0; l45 < 2; l45 = l45 + 1) {
			dsp->fRec37[l45] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l46;
		for (l46 = 0; l46 < 2; l46 = l46 + 1) {
			dsp->fRec38[l46] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l47;
		for (l47 = 0; l47 < 2; l47 = l47 + 1) {
			dsp->fRec39[l47] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l48;
		for (l48 = 0; l48 < 2; l48 = l48 + 1) {
			dsp->fRec40[l48] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l49;
		for (l49 = 0; l49 < 2; l49 = l49 + 1) {
			dsp->fRec36[l49] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 6.2831855f / dsp->fConst0;
	dsp->fConst2 = expf(-(2e+01f / dsp->fConst0));
	dsp->fConst3 = 1.0f - dsp->fConst2;
	dsp->fConst4 = 1.0f / dsp->fConst0;
	dsp->fConst5 = 0.25f * dsp->fConst0;
	dsp->fConst6 = 44.1f / dsp->fConst0;
	dsp->fConst7 = 1.0f - dsp->fConst6;
	dsp->fConst8 = 1e+01f / dsp->fConst0;
	dsp->fConst9 = expf(-dsp->fConst8);
	dsp->fConst10 = 1.0f - dsp->fConst9;
}

void instanceInitmydsp(mydsp* dsp, int sample_rate) {
	instanceConstantsmydsp(dsp, sample_rate);
	instanceResetUserInterfacemydsp(dsp);
	instanceClearmydsp(dsp);
}

void initmydsp(mydsp* dsp, int sample_rate) {
	classInitmydsp(sample_rate);
	instanceInitmydsp(dsp, sample_rate);
}

void buildUserInterfacemydsp(mydsp* dsp, UIGlue* ui_interface) {
	ui_interface->openVerticalBox(ui_interface->uiInterface, "m0ss");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "asb", "16");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "midi", "41");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "adsr-bias", &dsp->fHslider15, (FAUSTFLOAT)5.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)9.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "midi", "1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "mod", "16");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "attack", &dsp->fHslider13, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "midi", "2");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "mod", "14");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoff", &dsp->fHslider3, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider43, "alt", "21");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider43, "midi", "37");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "d_fb", &dsp->fHslider43, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider44, "alt", "19");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider44, "midi", "36");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "d_time", &dsp->fHslider44, (FAUSTFLOAT)1024.0f, (FAUSTFLOAT)1024.0f, (FAUSTFLOAT)8192.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "alt", "25");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "midi", "38");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "d_wet", &dsp->fHslider0, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "midi", "29");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "mod", "19");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "decay", &dsp->fHslider12, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider34, "alt", "2");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider34, "midi", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "detune", &dsp->fHslider34, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider28, "midi", "27");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider28, "mod", "20");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-osc", &dsp->fHslider28, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider29, "midi", "28");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider29, "mod", "24");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-pwm", &dsp->fHslider29, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider41, "midi", "25");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider41, "mod", "15");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vca", &dsp->fHslider41, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "midi", "26");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "mod", "18");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vcf", &dsp->fHslider9, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider40, "alt-sel", "15");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider40, "midi", "20");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-vca-inv", &dsp->fHslider40, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph1, "env", "");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "env", &dsp->fVbargraph1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "fine-tune", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "midi", "42");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "fine-tune", &dsp->fHslider20, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)-1e+02f, (FAUSTFLOAT)1e+02f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fButton0, "gate", "");
	ui_interface->addButton(ui_interface->uiInterface, "gate", &dsp->fButton0);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider23, "alt", "23");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider23, "midi", "35");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "glide", &dsp->fHslider23, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.99f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "midi", "16");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "sel", "13");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "hp-lp-bp", &dsp->fHslider2, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider39, "alt-sel", "13");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider39, "midi", "17");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "key-track", &dsp->fHslider39, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "midi", "3");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "mod", "12");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-freq", &dsp->fHslider7, (FAUSTFLOAT)0.3f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "alt-sel", "12");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "midi", "19");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-range", &dsp->fHslider6, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "midi", "15");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "sel", "9");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-env", &dsp->fHslider10, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider27, "midi", "21");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider27, "mod", "10");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-osc", &dsp->fHslider27, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider31, "midi", "24");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider31, "mod", "6");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-pwm", &dsp->fHslider31, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider42, "midi", "22");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider42, "mod", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vca", &dsp->fHslider42, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "midi", "23");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "mod", "11");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vcf", &dsp->fHslider4, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "midi", "14");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "sel", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-wavform", &dsp->fHslider5, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph0, "lfo", "");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "lfo", &dsp->fVbargraph0, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "alt-sel", "7");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "midi", "18");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "noise-color", &dsp->fHslider8, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider37, "alt", "5");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider37, "midi", "34");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "noise-vol", &dsp->fHslider37, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider30, "alt", "0");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider30, "midi", "31");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-1-pw", &dsp->fHslider30, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider36, "alt", "3");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider36, "midi", "32");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-2-pw", &dsp->fHslider36, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "midi", "11");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "sel", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-oct", &dsp->fHslider19, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "midi", "4");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "mod", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-vol", &dsp->fHslider17, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "midi", "10");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "sel", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-wavform", &dsp->fHslider18, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider35, "midi", "12");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider35, "sel", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-oct", &dsp->fHslider35, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider32, "midi", "5");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider32, "mod", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-vol", &dsp->fHslider32, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider33, "midi", "13");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider33, "sel", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-wavform", &dsp->fHslider33, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider25, "asb", "11");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider25, "midi", "40");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend-dn", &dsp->fHslider25, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)12.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider26, "asb", "10");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider26, "midi", "39");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend-up", &dsp->fHslider26, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)12.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider24, "pitch-bend", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch-bend", &dsp->fHslider24, (FAUSTFLOAT)8192.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)16383.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "pitch", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch", &dsp->fHslider22, (FAUSTFLOAT)4e+01f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)127.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "midi", "6");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "mod", "25");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "release", &dsp->fHslider14, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "midi", "7");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "mod", "17");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "resonance", &dsp->fHslider16, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "midi", "30");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "mod", "21");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "sustain", &dsp->fHslider11, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider21, "midi", "43");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider21, "transpose", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "transpose", &dsp->fHslider21, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)-127.0f, (FAUSTFLOAT)127.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph2, "vca", "");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "vca", &dsp->fVbargraph2, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "midi", "9");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "mod", "23");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "volume", &dsp->fHslider1, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider38, "alt", "4");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider38, "midi", "33");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "xor-vol", &dsp->fHslider38, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	float fSlow0 = (float)(dsp->fHslider0);
	float fSlow1 = 1.0f - fSlow0;
	float fSlow2 = 0.9f * (float)(dsp->fHslider1);
	float fSlow3 = (float)(dsp->fHslider2);
	int iSlow4 = fSlow3 >= 2.0f;
	int iSlow5 = fSlow3 >= 1.0f;
	float fSlow6 = (float)(dsp->fHslider3);
	float fSlow7 = (float)(dsp->fHslider4);
	float fSlow8 = (float)(dsp->fHslider5);
	int iSlow9 = fSlow8 >= 2.0f;
	int iSlow10 = fSlow8 >= 1.0f;
	float fSlow11 = mydsp_faustpower2_f((float)(dsp->fHslider7));
	float fSlow12 = dsp->fConst4 * (((float)(dsp->fHslider6) >= 1.0f) ? 9.98e+03f * fSlow11 + 2e+01f : 19.99f * fSlow11 + 0.01f);
	int iSlow13 = (float)(dsp->fHslider8) >= 1.0f;
	float fSlow14 = (float)(dsp->fHslider9);
	int iSlow15 = (float)(dsp->fHslider10) >= 1.0f;
	float fSlow16 = (float)(dsp->fButton0);
	float fSlow17 = (float)(dsp->fHslider11);
	float fSlow18 = (fSlow17 + -1.0f) / fmaxf(1.0f, dsp->fConst0 * (19.999f * mydsp_faustpower2_f((float)(dsp->fHslider12)) + 0.001f));
	float fSlow19 = 1.0f / fmaxf(1.0f, dsp->fConst0 * (19.999f * mydsp_faustpower3_f((float)(dsp->fHslider13)) + 0.001f));
	float fSlow20 = 1.0f / fmaxf(1.0f, dsp->fConst0 * (19.999f * mydsp_faustpower2_f((float)(dsp->fHslider14)) + 0.001f));
	float fSlow21 = 0.1f * (float)(dsp->fHslider15);
	float fSlow22 = 1.0f - fSlow21;
	float fSlow23 = (float)(dsp->fHslider16);
	float fSlow24 = 24.293f * fSlow23 + 0.707f;
	float fSlow25 = 0.21521576f * (0.33333334f * fSlow24 + -0.707f);
	float fSlow26 = 0.9f * (float)(dsp->fHslider17);
	float fSlow27 = (float)(dsp->fHslider18);
	int iSlow28 = fSlow27 >= 2.0f;
	int iSlow29 = fSlow27 >= 1.0f;
	float fSlow30 = (float)(dsp->fHslider19);
	int iSlow31 = fSlow30 >= 2.0f;
	int iSlow32 = fSlow30 >= 1.0f;
	float fSlow33 = 0.9f * powf(2.0f, 0.00083333335f * (float)(dsp->fHslider20)) * powf(2.0f, 0.083333336f * (float)(dsp->fHslider21));
	float fSlow34 = (float)(dsp->fHslider23);
	int iSlow35 = fabsf(fSlow34) < 1.1920929e-07f;
	float fSlow36 = ((iSlow35) ? 0.0f : expf(-(dsp->fConst4 / ((iSlow35) ? 1.0f : fSlow34))));
	float fSlow37 = 4.4e+02f * powf(2.0f, 0.083333336f * ((float)(dsp->fHslider22) + -69.0f)) * (1.0f - fSlow36);
	float fSlow38 = 0.00012207031f * (float)(dsp->fHslider24) + -1.0f;
	float fSlow39 = dsp->fConst6 * powf(2.0f, 0.083333336f * ((fSlow38 > 0.0f) ? (float)(dsp->fHslider26) * fSlow38 : (float)(dsp->fHslider25) * fSlow38));
	float fSlow40 = 10.583333f * mydsp_faustpower2_f((float)(dsp->fHslider27));
	float fSlow41 = 10.583333f * mydsp_faustpower2_f((float)(dsp->fHslider28));
	float fSlow42 = dsp->fConst0 * (1.0f - (float)(dsp->fHslider29));
	float fSlow43 = dsp->fConst10 * (float)(dsp->fHslider30);
	float fSlow44 = (float)(dsp->fHslider31);
	float fSlow45 = 0.9f * (float)(dsp->fHslider32);
	float fSlow46 = (float)(dsp->fHslider33);
	int iSlow47 = fSlow46 >= 2.0f;
	int iSlow48 = fSlow46 >= 1.0f;
	float fSlow49 = 0.9f * powf(2.0f, mydsp_faustpower2_f((float)(dsp->fHslider34)));
	float fSlow50 = (float)(dsp->fHslider35);
	int iSlow51 = fSlow50 >= 2.0f;
	int iSlow52 = fSlow50 >= 1.0f;
	float fSlow53 = dsp->fConst10 * (float)(dsp->fHslider36);
	float fSlow54 = 0.9f * (float)(dsp->fHslider37);
	float fSlow55 = 0.9f * (float)(dsp->fHslider38);
	int iSlow56 = (float)(dsp->fHslider39) >= 1.0f;
	float fSlow57 = 4.0f * fSlow23;
	float fSlow58 = 1.0f / fSlow24;
	int iSlow59 = (float)(dsp->fHslider40) >= 1.0f;
	float fSlow60 = (float)(dsp->fHslider41);
	float fSlow61 = (float)(dsp->fHslider42);
	float fSlow62 = (float)(dsp->fHslider43);
	float fSlow63 = (float)(dsp->fHslider44);
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec0[0] = 1;
			dsp->fRec0[0] = fSlow2 + 0.1f * dsp->fRec0[1];
			int iTemp0 = 1 - dsp->iVec0[1];
			float fTemp1 = ((iTemp0) ? 0.0f : dsp->fRec6[1] + fSlow12);
			dsp->fRec6[0] = fTemp1 - floorf(fTemp1);
			float fTemp2 = (float)(dsp->fRec6[0] <= 0.5f);
			dsp->fVec1[0] = fTemp2;
			int iTemp3 = (dsp->fVec1[1] <= 0.0f) & (fTemp2 > 0.0f);
			dsp->iRec8[0] = 1103515245 * dsp->iRec8[1] + 12345;
			float fTemp4 = 4.656613e-10f * (float)(dsp->iRec8[0]);
			dsp->fRec9[0] = 0.5221894f * dsp->fRec9[3] + fTemp4 + 2.494956f * dsp->fRec9[1] - 2.0172658f * dsp->fRec9[2];
			float fTemp5 = ((iSlow13) ? 3.0f * (0.049922034f * dsp->fRec9[0] + 0.0506127f * dsp->fRec9[2] - (0.095993534f * dsp->fRec9[1] + 0.004408786f * dsp->fRec9[3])) : fTemp4);
			dsp->fRec7[0] = dsp->fRec7[1] * (float)(1 - iTemp3) + 0.5f * (fTemp5 + 1.0f) * (float)(iTemp3);
			float fTemp6 = ((iSlow9) ? dsp->fRec7[0] : ((iSlow10) ? fTemp2 : 1.0f - fabsf(2.0f * dsp->fRec6[0] + -1.0f)));
			dsp->fVbargraph0 = (FAUSTFLOAT)(fTemp6);
			float fTemp7 = fTemp6;
			float fTemp8 = ((iSlow15) ? fTemp2 : fSlow16);
			int iTemp9 = dsp->iRec10[1] == 0;
			int iTemp10 = dsp->iRec10[1] == 1;
			dsp->iRec12[0] = dsp->iRec12[1] + 1;
			int iTemp11 = (dsp->iRec12[0] + -1) == 0;
			float fTemp12 = ((iTemp11) ? 0.0f : dsp->fRec11[1]);
			dsp->iRec10[0] = ((fTemp8 > 0.0f) ? ((iTemp9) ? 1 : ((iTemp10) ? ((fTemp12 < 1.0f) ? 1 : 2) : 2)) : 0);
			float fTemp13 = ((dsp->iRec10[1] == 2) ? fSlow17 : 0.0f);
			int iTemp14 = fTemp8 == 0.0f;
			dsp->iVec2[0] = iTemp14;
			int iTemp15 = (dsp->iVec2[1] <= 0) & (iTemp14 > 0);
			dsp->fRec13[0] = dsp->fRec13[1] * (float)(1 - iTemp15) + ((iTemp11) ? 1.0f : fTemp12) * (float)(iTemp15);
			float fTemp16 = fmaxf(0.03f, fminf(0.97f, ((iTemp9) ? fSlow21 : ((iTemp10) ? fSlow22 : fSlow21))));
			float fTemp17 = fTemp16 + -1.0f;
			float fTemp18 = ((iTemp9) ? dsp->fRec13[0] : 1.0f);
			float fTemp19 = ((fTemp13 == fTemp18) ? 0.5f : (fTemp12 - fTemp13) / (fTemp18 - fTemp13));
			float fTemp20 = fTemp17 * fTemp19 / (fTemp16 * (2.0f * fTemp19 + -1.0f) - fTemp19);
			dsp->fRec11[0] = fmaxf(fTemp13, fminf(1.0f, fTemp12 - ((iTemp9) ? -(fSlow20 * dsp->fRec13[0]) : ((iTemp10) ? fSlow19 : fSlow18)) * fTemp16 * fTemp17 / mydsp_faustpower2_f(fTemp16 * (2.0f * fTemp20 + -1.0f) + (1.0f - fTemp20))));
			dsp->fVbargraph1 = (FAUSTFLOAT)(dsp->fRec11[0]);
			float fTemp21 = dsp->fRec11[0];
			dsp->fRec5[0] = dsp->fConst3 * (fSlow6 + fSlow7 * fTemp7 + fSlow14 * fTemp21) + dsp->fConst2 * dsp->fRec5[1];
			float fTemp22 = fminf(fmaxf(0.0f, mydsp_faustpower2_f(dsp->fRec5[0])), 1.0f);
			float fTemp23 = tanf(dsp->fConst1 * powf(1e+01f, 3.0f * fTemp22 + 1.0f));
			dsp->fRec14[0] = fSlow26 + 0.1f * dsp->fRec14[1];
			float fTemp24 = (float)(dsp->iVec0[1]);
			dsp->fRec17[0] = fSlow37 + fSlow36 * dsp->fRec17[1];
			dsp->fRec18[0] = fSlow39 + dsp->fConst7 * dsp->fRec18[1];
			dsp->fRec16[0] = fSlow33 * dsp->fRec17[0] * dsp->fRec18[0] * powf(2.0f, fSlow40 * (fTemp7 + -0.5f)) * powf(2.0f, fSlow41 * fTemp21) + 0.1f * dsp->fRec16[1];
			float fTemp25 = 0.5f * dsp->fRec16[0];
			float fTemp26 = 0.25f * dsp->fRec16[0];
			float fTemp27 = ((iSlow31) ? fTemp26 : ((iSlow32) ? fTemp25 : dsp->fRec16[0]));
			float fTemp28 = fmaxf(fTemp27, 23.44895f);
			float fTemp29 = fmaxf(2e+01f, fabsf(fTemp28));
			float fTemp30 = ((iTemp0) ? 0.0f : dsp->fRec15[1] + dsp->fConst4 * fTemp29);
			dsp->fRec15[0] = fTemp30 - floorf(fTemp30);
			float fTemp31 = mydsp_faustpower2_f(2.0f * dsp->fRec15[0] + -1.0f);
			dsp->fVec3[0] = fTemp31;
			float fTemp32 = fTemp24 * (fTemp31 - dsp->fVec3[1]) / fTemp29;
			dsp->fVec4[dsp->IOTA0 & 4095] = fTemp32;
			dsp->fRec19[0] = fSlow43 + dsp->fConst9 * dsp->fRec19[1];
			float fTemp33 = dsp->fRec19[0] * (1.0f - fSlow44 * fTemp7);
			float fTemp34 = fmaxf(0.0f, fminf(2047.0f, fSlow42 * (fTemp33 / fTemp28)));
			int iTemp35 = (int)(fTemp34);
			float fTemp36 = floorf(fTemp34);
			float fTemp37 = fTemp32 - dsp->fVec4[(dsp->IOTA0 - iTemp35) & 4095] * (fTemp36 + (1.0f - fTemp34)) - (fTemp34 - fTemp36) * dsp->fVec4[(dsp->IOTA0 - (iTemp35 + 1)) & 4095];
			float fTemp38 = dsp->fConst5 * fTemp37;
			float fTemp39 = fmaxf(2e+01f, fabsf(fTemp27));
			float fTemp40 = ((iTemp0) ? 0.0f : dsp->fRec20[1] + dsp->fConst4 * fTemp39);
			dsp->fRec20[0] = fTemp40 - floorf(fTemp40);
			float fTemp41 = mydsp_faustpower2_f(2.0f * dsp->fRec20[0] + -1.0f);
			dsp->fVec5[0] = fTemp41;
			dsp->fVec6[dsp->IOTA0 & 8191] = fTemp24 * (fTemp41 - dsp->fVec5[1]) / fTemp39;
			float fTemp42 = dsp->fVec6[(dsp->IOTA0 - max(0, min(8191, (int)(fSlow42 * (fTemp33 / fTemp27) + 0.5f)))) & 8191];
			dsp->fRec21[0] = fSlow45 + 0.1f * dsp->fRec21[1];
			dsp->fRec23[0] = fSlow49 + 0.1f * dsp->fRec23[1];
			float fTemp43 = dsp->fRec23[0] * ((iSlow51) ? fTemp26 : ((iSlow52) ? fTemp25 : dsp->fRec16[0]));
			float fTemp44 = fmaxf(fTemp43, 23.44895f);
			float fTemp45 = fmaxf(2e+01f, fabsf(fTemp44));
			float fTemp46 = ((iTemp0) ? 0.0f : dsp->fRec22[1] + dsp->fConst4 * fTemp45);
			dsp->fRec22[0] = fTemp46 - floorf(fTemp46);
			float fTemp47 = mydsp_faustpower2_f(2.0f * dsp->fRec22[0] + -1.0f);
			dsp->fVec7[0] = fTemp47;
			float fTemp48 = fTemp24 * (fTemp47 - dsp->fVec7[1]) / fTemp45;
			dsp->fVec8[dsp->IOTA0 & 4095] = fTemp48;
			dsp->fRec24[0] = fSlow53 + dsp->fConst9 * dsp->fRec24[1];
			float fTemp49 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst0 * (dsp->fRec24[0] / fTemp44)));
			int iTemp50 = (int)(fTemp49);
			float fTemp51 = floorf(fTemp49);
			float fTemp52 = fTemp48 - dsp->fVec8[(dsp->IOTA0 - iTemp50) & 4095] * (fTemp51 + (1.0f - fTemp49)) - (fTemp49 - fTemp51) * dsp->fVec8[(dsp->IOTA0 - (iTemp50 + 1)) & 4095];
			float fTemp53 = dsp->fConst5 * fTemp52;
			float fTemp54 = fmaxf(2e+01f, fabsf(fTemp43));
			float fTemp55 = ((iTemp0) ? 0.0f : dsp->fRec25[1] + dsp->fConst4 * fTemp54);
			dsp->fRec25[0] = fTemp55 - floorf(fTemp55);
			float fTemp56 = mydsp_faustpower2_f(2.0f * dsp->fRec25[0] + -1.0f);
			dsp->fVec9[0] = fTemp56;
			dsp->fVec10[dsp->IOTA0 & 8191] = fTemp24 * (fTemp56 - dsp->fVec9[1]) / fTemp54;
			float fTemp57 = dsp->fVec10[(dsp->IOTA0 - max(0, min(8191, (int)(dsp->fConst0 * (dsp->fRec24[0] / fTemp43) + 0.5f)))) & 8191];
			dsp->fRec26[0] = fSlow54 + 0.1f * dsp->fRec26[1];
			dsp->fRec27[0] = fSlow55 + 0.1f * dsp->fRec27[1];
			float fTemp58 = dsp->fRec14[0] * ((iSlow28) ? dsp->fConst5 * (fTemp37 + fTemp42) : ((iSlow29) ? dsp->fConst5 * fTemp42 : fTemp38)) + dsp->fRec21[0] * ((iSlow47) ? dsp->fConst5 * (fTemp52 + fTemp57) : ((iSlow48) ? dsp->fConst5 * fTemp57 : fTemp53)) + dsp->fRec26[0] * fTemp5 + dsp->fRec27[0] * (float)((int)(fTemp38) ^ (int)(fTemp53));
			float fTemp59 = (fTemp58 - dsp->fRec4[1]) * fTemp23;
			float fTemp60 = fTemp23 + 1.0f;
			float fTemp61 = (fTemp58 - (dsp->fRec4[1] + (fTemp59 - dsp->fRec1[1] + fTemp23 * dsp->fRec3[1] / fTemp60) / fTemp60)) / (1.0f - fSlow25 * (fTemp23 * (1.0f - fTemp23 / fTemp60) / fTemp60));
			float fTemp62 = fSlow25 * fTemp61;
			float fTemp63 = fTemp23 * (fTemp62 - dsp->fRec3[1]) / fTemp60;
			dsp->fRec1[0] = dsp->fRec1[1] + 2.0f * (fTemp23 * (fTemp62 - (fTemp63 + dsp->fRec1[1] + dsp->fRec3[1])) / fTemp60);
			float fRec2 = fTemp61;
			dsp->fRec3[0] = dsp->fRec3[1] + 2.0f * fTemp63;
			dsp->fRec4[0] = dsp->fRec4[1] + 2.0f * (fTemp59 / fTemp60);
			float fTemp64 = tanf(1.5707964f * fminf(fmaxf(0.0f, ((iSlow56) ? 0.0022727272f * dsp->fRec16[0] * fTemp22 : fTemp22)), 1.0f));
			float fTemp65 = fTemp64 + 1.0f;
			float fTemp66 = fTemp64 * ((fTemp58 - fSlow57 * (1.0f - fTemp64 / fTemp65) * (dsp->fRec31[1] + fTemp64 * (dsp->fRec30[1] + fTemp64 * (dsp->fRec29[1] + fTemp64 * dsp->fRec28[1] / fTemp65) / fTemp65) / fTemp65)) / (fSlow57 * (mydsp_faustpower4_f(fTemp64) / mydsp_faustpower4_f(fTemp65)) + 1.0f) - dsp->fRec28[1]) / fTemp65;
			dsp->fRec28[0] = dsp->fRec28[1] + 2.0f * fTemp66;
			float fTemp67 = fTemp64 * (dsp->fRec28[1] + fTemp66 - dsp->fRec29[1]) / fTemp65;
			dsp->fRec29[0] = dsp->fRec29[1] + 2.0f * fTemp67;
			float fTemp68 = fTemp64 * (dsp->fRec29[1] + fTemp67 - dsp->fRec30[1]) / fTemp65;
			dsp->fRec30[0] = dsp->fRec30[1] + 2.0f * fTemp68;
			float fTemp69 = fTemp64 * (dsp->fRec30[1] + fTemp68 - dsp->fRec31[1]) / fTemp65;
			dsp->fRec31[0] = dsp->fRec31[1] + 2.0f * fTemp69;
			float fRec32 = dsp->fRec31[1] + fTemp69;
			float fTemp70 = fSlow58 + fTemp23;
			float fTemp71 = fTemp58 - (dsp->fRec34[1] + dsp->fRec35[1] * fTemp70);
			float fTemp72 = fTemp23 * fTemp70 + 1.0f;
			float fTemp73 = fTemp23 * fTemp71 / fTemp72;
			float fTemp74 = fmaxf(-1.0f, fminf(1.0f, dsp->fRec35[1] + fTemp73));
			float fTemp75 = 1.0f - 0.33333334f * mydsp_faustpower2_f(fTemp74);
			float fTemp76 = fTemp74 * fTemp75;
			float fRec33 = fTemp76;
			float fTemp77 = fTemp23 * fTemp74 * fTemp75;
			dsp->fRec34[0] = dsp->fRec34[1] + 2.0f * fTemp77;
			dsp->fRec35[0] = fTemp73 + fTemp76;
			float fTemp78 = ((iSlow59) ? 1.0f - fSlow60 * (1.0f - fTemp21) : fSlow60 * fTemp21) * (fSlow61 * fTemp7 + 1.0f);
			dsp->fVbargraph2 = (FAUSTFLOAT)(fTemp78);
			float fTemp79 = dsp->fRec0[0] * ((iSlow4) ? fRec33 : ((iSlow5) ? fRec32 : fRec2)) * fTemp78;
			float fTemp80 = fTemp79 + fSlow62 * dsp->fRec36[1];
			dsp->fVec11[dsp->IOTA0 & 16383] = fTemp80;
			float fTemp81 = ((dsp->fRec37[1] != 0.0f) ? (((dsp->fRec38[1] > 0.0f) & (dsp->fRec38[1] < 1.0f)) ? dsp->fRec37[1] : 0.0f) : (((dsp->fRec38[1] == 0.0f) & (fSlow63 != dsp->fRec39[1])) ? dsp->fConst8 : (((dsp->fRec38[1] == 1.0f) & (fSlow63 != dsp->fRec40[1])) ? -dsp->fConst8 : 0.0f)));
			dsp->fRec37[0] = fTemp81;
			dsp->fRec38[0] = fmaxf(0.0f, fminf(1.0f, dsp->fRec38[1] + fTemp81));
			dsp->fRec39[0] = (((dsp->fRec38[1] >= 1.0f) & (dsp->fRec40[1] != fSlow63)) ? fSlow63 : dsp->fRec39[1]);
			dsp->fRec40[0] = (((dsp->fRec38[1] <= 0.0f) & (dsp->fRec39[1] != fSlow63)) ? fSlow63 : dsp->fRec40[1]);
			float fTemp82 = dsp->fVec11[(dsp->IOTA0 - (int)(fminf(8192.0f, fmaxf(0.0f, dsp->fRec39[0])))) & 16383];
			dsp->fRec36[0] = fTemp82 + dsp->fRec38[0] * (dsp->fVec11[(dsp->IOTA0 - (int)(fminf(8192.0f, fmaxf(0.0f, dsp->fRec40[0])))) & 16383] - fTemp82);
			output0[i0] = (FAUSTFLOAT)(fSlow1 * fTemp79 + fSlow0 * dsp->fRec36[0]);
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fVec1[1] = dsp->fVec1[0];
			dsp->iRec8[1] = dsp->iRec8[0];
			/* C99 loop */
			{
				int j0;
				for (j0 = 3; j0 > 0; j0 = j0 - 1) {
					dsp->fRec9[j0] = dsp->fRec9[j0 - 1];
				}
			}
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->iRec12[1] = dsp->iRec12[0];
			dsp->iRec10[1] = dsp->iRec10[0];
			dsp->iVec2[1] = dsp->iVec2[0];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fRec11[1] = dsp->fRec11[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fRec17[1] = dsp->fRec17[0];
			dsp->fRec18[1] = dsp->fRec18[0];
			dsp->fRec16[1] = dsp->fRec16[0];
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fRec20[1] = dsp->fRec20[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec21[1] = dsp->fRec21[0];
			dsp->fRec23[1] = dsp->fRec23[0];
			dsp->fRec22[1] = dsp->fRec22[0];
			dsp->fVec7[1] = dsp->fVec7[0];
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fRec25[1] = dsp->fRec25[0];
			dsp->fVec9[1] = dsp->fVec9[0];
			dsp->fRec26[1] = dsp->fRec26[0];
			dsp->fRec27[1] = dsp->fRec27[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->fRec3[1] = dsp->fRec3[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->fRec28[1] = dsp->fRec28[0];
			dsp->fRec29[1] = dsp->fRec29[0];
			dsp->fRec30[1] = dsp->fRec30[0];
			dsp->fRec31[1] = dsp->fRec31[0];
			dsp->fRec34[1] = dsp->fRec34[0];
			dsp->fRec35[1] = dsp->fRec35[0];
			dsp->fRec37[1] = dsp->fRec37[0];
			dsp->fRec38[1] = dsp->fRec38[0];
			dsp->fRec39[1] = dsp->fRec39[0];
			dsp->fRec40[1] = dsp->fRec40[0];
			dsp->fRec36[1] = dsp->fRec36[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
