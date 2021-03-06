/* linux/arch/arm/mach-s5pc100/dma.c
 *
 * Copyright (c) 2011 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com
 *
 * Copyright (C) 2010 Samsung Electronics Co. Ltd.
 *	Jaswinder Singh <jassi.brar@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <linux/dma-mapping.h>
#include <linux/amba/bus.h>
#include <linux/amba/pl330.h>

#include <asm/irq.h>
#include <plat/devs.h>
#include <plat/irqs.h>

#include <mach/map.h>
#include <mach/irqs.h>
#include <mach/dma.h>

static u64 dma_dmamask = DMA_BIT_MASK(32);

struct dma_pl330_peri pdma0_peri[30] = {
	{
		.peri_id = (u8)DMACH_UART0_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_UART0_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_UART1_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_UART1_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_UART2_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_UART2_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_UART3_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_UART3_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = DMACH_IRDA,
	}, {
		.peri_id = (u8)DMACH_I2S0_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_I2S0_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_I2S0S_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_I2S1_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_I2S1_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_I2S2_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_I2S2_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_SPI0_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_SPI0_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_SPI1_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_SPI1_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_SPI2_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_SPI2_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_AC97_MICIN,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_AC97_PCMIN,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_AC97_PCMOUT,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_EXTERNAL,
	}, {
		.peri_id = (u8)DMACH_PWM,
	}, {
		.peri_id = (u8)DMACH_SPDIF,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_HSI_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_HSI_TX,
		.rqtype = MEMTODEV,
	},
};

struct dma_pl330_platdata s5pc100_pdma0_pdata = {
	.nr_valid_peri = ARRAY_SIZE(pdma0_peri),
	.peri = pdma0_peri,
};

struct amba_device s5pc100_device_pdma0 = {
	.dev = {
		.init_name = "dma-pl330.0",
		.dma_mask = &dma_dmamask,
		.coherent_dma_mask = DMA_BIT_MASK(32),
		.platform_data = &s5pc100_pdma0_pdata,
	},
	.res = {
		.start = S5PC100_PA_PDMA0,
		.end = S5PC100_PA_PDMA0 + SZ_4K,
		.flags = IORESOURCE_MEM,
	},
	.irq = {IRQ_PDMA0, NO_IRQ},
	.periphid = 0x00041330,
};

struct dma_pl330_peri pdma1_peri[30] = {
	{
		.peri_id = (u8)DMACH_UART0_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_UART0_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_UART1_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_UART1_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_UART2_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_UART2_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_UART3_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_UART3_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = DMACH_IRDA,
	}, {
		.peri_id = (u8)DMACH_I2S0_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_I2S0_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_I2S0S_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_I2S1_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_I2S1_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_I2S2_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_I2S2_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_SPI0_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_SPI0_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_SPI1_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_SPI1_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_SPI2_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_SPI2_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_PCM0_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_PCM1_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_PCM1_RX,
		.rqtype = DEVTOMEM,
	}, {
		.peri_id = (u8)DMACH_PCM1_TX,
		.rqtype = MEMTODEV,
	}, {
		.peri_id = (u8)DMACH_MSM_REQ0,
	}, {
		.peri_id = (u8)DMACH_MSM_REQ1,
	}, {
		.peri_id = (u8)DMACH_MSM_REQ2,
	}, {
		.peri_id = (u8)DMACH_MSM_REQ3,
	},
};

struct dma_pl330_platdata s5pc100_pdma1_pdata = {
	.nr_valid_peri = ARRAY_SIZE(pdma1_peri),
	.peri = pdma1_peri,
};

struct amba_device s5pc100_device_pdma1 = {
	.dev = {
		.init_name = "dma-pl330.1",
		.dma_mask = &dma_dmamask,
		.coherent_dma_mask = DMA_BIT_MASK(32),
		.platform_data = &s5pc100_pdma1_pdata,
	},
	.res = {
		.start = S5PC100_PA_PDMA1,
		.end = S5PC100_PA_PDMA1 + SZ_4K,
		.flags = IORESOURCE_MEM,
	},
	.irq = {IRQ_PDMA1, NO_IRQ},
	.periphid = 0x00041330,
};

static int __init s5pc100_dma_init(void)
{
	amba_device_register(&s5pc100_device_pdma0, &iomem_resource);
	amba_device_register(&s5pc100_device_pdma1, &iomem_resource);

	return 0;
}
arch_initcall(s5pc100_dma_init);
