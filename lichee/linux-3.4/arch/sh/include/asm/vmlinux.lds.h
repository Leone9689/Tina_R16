/*
 * arch/sh/include/asm/vmlinux.lds.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef __ASM_SH_VMLINUX_LDS_H
#define __ASM_SH_VMLINUX_LDS_H

#include <asm-generic/vmlinux.lds.h>

#ifdef CONFIG_DWARF_UNWINDER
#define DWARF_EH_FRAME							\
	.eh_frame : AT(ADDR(.eh_frame) - LOAD_OFFSET) {			\
		  VMLINUX_SYMBOL(__start_eh_frame) = .;			\
		  *(.eh_frame)						\
		  VMLINUX_SYMBOL(__stop_eh_frame) = .;			\
	}
#else
#define DWARF_EH_FRAME
#endif

#ifdef CONFIG_SUPERH64
#define EXTRA_TEXT		\
	*(.text64)		\
	*(.text..SHmedia32)
#else
#define EXTRA_TEXT
#endif

#endif /* __ASM_SH_VMLINUX_LDS_H */