TOOLPREFIX:=	/arm-eabi
QTDIR	:=	$(TOOLPREFIX)/lib/qt-2.3.8
EZXDIR	:=	$(TOOLPREFIX)/lib/ezx-z6
UPLOAD_PATH :=  /mmc/mmca1/bin/
CC	=	$(TOOLPREFIX)/bin/arm-linux-gnueabi-gcc
CXX	=	$(TOOLPREFIX)/bin/arm-linux-gnueabi-g++
LD	=	$(TOOLPREFIX)/bin/arm-linux-gnueabi-g++
CFLAGS	=	-pipe -Wall -W -O2 -DNO_DEBUG $(INCPATH)
CXXFLAGS=	-pipe -DQWS -fno-exceptions -fno-rtti -Wall -W -O2 -DNO_DEBUG $(INCPATH)
INCPATH	=	-I$(QTDIR)/include -I$(EZXDIR)/include
LDFLAGS	=	-s
LDLIBS	=	-L$(TOOLPREFIX)/arm-linux-gnueabi/lib -L$(QTDIR)/lib -L$(EZXDIR)/lib -lm -lqte-mt -lezxpm -ljpeg -lezxappbase -lezxtapi-xscale-r -llog_util -llighting
MOC	=	$(QTDIR)/bin/moc
RM=rm -f
MV=mv

TARGETS = libezxsoundhelp.a

all: $(TARGETS)

libezxsoundhelp.a: soundhelp.o
	$(AR) rcs $@ $<

install: $(TARGETS)
	ncftpput -u root -p "" 192.168.16.2 $(UPLOAD_PATH) $(TARGETS)

clean:
	$(RM) $(TARGETS)
	$(RM) main
	$(RM) *.o
