#ifndef _GC0309B_CFG_H_
#define _GC0309B_CFG_H_

#include "rda_sensor.h"
#include <linux/delay.h>

#ifdef BIT
#undef BIT
#endif
#define BIT	8

static struct sensor_reg exp_gc0309b[][3] =
{
	{{0xfe,0x00,BIT,0},{0xb5,0xd0,BIT,0},{0xd3,0x38,BIT,0}},
	{{0xfe,0x00,BIT,0},{0xb5,0xe0,BIT,0},{0xd3,0x40,BIT,0}},
	{{0xfe,0x00,BIT,0},{0xb5,0xf0,BIT,0},{0xd3,0x48,BIT,0}},
	{{0xfe,0x00,BIT,0},{0xb5,0x00,BIT,0},{0xd3,0x50,BIT,0}},
	{{0xfe,0x00,BIT,0},{0xb5,0x10,BIT,0},{0xd3,0x58,BIT,0}},
	{{0xfe,0x00,BIT,0},{0xb5,0x20,BIT,0},{0xd3,0x60,BIT,0}},
	{{0xfe,0x00,BIT,0},{0xb5,0x30,BIT,0},{0xd3,0x68,BIT,0}},
};

static struct sensor_reg awb_gc0309b[][4] =
{
	{{0x22,0x55,BIT,0},{0x5a,0x4c,BIT,0},{0x5b,0x40,BIT,0},{0x5c,0x4a,BIT,0}},//OFF
	{{0x22,0x57,BIT,0},{0x5a,0x4c,BIT,0},{0x5b,0x40,BIT,0},{0x5c,0x4a,BIT,0}},//AUTO
	{{0x22,0x55,BIT,0},{0x5a,0x48,BIT,0},{0x5b,0x40,BIT,0},{0x5c,0x5c,BIT,0}},//INCANDESCENT
	{{0x22,0x55,BIT,0},{0x5a,0x40,BIT,0},{0x5b,0x42,BIT,0},{0x5c,0x50,BIT,0}},//FLUORESCENT
	{{0x22,0x55,BIT,0},{0x5a,0x40,BIT,0},{0x5b,0x54,BIT,0},{0x5c,0x70,BIT,0}},//TUNGSTEN
	{{0x22,0x55,BIT,0},{0x5a,0x74,BIT,0},{0x5b,0x52,BIT,0},{0x5c,0x40,BIT,0}},//DAYLIGHT
	{{0x22,0x55,BIT,0},{0x5a,0x8c,BIT,0},{0x5b,0x50,BIT,0},{0x5c,0x40,BIT,0}},//CLOUD
};

// use this for 640x480 (VGA) capture
static struct sensor_reg vga_gc0309b[] =
{
	{0xf7,0x04,BIT,0},
	{0xf8,0x02,BIT,0},
	{0xf9,0x9f,BIT,0},
	{0xfa,0x78,BIT,0},

	{0x46,0x00,BIT,0},

	{0xfe,0x01,BIT,0},
	{0x54,0x11,BIT,0},
	{0xfe,0x00,BIT,0},
};

// use this for 320x240 (QVGA) capture
static struct sensor_reg qvga_gc0309b[] =
{
	{0xf7,0x04,BIT,0},
	{0xf8,0x02,BIT,0},
	{0xf9,0x9f,BIT,0},
	{0xfa,0x78,BIT,0},

	{0x46,0x00,BIT,0},

	{0xfe,0x01,BIT,0},
	{0x54,0x22,BIT,0},
	{0xfe,0x00,BIT,0},
};

// use this for 160x120 (QQVGA) capture
static struct sensor_reg qqvga_gc0309b[] =
{
	{0xf7,0x04,BIT,0},
	{0xf8,0x02,BIT,0},
	{0xf9,0x9f,BIT,0},
	{0xfa,0x78,BIT,0},

	{0x46,0x00,BIT,0},

	{0xfe,0x01,BIT,0},
	{0x54,0x44,BIT,0},
	{0xfe,0x00,BIT,0},
};

// use this for 176x144 (QCIF) capture
static struct sensor_reg qcif_gc0309b[] =
{
	{0xf7,0x04,BIT,0},
	{0xf8,0x02,BIT,0},
	{0xf9,0x9f,BIT,0},
	{0xfa,0x78,BIT,0},

