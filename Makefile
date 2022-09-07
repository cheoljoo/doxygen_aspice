export DOXYASPICE_HOME ?= $(shell pwd)
DOXYASPICE_VER = $(shell cat doxyaspice.ver)

all: parallel

parallel:
	#make lib
	#make api
	#rm -rf ${DOXYASPICE_HOME}/build
	#make common
	make generate

lib:
ifeq (,$(wildcard ./lib/CGA_RDL))
	git clone https://github.com/1434cga/CGA_RDL.git lib/CGA_RDL
else
	cd lib/CGA_RDL; git pull
	cd ../..
endif

api:
ifeq (,$(wildcard ./api))
	git clone http://mod.lge.com/hub/dcmpf/dcmpf-api.git -b ${DOXYASPICE_VER} api
else
	cd api; git pull
endif

doc:
ifeq (,$(wildcard ./doc))
	git clone http://mod.lge.com/hub/dcmpf/dcmpf-doc.git -b ${DOXYASPICE_VER} doc
else
	cd doc; git pull
endif

common:
	bash run.sh
	bash ${DOXYASPICE_HOME}/tools/concat.sh
	make generate

generate:
	#rm -rf ${DOXYASPICE_HOME}/gen/src
	#mkdir -p ${DOXYASPICE_HOME}/gen/src
	#bash ${DOXYASPICE_HOME}/tools/run-gen.sh
	python3 ${DOXYASPICE_HOME}/tools/gen-code.py --key=test --input=${DOXYASPICE_HOME}/template/doc/doc.md.stcI --output=${DOXYASPICE_HOME}/gen/
	#make output

output:
	mkdir -p ${DOXYASPICE_HOME}/out/dcmpfapi/src ${DOXYASPICE_HOME}/out/dcmpfapi/inc/dcmpf ${DOXYASPICE_HOME}/out/dcmpfapi/template
	rm -rf ${DOXYASPICE_HOME}/out/dcmpfapi/src/*
	rm -rf ${DOXYASPICE_HOME}/out/dcmpfapi/inc/dcmpf/*
	rm -rf ${DOXYASPICE_HOME}/out/dcmpfapi/template/*
	cp -rf ${DOXYASPICE_HOME}/api/* ${DOXYASPICE_HOME}/out/dcmpfapi/inc/dcmpf
	cp -rf ${DOXYASPICE_HOME}/gen/* ${DOXYASPICE_HOME}/out/dcmpfapi/
	cp -rf ${DOXYASPICE_HOME}/gen/* ${DOXYASPICE_HOME}/out/dcmpfapi/template/
	bash ${DOXYASPICE_HOME}/tools/remove-doxygen-output.sh
	mkdir -p ${DOXYASPICE_HOME}/out/dcmpfapi/template/inc/dcmpf
	cp -rf ${DOXYASPICE_HOME}/out/dcmpfapi/inc/dcmpf/* ${DOXYASPICE_HOME}/out/dcmpfapi/template/inc/dcmpf


collect:
	rm -rf ${DOXYASPICE_HOME}/tmp/*
	bash ${DOXYASPICE_HOME}/tools/get-sub-folder.sh

clean:
	rm -rf build api doc gen out __pycache__ lib tmp
