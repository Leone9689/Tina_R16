/*
 * arch/mips/lasat/ds1603.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
/*
 * Dallas Semiconductors 1603 RTC driver
 *
 * Brian Murphy <brian@murphy.dk>
 *
 */
#ifndef __DS1603_H
#define __DS1603_H

struct ds_defs {
	volatile u32 *reg;
	volatile u32 *data_reg;
	u32 rst;
	u32 clk;
	u32 data;
	u32 data_read_shift;
	char data_reversed;
	u32 huge_delay;
};

extern struct ds_defs *ds1603;

void ds1603_set_trimmer(unsigned int);
void ds1603_enable(void);
void ds1603_disable(void);
void ds1603_init(struct ds_defs *);

#define TRIMMER_DEFAULT	3
#define TRIMMER_DISABLE_RTC 0

#endif