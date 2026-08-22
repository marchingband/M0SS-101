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
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	int fSampleRate;
	float fConst0;
	float fConst1;
	int iVec0[2];
	float fConst2;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fHslider12;
	float fRec5[2];
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fHslider16;
	float fRec6[2];
	float fVec1[2];
	FAUSTFLOAT fHslider17;
	int iRec8[2];
	float fRec9[4];
	float fRec7[2];
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fButton0;
	float fVec2[2];
	float fRec10[2];
	FAUSTFLOAT fHslider21;
	FAUSTFLOAT fHslider22;
	FAUSTFLOAT fHslider23;
	int iRec11[2];
	FAUSTFLOAT fVbargraph1;
	FAUSTFLOAT fHslider24;
	FAUSTFLOAT fHslider25;
	FAUSTFLOAT fHslider26;
	float fVec3[2];
	float fRec12[2];
	FAUSTFLOAT fHslider27;
	FAUSTFLOAT fHslider28;
	FAUSTFLOAT fHslider29;
	int iRec13[2];
	FAUSTFLOAT fVbargraph2;
	float fRec4[2];
	float fVec4[2];
	int IOTA0;
	float fVec5[4096];
	FAUSTFLOAT fHslider30;
	FAUSTFLOAT fHslider31;
	float fConst3;
	float fConst4;
	float fConst5;
	FAUSTFLOAT fHslider32;
	float fRec14[2];
	FAUSTFLOAT fHslider33;
	float fRec15[2];
	float fVec6[2];
	float fVec7[8192];
	FAUSTFLOAT fHslider34;
	FAUSTFLOAT fHslider35;
	FAUSTFLOAT fHslider36;
	FAUSTFLOAT fHslider37;
	float fRec16[2];
	float fVec8[2];
	float fVec9[4096];
	FAUSTFLOAT fHslider38;
	float fRec17[2];
	float fRec18[2];
	float fVec10[2];
	float fVec11[8192];
	FAUSTFLOAT fHslider39;
	float fRec19[2];
	FAUSTFLOAT fHslider40;
	float fRec20[2];
	float fConst6;
	float fConst7;
	float fConst8;
	FAUSTFLOAT fHslider41;
	FAUSTFLOAT fHslider42;
	FAUSTFLOAT fHslider43;
	FAUSTFLOAT fHslider44;
	float fRec21[2];
	FAUSTFLOAT fHslider45;
	float fRec1[2];
	float fRec2[2];
	float fRec3[2];
	FAUSTFLOAT fHslider46;
	float fRec22[2];
	float fRec23[2];
	float fRec24[2];
	float fRec25[2];
	float fRec27[2];
	float fRec28[2];
	FAUSTFLOAT fHslider47;
	FAUSTFLOAT fHslider48;
	FAUSTFLOAT fHslider49;
	FAUSTFLOAT fHslider50;
	FAUSTFLOAT fHslider51;
	FAUSTFLOAT fVbargraph3;
	FAUSTFLOAT fHslider52;
	float fVec12[16384];
	FAUSTFLOAT fHslider53;
	float fRec31[2];
	float fRec32[2];
	float fRec33[2];
	float fRec34[2];
	float fRec30[2];
} mydsp;

mydsp* newmydsp() { 
	mydsp* dsp = (mydsp*)calloc(1, sizeof(mydsp));
	return dsp;
}

void deletemydsp(mydsp* dsp) { 
	free(dsp);
}

