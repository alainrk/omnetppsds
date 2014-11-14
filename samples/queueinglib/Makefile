#
# OMNeT++/OMNEST Makefile for libqueueinglib
#
# This file was generated with the command:
#  opp_makemake -f --deep --make-so -O out -pQUEUEING
#

# Name of target to be created (-o option)
TARGET = libqueueinglib$(SHARED_LIB_SUFFIX)

# C++ include paths (with -I)
INCLUDE_PATH = -I. -Itemplates -Itemplates/queueing

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/Clone.o \
    $O/ResourceBasedQueue.o \
    $O/Delay.o \
    $O/SelectionStrategies.o \
    $O/Source.o \
    $O/Server.o \
    $O/Join.o \
    $O/PassiveQueue.o \
    $O/MyQueue.o \
    $O/Job.o \
    $O/MultigateQueue.o \
    $O/Merge.o \
    $O/Classifier.o \
    $O/JobList.o \
    $O/Router.o \
    $O/Allocate.o \
    $O/Deallocate.o \
    $O/ResourcePool.o \
    $O/Queue.o \
    $O/Fork.o \
    $O/Sink.o \
    $O/Job_m.o

# Message files
MSGFILES = \
    Job.msg

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppenvir$D $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS) -DQUEUEING_EXPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH) -PQUEUEING_API

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating shared library: $@
	$(Q)$(SHLIB_LD) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS) $(LDFLAGS)
	$(Q)$(SHLIB_POSTPROCESS) $O/$(TARGET)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f queueinglib queueinglib.exe libqueueinglib.so libqueueinglib.a libqueueinglib.dll libqueueinglib.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f templates/*_m.cc templates/*_m.h
	$(Q)-rm -f templates/queueing/*_m.cc templates/queueing/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc templates/*.cc templates/queueing/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/Allocate.o: Allocate.cc \
	Allocate.h \
	IResourcePool.h \
	Job.h \
	Job_m.h \
	QueueingDefs.h \
	ResourcePool.h
$O/Classifier.o: Classifier.cc \
	Classifier.h \
	Job.h \
	Job_m.h \
	QueueingDefs.h
$O/Clone.o: Clone.cc \
	Clone.h \
	Job.h \
	Job_m.h \
	QueueingDefs.h
$O/Deallocate.o: Deallocate.cc \
	Deallocate.h \
	IResourcePool.h \
	QueueingDefs.h \
	ResourcePool.h
$O/Delay.o: Delay.cc \
	Delay.h \
	Job.h \
	Job_m.h \
	QueueingDefs.h
$O/Fork.o: Fork.cc \
	Fork.h \
	Job.h \
	Job_m.h \
	QueueingDefs.h
$O/Job.o: Job.cc \
	Job.h \
	JobList.h \
	Job_m.h \
	QueueingDefs.h
$O/JobList.o: JobList.cc \
	Job.h \
	JobList.h \
	Job_m.h \
	QueueingDefs.h
$O/Job_m.o: Job_m.cc \
	Job_m.h \
	QueueingDefs.h
$O/Join.o: Join.cc \
	Job.h \
	Job_m.h \
	Join.h \
	QueueingDefs.h
$O/Merge.o: Merge.cc \
	Merge.h \
	QueueingDefs.h
$O/MultigateQueue.o: MultigateQueue.cc \
	Job.h \
	Job_m.h \
	MultigateQueue.h \
	QueueingDefs.h
$O/MyQueue.o: MyQueue.cc \
	Job.h \
	Job_m.h \
	MyQueue.h \
	QueueingDefs.h
$O/PassiveQueue.o: PassiveQueue.cc \
	IPassiveQueue.h \
	Job.h \
	Job_m.h \
	PassiveQueue.h \
	QueueingDefs.h \
	SelectionStrategies.h
$O/Queue.o: Queue.cc \
	Job.h \
	Job_m.h \
	Queue.h \
	QueueingDefs.h
$O/ResourceBasedQueue.o: ResourceBasedQueue.cc \
	IResourcePool.h \
	Job.h \
	Job_m.h \
	QueueingDefs.h \
	ResourceBasedQueue.h
$O/ResourcePool.o: ResourcePool.cc \
	IResourcePool.h \
	QueueingDefs.h \
	ResourcePool.h
$O/Router.o: Router.cc \
	QueueingDefs.h \
	Router.h
$O/SelectionStrategies.o: SelectionStrategies.cc \
	IPassiveQueue.h \
	IServer.h \
	PassiveQueue.h \
	QueueingDefs.h \
	SelectionStrategies.h \
	Server.h
$O/Server.o: Server.cc \
	IPassiveQueue.h \
	IServer.h \
	Job.h \
	Job_m.h \
	QueueingDefs.h \
	SelectionStrategies.h \
	Server.h
$O/Sink.o: Sink.cc \
	Job.h \
	Job_m.h \
	QueueingDefs.h \
	Sink.h
$O/Source.o: Source.cc \
	Job.h \
	Job_m.h \
	QueueingDefs.h \
	Source.h