	{0x46,0x80,BIT,0},
	{0x49,0x00,BIT,0},
	{0x4a,0x90,BIT,0},
	{0x4b,0x00,BIT,0},
	{0x4c,0xb0,BIT,0},

	{0xfe,0x01,BIT,0},
	{0x54,0x33,BIT,0},
	{0xfe,0x00,BIT,0},
};

// use this for init sensor
static struct sensor_reg init_gc0309b[] =
{
	{0xfe,0x80,BIT,0},
	{0xfe,0x00,BIT,0},	// set page0

	{0x1a,0x16,BIT,0},
	{0xd2,0x10,BIT,0},	// close AEC
	{0x22,0x55,BIT,0},	// close AWB

	{0x5a,0x56,BIT,0},
	{0x5b,0x40,BIT,0},
	{0x5c,0x4a,BIT,0},

	{0x22,0x57,BIT,0},

#if 0//fix 14.3
	{0x01,0xfa,BIT,0},
	{0x02,0xd4,BIT,0},
	{0x0f,0x01,BIT,0},

	{0x03,0x01,BIT,0},
	{0x04,0x90,BIT,0},

	{0xe2,0x00,BIT,0},
	{0xe3,0x64,BIT,0},

	{0xe4,0x02,BIT,0},
	{0xe5,0xbc,BIT,0},
	{0xe6,0x02,BIT,0},
	{0xe7,0xbc,BIT,0},
	{0xe8,0x02,BIT,0},
	{0xe9,0xbc,BIT,0},
	{0xea,0x09,BIT,0},
	{0xeb,0xc4,BIT,0},
#elif 0 //mclk =13MHZ fps =8.3
	{0x01,0x2c,BIT,0},
	{0x02,0x88,BIT,0},
	{0x0f,0x02,BIT,0},

	{0x03,0x00,BIT,0},
	{0x04,0x9c,BIT,0},

	{0xe2,0x00,BIT,0},
	{0xe3,0x34,BIT,0},

	{0xe4,0x02,BIT,0},
	{0xe5,0x70,BIT,0},
	{0xe6,0x02,BIT,0},
	{0xe7,0x70,BIT,0},
	{0xe8,0x02,BIT,0},
	{0xe9,0x70,BIT,0},
	{0xea,0x04,BIT,0},
	{0xeb,0x10,BIT,0},
#else //mclk =26MHZ fps =16.6--7.2
	{0x01,0x2c,BIT,0},
	{0x02,0xac,BIT,0},
	{0x0f,0x02,BIT,0},

	{0x03,0x01,BIT,0},
	{0x04,0x38,BIT,0},

	{0xe2,0x00,BIT,0},
	{0xe3,0x84,BIT,0},
	{0xe4,0x02,BIT,0},
	{0xe5,0x94,BIT,0},
	{0xe6,0x03,BIT,0},
	{0xe7,0x18,BIT,0},
	{0xe8,0x04,BIT,0},
	{0xe9,0x20,BIT,0},
	{0xea,0x08,BIT,0},
	{0xeb,0x40,BIT,0},
#endif
	{0x05,0x00,BIT,0},
	{0x06,0x00,BIT,0},
	{0x07,0x00,BIT,0},
	{0x08,0x00,BIT,0},
	{0x09,0x01,BIT,0},
	{0x0a,0xe8,BIT,0},
	{0x0b,0x02,BIT,0},
	{0x0c,0x88,BIT,0},
	{0x0d,0x02,BIT,0},
	{0x0e,0x02,BIT,0},
	{0x10,0x22,BIT,0},
	{0x11,0x0d,BIT,0},
	{0x12,0x2a,BIT,0},
	{0x13,0x00,BIT,0},
	{0x15,0x0a,BIT,0},
	{0x16,0x05,BIT,0},
	{0x17,0x01,BIT,0},

	{0x1b,0x03,BIT,0},
	{0x1c,0xc1,BIT,0},
	{0x1d,0x08,BIT,0},
	{0x1e,0x20,BIT,0},
	{0x1f,0x16,BIT,0},

