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
	float fRec3[2];
	float fVec1[2];
	float fVec2[2];
	int iRec4[2];
	int iRec1[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	int iVec3[2];
	float fRec5[2];
	float fRec2[2];
	int iRec6[2];
	float fConst4;
	float fRec7[2];
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider7;
	float fConst5;
	float fConst6;
	float fConst7;
	FAUSTFLOAT fHslider8;
	float fRec12[2];
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	int iRec14[2];
	float fRec13[2];
	FAUSTFLOAT fVbargraph1;
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fHslider12;
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	float fConst8;
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fHslider19;
	float fRec16[2];
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fHslider21;
	FAUSTFLOAT fHslider22;
	float fRec17[2];
	float fRec15[2];
	float fVec4[2];
	int IOTA0;
	float fVec5[4096];
	FAUSTFLOAT fHslider23;
	float fRec18[2];
	float fRec19[2];
	float fVec6[2];
	FAUSTFLOAT fHslider24;
	FAUSTFLOAT fHslider25;
	FAUSTFLOAT fHslider26;
	float fRec20[2];
	float fVec7[2];
	float fVec8[4096];
	FAUSTFLOAT fHslider27;
	float fRec21[2];
	float fRec22[2];
	float fVec9[2];
	FAUSTFLOAT fHslider28;
	float fRec23[2];
	FAUSTFLOAT fHslider29;
	float fRec24[2];
	float fRec8[2];
	float fRec10[2];
	float fRec11[2];
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
	m->declare(m->metaInterface, "aanl.lib/name", "Faust Antialiased Nonlinearities");
	m->declare(m->metaInterface, "aanl.lib/version", "0.3");
	m->declare(m->metaInterface, "basics.lib/name", "Faust Basic Element Library");
	m->declare(m->metaInterface, "basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
	m->declare(m->metaInterface, "basics.lib/version", "0.10");
	m->declare(m->metaInterface, "compile_options", "-lang c -ct 1 -es 1 -mcd 16 -single -ftz 0");
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
	dsp->fHslider5 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider6 = (FAUSTFLOAT)(0.001f);
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
			dsp->fRec3[l2] = 0.0f;
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
			dsp->iRec4[l5] = 0;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->iRec1[l6] = 0;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 2; l7 = l7 + 1) {
			dsp->iVec3[l7] = 0;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 2; l8 = l8 + 1) {
			dsp->fRec5[l8] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 2; l9 = l9 + 1) {
			dsp->fRec2[l9] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 2; l10 = l10 + 1) {
			dsp->iRec6[l10] = 0;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 2; l11 = l11 + 1) {
			dsp->fRec7[l11] = 0.0f;
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
			dsp->iRec14[l13] = 0;
		}
	}
	/* C99 loop */
	{
		int l14;
		for (l14 = 0; l14 < 2; l14 = l14 + 1) {
			dsp->fRec13[l14] = 0.0f;
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
			dsp->fRec17[l16] = 0.0f;
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
			dsp->fVec4[l18] = 0.0f;
		}
	}
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l19;
		for (l19 = 0; l19 < 4096; l19 = l19 + 1) {
			dsp->fVec5[l19] = 0.0f;
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
			dsp->fRec19[l21] = 0.0f;
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
		for (l25 = 0; l25 < 4096; l25 = l25 + 1) {
			dsp->fVec8[l25] = 0.0f;
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
			dsp->fRec22[l27] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l28;
		for (l28 = 0; l28 < 2; l28 = l28 + 1) {
			dsp->fVec9[l28] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l29;
		for (l29 = 0; l29 < 2; l29 = l29 + 1) {
			dsp->fRec23[l29] = 0.0f;
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
			dsp->fRec8[l31] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l32;
		for (l32 = 0; l32 < 2; l32 = l32 + 1) {
			dsp->fRec10[l32] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l33;
		for (l33 = 0; l33 < 2; l33 = l33 + 1) {
			dsp->fRec11[l33] = 0.0f;
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
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 44.1f / dsp->fConst0;
	dsp->fConst2 = 1.0f - dsp->fConst1;
	dsp->fConst3 = 1.0f / dsp->fConst0;
	dsp->fConst4 = 6.9077554f / dsp->fConst0;
	dsp->fConst5 = 6.2831855f / dsp->fConst0;
	dsp->fConst6 = expf(0.0f - 2e+01f / dsp->fConst0);
	dsp->fConst7 = 1.0f - dsp->fConst6;
	dsp->fConst8 = 0.25f * dsp->fConst0;
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "midi", "1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "attack", &dsp->fHslider5, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "midi", "5");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "release", &dsp->fHslider6, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0001f);
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
	float fSlow6 = 20.019018f * (mydsp_faustpower3_f((float)(dsp->fHslider5)) + -0.001f) + 0.001f;
	float fSlow7 = dsp->fConst0 * fSlow6;
	float fSlow8 = 1.0f / fmaxf(1.0f, fSlow7);
	float fSlow9 = 20.019018f * (mydsp_faustpower2_f((float)(dsp->fHslider6)) + -0.001f) + 0.001f;
	float fSlow10 = 1.0f / fmaxf(1.0f, dsp->fConst0 * fSlow9);
	float fSlow11 = expf(0.0f - dsp->fConst4 / fSlow6);
	float fSlow12 = expf(0.0f - dsp->fConst4 / fSlow9);
	float fSlow13 = (float)(dsp->fHslider7);
	int iSlow14 = fSlow13 >= 2.0f;
	int iSlow15 = fSlow13 >= 1.0f;
	float fSlow16 = dsp->fConst7 * mydsp_faustpower2_f((float)(dsp->fHslider8));
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
			float fTemp1 = ((iTemp0) ? 0.0f : fSlow5 + dsp->fRec3[1]);
			dsp->fRec3[0] = fTemp1 - floorf(fTemp1);
			float fTemp2 = (float)(dsp->fRec3[0] <= 0.5f);
			dsp->fVec1[0] = fTemp2;
			float fTemp3 = ((iSlow3) ? fTemp2 : fSlow4);
			dsp->fVec2[0] = fTemp3;
			int iTemp4 = dsp->iRec1[1] == 0;
			int iTemp5 = dsp->iRec1[1] == 1;
			dsp->iRec4[0] = dsp->iRec4[1] + 1;
			int iTemp6 = (dsp->iRec4[0] + -1) == 0;
			float fTemp7 = ((iTemp6) ? 0.0f : dsp->fRec2[1]);
			dsp->iRec1[0] = ((fTemp3 > 0.0f) ? ((iTemp4) ? 1 : ((iTemp5) ? ((fTemp7 < 1.0f) ? 1 : 2) : 2)) : 0);
			float fTemp8 = (float)(((dsp->iRec1[1] == 2) ? 1 : 0));
			int iTemp9 = fTemp3 == 0.0f;
			dsp->iVec3[0] = iTemp9;
			int iTemp10 = (dsp->iVec3[1] <= 0) & (iTemp9 > 0);
			dsp->fRec5[0] = dsp->fRec5[1] * (float)(1 - iTemp10) + ((iTemp6) ? 1.0f : fTemp7) * (float)(iTemp10);
			float fTemp11 = ((iTemp4) ? dsp->fRec5[0] : 1.0f);
			float fTemp12 = ((fTemp8 == fTemp11) ? 0.5f : (fTemp7 - fTemp8) / (fTemp11 - fTemp8));
			float fTemp13 = (0.0f - 0.3f * fTemp12) / (0.4f * fTemp12 + -0.7f);
			dsp->fRec2[0] = fmaxf(fTemp8, fminf(1.0f, fTemp7 - ((iTemp4) ? 0.0f - fSlow10 * dsp->fRec5[0] : ((iTemp5) ? fSlow8 : 0.0f)) * (0.0f - 0.21f / mydsp_faustpower2_f(0.7f * (2.0f * fTemp13 + -1.0f) + (1.0f - fTemp13)))));
			int iTemp14 = (((fTemp3 > dsp->fVec2[1]) != 0) ? 1 : dsp->iRec6[1] + 1);
			dsp->iRec6[0] = iTemp14;
			dsp->fRec7[0] = (((float)(iTemp14) >= fSlow7) ? fSlow12 * dsp->fRec7[1] : 1.0f - fSlow11 * (1.0f - dsp->fRec7[1]));
			float fTemp15 = ((iSlow2) ? dsp->fRec7[0] : dsp->fRec2[0]);
			dsp->fVbargraph0 = (FAUSTFLOAT)(fTemp15);
			float fTemp16 = fTemp15;
			dsp->fRec12[0] = fSlow16 + dsp->fConst6 * dsp->fRec12[1];
			int iTemp17 = (dsp->fVec1[1] <= 0.0f) & (fTemp2 > 0.0f);
			dsp->iRec14[0] = 1103515245 * dsp->iRec14[1] + 12345;
			float fTemp18 = (float)(dsp->iRec14[0]);
			dsp->fRec13[0] = dsp->fRec13[1] * (float)(1 - iTemp17) + 4.656613e-10f * fTemp18 * (float)(iTemp17);
			float fTemp19 = ((iSlow19) ? dsp->fRec13[0] : ((iSlow20) ? fTemp2 : 2.0f * (1.0f - fabsf(2.0f * dsp->fRec3[0] + -1.0f)) + -1.0f));
			dsp->fVbargraph1 = (FAUSTFLOAT)(fTemp19);
			float fTemp20 = fTemp19;
			float fTemp21 = fTemp20 + -0.5f;
			float fTemp22 = fminf(fmaxf(0.0f, dsp->fRec12[0] * powf(2.0f, fSlow17 * fTemp21) * powf(2.0f, fSlow21 * fTemp16)), 1.0f);
			float fTemp23 = tanf(dsp->fConst5 * powf(1e+01f, 3.0f * fTemp22 + 1.0f));
			float fTemp24 = (float)(dsp->iVec0[1]);
			dsp->fRec16[0] = fSlow32 * fSlow36 * powf(2.0f, fSlow37 * fTemp21) * powf(2.0f, fSlow38 * fTemp16) + fSlow35 * dsp->fRec16[1];
			dsp->fRec17[0] = fSlow40 + dsp->fConst2 * dsp->fRec17[1];
			float fTemp25 = dsp->fRec16[0] * dsp->fRec17[0];
			float fTemp26 = 0.5f * fTemp25;
			float fTemp27 = 0.25f * fTemp25;
			float fTemp28 = ((iSlow30) ? fTemp27 : ((iSlow31) ? fTemp26 : fTemp25));
			float fTemp29 = fmaxf(fTemp28, 23.44895f);
			float fTemp30 = fmaxf(2e+01f, fabsf(fTemp29));
			float fTemp31 = ((iTemp0) ? 0.0f : dsp->fRec15[1] + dsp->fConst3 * fTemp30);
			dsp->fRec15[0] = fTemp31 - floorf(fTemp31);
			float fTemp32 = mydsp_faustpower2_f(2.0f * dsp->fRec15[0] + -1.0f);
			dsp->fVec4[0] = fTemp32;
			float fTemp33 = fTemp24 * (fTemp32 - dsp->fVec4[1]) / fTemp30;
			dsp->fVec5[dsp->IOTA0 & 4095] = fTemp33;
			dsp->fRec18[0] = fSlow41 + dsp->fConst2 * dsp->fRec18[1];
			float fTemp34 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst0 * (dsp->fRec18[0] / fTemp29)));
			int iTemp35 = (int)(fTemp34);
			float fTemp36 = floorf(fTemp34);
			float fTemp37 = fTemp33 - dsp->fVec5[(dsp->IOTA0 - iTemp35) & 4095] * (fTemp36 + (1.0f - fTemp34)) - (fTemp34 - fTemp36) * dsp->fVec5[(dsp->IOTA0 - (iTemp35 + 1)) & 4095];
			float fTemp38 = dsp->fConst8 * fTemp37;
			float fTemp39 = fmaxf(2e+01f, fabsf(fTemp28));
			float fTemp40 = ((iTemp0) ? 0.0f : dsp->fRec19[1] + dsp->fConst3 * fTemp39);
			dsp->fRec19[0] = fTemp40 - floorf(fTemp40);
			float fTemp41 = mydsp_faustpower2_f(2.0f * dsp->fRec19[0] + -1.0f);
			dsp->fVec6[0] = fTemp41;
			float fTemp42 = fTemp24 * (fTemp41 - dsp->fVec6[1]) / fTemp39;
			float fTemp43 = fSlow46 * ((iSlow48) ? fTemp27 : ((iSlow49) ? fTemp26 : fTemp25));
			float fTemp44 = fmaxf(fTemp43, 23.44895f);
			float fTemp45 = fmaxf(2e+01f, fabsf(fTemp44));
			float fTemp46 = ((iTemp0) ? 0.0f : dsp->fRec20[1] + dsp->fConst3 * fTemp45);
			dsp->fRec20[0] = fTemp46 - floorf(fTemp46);
			float fTemp47 = mydsp_faustpower2_f(2.0f * dsp->fRec20[0] + -1.0f);
			dsp->fVec7[0] = fTemp47;
			float fTemp48 = fTemp24 * (fTemp47 - dsp->fVec7[1]) / fTemp45;
			dsp->fVec8[dsp->IOTA0 & 4095] = fTemp48;
			dsp->fRec21[0] = fSlow50 + dsp->fConst2 * dsp->fRec21[1];
			float fTemp49 = fmaxf(0.0f, fminf(2047.0f, dsp->fConst0 * (dsp->fRec21[0] / fTemp44)));
			int iTemp50 = (int)(fTemp49);
			float fTemp51 = floorf(fTemp49);
			float fTemp52 = fTemp48 - dsp->fVec8[(dsp->IOTA0 - iTemp50) & 4095] * (fTemp51 + (1.0f - fTemp49)) - (fTemp49 - fTemp51) * dsp->fVec8[(dsp->IOTA0 - (iTemp50 + 1)) & 4095];
			float fTemp53 = dsp->fConst8 * fTemp52;
			float fTemp54 = fmaxf(2e+01f, fabsf(fTemp43));
			float fTemp55 = ((iTemp0) ? 0.0f : dsp->fRec22[1] + dsp->fConst3 * fTemp54);
			dsp->fRec22[0] = fTemp55 - floorf(fTemp55);
			float fTemp56 = mydsp_faustpower2_f(2.0f * dsp->fRec22[0] + -1.0f);
			dsp->fVec9[0] = fTemp56;
			float fTemp57 = fTemp24 * (fTemp56 - dsp->fVec9[1]) / fTemp54;
			dsp->fRec23[0] = fSlow51 + dsp->fConst2 * dsp->fRec23[1];
			dsp->fRec24[0] = fSlow52 + dsp->fConst2 * dsp->fRec24[1];
			float fTemp58 = fSlow25 * ((iSlow27) ? dsp->fConst8 * (fTemp37 + fTemp42) : ((iSlow28) ? dsp->fConst8 * fTemp42 : fTemp38)) + fSlow42 * ((iSlow44) ? dsp->fConst8 * (fTemp52 + fTemp57) : ((iSlow45) ? dsp->fConst8 * fTemp57 : fTemp53)) + 4.656613e-10f * dsp->fRec23[0] * fTemp18 + dsp->fRec24[0] * (float)((int)(fTemp38) ^ (int)(fTemp53));
			float fTemp59 = (fTemp58 - dsp->fRec11[1]) * fTemp23;
			float fTemp60 = fTemp23 + 1.0f;
			float fTemp61 = fTemp23 / fTemp60;
			float fTemp62 = (fTemp58 - (dsp->fRec11[1] + (fTemp59 - dsp->fRec8[1] - dsp->fRec10[1] * (0.0f - fTemp61)) / fTemp60)) / (1.0f - fSlow24 * (fTemp23 * (1.0f - fTemp61) / fTemp60));
			float fTemp63 = fSlow24 * fTemp62;
			float fTemp64 = fTemp23 * (fTemp63 - dsp->fRec10[1]) / fTemp60;
			dsp->fRec8[0] = dsp->fRec8[1] + 2.0f * (fTemp23 * (fTemp63 - (fTemp64 + dsp->fRec8[1] + dsp->fRec10[1])) / fTemp60);
			float fRec9 = fTemp62;
			dsp->fRec10[0] = dsp->fRec10[1] + 2.0f * fTemp64;
			dsp->fRec11[0] = dsp->fRec11[1] + 2.0f * (fTemp59 / fTemp60);
			float fTemp65 = tanf(0.0035699916f * fTemp25 * fTemp22);
			float fTemp66 = fTemp65 + 1.0f;
			float fTemp67 = fTemp65 * ((fTemp58 - fSlow53 * (1.0f - fTemp65 / fTemp66) * (dsp->fRec28[1] + fTemp65 * (dsp->fRec27[1] + fTemp65 * (dsp->fRec26[1] + fTemp65 * dsp->fRec25[1] / fTemp66) / fTemp66) / fTemp66)) / (fSlow53 * (mydsp_faustpower4_f(fTemp65) / mydsp_faustpower4_f(fTemp66)) + 1.0f) - dsp->fRec25[1]) / fTemp66;
			dsp->fRec25[0] = dsp->fRec25[1] + 2.0f * fTemp67;
			float fTemp68 = fTemp65 * (dsp->fRec25[1] + fTemp67 - dsp->fRec26[1]) / fTemp66;
			dsp->fRec26[0] = dsp->fRec26[1] + 2.0f * fTemp68;
			float fTemp69 = fTemp65 * (dsp->fRec26[1] + fTemp68 - dsp->fRec27[1]) / fTemp66;
			dsp->fRec27[0] = dsp->fRec27[1] + 2.0f * fTemp69;
			float fTemp70 = fTemp65 * (dsp->fRec27[1] + fTemp69 - dsp->fRec28[1]) / fTemp66;
			dsp->fRec28[0] = dsp->fRec28[1] + 2.0f * fTemp70;
			float fRec29 = dsp->fRec28[1] + fTemp70;
			float fTemp71 = fSlow54 + fTemp23;
			float fTemp72 = fTemp58 - (dsp->fRec31[1] + dsp->fRec32[1] * fTemp71);
			float fTemp73 = fTemp23 * fTemp71 + 1.0f;
			float fTemp74 = fTemp23 * fTemp72 / fTemp73;
			float fTemp75 = fmaxf(-1.0f, fminf(1.0f, dsp->fRec32[1] + fTemp74));
			float fTemp76 = 1.0f - 0.33333334f * mydsp_faustpower2_f(fTemp75);
			float fTemp77 = fTemp75 * fTemp76;
			float fRec30 = fTemp77;
			float fTemp78 = fTemp23 * fTemp75 * fTemp76;
			dsp->fRec31[0] = dsp->fRec31[1] + 2.0f * fTemp78;
			dsp->fRec32[0] = fTemp74 + fTemp77;
			output0[i0] = (FAUSTFLOAT)(fSlow0 * dsp->fRec0[0] * fTemp16 * ((iSlow14) ? fRec30 : ((iSlow15) ? fRec29 : fRec9)) * (fSlow55 * fTemp20 + 1.0f));
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec3[1] = dsp->fRec3[0];
			dsp->fVec1[1] = dsp->fVec1[0];
			dsp->fVec2[1] = dsp->fVec2[0];
			dsp->iRec4[1] = dsp->iRec4[0];
			dsp->iRec1[1] = dsp->iRec1[0];
			dsp->iVec3[1] = dsp->iVec3[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->iRec6[1] = dsp->iRec6[0];
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->iRec14[1] = dsp->iRec14[0];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fRec16[1] = dsp->fRec16[0];
			dsp->fRec17[1] = dsp->fRec17[0];
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fVec4[1] = dsp->fVec4[0];
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec18[1] = dsp->fRec18[0];
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fVec6[1] = dsp->fVec6[0];
			dsp->fRec20[1] = dsp->fRec20[0];
			dsp->fVec7[1] = dsp->fVec7[0];
			dsp->fRec21[1] = dsp->fRec21[0];
			dsp->fRec22[1] = dsp->fRec22[0];
			dsp->fVec9[1] = dsp->fVec9[0];
			dsp->fRec23[1] = dsp->fRec23[0];
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fRec8[1] = dsp->fRec8[0];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->fRec11[1] = dsp->fRec11[0];
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
