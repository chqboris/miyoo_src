#
# Copyright (C) 2007 Ludovic Jacomme (ludovic.jacomme@gmail.com)
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#
WRITE_VERSION=1.1.0

TARGET = wizwrite
#SDL_CONFIG = sdl-config
SDL_CONFIG = /opt/miyoo/arm-miyoo-linux-uclibcgnueabi/sysroot/usr/bin/sdl-config
OBJS= gp2x_psp.o \
      psp_menu.o psp_menu_set.o \
      psp_help.o \
      psp_global.o \
      psp_main.o  \
      psp_fmgr.o \
      psp_sdl.o psp_font.o psp_danzeff.o \
      psp_editor.o

#CC = gcc
CC = arm-linux-gcc
DEFAULT_CFLAGS = $(shell $(SDL_CONFIG) --cflags)
MORE_CFLAGS = -I/usr/include  -I. \
-DWRITE_VERSION=\"$(WRITE_VERSION)\" \
-DLINUX_MODE -DNO_STDIO_REDIRECT

CFLAGS = $(DEFAULT_CFLAGS) $(MORE_CFLAGS) -fsigned-char -g 

LIBS += -L/usr/lib -L/usr/X11R6/lib -lSDL_image -lSDL -lXext -lX11 -lpng -ljpeg -lz -lm -lpthread

all : $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

ctags: 
	ctags *[ch]
