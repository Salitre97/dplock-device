# dplock-device
Embedded code development for the Senior Design project DPLOCK device.

## Development Notes

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
  

