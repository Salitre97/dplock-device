# official ESP-IDF Docker image
FROM espressif/idf:v5.3

WORKDIR /app

COPY . /app

ENV IDF_PATH /opt/esp/idf

RUN . $IDF_PATH/export.sh && idf.py set-target esp32s3

# Run when the container starts
CMD ["idf.py", "build"]

