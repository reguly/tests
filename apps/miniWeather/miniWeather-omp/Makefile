#===============================================================================
# User Options
#===============================================================================

# Compiler can be set below, or via environment variable
CC        = mpicxx
OPTIMIZE  = yes
DEBUG     = no
DEVICE    = cpu

#===============================================================================
# Program name & source code list
#===============================================================================

program = main

source = main.cpp timing.cpp

obj = $(source:.cpp=.o)

#===============================================================================
# Sets Flags
#===============================================================================

# Standard Flags
CFLAGS := $(EXTRA_CFLAGS) -std=c++14 -Wall \
	-DNX=4000 \
       	-DNZ=2000 \
	-DSIM_TIME=1 \
	-DDATA_SPEC=DATA_SPEC_THERMAL

# Linker Flags
LDFLAGS = 

# Debug Flags
ifeq ($(DEBUG),yes)
  CFLAGS += -g -DDEBUG
  LDFLAGS  += -g
endif


# Optimization Flags
ifeq ($(OPTIMIZE),yes)
  CFLAGS += -O3 -march=native -ffast-math -funroll-loops
ifdef TEST_ZMM
  CFLAGS += -qopt-zmm-usage=high
endif
endif

ifeq ($(DEVICE),gpu)
  CFLAGS +=-cxx=icpx -qnextgen -fiopenmp -fopenmp-targets=spir64 -D__STRICT_ANSI__
else
  CFLAGS += -qopenmp #-cxx=icpx
endif
#===============================================================================
# Targets to Build
#===============================================================================

$(program): $(obj) Makefile
	gcc ../../energy.c -c -o energy.o
	$(CC) $(CFLAGS) $(obj) energy.o -o $@ $(LDFLAGS)

%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(program) $(obj)

run: $(program)
	mpiexec -n 1 ./$(program)

