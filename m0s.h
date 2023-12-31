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
	int iVec2[2];
	FAUSTFLOAT fHslider3;
	int iRec2[2];
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	float fRec0[2];
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider7;
	float fRec3[2];
	FAUSTFLOAT fHslider8;
	float fConst2;
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider9;
	float fRec8[2];
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fHslider11;
	int iRec10[2];
	float fRec9[2];
	FAUSTFLOAT fVbargraph1;
	FAUSTFLOAT fHslider12;
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	float fRec11[2];
	FAUSTFLOAT fHslider15;
	float fConst5;
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	float fRec14[2];
	float fConst6;
	FAUSTFLOAT fHslider21;
	FAUSTFLOAT fHslider22;
	FAUSTFLOAT fHslider23;
	float fConst7;
	float fRec15[2];
	float fRec13[2];
	float fRec12[2];
	float fVec3[2];
	int IOTA0;
	float fVec4[4096];
	FAUSTFLOAT fHslider24;
	float fRec16[2];
	float fRec17[2];
	float fVec5[2];
	FAUSTFLOAT fHslider25;
	FAUSTFLOAT fHslider26;
	float fRec19[2];
	FAUSTFLOAT fHslider27;
	float fRec18[2];
	float fVec6[2];
	float fVec7[4096];
	FAUSTFLOAT fHslider28;
	float fRec20[2];
	float fRec21[2];
	float fVec8[2];
	FAUSTFLOAT fHslider29;
	float fRec22[2];
	FAUSTFLOAT fHslider30;
	float fRec23[2];
	float fRec4[2];
	float fRec5[2];
	float fRec6[2];
	float fRec24[2];
	float fRec25[2];
	float fRec26[2];
	float fRec27[2];
	float fRec30[2];
	float fRec31[2];
	FAUSTFLOAT fHslider31;
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
	m->declare(m->metaInterface, "envelopes.lib/adsre:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "envelopes.lib/adsre:licence", "STK-4.3");
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
	dsp->fHslider5 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider6 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider7 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider8 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider9 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider10 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider11 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider12 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider13 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider14 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider15 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider16 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider17 = (FAUSTFLOAT)(4e+01f);
	dsp->fHslider18 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider19 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider20 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider21 = (FAUSTFLOAT)(8192.0f);
	dsp->fHslider22 = (FAUSTFLOAT)(12.0f);
	dsp->fHslider23 = (FAUSTFLOAT)(2.0f);
	dsp->fHslider24 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider25 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider26 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider27 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider28 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider29 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider30 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider31 = (FAUSTFLOAT)(0.0f);
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
			dsp->iVec2[l3] = 0;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->iRec2[l4] = 0;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->fRec0[l5] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->fRec3[l6] = 0.0f;
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
			dsp->iRec10[l8] = 0;
		}
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 2; l9 = l9 + 1) {
			dsp->fRec9[l9] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 2; l10 = l10 + 1) {
			dsp->fRec11[l10] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 2; l11 = l11 + 1) {
			dsp->fRec14[l11] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l12;
		for (l12 = 0; l12 < 2; l12 = l12 + 1) {
			dsp->fRec15[l12] = 0.0f;
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
			dsp->fRec12[l14] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l15;
		for (l15 = 0; l15 < 2; l15 = l15 + 1) {
			dsp->fVec3[l15] = 0.0f;
		}
	}
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l16;
		for (l16 = 0; l16 < 4096; l16 = l16 + 1) {
			dsp->fVec4[l16] = 0.0f;
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
			dsp->fRec17[l18] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l19;
		for (l19 = 0; l19 < 2; l19 = l19 + 1) {
			dsp->fVec5[l19] = 0.0f;
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
			dsp->fRec18[l21] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l22;
		for (l22 = 0; l22 < 2; l22 = l22 + 1) {
			dsp->fVec6[l22] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l23;
		for (l23 = 0; l23 < 4096; l23 = l23 + 1) {
			dsp->fVec7[l23] = 0.0f;
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
			dsp->fRec21[l25] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l26;
		for (l26 = 0; l26 < 2; l26 = l26 + 1) {
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
			dsp->fRec4[l29] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l30;
		for (l30 = 0; l30 < 2; l30 = l30 + 1) {
			dsp->fRec5[l30] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l31;
		for (l31 = 0; l31 < 2; l31 = l31 + 1) {
			dsp->fRec6[l31] = 0.0f;
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
			dsp->fRec26[l34] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l35;
		for (l35 = 0; l35 < 2; l35 = l35 + 1) {
			dsp->fRec27[l35] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l36;
		for (l36 = 0; l36 < 2; l36 = l36 + 1) {
			dsp->fRec30[l36] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l37;
		for (l37 = 0; l37 < 2; l37 = l37 + 1) {
			dsp->fRec31[l37] = 0.0f;
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "midi", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoff", &dsp->fHslider9, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "mod", "19");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "decay", &dsp->fHslider5, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider26, "midi", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "detune", &dsp->fHslider26, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "mod", "20");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-osc", &dsp->fHslider20, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "mod", "15");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vca", &dsp->fHslider0, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "mod", "18");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vcf", &dsp->fHslider12, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph0, "env", "0");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "env", &dsp->fVbargraph0, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fButton0, "gate", "");
	ui_interface->addButton(ui_interface->uiInterface, "gate", &dsp->fButton0);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "alt", "23");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "glide", &dsp->fHslider18, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.99f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "sel", "13");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "hp-lp-bp", &dsp->fHslider8, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "midi", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-freq", &dsp->fHslider2, (FAUSTFLOAT)0.3f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "sel", "9");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-env", &dsp->fHslider1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "mod", "10");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-osc", &dsp->fHslider19, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider31, "mod", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vca", &dsp->fHslider31, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "mod", "11");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vcf", &dsp->fHslider10, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "sel", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-wavform", &dsp->fHslider11, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph1, "lfo", "0");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "lfo", &dsp->fVbargraph1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "midi", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "mix", &dsp->fHslider14, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider29, "alt", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "noise-vol", &dsp->fHslider29, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider24, "alt", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-1-pw", &dsp->fHslider24, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider28, "alt", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-2-pw", &dsp->fHslider28, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "sel", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-oct", &dsp->fHslider16, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "sel", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-wavform", &dsp->fHslider15, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider27, "sel", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-oct", &dsp->fHslider27, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider25, "sel", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-wavform", &dsp->fHslider25, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "asb", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend_dn", &dsp->fHslider22, (FAUSTFLOAT)12.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)24.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider23, "asb", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend_up", &dsp->fHslider23, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)24.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider21, "pitch-bend", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch-bend", &dsp->fHslider21, (FAUSTFLOAT)8192.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)16383.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "pitch", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch", &dsp->fHslider17, (FAUSTFLOAT)4e+01f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)127.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "midi", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "release", &dsp->fHslider3, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "midi", "6");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "resonance", &dsp->fHslider13, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "mod", "21");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "sustain", &dsp->fHslider6, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "midi", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "volume", &dsp->fHslider7, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider30, "alt", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "xor-vol", &dsp->fHslider30, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
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
	int iSlow6 = (int)(dsp->fConst0 * fSlow5);
	float fSlow7 = (float)(dsp->fHslider5);
	float fSlow8 = (float)(dsp->fHslider6);
	float fSlow9 = 0.9f * (float)(dsp->fHslider7);
	float fSlow10 = (float)(dsp->fHslider8);
	int iSlow11 = fSlow10 >= 2.0f;
	int iSlow12 = fSlow10 >= 1.0f;
	float fSlow13 = dsp->fConst4 * mydsp_faustpower2_f((float)(dsp->fHslider9));
	float fSlow14 = (float)(dsp->fHslider10);
	float fSlow15 = (float)(dsp->fHslider11);
	int iSlow16 = fSlow15 >= 2.0f;
	int iSlow17 = fSlow15 >= 1.0f;
	float fSlow18 = 2.1666667f * (float)(dsp->fHslider12);
	float fSlow19 = (float)(dsp->fHslider13);
	float fSlow20 = 24.293f * fSlow19 + 0.707f;
	float fSlow21 = 0.21521576f * (0.33333334f * fSlow20 + -0.707f);
	float fSlow22 = 0.9f * (float)(dsp->fHslider14);
	float fSlow23 = (float)(dsp->fHslider15);
	int iSlow24 = fSlow23 >= 2.0f;
	int iSlow25 = fSlow23 >= 1.0f;
	float fSlow26 = (float)(dsp->fHslider16);
	int iSlow27 = fSlow26 >= 2.0f;
	int iSlow28 = fSlow26 >= 1.0f;
	float fSlow29 = 4.4e+02f * powf(2.0f, 0.083333336f * ((float)(dsp->fHslider17) + -69.0f));
	float fSlow30 = (float)(dsp->fHslider18);
	int iSlow31 = fabsf(fSlow30) < 1.1920929e-07f;
	float fSlow32 = ((iSlow31) ? 0.0f : expf(-(dsp->fConst1 / ((iSlow31) ? 1.0f : fSlow30))));
	float fSlow33 = 1.0f - fSlow32;
	float fSlow34 = (float)(dsp->fHslider19);
	float fSlow35 = 0.083333336f * (float)(dsp->fHslider20);
	float fSlow36 = 0.00012207031f * (float)(dsp->fHslider21) + -1.0f;
	float fSlow37 = dsp->fConst6 * powf(2.0f, 0.083333336f * ((fSlow36 > 0.0f) ? (float)(dsp->fHslider23) * fSlow36 : (float)(dsp->fHslider22) * fSlow36));
	float fSlow38 = 0.9f * (float)(dsp->fHslider24);
	float fSlow39 = (float)(dsp->fHslider25);
	int iSlow40 = fSlow39 >= 2.0f;
	int iSlow41 = fSlow39 >= 1.0f;
	float fSlow42 = 0.9f * powf(2.0f, mydsp_faustpower2_f((float)(dsp->fHslider26)));
	float fSlow43 = (float)(dsp->fHslider27);
	int iSlow44 = fSlow43 >= 2.0f;
	int iSlow45 = fSlow43 >= 1.0f;
	float fSlow46 = 0.9f * (float)(dsp->fHslider28);
	float fSlow47 = 0.9f * (float)(dsp->fHslider29);
	float fSlow48 = 0.9f * (float)(dsp->fHslider30);
	float fSlow49 = 4.0f * fSlow19;
	float fSlow50 = 1.0f / fSlow20;
	float fSlow51 = (float)(dsp->fHslider31);
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
			dsp->iVec2[0] = iTemp3;
			dsp->iRec2[0] = iTemp3 * (dsp->iRec2[1] + 1);
			int iTemp4 = iTemp3 - dsp->iVec2[1];
			int iTemp5 = (dsp->iRec2[0] < iSlow6) | (iTemp4 * (iTemp4 > 0));
			float fTemp6 = 0.1447178f * ((iTemp3) ? ((iTemp5) ? fSlow5 : fSlow7) : fSlow4);
			int iTemp7 = fabsf(fTemp6) < 1.1920929e-07f;
			float fTemp8 = ((iTemp7) ? 0.0f : expf(-(dsp->fConst1 / ((iTemp7) ? 1.0f : fTemp6))));
			float fTemp9 = (float)(iTemp3);
			dsp->fRec0[0] = (1.0f - fTemp8) * ((iTemp3) ? ((iTemp5) ? fTemp9 : fSlow8 * fTemp9) : 0.0f) + fTemp8 * dsp->fRec0[1];
			dsp->fVbargraph0 = (FAUSTFLOAT)(dsp->fRec0[0]);
			float fTemp10 = dsp->fRec0[0];
			dsp->fRec3[0] = fSlow9 + 0.1f * dsp->fRec3[1];
			dsp->fRec8[0] = fSlow13 + dsp->fConst3 * dsp->fRec8[1];
			int iTemp11 = (dsp->fVec1[1] <= 0.0f) & (fTemp2 > 0.0f);
			dsp->iRec10[0] = 1103515245 * dsp->iRec10[1] + 12345;
			float fTemp12 = (float)(dsp->iRec10[0]);
			dsp->fRec9[0] = dsp->fRec9[1] * (float)(1 - iTemp11) + 4.656613e-10f * fTemp12 * (float)(iTemp11);
			float fTemp13 = ((iSlow16) ? dsp->fRec9[0] : ((iSlow17) ? fTemp2 : 2.0f * (1.0f - fabsf(2.0f * dsp->fRec1[0] + -1.0f)) + -1.0f));
			dsp->fVbargraph1 = (FAUSTFLOAT)(fTemp13);
			float fTemp14 = fTemp13;
			float fTemp15 = fTemp14 + -0.5f;
			float fTemp16 = fminf(fmaxf(0.0f, dsp->fRec8[0] * powf(2.0f, fSlow14 * fTemp15) * powf(2.0f, fSlow18 * fTemp10)), 1.0f);
			float fTemp17 = tanf(dsp->fConst2 * powf(1e+01f, 3.0f * fTemp16 + 1.0f));
			dsp->fRec11[0] = fSlow22 + 0.1f * dsp->fRec11[1];
			float fTemp18 = (float)(dsp->iVec0[1]);
			dsp->fRec14[0] = fSlow29 * fSlow33 * powf(2.0f, fSlow34 * fTemp15) * powf(2.0f, fSlow35 * fTemp10) + fSlow32 * dsp->fRec14[1];
			dsp->fRec15[0] = fSlow37 + dsp->fConst7 * dsp->fRec15[1];
			dsp->fRec13[0] = 0.9f * dsp->fRec14[0] * dsp->fRec15[0] + 0.1f * dsp->fRec13[1];
			float fTemp19 = 0.5f * dsp->fRec13[0];
			float fTemp20 = 0.25f * dsp->fRec13[0];
			float fTemp21 = ((iSlow27) ? fTemp20 : ((iSlow28) ? fTemp19 : dsp->fRec13[0]));
			float fTemp22 = fmaxf(fTemp21, 23.44895f);
			float fTemp23 = fmaxf(2e+01f, fabsf(fTemp22));
			float fTemp24 = ((iTemp0) ? 0.0f : dsp->fRec12[1] + dsp->fConst1 * fTemp23);
			dsp->fRec12[0] = fTemp24 - floorf(fTemp24);
			float fTemp25 = mydsp_faustpower2_f(2.0f * dsp->fRec12[0] + -1.0f);
			dsp->fVec3[0] = fTemp25;
			float fTemp26 = fTemp18 * (fTemp25 - dsp->fVec3[1]) / fTemp23;
			dsp->fVec4[dsp->IOTA0 & 4095] = fTemp26;
			dsp->fRec16[0] = fSlow38 + 0.1f * dsp->fRec16[1];
			float fTemp27 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst0 * (dsp->fRec16[0] / fTemp22)));
			int iTemp28 = (int)(fTemp27);
			float fTemp29 = floorf(fTemp27);
			float fTemp30 = fTemp26 - dsp->fVec4[(dsp->IOTA0 - iTemp28) & 4095] * (fTemp29 + (1.0f - fTemp27)) - (fTemp27 - fTemp29) * dsp->fVec4[(dsp->IOTA0 - (iTemp28 + 1)) & 4095];
			float fTemp31 = dsp->fConst5 * fTemp30;
			float fTemp32 = fmaxf(2e+01f, fabsf(fTemp21));
			float fTemp33 = ((iTemp0) ? 0.0f : dsp->fRec17[1] + dsp->fConst1 * fTemp32);
			dsp->fRec17[0] = fTemp33 - floorf(fTemp33);
			float fTemp34 = mydsp_faustpower2_f(2.0f * dsp->fRec17[0] + -1.0f);
			dsp->fVec5[0] = fTemp34;
			float fTemp35 = fTemp18 * (fTemp34 - dsp->fVec5[1]) / fTemp32;
			dsp->fRec19[0] = fSlow42 + 0.1f * dsp->fRec19[1];
			float fTemp36 = dsp->fRec19[0] * ((iSlow44) ? fTemp20 : ((iSlow45) ? fTemp19 : dsp->fRec13[0]));
			float fTemp37 = fmaxf(fTemp36, 23.44895f);
			float fTemp38 = fmaxf(2e+01f, fabsf(fTemp37));
			float fTemp39 = ((iTemp0) ? 0.0f : dsp->fRec18[1] + dsp->fConst1 * fTemp38);
			dsp->fRec18[0] = fTemp39 - floorf(fTemp39);
			float fTemp40 = mydsp_faustpower2_f(2.0f * dsp->fRec18[0] + -1.0f);
			dsp->fVec6[0] = fTemp40;
			float fTemp41 = fTemp18 * (fTemp40 - dsp->fVec6[1]) / fTemp38;
			dsp->fVec7[dsp->IOTA0 & 4095] = fTemp41;
			dsp->fRec20[0] = fSlow46 + 0.1f * dsp->fRec20[1];
			float fTemp42 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst0 * (dsp->fRec20[0] / fTemp37)));
			int iTemp43 = (int)(fTemp42);
			float fTemp44 = floorf(fTemp42);
			float fTemp45 = fTemp41 - dsp->fVec7[(dsp->IOTA0 - iTemp43) & 4095] * (fTemp44 + (1.0f - fTemp42)) - (fTemp42 - fTemp44) * dsp->fVec7[(dsp->IOTA0 - (iTemp43 + 1)) & 4095];
			float fTemp46 = dsp->fConst5 * fTemp45;
			float fTemp47 = fmaxf(2e+01f, fabsf(fTemp36));
			float fTemp48 = ((iTemp0) ? 0.0f : dsp->fRec21[1] + dsp->fConst1 * fTemp47);
			dsp->fRec21[0] = fTemp48 - floorf(fTemp48);
			float fTemp49 = mydsp_faustpower2_f(2.0f * dsp->fRec21[0] + -1.0f);
			dsp->fVec8[0] = fTemp49;
			float fTemp50 = fTemp18 * (fTemp49 - dsp->fVec8[1]) / fTemp47;
			dsp->fRec22[0] = fSlow47 + 0.1f * dsp->fRec22[1];
			dsp->fRec23[0] = fSlow48 + 0.1f * dsp->fRec23[1];
			float fTemp51 = dsp->fRec11[0] * ((iSlow24) ? dsp->fConst5 * (fTemp30 + fTemp35) : ((iSlow25) ? dsp->fConst5 * fTemp35 : fTemp31)) + (1.0f - dsp->fRec11[0]) * ((iSlow40) ? dsp->fConst5 * (fTemp45 + fTemp50) : ((iSlow41) ? dsp->fConst5 * fTemp50 : fTemp46)) + 4.656613e-10f * dsp->fRec22[0] * fTemp12 + dsp->fRec23[0] * (float)((int)(fTemp31) ^ (int)(fTemp46));
			float fTemp52 = (fTemp51 - dsp->fRec6[1]) * fTemp17;
			float fTemp53 = fTemp17 + 1.0f;
			float fTemp54 = (fTemp51 - (dsp->fRec6[1] + (fTemp52 - dsp->fRec4[1] + fTemp17 * dsp->fRec5[1] / fTemp53) / fTemp53)) / (1.0f - fSlow21 * (fTemp17 * (1.0f - fTemp17 / fTemp53) / fTemp53));
			float fTemp55 = fSlow21 * fTemp54;
			float fTemp56 = fTemp17 * (fTemp55 - dsp->fRec5[1]) / fTemp53;
			dsp->fRec4[0] = dsp->fRec4[1] + 2.0f * (fTemp17 * (fTemp55 - (dsp->fRec4[1] + dsp->fRec5[1] + fTemp56)) / fTemp53);
			dsp->fRec5[0] = dsp->fRec5[1] + 2.0f * fTemp56;
			dsp->fRec6[0] = dsp->fRec6[1] + 2.0f * (fTemp52 / fTemp53);
			float fRec7 = fTemp54;
			float fTemp57 = tanf(0.0035699916f * dsp->fRec13[0] * fTemp16);
			float fTemp58 = fTemp57 + 1.0f;
			float fTemp59 = fTemp57 * ((fTemp51 - fSlow49 * (1.0f - fTemp57 / fTemp58) * (dsp->fRec27[1] + fTemp57 * (dsp->fRec26[1] + fTemp57 * (dsp->fRec25[1] + fTemp57 * dsp->fRec24[1] / fTemp58) / fTemp58) / fTemp58)) / (fSlow49 * (mydsp_faustpower4_f(fTemp57) / mydsp_faustpower4_f(fTemp58)) + 1.0f) - dsp->fRec24[1]) / fTemp58;
			dsp->fRec24[0] = dsp->fRec24[1] + 2.0f * fTemp59;
			float fTemp60 = fTemp57 * (dsp->fRec24[1] + fTemp59 - dsp->fRec25[1]) / fTemp58;
			dsp->fRec25[0] = dsp->fRec25[1] + 2.0f * fTemp60;
			float fTemp61 = fTemp57 * (dsp->fRec25[1] + fTemp60 - dsp->fRec26[1]) / fTemp58;
			dsp->fRec26[0] = dsp->fRec26[1] + 2.0f * fTemp61;
			float fTemp62 = fTemp57 * (dsp->fRec26[1] + fTemp61 - dsp->fRec27[1]) / fTemp58;
			dsp->fRec27[0] = dsp->fRec27[1] + 2.0f * fTemp62;
			float fRec28 = dsp->fRec27[1] + fTemp62;
			float fTemp63 = fSlow50 + fTemp17;
			float fTemp64 = fTemp51 - (dsp->fRec30[1] + dsp->fRec31[1] * fTemp63);
			float fTemp65 = fTemp17 * fTemp63 + 1.0f;
			float fTemp66 = fTemp17 * fTemp64 / fTemp65;
			float fTemp67 = fmaxf(-1.0f, fminf(1.0f, dsp->fRec31[1] + fTemp66));
			float fTemp68 = 1.0f - 0.33333334f * mydsp_faustpower2_f(fTemp67);
			float fTemp69 = fTemp67 * fTemp68;
			float fRec29 = fTemp69;
			float fTemp70 = fTemp17 * fTemp67 * fTemp68;
			dsp->fRec30[0] = dsp->fRec30[1] + 2.0f * fTemp70;
			dsp->fRec31[0] = fTemp66 + fTemp69;
			output0[i0] = (FAUSTFLOAT)(fSlow0 * fTemp10 * dsp->fRec3[0] * ((iSlow11) ? fRec29 : ((iSlow12) ? fRec28 : fRec7)) * (fSlow51 * fTemp14 + 1.0f));
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->fVec1[1] = dsp->fVec1[0];
			dsp->iVec2[1] = dsp->iVec2[0];
			dsp->iRec2[1] = dsp->iRec2[0];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec3[1] = dsp->fRec3[0];
			dsp->fRec8[1] = dsp->fRec8[0];
			dsp->iRec10[1] = dsp->iRec10[0];
			dsp->fRec9[1] = dsp->fRec9[0];
			dsp->fRec11[1] = dsp->fRec11[0];
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec16[1] = dsp->fRec16[0];
			dsp->fRec17[1] = dsp->fRec17[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fRec18[1] = dsp->fRec18[0];
			dsp->fVec6[1] = dsp->fVec6[0];
			dsp->fRec20[1] = dsp->fRec20[0];
			dsp->fRec21[1] = dsp->fRec21[0];
			dsp->fVec8[1] = dsp->fVec8[0];
			dsp->fRec22[1] = dsp->fRec22[0];
			dsp->fRec23[1] = dsp->fRec23[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fRec25[1] = dsp->fRec25[0];
			dsp->fRec26[1] = dsp->fRec26[0];
			dsp->fRec27[1] = dsp->fRec27[0];
			dsp->fRec30[1] = dsp->fRec30[0];
			dsp->fRec31[1] = dsp->fRec31[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
