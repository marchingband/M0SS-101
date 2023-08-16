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
	FAUSTFLOAT fHslider11;
	float fRec7[2];
	float fVec1[2];
	int iRec9[2];
	float fRec8[2];
	FAUSTFLOAT fHslider12;
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fButton0;
	FAUSTFLOAT fHslider14;
	FAUSTFLOAT fHslider15;
	float fRec10[2];
	float fRec6[2];
	float fRec5[2];
	float fVec2[2];
	int IOTA0;
	float fVec3[4096];
	float fConst3;
	float fRec11[2];
	float fVec4[2];
	FAUSTFLOAT fHslider16;
	float fConst4;
	float fConst5;
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fHslider19;
	float fConst6;
	float fRec12[2];
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fHslider21;
	float fRec13[2];
	float fVec5[2];
	float fVec6[4096];
	float fRec14[2];
	float fVec7[2];
	float fRec4[2];
	float fRec3[2];
	float fRec2[2];
	float fRec1[2];
	float fRec0[2];
	FAUSTFLOAT fHslider22;
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
	dsp->fHslider4 = (FAUSTFLOAT)(2.0f);
	dsp->fHslider5 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider6 = (FAUSTFLOAT)(4e+01f);
	dsp->fHslider7 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider8 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider9 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider10 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider11 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider12 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider13 = (FAUSTFLOAT)(0.0f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider14 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider15 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider16 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider17 = (FAUSTFLOAT)(1e+03f);
	dsp->fHslider18 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider19 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider20 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider21 = (FAUSTFLOAT)(2.0f);
	dsp->fHslider22 = (FAUSTFLOAT)(1.0f);
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
			dsp->fRec10[l5] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->fRec6[l6] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 2; l7 = l7 + 1) {
			dsp->fRec5[l7] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 2; l8 = l8 + 1) {
			dsp->fVec2[l8] = 0.0f;
		}
	}
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 4096; l9 = l9 + 1) {
			dsp->fVec3[l9] = 0.0f;
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
			dsp->fVec4[l11] = 0.0f;
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
		for (l15 = 0; l15 < 4096; l15 = l15 + 1) {
			dsp->fVec6[l15] = 0.0f;
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
			dsp->fVec7[l17] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l18;
		for (l18 = 0; l18 < 2; l18 = l18 + 1) {
			dsp->fRec4[l18] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l19;
		for (l19 = 0; l19 < 2; l19 = l19 + 1) {
			dsp->fRec3[l19] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l20;
		for (l20 = 0; l20 < 2; l20 = l20 + 1) {
			dsp->fRec2[l20] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l21;
		for (l21 = 0; l21 < 2; l21 = l21 + 1) {
			dsp->fRec1[l21] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l22;
		for (l22 = 0; l22 < 2; l22 = l22 + 1) {
			dsp->fRec0[l22] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	float fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 0.25f * fConst0;
	dsp->fConst2 = 1.0f / fConst0;
	dsp->fConst3 = 0.5f * fConst0;
	dsp->fConst4 = 6.2831855f / fConst0;
	dsp->fConst5 = 44.1f / fConst0;
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "sel", "10");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "asr-to-cutoff", &dsp->fHslider19, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "sel", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "asr-to-pitch", &dsp->fHslider12, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "sel", "9");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "asr-to-volume", &dsp->fHslider22, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "midi", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "attack", &dsp->fHslider15, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)5.0f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "midi", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoff", &dsp->fHslider17, (FAUSTFLOAT)1e+03f, (FAUSTFLOAT)2e+01f, (FAUSTFLOAT)8e+03f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "midi", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "detune", &dsp->fHslider3, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)-5e+01f, (FAUSTFLOAT)5e+01f, (FAUSTFLOAT)0.0001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fButton0, "gate", "");
	ui_interface->addButton(ui_interface->uiInterface, "gate", &dsp->fButton0);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "glide", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "glide", &dsp->fHslider7, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.99f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "lfo-depth", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-depth", &dsp->fHslider9, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "midi", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-freq", &dsp->fHslider11, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f, (FAUSTFLOAT)2e+01f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "sel", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-pitch", &dsp->fHslider8, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "sel", "7");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vca", &dsp->fHslider13, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "sel", "6");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-to-vcf", &dsp->fHslider18, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "sel", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "lfo-wavform", &dsp->fHslider10, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "midi", "4");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "mix", &dsp->fHslider1, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider21, "sel", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-oct", &dsp->fHslider21, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "sel", "0");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc1-wavform", &dsp->fHslider20, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "sel", "3");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-oct", &dsp->fHslider4, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "sel", "2");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "osc2-wavform", &dsp->fHslider2, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "pitch-bend", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch-bend", &dsp->fHslider5, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)-1e+02f, (FAUSTFLOAT)1e+02f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "pitch", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "pitch", &dsp->fHslider6, (FAUSTFLOAT)4e+01f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)127.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "midi", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "release", &dsp->fHslider14, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)5.0f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "midi", "6");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "resonance", &dsp->fHslider16, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "midi", "8");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "volume", &dsp->fHslider0, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	float fSlow0 = (float)(dsp->fHslider0);
	float fSlow1 = (float)(dsp->fHslider1);
	float fSlow2 = 1.0f - fSlow1;
	int iSlow3 = (float)(dsp->fHslider2) >= 1.0f;
	float fSlow4 = powf(2.0f, 0.00083333335f * (float)(dsp->fHslider3));
	float fSlow5 = (float)(dsp->fHslider4);
	int iSlow6 = fSlow5 >= 2.0f;
	int iSlow7 = fSlow5 >= 1.0f;
	float fSlow8 = powf(2.0f, 0.00083333335f * (float)(dsp->fHslider5));
	float fSlow9 = 0.25f * fSlow8;
	float fSlow10 = 4.4e+02f * powf(2.0f, 0.083333336f * ((float)(dsp->fHslider6) + -69.0f));
	float fSlow11 = (float)(dsp->fHslider7);
	int iSlow12 = fabsf(fSlow11) < 1.1920929e-07f;
	float fSlow13 = ((iSlow12) ? 0.0f : expf(0.0f - dsp->fConst2 / ((iSlow12) ? 1.0f : fSlow11)));
	float fSlow14 = 1.0f - fSlow13;
	int iSlow15 = (float)(dsp->fHslider8) >= 1.0f;
	float fSlow16 = (float)(dsp->fHslider9);
	float fSlow17 = (float)(dsp->fHslider10);
	int iSlow18 = fSlow17 >= 2.0f;
	int iSlow19 = fSlow17 >= 1.0f;
	float fSlow20 = dsp->fConst2 * (float)(dsp->fHslider11);
	int iSlow21 = (float)(dsp->fHslider12) >= 1.0f;
	int iSlow22 = (float)(dsp->fHslider13) >= 1.0f;
	float fSlow23 = (float)(dsp->fButton0);
	float fSlow24 = (float)(dsp->fHslider14);
	float fSlow25 = (float)(dsp->fHslider15);
	float fSlow26 = 0.5f * fSlow8;
	float fSlow27 = 0.0f - 4.0f * fmaxf(0.0f, fminf((float)(dsp->fHslider16), 0.999999f));
	float fSlow28 = (float)(dsp->fHslider17);
	int iSlow29 = (float)(dsp->fHslider18) >= 1.0f;
	int iSlow30 = (float)(dsp->fHslider19) >= 1.0f;
	int iSlow31 = (float)(dsp->fHslider20) >= 1.0f;
	float fSlow32 = (float)(dsp->fHslider21);
	int iSlow33 = fSlow32 >= 2.0f;
	int iSlow34 = fSlow32 >= 1.0f;
	int iSlow35 = (float)(dsp->fHslider22) >= 1.0f;
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec0[0] = 1;
			float fTemp0 = (float)(dsp->iVec0[1]);
			int iTemp1 = 1 - dsp->iVec0[1];
			float fTemp2 = ((iTemp1) ? 0.0f : fSlow20 + dsp->fRec7[1]);
			dsp->fRec7[0] = fTemp2 - floorf(fTemp2);
			float fTemp3 = (float)(dsp->fRec7[0] <= 0.5f);
			dsp->fVec1[0] = fTemp3;
			int iTemp4 = (dsp->fVec1[1] <= 0.0f) & (fTemp3 > 0.0f);
			dsp->iRec9[0] = 1103515245 * dsp->iRec9[1] + 12345;
			dsp->fRec8[0] = dsp->fRec8[1] * (float)(1 - iTemp4) + 4.656613e-10f * (float)(dsp->iRec9[0]) * (float)(iTemp4);
			float fTemp5 = powf(2.0f, fSlow16 * ((iSlow18) ? dsp->fRec8[0] : ((iSlow19) ? fTemp3 : 2.0f * (1.0f - fabsf(2.0f * dsp->fRec7[0] + -1.0f)) + -1.0f)));
			int iTemp6 = ((iSlow22) ? fTemp3 : fSlow23) > 0.0f;
			float fTemp7 = 0.1447178f * ((iTemp6) ? fSlow25 : fSlow24);
			int iTemp8 = fabsf(fTemp7) < 1.1920929e-07f;
			float fTemp9 = ((iTemp8) ? 0.0f : expf(0.0f - dsp->fConst2 / ((iTemp8) ? 1.0f : fTemp7)));
			dsp->fRec10[0] = (1.0f - fTemp9) * ((iTemp6) ? (float)(iTemp6) : 0.0f) + fTemp9 * dsp->fRec10[1];
			dsp->fRec6[0] = fSlow10 * fSlow14 * ((iSlow15) ? fTemp5 : 1.0f) * ((iSlow21) ? powf(2.0f, 0.083333336f * dsp->fRec10[0]) : 1.0f) + fSlow13 * dsp->fRec6[1];
			float fTemp10 = fSlow9 * dsp->fRec6[0];
			float fTemp11 = fSlow26 * dsp->fRec6[0];
			float fTemp12 = fSlow8 * dsp->fRec6[0];
			float fTemp13 = fSlow4 * ((iSlow6) ? fTemp12 : ((iSlow7) ? fTemp11 : fTemp10));
			float fTemp14 = fmaxf(fTemp13, 23.44895f);
			float fTemp15 = fmaxf(2e+01f, fabsf(fTemp14));
			float fTemp16 = ((iTemp1) ? 0.0f : dsp->fRec5[1] + dsp->fConst2 * fTemp15);
			dsp->fRec5[0] = fTemp16 - floorf(fTemp16);
			float fTemp17 = mydsp_faustpower2_f(2.0f * dsp->fRec5[0] + -1.0f);
			dsp->fVec2[0] = fTemp17;
			float fTemp18 = fTemp0 * (fTemp17 - dsp->fVec2[1]) / fTemp15;
			dsp->fVec3[dsp->IOTA0 & 4095] = fTemp18;
			float fTemp19 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst3 / fTemp14));
			int iTemp20 = (int)(fTemp19);
			float fTemp21 = floorf(fTemp19);
			float fTemp22 = fmaxf(2e+01f, fabsf(fTemp13));
			float fTemp23 = ((iTemp1) ? 0.0f : dsp->fRec11[1] + dsp->fConst2 * fTemp22);
			dsp->fRec11[0] = fTemp23 - floorf(fTemp23);
			float fTemp24 = mydsp_faustpower2_f(2.0f * dsp->fRec11[0] + -1.0f);
			dsp->fVec4[0] = fTemp24;
			dsp->fRec12[0] = dsp->fConst5 * fminf(fmaxf(2e+01f, fSlow28 * ((iSlow29) ? fTemp5 : 1.0f) * ((iSlow30) ? powf(2.0f, 3.0f * dsp->fRec10[0]) : 1.0f)), 6e+03f) + dsp->fConst6 * dsp->fRec12[1];
			float fTemp25 = dsp->fConst4 * dsp->fRec12[0];
			float fTemp26 = 1.0f - fTemp25;
			float fTemp27 = ((iSlow33) ? fTemp12 : ((iSlow34) ? fTemp11 : fTemp10));
			float fTemp28 = fmaxf(fTemp27, 23.44895f);
			float fTemp29 = fmaxf(2e+01f, fabsf(fTemp28));
			float fTemp30 = ((iTemp1) ? 0.0f : dsp->fRec13[1] + dsp->fConst2 * fTemp29);
			dsp->fRec13[0] = fTemp30 - floorf(fTemp30);
			float fTemp31 = mydsp_faustpower2_f(2.0f * dsp->fRec13[0] + -1.0f);
			dsp->fVec5[0] = fTemp31;
			float fTemp32 = fTemp0 * (fTemp31 - dsp->fVec5[1]) / fTemp29;
			dsp->fVec6[dsp->IOTA0 & 4095] = fTemp32;
			float fTemp33 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst3 / fTemp28));
			int iTemp34 = (int)(fTemp33);
			float fTemp35 = floorf(fTemp33);
			float fTemp36 = fmaxf(2e+01f, fabsf(fTemp27));
			float fTemp37 = ((iTemp1) ? 0.0f : dsp->fRec14[1] + dsp->fConst2 * fTemp36);
			dsp->fRec14[0] = fTemp37 - floorf(fTemp37);
			float fTemp38 = mydsp_faustpower2_f(2.0f * dsp->fRec14[0] + -1.0f);
			dsp->fVec7[0] = fTemp38;
			dsp->fRec4[0] = fSlow2 * ((iSlow3) ? dsp->fConst1 * (fTemp0 * (fTemp24 - dsp->fVec4[1]) / fTemp22) : 0.0f - dsp->fConst1 * (dsp->fVec3[(dsp->IOTA0 - iTemp20) & 4095] * (fTemp21 + (1.0f - fTemp19)) - fTemp18 + (fTemp19 - fTemp21) * dsp->fVec3[(dsp->IOTA0 - (iTemp20 + 1)) & 4095])) + fSlow27 * dsp->fRec0[1] + fTemp26 * dsp->fRec4[1] + fSlow1 * ((iSlow31) ? dsp->fConst1 * (fTemp0 * (fTemp38 - dsp->fVec7[1]) / fTemp36) : dsp->fConst1 * (fTemp32 - dsp->fVec6[(dsp->IOTA0 - iTemp34) & 4095] * (fTemp35 + (1.0f - fTemp33)) - (fTemp33 - fTemp35) * dsp->fVec6[(dsp->IOTA0 - (iTemp34 + 1)) & 4095]));
			dsp->fRec3[0] = dsp->fRec4[0] + fTemp26 * dsp->fRec3[1];
			dsp->fRec2[0] = dsp->fRec3[0] + fTemp26 * dsp->fRec2[1];
			dsp->fRec1[0] = dsp->fRec2[0] + dsp->fRec1[1] * fTemp26;
			dsp->fRec0[0] = dsp->fRec1[0] * mydsp_faustpower4_f(fTemp25);
			output0[i0] = (FAUSTFLOAT)(fSlow0 * dsp->fRec0[0] * ((iSlow35) ? dsp->fRec10[0] : 1.0f));
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->fVec1[1] = dsp->fVec1[0];
			dsp->iRec9[1] = dsp->iRec9[0];
			dsp->fRec8[1] = dsp->fRec8[0];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fVec2[1] = dsp->fVec2[0];
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec11[1] = dsp->fRec11[0];
			dsp->fVec4[1] = dsp->fVec4[0];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fVec7[1] = dsp->fVec7[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->fRec3[1] = dsp->fRec3[0];
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->fRec0[1] = dsp->fRec0[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
