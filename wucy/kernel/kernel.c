/*
 * kernel.c
 *
 *  Created on: 2019-09-30
 *      Author: lukas.neverauskis
 */
/*
	Software for project "WUCY" - wearable open source general-purpose
	computer based on ESP32 running FreeRTOS on custom Therram kernel.
	<https://github.com/therram/wucy>

	License: GPL 3.0

	Copyright (C) 2019 Lukas Neverauskis

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#define WUCY_PRIV_ACCESS
#include "wucyOS.h"

#include "ui.h"

void wucy_Start(void){

	/* for debug */
	wucy_hal_PinOutputInit(25);
	wucy_hal_PinOutputInit(26);
	wucy_hal_PinOutputInit(27);

	wucy_disp_Init();
	wucy_wnd_Init();


	wucy_UI_Init();

	wucy_wnd_FramingStart(30);

	/* todo only works if task scheduler is already running and
	 * this function is inside a task. Need to create a specific kernel task */
	while(1){

		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}

