/* ------------------------------------------------------------
name: "m0ss"
Code generated with Faust 2.70.3 (https://faust.grame.fr)
Compilation options: -lang c -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
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
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fRec0[2];
	float fVec1[2];
	int iRec2[2];
	float fRec1[2];
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fButton0;
	int iRec5[2];
	int iRec3[2];
	FAUSTFLOAT fHslider4;
	int iVec2[2];
	float fRec6[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fRec4[2];
	FAUSTFLOAT fVbargraph1;
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fVbargraph2;
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fHslider11;
	float fConst2;
	FAUSTFLOAT fHslider12;
	float fConst3;
	float fRec11[2];
	float fConst4;
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	float fConst5;
	float fConst6;
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fHslider17;
	float fRec13[2];
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fHslider21;
	float fRec14[2];
	float fRec12[2];
	FAUSTFLOAT fHslider22;
	float fRec15[2];
	float fRec16[2];
	float fVec3[2];
	int IOTA0;
	float fVec4[4096];
	FAUSTFLOAT fHslider23;
	float fRec17[2];
	float fConst7;
	FAUSTFLOAT fHslider24;
	float fRec18[2];
	float fVec5[2];
	float fVec6[4096];
	FAUSTFLOAT fHslider25;
	FAUSTFLOAT fHslider26;
	float fRec19[2];
	FAUSTFLOAT fHslider27;
	FAUSTFLOAT fHslider28;
	float fRec20[2];
	FAUSTFLOAT fHslider29;
	float fRec21[2];
	FAUSTFLOAT fHslider30;
	float fRec22[2];
	float fVec7[2];
	FAUSTFLOAT fHslider31;
	float fRec23[2];
	FAUSTFLOAT fHslider32;
	float fRec24[2];
	float fVec8[2];
	float fVec9[8192];
	float fRec7[2];
	float fRec8[2];
	float fRec9[2];
	float fRec25[2];
	float fRec26[2];
	float fRec27[2];
	float fRec28[2];
	float fRec31[2];
	float fRec32[2];
	FAUSTFLOAT fHslider33;
	float fRec33[2];
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
	m->declare(m->metaInterface, "basics.lib/version", "1.12.0");
	m->declare(m->metaInterface, "compile_options", "-lang c -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
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
	m->declare(m->metaInterface, "oscillators.lib/version", "1.5.0");
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
	m->declare(m->metaInterface, "vaeffects.lib/version", "1.2.1");
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
	dsp->fHslider1 = (FAUSTFLOAT)(0.3f);
	dsp->fHslider2 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider3 = (FAUSTFLOAT)(0.0f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider4 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider5 = (FAUSTFLOAT)(0.01f);
	dsp->fHslider6 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider7 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider8 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider9 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider10 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider11 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider12 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider13 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider14 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider15 = (FAUSTFLOAT)(8192.0f);
	dsp->fHslider16 = (FAUSTFLOAT)(12.0f);
	dsp->fHslider17 = (FAUSTFLOAT)(2.0f);
	dsp->fHslider18 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider19 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider20 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider21 = (FAUSTFLOAT)(4e+01f);
	dsp->fHslider22 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider23 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider24 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider25 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider26 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider27 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider28 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider29 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider30 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider31 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider32 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider33 = (FAUSTFLOAT)(1.0f);
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
			dsp->fVec1[l2] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1) {
			dsp->iRec2[l3] = 0;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->fRec1[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->iRec5[l5] = 0;
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
			dsp->iVec2[l7] = 0;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 2; l8 = l8 + 1) {
			dsp->fRec6[l8] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 2; l9 = l9 + 1) {
			dsp->fRec4[l9] = 0.0f;
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
			dsp->fRec15[l14] = 0.0f;
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
			dsp->fVec3[l16] = 0.0f;
		}
	}
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l17;
		for (l17 = 0; l17 < 4096; l17 = l17 + 1) {
			dsp->fVec4[l17] = 0.0f;
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
			dsp->fRec18[l19] = 0.0f;
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
			dsp->fRec21[l24] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l25;
		for (l25 = 0; l25 < 2; l25 = l25 + 1) {
			dsp->fRec22[l25] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l26;
		for (l26 = 0; l26 < 2; l26 = l26 + 1) {
			dsp->fVec7[l26] = 0.0f;
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
			dsp->fRec24[l28] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l29;
		for (l29 = 0; l29 < 2; l29 = l29 + 1) {
			dsp->fVec8[l29] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l30;
		for (l30 = 0; l30 < 8192; l30 = l30 + 1) {
			dsp->fVec9[l30] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l31;
		for (l31 = 0; l31 < 2; l31 = l31 + 1) {
			dsp->fRec7[l31] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l32;
		for (l32 = 0; l32 < 2; l32 = l32 + 1) {
			dsp->fRec8[l32] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l33;
		for (l33 = 0; l33 < 2; l33 = l33 + 1) {
			dsp->fRec9[l33] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l34;
		for (l34 = 0; l34 < 2; l34 = l34 + 1) {
			dsp->fRec25[l34] = 0.0f;
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
			dsp->fRec31[l38] = 0.0f;
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
	dsp->fConst1 = 1.0f / dsp->fConst0;
	dsp->fConst2 = expf(-(2e+01f / dsp->fConst0));
	dsp->fConst3 = 1.0f - dsp->fConst2;
	dsp->fConst4 = 6.2831855f / dsp->fConst0;
	dsp->fConst5 = 44.1f / dsp->fConst0;
	dsp->fConst6 = 1.0f - dsp->fConst5;
	dsp->fConst7 = 0.25f * dsp->fConst0;
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "mod", "16");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "attack", &dsp->fHslider6, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "midi", "2");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "mod", "14");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoff", &dsp->fHslider12, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "midi", "24");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "mod", "19");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "decay", &dsp->fHslider5, (FAUSTFLOAT)0.01f, (FAUSTFLOAT)0.01f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "midi", "7");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "mod", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "detune", &dsp->fHslider22, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "midi", "22");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "mod", "20");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-osc", &dsp->fHslider19, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider27, "midi", "23");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider27, "mod", "24");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-pwm", &dsp->fHslider27, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "midi", "20");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "mod", "15");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vca", &dsp->fHslider8, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "midi", "21");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "mod", "18");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vcf", &dsp->fHslider10, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph1, "env", "0");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "env", &dsp->fVbargraph1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fButton0, "gate", "");
	ui_interface->addButton(ui_interface->uiInterface, "gate", &dsp->fButton0);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "alt", "23");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "midi", "30");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "glide", &dsp->fHslider18, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.99f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "midi", "15");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "sel", "13");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "hp-lp-bp", &dsp->fHslider9, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "midi", "3");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "mod", "12");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-freq", &dsp->fHslider1, (FAUSTFLOAT)0.3f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "midi", "14");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "sel", "9");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-env", &dsp->fHslider3, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "midi", "16");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "mod", "10");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-osc", &dsp->fHslider20, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider25, "midi", "19");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider25, "mod", "6");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-pwm", &dsp->fHslider25, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "midi", "17");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "mod", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vca", &dsp->fHslider2, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "midi", "18");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "mod", "11");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vcf", &dsp->fHslider11, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "midi", "13");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "sel", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-wavform", &dsp->fHslider0, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph0, "lfo", "0");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "lfo", &dsp->fVbargraph0, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider31, "midi", "4");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider31, "mod", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "mix", &dsp->fHslider31, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider29, "alt", "5");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider29, "midi", "29");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "noise-vol", &dsp->fHslider29, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider26, "alt", "0");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider26, "midi", "26");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-1-pw", &dsp->fHslider26, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider23, "alt", "3");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider23, "midi", "27");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-2-pw", &dsp->fHslider23, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider24, "midi", "10");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider24, "sel", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-oct", &dsp->fHslider24, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider32, "midi", "9");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider32, "sel", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-wavform", &dsp->fHslider32, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "midi", "11");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "sel", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-oct", &dsp->fHslider14, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider30, "midi", "12");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider30, "sel", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-wavform", &dsp->fHslider30, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "asb", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend_dn", &dsp->fHslider16, (FAUSTFLOAT)12.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)24.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "asb", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pbend_up", &dsp->fHslider17, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)24.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "pitch-bend", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch-bend", &dsp->fHslider15, (FAUSTFLOAT)8192.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)16383.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider21, "pitch", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch", &dsp->fHslider21, (FAUSTFLOAT)4e+01f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)127.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "midi", "5");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "mod", "25");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "release", &dsp->fHslider7, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "midi", "6");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "mod", "17");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "resonance", &dsp->fHslider13, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "midi", "25");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "mod", "21");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "sustain", &dsp->fHslider4, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph2, "vca", "0");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "vca", &dsp->fVbargraph2, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider33, "midi", "8");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider33, "mod", "23");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "volume", &dsp->fHslider33, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider28, "alt", "4");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider28, "midi", "28");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "xor-vol", &dsp->fHslider28, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	float fSlow0 = (float)(dsp->fHslider0);
	int iSlow1 = fSlow0 >= 2.0f;
	int iSlow2 = fSlow0 >= 1.0f;
	float fSlow3 = dsp->fConst1 * (19.99f * mydsp_faustpower2_f((float)(dsp->fHslider1)) + 0.01f);
	float fSlow4 = (float)(dsp->fHslider2);
	int iSlow5 = (float)(dsp->fHslider3) >= 1.0f;
	float fSlow6 = (float)(dsp->fButton0);
	float fSlow7 = (float)(dsp->fHslider4);
	float fSlow8 = (fSlow7 + -1.0f) / fmaxf(1.0f, dsp->fConst0 * (float)(dsp->fHslider5));
	float fSlow9 = 1.0f / fmaxf(1.0f, dsp->fConst0 * (19.999f * mydsp_faustpower3_f((float)(dsp->fHslider6)) + 0.001f));
	float fSlow10 = 1.0f / fmaxf(1.0f, dsp->fConst0 * (19.999f * mydsp_faustpower2_f((float)(dsp->fHslider7)) + 0.001f));
	float fSlow11 = (float)(dsp->fHslider8);
	float fSlow12 = (float)(dsp->fHslider9);
	int iSlow13 = fSlow12 >= 2.0f;
	int iSlow14 = fSlow12 >= 1.0f;
	float fSlow15 = 2.1666667f * (float)(dsp->fHslider10);
	float fSlow16 = (float)(dsp->fHslider11);
	float fSlow17 = dsp->fConst3 * mydsp_faustpower2_f((float)(dsp->fHslider12));
	float fSlow18 = 24.293f * (float)(dsp->fHslider13);
	float fSlow19 = fSlow18 + 0.707f;
	float fSlow20 = 0.21521823f * (0.33333334f * fSlow19 + -0.70710677f);
	float fSlow21 = (float)(dsp->fHslider14);
	int iSlow22 = fSlow21 >= 2.0f;
	int iSlow23 = fSlow21 >= 1.0f;
	float fSlow24 = 0.00012207031f * (float)(dsp->fHslider15) + -1.0f;
	float fSlow25 = dsp->fConst5 * powf(2.0f, 0.083333336f * ((fSlow24 > 0.0f) ? (float)(dsp->fHslider17) * fSlow24 : (float)(dsp->fHslider16) * fSlow24));
	float fSlow26 = (float)(dsp->fHslider18);
	int iSlow27 = fabsf(fSlow26) < 1.1920929e-07f;
	float fSlow28 = ((iSlow27) ? 0.0f : expf(-(dsp->fConst1 / ((iSlow27) ? 1.0f : fSlow26))));
	float fSlow29 = 0.083333336f * (float)(dsp->fHslider19);
	float fSlow30 = (float)(dsp->fHslider20);
	float fSlow31 = 1.0f - fSlow28;
	float fSlow32 = 4.4e+02f * powf(2.0f, 0.083333336f * ((float)(dsp->fHslider21) + -69.0f));
	float fSlow33 = 0.9f * powf(2.0f, mydsp_faustpower2_f((float)(dsp->fHslider22)));
	float fSlow34 = 0.9f * (float)(dsp->fHslider23);
	float fSlow35 = (float)(dsp->fHslider24);
	int iSlow36 = fSlow35 >= 2.0f;
	int iSlow37 = fSlow35 >= 1.0f;
	float fSlow38 = (float)(dsp->fHslider25);
	float fSlow39 = 0.9f * (float)(dsp->fHslider26);
	float fSlow40 = dsp->fConst0 * (1.0f - (float)(dsp->fHslider27));
	float fSlow41 = 0.9f * (float)(dsp->fHslider28);
	float fSlow42 = 0.9f * (float)(dsp->fHslider29);
	float fSlow43 = (float)(dsp->fHslider30);
	int iSlow44 = fSlow43 >= 2.0f;
	int iSlow45 = fSlow43 >= 1.0f;
	float fSlow46 = 0.9f * (float)(dsp->fHslider31);
	float fSlow47 = (float)(dsp->fHslider32);
	int iSlow48 = fSlow47 >= 2.0f;
	int iSlow49 = fSlow47 >= 1.0f;
	float fSlow50 = 0.1646572f * (fSlow18 + -0.00010678119f);
	float fSlow51 = 1.0f / fSlow19;
	float fSlow52 = 0.9f * (float)(dsp->fHslider33);
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec0[0] = 1;
			int iTemp0 = 1 - dsp->iVec0[1];
			float fTemp1 = ((iTemp0) ? 0.0f : fSlow3 + dsp->fRec0[1]);
			dsp->fRec0[0] = fTemp1 - floorf(fTemp1);
			float fTemp2 = (float)(dsp->fRec0[0] <= 0.5f);
			dsp->fVec1[0] = fTemp2;
			int iTemp3 = (dsp->fVec1[1] <= 0.0f) & (fTemp2 > 0.0f);
			dsp->iRec2[0] = 1103515245 * dsp->iRec2[1] + 12345;
			float fTemp4 = (float)(dsp->iRec2[0]);
			dsp->fRec1[0] = dsp->fRec1[1] * (float)(1 - iTemp3) + 4.656613e-10f * fTemp4 * (float)(iTemp3);
			float fTemp5 = ((iSlow1) ? dsp->fRec1[0] : ((iSlow2) ? fTemp2 : 2.0f * (1.0f - fabsf(2.0f * dsp->fRec0[0] + -1.0f)) + -1.0f));
			dsp->fVbargraph0 = (FAUSTFLOAT)(fTemp5);
			float fTemp6 = fTemp5;
			float fTemp7 = ((iSlow5) ? fTemp2 : fSlow6);
			int iTemp8 = dsp->iRec3[1] == 0;
			int iTemp9 = dsp->iRec3[1] == 1;
			dsp->iRec5[0] = dsp->iRec5[1] + 1;
			int iTemp10 = (dsp->iRec5[0] + -1) == 0;
			float fTemp11 = ((iTemp10) ? 0.0f : dsp->fRec4[1]);
			dsp->iRec3[0] = ((fTemp7 > 0.0f) ? ((iTemp8) ? 1 : ((iTemp9) ? ((fTemp11 < 1.0f) ? 1 : 2) : 2)) : 0);
			float fTemp12 = ((dsp->iRec3[1] == 2) ? fSlow7 : 0.0f);
			int iTemp13 = fTemp7 == 0.0f;
			dsp->iVec2[0] = iTemp13;
			int iTemp14 = (dsp->iVec2[1] <= 0) & (iTemp13 > 0);
			dsp->fRec6[0] = dsp->fRec6[1] * (float)(1 - iTemp14) + ((iTemp10) ? 1.0f : fTemp11) * (float)(iTemp14);
			float fTemp15 = ((iTemp8) ? dsp->fRec6[0] : 1.0f);
			float fTemp16 = ((fTemp12 == fTemp15) ? 0.5f : (fTemp11 - fTemp12) / (fTemp15 - fTemp12));
			dsp->fRec4[0] = fmaxf(fTemp12, fminf(1.0f, fTemp11 + 0.25f * (((iTemp8) ? -(fSlow10 * dsp->fRec6[0]) : ((iTemp9) ? fSlow9 : fSlow8)) / mydsp_faustpower2_f(0.5f * (2.0f * fTemp16 + -1.0f) + (1.0f - fTemp16)))));
			dsp->fVbargraph1 = (FAUSTFLOAT)(dsp->fRec4[0]);
			float fTemp17 = dsp->fRec4[0];
			float fTemp18 = fSlow11 * fTemp17 * (fSlow4 * fTemp6 + 1.0f);
			dsp->fVbargraph2 = (FAUSTFLOAT)(fTemp18);
			float fTemp19 = fTemp6 + -0.5f;
			dsp->fRec11[0] = fSlow17 + dsp->fConst2 * dsp->fRec11[1];
			float fTemp20 = fminf(fmaxf(0.0f, dsp->fRec11[0] * powf(2.0f, fSlow16 * fTemp19) * powf(2.0f, fSlow15 * fTemp17)), 1.0f);
			float fTemp21 = tanf(dsp->fConst4 * powf(1e+01f, 3.0f * fTemp20 + 1.0f));
			float fTemp22 = fTemp21 + 1.0f;
			dsp->fRec13[0] = fSlow25 + dsp->fConst6 * dsp->fRec13[1];
			dsp->fRec14[0] = fSlow32 * fSlow31 * powf(2.0f, fSlow30 * fTemp19) * powf(2.0f, fSlow29 * fTemp17) + fSlow28 * dsp->fRec14[1];
			dsp->fRec12[0] = 0.9f * dsp->fRec14[0] * dsp->fRec13[0] + 0.1f * dsp->fRec12[1];
			float fTemp23 = 0.5f * dsp->fRec12[0];
			float fTemp24 = 0.25f * dsp->fRec12[0];
			dsp->fRec15[0] = fSlow33 + 0.1f * dsp->fRec15[1];
			float fTemp25 = dsp->fRec15[0] * ((iSlow22) ? fTemp24 : ((iSlow23) ? fTemp23 : dsp->fRec12[0]));
			float fTemp26 = fmaxf(fTemp25, 23.44895f);
			float fTemp27 = fmaxf(2e+01f, fabsf(fTemp26));
			float fTemp28 = ((iTemp0) ? 0.0f : dsp->fRec16[1] + dsp->fConst1 * fTemp27);
			dsp->fRec16[0] = fTemp28 - floorf(fTemp28);
			float fTemp29 = mydsp_faustpower2_f(2.0f * dsp->fRec16[0] + -1.0f);
			dsp->fVec3[0] = fTemp29;
			float fTemp30 = (float)(dsp->iVec0[1]);
			float fTemp31 = fTemp30 * (fTemp29 - dsp->fVec3[1]) / fTemp27;
			dsp->fVec4[dsp->IOTA0 & 4095] = fTemp31;
			dsp->fRec17[0] = fSlow34 + 0.1f * dsp->fRec17[1];
			float fTemp32 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst0 * (dsp->fRec17[0] / fTemp26)));
			int iTemp33 = (int)(fTemp32);
			float fTemp34 = floorf(fTemp32);
			float fTemp35 = dsp->fVec4[(dsp->IOTA0 - iTemp33) & 4095] * (fTemp34 + (1.0f - fTemp32)) - fTemp31 + (fTemp32 - fTemp34) * dsp->fVec4[(dsp->IOTA0 - (iTemp33 + 1)) & 4095];
			float fTemp36 = dsp->fConst7 * fTemp35;
			float fTemp37 = ((iSlow36) ? fTemp24 : ((iSlow37) ? fTemp23 : dsp->fRec12[0]));
			float fTemp38 = fmaxf(fTemp37, 23.44895f);
			float fTemp39 = fmaxf(2e+01f, fabsf(fTemp38));
			float fTemp40 = ((iTemp0) ? 0.0f : dsp->fRec18[1] + dsp->fConst1 * fTemp39);
			dsp->fRec18[0] = fTemp40 - floorf(fTemp40);
			float fTemp41 = mydsp_faustpower2_f(2.0f * dsp->fRec18[0] + -1.0f);
			dsp->fVec5[0] = fTemp41;
			float fTemp42 = fTemp30 * (fTemp41 - dsp->fVec5[1]) / fTemp39;
			dsp->fVec6[dsp->IOTA0 & 4095] = fTemp42;
			dsp->fRec19[0] = fSlow39 + 0.1f * dsp->fRec19[1];
			float fTemp43 = dsp->fRec19[0] * (1.0f - fSlow38 * fTemp6);
			float fTemp44 = fmaxf(0.0f, fminf(2047.0f, fSlow40 * (fTemp43 / fTemp38)));
			int iTemp45 = (int)(fTemp44);
			float fTemp46 = floorf(fTemp44);
			float fTemp47 = fTemp42 - dsp->fVec6[(dsp->IOTA0 - iTemp45) & 4095] * (fTemp46 + (1.0f - fTemp44)) - (fTemp44 - fTemp46) * dsp->fVec6[(dsp->IOTA0 - (iTemp45 + 1)) & 4095];
			float fTemp48 = dsp->fConst7 * fTemp47;
			dsp->fRec20[0] = fSlow41 + 0.1f * dsp->fRec20[1];
			dsp->fRec21[0] = fSlow42 + 0.1f * dsp->fRec21[1];
			float fTemp49 = fmaxf(2e+01f, fabsf(fTemp25));
			float fTemp50 = ((iTemp0) ? 0.0f : dsp->fRec22[1] + dsp->fConst1 * fTemp49);
			dsp->fRec22[0] = fTemp50 - floorf(fTemp50);
			float fTemp51 = mydsp_faustpower2_f(2.0f * dsp->fRec22[0] + -1.0f);
			dsp->fVec7[0] = fTemp51;
			float fTemp52 = fTemp30 * (fTemp51 - dsp->fVec7[1]) / fTemp49;
			dsp->fRec23[0] = fSlow46 + 0.1f * dsp->fRec23[1];
			float fTemp53 = fmaxf(2e+01f, fabsf(fTemp37));
			float fTemp54 = ((iTemp0) ? 0.0f : dsp->fRec24[1] + dsp->fConst1 * fTemp53);
			dsp->fRec24[0] = fTemp54 - floorf(fTemp54);
			float fTemp55 = mydsp_faustpower2_f(2.0f * dsp->fRec24[0] + -1.0f);
			dsp->fVec8[0] = fTemp55;
			dsp->fVec9[dsp->IOTA0 & 8191] = fTemp30 * (fTemp55 - dsp->fVec8[1]) / fTemp53;
			float fTemp56 = dsp->fVec9[(dsp->IOTA0 - max(0, min(8191, (int)(fSlow40 * (fTemp43 / fTemp37) + 0.5f)))) & 8191];
			float fTemp57 = dsp->fRec23[0] * ((iSlow48) ? dsp->fConst7 * (fTemp47 + fTemp56) : ((iSlow49) ? dsp->fConst7 * fTemp56 : fTemp48)) + (1.0f - dsp->fRec23[0]) * ((iSlow44) ? -(dsp->fConst7 * (fTemp35 - fTemp52)) : ((iSlow45) ? dsp->fConst7 * fTemp52 : -fTemp36)) + 4.656613e-10f * dsp->fRec21[0] * fTemp4 + dsp->fRec20[0] * (float)((int)(fTemp48) ^ (int)(-fTemp36));
			float fTemp58 = (fTemp57 - dsp->fRec9[1]) * fTemp21;
			float fTemp59 = (fTemp57 - (dsp->fRec9[1] + (fTemp58 - dsp->fRec7[1] + fTemp21 * dsp->fRec8[1] / fTemp22) / fTemp22)) / (1.0f - fSlow20 * (fTemp21 * (1.0f - fTemp21 / fTemp22) / fTemp22));
			float fTemp60 = fSlow20 * fTemp59;
			float fTemp61 = fTemp21 * (fTemp60 - dsp->fRec8[1]) / fTemp22;
			dsp->fRec7[0] = dsp->fRec7[1] + 2.0f * (fTemp21 * (fTemp60 - (fTemp61 + dsp->fRec7[1] + dsp->fRec8[1])) / fTemp22);
			dsp->fRec8[0] = dsp->fRec8[1] + 2.0f * fTemp61;
			dsp->fRec9[0] = dsp->fRec9[1] + 2.0f * (fTemp58 / fTemp22);
			float fRec10 = fTemp59;
			float fTemp62 = tanf(1.5707964f * fminf(fmaxf(0.0f, 0.0022727272f * dsp->fRec12[0] * fTemp20), 1.0f));
			float fTemp63 = fTemp62 + 1.0f;
			float fTemp64 = fTemp62 * ((fTemp57 - fSlow50 * (1.0f - fTemp62 / fTemp63) * (dsp->fRec28[1] + fTemp62 * (dsp->fRec27[1] + fTemp62 * (dsp->fRec26[1] + fTemp62 * dsp->fRec25[1] / fTemp63) / fTemp63) / fTemp63)) / (fSlow50 * (mydsp_faustpower4_f(fTemp62) / mydsp_faustpower4_f(fTemp63)) + 1.0f) - dsp->fRec25[1]) / fTemp63;
			dsp->fRec25[0] = dsp->fRec25[1] + 2.0f * fTemp64;
			float fTemp65 = fTemp62 * (dsp->fRec25[1] + fTemp64 - dsp->fRec26[1]) / fTemp63;
			dsp->fRec26[0] = dsp->fRec26[1] + 2.0f * fTemp65;
			float fTemp66 = fTemp62 * (dsp->fRec26[1] + fTemp65 - dsp->fRec27[1]) / fTemp63;
			dsp->fRec27[0] = dsp->fRec27[1] + 2.0f * fTemp66;
			float fTemp67 = fTemp62 * (dsp->fRec27[1] + fTemp66 - dsp->fRec28[1]) / fTemp63;
			dsp->fRec28[0] = dsp->fRec28[1] + 2.0f * fTemp67;
			float fRec29 = dsp->fRec28[1] + fTemp67;
			float fTemp68 = fSlow51 + fTemp21;
			float fTemp69 = fTemp21 * fTemp68 + 1.0f;
			float fTemp70 = fTemp57 - (dsp->fRec31[1] + dsp->fRec32[1] * fTemp68);
			float fTemp71 = fTemp21 * fTemp70 / fTemp69;
			float fTemp72 = fmaxf(-1.0f, fminf(1.0f, dsp->fRec32[1] + fTemp71));
			float fTemp73 = 1.0f - 0.33333334f * mydsp_faustpower2_f(fTemp72);
			float fTemp74 = fTemp72 * fTemp73;
			float fRec30 = fTemp74;
			float fTemp75 = fTemp21 * fTemp72 * fTemp73;
			dsp->fRec31[0] = dsp->fRec31[1] + 2.0f * fTemp75;
			dsp->fRec32[0] = fTemp71 + fTemp74;
			dsp->fRec33[0] = fSlow52 + 0.1f * dsp->fRec33[1];
			output0[i0] = (FAUSTFLOAT)(dsp->fRec33[0] * ((iSlow13) ? fRec30 : ((iSlow14) ? fRec29 : fRec10)) * fTemp18);
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fVec1[1] = dsp->fVec1[0];
			dsp->iRec2[1] = dsp->iRec2[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->iRec5[1] = dsp->iRec5[0];
			dsp->iRec3[1] = dsp->iRec3[0];
			dsp->iVec2[1] = dsp->iVec2[0];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->fRec11[1] = dsp->fRec11[0];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fRec16[1] = dsp->fRec16[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec17[1] = dsp->fRec17[0];
			dsp->fRec18[1] = dsp->fRec18[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fRec20[1] = dsp->fRec20[0];
			dsp->fRec21[1] = dsp->fRec21[0];
			dsp->fRec22[1] = dsp->fRec22[0];
			dsp->fVec7[1] = dsp->fVec7[0];
			dsp->fRec23[1] = dsp->fRec23[0];
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fVec8[1] = dsp->fVec8[0];
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->fRec8[1] = dsp->fRec8[0];
			dsp->fRec9[1] = dsp->fRec9[0];
			dsp->fRec25[1] = dsp->fRec25[0];
			dsp->fRec26[1] = dsp->fRec26[0];
			dsp->fRec27[1] = dsp->fRec27[0];
			dsp->fRec28[1] = dsp->fRec28[0];
			dsp->fRec31[1] = dsp->fRec31[0];
			dsp->fRec32[1] = dsp->fRec32[0];
			dsp->fRec33[1] = dsp->fRec33[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
