ARG VERSION=latest
FROM connectedhomeip/chip-build-esp32:${VERSION}

RUN set -x \
    && apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -fy --no-install-recommends \
    ninja-build=1.10.0-1build1 \
    git=1:2.25.1-1ubuntu3.2 \
    libgcrypt20-dev=1.8.5-5ubuntu1.1 \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/ \
    && : # last line

WORKDIR /opt/espressif/qemu
# Setup QEMU emulator for ESP32 platform
RUN set -x \
    && git clone --depth 1 -b esp-develop-20210826 https://github.com/espressif/qemu.git ../qemu-src \
    && ../qemu-src/configure --target-list=xtensa-softmmu --enable-debug --enable-sanitizers --disable-strip --disable-user --disable-capstone --disable-vnc --disable-sdl --disable-gtk \
    && make -j8 \
    && : # last line

ENV QEMU_ESP32_DIR=/opt/espressif/qemu
ENV QEMU_ESP32=/opt/espressif/qemu/xtensa-softmmu/qemu-system-xtensa
