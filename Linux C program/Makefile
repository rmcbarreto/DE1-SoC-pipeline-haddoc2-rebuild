#
TARGET = de1_soc_hps_binary

#
ALT_DEVICE_FAMILY = soc_cv_av 

#${SOCEDS_DEST_ROOT} => Environment variable or write the full path manualy

CROSS_COMPILE = arm-linux-gnueabihf-
CFLAGS = -g -Wall -I ${SOCEDS_DEST_ROOT}/ip/altera/hps/altera_hps/hwlib/include -D${ALT_DEVICE_FAMILY}
LDFLAGS =  -g -Wall
CC = $(CROSS_COMPILE)gcc
ARCH= arm
PFLAGS = -lm

build: $(TARGET)

# $^ chama o target main.o
$(TARGET): main.o
	$(CC) $^ $(LDFLAGS) ${PFLAGS}  -o $@ 

# the .o file depends on the .c version of the file
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY: clean
clean:
	rm -f $(TARGET) *.a *.o *~