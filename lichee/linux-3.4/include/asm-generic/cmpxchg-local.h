/*
 * include/asm-generic/cmpxchg-local.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef __ASM_GENERIC_CMPXCHG_LOCAL_H
#define __ASM_GENERIC_CMPXCHG_LOCAL_H

#include <linux/types.h>
#include <linux/irqflags.h>

extern unsigned long wrong_size_cmpxchg(volatile void *ptr);

/*
 * Generic version of __cmpxchg_local (disables interrupts). Takes an unsigned
 * long parameter, supporting various types of architectures.
 */
static inline unsigned long __cmpxchg_local_generic(volatile void *ptr,
		unsigned long old, unsigned long new, int size)
{
	unsigned long flags, prev;

	/*
	 * Sanity checking, compile-time.
	 */
	if (size == 8 && sizeof(unsigned long) != 8)
		wrong_size_cmpxchg(ptr);

	local_irq_save(flags);
	switch (size) {
	case 1: prev = *(u8 *)ptr;
		if (prev == old)
			*(u8 *)ptr = (u8)new;
		break;
	case 2: prev = *(u16 *)ptr;
		if (prev == old)
			*(u16 *)ptr = (u16)new;
		break;
	case 4: prev = *(u32 *)ptr;
		if (prev == old)
			*(u32 *)ptr = (u32)new;
		break;
	case 8: prev = *(u64 *)ptr;
		if (prev == old)
			*(u64 *)ptr = (u64)new;
		break;
	default:
		wrong_size_cmpxchg(ptr);
	}
	local_irq_restore(flags);
	return prev;
}

/*
 * Generic version of __cmpxchg64_local. Takes an u64 parameter.
 */
static inline u64 __cmpxchg64_local_generic(volatile void *ptr,
		u64 old, u64 new)
{
	u64 prev;
	unsigned long flags;

	local_irq_save(flags);
	prev = *(u64 *)ptr;
	if (prev == old)
		*(u64 *)ptr = new;
	local_irq_restore(flags);
	return prev;
}

#endif