	{0x20,0xff,BIT,0},
	{0x21,0xf8,BIT,0},
	{0x24,0xa2,BIT,0},
	{0x25,0x0f,BIT,0},
	//output sync_mode
	{0x26,0x03,BIT,0},
	{0x2f,0x01,BIT,0},
	/////////////////////////////////////////////////////////////////////
	/////////////////////////// grab_t ////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x30,0xf7,BIT,0},
	{0x31,0x40,BIT,0},
	{0x32,0x00,BIT,0},
	{0x39,0x04,BIT,0},
	{0x3a,0x20,BIT,0},
	{0x3b,0x20,BIT,0},
	{0x3c,0x02,BIT,0},
	{0x3d,0x02,BIT,0},
	{0x3e,0x02,BIT,0},
	{0x3f,0x02,BIT,0},

	//gain
	{0x50,0x24,BIT,0},

	{0x53,0x80,BIT,0},
	{0x54,0x80,BIT,0},
	{0x55,0x80,BIT,0},
	{0x56,0x80,BIT,0},

	/////////////////////////////////////////////////////////////////////
	/////////////////////////// LSC_t ////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x8b,0x20,BIT,0},
	{0x8c,0x20,BIT,0},
	{0x8d,0x20,BIT,0},
	{0x8e,0x10,BIT,0},
	{0x8f,0x10,BIT,0},
	{0x90,0x10,BIT,0},
	{0x91,0x3c,BIT,0},
	{0x92,0x50,BIT,0},
	{0x5d,0x12,BIT,0},
	{0x5e,0x1a,BIT,0},
	{0x5f,0x24,BIT,0},
	/////////////////////////////////////////////////////////////////////
	/////////////////////////// DNDD_t ///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x60,0x07,BIT,0},
	{0x61,0x0e,BIT,0},
	{0x62,0x0f,BIT,0}, //0x0c
	{0x64,0x03,BIT,0},
	{0x66,0xe8,BIT,0},
	{0x67,0x86,BIT,0},
	{0x68,0xa2,BIT,0},

	/////////////////////////////////////////////////////////////////////
	/////////////////////////// asde_t ///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x69,0x20,BIT,0},
	{0x6a,0x0f,BIT,0},
	{0x6b,0x00,BIT,0},
	{0x6c,0x53,BIT,0},
	{0x6d,0x83,BIT,0},
	{0x6e,0xac,BIT,0},
	{0x6f,0xac,BIT,0},
	{0x70,0x15,BIT,0},
	{0x71,0x33,BIT,0},
	/////////////////////////////////////////////////////////////////////
	/////////////////////////// eeintp_t///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x72,0xdc,BIT,0},
	{0x73,0x80,BIT,0},
	//for high resolution in light scene
	{0x74,0x02,BIT,0},
	{0x75,0x3f,BIT,0},
	{0x76,0x02,BIT,0},
	{0x77,0x54,BIT,0},
	{0x78,0x88,BIT,0},
	{0x79,0x81,BIT,0},
	{0x7a,0x81,BIT,0},
	{0x7b,0x22,BIT,0},
	{0x7c,0xff,BIT,0},

	/////////////////////////////////////////////////////////////////////
	///////////////////////////CC_t///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0x93,0x48,BIT,0},
	{0x94,0x00,BIT,0},
	{0x95,0x05,BIT,0},
	{0x96,0xe8,BIT,0},
	{0x97,0x40,BIT,0},
	{0x98,0xf8,BIT,0},
	{0x9c,0x00,BIT,0},
	{0x9d,0x00,BIT,0},
	{0x9e,0x00,BIT,0},

	/////////////////////////////////////////////////////////////////////
	///////////////////////////YCP_t///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0xb1,0x42,BIT,0},
	{0xb2,0x42,BIT,0},
	{0xb8,0x20,BIT,0},
	{0xbe,0x36,BIT,0},
	{0xbf,0x00,BIT,0},
	/////////////////////////////////////////////////////////////////////
	///////////////////////////AEC_t///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	{0xd0,0xcb,BIT,0},
	{0xd1,0x10,BIT,0},

