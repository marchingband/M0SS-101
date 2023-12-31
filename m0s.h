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
	int iVec0[2];
	float fRec0[2];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fButton0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider4;
	float fRec2[2];
	float fVec1[2];
	float fVec2[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	float fRec1[2];
	int iRec3[2];
	float fConst2;
	float fRec4[2];
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider7;
	float fConst3;
	float fConst4;
	float fConst5;
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
	float fRec12[2];
	FAUSTFLOAT fHslider14;
	float fRec13[2];
	FAUSTFLOAT fHslider15;
	float fConst6;
	FAUSTFLOAT fHslider16;
	float fRec15[2];
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fHslider21;
	float fRec17[2];
	float fConst7;
	FAUSTFLOAT fHslider22;
	FAUSTFLOAT fHslider23;
	FAUSTFLOAT fHslider24;
	float fConst8;
	float fRec18[2];
	float fRec16[2];
	float fRec14[2];
	float fVec3[2];
	int IOTA0;
	float fVec4[4096];
	FAUSTFLOAT fHslider25;
	float fRec19[2];
	float fRec20[2];
	float fVec5[2];
	FAUSTFLOAT fHslider26;
	FAUSTFLOAT fHslider27;
	float fRec21[2];
	float fVec6[2];
	float fVec7[4096];
	FAUSTFLOAT fHslider28;
	float fRec22[2];
	float fRec23[2];
	float fVec8[2];
	FAUSTFLOAT fHslider29;
	float fRec24[2];
	float fRec5[2];
	float fRec6[2];
	float fRec7[2];
	float fRec25[2];
	float fRec26[2];
	float fRec27[2];
	float fRec28[2];
	float fRec31[2];
	float fRec32[2];
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
	dsp->fHslider1 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider2 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider3 = (FAUSTFLOAT)(0.0f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider4 = (FAUSTFLOAT)(0.3f);
	dsp->fHslider5 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider6 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider7 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider8 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider9 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider10 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider11 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider12 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider13 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider14 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider15 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider16 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider17 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider18 = (FAUSTFLOAT)(4e+01f);
	dsp->fHslider19 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider20 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider21 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider22 = (FAUSTFLOAT)(8192.0f);
	dsp->fHslider23 = (FAUSTFLOAT)(12.0f);
	dsp->fHslider24 = (FAUSTFLOAT)(2.0f);
	dsp->fHslider25 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider26 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider27 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider28 = (FAUSTFLOAT)(0.5f);
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
			dsp->fRec12[l11] = 0.0f;
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
			dsp->fRec15[l13] = 0.0f;
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
			dsp->fRec14[l17] = 0.0f;
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
		for (l23 = 0; l23 < 2; l23 = l23 + 1) {
			dsp->fRec21[l23] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l24;
		for (l24 = 0; l24 < 2; l24 = l24 + 1) {
			dsp->fVec6[l24] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l25;
		for (l25 = 0; l25 < 4096; l25 = l25 + 1) {
			dsp->fVec7[l25] = 0.0f;
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
			dsp->fRec23[l27] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l28;
		for (l28 = 0; l28 < 2; l28 = l28 + 1) {
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
			dsp->fRec7[l32] = 0.0f;
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
			dsp->fRec28[l36] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l37;
		for (l37 = 0; l37 < 2; l37 = l37 + 1) {
			dsp->fRec31[l37] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l38;
		for (l38 = 0; l38 < 2; l38 = l38 + 1) {
			dsp->fRec32[l38] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 1.0f / dsp->fConst0;
	dsp->fConst2 = 6.9077554f / dsp->fConst0;
	dsp->fConst3 = 6.2831855f / dsp->fConst0;
	dsp->fConst4 = expf(-(2e+01f / dsp->fConst0));
	dsp->fConst5 = 1.0f - dsp->fConst4;
	dsp->fConst6 = 0.25f * dsp->fConst0;
	dsp->fConst7 = 44.1f / dsp->fConst0;
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "midi", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "attack", &dsp->fHslider6, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "midi", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoff", &dsp->fHslider8, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "midi", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "detune", &dsp->fHslider16, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider21, "mod", "13");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-osc", &dsp->fHslider21, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "alt", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "glide", &dsp->fHslider19, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.99f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "sel", "9");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "hp-lp-bp", &dsp->fHslider7, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "midi", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-freq", &dsp->fHslider4, (FAUSTFLOAT)0.3f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "sel", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-env", &dsp->fHslider3, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "mod", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-osc", &dsp->fHslider20, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider30, "mod", "6");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vca", &dsp->fHslider30, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "mod", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vcf", &dsp->fHslider9, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "sel", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-wavform", &dsp->fHslider10, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph1, "lfo", "0");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "lfo", &dsp->fVbargraph1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "midi", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "mix", &dsp->fHslider14, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "alt", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "noise-vol", &dsp->fHslider13, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider28, "alt", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-1-pw", &dsp->fHslider28, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider25, "alt", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-2-pw", &dsp->fHslider25, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider27, "sel", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-oct", &dsp->fHslider27, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider26, "sel", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-wavform", &dsp->fHslider26, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "sel", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-oct", &dsp->fHslider17, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "sel", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-wavform", &dsp->fHslider15, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider23, "asb", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend_dn", &dsp->fHslider23, (FAUSTFLOAT)12.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)24.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider24, "asb", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend_up", &dsp->fHslider24, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)24.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "pitch-bend", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch-bend", &dsp->fHslider22, (FAUSTFLOAT)8192.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)16383.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "pitch", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch", &dsp->fHslider18, (FAUSTFLOAT)4e+01f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)127.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "midi", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "release", &dsp->fHslider5, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
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
	float fSlow1 = 0.9f * (float)(dsp->fHslider1);
	int iSlow2 = (float)(dsp->fHslider2) >= 1.0f;
	int iSlow3 = (float)(dsp->fHslider3) >= 1.0f;
	float fSlow4 = (float)(dsp->fButton0);
	float fSlow5 = dsp->fConst1 * (19.99f * mydsp_faustpower2_f((float)(dsp->fHslider4)) + 0.01f);
	float fSlow6 = (float)(dsp->fHslider5);
	float fSlow7 = (float)(dsp->fHslider6);
	float fSlow8 = dsp->fConst0 * fSlow7;
	float fSlow9 = expf(-(dsp->fConst2 / fSlow7));
	float fSlow10 = expf(-(dsp->fConst2 / fSlow6));
	float fSlow11 = (float)(dsp->fHslider7);
	int iSlow12 = fSlow11 >= 2.0f;
	int iSlow13 = fSlow11 >= 1.0f;
	float fSlow14 = dsp->fConst5 * mydsp_faustpower2_f((float)(dsp->fHslider8));
	float fSlow15 = (float)(dsp->fHslider9);
	float fSlow16 = (float)(dsp->fHslider10);
	int iSlow17 = fSlow16 >= 2.0f;
	int iSlow18 = fSlow16 >= 1.0f;
	float fSlow19 = 2.1666667f * (float)(dsp->fHslider11);
	float fSlow20 = (float)(dsp->fHslider12);
	float fSlow21 = 24.293f * fSlow20 + 0.707f;
	float fSlow22 = 0.21521576f * (0.33333334f * fSlow21 + -0.707f);
	float fSlow23 = 0.9f * (float)(dsp->fHslider13);
	float fSlow24 = 0.9f * (float)(dsp->fHslider14);
	float fSlow25 = (float)(dsp->fHslider15);
	int iSlow26 = fSlow25 >= 2.0f;
	int iSlow27 = fSlow25 >= 1.0f;
	float fSlow28 = 0.9f * powf(2.0f, mydsp_faustpower2_f((float)(dsp->fHslider16)));
	float fSlow29 = (float)(dsp->fHslider17);
	int iSlow30 = fSlow29 >= 2.0f;
	int iSlow31 = fSlow29 >= 1.0f;
	float fSlow32 = 4.4e+02f * powf(2.0f, 0.083333336f * ((float)(dsp->fHslider18) + -69.0f));
	float fSlow33 = (float)(dsp->fHslider19);
	int iSlow34 = fabsf(fSlow33) < 1.1920929e-07f;
	float fSlow35 = ((iSlow34) ? 0.0f : expf(-(dsp->fConst1 / ((iSlow34) ? 1.0f : fSlow33))));
	float fSlow36 = 1.0f - fSlow35;
	float fSlow37 = (float)(dsp->fHslider20);
	float fSlow38 = 0.083333336f * (float)(dsp->fHslider21);
	float fSlow39 = 0.00012207031f * (float)(dsp->fHslider22) + -1.0f;
	float fSlow40 = dsp->fConst7 * powf(2.0f, 0.083333336f * ((fSlow39 > 0.0f) ? (float)(dsp->fHslider24) * fSlow39 : (float)(dsp->fHslider23) * fSlow39));
	float fSlow41 = 0.9f * (float)(dsp->fHslider25);
	float fSlow42 = (float)(dsp->fHslider26);
	int iSlow43 = fSlow42 >= 2.0f;
	int iSlow44 = fSlow42 >= 1.0f;
	float fSlow45 = (float)(dsp->fHslider27);
	int iSlow46 = fSlow45 >= 2.0f;
	int iSlow47 = fSlow45 >= 1.0f;
	float fSlow48 = 0.9f * (float)(dsp->fHslider28);
	float fSlow49 = 0.9f * (float)(dsp->fHslider29);
	float fSlow50 = 4.0f * fSlow20;
	float fSlow51 = 1.0f / fSlow21;
	float fSlow52 = (float)(dsp->fHslider30);
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec0[0] = 1;
			dsp->fRec0[0] = fSlow1 + 0.1f * dsp->fRec0[1];
			int iTemp0 = 1 - dsp->iVec0[1];
			float fTemp1 = ((iTemp0) ? 0.0f : fSlow5 + dsp->fRec2[1]);
			dsp->fRec2[0] = fTemp1 - floorf(fTemp1);
			float fTemp2 = (float)(dsp->fRec2[0] <= 0.5f);
			dsp->fVec1[0] = fTemp2;
			float fTemp3 = ((iSlow3) ? fTemp2 : fSlow4);
			dsp->fVec2[0] = fTemp3;
			int iTemp4 = fTemp3 > 0.0f;
			float fTemp5 = 0.1447178f * ((iTemp4) ? fSlow7 : fSlow6);
			int iTemp6 = fabsf(fTemp5) < 1.1920929e-07f;
			float fTemp7 = ((iTemp6) ? 0.0f : expf(-(dsp->fConst1 / ((iTemp6) ? 1.0f : fTemp5))));
			dsp->fRec1[0] = (1.0f - fTemp7) * ((iTemp4) ? (float)(iTemp4) : 0.0f) + fTemp7 * dsp->fRec1[1];
			int iTemp8 = (((fTemp3 > dsp->fVec2[1]) != 0) ? 1 : dsp->iRec3[1] + 1);
			dsp->iRec3[0] = iTemp8;
			dsp->fRec4[0] = (((float)(iTemp8) >= fSlow8) ? fSlow10 * dsp->fRec4[1] : 1.0f - fSlow9 * (1.0f - dsp->fRec4[1]));
			float fTemp9 = ((iSlow2) ? dsp->fRec4[0] : dsp->fRec1[0]);
			dsp->fVbargraph0 = (FAUSTFLOAT)(fTemp9);
			float fTemp10 = fTemp9;
			dsp->fRec9[0] = fSlow14 + dsp->fConst4 * dsp->fRec9[1];
			int iTemp11 = (dsp->fVec1[1] <= 0.0f) & (fTemp2 > 0.0f);
			dsp->iRec11[0] = 1103515245 * dsp->iRec11[1] + 12345;
			float fTemp12 = (float)(dsp->iRec11[0]);
			dsp->fRec10[0] = dsp->fRec10[1] * (float)(1 - iTemp11) + 4.656613e-10f * fTemp12 * (float)(iTemp11);
			float fTemp13 = ((iSlow17) ? dsp->fRec10[0] : ((iSlow18) ? fTemp2 : 2.0f * (1.0f - fabsf(2.0f * dsp->fRec2[0] + -1.0f)) + -1.0f));
			dsp->fVbargraph1 = (FAUSTFLOAT)(fTemp13);
			float fTemp14 = fTemp13;
			float fTemp15 = fTemp14 + -0.5f;
			float fTemp16 = fminf(fmaxf(0.0f, dsp->fRec9[0] * powf(2.0f, fSlow15 * fTemp15) * powf(2.0f, fSlow19 * fTemp10)), 1.0f);
			float fTemp17 = tanf(dsp->fConst3 * powf(1e+01f, 3.0f * fTemp16 + 1.0f));
			dsp->fRec12[0] = fSlow23 + 0.1f * dsp->fRec12[1];
			dsp->fRec13[0] = fSlow24 + 0.1f * dsp->fRec13[1];
			float fTemp18 = (float)(dsp->iVec0[1]);
			dsp->fRec15[0] = fSlow28 + 0.1f * dsp->fRec15[1];
			dsp->fRec17[0] = fSlow32 * fSlow36 * powf(2.0f, fSlow37 * fTemp15) * powf(2.0f, fSlow38 * fTemp10) + fSlow35 * dsp->fRec17[1];
			dsp->fRec18[0] = fSlow40 + dsp->fConst8 * dsp->fRec18[1];
			dsp->fRec16[0] = 0.9f * dsp->fRec17[0] * dsp->fRec18[0] + 0.1f * dsp->fRec16[1];
			float fTemp19 = 0.5f * dsp->fRec16[0];
			float fTemp20 = 0.25f * dsp->fRec16[0];
			float fTemp21 = dsp->fRec15[0] * ((iSlow30) ? fTemp20 : ((iSlow31) ? fTemp19 : dsp->fRec16[0]));
			float fTemp22 = fmaxf(fTemp21, 23.44895f);
			float fTemp23 = fmaxf(2e+01f, fabsf(fTemp22));
			float fTemp24 = ((iTemp0) ? 0.0f : dsp->fRec14[1] + dsp->fConst1 * fTemp23);
			dsp->fRec14[0] = fTemp24 - floorf(fTemp24);
			float fTemp25 = mydsp_faustpower2_f(2.0f * dsp->fRec14[0] + -1.0f);
			dsp->fVec3[0] = fTemp25;
			float fTemp26 = fTemp18 * (fTemp25 - dsp->fVec3[1]) / fTemp23;
			dsp->fVec4[dsp->IOTA0 & 4095] = fTemp26;
			dsp->fRec19[0] = fSlow41 + 0.1f * dsp->fRec19[1];
			float fTemp27 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst0 * (dsp->fRec19[0] / fTemp22)));
			int iTemp28 = (int)(fTemp27);
			float fTemp29 = floorf(fTemp27);
			float fTemp30 = fTemp26 - dsp->fVec4[(dsp->IOTA0 - iTemp28) & 4095] * (fTemp29 + (1.0f - fTemp27)) - (fTemp27 - fTemp29) * dsp->fVec4[(dsp->IOTA0 - (iTemp28 + 1)) & 4095];
			float fTemp31 = dsp->fConst6 * fTemp30;
			float fTemp32 = fmaxf(2e+01f, fabsf(fTemp21));
			float fTemp33 = ((iTemp0) ? 0.0f : dsp->fRec20[1] + dsp->fConst1 * fTemp32);
			dsp->fRec20[0] = fTemp33 - floorf(fTemp33);
			float fTemp34 = mydsp_faustpower2_f(2.0f * dsp->fRec20[0] + -1.0f);
			dsp->fVec5[0] = fTemp34;
			float fTemp35 = fTemp18 * (fTemp34 - dsp->fVec5[1]) / fTemp32;
			float fTemp36 = ((iSlow46) ? fTemp20 : ((iSlow47) ? fTemp19 : dsp->fRec16[0]));
			float fTemp37 = fmaxf(fTemp36, 23.44895f);
			float fTemp38 = fmaxf(2e+01f, fabsf(fTemp37));
			float fTemp39 = ((iTemp0) ? 0.0f : dsp->fRec21[1] + dsp->fConst1 * fTemp38);
			dsp->fRec21[0] = fTemp39 - floorf(fTemp39);
			float fTemp40 = mydsp_faustpower2_f(2.0f * dsp->fRec21[0] + -1.0f);
			dsp->fVec6[0] = fTemp40;
			float fTemp41 = fTemp18 * (fTemp40 - dsp->fVec6[1]) / fTemp38;
			dsp->fVec7[dsp->IOTA0 & 4095] = fTemp41;
			dsp->fRec22[0] = fSlow48 + 0.1f * dsp->fRec22[1];
			float fTemp42 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst0 * (dsp->fRec22[0] / fTemp37)));
			int iTemp43 = (int)(fTemp42);
			float fTemp44 = floorf(fTemp42);
			float fTemp45 = fTemp41 - dsp->fVec7[(dsp->IOTA0 - iTemp43) & 4095] * (fTemp44 + (1.0f - fTemp42)) - (fTemp42 - fTemp44) * dsp->fVec7[(dsp->IOTA0 - (iTemp43 + 1)) & 4095];
			float fTemp46 = dsp->fConst6 * fTemp45;
			float fTemp47 = fmaxf(2e+01f, fabsf(fTemp36));
			float fTemp48 = ((iTemp0) ? 0.0f : dsp->fRec23[1] + dsp->fConst1 * fTemp47);
			dsp->fRec23[0] = fTemp48 - floorf(fTemp48);
			float fTemp49 = mydsp_faustpower2_f(2.0f * dsp->fRec23[0] + -1.0f);
			dsp->fVec8[0] = fTemp49;
			float fTemp50 = fTemp18 * (fTemp49 - dsp->fVec8[1]) / fTemp47;
			dsp->fRec24[0] = fSlow49 + 0.1f * dsp->fRec24[1];
			float fTemp51 = 4.656613e-10f * dsp->fRec12[0] * fTemp12 + (1.0f - dsp->fRec13[0]) * ((iSlow26) ? dsp->fConst6 * (fTemp30 + fTemp35) : ((iSlow27) ? dsp->fConst6 * fTemp35 : fTemp31)) + dsp->fRec13[0] * ((iSlow43) ? dsp->fConst6 * (fTemp45 + fTemp50) : ((iSlow44) ? dsp->fConst6 * fTemp50 : fTemp46)) + dsp->fRec24[0] * (float)((int)(fTemp46) ^ (int)(fTemp31));
			float fTemp52 = (fTemp51 - dsp->fRec7[1]) * fTemp17;
			float fTemp53 = fTemp17 + 1.0f;
			float fTemp54 = (fTemp51 - (dsp->fRec7[1] + (fTemp52 - dsp->fRec5[1] + fTemp17 * dsp->fRec6[1] / fTemp53) / fTemp53)) / (1.0f - fSlow22 * (fTemp17 * (1.0f - fTemp17 / fTemp53) / fTemp53));
			float fTemp55 = fSlow22 * fTemp54;
			float fTemp56 = fTemp17 * (fTemp55 - dsp->fRec6[1]) / fTemp53;
			dsp->fRec5[0] = dsp->fRec5[1] + 2.0f * (fTemp17 * (fTemp55 - (fTemp56 + dsp->fRec5[1] + dsp->fRec6[1])) / fTemp53);
			dsp->fRec6[0] = dsp->fRec6[1] + 2.0f * fTemp56;
			dsp->fRec7[0] = dsp->fRec7[1] + 2.0f * (fTemp52 / fTemp53);
			float fRec8 = fTemp54;
			float fTemp57 = tanf(0.0035699916f * dsp->fRec16[0] * fTemp16);
			float fTemp58 = fTemp57 + 1.0f;
			float fTemp59 = fTemp57 * ((fTemp51 - fSlow50 * (1.0f - fTemp57 / fTemp58) * (dsp->fRec28[1] + fTemp57 * (dsp->fRec27[1] + fTemp57 * (dsp->fRec26[1] + fTemp57 * dsp->fRec25[1] / fTemp58) / fTemp58) / fTemp58)) / (fSlow50 * (mydsp_faustpower4_f(fTemp57) / mydsp_faustpower4_f(fTemp58)) + 1.0f) - dsp->fRec25[1]) / fTemp58;
			dsp->fRec25[0] = dsp->fRec25[1] + 2.0f * fTemp59;
			float fTemp60 = fTemp57 * (dsp->fRec25[1] + fTemp59 - dsp->fRec26[1]) / fTemp58;
			dsp->fRec26[0] = dsp->fRec26[1] + 2.0f * fTemp60;
			float fTemp61 = fTemp57 * (dsp->fRec26[1] + fTemp60 - dsp->fRec27[1]) / fTemp58;
			dsp->fRec27[0] = dsp->fRec27[1] + 2.0f * fTemp61;
			float fTemp62 = fTemp57 * (dsp->fRec27[1] + fTemp61 - dsp->fRec28[1]) / fTemp58;
			dsp->fRec28[0] = dsp->fRec28[1] + 2.0f * fTemp62;
			float fRec29 = dsp->fRec28[1] + fTemp62;
			float fTemp63 = fSlow51 + fTemp17;
			float fTemp64 = fTemp51 - (dsp->fRec31[1] + dsp->fRec32[1] * fTemp63);
			float fTemp65 = fTemp17 * fTemp63 + 1.0f;
			float fTemp66 = fTemp17 * fTemp64 / fTemp65;
			float fTemp67 = fmaxf(-1.0f, fminf(1.0f, dsp->fRec32[1] + fTemp66));
			float fTemp68 = 1.0f - 0.33333334f * mydsp_faustpower2_f(fTemp67);
			float fTemp69 = fTemp67 * fTemp68;
			float fRec30 = fTemp69;
			float fTemp70 = fTemp17 * fTemp67 * fTemp68;
			dsp->fRec31[0] = dsp->fRec31[1] + 2.0f * fTemp70;
			dsp->fRec32[0] = fTemp66 + fTemp69;
			output0[i0] = (FAUSTFLOAT)(fSlow0 * dsp->fRec0[0] * fTemp10 * ((iSlow12) ? fRec30 : ((iSlow13) ? fRec29 : fRec8)) * (fSlow52 * fTemp14 + 1.0f));
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
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fRec17[1] = dsp->fRec17[0];
			dsp->fRec18[1] = dsp->fRec18[0];
			dsp->fRec16[1] = dsp->fRec16[0];
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fRec20[1] = dsp->fRec20[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec21[1] = dsp->fRec21[0];
			dsp->fVec6[1] = dsp->fVec6[0];
			dsp->fRec22[1] = dsp->fRec22[0];
			dsp->fRec23[1] = dsp->fRec23[0];
			dsp->fVec8[1] = dsp->fVec8[0];
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->fRec25[1] = dsp->fRec25[0];
			dsp->fRec26[1] = dsp->fRec26[0];
			dsp->fRec27[1] = dsp->fRec27[0];
			dsp->fRec28[1] = dsp->fRec28[0];
			dsp->fRec31[1] = dsp->fRec31[0];
			dsp->fRec32[1] = dsp->fRec32[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
