/* ------------------------------------------------------------
name: "m0ss"
Code generated with Faust 2.59.9 (https://faust.grame.fr)
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
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fConst2;
	int iVec0[2];
	float fRec0[2];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fButton0;
	float fConst3;
	FAUSTFLOAT fHslider4;
	float fRec2[2];
	float fVec1[2];
	float fVec2[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	float fRec1[2];
	int iRec3[2];
	float fConst4;
	float fConst5;
	float fRec4[2];
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider7;
	float fConst6;
	float fConst7;
	float fConst8;
	FAUSTFLOAT fHslider8;
	float fRec9[2];
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	int iRec11[2];
	float fRec10[2];
	FAUSTFLOAT fVbargraph1;
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fHslider12;
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	float fConst9;
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fHslider19;
	float fRec13[2];
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fHslider21;
	FAUSTFLOAT fHslider22;
	float fRec14[2];
	float fRec12[2];
	float fVec3[2];
	int IOTA0;
	float fVec4[4096];
	FAUSTFLOAT fHslider23;
	float fRec15[2];
	float fRec16[2];
	float fVec5[2];
	FAUSTFLOAT fHslider24;
	FAUSTFLOAT fHslider25;
	FAUSTFLOAT fHslider26;
	float fRec17[2];
	float fVec6[2];
	float fVec7[4096];
	FAUSTFLOAT fHslider27;
	float fRec18[2];
	float fRec19[2];
	float fVec8[2];
	FAUSTFLOAT fHslider28;
	float fRec20[2];
	FAUSTFLOAT fHslider29;
	float fRec21[2];
	float fRec5[2];
	float fRec6[2];
	float fRec7[2];
	float fRec22[2];
	float fRec23[2];
	float fRec24[2];
	float fRec25[2];
	float fRec28[2];
	float fRec29[2];
	FAUSTFLOAT fHslider30;
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
	m->declare(m->metaInterface, "basics.lib/version", "0.10");
	m->declare(m->metaInterface, "compile_options", "-lang c -ct 1 -es 1 -mcd 16 -single -ftz 0");
	m->declare(m->metaInterface, "envelopes.lib/asre:author", "Julius O. Smith III, revised by Stephane Letz");
	m->declare(m->metaInterface, "envelopes.lib/asre:licence", "STK-4.3");
	m->declare(m->metaInterface, "envelopes.lib/author", "GRAME");
	m->declare(m->metaInterface, "envelopes.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "envelopes.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "envelopes.lib/name", "Faust Envelope Library");
	m->declare(m->metaInterface, "envelopes.lib/version", "0.2");
	m->declare(m->metaInterface, "filename", "m0ss.dsp");
	m->declare(m->metaInterface, "interpolators.lib/name", "Faust Interpolator Library");
	m->declare(m->metaInterface, "interpolators.lib/remap:author", "David Braun");
	m->declare(m->metaInterface, "interpolators.lib/version", "0.3");
	m->declare(m->metaInterface, "maths.lib/author", "GRAME");
	m->declare(m->metaInterface, "maths.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "maths.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "maths.lib/name", "Faust Math Library");
	m->declare(m->metaInterface, "maths.lib/version", "2.6");
	m->declare(m->metaInterface, "misceffects.lib/name", "Misc Effects Library");
	m->declare(m->metaInterface, "misceffects.lib/version", "2.1");
	m->declare(m->metaInterface, "name", "m0ss");
	m->declare(m->metaInterface, "noises.lib/name", "Faust Noise Generator Library");
	m->declare(m->metaInterface, "noises.lib/version", "0.4");
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
	m->declare(m->metaInterface, "oscillators.lib/version", "0.4");
	m->declare(m->metaInterface, "platform.lib/name", "Generic Platform Library");
	m->declare(m->metaInterface, "platform.lib/version", "0.3");
	m->declare(m->metaInterface, "signals.lib/name", "Faust Signal Routing Library");
	m->declare(m->metaInterface, "signals.lib/version", "0.3");
	m->declare(m->metaInterface, "vaeffects.lib/korg35HPF:author", "Eric Tarr");
	m->declare(m->metaInterface, "vaeffects.lib/korg35HPF:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "vaeffects.lib/moogLadder:author", "Dario Sanfilippo");
	m->declare(m->metaInterface, "vaeffects.lib/moogLadder:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
	m->declare(m->metaInterface, "vaeffects.lib/oberheim:author", "Eric Tarr");
	m->declare(m->metaInterface, "vaeffects.lib/oberheim:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "vaeffects.lib/oberheimBPF:author", "Eric Tarr");
	m->declare(m->metaInterface, "vaeffects.lib/oberheimBPF:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "vaeffects.lib/version", "0.2");
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
	dsp->fHslider2 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider3 = (FAUSTFLOAT)(0.0f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider4 = (FAUSTFLOAT)(0.3f);
	dsp->fHslider5 = (FAUSTFLOAT)(0.01f);
	dsp->fHslider6 = (FAUSTFLOAT)(0.01f);
	dsp->fHslider7 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider8 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider9 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider10 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider11 = (FAUSTFLOAT)(0.0f);
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
	dsp->fHslider23 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider24 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider25 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider26 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider27 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider28 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider29 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider30 = (FAUSTFLOAT)(0.0f);
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
			dsp->fRec2[l2] = 0.0f;
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
			dsp->fVec2[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->fRec1[l5] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->iRec3[l6] = 0;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 2; l7 = l7 + 1) {
			dsp->fRec4[l7] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 2; l8 = l8 + 1) {
			dsp->fRec9[l8] = 0.0f;
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
			dsp->fRec10[l10] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 2; l11 = l11 + 1) {
			dsp->fRec13[l11] = 0.0f;
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
			dsp->fRec12[l13] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l14;
		for (l14 = 0; l14 < 2; l14 = l14 + 1) {
			dsp->fVec3[l14] = 0.0f;
		}
	}
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l15;
		for (l15 = 0; l15 < 4096; l15 = l15 + 1) {
			dsp->fVec4[l15] = 0.0f;
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
			dsp->fRec16[l17] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l18;
		for (l18 = 0; l18 < 2; l18 = l18 + 1) {
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
			dsp->fVec6[l20] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l21;
		for (l21 = 0; l21 < 4096; l21 = l21 + 1) {
			dsp->fVec7[l21] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l22;
		for (l22 = 0; l22 < 2; l22 = l22 + 1) {
			dsp->fRec18[l22] = 0.0f;
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
		for (l25 = 0; l25 < 2; l25 = l25 + 1) {
			dsp->fRec20[l25] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l26;
		for (l26 = 0; l26 < 2; l26 = l26 + 1) {
			dsp->fRec21[l26] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l27;
		for (l27 = 0; l27 < 2; l27 = l27 + 1) {
			dsp->fRec5[l27] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l28;
		for (l28 = 0; l28 < 2; l28 = l28 + 1) {
			dsp->fRec6[l28] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l29;
		for (l29 = 0; l29 < 2; l29 = l29 + 1) {
			dsp->fRec7[l29] = 0.0f;
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
			dsp->fRec24[l32] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l33;
		for (l33 = 0; l33 < 2; l33 = l33 + 1) {
			dsp->fRec25[l33] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l34;
		for (l34 = 0; l34 < 2; l34 = l34 + 1) {
			dsp->fRec28[l34] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l35;
		for (l35 = 0; l35 < 2; l35 = l35 + 1) {
			dsp->fRec29[l35] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 44.1f / dsp->fConst0;
	dsp->fConst2 = 1.0f - dsp->fConst1;
	dsp->fConst3 = 1.0f / dsp->fConst0;
	dsp->fConst4 = 1e+01f * dsp->fConst0;
	dsp->fConst5 = 0.6907755f / dsp->fConst0;
	dsp->fConst6 = 6.2831855f / dsp->fConst0;
	dsp->fConst7 = expf(0.0f - 2e+01f / dsp->fConst0);
	dsp->fConst8 = 1.0f - dsp->fConst7;
	dsp->fConst9 = 0.25f * dsp->fConst0;
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "midi", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "attack", &dsp->fHslider6, (FAUSTFLOAT)0.01f, (FAUSTFLOAT)0.01f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "midi", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoff", &dsp->fHslider8, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider25, "midi", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "detune", &dsp->fHslider25, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "mod", "13");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-osc", &dsp->fHslider19, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "mod", "10");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vca", &dsp->fHslider0, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "mod", "12");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vcf", &dsp->fHslider11, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "sel", "11");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-type", &dsp->fHslider2, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph0, "env", "0");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "env", &dsp->fVbargraph0, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fButton0, "gate", "");
	ui_interface->addButton(ui_interface->uiInterface, "gate", &dsp->fButton0);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "alt", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "glide", &dsp->fHslider17, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.99f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "sel", "9");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "hp-lp-bp", &dsp->fHslider7, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "midi", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-freq", &dsp->fHslider4, (FAUSTFLOAT)0.3f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "sel", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-env", &dsp->fHslider3, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "mod", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-osc", &dsp->fHslider18, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider30, "mod", "6");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vca", &dsp->fHslider30, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "mod", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vcf", &dsp->fHslider9, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "sel", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-wavform", &dsp->fHslider10, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph1, "lfo", "0");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "lfo", &dsp->fVbargraph1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "midi", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "mix", &dsp->fHslider13, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider28, "alt", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "noise-vol", &dsp->fHslider28, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider23, "alt", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-1-pw", &dsp->fHslider23, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider27, "alt", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-2-pw", &dsp->fHslider27, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "sel", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-oct", &dsp->fHslider15, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "sel", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-wavform", &dsp->fHslider14, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider26, "sel", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-oct", &dsp->fHslider26, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider24, "sel", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-wavform", &dsp->fHslider24, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider21, "asb", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend_dn", &dsp->fHslider21, (FAUSTFLOAT)12.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)24.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "asb", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend_up", &dsp->fHslider22, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)24.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "pitch-bend", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch-bend", &dsp->fHslider20, (FAUSTFLOAT)8192.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)16383.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "pitch", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch", &dsp->fHslider16, (FAUSTFLOAT)4e+01f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)127.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "midi", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "release", &dsp->fHslider5, (FAUSTFLOAT)0.01f, (FAUSTFLOAT)0.01f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "midi", "6");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "resonance", &dsp->fHslider12, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "midi", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "volume", &dsp->fHslider1, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider29, "alt", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "xor-vol", &dsp->fHslider29, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	float fSlow0 = (float)(dsp->fHslider0);
	float fSlow1 = dsp->fConst1 * (float)(dsp->fHslider1);
	int iSlow2 = (float)(dsp->fHslider2) >= 1.0f;
	int iSlow3 = (float)(dsp->fHslider3) >= 1.0f;
	float fSlow4 = (float)(dsp->fButton0);
	float fSlow5 = dsp->fConst3 * (19.99f * mydsp_faustpower2_f((float)(dsp->fHslider4)) + 0.01f);
	float fSlow6 = mydsp_faustpower2_f((float)(dsp->fHslider5));
	float fSlow7 = 1e+01f * fSlow6;
	float fSlow8 = mydsp_faustpower4_f((float)(dsp->fHslider6));
	float fSlow9 = 1e+01f * fSlow8;
	float fSlow10 = dsp->fConst4 * fSlow8;
	float fSlow11 = expf(0.0f - dsp->fConst5 / fSlow8);
	float fSlow12 = expf(0.0f - dsp->fConst5 / fSlow6);
	float fSlow13 = (float)(dsp->fHslider7);
	int iSlow14 = fSlow13 >= 2.0f;
	int iSlow15 = fSlow13 >= 1.0f;
	float fSlow16 = dsp->fConst8 * mydsp_faustpower2_f((float)(dsp->fHslider8));
	float fSlow17 = (float)(dsp->fHslider9);
	float fSlow18 = (float)(dsp->fHslider10);
	int iSlow19 = fSlow18 >= 2.0f;
	int iSlow20 = fSlow18 >= 1.0f;
	float fSlow21 = 2.1666667f * (float)(dsp->fHslider11);
	float fSlow22 = (float)(dsp->fHslider12);
	float fSlow23 = 24.293f * fSlow22 + 0.707f;
	float fSlow24 = 0.21521576f * (0.33333334f * fSlow23 + -0.707f);
	float fSlow25 = (float)(dsp->fHslider13);
	float fSlow26 = (float)(dsp->fHslider14);
	int iSlow27 = fSlow26 >= 2.0f;
	int iSlow28 = fSlow26 >= 1.0f;
	float fSlow29 = (float)(dsp->fHslider15);
	int iSlow30 = fSlow29 >= 2.0f;
	int iSlow31 = fSlow29 >= 1.0f;
	float fSlow32 = 4.4e+02f * powf(2.0f, 0.083333336f * ((float)(dsp->fHslider16) + -69.0f));
	float fSlow33 = (float)(dsp->fHslider17);
	int iSlow34 = fabsf(fSlow33) < 1.1920929e-07f;
	float fSlow35 = ((iSlow34) ? 0.0f : expf(0.0f - dsp->fConst3 / ((iSlow34) ? 1.0f : fSlow33)));
	float fSlow36 = 1.0f - fSlow35;
	float fSlow37 = (float)(dsp->fHslider18);
	float fSlow38 = 0.083333336f * (float)(dsp->fHslider19);
	float fSlow39 = 0.00012207031f * (float)(dsp->fHslider20) + -1.0f;
	float fSlow40 = dsp->fConst1 * powf(2.0f, 0.083333336f * ((fSlow39 > 0.0f) ? (float)(dsp->fHslider22) * fSlow39 : (float)(dsp->fHslider21) * fSlow39));
	float fSlow41 = dsp->fConst1 * (float)(dsp->fHslider23);
	float fSlow42 = 1.0f - fSlow25;
	float fSlow43 = (float)(dsp->fHslider24);
	int iSlow44 = fSlow43 >= 2.0f;
	int iSlow45 = fSlow43 >= 1.0f;
	float fSlow46 = powf(2.0f, mydsp_faustpower2_f((float)(dsp->fHslider25)));
	float fSlow47 = (float)(dsp->fHslider26);
	int iSlow48 = fSlow47 >= 2.0f;
	int iSlow49 = fSlow47 >= 1.0f;
	float fSlow50 = dsp->fConst1 * (float)(dsp->fHslider27);
	float fSlow51 = dsp->fConst1 * (float)(dsp->fHslider28);
	float fSlow52 = dsp->fConst1 * (float)(dsp->fHslider29);
	float fSlow53 = 4.0f * fSlow22;
	float fSlow54 = 1.0f / fSlow23;
	float fSlow55 = (float)(dsp->fHslider30);
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec0[0] = 1;
			dsp->fRec0[0] = fSlow1 + dsp->fConst2 * dsp->fRec0[1];
			int iTemp0 = 1 - dsp->iVec0[1];
			float fTemp1 = ((iTemp0) ? 0.0f : fSlow5 + dsp->fRec2[1]);
			dsp->fRec2[0] = fTemp1 - floorf(fTemp1);
			float fTemp2 = (float)(dsp->fRec2[0] <= 0.5f);
			dsp->fVec1[0] = fTemp2;
			float fTemp3 = ((iSlow3) ? fTemp2 : fSlow4);
			dsp->fVec2[0] = fTemp3;
			int iTemp4 = fTemp3 > 0.0f;
			float fTemp5 = 0.1447178f * ((iTemp4) ? fSlow9 : fSlow7);
			int iTemp6 = fabsf(fTemp5) < 1.1920929e-07f;
			float fTemp7 = ((iTemp6) ? 0.0f : expf(0.0f - dsp->fConst3 / ((iTemp6) ? 1.0f : fTemp5)));
			dsp->fRec1[0] = (1.0f - fTemp7) * ((iTemp4) ? (float)(iTemp4) : 0.0f) + fTemp7 * dsp->fRec1[1];
			int iTemp8 = (((fTemp3 > dsp->fVec2[1]) != 0) ? 1 : dsp->iRec3[1] + 1);
			dsp->iRec3[0] = iTemp8;
			dsp->fRec4[0] = (((float)(iTemp8) >= fSlow10) ? fSlow12 * dsp->fRec4[1] : 1.0f - fSlow11 * (1.0f - dsp->fRec4[1]));
			float fTemp9 = ((iSlow2) ? dsp->fRec4[0] : dsp->fRec1[0]);
			dsp->fVbargraph0 = (FAUSTFLOAT)(fTemp9);
			float fTemp10 = fTemp9;
			dsp->fRec9[0] = fSlow16 + dsp->fConst7 * dsp->fRec9[1];
			int iTemp11 = (dsp->fVec1[1] <= 0.0f) & (fTemp2 > 0.0f);
			dsp->iRec11[0] = 1103515245 * dsp->iRec11[1] + 12345;
			float fTemp12 = (float)(dsp->iRec11[0]);
			dsp->fRec10[0] = dsp->fRec10[1] * (float)(1 - iTemp11) + 4.656613e-10f * fTemp12 * (float)(iTemp11);
			float fTemp13 = ((iSlow19) ? dsp->fRec10[0] : ((iSlow20) ? fTemp2 : 2.0f * (1.0f - fabsf(2.0f * dsp->fRec2[0] + -1.0f)) + -1.0f));
			dsp->fVbargraph1 = (FAUSTFLOAT)(fTemp13);
			float fTemp14 = fTemp13;
			float fTemp15 = fTemp14 + -0.5f;
			float fTemp16 = fminf(fmaxf(0.0f, dsp->fRec9[0] * powf(2.0f, fSlow17 * fTemp15) * powf(2.0f, fSlow21 * fTemp10)), 1.0f);
			float fTemp17 = tanf(dsp->fConst6 * powf(1e+01f, 3.0f * fTemp16 + 1.0f));
			float fTemp18 = (float)(dsp->iVec0[1]);
			dsp->fRec13[0] = fSlow32 * fSlow36 * powf(2.0f, fSlow37 * fTemp15) * powf(2.0f, fSlow38 * fTemp10) + fSlow35 * dsp->fRec13[1];
			dsp->fRec14[0] = fSlow40 + dsp->fConst2 * dsp->fRec14[1];
			float fTemp19 = dsp->fRec13[0] * dsp->fRec14[0];
			float fTemp20 = 0.5f * fTemp19;
			float fTemp21 = 0.25f * fTemp19;
			float fTemp22 = ((iSlow30) ? fTemp21 : ((iSlow31) ? fTemp20 : fTemp19));
			float fTemp23 = fmaxf(fTemp22, 23.44895f);
			float fTemp24 = fmaxf(2e+01f, fabsf(fTemp23));
			float fTemp25 = ((iTemp0) ? 0.0f : dsp->fRec12[1] + dsp->fConst3 * fTemp24);
			dsp->fRec12[0] = fTemp25 - floorf(fTemp25);
			float fTemp26 = mydsp_faustpower2_f(2.0f * dsp->fRec12[0] + -1.0f);
			dsp->fVec3[0] = fTemp26;
			float fTemp27 = fTemp18 * (fTemp26 - dsp->fVec3[1]) / fTemp24;
			dsp->fVec4[dsp->IOTA0 & 4095] = fTemp27;
			dsp->fRec15[0] = fSlow41 + dsp->fConst2 * dsp->fRec15[1];
			float fTemp28 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst0 * (dsp->fRec15[0] / fTemp23)));
			int iTemp29 = (int)(fTemp28);
			float fTemp30 = floorf(fTemp28);
			float fTemp31 = fTemp27 - dsp->fVec4[(dsp->IOTA0 - iTemp29) & 4095] * (fTemp30 + (1.0f - fTemp28)) - (fTemp28 - fTemp30) * dsp->fVec4[(dsp->IOTA0 - (iTemp29 + 1)) & 4095];
			float fTemp32 = dsp->fConst9 * fTemp31;
			float fTemp33 = fmaxf(2e+01f, fabsf(fTemp22));
			float fTemp34 = ((iTemp0) ? 0.0f : dsp->fRec16[1] + dsp->fConst3 * fTemp33);
			dsp->fRec16[0] = fTemp34 - floorf(fTemp34);
			float fTemp35 = mydsp_faustpower2_f(2.0f * dsp->fRec16[0] + -1.0f);
			dsp->fVec5[0] = fTemp35;
			float fTemp36 = fTemp18 * (fTemp35 - dsp->fVec5[1]) / fTemp33;
			float fTemp37 = fSlow46 * ((iSlow48) ? fTemp21 : ((iSlow49) ? fTemp20 : fTemp19));
			float fTemp38 = fmaxf(fTemp37, 23.44895f);
			float fTemp39 = fmaxf(2e+01f, fabsf(fTemp38));
			float fTemp40 = ((iTemp0) ? 0.0f : dsp->fRec17[1] + dsp->fConst3 * fTemp39);
			dsp->fRec17[0] = fTemp40 - floorf(fTemp40);
			float fTemp41 = mydsp_faustpower2_f(2.0f * dsp->fRec17[0] + -1.0f);
			dsp->fVec6[0] = fTemp41;
			float fTemp42 = fTemp18 * (fTemp41 - dsp->fVec6[1]) / fTemp39;
			dsp->fVec7[dsp->IOTA0 & 4095] = fTemp42;
			dsp->fRec18[0] = fSlow50 + dsp->fConst2 * dsp->fRec18[1];
			float fTemp43 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst0 * (dsp->fRec18[0] / fTemp38)));
			int iTemp44 = (int)(fTemp43);
			float fTemp45 = floorf(fTemp43);
			float fTemp46 = fTemp42 - dsp->fVec7[(dsp->IOTA0 - iTemp44) & 4095] * (fTemp45 + (1.0f - fTemp43)) - (fTemp43 - fTemp45) * dsp->fVec7[(dsp->IOTA0 - (iTemp44 + 1)) & 4095];
			float fTemp47 = dsp->fConst9 * fTemp46;
			float fTemp48 = fmaxf(2e+01f, fabsf(fTemp37));
			float fTemp49 = ((iTemp0) ? 0.0f : dsp->fRec19[1] + dsp->fConst3 * fTemp48);
			dsp->fRec19[0] = fTemp49 - floorf(fTemp49);
			float fTemp50 = mydsp_faustpower2_f(2.0f * dsp->fRec19[0] + -1.0f);
			dsp->fVec8[0] = fTemp50;
			float fTemp51 = fTemp18 * (fTemp50 - dsp->fVec8[1]) / fTemp48;
			dsp->fRec20[0] = fSlow51 + dsp->fConst2 * dsp->fRec20[1];
			dsp->fRec21[0] = fSlow52 + dsp->fConst2 * dsp->fRec21[1];
			float fTemp52 = fSlow25 * ((iSlow27) ? dsp->fConst9 * (fTemp31 + fTemp36) : ((iSlow28) ? dsp->fConst9 * fTemp36 : fTemp32)) + fSlow42 * ((iSlow44) ? dsp->fConst9 * (fTemp46 + fTemp51) : ((iSlow45) ? dsp->fConst9 * fTemp51 : fTemp47)) + 4.656613e-10f * dsp->fRec20[0] * fTemp12 + dsp->fRec21[0] * (float)((int)(fTemp32) ^ (int)(fTemp47));
			float fTemp53 = (fTemp52 - dsp->fRec7[1]) * fTemp17;
			float fTemp54 = fTemp17 + 1.0f;
			float fTemp55 = fTemp17 / fTemp54;
			float fTemp56 = (fTemp52 - (dsp->fRec7[1] + (fTemp53 - dsp->fRec5[1] - dsp->fRec6[1] * (0.0f - fTemp55)) / fTemp54)) / (1.0f - fSlow24 * (fTemp17 * (1.0f - fTemp55) / fTemp54));
			float fTemp57 = fSlow24 * fTemp56;
			float fTemp58 = fTemp17 * (fTemp57 - dsp->fRec6[1]) / fTemp54;
			dsp->fRec5[0] = dsp->fRec5[1] + 2.0f * (fTemp17 * (fTemp57 - (fTemp58 + dsp->fRec5[1] + dsp->fRec6[1])) / fTemp54);
			dsp->fRec6[0] = dsp->fRec6[1] + 2.0f * fTemp58;
			dsp->fRec7[0] = dsp->fRec7[1] + 2.0f * (fTemp53 / fTemp54);
			float fRec8 = fTemp56;
			float fTemp59 = tanf(0.0035699916f * fTemp19 * fTemp16);
			float fTemp60 = fTemp59 + 1.0f;
			float fTemp61 = fTemp59 * ((fTemp52 - fSlow53 * (1.0f - fTemp59 / fTemp60) * (dsp->fRec25[1] + fTemp59 * (dsp->fRec24[1] + fTemp59 * (dsp->fRec23[1] + fTemp59 * dsp->fRec22[1] / fTemp60) / fTemp60) / fTemp60)) / (fSlow53 * (mydsp_faustpower4_f(fTemp59) / mydsp_faustpower4_f(fTemp60)) + 1.0f) - dsp->fRec22[1]) / fTemp60;
			dsp->fRec22[0] = dsp->fRec22[1] + 2.0f * fTemp61;
			float fTemp62 = fTemp59 * (dsp->fRec22[1] + fTemp61 - dsp->fRec23[1]) / fTemp60;
			dsp->fRec23[0] = dsp->fRec23[1] + 2.0f * fTemp62;
			float fTemp63 = fTemp59 * (dsp->fRec23[1] + fTemp62 - dsp->fRec24[1]) / fTemp60;
			dsp->fRec24[0] = dsp->fRec24[1] + 2.0f * fTemp63;
			float fTemp64 = fTemp59 * (dsp->fRec24[1] + fTemp63 - dsp->fRec25[1]) / fTemp60;
			dsp->fRec25[0] = dsp->fRec25[1] + 2.0f * fTemp64;
			float fRec26 = dsp->fRec25[1] + fTemp64;
			float fTemp65 = fSlow54 + fTemp17;
			float fTemp66 = fTemp52 - (dsp->fRec28[1] + dsp->fRec29[1] * fTemp65);
			float fTemp67 = fTemp17 * fTemp65 + 1.0f;
			float fTemp68 = fTemp17 * fTemp66 / fTemp67;
			float fTemp69 = fmaxf(-1.0f, fminf(1.0f, dsp->fRec29[1] + fTemp68));
			float fTemp70 = 1.0f - 0.33333334f * mydsp_faustpower2_f(fTemp69);
			float fTemp71 = fTemp69 * fTemp70;
			float fRec27 = fTemp71;
			float fTemp72 = fTemp17 * fTemp69 * fTemp70;
			dsp->fRec28[0] = dsp->fRec28[1] + 2.0f * fTemp72;
			dsp->fRec29[0] = fTemp68 + fTemp71;
			output0[i0] = (FAUSTFLOAT)(fSlow0 * dsp->fRec0[0] * fTemp10 * ((iSlow14) ? fRec27 : ((iSlow15) ? fRec26 : fRec8)) * (fSlow55 * fTemp14 + 1.0f));
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->fVec1[1] = dsp->fVec1[0];
			dsp->fVec2[1] = dsp->fVec2[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->iRec3[1] = dsp->iRec3[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->fRec9[1] = dsp->fRec9[0];
			dsp->iRec11[1] = dsp->iRec11[0];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fRec16[1] = dsp->fRec16[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec17[1] = dsp->fRec17[0];
			dsp->fVec6[1] = dsp->fVec6[0];
			dsp->fRec18[1] = dsp->fRec18[0];
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fVec8[1] = dsp->fVec8[0];
			dsp->fRec20[1] = dsp->fRec20[0];
			dsp->fRec21[1] = dsp->fRec21[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->fRec22[1] = dsp->fRec22[0];
			dsp->fRec23[1] = dsp->fRec23[0];
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fRec25[1] = dsp->fRec25[0];
			dsp->fRec28[1] = dsp->fRec28[0];
			dsp->fRec29[1] = dsp->fRec29[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