	{0xd3,0x50,BIT,0},
	{0xd5,0xf2,BIT,0},
	{0xd6,0x16,BIT,0},
	{0xdb,0x92,BIT,0},
	{0xdc,0xa5,BIT,0},
	{0xdf,0x23,BIT,0},
	{0xd9,0x00,BIT,0},
	{0xda,0x00,BIT,0},
	{0xe0,0x09,BIT,0},

	{0xec,0x20,BIT,0},
	{0xed,0x04,BIT,0},
	{0xee,0xa0,BIT,0},
	{0xef,0x40,BIT,0},
	///////////////////////////////////////////////////////////////////
	///////////////////////////GAMMA//////////////////////////////////
	///////////////////////////////////////////////////////////////////
	// for FAE to choose the gamma curve according to different LCD
	{0x9F,0x0e,BIT,0},	//gamma curve lvl2
	{0xA0,0x1c,BIT,0},
	{0xA1,0x34,BIT,0},
	{0xA2,0x48,BIT,0},
	{0xA3,0x5a,BIT,0},
	{0xA4,0x6b,BIT,0},
	{0xA5,0x7b,BIT,0},
	{0xA6,0x95,BIT,0},
	{0xA7,0xab,BIT,0},
	{0xA8,0xbf,BIT,0},
	{0xA9,0xce,BIT,0},
	{0xAA,0xd9,BIT,0},
	{0xAB,0xe4,BIT,0},
	{0xAC,0xec,BIT,0},
	{0xAD,0xf7,BIT,0},
	{0xAE,0xfd,BIT,0},
	{0xAF,0xff,BIT,0},

#if 0
	{0x9F,0x10,BIT,0},	// gamma curve lvl3
	{0xA0,0x20,BIT,0},
	{0xA1,0x38,BIT,0},
	{0xA2,0x4e,BIT,0},
	{0xA3,0x63,BIT,0},
	{0xA4,0x76,BIT,0},
	{0xA5,0x87,BIT,0},
	{0xA6,0xa2,BIT,0},
	{0xA7,0xb8,BIT,0},
	{0xA8,0xca,BIT,0},
	{0xA9,0xd8,BIT,0},
	{0xAA,0xe3,BIT,0},
	{0xAB,0xeb,BIT,0},
	{0xAC,0xf0,BIT,0},
	{0xAD,0xf8,BIT,0},
	{0xAE,0xfd,BIT,0},
	{0xAF,0xff,BIT,0},

	{0x9F,0x14,BIT,0},	// gamma curve lvl4
	{0xA0,0x28,BIT,0},
	{0xA1,0x44,BIT,0},
	{0xA2,0x5d,BIT,0},
	{0xA3,0x72,BIT,0},
	{0xA4,0x86,BIT,0},
	{0xA5,0x95,BIT,0},
	{0xA6,0xb1,BIT,0},
	{0xA7,0xc6,BIT,0},
	{0xA8,0xd5,BIT,0},
	{0xA9,0xe1,BIT,0},
	{0xAA,0xea,BIT,0},
	{0xAB,0xf1,BIT,0},
	{0xAC,0xf5,BIT,0},
	{0xAD,0xfb,BIT,0},
	{0xAE,0xfe,BIT,0},
	{0xAF,0xff,BIT,0},
#endif

	//Y_gamma
	{0xc0,0x00,BIT,0},
	{0xc1,0x0B,BIT,0},
	{0xc2,0x15,BIT,0},
	{0xc3,0x27,BIT,0},
	{0xc4,0x39,BIT,0},
	{0xc5,0x49,BIT,0},
	{0xc6,0x5A,BIT,0},
	{0xc7,0x6A,BIT,0},
	{0xc8,0x89,BIT,0},
	{0xc9,0xA8,BIT,0},
	{0xca,0xC6,BIT,0},
	{0xcb,0xE3,BIT,0},
	{0xcc,0xFF,BIT,0},

	/////////////////////////////////////////////////////////////////
	/////////////////////////// ABS_t ///////////////////////////////
	/////////////////////////////////////////////////////////////////
	{0xf0,0x02,BIT,0},
	{0xf1,0x01,BIT,0},
	{0xf2,0x00,BIT,0},
	{0xf3,0x30,BIT,0},

