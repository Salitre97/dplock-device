# Dockerfile
ARG USER=dplock
ARG UID=1000

FROM espressif/idf:v5.3

ARG UID
ARG USER 

# Create Non-Root User
RUN addgroup --gid ${UID} ${USER} \
    && adduser --disabled-password --gecos "" --ingroup ${USER} --uid ${UID} ${USER} \
    && usermod --append --groups dialout,plugdev ${USER}

# Set up the ESP-IDF environment for the non-root user
RUN echo "source /opt/esp/idf/export.sh" >> /home/${USER}/.bashrc \
    && chown ${UID}:${UID} /home/${USER}/.bashrc

USER ${USER}
WORKDIR /app
