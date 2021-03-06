#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = -IC:/wxWidgets-3.0.2/include -I../pambase
CFLAGS = -Wall -D_app_
RESINC = 
LIBDIR = -L../lib
LIB = 
LDFLAGS = 

INC_LINUX_RELEASE = $(INC)
CFLAGS_LINUX_RELEASE = $(CFLAGS) -O3 `wx-config --cxxflags` -fpermissive -DwxUSE_UNICODE -D__WXGNU__
RESINC_LINUX_RELEASE = $(RESINC)
RCFLAGS_LINUX_RELEASE = $(RCFLAGS)
LIBDIR_LINUX_RELEASE = $(LIBDIR)
LIB_LINUX_RELEASE = $(LIB)-lpambase
LDFLAGS_LINUX_RELEASE = $(LDFLAGS) `wx-config --libs`
OBJDIR_LINUX_RELEASE = .objs
DEP_LINUX_RELEASE = 
OUT_LINUX_RELEASE = ../bin/pamm

OBJ_LINUX_RELEASE = $(OBJDIR_LINUX_RELEASE)/pammApp.o $(OBJDIR_LINUX_RELEASE)/pammMain.o $(OBJDIR_LINUX_RELEASE)/pamprocess.o $(OBJDIR_LINUX_RELEASE)/wxpamconnection.o $(OBJDIR_LINUX_RELEASE)/wxpamserver.o

all: linux_release

clean: clean_linux_release

before_linux_release: 
	test -d ../bin || mkdir -p ../bin
	test -d $(OBJDIR_LINUX_RELEASE) || mkdir -p $(OBJDIR_LINUX_RELEASE)

after_linux_release: 
	../manifest_creator/bin/LinuxRelease/manifest_creator

linux_release: before_linux_release out_linux_release after_linux_release

out_linux_release: before_linux_release $(OBJ_LINUX_RELEASE) $(DEP_LINUX_RELEASE)
	$(LD) $(LIBDIR_LINUX_RELEASE) -o $(OUT_LINUX_RELEASE) $(OBJ_LINUX_RELEASE)  $(LDFLAGS_LINUX_RELEASE) $(LIB_LINUX_RELEASE)

$(OBJDIR_LINUX_RELEASE)/pammApp.o: pammApp.cpp
	$(CXX) $(CFLAGS_LINUX_RELEASE) $(INC_LINUX_RELEASE) -c pammApp.cpp -o $(OBJDIR_LINUX_RELEASE)/pammApp.o

$(OBJDIR_LINUX_RELEASE)/pammMain.o: pammMain.cpp
	$(CXX) $(CFLAGS_LINUX_RELEASE) $(INC_LINUX_RELEASE) -c pammMain.cpp -o $(OBJDIR_LINUX_RELEASE)/pammMain.o

$(OBJDIR_LINUX_RELEASE)/pamprocess.o: pamprocess.cpp
	$(CXX) $(CFLAGS_LINUX_RELEASE) $(INC_LINUX_RELEASE) -c pamprocess.cpp -o $(OBJDIR_LINUX_RELEASE)/pamprocess.o

$(OBJDIR_LINUX_RELEASE)/wxpamconnection.o: wxpamconnection.cpp
	$(CXX) $(CFLAGS_LINUX_RELEASE) $(INC_LINUX_RELEASE) -c wxpamconnection.cpp -o $(OBJDIR_LINUX_RELEASE)/wxpamconnection.o

$(OBJDIR_LINUX_RELEASE)/wxpamserver.o: wxpamserver.cpp
	$(CXX) $(CFLAGS_LINUX_RELEASE) $(INC_LINUX_RELEASE) -c wxpamserver.cpp -o $(OBJDIR_LINUX_RELEASE)/wxpamserver.o

clean_linux_release: 
	rm -f $(OBJ_LINUX_RELEASE) $(OUT_LINUX_RELEASE)
	rm -rf ../bin
	rm -rf $(OBJDIR_LINUX_RELEASE)

.PHONY: before_linux_release after_linux_release clean_linux_release

