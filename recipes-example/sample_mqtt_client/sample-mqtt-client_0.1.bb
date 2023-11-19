DESCRIPTION = "Sample mqtt application"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
SRC_URI = "file://sample_mqtt_client.c"

S = "${WORKDIR}"
DEPENDS = "mosquitto"
do_compile(){
	${CC} sample_mqtt_client.c ${LDFLAGS} -o sample_mqtt_client -lmosquitto
}

do_install(){
	install -d ${D}${bindir}
	install -m 0755 sample_mqtt_client ${D}${bindir}
}
