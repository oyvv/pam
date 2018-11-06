#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = -I../../pambase -I\$\(\#kiss.include\) -I\$\(\#kiss.include\)/tools
CFLAGS = -D_test_
RESINC = 
LIBDIR = -L../../lib
LIB = 
LDFLAGS = 

INC_LINUX_RELEASE = $(INC)
CFLAGS_LINUX_RELEASE = $(CFLAGS) -O3 `wx-config --cxxflags` -fpermissive -fPIC -DDLL_EXPORTS -DwxUSE_UNICODE -D__WXGNU__
RESINC_LINUX_RELEASE = $(RESINC)
RCFLAGS_LINUX_RELEASE = $(RCFLAGS)
LIBDIR_LINUX_RELEASE = $(LIBDIR)
LIB_LINUX_RELEASE = $(LIB)-lpambase
LDFLAGS_LINUX_RELEASE = $(LDFLAGS) `wx-config --libs`
OBJDIR_LINUX_RELEASE = obj/linux
DEP_LINUX_RELEASE = 
OUT_LINUX_RELEASE = ../../lib/test/libpeaklog.so

OBJ_LINUX_RELEASE = $(OBJDIR_LINUX_RELEASE)/peaklog.o $(OBJDIR_LINUX_RELEASE)/peaklogbuilder.o $(OBJDIR_LINUX_RELEASE)/pnlPeakLog.o

all: linux_release

clean: clean_linux_release

before_linux_release: 
	test -d ../../lib/test || mkdir -p ../../lib/test
	test -d $(OBJDIR_LINUX_RELEASE) || mkdir -p $(OBJDIR_LINUX_RELEASE)

after_linux_release: 
	../../manifest_creator/bin/LinuxRelease/manifest_creator

linux_release: before_linux_release out_linux_release after_linux_release

out_linux_release: before_linux_release $(OBJ_LINUX_RELEASE) $(DEP_LINUX_RELEASE)
	$(LD) -shared $(LIBDIR_LINUX_RELEASE) $(OBJ_LINUX_RELEASE)  -o $(OUT_LINUX_RELEASE) $(LDFLAGS_LINUX_RELEASE) $(LIB_LINUX_RELEASE)

$(OBJDIR_LINUX_RELEASE)/peaklog.o: peaklog.cpp
	$(CXX) $(CFLAGS_LINUX_RELEASE) $(INC_LINUX_RELEASE) -c peaklog.cpp -o $(OBJDIR_LINUX_RELEASE)/peaklog.o

$(OBJDIR_LINUX_RELEASE)/peaklogbuilder.o: peaklogbuilder.cpp
	$(CXX) $(CFLAGS_LINUX_RELEASE) $(INC_LINUX_RELEASE) -c peaklogbuilder.cpp -o $(OBJDIR_LINUX_RELEASE)/peaklogbuilder.o

$(OBJDIR_LINUX_RELEASE)/pnlPeakLog.o: pnlPeakLog.cpp
	$(CXX) $(CFLAGS_LINUX_RELEASE) $(INC_LINUX_RELEASE) -c pnlPeakLog.cpp -o $(OBJDIR_LINUX_RELEASE)/pnlPeakLog.o

clean_linux_release: 
	rm -f $(OBJ_LINUX_RELEASE) $(OUT_LINUX_RELEASE)
	rm -rf ../../lib/test
	rm -rf $(OBJDIR_LINUX_RELEASE)

.PHONY: before_linux_release after_linux_release clean_linux_release

