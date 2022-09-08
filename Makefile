export DOXYASPICE_HOME ?= $(shell pwd)
DOXYASPICE_VER = $(shell cat doxyaspice.ver)

all: generate

generate:
	cd ${DOXYASPICE_HOME}/doxygen; doxygen
	cd ${DOXYASPICE_HOME}/tools; cp ../doxygen/DOXYGEN_OUTPUT/perlmod/DoxyDocs.pm . -f
	cd ${DOXYASPICE_HOME}/tools; perl doxy2cga.pl default.GV > b.log
	cd ${DOXYASPICE_HOME}/tools; cp -f DB4python.data D.py
	python3 ${DOXYASPICE_HOME}/tools/gen-code.py --key=test --input=${DOXYASPICE_HOME}/template/doc/doc.md.stcI --output=${DOXYASPICE_HOME}/gen/

clean:
	rm -rf gen doxygen/DOXYGEN_OUTPUT tools/DB4python.data tools/DoxyDocs.pm tools/default.GV

lib:
ifeq (,$(wildcard ./lib/CGA_RDL))
	git clone https://github.com/1434cga/CGA_RDL.git lib/CGA_RDL
else
	cd lib/CGA_RDL; git pull
	cd ../..
endif


