DEFAULT_WIN_PORT = COM6
DEFAULT_POSIX_PORT = /dev/ttyUSB0

ifeq ($(OS),Windows_NT)
DEFAULT_PORT = $(DEFAULT_WIN_PORT)
else
DEFAULT_PORT = $(DEFAULT_POSIX_PORT)
endif

setup :
	pip3 install esptool

ports :
	python -c "import serial.tools.list_ports as ls; print([p.device for p in ls.comports()])"

#esp32

e32 :
	esptool.py --chip esp32 --port $(DEFAULT_PORT) erase_flash

f32 :
	esptool.py --chip esp32 --port $(DEFAULT_PORT) --baud 460800 write_flash -z 0x1000 firmware/esp32-20220618-v1.19.1.bin

#esp32cam

e32c :
	esptool.py --chip esp32 --port $(DEFAULT_PORT) erase_flash

f32c :
	esptool.py --chip esp32 --port $(DEFAULT_PORT) --baud 460800 write_flash -z 0x1000 firmware/micropython_camera_feeeb5ea3_esp32_idf4_4.bin


# esp8266

e8266 :
	esptool.py --chip esp8266 --port $(DEFAULT_PORT) erase_flash

f8266 :
	esptool.py --chip esp8266 --port $(DEFAULT_PORT) --baud 460800 write_flash --flash_size=detect 0 firmware/esp8266-1m-20220618-v1.19.1.bin

#nodemcu

e12 :
	make e8266

f12 :
	esptool.py --chip esp8266 --port $(DEFAULT_PORT) --baud 460800 write_flash --flash_size=detect -fm dout 0 firmware/esp8266-1m-20220618-v1.19.1.bin
