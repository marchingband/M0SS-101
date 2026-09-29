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
	int iVec0[2];
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
	float fRec5[2];
	float fVec1[2];
	FAUSTFLOAT fHslider8;
	int iRec7[2];
	float fRec8[4];
	float fRec6[2];
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fButton0;
	int iRec9[2];
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fHslider12;
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	int iVec2[2];
	float fRec11[2];
	float fRec10[2];
	FAUSTFLOAT fVbargraph1;
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fHslider16;
	int iRec12[2];
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	int iVec3[2];
	float fRec14[2];
	float fRec13[2];
	FAUSTFLOAT fVbargraph2;
	float fRec4[2];
	FAUSTFLOAT fHslider21;
	FAUSTFLOAT fHslider22;
	FAUSTFLOAT fHslider23;
	float fConst5;
	FAUSTFLOAT fHslider24;
	FAUSTFLOAT fHslider25;
	FAUSTFLOAT fHslider26;
	FAUSTFLOAT fHslider27;
	FAUSTFLOAT fHslider28;
	FAUSTFLOAT fHslider29;
	FAUSTFLOAT fHslider30;
	FAUSTFLOAT fHslider31;
	float fRec16[2];
	FAUSTFLOAT fHslider32;
	FAUSTFLOAT fHslider33;
	FAUSTFLOAT fHslider34;
	float fRec15[2];
	float fVec4[2];
	int IOTA0;
	float fVec5[4096];
	FAUSTFLOAT fHslider35;
	FAUSTFLOAT fHslider36;
	float fConst6;
	float fConst7;
	float fConst8;
	FAUSTFLOAT fHslider37;
	float fRec17[2];
	FAUSTFLOAT fHslider38;
	float fRec18[2];
	float fVec6[2];
	float fVec7[8192];
	FAUSTFLOAT fHslider39;
	FAUSTFLOAT fHslider40;
	FAUSTFLOAT fHslider41;
	FAUSTFLOAT fHslider42;
	float fRec19[2];
	float fVec8[2];
	float fVec9[4096];
	FAUSTFLOAT fHslider43;
	float fRec20[2];
	float fRec21[2];
	float fVec10[2];
	float fVec11[8192];
	FAUSTFLOAT fHslider44;
	float fRec22[2];
	FAUSTFLOAT fHslider45;
	float fRec23[2];
	float fRec0[2];
	float fRec1[2];
	float fRec2[2];
	FAUSTFLOAT fHslider46;
	float fRec24[2];
	float fRec25[2];
	float fRec26[2];
	float fRec27[2];
	float fRec30[2];
	float fRec31[2];
	FAUSTFLOAT fHslider47;
	FAUSTFLOAT fHslider48;
	FAUSTFLOAT fHslider49;
	FAUSTFLOAT fHslider50;
	FAUSTFLOAT fHslider51;
	FAUSTFLOAT fVbargraph3;
	FAUSTFLOAT fHslider52;
	float fVec12[16384];
	FAUSTFLOAT fHslider53;
	float fRec33[2];
	float fRec34[2];
	float fRec35[2];
	float fRec36[2];
	float fRec32[2];
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
	dsp->fHslider3 = (FAUSTFLOAT)(1.0f);
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
	dsp->fHslider15 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider16 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider17 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider18 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider19 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider20 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider21 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider22 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider23 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider24 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider25 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider26 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider27 = (FAUSTFLOAT)(8192.0f);
	dsp->fHslider28 = (FAUSTFLOAT)(2.0f);
	dsp->fHslider29 = (FAUSTFLOAT)(2.0f);
	dsp->fHslider30 = (FAUSTFLOAT)(45.0f);
	dsp->fHslider31 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider32 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider33 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider34 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider35 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider36 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider37 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider38 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider39 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider40 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider41 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider42 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider43 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider44 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider45 = (FAUSTFLOAT)(0.0f);
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
			dsp->fVec1[l2] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1) {
			dsp->iRec7[l3] = 0;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 4; l4 = l4 + 1) {
			dsp->fRec8[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->fRec6[l5] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->iRec9[l6] = 0;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 2; l7 = l7 + 1) {
			dsp->iVec2[l7] = 0;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 2; l8 = l8 + 1) {
			dsp->fRec11[l8] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 2; l9 = l9 + 1) {
			dsp->fRec10[l9] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 2; l10 = l10 + 1) {
			dsp->iRec12[l10] = 0;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 2; l11 = l11 + 1) {
			dsp->iVec3[l11] = 0;
		}
	}
	/* C99 loop */
	{
		int l12;
		for (l12 = 0; l12 < 2; l12 = l12 + 1) {
			dsp->fRec14[l12] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l13;
		for (l13 = 0; l13 < 2; l13 = l13 + 1) {
			dsp->fRec13[l13] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l14;
		for (l14 = 0; l14 < 2; l14 = l14 + 1) {
			dsp->fRec4[l14] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l15;
		for (l15 = 0; l15 < 2; l15 = l15 + 1) {
			dsp->fRec16[l15] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l16;
		for (l16 = 0; l16 < 2; l16 = l16 + 1) {
			dsp->fRec15[l16] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l17;
		for (l17 = 0; l17 < 2; l17 = l17 + 1) {
			dsp->fVec4[l17] = 0.0f;
		}
	}
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l18;
		for (l18 = 0; l18 < 4096; l18 = l18 + 1) {
			dsp->fVec5[l18] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l19;
		for (l19 = 0; l19 < 2; l19 = l19 + 1) {
			dsp->fRec17[l19] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l20;
		for (l20 = 0; l20 < 2; l20 = l20 + 1) {
			dsp->fRec18[l20] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l21;
		for (l21 = 0; l21 < 2; l21 = l21 + 1) {
			dsp->fVec6[l21] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l22;
		for (l22 = 0; l22 < 8192; l22 = l22 + 1) {
			dsp->fVec7[l22] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l23;
		for (l23 = 0; l23 < 2; l23 = l23 + 1) {
			dsp->fRec19[l23] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l24;
		for (l24 = 0; l24 < 2; l24 = l24 + 1) {
			dsp->fVec8[l24] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l25;
		for (l25 = 0; l25 < 4096; l25 = l25 + 1) {
			dsp->fVec9[l25] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l26;
		for (l26 = 0; l26 < 2; l26 = l26 + 1) {
			dsp->fRec20[l26] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l27;
		for (l27 = 0; l27 < 2; l27 = l27 + 1) {
			dsp->fRec21[l27] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l28;
		for (l28 = 0; l28 < 2; l28 = l28 + 1) {
			dsp->fVec10[l28] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l29;
		for (l29 = 0; l29 < 8192; l29 = l29 + 1) {
			dsp->fVec11[l29] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l30;
		for (l30 = 0; l30 < 2; l30 = l30 + 1) {
			dsp->fRec22[l30] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l31;
		for (l31 = 0; l31 < 2; l31 = l31 + 1) {
			dsp->fRec23[l31] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l32;
		for (l32 = 0; l32 < 2; l32 = l32 + 1) {
			dsp->fRec0[l32] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l33;
		for (l33 = 0; l33 < 2; l33 = l33 + 1) {
			dsp->fRec1[l33] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l34;
		for (l34 = 0; l34 < 2; l34 = l34 + 1) {
			dsp->fRec2[l34] = 0.0f;
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
			dsp->fRec26[l37] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l38;
		for (l38 = 0; l38 < 2; l38 = l38 + 1) {
			dsp->fRec27[l38] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l39;
		for (l39 = 0; l39 < 2; l39 = l39 + 1) {
			dsp->fRec30[l39] = 0.0f;
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
		for (l41 = 0; l41 < 16384; l41 = l41 + 1) {
			dsp->fVec12[l41] = 0.0f;
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
			dsp->fRec35[l44] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l45;
		for (l45 = 0; l45 < 2; l45 = l45 + 1) {
			dsp->fRec36[l45] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l46;
		for (l46 = 0; l46 < 2; l46 = l46 + 1) {
			dsp->fRec32[l46] = 0.0f;
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
	dsp->fConst6 = 1e+01f / dsp->fConst0;
	dsp->fConst7 = expf(-dsp->fConst6);
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "envII-mod", "16");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "midi", "50");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "attackII", &dsp->fHslider19, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "midi", "1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "mod", "16");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "attack", &dsp->fHslider13, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "midi", "2");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "mod", "14");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoff", &dsp->fHslider3, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider52, "alt", "21");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider52, "midi", "37");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "d_fb", &dsp->fHslider52, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider53, "alt", "19");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider53, "midi", "36");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "d_time", &dsp->fHslider53, (FAUSTFLOAT)1024.0f, (FAUSTFLOAT)1024.0f, (FAUSTFLOAT)8192.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "alt", "25");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "midi", "38");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "d_wet", &dsp->fHslider1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "envII-mod", "19");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "midi", "52");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "decayII", &dsp->fHslider18, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "midi", "29");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "mod", "19");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "decay", &dsp->fHslider12, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider41, "alt", "2");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider41, "midi", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "detune", &dsp->fHslider41, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider33, "midi", "27");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider33, "mod", "20");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-osc", &dsp->fHslider33, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider35, "midi", "28");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider35, "mod", "24");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-pwm", &dsp->fHslider35, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider48, "midi", "25");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider48, "mod", "15");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vca", &dsp->fHslider48, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "midi", "26");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "mod", "18");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vcf", &dsp->fHslider9, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider47, "alt-sel", "15");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider47, "midi", "20");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-vca-inv", &dsp->fHslider47, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider34, "envII-mod", "20");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider34, "midi", "48");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "envII-to-osc", &dsp->fHslider34, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider36, "envII-mod", "24");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider36, "midi", "49");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "envII-to-pwm", &dsp->fHslider36, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider50, "envII-mod", "15");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider50, "midi", "46");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "envII-to-vca", &dsp->fHslider50, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "envII-mod", "18");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "midi", "47");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "envII-to-vcf", &dsp->fHslider15, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider49, "envII-alt-sel", "15");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider49, "midi", "45");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "envII-vca-inv", &dsp->fHslider49, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph2, "envII", "");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "envII", &dsp->fVbargraph2, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph1, "env", "");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "env", &dsp->fVbargraph1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider25, "fine-tune", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider25, "midi", "42");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "fine-tune", &dsp->fHslider25, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)-1e+02f, (FAUSTFLOAT)1e+02f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fButton0, "gate", "");
	ui_interface->addButton(ui_interface->uiInterface, "gate", &dsp->fButton0);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider31, "alt", "23");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider31, "midi", "35");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "glide", &dsp->fHslider31, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.99f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "midi", "16");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "sel", "13");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "hp-lp-bp", &dsp->fHslider2, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider46, "alt-sel", "13");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider46, "midi", "17");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "key-track", &dsp->fHslider46, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "midi", "3");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "mod", "12");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-freq", &dsp->fHslider7, (FAUSTFLOAT)0.3f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "alt-sel", "12");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "midi", "19");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-range", &dsp->fHslider6, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "envII-sel", "9");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "midi", "44");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-envII", &dsp->fHslider16, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "midi", "15");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "sel", "9");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-env", &dsp->fHslider10, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider32, "midi", "21");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider32, "mod", "10");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-osc", &dsp->fHslider32, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider38, "midi", "24");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider38, "mod", "6");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-pwm", &dsp->fHslider38, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider51, "midi", "22");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider51, "mod", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vca", &dsp->fHslider51, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider44, "alt", "5");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider44, "midi", "34");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "noise-vol", &dsp->fHslider44, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider37, "alt", "0");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider37, "midi", "31");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-1-pw", &dsp->fHslider37, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider43, "alt", "3");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider43, "midi", "32");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-2-pw", &dsp->fHslider43, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider24, "midi", "11");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider24, "sel", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-oct", &dsp->fHslider24, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "midi", "4");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "mod", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-vol", &dsp->fHslider22, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider23, "midi", "10");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider23, "sel", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-wavform", &dsp->fHslider23, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider42, "midi", "12");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider42, "sel", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-oct", &dsp->fHslider42, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider39, "midi", "5");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider39, "mod", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-vol", &dsp->fHslider39, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider40, "midi", "13");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider40, "sel", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-wavform", &dsp->fHslider40, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider28, "asb", "11");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider28, "midi", "40");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend-dn", &dsp->fHslider28, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)12.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider29, "asb", "10");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider29, "midi", "39");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend-up", &dsp->fHslider29, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)12.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider27, "pitch-bend", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch-bend", &dsp->fHslider27, (FAUSTFLOAT)8192.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)16383.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider30, "pitch", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch", &dsp->fHslider30, (FAUSTFLOAT)45.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)127.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "envII-mod", "25");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "midi", "51");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "releaseII", &dsp->fHslider20, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "midi", "6");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "mod", "25");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "release", &dsp->fHslider14, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider21, "midi", "7");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider21, "mod", "17");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "resonance", &dsp->fHslider21, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "envII-mod", "21");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "midi", "53");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "sustainII", &dsp->fHslider17, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "midi", "30");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "mod", "21");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "sustain", &dsp->fHslider11, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider26, "midi", "43");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider26, "transpose", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "transpose", &dsp->fHslider26, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)-127.0f, (FAUSTFLOAT)127.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph3, "vca", "");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "vca", &dsp->fVbargraph3, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "midi", "9");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "mod", "23");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "volume", &dsp->fHslider0, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider45, "alt", "4");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider45, "midi", "33");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "xor-vol", &dsp->fHslider45, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
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
	float fSlow21 = (float)(dsp->fHslider15);
	int iSlow22 = (float)(dsp->fHslider16) >= 1.0f;
	float fSlow23 = (float)(dsp->fHslider17);
	float fSlow24 = (fSlow23 + -1.0f) / fmaxf(1.0f, dsp->fConst0 * (19.999f * mydsp_faustpower2_f((float)(dsp->fHslider18)) + 0.001f));
	float fSlow25 = 1.0f / fmaxf(1.0f, dsp->fConst0 * (19.999f * mydsp_faustpower3_f((float)(dsp->fHslider19)) + 0.001f));
	float fSlow26 = 1.0f / fmaxf(1.0f, dsp->fConst0 * (19.999f * mydsp_faustpower2_f((float)(dsp->fHslider20)) + 0.001f));
	float fSlow27 = (float)(dsp->fHslider21);
	float fSlow28 = 24.293f * fSlow27 + 0.707f;
	float fSlow29 = 0.21521576f * (0.33333334f * fSlow28 + -0.707f);
	float fSlow30 = (float)(dsp->fHslider22);
	float fSlow31 = (float)(dsp->fHslider23);
	int iSlow32 = fSlow31 >= 2.0f;
	int iSlow33 = fSlow31 >= 1.0f;
	float fSlow34 = (float)(dsp->fHslider24);
	int iSlow35 = fSlow34 >= 2.0f;
	int iSlow36 = fSlow34 >= 1.0f;
	float fSlow37 = powf(2.0f, 0.00083333335f * (float)(dsp->fHslider25)) * powf(2.0f, 0.083333336f * (float)(dsp->fHslider26));
	float fSlow38 = fminf(fmaxf(-1.0f, 0.00012208521f * ((float)(dsp->fHslider27) + -8192.0f)), 1.0f);
	float fSlow39 = powf(2.0f, 0.083333336f * ((fSlow38 > 0.0f) ? fSlow38 * (float)(dsp->fHslider29) : fSlow38 * (float)(dsp->fHslider28)));
	float fSlow40 = (float)(dsp->fHslider31);
	int iSlow41 = fabsf(fSlow40) < 1.1920929e-07f;
	float fSlow42 = ((iSlow41) ? 0.0f : expf(-(dsp->fConst4 / ((iSlow41) ? 1.0f : fSlow40))));
	float fSlow43 = 4.4e+02f * powf(2.0f, 0.083333336f * ((float)(dsp->fHslider30) + -69.0f)) * (1.0f - fSlow42);
	float fSlow44 = mydsp_faustpower2_f((float)(dsp->fHslider32));
	float fSlow45 = mydsp_faustpower2_f((float)(dsp->fHslider33));
	float fSlow46 = mydsp_faustpower2_f((float)(dsp->fHslider34));
	float fSlow47 = 0.5f * fSlow37;
	float fSlow48 = 0.25f * fSlow37;
	float fSlow49 = dsp->fConst0 * (1.0f - (float)(dsp->fHslider35)) * (1.0f - (float)(dsp->fHslider36));
	float fSlow50 = dsp->fConst8 * (float)(dsp->fHslider37);
	float fSlow51 = (float)(dsp->fHslider38);
	float fSlow52 = (float)(dsp->fHslider39);
	float fSlow53 = (float)(dsp->fHslider40);
	int iSlow54 = fSlow53 >= 2.0f;
	int iSlow55 = fSlow53 >= 1.0f;
	float fSlow56 = powf(2.0f, mydsp_faustpower2_f((float)(dsp->fHslider41)));
	float fSlow57 = (float)(dsp->fHslider42);
	int iSlow58 = fSlow57 >= 2.0f;
	int iSlow59 = fSlow57 >= 1.0f;
	float fSlow60 = dsp->fConst8 * (float)(dsp->fHslider43);
	float fSlow61 = dsp->fConst0 / fSlow56;
	float fSlow62 = 0.9f * (float)(dsp->fHslider44);
	float fSlow63 = 0.9f * (float)(dsp->fHslider45);
	int iSlow64 = (float)(dsp->fHslider46) >= 1.0f;
	float fSlow65 = 0.0022727272f * fSlow37;
	float fSlow66 = 4.0f * fSlow27;
	float fSlow67 = 1.0f / fSlow28;
	int iSlow68 = (float)(dsp->fHslider47) >= 1.0f;
	float fSlow69 = (float)(dsp->fHslider48);
	int iSlow70 = (float)(dsp->fHslider49) >= 1.0f;
	float fSlow71 = (float)(dsp->fHslider50);
	float fSlow72 = (float)(dsp->fHslider51);
	float fSlow73 = (float)(dsp->fHslider52);
	float fSlow74 = (float)(dsp->fHslider53);
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec0[0] = 1;
			int iTemp0 = 1 - dsp->iVec0[1];
			float fTemp1 = ((iTemp0) ? 0.0f : dsp->fRec5[1] + fSlow12);
			dsp->fRec5[0] = fTemp1 - floorf(fTemp1);
			float fTemp2 = (float)(dsp->fRec5[0] <= 0.5f);
			dsp->fVec1[0] = fTemp2;
			int iTemp3 = (dsp->fVec1[1] <= 0.0f) & (fTemp2 > 0.0f);
			dsp->iRec7[0] = 1103515245 * dsp->iRec7[1] + 12345;
			float fTemp4 = 4.656613e-10f * (float)(dsp->iRec7[0]);
			dsp->fRec8[0] = 0.5221894f * dsp->fRec8[3] + fTemp4 + 2.494956f * dsp->fRec8[1] - 2.0172658f * dsp->fRec8[2];
			float fTemp5 = ((iSlow13) ? 3.0f * (0.049922034f * dsp->fRec8[0] + 0.0506127f * dsp->fRec8[2] - (0.095993534f * dsp->fRec8[1] + 0.004408786f * dsp->fRec8[3])) : fTemp4);
			dsp->fRec6[0] = dsp->fRec6[1] * (float)(1 - iTemp3) + 0.5f * (fTemp5 + 1.0f) * (float)(iTemp3);
			float fTemp6 = ((iSlow9) ? dsp->fRec6[0] : ((iSlow10) ? fTemp2 : 1.0f - fabsf(2.0f * dsp->fRec5[0] + -1.0f)));
			dsp->fVbargraph0 = (FAUSTFLOAT)(fTemp6);
			float fTemp7 = fTemp6;
			float fTemp8 = ((iSlow15) ? fTemp2 : fSlow16);
			int iTemp9 = dsp->iRec9[1] == 0;
			int iTemp10 = dsp->iRec9[1] == 1;
			dsp->iRec9[0] = ((fTemp8 > 0.0f) ? ((iTemp9) ? 1 : ((iTemp10) ? ((dsp->fRec10[1] < 1.0f) ? 1 : 2) : 2)) : 0);
			int iTemp11 = fTemp8 == 0.0f;
			dsp->iVec2[0] = iTemp11;
			int iTemp12 = (dsp->iVec2[1] <= 0) & (iTemp11 > 0);
			dsp->fRec11[0] = dsp->fRec11[1] * (float)(1 - iTemp12) + dsp->fRec10[1] * (float)(iTemp12);
			dsp->fRec10[0] = fmaxf(((dsp->iRec9[1] == 2) ? fSlow17 : 0.0f), fminf(1.0f, dsp->fRec10[1] + ((iTemp9) ? -(fSlow20 * dsp->fRec11[0]) : ((iTemp10) ? fSlow19 : fSlow18))));
			dsp->fVbargraph1 = (FAUSTFLOAT)(dsp->fRec10[0]);
			float fTemp13 = dsp->fRec10[0];
			float fTemp14 = ((iSlow22) ? fTemp2 : fSlow16);
			int iTemp15 = dsp->iRec12[1] == 0;
			int iTemp16 = dsp->iRec12[1] == 1;
			dsp->iRec12[0] = ((fTemp14 > 0.0f) ? ((iTemp15) ? 1 : ((iTemp16) ? ((dsp->fRec13[1] < 1.0f) ? 1 : 2) : 2)) : 0);
			int iTemp17 = fTemp14 == 0.0f;
			dsp->iVec3[0] = iTemp17;
			int iTemp18 = (dsp->iVec3[1] <= 0) & (iTemp17 > 0);
			dsp->fRec14[0] = dsp->fRec14[1] * (float)(1 - iTemp18) + dsp->fRec13[1] * (float)(iTemp18);
			dsp->fRec13[0] = fmaxf(((dsp->iRec12[1] == 2) ? fSlow23 : 0.0f), fminf(1.0f, dsp->fRec13[1] + ((iTemp15) ? -(fSlow26 * dsp->fRec14[0]) : ((iTemp16) ? fSlow25 : fSlow24))));
			dsp->fVbargraph2 = (FAUSTFLOAT)(dsp->fRec13[0]);
			float fTemp19 = dsp->fRec13[0];
			dsp->fRec4[0] = dsp->fConst3 * (fSlow6 + fSlow7 * fTemp7 + fSlow14 * fTemp13 + fSlow21 * fTemp19) + dsp->fConst2 * dsp->fRec4[1];
			float fTemp20 = fminf(fmaxf(0.0f, mydsp_faustpower2_f(dsp->fRec4[0])), 1.0f);
			float fTemp21 = tanf(dsp->fConst1 * powf(1e+01f, 3.0f * fTemp20 + 1.0f));
			float fTemp22 = (float)(dsp->iVec0[1]);
			dsp->fRec16[0] = fSlow43 + fSlow42 * dsp->fRec16[1];
			float fTemp23 = fSlow39 * dsp->fRec16[0] * powf(2.0f, 10.583333f * (fSlow44 * (fTemp7 + -0.5f) + fSlow45 * fTemp13 + fSlow46 * fTemp19));
			float fTemp24 = fSlow37 * fTemp23;
			float fTemp25 = fSlow47 * fTemp23;
			float fTemp26 = fSlow48 * fTemp23;
			float fTemp27 = ((iSlow35) ? fTemp26 : ((iSlow36) ? fTemp25 : fTemp24));
			float fTemp28 = fmaxf(fTemp27, 23.44895f);
			float fTemp29 = fmaxf(2e+01f, fabsf(fTemp28));
			float fTemp30 = ((iTemp0) ? 0.0f : dsp->fRec15[1] + dsp->fConst4 * fTemp29);
			dsp->fRec15[0] = fTemp30 - floorf(fTemp30);
			float fTemp31 = mydsp_faustpower2_f(2.0f * dsp->fRec15[0] + -1.0f);
			dsp->fVec4[0] = fTemp31;
			float fTemp32 = fTemp22 * (fTemp31 - dsp->fVec4[1]) / fTemp29;
			dsp->fVec5[dsp->IOTA0 & 4095] = fTemp32;
			dsp->fRec17[0] = fSlow50 + dsp->fConst7 * dsp->fRec17[1];
			float fTemp33 = dsp->fRec17[0] * (1.0f - fSlow51 * fTemp7);
			float fTemp34 = fmaxf(0.0f, fminf(2047.0f, fSlow49 * (fTemp33 / fTemp28)));
			int iTemp35 = (int)(fTemp34);
			float fTemp36 = floorf(fTemp34);
			float fTemp37 = fTemp32 - dsp->fVec5[(dsp->IOTA0 - iTemp35) & 4095] * (fTemp36 + (1.0f - fTemp34)) - (fTemp34 - fTemp36) * dsp->fVec5[(dsp->IOTA0 - (iTemp35 + 1)) & 4095];
			float fTemp38 = dsp->fConst5 * fTemp37;
			float fTemp39 = fmaxf(2e+01f, fabsf(fTemp27));
			float fTemp40 = ((iTemp0) ? 0.0f : dsp->fRec18[1] + dsp->fConst4 * fTemp39);
			dsp->fRec18[0] = fTemp40 - floorf(fTemp40);
			float fTemp41 = mydsp_faustpower2_f(2.0f * dsp->fRec18[0] + -1.0f);
			dsp->fVec6[0] = fTemp41;
			dsp->fVec7[dsp->IOTA0 & 8191] = fTemp22 * (fTemp41 - dsp->fVec6[1]) / fTemp39;
			float fTemp42 = dsp->fVec7[(dsp->IOTA0 - max(0, min(8191, (int)(fSlow49 * (fTemp33 / fTemp27) + 0.5f)))) & 8191];
			float fTemp43 = ((iSlow58) ? fTemp26 : ((iSlow59) ? fTemp25 : fTemp24));
			float fTemp44 = fSlow56 * fTemp43;
			float fTemp45 = fmaxf(fTemp44, 23.44895f);
			float fTemp46 = fmaxf(2e+01f, fabsf(fTemp45));
			float fTemp47 = ((iTemp0) ? 0.0f : dsp->fRec19[1] + dsp->fConst4 * fTemp46);
			dsp->fRec19[0] = fTemp47 - floorf(fTemp47);
			float fTemp48 = mydsp_faustpower2_f(2.0f * dsp->fRec19[0] + -1.0f);
			dsp->fVec8[0] = fTemp48;
			float fTemp49 = fTemp22 * (fTemp48 - dsp->fVec8[1]) / fTemp46;
			dsp->fVec9[dsp->IOTA0 & 4095] = fTemp49;
			dsp->fRec20[0] = fSlow60 + dsp->fConst7 * dsp->fRec20[1];
			float fTemp50 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst0 * (dsp->fRec20[0] / fTemp45)));
			int iTemp51 = (int)(fTemp50);
			float fTemp52 = floorf(fTemp50);
			float fTemp53 = fTemp49 - dsp->fVec9[(dsp->IOTA0 - iTemp51) & 4095] * (fTemp52 + (1.0f - fTemp50)) - (fTemp50 - fTemp52) * dsp->fVec9[(dsp->IOTA0 - (iTemp51 + 1)) & 4095];
			float fTemp54 = dsp->fConst5 * fTemp53;
			float fTemp55 = fmaxf(2e+01f, fabsf(fTemp44));
			float fTemp56 = ((iTemp0) ? 0.0f : dsp->fRec21[1] + dsp->fConst4 * fTemp55);
			dsp->fRec21[0] = fTemp56 - floorf(fTemp56);
			float fTemp57 = mydsp_faustpower2_f(2.0f * dsp->fRec21[0] + -1.0f);
			dsp->fVec10[0] = fTemp57;
			dsp->fVec11[dsp->IOTA0 & 8191] = fTemp22 * (fTemp57 - dsp->fVec10[1]) / fTemp55;
			float fTemp58 = dsp->fVec11[(dsp->IOTA0 - max(0, min(8191, (int)(fSlow61 * (dsp->fRec20[0] / fTemp43) + 0.5f)))) & 8191];
			dsp->fRec22[0] = fSlow62 + 0.1f * dsp->fRec22[1];
			dsp->fRec23[0] = fSlow63 + 0.1f * dsp->fRec23[1];
			float fTemp59 = fSlow30 * ((iSlow32) ? dsp->fConst5 * (fTemp37 + fTemp42) : ((iSlow33) ? dsp->fConst5 * fTemp42 : fTemp38)) + fSlow52 * ((iSlow54) ? dsp->fConst5 * (fTemp53 + fTemp58) : ((iSlow55) ? dsp->fConst5 * fTemp58 : fTemp54)) + dsp->fRec22[0] * fTemp5 + dsp->fRec23[0] * (float)((int)(fTemp38) ^ (int)(fTemp54));
			float fTemp60 = (fTemp59 - dsp->fRec2[1]) * fTemp21;
			float fTemp61 = fTemp21 + 1.0f;
			float fTemp62 = (fTemp59 - (dsp->fRec2[1] + (fTemp60 - dsp->fRec0[1] + fTemp21 * dsp->fRec1[1] / fTemp61) / fTemp61)) / (1.0f - fSlow29 * (fTemp21 * (1.0f - fTemp21 / fTemp61) / fTemp61));
			float fTemp63 = fSlow29 * fTemp62;
			float fTemp64 = fTemp21 * (fTemp63 - dsp->fRec1[1]) / fTemp61;
			dsp->fRec0[0] = dsp->fRec0[1] + 2.0f * (fTemp21 * (fTemp63 - (fTemp64 + dsp->fRec0[1] + dsp->fRec1[1])) / fTemp61);
			dsp->fRec1[0] = dsp->fRec1[1] + 2.0f * fTemp64;
			dsp->fRec2[0] = dsp->fRec2[1] + 2.0f * (fTemp60 / fTemp61);
			float fRec3 = fTemp62;
			float fTemp65 = tanf(1.5707964f * fminf(fmaxf(0.0f, ((iSlow64) ? fSlow65 * fTemp23 * fTemp20 : fTemp20)), 1.0f));
			float fTemp66 = fTemp65 + 1.0f;
			float fTemp67 = fTemp65 * ((fTemp59 - fSlow66 * (1.0f - fTemp65 / fTemp66) * (dsp->fRec27[1] + fTemp65 * (dsp->fRec26[1] + fTemp65 * (dsp->fRec25[1] + fTemp65 * dsp->fRec24[1] / fTemp66) / fTemp66) / fTemp66)) / (fSlow66 * (mydsp_faustpower4_f(fTemp65) / mydsp_faustpower4_f(fTemp66)) + 1.0f) - dsp->fRec24[1]) / fTemp66;
			dsp->fRec24[0] = dsp->fRec24[1] + 2.0f * fTemp67;
			float fTemp68 = fTemp65 * (dsp->fRec24[1] + fTemp67 - dsp->fRec25[1]) / fTemp66;
			dsp->fRec25[0] = dsp->fRec25[1] + 2.0f * fTemp68;
			float fTemp69 = fTemp65 * (dsp->fRec25[1] + fTemp68 - dsp->fRec26[1]) / fTemp66;
			dsp->fRec26[0] = dsp->fRec26[1] + 2.0f * fTemp69;
			float fTemp70 = fTemp65 * (dsp->fRec26[1] + fTemp69 - dsp->fRec27[1]) / fTemp66;
			dsp->fRec27[0] = dsp->fRec27[1] + 2.0f * fTemp70;
			float fRec28 = dsp->fRec27[1] + fTemp70;
			float fTemp71 = fSlow67 + fTemp21;
			float fTemp72 = fTemp59 - (dsp->fRec30[1] + dsp->fRec31[1] * fTemp71);
			float fTemp73 = fTemp21 * fTemp71 + 1.0f;
			float fTemp74 = fTemp21 * fTemp72 / fTemp73;
			float fTemp75 = fmaxf(-1.0f, fminf(1.0f, dsp->fRec31[1] + fTemp74));
			float fTemp76 = 1.0f - 0.33333334f * mydsp_faustpower2_f(fTemp75);
			float fTemp77 = fTemp75 * fTemp76;
			float fRec29 = fTemp77;
			float fTemp78 = fTemp21 * fTemp75 * fTemp76;
			dsp->fRec30[0] = dsp->fRec30[1] + 2.0f * fTemp78;
			dsp->fRec31[0] = fTemp74 + fTemp77;
			float fTemp79 = fminf(fmaxf(0.0f, ((iSlow68) ? 1.0f - fSlow69 * (1.0f - fTemp13) : fSlow69 * fTemp13) + ((iSlow70) ? 1.0f - fSlow71 * (1.0f - fTemp19) : fSlow71 * fTemp19) + fSlow72 * fTemp7), 1.0f);
			dsp->fVbargraph3 = (FAUSTFLOAT)(fTemp79);
			float fTemp80 = ((iSlow4) ? fRec29 : ((iSlow5) ? fRec28 : fRec3)) * fTemp79;
			float fTemp81 = fSlow0 * fTemp80 + fSlow73 * dsp->fRec32[1];
			dsp->fVec12[dsp->IOTA0 & 16383] = fTemp81;
			float fTemp82 = ((dsp->fRec33[1] != 0.0f) ? (((dsp->fRec34[1] > 0.0f) & (dsp->fRec34[1] < 1.0f)) ? dsp->fRec33[1] : 0.0f) : (((dsp->fRec34[1] == 0.0f) & (fSlow74 != dsp->fRec35[1])) ? dsp->fConst6 : (((dsp->fRec34[1] == 1.0f) & (fSlow74 != dsp->fRec36[1])) ? -dsp->fConst6 : 0.0f)));
			dsp->fRec33[0] = fTemp82;
			dsp->fRec34[0] = fmaxf(0.0f, fminf(1.0f, dsp->fRec34[1] + fTemp82));
			dsp->fRec35[0] = (((dsp->fRec34[1] >= 1.0f) & (dsp->fRec36[1] != fSlow74)) ? fSlow74 : dsp->fRec35[1]);
			dsp->fRec36[0] = (((dsp->fRec34[1] <= 0.0f) & (dsp->fRec35[1] != fSlow74)) ? fSlow74 : dsp->fRec36[1]);
			float fTemp83 = dsp->fVec12[(dsp->IOTA0 - (int)(fminf(8192.0f, fmaxf(0.0f, dsp->fRec35[0])))) & 16383];
			dsp->fRec32[0] = fTemp83 + dsp->fRec34[0] * (dsp->fVec12[(dsp->IOTA0 - (int)(fminf(8192.0f, fmaxf(0.0f, dsp->fRec36[0])))) & 16383] - fTemp83);
			output0[i0] = (FAUSTFLOAT)(fSlow2 * fTemp80 + fSlow1 * dsp->fRec32[0]);
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fVec1[1] = dsp->fVec1[0];
			dsp->iRec7[1] = dsp->iRec7[0];
			/* C99 loop */
			{
				int j0;
				for (j0 = 3; j0 > 0; j0 = j0 - 1) {
					dsp->fRec8[j0] = dsp->fRec8[j0 - 1];
				}
			}
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->iRec9[1] = dsp->iRec9[0];
			dsp->iVec2[1] = dsp->iVec2[0];
			dsp->fRec11[1] = dsp->fRec11[0];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->iRec12[1] = dsp->iRec12[0];
			dsp->iVec3[1] = dsp->iVec3[0];
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->fRec16[1] = dsp->fRec16[0];
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fVec4[1] = dsp->fVec4[0];
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec17[1] = dsp->fRec17[0];
			dsp->fRec18[1] = dsp->fRec18[0];
			dsp->fVec6[1] = dsp->fVec6[0];
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fVec8[1] = dsp->fVec8[0];
			dsp->fRec20[1] = dsp->fRec20[0];
			dsp->fRec21[1] = dsp->fRec21[0];
			dsp->fVec10[1] = dsp->fVec10[0];
			dsp->fRec22[1] = dsp->fRec22[0];
			dsp->fRec23[1] = dsp->fRec23[0];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fRec25[1] = dsp->fRec25[0];
			dsp->fRec26[1] = dsp->fRec26[0];
			dsp->fRec27[1] = dsp->fRec27[0];
			dsp->fRec30[1] = dsp->fRec30[0];
			dsp->fRec31[1] = dsp->fRec31[0];
			dsp->fRec33[1] = dsp->fRec33[0];
			dsp->fRec34[1] = dsp->fRec34[0];
			dsp->fRec35[1] = dsp->fRec35[0];
			dsp->fRec36[1] = dsp->fRec36[0];
			dsp->fRec32[1] = dsp->fRec32[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
