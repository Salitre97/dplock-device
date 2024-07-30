# dplock-device
Embedded code development for the Senior Design project DPLOCK device.

## Prerequisites
- **Docker:** Docker is required to build and run the project in a containerized environment. Install from website [Docker's official website](https://www.docker.com/get-started).

## Usingg Docker
If not on VSCode:
### 1. Build and Run the Docker Image

```bash
docker build -t dplock-container .

docker run -it -v /path/to/your/local/dplock:/dplock dplock-container
``` 

## Development Notes

**Tasks to Create with RTOS:**
- GPIOs (Will log data from peripherals)
- BLE ( Will scan for clients and transmit data when not in Deep Sleep Mode)

1. **Key ESP-IDF API References:** 
[ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/index.html)
   - **Event Loop Library** -> How to handle events
   - **Sleep Modes** -> Enable and disable low power mode
   - **GPIO & RTC GPIO** -> Set directions & pull modes of registers
   - **Bluetooth Low Energy** -> How to handle GAP, GATT Define, GATT Server, GATT Client, BluFi
     - **Client** -> Allows connection and data reading from other BLE devices (e.g., smartphones)
     - **Event Handling** -> Handling data receptions, incoming connections, and other BLE activities
   - **Error Handling** -> Check for situations such as invalid states
   - **Watchdogs** -> For reliability and fault tolerance
   - **Motor Control PWM (MCPWM)** -> For DC servo motor

**BLE Examples For Reference**
[gatt_client_walkthrough](https://github.com/espressif/esp-idf/blob/v5.3/examples/bluetooth/bluedroid/ble/gatt_security_client/tutorial/Gatt_Security_Client_Example_Walkthrough.md)
- Enable hardware interrupts to allow for mcu to wake and collecg data from peripherals.
- ESP32 will act as a GATT Server for mininmal power consumption and will wait for client (smartphien) to initiate BLE connection.
- AES-128 enccryption allows for secure data transmission
- Review ESP-IDF ble examples for implementation.



2. **Key FreeRTOS API References:**
   [FreeRTOS](https://www.freertos.org/Documentation/RTOS_book.html)

**Flow Chart**
  


