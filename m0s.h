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
	FAUSTFLOAT fButton0;
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider2;
	float fRec1[2];
	float fVec1[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec0[2];
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider5;
	float fRec2[2];
	FAUSTFLOAT fHslider6;
	float fConst2;
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider7;
	float fRec7[2];
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	int iRec9[2];
	float fRec8[2];
	FAUSTFLOAT fVbargraph1;
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fHslider12;
	float fRec10[2];
	FAUSTFLOAT fHslider13;
	float fConst5;
	FAUSTFLOAT fHslider14;
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	float fRec13[2];
	float fConst6;
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fHslider21;
	float fConst7;
	float fRec14[2];
	float fRec12[2];
	float fRec11[2];
	float fVec2[2];
	int IOTA0;
	float fVec3[4096];
	FAUSTFLOAT fHslider22;
	float fRec15[2];
	float fRec16[2];
	float fVec4[2];
	FAUSTFLOAT fHslider23;
	FAUSTFLOAT fHslider24;
	float fRec18[2];
	FAUSTFLOAT fHslider25;
	float fRec17[2];
	float fVec5[2];
	float fVec6[4096];
	FAUSTFLOAT fHslider26;
	float fRec19[2];
	float fRec20[2];
	float fVec7[2];
	FAUSTFLOAT fHslider27;
	float fRec21[2];
	FAUSTFLOAT fHslider28;
	float fRec22[2];
	float fRec3[2];
	float fRec5[2];
	float fRec6[2];
	float fRec23[2];
	float fRec24[2];
	float fRec25[2];
	float fRec26[2];
	float fRec29[2];
	float fRec30[2];
	FAUSTFLOAT fHslider29;
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
	m->declare(m->metaInterface, "envelopes.lib/asre:author", "Julius O. Smith III, revised by Stephane Letz");
	m->declare(m->metaInterface, "envelopes.lib/asre:licence", "STK-4.3");
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
	dsp->fHslider1 = (FAUSTFLOAT)(0.0f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider2 = (FAUSTFLOAT)(0.3f);
	dsp->fHslider3 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider4 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider5 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider6 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider7 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider8 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider9 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider10 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider11 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider12 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider13 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider14 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider15 = (FAUSTFLOAT)(4e+01f);
	dsp->fHslider16 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider17 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider18 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider19 = (FAUSTFLOAT)(8192.0f);
	dsp->fHslider20 = (FAUSTFLOAT)(12.0f);
	dsp->fHslider21 = (FAUSTFLOAT)(2.0f);
	dsp->fHslider22 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider23 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider24 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider25 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider26 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider27 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider28 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider29 = (FAUSTFLOAT)(0.0f);
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
			dsp->fRec1[l1] = 0.0f;
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
			dsp->fRec0[l3] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->fRec2[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->fRec7[l5] = 0.0f;
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
			dsp->fRec8[l7] = 0.0f;
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
			dsp->fRec13[l9] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 2; l10 = l10 + 1) {
			dsp->fRec14[l10] = 0.0f;
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
			dsp->fRec11[l12] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l13;
		for (l13 = 0; l13 < 2; l13 = l13 + 1) {
			dsp->fVec2[l13] = 0.0f;
		}
	}
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l14;
		for (l14 = 0; l14 < 4096; l14 = l14 + 1) {
			dsp->fVec3[l14] = 0.0f;
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
			dsp->fRec16[l16] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l17;
		for (l17 = 0; l17 < 2; l17 = l17 + 1) {
			dsp->fVec4[l17] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l18;
		for (l18 = 0; l18 < 2; l18 = l18 + 1) {
			dsp->fRec18[l18] = 0.0f;
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
			dsp->fVec5[l20] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l21;
		for (l21 = 0; l21 < 4096; l21 = l21 + 1) {
			dsp->fVec6[l21] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l22;
		for (l22 = 0; l22 < 2; l22 = l22 + 1) {
			dsp->fRec19[l22] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l23;
		for (l23 = 0; l23 < 2; l23 = l23 + 1) {
			dsp->fRec20[l23] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l24;
		for (l24 = 0; l24 < 2; l24 = l24 + 1) {
			dsp->fVec7[l24] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l25;
		for (l25 = 0; l25 < 2; l25 = l25 + 1) {
			dsp->fRec21[l25] = 0.0f;
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
			dsp->fRec3[l27] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l28;
		for (l28 = 0; l28 < 2; l28 = l28 + 1) {
			dsp->fRec5[l28] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l29;
		for (l29 = 0; l29 < 2; l29 = l29 + 1) {
			dsp->fRec6[l29] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l30;
		for (l30 = 0; l30 < 2; l30 = l30 + 1) {
			dsp->fRec23[l30] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l31;
		for (l31 = 0; l31 < 2; l31 = l31 + 1) {
			dsp->fRec24[l31] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l32;
		for (l32 = 0; l32 < 2; l32 = l32 + 1) {
			dsp->fRec25[l32] = 0.0f;
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
			dsp->fRec29[l34] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l35;
		for (l35 = 0; l35 < 2; l35 = l35 + 1) {
			dsp->fRec30[l35] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 1.0f / dsp->fConst0;
	dsp->fConst2 = 6.2831855f / dsp->fConst0;
	dsp->fConst3 = expf(-(2e+01f / dsp->fConst0));
	dsp->fConst4 = 1.0f - dsp->fConst3;
	dsp->fConst5 = 0.25f * dsp->fConst0;
	dsp->fConst6 = 44.1f / dsp->fConst0;
	dsp->fConst7 = 1.0f - dsp->fConst6;
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "midi", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "attack", &dsp->fHslider4, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "midi", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoff", &dsp->fHslider7, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider24, "midi", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "detune", &dsp->fHslider24, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "mod", "20");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-osc", &dsp->fHslider18, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "mod", "15");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vca", &dsp->fHslider0, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "mod", "18");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vcf", &dsp->fHslider10, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph0, "env", "0");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "env", &dsp->fVbargraph0, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fButton0, "gate", "");
	ui_interface->addButton(ui_interface->uiInterface, "gate", &dsp->fButton0);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "alt", "23");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "glide", &dsp->fHslider16, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.99f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "sel", "13");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "hp-lp-bp", &dsp->fHslider6, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "midi", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-freq", &dsp->fHslider2, (FAUSTFLOAT)0.3f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "sel", "9");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-env", &dsp->fHslider1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "mod", "10");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-osc", &dsp->fHslider17, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider29, "mod", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vca", &dsp->fHslider29, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "mod", "11");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vcf", &dsp->fHslider8, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "sel", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-wavform", &dsp->fHslider9, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph1, "lfo", "0");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "lfo", &dsp->fVbargraph1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "midi", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "mix", &dsp->fHslider12, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider27, "alt", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "noise-vol", &dsp->fHslider27, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "alt", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-1-pw", &dsp->fHslider22, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider26, "alt", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-2-pw", &dsp->fHslider26, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "sel", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-oct", &dsp->fHslider14, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "sel", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-wavform", &dsp->fHslider13, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider25, "sel", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-oct", &dsp->fHslider25, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider23, "sel", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-wavform", &dsp->fHslider23, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "asb", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend_dn", &dsp->fHslider20, (FAUSTFLOAT)12.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)24.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider21, "asb", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend_up", &dsp->fHslider21, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)24.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "pitch-bend", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch-bend", &dsp->fHslider19, (FAUSTFLOAT)8192.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)16383.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "pitch", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch", &dsp->fHslider15, (FAUSTFLOAT)4e+01f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)127.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "midi", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "release", &dsp->fHslider3, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "midi", "6");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "resonance", &dsp->fHslider11, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "midi", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "volume", &dsp->fHslider5, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider28, "alt", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "xor-vol", &dsp->fHslider28, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	float fSlow0 = (float)(dsp->fHslider0);
	int iSlow1 = (float)(dsp->fHslider1) >= 1.0f;
	float fSlow2 = (float)(dsp->fButton0);
	float fSlow3 = dsp->fConst1 * (19.99f * mydsp_faustpower2_f((float)(dsp->fHslider2)) + 0.01f);
	float fSlow4 = (float)(dsp->fHslider3);
	float fSlow5 = (float)(dsp->fHslider4);
	float fSlow6 = 0.9f * (float)(dsp->fHslider5);
	float fSlow7 = (float)(dsp->fHslider6);
	int iSlow8 = fSlow7 >= 2.0f;
	int iSlow9 = fSlow7 >= 1.0f;
	float fSlow10 = dsp->fConst4 * mydsp_faustpower2_f((float)(dsp->fHslider7));
	float fSlow11 = (float)(dsp->fHslider8);
	float fSlow12 = (float)(dsp->fHslider9);
	int iSlow13 = fSlow12 >= 2.0f;
	int iSlow14 = fSlow12 >= 1.0f;
	float fSlow15 = 2.1666667f * (float)(dsp->fHslider10);
	float fSlow16 = (float)(dsp->fHslider11);
	float fSlow17 = 24.293f * fSlow16 + 0.707f;
	float fSlow18 = 0.21521576f * (0.33333334f * fSlow17 + -0.707f);
	float fSlow19 = 0.9f * (float)(dsp->fHslider12);
	float fSlow20 = (float)(dsp->fHslider13);
	int iSlow21 = fSlow20 >= 2.0f;
	int iSlow22 = fSlow20 >= 1.0f;
	float fSlow23 = (float)(dsp->fHslider14);
	int iSlow24 = fSlow23 >= 2.0f;
	int iSlow25 = fSlow23 >= 1.0f;
	float fSlow26 = 4.4e+02f * powf(2.0f, 0.083333336f * ((float)(dsp->fHslider15) + -69.0f));
	float fSlow27 = (float)(dsp->fHslider16);
	int iSlow28 = fabsf(fSlow27) < 1.1920929e-07f;
	float fSlow29 = ((iSlow28) ? 0.0f : expf(-(dsp->fConst1 / ((iSlow28) ? 1.0f : fSlow27))));
	float fSlow30 = 1.0f - fSlow29;
	float fSlow31 = (float)(dsp->fHslider17);
	float fSlow32 = 0.083333336f * (float)(dsp->fHslider18);
	float fSlow33 = 0.00012207031f * (float)(dsp->fHslider19) + -1.0f;
	float fSlow34 = dsp->fConst6 * powf(2.0f, 0.083333336f * ((fSlow33 > 0.0f) ? (float)(dsp->fHslider21) * fSlow33 : (float)(dsp->fHslider20) * fSlow33));
	float fSlow35 = 0.9f * (float)(dsp->fHslider22);
	float fSlow36 = (float)(dsp->fHslider23);
	int iSlow37 = fSlow36 >= 2.0f;
	int iSlow38 = fSlow36 >= 1.0f;
	float fSlow39 = 0.9f * powf(2.0f, mydsp_faustpower2_f((float)(dsp->fHslider24)));
	float fSlow40 = (float)(dsp->fHslider25);
	int iSlow41 = fSlow40 >= 2.0f;
	int iSlow42 = fSlow40 >= 1.0f;
	float fSlow43 = 0.9f * (float)(dsp->fHslider26);
	float fSlow44 = 0.9f * (float)(dsp->fHslider27);
	float fSlow45 = 0.9f * (float)(dsp->fHslider28);
	float fSlow46 = 4.0f * fSlow16;
	float fSlow47 = 1.0f / fSlow17;
	float fSlow48 = (float)(dsp->fHslider29);
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec0[0] = 1;
			int iTemp0 = 1 - dsp->iVec0[1];
			float fTemp1 = ((iTemp0) ? 0.0f : fSlow3 + dsp->fRec1[1]);
			dsp->fRec1[0] = fTemp1 - floorf(fTemp1);
			float fTemp2 = (float)(dsp->fRec1[0] <= 0.5f);
			dsp->fVec1[0] = fTemp2;
			int iTemp3 = ((iSlow1) ? fTemp2 : fSlow2) > 0.0f;
			float fTemp4 = 0.1447178f * ((iTemp3) ? fSlow5 : fSlow4);
			int iTemp5 = fabsf(fTemp4) < 1.1920929e-07f;
			float fTemp6 = ((iTemp5) ? 0.0f : expf(-(dsp->fConst1 / ((iTemp5) ? 1.0f : fTemp4))));
			dsp->fRec0[0] = (1.0f - fTemp6) * ((iTemp3) ? (float)(iTemp3) : 0.0f) + fTemp6 * dsp->fRec0[1];
			dsp->fVbargraph0 = (FAUSTFLOAT)(dsp->fRec0[0]);
			float fTemp7 = dsp->fRec0[0];
			dsp->fRec2[0] = fSlow6 + 0.1f * dsp->fRec2[1];
			dsp->fRec7[0] = fSlow10 + dsp->fConst3 * dsp->fRec7[1];
			int iTemp8 = (dsp->fVec1[1] <= 0.0f) & (fTemp2 > 0.0f);
			dsp->iRec9[0] = 1103515245 * dsp->iRec9[1] + 12345;
			float fTemp9 = (float)(dsp->iRec9[0]);
			dsp->fRec8[0] = dsp->fRec8[1] * (float)(1 - iTemp8) + 4.656613e-10f * fTemp9 * (float)(iTemp8);
			float fTemp10 = ((iSlow13) ? dsp->fRec8[0] : ((iSlow14) ? fTemp2 : 2.0f * (1.0f - fabsf(2.0f * dsp->fRec1[0] + -1.0f)) + -1.0f));
			dsp->fVbargraph1 = (FAUSTFLOAT)(fTemp10);
			float fTemp11 = fTemp10;
			float fTemp12 = fTemp11 + -0.5f;
			float fTemp13 = fminf(fmaxf(0.0f, dsp->fRec7[0] * powf(2.0f, fSlow11 * fTemp12) * powf(2.0f, fSlow15 * fTemp7)), 1.0f);
			float fTemp14 = tanf(dsp->fConst2 * powf(1e+01f, 3.0f * fTemp13 + 1.0f));
			dsp->fRec10[0] = fSlow19 + 0.1f * dsp->fRec10[1];
			float fTemp15 = (float)(dsp->iVec0[1]);
			dsp->fRec13[0] = fSlow26 * fSlow30 * powf(2.0f, fSlow31 * fTemp12) * powf(2.0f, fSlow32 * fTemp7) + fSlow29 * dsp->fRec13[1];
			dsp->fRec14[0] = fSlow34 + dsp->fConst7 * dsp->fRec14[1];
			dsp->fRec12[0] = 0.9f * dsp->fRec13[0] * dsp->fRec14[0] + 0.1f * dsp->fRec12[1];
			float fTemp16 = 0.5f * dsp->fRec12[0];
			float fTemp17 = 0.25f * dsp->fRec12[0];
			float fTemp18 = ((iSlow24) ? fTemp17 : ((iSlow25) ? fTemp16 : dsp->fRec12[0]));
			float fTemp19 = fmaxf(fTemp18, 23.44895f);
			float fTemp20 = fmaxf(2e+01f, fabsf(fTemp19));
			float fTemp21 = ((iTemp0) ? 0.0f : dsp->fRec11[1] + dsp->fConst1 * fTemp20);
			dsp->fRec11[0] = fTemp21 - floorf(fTemp21);
			float fTemp22 = mydsp_faustpower2_f(2.0f * dsp->fRec11[0] + -1.0f);
			dsp->fVec2[0] = fTemp22;
			float fTemp23 = fTemp15 * (fTemp22 - dsp->fVec2[1]) / fTemp20;
			dsp->fVec3[dsp->IOTA0 & 4095] = fTemp23;
			dsp->fRec15[0] = fSlow35 + 0.1f * dsp->fRec15[1];
			float fTemp24 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst0 * (dsp->fRec15[0] / fTemp19)));
			int iTemp25 = (int)(fTemp24);
			float fTemp26 = floorf(fTemp24);
			float fTemp27 = fTemp23 - dsp->fVec3[(dsp->IOTA0 - iTemp25) & 4095] * (fTemp26 + (1.0f - fTemp24)) - (fTemp24 - fTemp26) * dsp->fVec3[(dsp->IOTA0 - (iTemp25 + 1)) & 4095];
			float fTemp28 = dsp->fConst5 * fTemp27;
			float fTemp29 = fmaxf(2e+01f, fabsf(fTemp18));
			float fTemp30 = ((iTemp0) ? 0.0f : dsp->fRec16[1] + dsp->fConst1 * fTemp29);
			dsp->fRec16[0] = fTemp30 - floorf(fTemp30);
			float fTemp31 = mydsp_faustpower2_f(2.0f * dsp->fRec16[0] + -1.0f);
			dsp->fVec4[0] = fTemp31;
			float fTemp32 = fTemp15 * (fTemp31 - dsp->fVec4[1]) / fTemp29;
			dsp->fRec18[0] = fSlow39 + 0.1f * dsp->fRec18[1];
			float fTemp33 = dsp->fRec18[0] * ((iSlow41) ? fTemp17 : ((iSlow42) ? fTemp16 : dsp->fRec12[0]));
			float fTemp34 = fmaxf(fTemp33, 23.44895f);
			float fTemp35 = fmaxf(2e+01f, fabsf(fTemp34));
			float fTemp36 = ((iTemp0) ? 0.0f : dsp->fRec17[1] + dsp->fConst1 * fTemp35);
			dsp->fRec17[0] = fTemp36 - floorf(fTemp36);
			float fTemp37 = mydsp_faustpower2_f(2.0f * dsp->fRec17[0] + -1.0f);
			dsp->fVec5[0] = fTemp37;
			float fTemp38 = fTemp15 * (fTemp37 - dsp->fVec5[1]) / fTemp35;
			dsp->fVec6[dsp->IOTA0 & 4095] = fTemp38;
			dsp->fRec19[0] = fSlow43 + 0.1f * dsp->fRec19[1];
			float fTemp39 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst0 * (dsp->fRec19[0] / fTemp34)));
			int iTemp40 = (int)(fTemp39);
			float fTemp41 = floorf(fTemp39);
			float fTemp42 = fTemp38 - dsp->fVec6[(dsp->IOTA0 - iTemp40) & 4095] * (fTemp41 + (1.0f - fTemp39)) - (fTemp39 - fTemp41) * dsp->fVec6[(dsp->IOTA0 - (iTemp40 + 1)) & 4095];
			float fTemp43 = dsp->fConst5 * fTemp42;
			float fTemp44 = fmaxf(2e+01f, fabsf(fTemp33));
			float fTemp45 = ((iTemp0) ? 0.0f : dsp->fRec20[1] + dsp->fConst1 * fTemp44);
			dsp->fRec20[0] = fTemp45 - floorf(fTemp45);
			float fTemp46 = mydsp_faustpower2_f(2.0f * dsp->fRec20[0] + -1.0f);
			dsp->fVec7[0] = fTemp46;
			float fTemp47 = fTemp15 * (fTemp46 - dsp->fVec7[1]) / fTemp44;
			dsp->fRec21[0] = fSlow44 + 0.1f * dsp->fRec21[1];
			dsp->fRec22[0] = fSlow45 + 0.1f * dsp->fRec22[1];
			float fTemp48 = dsp->fRec10[0] * ((iSlow21) ? dsp->fConst5 * (fTemp27 + fTemp32) : ((iSlow22) ? dsp->fConst5 * fTemp32 : fTemp28)) + (1.0f - dsp->fRec10[0]) * ((iSlow37) ? dsp->fConst5 * (fTemp42 + fTemp47) : ((iSlow38) ? dsp->fConst5 * fTemp47 : fTemp43)) + 4.656613e-10f * dsp->fRec21[0] * fTemp9 + dsp->fRec22[0] * (float)((int)(fTemp28) ^ (int)(fTemp43));
			float fTemp49 = (fTemp48 - dsp->fRec6[1]) * fTemp14;
			float fTemp50 = fTemp14 + 1.0f;
			float fTemp51 = (fTemp48 - (dsp->fRec6[1] + (fTemp49 - dsp->fRec3[1] + fTemp14 * dsp->fRec5[1] / fTemp50) / fTemp50)) / (1.0f - fSlow18 * (fTemp14 * (1.0f - fTemp14 / fTemp50) / fTemp50));
			float fTemp52 = fSlow18 * fTemp51;
			float fTemp53 = fTemp14 * (fTemp52 - dsp->fRec5[1]) / fTemp50;
			dsp->fRec3[0] = dsp->fRec3[1] + 2.0f * (fTemp14 * (fTemp52 - (dsp->fRec5[1] + dsp->fRec3[1] + fTemp53)) / fTemp50);
			float fRec4 = fTemp51;
			dsp->fRec5[0] = dsp->fRec5[1] + 2.0f * fTemp53;
			dsp->fRec6[0] = dsp->fRec6[1] + 2.0f * (fTemp49 / fTemp50);
			float fTemp54 = tanf(0.0035699916f * dsp->fRec12[0] * fTemp13);
			float fTemp55 = fTemp54 + 1.0f;
			float fTemp56 = fTemp54 * ((fTemp48 - fSlow46 * (1.0f - fTemp54 / fTemp55) * (dsp->fRec26[1] + fTemp54 * (dsp->fRec25[1] + fTemp54 * (dsp->fRec24[1] + fTemp54 * dsp->fRec23[1] / fTemp55) / fTemp55) / fTemp55)) / (fSlow46 * (mydsp_faustpower4_f(fTemp54) / mydsp_faustpower4_f(fTemp55)) + 1.0f) - dsp->fRec23[1]) / fTemp55;
			dsp->fRec23[0] = dsp->fRec23[1] + 2.0f * fTemp56;
			float fTemp57 = fTemp54 * (dsp->fRec23[1] + fTemp56 - dsp->fRec24[1]) / fTemp55;
			dsp->fRec24[0] = dsp->fRec24[1] + 2.0f * fTemp57;
			float fTemp58 = fTemp54 * (dsp->fRec24[1] + fTemp57 - dsp->fRec25[1]) / fTemp55;
			dsp->fRec25[0] = dsp->fRec25[1] + 2.0f * fTemp58;
			float fTemp59 = fTemp54 * (dsp->fRec25[1] + fTemp58 - dsp->fRec26[1]) / fTemp55;
			dsp->fRec26[0] = dsp->fRec26[1] + 2.0f * fTemp59;
			float fRec27 = dsp->fRec26[1] + fTemp59;
			float fTemp60 = fSlow47 + fTemp14;
			float fTemp61 = fTemp48 - (dsp->fRec29[1] + dsp->fRec30[1] * fTemp60);
			float fTemp62 = fTemp14 * fTemp60 + 1.0f;
			float fTemp63 = fTemp14 * fTemp61 / fTemp62;
			float fTemp64 = fmaxf(-1.0f, fminf(1.0f, dsp->fRec30[1] + fTemp63));
			float fTemp65 = 1.0f - 0.33333334f * mydsp_faustpower2_f(fTemp64);
			float fTemp66 = fTemp64 * fTemp65;
			float fRec28 = fTemp66;
			float fTemp67 = fTemp14 * fTemp64 * fTemp65;
			dsp->fRec29[0] = dsp->fRec29[1] + 2.0f * fTemp67;
			dsp->fRec30[0] = fTemp63 + fTemp66;
			output0[i0] = (FAUSTFLOAT)(fSlow0 * fTemp7 * dsp->fRec2[0] * ((iSlow8) ? fRec28 : ((iSlow9) ? fRec27 : fRec4)) * (fSlow48 * fTemp11 + 1.0f));
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->fVec1[1] = dsp->fVec1[0];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->iRec9[1] = dsp->iRec9[0];
			dsp->fRec8[1] = dsp->fRec8[0];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->fRec11[1] = dsp->fRec11[0];
			dsp->fVec2[1] = dsp->fVec2[0];
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fRec16[1] = dsp->fRec16[0];
			dsp->fVec4[1] = dsp->fVec4[0];
			dsp->fRec18[1] = dsp->fRec18[0];
			dsp->fRec17[1] = dsp->fRec17[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fRec20[1] = dsp->fRec20[0];
			dsp->fVec7[1] = dsp->fVec7[0];
			dsp->fRec21[1] = dsp->fRec21[0];
			dsp->fRec22[1] = dsp->fRec22[0];
			dsp->fRec3[1] = dsp->fRec3[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fRec23[1] = dsp->fRec23[0];
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fRec25[1] = dsp->fRec25[0];
			dsp->fRec26[1] = dsp->fRec26[0];
			dsp->fRec29[1] = dsp->fRec29[0];
			dsp->fRec30[1] = dsp->fRec30[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
