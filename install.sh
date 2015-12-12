#!/bin/sh

INC_DIR=/usr/include
LIB_DIR=/usr/lib

cp -v bin/libmset.so "${LIB_DIR}"
cp -v src/m_set.h "${INC_DIR}"

