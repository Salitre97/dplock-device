FROM ubuntu:22.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y \
      apt-utils \
      bison \
      bzip2 \
      ca-certificates \
      ccache \
      check \
      curl \
      flex \
      git \
      git-lfs \
      gperf \
      lcov \
      libbsd-dev \
      libffi-dev \
      libglib2.0-0 \
      libncurses-dev \
      libpixman-1-0 \
      libsdl2-2.0-0 \
      libslirp0 \
      libusb-1.0-0-dev \
      make \
      ninja-build \
      python3 \
      python3-venv \
      ruby \
      unzip \
      wget \
      xz-utils \
      zip \
    && apt-get autoremove -y \
    && rm -rf /var/lib/apt/lists/* \
    && update-alternatives --install /usr/bin/python python /usr/bin/python3 10

ARG IDF_CLONE_URL=https://github.com/espressif/esp-idf.git
ARG IDF_CLONE_BRANCH_OR_TAG=master
ARG IDF_CHECKOUT_REF=
ARG IDF_CLONE_SHALLOW=
ARG IDF_CLONE_SHALLOW_DEPTH=1
ARG IDF_INSTALL_TARGETS=all

ENV IDF_PATH=/opt/esp/idf
ENV IDF_TOOLS_PATH=/opt/esp

RUN if [ "$IDF_INSTALL_TARGETS" = "all" ]; then \
        apt-get update \
        && apt-get install -y build-essential \
        && apt-get autoremove -y \
        && rm -rf /var/lib/apt/lists/* ; \
    fi

RUN git clone --recursive \
      ${IDF_CLONE_SHALLOW:+--depth=${IDF_CLONE_SHALLOW_DEPTH} --shallow-submodules} \
      ${IDF_CLONE_BRANCH_OR_TAG:+-b $IDF_CLONE_BRANCH_OR_TAG} \
      $IDF_CLONE_URL $IDF_PATH \
    && git config --system --add safe.directory $IDF_PATH \
    && if [ -n "$IDF_CHECKOUT_REF" ]; then \
        cd $IDF_PATH && \
        if [ -n "$IDF_CLONE_SHALLOW" ]; then \
            git fetch origin --depth=${IDF_CLONE_SHALLOW_DEPTH} --recurse-submodules ${IDF_CHECKOUT_REF}; \
        fi && \
        git checkout $IDF_CHECKOUT_REF && \
        git submodule update --init --recursive; \
    fi

RUN update-ca-certificates --fresh \
    && $IDF_PATH/tools/idf_tools.py --non-interactive install required --targets=${IDF_INSTALL_TARGETS} \
    && $IDF_PATH/tools/idf_tools.py --non-interactive install qemu* --targets=${IDF_INSTALL_TARGETS} \
    && $IDF_PATH/tools/idf_tools.py --non-interactive install cmake \
    && $IDF_PATH/tools/idf_tools.py --non-interactive install-python-env \
    && rm -rf $IDF_TOOLS_PATH/dist

COPY entrypoint.sh /opt/esp/entrypoint.sh

RUN chmod +x /opt/esp/entrypoint.sh

ENTRYPOINT [ "/opt/esp/entrypoint.sh" ]
CMD [ "/bin/bash" ]
