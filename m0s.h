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
#include <dsp.h>

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
	float fRec4[2];
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider7;
	float fConst5;
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	int iRec11[2];
	float fRec10[2];
	FAUSTFLOAT fVbargraph1;
	FAUSTFLOAT fHslider11;
	float fRec9[2];
	FAUSTFLOAT fHslider12;
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	float fConst6;
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fHslider21;
	float fRec13[2];
	float fRec12[2];
	float fVec3[2];
	int IOTA0;
	float fVec4[4096];
	FAUSTFLOAT fHslider22;
	float fRec14[2];
	float fVec5[2];
	FAUSTFLOAT fHslider23;
	FAUSTFLOAT fHslider24;
	FAUSTFLOAT fHslider25;
	float fRec15[2];
	float fVec6[2];
	float fVec7[4096];
	FAUSTFLOAT fHslider26;
	float fRec16[2];
	float fVec8[2];
	FAUSTFLOAT fHslider27;
	FAUSTFLOAT fHslider28;
	float fRec5[2];
	float fRec7[2];
	float fRec8[2];
	float fConst7;
	float fRec21[2];
	float fRec20[2];
	float fRec19[2];
	float fRec18[2];
	float fRec17[2];
	float fRec23[2];
	float fRec24[2];
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
	m->declare(m->metaInterface, "filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/name", "Faust Filters Library");
	m->declare(m->metaInterface, "filters.lib/pole:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/pole:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/version", "0.3");
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
	m->declare(m->metaInterface, "vaeffects.lib/moog_vcf:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "vaeffects.lib/moog_vcf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "vaeffects.lib/moog_vcf:license", "MIT-style STK-4.3 license");
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
	dsp->fHslider4 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider5 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider6 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider7 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider8 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider9 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider10 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider11 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider12 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider13 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider14 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider15 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider16 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider17 = (FAUSTFLOAT)(4e+01f);
	dsp->fHslider18 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider19 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider20 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider21 = (FAUSTFLOAT)(0.0f);
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
			dsp->iRec11[l8] = 0;
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
			dsp->fRec9[l10] = 0.0f;
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
			dsp->fRec12[l12] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l13;
		for (l13 = 0; l13 < 2; l13 = l13 + 1) {
			dsp->fVec3[l13] = 0.0f;
		}
	}
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l14;
		for (l14 = 0; l14 < 4096; l14 = l14 + 1) {
			dsp->fVec4[l14] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l15;
		for (l15 = 0; l15 < 2; l15 = l15 + 1) {
			dsp->fRec14[l15] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l16;
		for (l16 = 0; l16 < 2; l16 = l16 + 1) {
			dsp->fVec5[l16] = 0.0f;
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
		for (l19 = 0; l19 < 4096; l19 = l19 + 1) {
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
		for (l22 = 0; l22 < 2; l22 = l22 + 1) {
			dsp->fRec5[l22] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l23;
		for (l23 = 0; l23 < 2; l23 = l23 + 1) {
			dsp->fRec7[l23] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l24;
		for (l24 = 0; l24 < 2; l24 = l24 + 1) {
			dsp->fRec8[l24] = 0.0f;
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
			dsp->fRec20[l26] = 0.0f;
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
			dsp->fRec18[l28] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l29;
		for (l29 = 0; l29 < 2; l29 = l29 + 1) {
			dsp->fRec17[l29] = 0.0f;
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
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 44.1f / dsp->fConst0;
	dsp->fConst2 = 1.0f - dsp->fConst1;
	dsp->fConst3 = 1.0f / dsp->fConst0;
	dsp->fConst4 = 6.9077554f / dsp->fConst0;
	dsp->fConst5 = 6.2831855f / dsp->fConst0;
	dsp->fConst6 = 0.25f * dsp->fConst0;
	dsp->fConst7 = 43084.7f / dsp->fConst0;
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
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "attack", &dsp->fHslider6, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)5.0f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "midi", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoff", &dsp->fHslider8, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider24, "midi", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "detune", &dsp->fHslider24, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)5e+01f, (FAUSTFLOAT)0.001f);
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "alt", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "glide", &dsp->fHslider18, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.99f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "sel", "9");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "hp-lp-bp", &dsp->fHslider7, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "lfo-depth", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-depth", &dsp->fHslider19, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "midi", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-freq", &dsp->fHslider4, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f, (FAUSTFLOAT)2e+01f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "sel", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-env", &dsp->fHslider3, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "mod", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-osc", &dsp->fHslider20, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider29, "mod", "6");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vca", &dsp->fHslider29, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "mod", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vcf", &dsp->fHslider9, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "sel", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-wavform", &dsp->fHslider10, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVbargraph1, "lfo", "0");
	ui_interface->addVerticalBargraph(ui_interface->uiInterface, "lfo", &dsp->fVbargraph1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "midi", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "mix", &dsp->fHslider13, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider27, "alt", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "noise-vol", &dsp->fHslider27, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "alt", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-1-pw", &dsp->fHslider22, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider26, "alt", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-2-pw", &dsp->fHslider26, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "sel", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-oct", &dsp->fHslider15, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "sel", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-wavform", &dsp->fHslider14, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider25, "sel", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-oct", &dsp->fHslider25, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider23, "sel", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-wavform", &dsp->fHslider23, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "pitch-bend", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch-bend", &dsp->fHslider16, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)-1e+02f, (FAUSTFLOAT)1e+02f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "pitch", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch", &dsp->fHslider17, (FAUSTFLOAT)4e+01f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)127.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "midi", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "release", &dsp->fHslider5, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)5.0f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "midi", "6");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "resonance", &dsp->fHslider12, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1e+01f, (FAUSTFLOAT)0.1f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "midi", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "volume", &dsp->fHslider1, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider28, "alt", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "xor-vol", &dsp->fHslider28, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	float fSlow0 = (float)(dsp->fHslider0);
	float fSlow1 = dsp->fConst1 * (float)(dsp->fHslider1);
	int iSlow2 = (float)(dsp->fHslider2) >= 1.0f;
	int iSlow3 = (float)(dsp->fHslider3) >= 1.0f;
	float fSlow4 = (float)(dsp->fButton0);
	float fSlow5 = dsp->fConst3 * (float)(dsp->fHslider4);
	float fSlow6 = (float)(dsp->fHslider5);
	float fSlow7 = (float)(dsp->fHslider6);
	float fSlow8 = dsp->fConst0 * fSlow7;
	float fSlow9 = expf(0.0f - dsp->fConst4 / fSlow7);
	float fSlow10 = expf(0.0f - dsp->fConst4 / fSlow6);
	float fSlow11 = (float)(dsp->fHslider7);
	int iSlow12 = fSlow11 >= 2.0f;
	int iSlow13 = fSlow11 >= 1.0f;
	float fSlow14 = (float)(dsp->fHslider8);
	float fSlow15 = (float)(dsp->fHslider9);
	float fSlow16 = (float)(dsp->fHslider10);
	int iSlow17 = fSlow16 >= 2.0f;
	int iSlow18 = fSlow16 >= 1.0f;
	float fSlow19 = 2.1666667f * (float)(dsp->fHslider11);
	float fSlow20 = (float)(dsp->fHslider12);
	float fSlow21 = 0.21521576f * (fSlow20 + -0.707f);
	float fSlow22 = (float)(dsp->fHslider13);
	int iSlow23 = (float)(dsp->fHslider14) >= 1.0f;
	float fSlow24 = (float)(dsp->fHslider15);
	int iSlow25 = fSlow24 >= 2.0f;
	int iSlow26 = fSlow24 >= 1.0f;
	float fSlow27 = powf(2.0f, 0.00083333335f * (float)(dsp->fHslider16));
	float fSlow28 = 4.4e+02f * powf(2.0f, 0.083333336f * ((float)(dsp->fHslider17) + -69.0f));
	float fSlow29 = (float)(dsp->fHslider18);
	int iSlow30 = fabsf(fSlow29) < 1.1920929e-07f;
	float fSlow31 = ((iSlow30) ? 0.0f : expf(0.0f - dsp->fConst3 / ((iSlow30) ? 1.0f : fSlow29)));
	float fSlow32 = 1.0f - fSlow31;
	float fSlow33 = (float)(dsp->fHslider19) * (float)(dsp->fHslider20);
	float fSlow34 = 0.083333336f * (float)(dsp->fHslider21);
	float fSlow35 = 0.5f * fSlow27;
	float fSlow36 = 0.25f * fSlow27;
	float fSlow37 = dsp->fConst0 * (float)(dsp->fHslider22);
	float fSlow38 = 1.0f - fSlow22;
	int iSlow39 = (float)(dsp->fHslider23) >= 1.0f;
	float fSlow40 = powf(2.0f, 0.00083333335f * (float)(dsp->fHslider24));
	float fSlow41 = (float)(dsp->fHslider25);
	int iSlow42 = fSlow41 >= 2.0f;
	int iSlow43 = fSlow41 >= 1.0f;
	float fSlow44 = dsp->fConst0 * (float)(dsp->fHslider26);
	float fSlow45 = 4.656613e-10f * (float)(dsp->fHslider27);
	float fSlow46 = (float)(dsp->fHslider28);
	float fSlow47 = 0.0f - 4.0f * fmaxf(0.0f, fminf(0.1f * fSlow20, 0.999999f));
	float fSlow48 = 1.0f / fSlow20;
	float fSlow49 = (float)(dsp->fHslider29);
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
			float fTemp5 = 0.1447178f * ((iTemp4) ? fSlow7 : fSlow6);
			int iTemp6 = fabsf(fTemp5) < 1.1920929e-07f;
			float fTemp7 = ((iTemp6) ? 0.0f : expf(0.0f - dsp->fConst3 / ((iTemp6) ? 1.0f : fTemp5)));
			dsp->fRec1[0] = (1.0f - fTemp7) * ((iTemp4) ? (float)(iTemp4) : 0.0f) + fTemp7 * dsp->fRec1[1];
			int iTemp8 = (((fTemp3 > dsp->fVec2[1]) != 0) ? 1 : dsp->iRec3[1] + 1);
			dsp->iRec3[0] = iTemp8;
			dsp->fRec4[0] = (((float)(iTemp8) >= fSlow8) ? fSlow10 * dsp->fRec4[1] : 1.0f - fSlow9 * (1.0f - dsp->fRec4[1]));
			float fTemp9 = ((iSlow2) ? dsp->fRec4[0] : dsp->fRec1[0]);
			dsp->fVbargraph0 = (FAUSTFLOAT)(fTemp9);
			float fTemp10 = fTemp9;
			int iTemp11 = (dsp->fVec1[1] <= 0.0f) & (fTemp2 > 0.0f);
			dsp->iRec11[0] = 1103515245 * dsp->iRec11[1] + 12345;
			float fTemp12 = (float)(dsp->iRec11[0]);
			dsp->fRec10[0] = dsp->fRec10[1] * (float)(1 - iTemp11) + 4.656613e-10f * fTemp12 * (float)(iTemp11);
			float fTemp13 = ((iSlow17) ? dsp->fRec10[0] : ((iSlow18) ? fTemp2 : 2.0f * (1.0f - fabsf(2.0f * dsp->fRec2[0] + -1.0f)) + -1.0f));
			dsp->fVbargraph1 = (FAUSTFLOAT)(fTemp13);
			float fTemp14 = fTemp13;
			float fTemp15 = fTemp14 + -0.5f;
			dsp->fRec9[0] = dsp->fConst1 * fminf(fmaxf(0.0f, fSlow14 * powf(2.0f, fSlow15 * fTemp15) * powf(2.0f, fSlow19 * fTemp10)), 1.0f) + dsp->fConst2 * dsp->fRec9[1];
			float fTemp16 = tanf(dsp->fConst5 * powf(1e+01f, 3.0f * dsp->fRec9[0] + 1.0f));
			float fTemp17 = (float)(dsp->iVec0[1]);
			dsp->fRec13[0] = fSlow28 * fSlow32 * powf(2.0f, fSlow33 * fTemp15) * powf(2.0f, fSlow34 * fTemp10) + fSlow31 * dsp->fRec13[1];
			float fTemp18 = fSlow27 * dsp->fRec13[0];
			float fTemp19 = fSlow35 * dsp->fRec13[0];
			float fTemp20 = fSlow36 * dsp->fRec13[0];
			float fTemp21 = ((iSlow25) ? fTemp20 : ((iSlow26) ? fTemp19 : fTemp18));
			float fTemp22 = fmaxf(fTemp21, 23.44895f);
			float fTemp23 = fmaxf(2e+01f, fabsf(fTemp22));
			float fTemp24 = ((iTemp0) ? 0.0f : dsp->fRec12[1] + dsp->fConst3 * fTemp23);
			dsp->fRec12[0] = fTemp24 - floorf(fTemp24);
			float fTemp25 = mydsp_faustpower2_f(2.0f * dsp->fRec12[0] + -1.0f);
			dsp->fVec3[0] = fTemp25;
			float fTemp26 = fTemp17 * (fTemp25 - dsp->fVec3[1]) / fTemp23;
			dsp->fVec4[dsp->IOTA0 & 4095] = fTemp26;
			float fTemp27 = fmaxf(0.0f, fminf(2047.0f, fSlow37 / fTemp22));
			int iTemp28 = (int)(fTemp27);
			float fTemp29 = floorf(fTemp27);
			float fTemp30 = 0.0f - dsp->fConst6 * (dsp->fVec4[(dsp->IOTA0 - iTemp28) & 4095] * (fTemp29 + (1.0f - fTemp27)) - fTemp26 + (fTemp27 - fTemp29) * dsp->fVec4[(dsp->IOTA0 - (iTemp28 + 1)) & 4095]);
			float fTemp31 = fmaxf(2e+01f, fabsf(fTemp21));
			float fTemp32 = ((iTemp0) ? 0.0f : dsp->fRec14[1] + dsp->fConst3 * fTemp31);
			dsp->fRec14[0] = fTemp32 - floorf(fTemp32);
			float fTemp33 = mydsp_faustpower2_f(2.0f * dsp->fRec14[0] + -1.0f);
			dsp->fVec5[0] = fTemp33;
			float fTemp34 = fSlow40 * ((iSlow42) ? fTemp20 : ((iSlow43) ? fTemp19 : fTemp18));
			float fTemp35 = fmaxf(fTemp34, 23.44895f);
			float fTemp36 = fmaxf(2e+01f, fabsf(fTemp35));
			float fTemp37 = ((iTemp0) ? 0.0f : dsp->fRec15[1] + dsp->fConst3 * fTemp36);
			dsp->fRec15[0] = fTemp37 - floorf(fTemp37);
			float fTemp38 = mydsp_faustpower2_f(2.0f * dsp->fRec15[0] + -1.0f);
			dsp->fVec6[0] = fTemp38;
			float fTemp39 = fTemp17 * (fTemp38 - dsp->fVec6[1]) / fTemp36;
			dsp->fVec7[dsp->IOTA0 & 4095] = fTemp39;
			float fTemp40 = fmaxf(0.0f, fminf(2047.0f, fSlow44 / fTemp35));
			int iTemp41 = (int)(fTemp40);
			float fTemp42 = floorf(fTemp40);
			float fTemp43 = dsp->fConst6 * (fTemp39 - dsp->fVec7[(dsp->IOTA0 - iTemp41) & 4095] * (fTemp42 + (1.0f - fTemp40)) - (fTemp40 - fTemp42) * dsp->fVec7[(dsp->IOTA0 - (iTemp41 + 1)) & 4095]);
			float fTemp44 = fmaxf(2e+01f, fabsf(fTemp34));
			float fTemp45 = ((iTemp0) ? 0.0f : dsp->fRec16[1] + dsp->fConst3 * fTemp44);
			dsp->fRec16[0] = fTemp45 - floorf(fTemp45);
			float fTemp46 = mydsp_faustpower2_f(2.0f * dsp->fRec16[0] + -1.0f);
			dsp->fVec8[0] = fTemp46;
			float fTemp47 = fSlow22 * ((iSlow23) ? dsp->fConst6 * (fTemp17 * (fTemp33 - dsp->fVec5[1]) / fTemp31) : fTemp30) + fSlow38 * ((iSlow39) ? dsp->fConst6 * (fTemp17 * (fTemp46 - dsp->fVec8[1]) / fTemp44) : fTemp43) + fSlow45 * fTemp12 + fSlow46 * (float)((int)(fTemp30) ^ (int)(fTemp43));
			float fTemp48 = (fTemp47 - dsp->fRec8[1]) * fTemp16;
			float fTemp49 = fTemp16 + 1.0f;
			float fTemp50 = fTemp16 / fTemp49;
			float fTemp51 = (fTemp47 - (dsp->fRec8[1] + (fTemp48 - dsp->fRec5[1] - dsp->fRec7[1] * (0.0f - fTemp50)) / fTemp49)) / (1.0f - fSlow21 * (fTemp16 * (1.0f - fTemp50) / fTemp49));
			float fTemp52 = fSlow21 * fTemp51;
			float fTemp53 = fTemp16 * (fTemp52 - dsp->fRec7[1]) / fTemp49;
			dsp->fRec5[0] = dsp->fRec5[1] + 2.0f * (fTemp16 * (fTemp52 - (fTemp53 + dsp->fRec5[1] + dsp->fRec7[1])) / fTemp49);
			float fRec6 = fTemp51;
			dsp->fRec7[0] = dsp->fRec7[1] + 2.0f * fTemp53;
			dsp->fRec8[0] = dsp->fRec8[1] + 2.0f * (fTemp48 / fTemp49);
			float fTemp54 = dsp->fConst7 * dsp->fRec9[0];
			float fTemp55 = 1.0f - fTemp54;
			dsp->fRec21[0] = fSlow47 * dsp->fRec17[1] + fTemp47 + fTemp55 * dsp->fRec21[1];
			dsp->fRec20[0] = dsp->fRec21[0] + fTemp55 * dsp->fRec20[1];
			dsp->fRec19[0] = dsp->fRec20[0] + fTemp55 * dsp->fRec19[1];
			dsp->fRec18[0] = dsp->fRec19[0] + dsp->fRec18[1] * fTemp55;
			dsp->fRec17[0] = dsp->fRec18[0] * mydsp_faustpower4_f(fTemp54);
			float fTemp56 = fSlow48 + fTemp16;
			float fTemp57 = fTemp47 - (dsp->fRec23[1] + dsp->fRec24[1] * fTemp56);
			float fTemp58 = fTemp16 * fTemp56 + 1.0f;
			float fTemp59 = fTemp16 * fTemp57 / fTemp58;
			float fTemp60 = fmaxf(-1.0f, fminf(1.0f, dsp->fRec24[1] + fTemp59));
			float fTemp61 = 1.0f - 0.33333334f * mydsp_faustpower2_f(fTemp60);
			float fTemp62 = fTemp60 * fTemp61;
			float fRec22 = fTemp62;
			float fTemp63 = fTemp16 * fTemp60 * fTemp61;
			dsp->fRec23[0] = dsp->fRec23[1] + 2.0f * fTemp63;
			dsp->fRec24[0] = fTemp59 + fTemp62;
			output0[i0] = (FAUSTFLOAT)(fSlow0 * dsp->fRec0[0] * fTemp10 * ((iSlow12) ? fRec22 : ((iSlow13) ? dsp->fRec17[0] : fRec6)) * (fSlow49 * fTemp14 + 1.0f));
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->fVec1[1] = dsp->fVec1[0];
			dsp->fVec2[1] = dsp->fVec2[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->iRec3[1] = dsp->iRec3[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->iRec11[1] = dsp->iRec11[0];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->fRec9[1] = dsp->fRec9[0];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fVec6[1] = dsp->fVec6[0];
			dsp->fRec16[1] = dsp->fRec16[0];
			dsp->fVec8[1] = dsp->fVec8[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->fRec8[1] = dsp->fRec8[0];
			dsp->fRec21[1] = dsp->fRec21[0];
			dsp->fRec20[1] = dsp->fRec20[0];
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fRec18[1] = dsp->fRec18[0];
			dsp->fRec17[1] = dsp->fRec17[0];
			dsp->fRec23[1] = dsp->fRec23[0];
			dsp->fRec24[1] = dsp->fRec24[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
