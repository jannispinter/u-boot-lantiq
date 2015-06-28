/*
 * Copyright (C) 2013 Matti Laakso <malaakso@elisanet.fi>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_MACH_TYPE	"ARV7510PW"
#define CONFIG_IDENT_STRING	" "CONFIG_MACH_TYPE
#define CONFIG_BOARD_NAME	"Arcadyan ARV7510PW"

/* Configure SoC */
#define CONFIG_LTQ_SUPPORT_UART		/* Enable ASC and UART */
#define CONFIG_LTQ_SUPPORT_ETHERNET	/* Enable ethernet */
#define CONFIG_LTQ_SUPPORT_NOR_FLASH	/* Have a parallel NOR flash */

/* Switch devices */
#define CONFIG_SWITCH_MULTI
#define CONFIG_SWITCH_ADM6996I

/* SSIO */
#define CONFIG_LTQ_SSIO_SHIFT_REGS	2
#define CONFIG_LTQ_SSIO_EDGE_FALLING
#define CONFIG_LTQ_SSIO_GPHY1_MODE	0
#define CONFIG_LTQ_SSIO_GPHY2_MODE	0
#define CONFIG_LTQ_SSIO_INIT_VALUE	0

/* Environment */
#if defined(CONFIG_SYS_BOOT_NOR)
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_OFFSET		(256 * 1024)
#define CONFIG_ENV_SECT_SIZE		(128 * 1024)
#else
#define CONFIG_ENV_IS_NOWHERE
#endif

#define CONFIG_ENV_SIZE			(8 * 1024)
#define CONFIG_LOADADDR			CONFIG_SYS_LOAD_ADDR

/* Brnboot loadable image */
#if defined(CONFIG_SYS_BOOT_BRN)
#define CONFIG_SYS_TEXT_BASE		0x80002000
#define CONFIG_SKIP_LOWLEVEL_INIT
#define CONFIG_SYS_DISABLE_CACHE
#define CONFIG_ENV_OVERWRITE 1
#endif

/* Console */
#define CONFIG_LTQ_ADVANCED_CONSOLE
#define CONFIG_BAUDRATE			115200
#define CONFIG_CONSOLE_ASC		1

/* Pull in default board configs for Lantiq XWAY Danube */
#include <asm/lantiq/config.h>
#include <asm/arch/config.h>

/* Buffered write broken in ARV7510PW */
#undef CONFIG_SYS_FLASH_USE_BUFFER_WRITE

/* Pull in default OpenWrt configs for Lantiq SoC */
#include "openwrt-lantiq-common.h"

#define CONFIG_ENV_UPDATE_UBOOT_NOR		\
	"update-uboot-nor=run load-uboot-nor write-uboot-nor\0"

#define CONFIG_EXTRA_ENV_SETTINGS		\
	CONFIG_ENV_LANTIQ_DEFAULTS		\
	CONFIG_ENV_UPDATE_UBOOT_NOR		\
	"kernel_addr=0xB0060000\0"

#endif /* __CONFIG_H */
