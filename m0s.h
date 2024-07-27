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
	int iVec0[2];
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fConst4;
	FAUSTFLOAT fHslider5;
	float fRec6[2];
	float fVec1[2];
	int iRec8[2];
	float fRec7[2];
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fButton0;
	int iRec11[2];
	int iRec9[2];
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fHslider11;
	int iVec2[2];
	float fRec12[2];
	float fRec10[2];
	FAUSTFLOAT fVbargraph1;
	FAUSTFLOAT fHslider12;
	FAUSTFLOAT fHslider13;
	float fRec13[2];
	FAUSTFLOAT fHslider14;
	float fConst5;
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fHslider19;
	float fRec16[2];
	float fConst6;
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fHslider21;
	FAUSTFLOAT fHslider22;
	float fConst7;
	float fRec17[2];
	float fRec15[2];
	float fRec14[2];
	float fVec3[2];
	int IOTA0;
	float fVec4[4096];
	FAUSTFLOAT fHslider23;
	float fConst8;
	float fConst9;
	FAUSTFLOAT fHslider24;
	float fRec18[2];
	FAUSTFLOAT fHslider25;
	float fRec19[2];
	float fVec5[2];
	float fVec6[8192];
	FAUSTFLOAT fHslider26;
	FAUSTFLOAT fHslider27;
	float fRec21[2];
	FAUSTFLOAT fHslider28;
	float fRec20[2];
	float fVec7[2];
	float fVec8[4096];
	FAUSTFLOAT fHslider29;
	float fRec22[2];
	float fRec23[2];
	float fVec9[2];
	FAUSTFLOAT fHslider30;
	float fRec24[2];
	FAUSTFLOAT fHslider31;
	float fRec25[2];
	float fRec1[2];
	float fRec3[2];
	float fRec4[2];
	float fRec26[2];
	float fRec27[2];
	float fRec28[2];
	float fRec29[2];
	float fRec32[2];
	float fRec33[2];
	FAUSTFLOAT fHslider32;
	FAUSTFLOAT fHslider33;
	FAUSTFLOAT fVbargraph2;
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
	m->declare(m->metaInterface, "envelopes.lib/adsr_bias:author", "Andrew John March and David Braun");
	m->declare(m->metaInterface, "envelopes.lib/adsr_bias:licence", "STK-4.3");
	m->declare(m->metaInterface, "envelopes.lib/author", "GRAME");
	m->declare(m->metaInterface, "envelopes.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "envelopes.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "envelopes.lib/name", "Faust Envelope Library");
	m->declare(m->metaInterface, "envelopes.lib/version", "1.3.0");
	m->declare(m->metaInterface, "filename", "m0ss.dsp");
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
	m->declare(m->metaInterface, "oscillators.lib/lf_triangle:author", "Bart Brouns");
	m->declare(m->metaInterface, "oscillators.lib/lf_triangle:licence", "STK-4.3");
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
	dsp->fHslider1 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider2 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider3 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider4 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider5 = (FAUSTFLOAT)(0.3f);
	dsp->fHslider6 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider7 = (FAUSTFLOAT)(0.0f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider8 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider9 = (FAUSTFLOAT)(0.01f);
	dsp->fHslider10 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider11 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider12 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider13 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider14 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider15 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider16 = (FAUSTFLOAT)(4e+01f);
	dsp->fHslider17 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider18 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider19 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider20 = (FAUSTFLOAT)(8192.0f);
	dsp->fHslider21 = (FAUSTFLOAT)(12.0f);
	dsp->fHslider22 = (FAUSTFLOAT)(2.0f);
	dsp->fHslider23 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider24 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider25 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider26 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider27 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider28 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider29 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider30 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider31 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider32 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider33 = (FAUSTFLOAT)(0.0f);
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
			dsp->fRec5[l2] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1) {
			dsp->fRec6[l3] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->fVec1[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->iRec8[l5] = 0;
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
			dsp->iRec11[l7] = 0;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 2; l8 = l8 + 1) {
			dsp->iRec9[l8] = 0;
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
			dsp->fRec12[l10] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 2; l11 = l11 + 1) {
			dsp->fRec10[l11] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l12;
		for (l12 = 0; l12 < 2; l12 = l12 + 1) {
			dsp->fRec13[l12] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l13;
		for (l13 = 0; l13 < 2; l13 = l13 + 1) {
			dsp->fRec16[l13] = 0.0f;
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
			dsp->fRec15[l15] = 0.0f;
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
			dsp->fVec3[l17] = 0.0f;
		}
	}
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l18;
		for (l18 = 0; l18 < 4096; l18 = l18 + 1) {
			dsp->fVec4[l18] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l19;
		for (l19 = 0; l19 < 2; l19 = l19 + 1) {
			dsp->fRec18[l19] = 0.0f;
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
			dsp->fVec5[l21] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l22;
		for (l22 = 0; l22 < 8192; l22 = l22 + 1) {
			dsp->fVec6[l22] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l23;
		for (l23 = 0; l23 < 2; l23 = l23 + 1) {
			dsp->fRec21[l23] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l24;
		for (l24 = 0; l24 < 2; l24 = l24 + 1) {
			dsp->fRec20[l24] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l25;
		for (l25 = 0; l25 < 2; l25 = l25 + 1) {
			dsp->fVec7[l25] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l26;
		for (l26 = 0; l26 < 4096; l26 = l26 + 1) {
			dsp->fVec8[l26] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l27;
		for (l27 = 0; l27 < 2; l27 = l27 + 1) {
			dsp->fRec22[l27] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l28;
		for (l28 = 0; l28 < 2; l28 = l28 + 1) {
			dsp->fRec23[l28] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l29;
		for (l29 = 0; l29 < 2; l29 = l29 + 1) {
			dsp->fVec9[l29] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l30;
		for (l30 = 0; l30 < 2; l30 = l30 + 1) {
			dsp->fRec24[l30] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l31;
		for (l31 = 0; l31 < 2; l31 = l31 + 1) {
			dsp->fRec25[l31] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l32;
		for (l32 = 0; l32 < 2; l32 = l32 + 1) {
			dsp->fRec1[l32] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l33;
		for (l33 = 0; l33 < 2; l33 = l33 + 1) {
			dsp->fRec3[l33] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l34;
		for (l34 = 0; l34 < 2; l34 = l34 + 1) {
			dsp->fRec4[l34] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l35;
		for (l35 = 0; l35 < 2; l35 = l35 + 1) {
			dsp->fRec26[l35] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l36;
		for (l36 = 0; l36 < 2; l36 = l36 + 1) {
			dsp->fRec27[l36] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l37;
		for (l37 = 0; l37 < 2; l37 = l37 + 1) {
			dsp->fRec28[l37] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l38;
		for (l38 = 0; l38 < 2; l38 = l38 + 1) {
			dsp->fRec29[l38] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l39;
		for (l39 = 0; l39 < 2; l39 = l39 + 1) {
			dsp->fRec32[l39] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l40;
		for (l40 = 0; l40 < 2; l40 = l40 + 1) {
			dsp->fRec33[l40] = 0.0f;
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
	dsp->fConst8 = expf(-(1e+01f / dsp->fConst0));
	dsp->fConst9 = 1.0f - dsp->fConst8;
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "midi", "1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "mod", "16");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "attack", &dsp->fHslider10, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "midi", "2");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "mod", "14");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoff", &dsp->fHslider2, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "midi", "24");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "mod", "19");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "decay", &dsp->fHslider9, (FAUSTFLOAT)0.01f, (FAUSTFLOAT)0.01f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider27, "midi", "7");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider27, "mod", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "detune", &dsp->fHslider27, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "midi", "22");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "mod", "20");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-osc", &dsp->fHslider19, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider23, "midi", "23");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider23, "mod", "24");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-pwm", &dsp->fHslider23, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider32, "midi", "20");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider32, "mod", "15");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vca", &dsp->fHslider32, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "midi", "21");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "mod", "18");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vcf", &dsp->fHslider6, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph1, "env", "0");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "env", &dsp->fVbargraph1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fButton0, "gate", "");
	ui_interface->addButton(ui_interface->uiInterface, "gate", &dsp->fButton0);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "alt", "23");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "midi", "30");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "glide", &dsp->fHslider17, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.99f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "midi", "15");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "sel", "13");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "hp-lp-bp", &dsp->fHslider1, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "midi", "3");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "mod", "12");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-freq", &dsp->fHslider5, (FAUSTFLOAT)0.3f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "midi", "14");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "sel", "9");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-env", &dsp->fHslider7, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "midi", "16");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "mod", "10");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-osc", &dsp->fHslider18, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider25, "midi", "19");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider25, "mod", "6");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-pwm", &dsp->fHslider25, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider33, "midi", "17");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider33, "mod", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vca", &dsp->fHslider33, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "midi", "18");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "mod", "11");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vcf", &dsp->fHslider3, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "midi", "13");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "sel", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-wavform", &dsp->fHslider4, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph0, "lfo", "0");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "lfo", &dsp->fVbargraph0, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "midi", "4");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "mod", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "mix", &dsp->fHslider13, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider30, "alt", "5");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider30, "midi", "29");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "noise-vol", &dsp->fHslider30, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider24, "alt", "0");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider24, "midi", "26");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-1-pw", &dsp->fHslider24, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider29, "alt", "3");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider29, "midi", "27");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-2-pw", &dsp->fHslider29, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "midi", "10");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "sel", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-oct", &dsp->fHslider15, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "midi", "9");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "sel", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-wavform", &dsp->fHslider14, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider28, "midi", "11");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider28, "sel", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-oct", &dsp->fHslider28, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider26, "midi", "12");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider26, "sel", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-wavform", &dsp->fHslider26, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider21, "asb", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend_dn", &dsp->fHslider21, (FAUSTFLOAT)12.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)24.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "asb", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend_up", &dsp->fHslider22, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)24.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "pitch-bend", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch-bend", &dsp->fHslider20, (FAUSTFLOAT)8192.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)16383.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "pitch", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch", &dsp->fHslider16, (FAUSTFLOAT)4e+01f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)127.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "midi", "5");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "mod", "25");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "release", &dsp->fHslider11, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "midi", "6");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "mod", "17");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "resonance", &dsp->fHslider12, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "midi", "25");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "mod", "21");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "sustain", &dsp->fHslider8, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph2, "vca", "0");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "vca", &dsp->fVbargraph2, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "midi", "8");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "mod", "23");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "volume", &dsp->fHslider0, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider31, "alt", "4");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider31, "midi", "28");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "xor-vol", &dsp->fHslider31, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	float fSlow0 = 0.9f * (float)(dsp->fHslider0);
	float fSlow1 = (float)(dsp->fHslider1);
	int iSlow2 = fSlow1 >= 2.0f;
	int iSlow3 = fSlow1 >= 1.0f;
	float fSlow4 = dsp->fConst3 * mydsp_faustpower2_f((float)(dsp->fHslider2));
	float fSlow5 = (float)(dsp->fHslider3);
	float fSlow6 = (float)(dsp->fHslider4);
	int iSlow7 = fSlow6 >= 2.0f;
	int iSlow8 = fSlow6 >= 1.0f;
	float fSlow9 = dsp->fConst4 * (19.99f * mydsp_faustpower2_f((float)(dsp->fHslider5)) + 0.01f);
	float fSlow10 = 2.1666667f * (float)(dsp->fHslider6);
	int iSlow11 = (float)(dsp->fHslider7) >= 1.0f;
	float fSlow12 = (float)(dsp->fButton0);
	float fSlow13 = (float)(dsp->fHslider8);
	float fSlow14 = (fSlow13 + -1.0f) / fmaxf(1.0f, dsp->fConst0 * (float)(dsp->fHslider9));
	float fSlow15 = 1.0f / fmaxf(1.0f, dsp->fConst0 * (19.999f * mydsp_faustpower3_f((float)(dsp->fHslider10)) + 0.001f));
	float fSlow16 = 1.0f / fmaxf(1.0f, dsp->fConst0 * (19.999f * mydsp_faustpower2_f((float)(dsp->fHslider11)) + 0.001f));
	float fSlow17 = (float)(dsp->fHslider12);
	float fSlow18 = 24.293f * fSlow17 + 0.707f;
	float fSlow19 = 0.21521576f * (0.33333334f * fSlow18 + -0.707f);
	float fSlow20 = 0.9f * (float)(dsp->fHslider13);
	float fSlow21 = (float)(dsp->fHslider14);
	int iSlow22 = fSlow21 >= 2.0f;
	int iSlow23 = fSlow21 >= 1.0f;
	float fSlow24 = (float)(dsp->fHslider15);
	int iSlow25 = fSlow24 >= 2.0f;
	int iSlow26 = fSlow24 >= 1.0f;
	float fSlow27 = 4.4e+02f * powf(2.0f, 0.083333336f * ((float)(dsp->fHslider16) + -69.0f));
	float fSlow28 = (float)(dsp->fHslider17);
	int iSlow29 = fabsf(fSlow28) < 1.1920929e-07f;
	float fSlow30 = ((iSlow29) ? 0.0f : expf(-(dsp->fConst4 / ((iSlow29) ? 1.0f : fSlow28))));
	float fSlow31 = 1.0f - fSlow30;
	float fSlow32 = (float)(dsp->fHslider18);
	float fSlow33 = 0.083333336f * (float)(dsp->fHslider19);
	float fSlow34 = 0.00012207031f * (float)(dsp->fHslider20) + -1.0f;
	float fSlow35 = dsp->fConst6 * powf(2.0f, 0.083333336f * ((fSlow34 > 0.0f) ? (float)(dsp->fHslider22) * fSlow34 : (float)(dsp->fHslider21) * fSlow34));
	float fSlow36 = dsp->fConst0 * (1.0f - (float)(dsp->fHslider23));
	float fSlow37 = dsp->fConst9 * (float)(dsp->fHslider24);
	float fSlow38 = (float)(dsp->fHslider25);
	float fSlow39 = (float)(dsp->fHslider26);
	int iSlow40 = fSlow39 >= 2.0f;
	int iSlow41 = fSlow39 >= 1.0f;
	float fSlow42 = 0.9f * powf(2.0f, mydsp_faustpower2_f((float)(dsp->fHslider27)));
	float fSlow43 = (float)(dsp->fHslider28);
	int iSlow44 = fSlow43 >= 2.0f;
	int iSlow45 = fSlow43 >= 1.0f;
	float fSlow46 = dsp->fConst9 * (float)(dsp->fHslider29);
	float fSlow47 = 0.9f * (float)(dsp->fHslider30);
	float fSlow48 = 0.9f * (float)(dsp->fHslider31);
	float fSlow49 = 4.0f * fSlow17;
	float fSlow50 = 1.0f / fSlow18;
	float fSlow51 = (float)(dsp->fHslider32);
	float fSlow52 = (float)(dsp->fHslider33);
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec0[0] = 1;
			dsp->fRec0[0] = fSlow0 + 0.1f * dsp->fRec0[1];
			dsp->fRec5[0] = fSlow4 + dsp->fConst2 * dsp->fRec5[1];
			int iTemp0 = 1 - dsp->iVec0[1];
			float fTemp1 = ((iTemp0) ? 0.0f : fSlow9 + dsp->fRec6[1]);
			dsp->fRec6[0] = fTemp1 - floorf(fTemp1);
			float fTemp2 = (float)(dsp->fRec6[0] <= 0.5f);
			dsp->fVec1[0] = fTemp2;
			int iTemp3 = (dsp->fVec1[1] <= 0.0f) & (fTemp2 > 0.0f);
			dsp->iRec8[0] = 1103515245 * dsp->iRec8[1] + 12345;
			float fTemp4 = (float)(dsp->iRec8[0]);
			dsp->fRec7[0] = dsp->fRec7[1] * (float)(1 - iTemp3) + 4.656613e-10f * fTemp4 * (float)(iTemp3);
			float fTemp5 = ((iSlow7) ? dsp->fRec7[0] : ((iSlow8) ? fTemp2 : 2.0f * (1.0f - fabsf(2.0f * dsp->fRec6[0] + -1.0f)) + -1.0f));
			dsp->fVbargraph0 = (FAUSTFLOAT)(fTemp5);
			float fTemp6 = fTemp5;
			float fTemp7 = fTemp6 + -0.5f;
			float fTemp8 = ((iSlow11) ? fTemp2 : fSlow12);
			int iTemp9 = dsp->iRec9[1] == 0;
			int iTemp10 = dsp->iRec9[1] == 1;
			dsp->iRec11[0] = dsp->iRec11[1] + 1;
			int iTemp11 = (dsp->iRec11[0] + -1) == 0;
			float fTemp12 = ((iTemp11) ? 0.0f : dsp->fRec10[1]);
			dsp->iRec9[0] = ((fTemp8 > 0.0f) ? ((iTemp9) ? 1 : ((iTemp10) ? ((fTemp12 < 1.0f) ? 1 : 2) : 2)) : 0);
			float fTemp13 = ((dsp->iRec9[1] == 2) ? fSlow13 : 0.0f);
			int iTemp14 = fTemp8 == 0.0f;
			dsp->iVec2[0] = iTemp14;
			int iTemp15 = (dsp->iVec2[1] <= 0) & (iTemp14 > 0);
			dsp->fRec12[0] = dsp->fRec12[1] * (float)(1 - iTemp15) + ((iTemp11) ? 1.0f : fTemp12) * (float)(iTemp15);
			float fTemp16 = ((iTemp9) ? dsp->fRec12[0] : 1.0f);
			float fTemp17 = ((fTemp13 == fTemp16) ? 0.5f : (fTemp12 - fTemp13) / (fTemp16 - fTemp13));
			dsp->fRec10[0] = fmaxf(fTemp13, fminf(1.0f, fTemp12 + 0.25f * (((iTemp9) ? -(fSlow16 * dsp->fRec12[0]) : ((iTemp10) ? fSlow15 : fSlow14)) / mydsp_faustpower2_f(0.5f * (2.0f * fTemp17 + -1.0f) + (1.0f - fTemp17)))));
			dsp->fVbargraph1 = (FAUSTFLOAT)(dsp->fRec10[0]);
			float fTemp18 = dsp->fRec10[0];
			float fTemp19 = fminf(fmaxf(0.0f, dsp->fRec5[0] * powf(2.0f, fSlow5 * fTemp7) * powf(2.0f, fSlow10 * fTemp18)), 1.0f);
			float fTemp20 = tanf(dsp->fConst1 * powf(1e+01f, 3.0f * fTemp19 + 1.0f));
			dsp->fRec13[0] = fSlow20 + 0.1f * dsp->fRec13[1];
			float fTemp21 = (float)(dsp->iVec0[1]);
			dsp->fRec16[0] = fSlow27 * fSlow31 * powf(2.0f, fSlow32 * fTemp7) * powf(2.0f, fSlow33 * fTemp18) + fSlow30 * dsp->fRec16[1];
			dsp->fRec17[0] = fSlow35 + dsp->fConst7 * dsp->fRec17[1];
			dsp->fRec15[0] = 0.9f * dsp->fRec16[0] * dsp->fRec17[0] + 0.1f * dsp->fRec15[1];
			float fTemp22 = 0.5f * dsp->fRec15[0];
			float fTemp23 = 0.25f * dsp->fRec15[0];
			float fTemp24 = ((iSlow25) ? fTemp23 : ((iSlow26) ? fTemp22 : dsp->fRec15[0]));
			float fTemp25 = fmaxf(fTemp24, 23.44895f);
			float fTemp26 = fmaxf(2e+01f, fabsf(fTemp25));
			float fTemp27 = ((iTemp0) ? 0.0f : dsp->fRec14[1] + dsp->fConst4 * fTemp26);
			dsp->fRec14[0] = fTemp27 - floorf(fTemp27);
			float fTemp28 = mydsp_faustpower2_f(2.0f * dsp->fRec14[0] + -1.0f);
			dsp->fVec3[0] = fTemp28;
			float fTemp29 = fTemp21 * (fTemp28 - dsp->fVec3[1]) / fTemp26;
			dsp->fVec4[dsp->IOTA0 & 4095] = fTemp29;
			dsp->fRec18[0] = fSlow37 + dsp->fConst8 * dsp->fRec18[1];
			float fTemp30 = dsp->fRec18[0] * (1.0f - fSlow38 * fTemp6);
			float fTemp31 = fmaxf(0.0f, fminf(2047.0f, fSlow36 * (fTemp30 / fTemp25)));
			int iTemp32 = (int)(fTemp31);
			float fTemp33 = floorf(fTemp31);
			float fTemp34 = fTemp29 - dsp->fVec4[(dsp->IOTA0 - iTemp32) & 4095] * (fTemp33 + (1.0f - fTemp31)) - (fTemp31 - fTemp33) * dsp->fVec4[(dsp->IOTA0 - (iTemp32 + 1)) & 4095];
			float fTemp35 = dsp->fConst5 * fTemp34;
			float fTemp36 = fmaxf(2e+01f, fabsf(fTemp24));
			float fTemp37 = ((iTemp0) ? 0.0f : dsp->fRec19[1] + dsp->fConst4 * fTemp36);
			dsp->fRec19[0] = fTemp37 - floorf(fTemp37);
			float fTemp38 = mydsp_faustpower2_f(2.0f * dsp->fRec19[0] + -1.0f);
			dsp->fVec5[0] = fTemp38;
			dsp->fVec6[dsp->IOTA0 & 8191] = fTemp21 * (fTemp38 - dsp->fVec5[1]) / fTemp36;
			float fTemp39 = dsp->fVec6[(dsp->IOTA0 - max(0, min(8191, (int)(fSlow36 * (fTemp30 / fTemp24) + 0.5f)))) & 8191];
			dsp->fRec21[0] = fSlow42 + 0.1f * dsp->fRec21[1];
			float fTemp40 = dsp->fRec21[0] * ((iSlow44) ? fTemp23 : ((iSlow45) ? fTemp22 : dsp->fRec15[0]));
			float fTemp41 = fmaxf(fTemp40, 23.44895f);
			float fTemp42 = fmaxf(2e+01f, fabsf(fTemp41));
			float fTemp43 = ((iTemp0) ? 0.0f : dsp->fRec20[1] + dsp->fConst4 * fTemp42);
			dsp->fRec20[0] = fTemp43 - floorf(fTemp43);
			float fTemp44 = mydsp_faustpower2_f(2.0f * dsp->fRec20[0] + -1.0f);
			dsp->fVec7[0] = fTemp44;
			float fTemp45 = fTemp21 * (fTemp44 - dsp->fVec7[1]) / fTemp42;
			dsp->fVec8[dsp->IOTA0 & 4095] = fTemp45;
			dsp->fRec22[0] = fSlow46 + dsp->fConst8 * dsp->fRec22[1];
			float fTemp46 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst0 * (dsp->fRec22[0] / fTemp41)));
			int iTemp47 = (int)(fTemp46);
			float fTemp48 = floorf(fTemp46);
			float fTemp49 = fTemp45 - dsp->fVec8[(dsp->IOTA0 - iTemp47) & 4095] * (fTemp48 + (1.0f - fTemp46)) - (fTemp46 - fTemp48) * dsp->fVec8[(dsp->IOTA0 - (iTemp47 + 1)) & 4095];
			float fTemp50 = dsp->fConst5 * fTemp49;
			float fTemp51 = fmaxf(2e+01f, fabsf(fTemp40));
			float fTemp52 = ((iTemp0) ? 0.0f : dsp->fRec23[1] + dsp->fConst4 * fTemp51);
			dsp->fRec23[0] = fTemp52 - floorf(fTemp52);
			float fTemp53 = mydsp_faustpower2_f(2.0f * dsp->fRec23[0] + -1.0f);
			dsp->fVec9[0] = fTemp53;
			float fTemp54 = fTemp21 * (fTemp53 - dsp->fVec9[1]) / fTemp51;
			dsp->fRec24[0] = fSlow47 + 0.1f * dsp->fRec24[1];
			dsp->fRec25[0] = fSlow48 + 0.1f * dsp->fRec25[1];
			float fTemp55 = dsp->fRec13[0] * ((iSlow22) ? dsp->fConst5 * (fTemp34 + fTemp39) : ((iSlow23) ? dsp->fConst5 * fTemp39 : fTemp35)) + (1.0f - dsp->fRec13[0]) * ((iSlow40) ? dsp->fConst5 * (fTemp49 + fTemp54) : ((iSlow41) ? dsp->fConst5 * fTemp54 : fTemp50)) + 4.656613e-10f * dsp->fRec24[0] * fTemp4 + dsp->fRec25[0] * (float)((int)(fTemp35) ^ (int)(fTemp50));
			float fTemp56 = (fTemp55 - dsp->fRec4[1]) * fTemp20;
			float fTemp57 = fTemp20 + 1.0f;
			float fTemp58 = (fTemp55 - (dsp->fRec4[1] + (fTemp56 - dsp->fRec1[1] + fTemp20 * dsp->fRec3[1] / fTemp57) / fTemp57)) / (1.0f - fSlow19 * (fTemp20 * (1.0f - fTemp20 / fTemp57) / fTemp57));
			float fTemp59 = fSlow19 * fTemp58;
			float fTemp60 = fTemp20 * (fTemp59 - dsp->fRec3[1]) / fTemp57;
			dsp->fRec1[0] = dsp->fRec1[1] + 2.0f * (fTemp20 * (fTemp59 - (fTemp60 + dsp->fRec1[1] + dsp->fRec3[1])) / fTemp57);
			float fRec2 = fTemp58;
			dsp->fRec3[0] = dsp->fRec3[1] + 2.0f * fTemp60;
			dsp->fRec4[0] = dsp->fRec4[1] + 2.0f * (fTemp56 / fTemp57);
			float fTemp61 = tanf(1.5707964f * fminf(fmaxf(0.0f, 0.0022727272f * dsp->fRec15[0] * fTemp19), 1.0f));
			float fTemp62 = fTemp61 + 1.0f;
			float fTemp63 = fTemp61 * ((fTemp55 - fSlow49 * (1.0f - fTemp61 / fTemp62) * (dsp->fRec29[1] + fTemp61 * (dsp->fRec28[1] + fTemp61 * (dsp->fRec27[1] + fTemp61 * dsp->fRec26[1] / fTemp62) / fTemp62) / fTemp62)) / (fSlow49 * (mydsp_faustpower4_f(fTemp61) / mydsp_faustpower4_f(fTemp62)) + 1.0f) - dsp->fRec26[1]) / fTemp62;
			dsp->fRec26[0] = dsp->fRec26[1] + 2.0f * fTemp63;
			float fTemp64 = fTemp61 * (dsp->fRec26[1] + fTemp63 - dsp->fRec27[1]) / fTemp62;
			dsp->fRec27[0] = dsp->fRec27[1] + 2.0f * fTemp64;
			float fTemp65 = fTemp61 * (dsp->fRec27[1] + fTemp64 - dsp->fRec28[1]) / fTemp62;
			dsp->fRec28[0] = dsp->fRec28[1] + 2.0f * fTemp65;
			float fTemp66 = fTemp61 * (dsp->fRec28[1] + fTemp65 - dsp->fRec29[1]) / fTemp62;
			dsp->fRec29[0] = dsp->fRec29[1] + 2.0f * fTemp66;
			float fRec30 = dsp->fRec29[1] + fTemp66;
			float fTemp67 = fSlow50 + fTemp20;
			float fTemp68 = fTemp55 - (dsp->fRec32[1] + dsp->fRec33[1] * fTemp67);
			float fTemp69 = fTemp20 * fTemp67 + 1.0f;
			float fTemp70 = fTemp20 * fTemp68 / fTemp69;
			float fTemp71 = fmaxf(-1.0f, fminf(1.0f, dsp->fRec33[1] + fTemp70));
			float fTemp72 = 1.0f - 0.33333334f * mydsp_faustpower2_f(fTemp71);
			float fTemp73 = fTemp71 * fTemp72;
			float fRec31 = fTemp73;
			float fTemp74 = fTemp20 * fTemp71 * fTemp72;
			dsp->fRec32[0] = dsp->fRec32[1] + 2.0f * fTemp74;
			dsp->fRec33[0] = fTemp70 + fTemp73;
			float fTemp75 = fSlow51 * fTemp18 * (fSlow52 * fTemp6 + 1.0f);
			dsp->fVbargraph2 = (FAUSTFLOAT)(fTemp75);
			output0[i0] = (FAUSTFLOAT)(dsp->fRec0[0] * ((iSlow2) ? fRec31 : ((iSlow3) ? fRec30 : fRec2)) * fTemp75);
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fVec1[1] = dsp->fVec1[0];
			dsp->iRec8[1] = dsp->iRec8[0];
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->iRec11[1] = dsp->iRec11[0];
			dsp->iRec9[1] = dsp->iRec9[0];
			dsp->iVec2[1] = dsp->iVec2[0];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fRec16[1] = dsp->fRec16[0];
			dsp->fRec17[1] = dsp->fRec17[0];
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec18[1] = dsp->fRec18[0];
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec21[1] = dsp->fRec21[0];
			dsp->fRec20[1] = dsp->fRec20[0];
			dsp->fVec7[1] = dsp->fVec7[0];
			dsp->fRec22[1] = dsp->fRec22[0];
			dsp->fRec23[1] = dsp->fRec23[0];
			dsp->fVec9[1] = dsp->fVec9[0];
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fRec25[1] = dsp->fRec25[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->fRec3[1] = dsp->fRec3[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->fRec26[1] = dsp->fRec26[0];
			dsp->fRec27[1] = dsp->fRec27[0];
			dsp->fRec28[1] = dsp->fRec28[0];
			dsp->fRec29[1] = dsp->fRec29[0];
			dsp->fRec32[1] = dsp->fRec32[0];
			dsp->fRec33[1] = dsp->fRec33[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
