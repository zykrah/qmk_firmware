/*
Copyright 2025 Zykrah
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define WEAR_LEVELING_DEBUG_OUTPUT

// SPI config
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN A5
#define SPI_MISO_PIN A6
#define SPI_MOSI_PIN A7
#define SPI_SCK_PAL_MODE 5
#define SPI_MISO_PAL_MODE 5
#define SPI_MOSI_PAL_MODE 5

// External flash config
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN A4
#define EXTERNAL_FLASH_SPI_CLOCK_DIVISOR 8
#define EXTERNAL_FLASH_PAGE_SIZE 256
#define EXTERNAL_FLASH_SECTOR_SIZE (4 * 1024)
#define EXTERNAL_FLASH_BLOCK_SIZE (64 * 1024)
#define EXTERNAL_FLASH_SIZE (16 * 1024 * 1024) // 128Mb/16MB capacity
#define EXTERNAL_FLASH_ADDRESS_SIZE 3

// Wear levelling
#define WEAR_LEVELING_EXTERNAL_FLASH_BLOCK_COUNT 1
#define WEAR_LEVELING_EXTERNAL_FLASH_BLOCK_OFFSET 0
#define WEAR_LEVELING_LOGICAL_SIZE (32 * 1024)
#define WEAR_LEVELING_BACKING_SIZE (64 * 1024)
#define BACKING_STORE_WRITE_SIZE 8