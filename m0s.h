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
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	int fSampleRate;
	float fConst0;
	float fConst1;
	int iVec0[2];
	float fConst2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	float fRec7[2];
	float fVec1[2];
	int iRec9[2];
	float fRec8[2];
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fHslider12;
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fButton0;
	float fVec2[2];
	FAUSTFLOAT fHslider14;
	FAUSTFLOAT fHslider15;
	float fRec10[2];
	int iRec11[2];
	float fConst3;
	float fRec12[2];
	float fRec6[2];
	float fRec5[2];
	float fVec3[2];
	int IOTA0;
	float fVec4[4096];
	FAUSTFLOAT fHslider16;
	float fRec13[2];
	float fVec5[2];
	FAUSTFLOAT fHslider17;
	float fConst4;
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fHslider21;
	FAUSTFLOAT fHslider22;
	FAUSTFLOAT fHslider23;
	float fRec14[2];
	float fVec6[2];
	float fVec7[4096];
	FAUSTFLOAT fHslider24;
	float fRec15[2];
	float fVec8[2];
	FAUSTFLOAT fHslider25;
	FAUSTFLOAT fHslider26;
	float fRec4[2];
	float fRec3[2];
	float fRec2[2];
	float fRec1[2];
	float fRec0[2];
	float fConst5;
	FAUSTFLOAT fHslider27;
	float fConst6;
	float fRec16[2];
	FAUSTFLOAT fHslider28;
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
	m->declare(m->metaInterface, "vaeffects.lib/moog_vcf:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "vaeffects.lib/moog_vcf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "vaeffects.lib/moog_vcf:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
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
	dsp->fHslider1 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider2 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider3 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider4 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider5 = (FAUSTFLOAT)(4e+01f);
	dsp->fHslider6 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider7 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider8 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider9 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider10 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider11 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider12 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider13 = (FAUSTFLOAT)(0.0f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider14 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider15 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider16 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider17 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider18 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider19 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider20 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider21 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider22 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider23 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider24 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider25 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider26 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider27 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider28 = (FAUSTFLOAT)(0.0f);
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
			dsp->fRec7[l1] = 0.0f;
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
			dsp->iRec9[l3] = 0;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->fRec8[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->fVec2[l5] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->fRec10[l6] = 0.0f;
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
			dsp->fRec12[l8] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 2; l9 = l9 + 1) {
			dsp->fRec6[l9] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 2; l10 = l10 + 1) {
			dsp->fRec5[l10] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 2; l11 = l11 + 1) {
			dsp->fVec3[l11] = 0.0f;
		}
	}
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l12;
		for (l12 = 0; l12 < 4096; l12 = l12 + 1) {
			dsp->fVec4[l12] = 0.0f;
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
			dsp->fVec5[l14] = 0.0f;
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
			dsp->fVec6[l16] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l17;
		for (l17 = 0; l17 < 4096; l17 = l17 + 1) {
			dsp->fVec7[l17] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l18;
		for (l18 = 0; l18 < 2; l18 = l18 + 1) {
			dsp->fRec15[l18] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l19;
		for (l19 = 0; l19 < 2; l19 = l19 + 1) {
			dsp->fVec8[l19] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l20;
		for (l20 = 0; l20 < 2; l20 = l20 + 1) {
			dsp->fRec4[l20] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l21;
		for (l21 = 0; l21 < 2; l21 = l21 + 1) {
			dsp->fRec3[l21] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l22;
		for (l22 = 0; l22 < 2; l22 = l22 + 1) {
			dsp->fRec2[l22] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l23;
		for (l23 = 0; l23 < 2; l23 = l23 + 1) {
			dsp->fRec1[l23] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l24;
		for (l24 = 0; l24 < 2; l24 = l24 + 1) {
			dsp->fRec0[l24] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l25;
		for (l25 = 0; l25 < 2; l25 = l25 + 1) {
			dsp->fRec16[l25] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 0.25f * dsp->fConst0;
	dsp->fConst2 = 1.0f / dsp->fConst0;
	dsp->fConst3 = 6.9077554f / dsp->fConst0;
	dsp->fConst4 = 43084.7f / dsp->fConst0;
	dsp->fConst5 = 44.1f / dsp->fConst0;
	dsp->fConst6 = 1.0f - dsp->fConst5;
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "midi", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "attack", &dsp->fHslider15, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)5.0f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "midi", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoff", &dsp->fHslider18, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "midi", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "detune", &dsp->fHslider22, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)-5e+01f, (FAUSTFLOAT)5e+01f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "mod", "13");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-osc", &dsp->fHslider11, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "mod", "10");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vca", &dsp->fHslider0, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "mod", "12");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-to-vcf", &dsp->fHslider20, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "sel", "11");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "env-type", &dsp->fHslider12, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fButton0, "gate", "");
	ui_interface->addButton(ui_interface->uiInterface, "gate", &dsp->fButton0);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "alt", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "glide", &dsp->fHslider6, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.99f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "lfo-depth", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-depth", &dsp->fHslider7, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "midi", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-freq", &dsp->fHslider10, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f, (FAUSTFLOAT)2e+01f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "mod", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-env", &dsp->fHslider13, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "mod", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-osc", &dsp->fHslider8, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider28, "mod", "6");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vca", &dsp->fHslider28, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "mod", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vcf", &dsp->fHslider19, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "sel", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-wavform", &dsp->fHslider9, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "midi", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "mix", &dsp->fHslider1, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider25, "alt", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "noise-vol", &dsp->fHslider25, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "alt", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-1-pw", &dsp->fHslider16, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider24, "alt", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc-2-pw", &dsp->fHslider24, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "sel", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-oct", &dsp->fHslider3, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "sel", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-wavform", &dsp->fHslider2, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider23, "sel", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-oct", &dsp->fHslider23, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider21, "sel", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-wavform", &dsp->fHslider21, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "pitch-bend", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch-bend", &dsp->fHslider4, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)-1e+02f, (FAUSTFLOAT)1e+02f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "pitch", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch", &dsp->fHslider5, (FAUSTFLOAT)4e+01f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)127.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "midi", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "release", &dsp->fHslider14, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)5.0f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "midi", "6");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "resonance", &dsp->fHslider17, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1e+01f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider27, "midi", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "volume", &dsp->fHslider27, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider26, "alt", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "xor-vol", &dsp->fHslider26, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	float fSlow0 = (float)(dsp->fHslider0);
	float fSlow1 = (float)(dsp->fHslider1);
	int iSlow2 = (float)(dsp->fHslider2) >= 1.0f;
	float fSlow3 = (float)(dsp->fHslider3);
	int iSlow4 = fSlow3 >= 2.0f;
	int iSlow5 = fSlow3 >= 1.0f;
	float fSlow6 = powf(2.0f, 0.00083333335f * (float)(dsp->fHslider4));
	float fSlow7 = 4.4e+02f * powf(2.0f, 0.083333336f * ((float)(dsp->fHslider5) + -69.0f));
	float fSlow8 = (float)(dsp->fHslider6);
	int iSlow9 = fabsf(fSlow8) < 1.1920929e-07f;
	float fSlow10 = ((iSlow9) ? 0.0f : expf(0.0f - dsp->fConst2 / ((iSlow9) ? 1.0f : fSlow8)));
	float fSlow11 = 1.0f - fSlow10;
	float fSlow12 = (float)(dsp->fHslider7) * (float)(dsp->fHslider8);
	float fSlow13 = (float)(dsp->fHslider9);
	int iSlow14 = fSlow13 >= 2.0f;
	int iSlow15 = fSlow13 >= 1.0f;
	float fSlow16 = dsp->fConst2 * (float)(dsp->fHslider10);
	float fSlow17 = 0.083333336f * (float)(dsp->fHslider11);
	int iSlow18 = (float)(dsp->fHslider12) >= 1.0f;
	int iSlow19 = (float)(dsp->fHslider13) >= 1.0f;
	float fSlow20 = (float)(dsp->fButton0);
	float fSlow21 = (float)(dsp->fHslider14);
	float fSlow22 = (float)(dsp->fHslider15);
	float fSlow23 = dsp->fConst0 * fSlow22;
	float fSlow24 = expf(0.0f - dsp->fConst3 / fSlow22);
	float fSlow25 = expf(0.0f - dsp->fConst3 / fSlow21);
	float fSlow26 = 0.5f * fSlow6;
	float fSlow27 = 0.25f * fSlow6;
	float fSlow28 = dsp->fConst0 * (float)(dsp->fHslider16);
	float fSlow29 = 0.0f - 4.0f * fmaxf(0.0f, fminf(0.1f * (float)(dsp->fHslider17), 0.999999f));
	float fSlow30 = (float)(dsp->fHslider18);
	float fSlow31 = (float)(dsp->fHslider19);
	float fSlow32 = 2.1666667f * (float)(dsp->fHslider20);
	float fSlow33 = 1.0f - fSlow1;
	int iSlow34 = (float)(dsp->fHslider21) >= 1.0f;
	float fSlow35 = powf(2.0f, 0.00083333335f * (float)(dsp->fHslider22));
	float fSlow36 = (float)(dsp->fHslider23);
	int iSlow37 = fSlow36 >= 2.0f;
	int iSlow38 = fSlow36 >= 1.0f;
	float fSlow39 = dsp->fConst0 * (float)(dsp->fHslider24);
	float fSlow40 = 4.656613e-10f * (float)(dsp->fHslider25);
	float fSlow41 = (float)(dsp->fHslider26);
	float fSlow42 = dsp->fConst5 * (float)(dsp->fHslider27);
	float fSlow43 = (float)(dsp->fHslider28);
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec0[0] = 1;
			float fTemp0 = (float)(dsp->iVec0[1]);
			int iTemp1 = 1 - dsp->iVec0[1];
			float fTemp2 = ((iTemp1) ? 0.0f : fSlow16 + dsp->fRec7[1]);
			dsp->fRec7[0] = fTemp2 - floorf(fTemp2);
			float fTemp3 = (float)(dsp->fRec7[0] <= 0.5f);
			dsp->fVec1[0] = fTemp3;
			int iTemp4 = (dsp->fVec1[1] <= 0.0f) & (fTemp3 > 0.0f);
			dsp->iRec9[0] = 1103515245 * dsp->iRec9[1] + 12345;
			float fTemp5 = (float)(dsp->iRec9[0]);
			dsp->fRec8[0] = dsp->fRec8[1] * (float)(1 - iTemp4) + 4.656613e-10f * fTemp5 * (float)(iTemp4);
			float fTemp6 = ((iSlow14) ? dsp->fRec8[0] : ((iSlow15) ? fTemp3 : 2.0f * (1.0f - fabsf(2.0f * dsp->fRec7[0] + -1.0f)) + -1.0f));
			float fTemp7 = fTemp6 + -0.5f;
			float fTemp8 = ((iSlow19) ? fTemp3 : fSlow20);
			dsp->fVec2[0] = fTemp8;
			int iTemp9 = fTemp8 > 0.0f;
			float fTemp10 = 0.1447178f * ((iTemp9) ? fSlow22 : fSlow21);
			int iTemp11 = fabsf(fTemp10) < 1.1920929e-07f;
			float fTemp12 = ((iTemp11) ? 0.0f : expf(0.0f - dsp->fConst2 / ((iTemp11) ? 1.0f : fTemp10)));
			dsp->fRec10[0] = (1.0f - fTemp12) * ((iTemp9) ? (float)(iTemp9) : 0.0f) + fTemp12 * dsp->fRec10[1];
			int iTemp13 = (((fTemp8 > dsp->fVec2[1]) != 0) ? 1 : dsp->iRec11[1] + 1);
			dsp->iRec11[0] = iTemp13;
			dsp->fRec12[0] = (((float)(iTemp13) >= fSlow23) ? fSlow25 * dsp->fRec12[1] : 1.0f - fSlow24 * (1.0f - dsp->fRec12[1]));
			float fTemp14 = ((iSlow18) ? dsp->fRec12[0] : dsp->fRec10[0]);
			dsp->fRec6[0] = fSlow7 * fSlow11 * powf(2.0f, fSlow12 * fTemp7) * powf(2.0f, fSlow17 * fTemp14) + fSlow10 * dsp->fRec6[1];
			float fTemp15 = fSlow6 * dsp->fRec6[0];
			float fTemp16 = fSlow26 * dsp->fRec6[0];
			float fTemp17 = fSlow27 * dsp->fRec6[0];
			float fTemp18 = ((iSlow4) ? fTemp17 : ((iSlow5) ? fTemp16 : fTemp15));
			float fTemp19 = fmaxf(fTemp18, 23.44895f);
			float fTemp20 = fmaxf(2e+01f, fabsf(fTemp19));
			float fTemp21 = ((iTemp1) ? 0.0f : dsp->fRec5[1] + dsp->fConst2 * fTemp20);
			dsp->fRec5[0] = fTemp21 - floorf(fTemp21);
			float fTemp22 = mydsp_faustpower2_f(2.0f * dsp->fRec5[0] + -1.0f);
			dsp->fVec3[0] = fTemp22;
			float fTemp23 = fTemp0 * (fTemp22 - dsp->fVec3[1]) / fTemp20;
			dsp->fVec4[dsp->IOTA0 & 4095] = fTemp23;
			float fTemp24 = fmaxf(0.0f, fminf(2047.0f, fSlow28 / fTemp19));
			int iTemp25 = (int)(fTemp24);
			float fTemp26 = floorf(fTemp24);
			float fTemp27 = dsp->fConst1 * (fTemp23 - dsp->fVec4[(dsp->IOTA0 - iTemp25) & 4095] * (fTemp26 + (1.0f - fTemp24)) - (fTemp24 - fTemp26) * dsp->fVec4[(dsp->IOTA0 - (iTemp25 + 1)) & 4095]);
			float fTemp28 = fmaxf(2e+01f, fabsf(fTemp18));
			float fTemp29 = ((iTemp1) ? 0.0f : dsp->fRec13[1] + dsp->fConst2 * fTemp28);
			dsp->fRec13[0] = fTemp29 - floorf(fTemp29);
			float fTemp30 = mydsp_faustpower2_f(2.0f * dsp->fRec13[0] + -1.0f);
			dsp->fVec5[0] = fTemp30;
			float fTemp31 = dsp->fConst4 * fminf(fmaxf(0.0f, fSlow30 * powf(2.0f, fSlow31 * fTemp7) * powf(2.0f, fSlow32 * fTemp14)), 1.0f);
			float fTemp32 = 1.0f - fTemp31;
			float fTemp33 = fSlow35 * ((iSlow37) ? fTemp17 : ((iSlow38) ? fTemp16 : fTemp15));
			float fTemp34 = fmaxf(fTemp33, 23.44895f);
			float fTemp35 = fmaxf(2e+01f, fabsf(fTemp34));
			float fTemp36 = ((iTemp1) ? 0.0f : dsp->fRec14[1] + dsp->fConst2 * fTemp35);
			dsp->fRec14[0] = fTemp36 - floorf(fTemp36);
			float fTemp37 = mydsp_faustpower2_f(2.0f * dsp->fRec14[0] + -1.0f);
			dsp->fVec6[0] = fTemp37;
			float fTemp38 = fTemp0 * (fTemp37 - dsp->fVec6[1]) / fTemp35;
			dsp->fVec7[dsp->IOTA0 & 4095] = fTemp38;
			float fTemp39 = fmaxf(0.0f, fminf(2047.0f, fSlow39 / fTemp34));
			int iTemp40 = (int)(fTemp39);
			float fTemp41 = floorf(fTemp39);
			float fTemp42 = dsp->fConst1 * (fTemp38 - dsp->fVec7[(dsp->IOTA0 - iTemp40) & 4095] * (fTemp41 + (1.0f - fTemp39)) - (fTemp39 - fTemp41) * dsp->fVec7[(dsp->IOTA0 - (iTemp40 + 1)) & 4095]);
			float fTemp43 = fmaxf(2e+01f, fabsf(fTemp33));
			float fTemp44 = ((iTemp1) ? 0.0f : dsp->fRec15[1] + dsp->fConst2 * fTemp43);
			dsp->fRec15[0] = fTemp44 - floorf(fTemp44);
			float fTemp45 = mydsp_faustpower2_f(2.0f * dsp->fRec15[0] + -1.0f);
			dsp->fVec8[0] = fTemp45;
			dsp->fRec4[0] = fSlow1 * ((iSlow2) ? dsp->fConst1 * (fTemp0 * (fTemp30 - dsp->fVec5[1]) / fTemp28) : fTemp27) + fSlow29 * dsp->fRec0[1] + fTemp32 * dsp->fRec4[1] + fSlow33 * ((iSlow34) ? dsp->fConst1 * (fTemp0 * (fTemp45 - dsp->fVec8[1]) / fTemp43) : fTemp42) + fSlow40 * fTemp5 + fSlow41 * (float)((int)(fTemp27) ^ (int)(fTemp42));
			dsp->fRec3[0] = dsp->fRec4[0] + fTemp32 * dsp->fRec3[1];
			dsp->fRec2[0] = dsp->fRec3[0] + fTemp32 * dsp->fRec2[1];
			dsp->fRec1[0] = dsp->fRec2[0] + dsp->fRec1[1] * fTemp32;
			dsp->fRec0[0] = dsp->fRec1[0] * mydsp_faustpower4_f(fTemp31);
			dsp->fRec16[0] = fSlow42 + dsp->fConst6 * dsp->fRec16[1];
			output0[i0] = (FAUSTFLOAT)(fSlow0 * dsp->fRec0[0] * dsp->fRec16[0] * fTemp14 * (fSlow43 * fTemp6 + 1.0f));
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->fVec1[1] = dsp->fVec1[0];
			dsp->iRec9[1] = dsp->iRec9[0];
			dsp->fRec8[1] = dsp->fRec8[0];
			dsp->fVec2[1] = dsp->fVec2[0];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->iRec11[1] = dsp->iRec11[0];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fVec6[1] = dsp->fVec6[0];
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fVec8[1] = dsp->fVec8[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->fRec3[1] = dsp->fRec3[0];
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec16[1] = dsp->fRec16[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
