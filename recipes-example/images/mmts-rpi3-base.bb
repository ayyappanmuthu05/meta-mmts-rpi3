SUMMARY = "image recipe"
DESCRIPTION = "Recipe created for mmts-rpi3"

require recipes-sato/images/core-image-sato.bb

IMAGE_INSTALL_append = " mosquitto sample-mqtt-client connman connman-client"
