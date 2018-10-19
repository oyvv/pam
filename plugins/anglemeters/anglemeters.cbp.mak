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
CFLAGS = -D_monitor_
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
OUT_LINUX_RELEASE = ../../lib/monitor/libanglemeters.so

OBJ_LINUX_RELEASE = $(OBJDIR_LINUX_RELEASE)/anglemeters.o $(OBJDIR_LINUX_RELEASE)/anglemetersbuilder.o $(OBJDIR_LINUX_RELEASE)/pnlAngleMeters.o $(OBJDIR_LINUX_RELEASE)/pnlMeterSettings.o $(OBJDIR_LINUX_RELEASE)/pnlMode.o $(OBJDIR_LINUX_RELEASE)/pnlOptions.o

all: linux_release

clean: clean_linux_release

before_linux_release: 
	test -d ../../lib/monitor || mkdir -p ../../lib/monitor
	test -d $(OBJDIR_LINUX_RELEASE) || mkdir -p $(OBJDIR_LINUX_RELEASE)

after_linux_release: 
	../../manifest_creator/bin/LinuxRelease/manifest_creator

linux_release: before_linux_release out_linux_release after_linux_release

out_linux_release: before_linux_release $(OBJ_LINUX_RELEASE) $(DEP_LINUX_RELEASE)
	$(LD) -shared $(LIBDIR_LINUX_RELEASE) $(OBJ_LINUX_RELEASE)  -o $(OUT_LINUX_RELEASE) $(LDFLAGS_LINUX_RELEASE) $(LIB_LINUX_RELEASE)

$(OBJDIR_LINUX_RELEASE)/anglemeters.o: anglemeters.cpp
	$(CXX) $(CFLAGS_LINUX_RELEASE) $(INC_LINUX_RELEASE) -c anglemeters.cpp -o $(OBJDIR_LINUX_RELEASE)/anglemeters.o

$(OBJDIR_LINUX_RELEASE)/anglemetersbuilder.o: anglemetersbuilder.cpp
	$(CXX) $(CFLAGS_LINUX_RELEASE) $(INC_LINUX_RELEASE) -c anglemetersbuilder.cpp -o $(OBJDIR_LINUX_RELEASE)/anglemetersbuilder.o

$(OBJDIR_LINUX_RELEASE)/pnlAngleMeters.o: pnlAngleMeters.cpp
	$(CXX) $(CFLAGS_LINUX_RELEASE) $(INC_LINUX_RELEASE) -c pnlAngleMeters.cpp -o $(OBJDIR_LINUX_RELEASE)/pnlAngleMeters.o

$(OBJDIR_LINUX_RELEASE)/pnlMeterSettings.o: pnlMeterSettings.cpp
	$(CXX) $(CFLAGS_LINUX_RELEASE) $(INC_LINUX_RELEASE) -c pnlMeterSettings.cpp -o $(OBJDIR_LINUX_RELEASE)/pnlMeterSettings.o

$(OBJDIR_LINUX_RELEASE)/pnlMode.o: pnlMode.cpp
	$(CXX) $(CFLAGS_LINUX_RELEASE) $(INC_LINUX_RELEASE) -c pnlMode.cpp -o $(OBJDIR_LINUX_RELEASE)/pnlMode.o

$(OBJDIR_LINUX_RELEASE)/pnlOptions.o: pnlOptions.cpp
	$(CXX) $(CFLAGS_LINUX_RELEASE) $(INC_LINUX_RELEASE) -c pnlOptions.cpp -o $(OBJDIR_LINUX_RELEASE)/pnlOptions.o

clean_linux_release: 
	rm -f $(OBJ_LINUX_RELEASE) $(OUT_LINUX_RELEASE)
	rm -rf ../../lib/monitor
	rm -rf $(OBJDIR_LINUX_RELEASE)

.PHONY: before_linux_release after_linux_release clean_linux_release