void metadatamydsp(MetaGlue* m) { 
	m->declare(m->metaInterface, "basics.lib/name", "Faust Basic Element Library");
	m->declare(m->metaInterface, "basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
	m->declare(m->metaInterface, "basics.lib/version", "1.11.1");
	m->declare(m->metaInterface, "compile_options", "-lang c -ct 1 -es 1 -mcd 16 -single -ftz 0");
	m->declare(m->metaInterface, "delays.lib/name", "Faust Delay Library");
	m->declare(m->metaInterface, "delays.lib/version", "1.1.0");
	m->declare(m->metaInterface, "envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
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
	dsp->fHslider0 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider1 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider2 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider3 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider4 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider5 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider6 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider7 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider8 = (FAUSTFLOAT)(8192.0f);
	dsp->fHslider9 = (FAUSTFLOAT)(2.0f);
	dsp->fHslider10 = (FAUSTFLOAT)(2.0f);
	dsp->fHslider11 = (FAUSTFLOAT)(45.0f);
	dsp->fHslider12 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider13 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider14 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider15 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider16 = (FAUSTFLOAT)(0.3f);
	dsp->fHslider17 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider18 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider19 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider20 = (FAUSTFLOAT)(0.0f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider21 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider22 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider23 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider24 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider25 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider26 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider27 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider28 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider29 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider30 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider31 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider32 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider33 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider34 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider35 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider36 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider37 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider38 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider39 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider40 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider41 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider42 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider43 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider44 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider45 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider46 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider47 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider48 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider49 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider50 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider51 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider52 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider53 = (FAUSTFLOAT)(1024.0f);
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
			dsp->fRec5[l1] = 0.0f;
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
			dsp->fVec2[l7] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 2; l8 = l8 + 1) {
			dsp->fRec10[l8] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 2; l9 = l9 + 1) {
			dsp->iRec11[l9] = 0;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 2; l10 = l10 + 1) {
			dsp->fVec3[l10] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 2; l11 = l11 + 1) {
			dsp->fRec12[l11] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l12;
		for (l12 = 0; l12 < 2; l12 = l12 + 1) {
			dsp->iRec13[l12] = 0;
		}
	}
	/* C99 loop */
	{
		int l13;
		for (l13 = 0; l13 < 2; l13 = l13 + 1) {
			dsp->fRec4[l13] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l14;
		for (l14 = 0; l14 < 2; l14 = l14 + 1) {
			dsp->fVec4[l14] = 0.0f;
		}
	}
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l15;
		for (l15 = 0; l15 < 4096; l15 = l15 + 1) {
			dsp->fVec5[l15] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l16;
		for (l16 = 0; l16 < 2; l16 = l16 + 1) {
			dsp->fRec14[l16] = 0.0f;
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
			dsp->fVec6[l18] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l19;
		for (l19 = 0; l19 < 8192; l19 = l19 + 1) {
			dsp->fVec7[l19] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l20;
		for (l20 = 0; l20 < 2; l20 = l20 + 1) {
			dsp->fRec16[l20] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l21;
		for (l21 = 0; l21 < 2; l21 = l21 + 1) {
			dsp->fVec8[l21] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l22;
		for (l22 = 0; l22 < 4096; l22 = l22 + 1) {
			dsp->fVec9[l22] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l23;
		for (l23 = 0; l23 < 2; l23 = l23 + 1) {
			dsp->fRec17[l23] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l24;
		for (l24 = 0; l24 < 2; l24 = l24 + 1) {
			dsp->fRec18[l24] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l25;
		for (l25 = 0; l25 < 2; l25 = l25 + 1) {
			dsp->fVec10[l25] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l26;
		for (l26 = 0; l26 < 8192; l26 = l26 + 1) {
			dsp->fVec11[l26] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l27;
		for (l27 = 0; l27 < 2; l27 = l27 + 1) {
			dsp->fRec19[l27] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l28;
		for (l28 = 0; l28 < 2; l28 = l28 + 1) {
			dsp->fRec20[l28] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l29;
		for (l29 = 0; l29 < 2; l29 = l29 + 1) {
			dsp->fRec21[l29] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l30;
		for (l30 = 0; l30 < 2; l30 = l30 + 1) {
			dsp->fRec1[l30] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l31;
		for (l31 = 0; l31 < 2; l31 = l31 + 1) {
			dsp->fRec2[l31] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l32;
		for (l32 = 0; l32 < 2; l32 = l32 + 1) {
			dsp->fRec3[l32] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l33;
		for (l33 = 0; l33 < 2; l33 = l33 + 1) {
			dsp->fRec22[l33] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l34;
		for (l34 = 0; l34 < 2; l34 = l34 + 1) {
			dsp->fRec23[l34] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l35;
		for (l35 = 0; l35 < 2; l35 = l35 + 1) {
			dsp->fRec24[l35] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l36;
		for (l36 = 0; l36 < 2; l36 = l36 + 1) {
			dsp->fRec25[l36] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l37;
		for (l37 = 0; l37 < 2; l37 = l37 + 1) {
			dsp->fRec27[l37] = 0.0f;
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
		for (l39 = 0; l39 < 16384; l39 = l39 + 1) {
			dsp->fVec12[l39] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l40;
		for (l40 = 0; l40 < 2; l40 = l40 + 1) {
			dsp->fRec31[l40] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l41;
		for (l41 = 0; l41 < 2; l41 = l41 + 1) {
			dsp->fRec32[l41] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l42;
		for (l42 = 0; l42 < 2; l42 = l42 + 1) {
			dsp->fRec33[l42] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l43;
		for (l43 = 0; l43 < 2; l43 = l43 + 1) {
			dsp->fRec34[l43] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l44;
		for (l44 = 0; l44 < 2; l44 = l44 + 1) {
			dsp->fRec30[l44] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 0.25f * dsp->fConst0;
	dsp->fConst2 = 1.0f / dsp->fConst0;
	dsp->fConst3 = 1e+01f / dsp->fConst0;
	dsp->fConst4 = expf(-dsp->fConst3);
	dsp->fConst5 = 1.0f - dsp->fConst4;
	dsp->fConst6 = 6.2831855f / dsp->fConst0;
	dsp->fConst7 = expf(-(2e+01f / dsp->fConst0));
	dsp->fConst8 = 1.0f - dsp->fConst7;
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider25, "envII-mod", "16");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider25, "midi", "50");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "attackII", &dsp->fHslider25, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "midi", "1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "mod", "16");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "attack", &dsp->fHslider19, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider41, "midi", "2");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider41, "mod", "14");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoff", &dsp->fHslider41, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider52, "alt", "21");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider52, "midi", "37");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "d_fb", &dsp->fHslider52, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider53, "alt", "19");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider53, "midi", "36");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "d_time", &dsp->fHslider53, (FAUSTFLOAT)1024.0f, (FAUSTFLOAT)1024.0f, (FAUSTFLOAT)8192.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "alt", "25");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "midi", "38");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "d_wet", &dsp->fHslider1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider28, "envII-mod", "19");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider28, "midi", "52");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "decayII", &dsp->fHslider28, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "midi", "29");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "mod", "19");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "decay", &dsp->fHslider22, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider36, "alt", "2");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider36, "midi", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "detune", &dsp->fHslider36, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "midi", "27");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "mod", "20");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-osc", &dsp->fHslider18, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider30, "midi", "28");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider30, "mod", "24");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-pwm", &dsp->fHslider30, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider48, "midi", "25");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider48, "mod", "15");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vca", &dsp->fHslider48, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider43, "midi", "26");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider43, "mod", "18");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vcf", &dsp->fHslider43, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider47, "alt-sel", "15");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider47, "midi", "20");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-vca-inv", &dsp->fHslider47, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider24, "envII-mod", "20");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider24, "midi", "48");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "envII-to-osc", &dsp->fHslider24, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider31, "envII-mod", "24");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider31, "midi", "49");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "envII-to-pwm", &dsp->fHslider31, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider50, "envII-mod", "15");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider50, "midi", "46");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "envII-to-vca", &dsp->fHslider50, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider44, "envII-mod", "18");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider44, "midi", "47");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "envII-to-vcf", &dsp->fHslider44, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider49, "envII-alt-sel", "15");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider49, "midi", "45");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "envII-vca-inv", &dsp->fHslider49, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph2, "envII", "");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "envII", &dsp->fVbargraph2, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph1, "env", "");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "env", &dsp->fVbargraph1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "fine-tune", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "midi", "42");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "fine-tune", &dsp->fHslider6, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)-1e+02f, (FAUSTFLOAT)1e+02f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fButton0, "gate", "");
	ui_interface->addButton(ui_interface->uiInterface, "gate", &dsp->fButton0);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "alt", "23");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "midi", "35");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "glide", &dsp->fHslider12, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.99f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "midi", "16");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "sel", "13");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "hp-lp-bp", &dsp->fHslider2, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider46, "alt-sel", "13");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider46, "midi", "17");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "key-track", &dsp->fHslider46, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "midi", "3");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "mod", "12");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-freq", &dsp->fHslider16, (FAUSTFLOAT)0.3f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "alt-sel", "12");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "midi", "19");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-range", &dsp->fHslider15, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider26, "envII-sel", "9");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider26, "midi", "44");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-envII", &dsp->fHslider26, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "midi", "15");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "sel", "9");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-env", &dsp->fHslider20, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "midi", "21");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "mod", "10");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-osc", &dsp->fHslider13, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider33, "midi", "24");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider33, "mod", "6");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-pwm", &dsp->fHslider33, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider51, "midi", "22");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider51, "mod", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vca", &dsp->fHslider51, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider42, "midi", "23");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider42, "mod", "11");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vcf", &dsp->fHslider42, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "midi", "14");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "sel", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-wavform", &dsp->fHslider14, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph0, "lfo", "");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "lfo", &dsp->fVbargraph0, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "alt-sel", "7");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "midi", "18");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "noise-color", &dsp->fHslider17, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider39, "alt", "5");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider39, "midi", "34");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "noise-vol", &dsp->fHslider39, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider32, "alt", "0");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider32, "midi", "31");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-1-pw", &dsp->fHslider32, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider38, "alt", "3");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider38, "midi", "32");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-2-pw", &dsp->fHslider38, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "midi", "11");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "sel", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-oct", &dsp->fHslider5, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "midi", "4");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "mod", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-vol", &dsp->fHslider3, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "midi", "10");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "sel", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-wavform", &dsp->fHslider4, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider37, "midi", "12");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider37, "sel", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-oct", &dsp->fHslider37, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider34, "midi", "5");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider34, "mod", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-vol", &dsp->fHslider34, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider35, "midi", "13");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider35, "sel", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-wavform", &dsp->fHslider35, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "asb", "11");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "midi", "40");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend-dn", &dsp->fHslider9, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)12.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "asb", "10");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "midi", "39");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend-up", &dsp->fHslider10, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)12.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "pitch-bend", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch-bend", &dsp->fHslider8, (FAUSTFLOAT)8192.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)16383.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "pitch", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch", &dsp->fHslider11, (FAUSTFLOAT)45.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)127.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider29, "envII-mod", "25");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider29, "midi", "51");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "releaseII", &dsp->fHslider29, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider23, "midi", "6");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider23, "mod", "25");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "release", &dsp->fHslider23, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider45, "midi", "7");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider45, "mod", "17");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "resonance", &dsp->fHslider45, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider27, "envII-mod", "21");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider27, "midi", "53");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "sustainII", &dsp->fHslider27, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider21, "midi", "30");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider21, "mod", "21");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "sustain", &dsp->fHslider21, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "midi", "43");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "transpose", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "transpose", &dsp->fHslider7, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)-127.0f, (FAUSTFLOAT)127.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph3, "vca", "");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "vca", &dsp->fVbargraph3, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "midi", "9");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "mod", "23");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "volume", &dsp->fHslider0, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider40, "alt", "4");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider40, "midi", "33");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "xor-vol", &dsp->fHslider40, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	float fSlow0 = (float)(dsp->fHslider0);
	float fSlow1 = (float)(dsp->fHslider1);
	float fSlow2 = fSlow0 * (1.0f - fSlow1);
	float fSlow3 = (float)(dsp->fHslider2);
	int iSlow4 = fSlow3 >= 2.0f;
	int iSlow5 = fSlow3 >= 1.0f;
	float fSlow6 = (float)(dsp->fHslider3);
	float fSlow7 = (float)(dsp->fHslider4);
	int iSlow8 = fSlow7 >= 2.0f;
	int iSlow9 = fSlow7 >= 1.0f;
	float fSlow10 = (float)(dsp->fHslider5);
	int iSlow11 = fSlow10 >= 2.0f;
	int iSlow12 = fSlow10 >= 1.0f;
	float fSlow13 = powf(2.0f, 0.00083333335f * (float)(dsp->fHslider6)) * powf(2.0f, 0.083333336f * (float)(dsp->fHslider7));
	float fSlow14 = fminf(fmaxf(-1.0f, 0.00012208521f * ((float)(dsp->fHslider8) + -8192.0f)), 1.0f);
	float fSlow15 = powf(2.0f, 0.083333336f * ((fSlow14 > 0.0f) ? fSlow14 * (float)(dsp->fHslider10) : fSlow14 * (float)(dsp->fHslider9)));
	float fSlow16 = (float)(dsp->fHslider12);
	int iSlow17 = fabsf(fSlow16) < 1.1920929e-07f;
	float fSlow18 = ((iSlow17) ? 0.0f : expf(-(dsp->fConst2 / ((iSlow17) ? 1.0f : fSlow16))));
	float fSlow19 = 4.4e+02f * powf(2.0f, 0.083333336f * ((float)(dsp->fHslider11) + -69.0f)) * (1.0f - fSlow18);
	float fSlow20 = mydsp_faustpower2_f((float)(dsp->fHslider13));
	float fSlow21 = (float)(dsp->fHslider14);
	int iSlow22 = fSlow21 >= 2.0f;
	int iSlow23 = fSlow21 >= 1.0f;
	float fSlow24 = mydsp_faustpower2_f((float)(dsp->fHslider16));
	float fSlow25 = dsp->fConst2 * (((float)(dsp->fHslider15) >= 1.0f) ? 9.98e+03f * fSlow24 + 2e+01f : 19.99f * fSlow24 + 0.01f);
	int iSlow26 = (float)(dsp->fHslider17) >= 1.0f;
	float fSlow27 = mydsp_faustpower2_f((float)(dsp->fHslider18));
	float fSlow28 = fmaxf(1.0f, dsp->fConst0 * (19.999f * mydsp_faustpower3_f((float)(dsp->fHslider19)) + 0.001f));
	float fSlow29 = 1.0f / fSlow28;
	int iSlow30 = (float)(dsp->fHslider20) >= 1.0f;
	float fSlow31 = (float)(dsp->fButton0);
	float fSlow32 = (float)(dsp->fHslider21);
	float fSlow33 = (1.0f - fSlow32) / fmaxf(1.0f, dsp->fConst0 * (19.999f * mydsp_faustpower2_f((float)(dsp->fHslider22)) + 0.001f));
	float fSlow34 = 1.0f / fmaxf(1.0f, dsp->fConst0 * (19.999f * mydsp_faustpower2_f((float)(dsp->fHslider23)) + 0.001f));
	float fSlow35 = mydsp_faustpower2_f((float)(dsp->fHslider24));
	float fSlow36 = fmaxf(1.0f, dsp->fConst0 * (19.999f * mydsp_faustpower3_f((float)(dsp->fHslider25)) + 0.001f));
	float fSlow37 = 1.0f / fSlow36;
	int iSlow38 = (float)(dsp->fHslider26) >= 1.0f;
	float fSlow39 = (float)(dsp->fHslider27);
	float fSlow40 = (1.0f - fSlow39) / fmaxf(1.0f, dsp->fConst0 * (19.999f * mydsp_faustpower2_f((float)(dsp->fHslider28)) + 0.001f));
	float fSlow41 = 1.0f / fmaxf(1.0f, dsp->fConst0 * (19.999f * mydsp_faustpower2_f((float)(dsp->fHslider29)) + 0.001f));
	float fSlow42 = 0.5f * fSlow13;
	float fSlow43 = 0.25f * fSlow13;
	float fSlow44 = dsp->fConst0 * (1.0f - (float)(dsp->fHslider30)) * (1.0f - (float)(dsp->fHslider31));
	float fSlow45 = dsp->fConst5 * (float)(dsp->fHslider32);
	float fSlow46 = (float)(dsp->fHslider33);
	float fSlow47 = (float)(dsp->fHslider34);
	float fSlow48 = (float)(dsp->fHslider35);
	int iSlow49 = fSlow48 >= 2.0f;
	int iSlow50 = fSlow48 >= 1.0f;
	float fSlow51 = powf(2.0f, mydsp_faustpower2_f((float)(dsp->fHslider36)));
	float fSlow52 = (float)(dsp->fHslider37);
	int iSlow53 = fSlow52 >= 2.0f;
	int iSlow54 = fSlow52 >= 1.0f;
	float fSlow55 = dsp->fConst5 * (float)(dsp->fHslider38);
	float fSlow56 = dsp->fConst0 / fSlow51;
	float fSlow57 = 0.9f * (float)(dsp->fHslider39);
	float fSlow58 = 0.9f * (float)(dsp->fHslider40);
	float fSlow59 = (float)(dsp->fHslider41);
	float fSlow60 = (float)(dsp->fHslider42);
	float fSlow61 = (float)(dsp->fHslider43);
	float fSlow62 = (float)(dsp->fHslider44);
	float fSlow63 = (float)(dsp->fHslider45);
	float fSlow64 = 24.293f * fSlow63 + 0.707f;
	float fSlow65 = 0.21521576f * (0.33333334f * fSlow64 + -0.707f);
	int iSlow66 = (float)(dsp->fHslider46) >= 1.0f;
	float fSlow67 = 0.0022727272f * fSlow13;
	float fSlow68 = 4.0f * fSlow63;
	float fSlow69 = 1.0f / fSlow64;
	int iSlow70 = (float)(dsp->fHslider47) >= 1.0f;
	float fSlow71 = (float)(dsp->fHslider48);
	int iSlow72 = (float)(dsp->fHslider49) >= 1.0f;
	float fSlow73 = (float)(dsp->fHslider50);
	float fSlow74 = (float)(dsp->fHslider51);
	float fSlow75 = (float)(dsp->fHslider52);
	float fSlow76 = (float)(dsp->fHslider53);
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec0[0] = 1;
			float fTemp0 = (float)(dsp->iVec0[1]);
			int iTemp1 = 1 - dsp->iVec0[1];
			dsp->fRec5[0] = fSlow19 + fSlow18 * dsp->fRec5[1];
			float fTemp2 = ((iTemp1) ? 0.0f : dsp->fRec6[1] + fSlow25);
			dsp->fRec6[0] = fTemp2 - floorf(fTemp2);
			float fTemp3 = (float)(dsp->fRec6[0] <= 0.5f);
			dsp->fVec1[0] = fTemp3;
			int iTemp4 = (dsp->fVec1[1] <= 0.0f) & (fTemp3 > 0.0f);
			dsp->iRec8[0] = 1103515245 * dsp->iRec8[1] + 12345;
			float fTemp5 = 4.656613e-10f * (float)(dsp->iRec8[0]);
			dsp->fRec9[0] = 0.5221894f * dsp->fRec9[3] + fTemp5 + 2.494956f * dsp->fRec9[1] - 2.0172658f * dsp->fRec9[2];
			float fTemp6 = ((iSlow26) ? 3.0f * (0.049922034f * dsp->fRec9[0] + 0.0506127f * dsp->fRec9[2] - (0.095993534f * dsp->fRec9[1] + 0.004408786f * dsp->fRec9[3])) : fTemp5);
			dsp->fRec7[0] = dsp->fRec7[1] * (float)(1 - iTemp4) + 0.5f * (fTemp6 + 1.0f) * (float)(iTemp4);
			float fTemp7 = ((iSlow22) ? dsp->fRec7[0] : ((iSlow23) ? fTemp3 : 1.0f - fabsf(2.0f * dsp->fRec6[0] + -1.0f)));
			dsp->fVbargraph0 = (FAUSTFLOAT)(fTemp7);
			float fTemp8 = fTemp7;
			float fTemp9 = ((iSlow30) ? fTemp3 : fSlow31);
			dsp->fVec2[0] = fTemp9;
			dsp->fRec10[0] = fTemp9 + dsp->fRec10[1] * (float)(dsp->fVec2[1] >= fTemp9);
			dsp->iRec11[0] = (fTemp9 == 0.0f) * (dsp->iRec11[1] + 1);
			float fTemp10 = fmaxf(0.0f, fminf(fSlow29 * dsp->fRec10[0], fmaxf(fSlow33 * (fSlow28 - dsp->fRec10[0]) + 1.0f, fSlow32)) * (1.0f - fSlow34 * (float)(dsp->iRec11[0])));
			dsp->fVbargraph1 = (FAUSTFLOAT)(fTemp10);
			float fTemp11 = fTemp10;
			float fTemp12 = ((iSlow38) ? fTemp3 : fSlow31);
			dsp->fVec3[0] = fTemp12;
			dsp->fRec12[0] = fTemp12 + dsp->fRec12[1] * (float)(dsp->fVec3[1] >= fTemp12);
			dsp->iRec13[0] = (fTemp12 == 0.0f) * (dsp->iRec13[1] + 1);
			float fTemp13 = fmaxf(0.0f, fminf(fSlow37 * dsp->fRec12[0], fmaxf(fSlow40 * (fSlow36 - dsp->fRec12[0]) + 1.0f, fSlow39)) * (1.0f - fSlow41 * (float)(dsp->iRec13[0])));
			dsp->fVbargraph2 = (FAUSTFLOAT)(fTemp13);
			float fTemp14 = fTemp13;
			float fTemp15 = fSlow15 * dsp->fRec5[0] * powf(2.0f, 10.583333f * (fSlow20 * (fTemp8 + -0.5f) + fSlow27 * fTemp11 + fSlow35 * fTemp14));
			float fTemp16 = fSlow13 * fTemp15;
			float fTemp17 = fSlow42 * fTemp15;
			float fTemp18 = fSlow43 * fTemp15;
			float fTemp19 = ((iSlow11) ? fTemp18 : ((iSlow12) ? fTemp17 : fTemp16));
			float fTemp20 = fmaxf(fTemp19, 23.44895f);
			float fTemp21 = fmaxf(2e+01f, fabsf(fTemp20));
			float fTemp22 = ((iTemp1) ? 0.0f : dsp->fRec4[1] + dsp->fConst2 * fTemp21);
			dsp->fRec4[0] = fTemp22 - floorf(fTemp22);
			float fTemp23 = mydsp_faustpower2_f(2.0f * dsp->fRec4[0] + -1.0f);
			dsp->fVec4[0] = fTemp23;
			float fTemp24 = fTemp0 * (fTemp23 - dsp->fVec4[1]) / fTemp21;
			dsp->fVec5[dsp->IOTA0 & 4095] = fTemp24;
			dsp->fRec14[0] = fSlow45 + dsp->fConst4 * dsp->fRec14[1];
			float fTemp25 = dsp->fRec14[0] * (1.0f - fSlow46 * fTemp8);
			float fTemp26 = fmaxf(0.0f, fminf(2047.0f, fSlow44 * (fTemp25 / fTemp20)));
			int iTemp27 = (int)(fTemp26);
			float fTemp28 = floorf(fTemp26);
			float fTemp29 = fTemp24 - dsp->fVec5[(dsp->IOTA0 - iTemp27) & 4095] * (fTemp28 + (1.0f - fTemp26)) - (fTemp26 - fTemp28) * dsp->fVec5[(dsp->IOTA0 - (iTemp27 + 1)) & 4095];
			float fTemp30 = dsp->fConst1 * fTemp29;
			float fTemp31 = fmaxf(2e+01f, fabsf(fTemp19));
			float fTemp32 = ((iTemp1) ? 0.0f : dsp->fRec15[1] + dsp->fConst2 * fTemp31);
			dsp->fRec15[0] = fTemp32 - floorf(fTemp32);
			float fTemp33 = mydsp_faustpower2_f(2.0f * dsp->fRec15[0] + -1.0f);
			dsp->fVec6[0] = fTemp33;
			dsp->fVec7[dsp->IOTA0 & 8191] = fTemp0 * (fTemp33 - dsp->fVec6[1]) / fTemp31;
			float fTemp34 = dsp->fVec7[(dsp->IOTA0 - max(0, min(8191, (int)(fSlow44 * (fTemp25 / fTemp19) + 0.5f)))) & 8191];
			float fTemp35 = ((iSlow53) ? fTemp18 : ((iSlow54) ? fTemp17 : fTemp16));
			float fTemp36 = fSlow51 * fTemp35;
			float fTemp37 = fmaxf(fTemp36, 23.44895f);
			float fTemp38 = fmaxf(2e+01f, fabsf(fTemp37));
			float fTemp39 = ((iTemp1) ? 0.0f : dsp->fRec16[1] + dsp->fConst2 * fTemp38);
			dsp->fRec16[0] = fTemp39 - floorf(fTemp39);
			float fTemp40 = mydsp_faustpower2_f(2.0f * dsp->fRec16[0] + -1.0f);
			dsp->fVec8[0] = fTemp40;
			float fTemp41 = fTemp0 * (fTemp40 - dsp->fVec8[1]) / fTemp38;
			dsp->fVec9[dsp->IOTA0 & 4095] = fTemp41;
			dsp->fRec17[0] = fSlow55 + dsp->fConst4 * dsp->fRec17[1];
			float fTemp42 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst0 * (dsp->fRec17[0] / fTemp37)));
			int iTemp43 = (int)(fTemp42);
			float fTemp44 = floorf(fTemp42);
			float fTemp45 = fTemp41 - dsp->fVec9[(dsp->IOTA0 - iTemp43) & 4095] * (fTemp44 + (1.0f - fTemp42)) - (fTemp42 - fTemp44) * dsp->fVec9[(dsp->IOTA0 - (iTemp43 + 1)) & 4095];
			float fTemp46 = dsp->fConst1 * fTemp45;
			float fTemp47 = fmaxf(2e+01f, fabsf(fTemp36));
			float fTemp48 = ((iTemp1) ? 0.0f : dsp->fRec18[1] + dsp->fConst2 * fTemp47);
			dsp->fRec18[0] = fTemp48 - floorf(fTemp48);
			float fTemp49 = mydsp_faustpower2_f(2.0f * dsp->fRec18[0] + -1.0f);
			dsp->fVec10[0] = fTemp49;
			dsp->fVec11[dsp->IOTA0 & 8191] = fTemp0 * (fTemp49 - dsp->fVec10[1]) / fTemp47;
			float fTemp50 = dsp->fVec11[(dsp->IOTA0 - max(0, min(8191, (int)(fSlow56 * (dsp->fRec17[0] / fTemp35) + 0.5f)))) & 8191];
			dsp->fRec19[0] = fSlow57 + 0.1f * dsp->fRec19[1];
			dsp->fRec20[0] = fSlow58 + 0.1f * dsp->fRec20[1];
			float fTemp51 = fSlow6 * ((iSlow8) ? dsp->fConst1 * (fTemp29 + fTemp34) : ((iSlow9) ? dsp->fConst1 * fTemp34 : fTemp30)) + fSlow47 * ((iSlow49) ? dsp->fConst1 * (fTemp45 + fTemp50) : ((iSlow50) ? dsp->fConst1 * fTemp50 : fTemp46)) + dsp->fRec19[0] * fTemp6 + dsp->fRec20[0] * (float)((int)(fTemp30) ^ (int)(fTemp46));
			dsp->fRec21[0] = dsp->fConst8 * (fSlow59 + fSlow60 * fTemp8 + fSlow61 * fTemp11 + fSlow62 * fTemp14) + dsp->fConst7 * dsp->fRec21[1];
			float fTemp52 = fminf(fmaxf(0.0f, mydsp_faustpower2_f(dsp->fRec21[0])), 1.0f);
			float fTemp53 = tanf(dsp->fConst6 * powf(1e+01f, 3.0f * fTemp52 + 1.0f));
			float fTemp54 = (fTemp51 - dsp->fRec2[1]) * fTemp53;
			float fTemp55 = fTemp53 + 1.0f;
			float fTemp56 = (fTemp51 - (dsp->fRec2[1] + (fTemp54 - dsp->fRec3[1] + fTemp53 * dsp->fRec1[1] / fTemp55) / fTemp55)) / (1.0f - fSlow65 * (fTemp53 * (1.0f - fTemp53 / fTemp55) / fTemp55));
			float fRec0 = fTemp56;
			float fTemp57 = fSlow65 * fTemp56;
			float fTemp58 = fTemp53 * (fTemp57 - dsp->fRec1[1]) / fTemp55;
			dsp->fRec1[0] = dsp->fRec1[1] + 2.0f * fTemp58;
			dsp->fRec2[0] = dsp->fRec2[1] + 2.0f * (fTemp54 / fTemp55);
			dsp->fRec3[0] = dsp->fRec3[1] + 2.0f * (fTemp53 * (fTemp57 - (fTemp58 + dsp->fRec3[1] + dsp->fRec1[1])) / fTemp55);
			float fTemp59 = tanf(1.5707964f * fminf(fmaxf(0.0f, ((iSlow66) ? fSlow67 * fTemp15 * fTemp52 : fTemp52)), 1.0f));
			float fTemp60 = fTemp59 + 1.0f;
			float fTemp61 = fTemp59 * ((fTemp51 - fSlow68 * (1.0f - fTemp59 / fTemp60) * (dsp->fRec25[1] + fTemp59 * (dsp->fRec24[1] + fTemp59 * (dsp->fRec23[1] + fTemp59 * dsp->fRec22[1] / fTemp60) / fTemp60) / fTemp60)) / (fSlow68 * (mydsp_faustpower4_f(fTemp59) / mydsp_faustpower4_f(fTemp60)) + 1.0f) - dsp->fRec22[1]) / fTemp60;
			dsp->fRec22[0] = dsp->fRec22[1] + 2.0f * fTemp61;
			float fTemp62 = fTemp59 * (dsp->fRec22[1] + fTemp61 - dsp->fRec23[1]) / fTemp60;
			dsp->fRec23[0] = dsp->fRec23[1] + 2.0f * fTemp62;
			float fTemp63 = fTemp59 * (dsp->fRec23[1] + fTemp62 - dsp->fRec24[1]) / fTemp60;
			dsp->fRec24[0] = dsp->fRec24[1] + 2.0f * fTemp63;
			float fTemp64 = fTemp59 * (dsp->fRec24[1] + fTemp63 - dsp->fRec25[1]) / fTemp60;
			dsp->fRec25[0] = dsp->fRec25[1] + 2.0f * fTemp64;
			float fRec26 = dsp->fRec25[1] + fTemp64;
			float fTemp65 = fSlow69 + fTemp53;
			float fTemp66 = fTemp51 - (dsp->fRec27[1] + dsp->fRec28[1] * fTemp65);
			float fTemp67 = fTemp53 * fTemp65 + 1.0f;
			float fTemp68 = fTemp53 * fTemp66 / fTemp67;
			float fTemp69 = fmaxf(-1.0f, fminf(1.0f, dsp->fRec28[1] + fTemp68));
			float fTemp70 = 1.0f - 0.33333334f * mydsp_faustpower2_f(fTemp69);
			float fTemp71 = fTemp53 * fTemp69 * fTemp70;
			dsp->fRec27[0] = dsp->fRec27[1] + 2.0f * fTemp71;
			float fTemp72 = fTemp69 * fTemp70;
			dsp->fRec28[0] = fTemp68 + fTemp72;
			float fRec29 = fTemp72;
			float fTemp73 = fminf(fmaxf(0.0f, ((iSlow70) ? 1.0f - fSlow71 * (1.0f - fTemp11) : fSlow71 * fTemp11) + ((iSlow72) ? 1.0f - fSlow73 * (1.0f - fTemp14) : fSlow73 * fTemp14) + fSlow74 * fTemp8), 1.0f);
			dsp->fVbargraph3 = (FAUSTFLOAT)(fTemp73);
			float fTemp74 = ((iSlow4) ? fRec29 : ((iSlow5) ? fRec26 : fRec0)) * fTemp73;
			float fTemp75 = fSlow0 * fTemp74 + fSlow75 * dsp->fRec30[1];
			dsp->fVec12[dsp->IOTA0 & 16383] = fTemp75;
			float fTemp76 = ((dsp->fRec31[1] != 0.0f) ? (((dsp->fRec32[1] > 0.0f) & (dsp->fRec32[1] < 1.0f)) ? dsp->fRec31[1] : 0.0f) : (((dsp->fRec32[1] == 0.0f) & (fSlow76 != dsp->fRec33[1])) ? dsp->fConst3 : (((dsp->fRec32[1] == 1.0f) & (fSlow76 != dsp->fRec34[1])) ? -dsp->fConst3 : 0.0f)));
			dsp->fRec31[0] = fTemp76;
			dsp->fRec32[0] = fmaxf(0.0f, fminf(1.0f, dsp->fRec32[1] + fTemp76));
			dsp->fRec33[0] = (((dsp->fRec32[1] >= 1.0f) & (dsp->fRec34[1] != fSlow76)) ? fSlow76 : dsp->fRec33[1]);
			dsp->fRec34[0] = (((dsp->fRec32[1] <= 0.0f) & (dsp->fRec33[1] != fSlow76)) ? fSlow76 : dsp->fRec34[1]);
			float fTemp77 = dsp->fVec12[(dsp->IOTA0 - (int)(fminf(8192.0f, fmaxf(0.0f, dsp->fRec33[0])))) & 16383];
			dsp->fRec30[0] = fTemp77 + dsp->fRec32[0] * (dsp->fVec12[(dsp->IOTA0 - (int)(fminf(8192.0f, fmaxf(0.0f, dsp->fRec34[0])))) & 16383] - fTemp77);
			output0[i0] = (FAUSTFLOAT)(fSlow2 * fTemp74 + fSlow1 * dsp->fRec30[0]);
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->fRec5[1] = dsp->fRec5[0];
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
			dsp->fVec2[1] = dsp->fVec2[0];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->iRec11[1] = dsp->iRec11[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->iRec13[1] = dsp->iRec13[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->fVec4[1] = dsp->fVec4[0];
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fVec6[1] = dsp->fVec6[0];
			dsp->fRec16[1] = dsp->fRec16[0];
			dsp->fVec8[1] = dsp->fVec8[0];
			dsp->fRec17[1] = dsp->fRec17[0];
			dsp->fRec18[1] = dsp->fRec18[0];
			dsp->fVec10[1] = dsp->fVec10[0];
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fRec20[1] = dsp->fRec20[0];
			dsp->fRec21[1] = dsp->fRec21[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->fRec3[1] = dsp->fRec3[0];
			dsp->fRec22[1] = dsp->fRec22[0];
			dsp->fRec23[1] = dsp->fRec23[0];
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fRec25[1] = dsp->fRec25[0];
			dsp->fRec27[1] = dsp->fRec27[0];
			dsp->fRec28[1] = dsp->fRec28[0];
			dsp->fRec31[1] = dsp->fRec31[0];
			dsp->fRec32[1] = dsp->fRec32[0];
			dsp->fRec33[1] = dsp->fRec33[0];
			dsp->fRec34[1] = dsp->fRec34[0];
			dsp->fRec30[1] = dsp->fRec30[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
