SUMMARY = "Open source MQTT implementation"
DESCRIPTION = "Mosquitto is an open source (Eclipse licensed) message broker \
that implements the MQ Telemetry Transport protocol version 3.1, 3.1.1 and \
5, providing both an MQTT broker and several command-line clients. MQTT \
provides a lightweight method of carrying out messaging using a \
publish/subscribe model. "
HOMEPAGE = "http://mosquitto.org/"

FILES_${PN}_append = "${bindir}/mosquitto_pub \
               ${bindir}/mosquitto_sub \
               ${bindir}/mosquitto_rr \
"