	/////////////////////////////////////////////////////////////////
	/////////////////////////// Measure Window ///////////////////////
	/////////////////////////////////////////////////////////////////
	{0xf7,0x04,BIT,0},
	{0xf8,0x02,BIT,0},
	{0xf9,0x9f,BIT,0},
	{0xfa,0x78,BIT,0},

	//---------------------------------------------------------------
	{0xfe,0x01,BIT,0},

	/////////////////////////////////////////////////////////////////
	///////////////////////////AWB_p/////////////////////////////////
	/////////////////////////////////////////////////////////////////
	{0x00,0xf5,BIT,0},
//	{0x01,0x0a,BIT,0},
	{0x02,0x1a,BIT,0},
	{0x0a,0xa0,BIT,0},
	{0x0b,0x60,BIT,0},
	{0x0c,0x08,BIT,0},
	{0x0e,0x4c,BIT,0},
	{0x0f,0x39,BIT,0},
	{0x11,0x3f,BIT,0},
	{0x12,0x72,BIT,0},
	{0x13,0x39,BIT,0},
	{0x14,0x42,BIT,0},
	{0x15,0x43,BIT,0},
	{0x16,0xc2,BIT,0},
	{0x17,0xa8,BIT,0},
	{0x18,0x18,BIT,0},
	{0x19,0x40,BIT,0},
	{0x1a,0xd0,BIT,0},
	{0x1b,0xf5,BIT,0},

	{0x70,0x40,BIT,0},
	{0x71,0x58,BIT,0},
	{0x72,0x30,BIT,0},
	{0x73,0x48,BIT,0},
	{0x74,0x20,BIT,0},
	{0x75,0x60,BIT,0},

	{0xfe,0x00,BIT,0},

	{0xd2,0x90,BIT,0},	// Open AEC
	{0x23,0x00,BIT,0},
	{0x2d,0x0a,BIT,0},
	{0x20,0xff,BIT,0},
	{0x73,0x00,BIT,0},
	{0x77,0x33,BIT,0},
	{0xb3,0x40,BIT,0},
	{0xb4,0x80,BIT,0},
	{0xb5,0x00,BIT,0},
	{0xba,0x00,BIT,0},
	{0xbb,0x00,BIT,0},

	{0x8b,0x22,BIT,0},
	{0x71,0x43,BIT,0},
	{0x31,0x60,BIT,0},
	{0x1c,0x49,BIT,0},
	{0x1d,0x98,BIT,0},
	{0x10,0x26,BIT,0},
	{0x1a,0x26,BIT,0},

	{0x14,0x10,BIT,20},	// Mirror UpsideDown

	{0xff,0xff,BIT,0},
};

static struct sensor_reg_list gc0309b_init = {
	.size = ARRAY_ROW(init_gc0309b),
	.val = init_gc0309b
};

static struct sensor_reg_list gc0309b_vga = {
	.size = ARRAY_ROW(vga_gc0309b),
	.val = vga_gc0309b
};
static struct sensor_reg_list gc0309b_qvga = {
	.size = ARRAY_ROW(qvga_gc0309b),
	.val = qvga_gc0309b
};
static struct sensor_reg_list gc0309b_qcif = {
	.size = ARRAY_ROW(qcif_gc0309b),
	.val = qcif_gc0309b
};
static struct sensor_reg_list gc0309b_qqvga = {
	.size = ARRAY_ROW(qqvga_gc0309b),
	.val = qqvga_gc0309b
};
static struct sensor_win_size gc0309b_win_size[] = {
	WIN_SIZE("VGA", W_VGA, H_VGA, &gc0309b_vga),
	WIN_SIZE("QVGA", W_QVGA, H_QVGA, &gc0309b_qvga),
	WIN_SIZE("QCIF", W_QCIF, H_QCIF, &gc0309b_qcif),
	WIN_SIZE("QQVGA", W_QQVGA, H_QQVGA, &gc0309b_qqvga),
};

static struct sensor_win_cfg gc0309b_win_cfg = {
	.num = ARRAY_ROW(gc0309b_win_size),
	.win_size = gc0309b_win_size
};

static struct sensor_csi_cfg gc0309b_csi_cfg = {
	.csi_en = false,
	.d_term_en = 0,
	.c_term_en = 0,
	.dhs_settle = 0,
	.chs_settle = 0,
};

