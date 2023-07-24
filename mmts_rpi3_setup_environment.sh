#!/bin/bash

export MMTSBUILD="../../build"
#echo $BUILD
source ../poky/oe-init-build-env $MMTSBUILD
bitbake-layers add-layer ../sources/meta-openembedded/meta-oe
bitbake-layers add-layer ../sources/meta-openembedded/meta-python
bitbake-layers add-layer ../sources/meta-openembedded/meta-multimedia
bitbake-layers add-layer ../sources/meta-openembedded/meta-networking
bitbake-layers add-layer ../sources/meta-openembedded/meta-gnome
bitbake-layers add-layer ../sources/meta-openembedded/meta-xfce
bitbake-layers add-layer ../sources/meta-raspberrypi
bitbake-layers add-layer ../sources/meta-mmts-rpi3
#cd $MMTSBUILD