static struct sensor_info gc0309b_info = {
	.name		= "gc0309",
	.chip_id	= 0xa0,
	.mclk		= 26,
	.i2c_addr	= 0x21,
	.exp_def	= 0,
	.awb_def	= 1,
	.rst_act_h	= false,
	.pdn_act_h	= true,
	.init		= &gc0309b_init,
	.win_cfg	= &gc0309b_win_cfg,
	.csi_cfg	= &gc0309b_csi_cfg
};

extern void sensor_power_down(bool high, bool acth, int id);
extern void sensor_reset(bool rst, bool acth);
extern void sensor_clock(bool out, int mclk);
extern void sensor_read(const u16 addr, u8 *data, u8 bits);
extern void sensor_write(const u16 addr, const u8 data, u8 bits);
extern void sensor_write_group(struct sensor_reg* reg, u32 size);

static u32 gc0309b_power(int id, int mclk, bool rst_h, bool pdn_h)
{
	/* set state to power off */
	sensor_power_down(true, pdn_h, 0);
	mdelay(1);
	sensor_power_down(true, pdn_h, 1);
	mdelay(1);
	sensor_reset(true, rst_h);
	mdelay(1);

	/* power on sequence */
	sensor_clock(true, mclk);
	mdelay(1);
	sensor_power_down(false, pdn_h, id);
	mdelay(1);
	sensor_reset(false, rst_h);
	mdelay(10);

	return 0;
}

static u32 gc0309b_get_chipid(void)
{
	u8 chip_id = 0;

	sensor_read(0x00, &chip_id, BIT);
printk("gc0309b_get_chipid   chipid = 0x%x \r\n",chip_id);
	return chip_id;
}

static u32 gc0309b_get_lum(void)
{
	u8 val = 0;
	u32 ret = 0;

	sensor_write(0xfe, 0x00, BIT);
	sensor_read(0xd4, &val, BIT);

	if (val < 0x30)
		ret = 1;

	return ret;
}

#define GC0309B_FLIP_BASE	0x14
#define GC0309B_H_FLIP_BIT	0
#define GC0309B_V_FLIP_BIT	1
static void gc0309b_set_flip(int hv, int flip)
{
	u8 tmp = 0;

	sensor_read(GC0309B_FLIP_BASE, &tmp, BIT);

	if (hv) {
		if (flip)
			tmp |= (0x1 << GC0309B_V_FLIP_BIT);
		else
			tmp &= ~(0x1 << GC0309B_V_FLIP_BIT);
	}
	else {
		if (flip)
			tmp |= (0x1 << GC0309B_H_FLIP_BIT);
		else
			tmp &= ~(0x1 << GC0309B_H_FLIP_BIT);
	}

	sensor_write(GC0309B_FLIP_BASE, tmp, BIT);
}

#define GC0309B_EXP_ROW		ARRAY_ROW(exp_gc0309b)
#define GC0309B_EXP_COL		ARRAY_COL(exp_gc0309b)
static void gc0309b_set_exp(int exp)
{
	int key = exp + (GC0309B_EXP_ROW / 2);
	if ((key < 0) || (key > (GC0309B_EXP_ROW - 1)))
		return;

	sensor_write_group(exp_gc0309b[key], GC0309B_EXP_COL);
}

#define GC0309B_AWB_ROW		ARRAY_ROW(awb_gc0309b)
#define GC0309B_AWB_COL		ARRAY_COL(awb_gc0309b)
static void gc0309b_set_awb(int awb)
{
	if ((awb < 0) || (awb > (GC0309B_AWB_ROW - 1)))
		return;

	sensor_write_group(awb_gc0309b[awb], GC0309B_AWB_COL);
}

static struct sensor_ops gc0309b_ops = {
	.power		= gc0309b_power,
	.get_chipid	= gc0309b_get_chipid,
	.get_lum	= gc0309b_get_lum,
	.set_flip	= gc0309b_set_flip,
	.set_exp	= gc0309b_set_exp,
	.set_awb	= gc0309b_set_awb,
	.start		= NULL,
	.stop		= NULL
};

struct sensor_dev gc0309b_dev = {
	.info	= &gc0309b_info,
	.ops	= &gc0309b_ops,
};

#undef BIT
#endif
