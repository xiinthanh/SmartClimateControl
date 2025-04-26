#ifndef APP_CONFIG_H
#define APP_CONFIG_H

/* ---------------- Pin map ---------------- */
#define PIN_STATUS       48  // on‑board LED (heartbeat)

#define PIN_HEATER_A      6  // D3
#define PIN_HEATER_B      7  // D4
#define PIN_COOLER_A      8  // D5
#define PIN_COOLER_B      9  // D6
#define PIN_HUM_A        10  // D7
#define PIN_HUM_B        17  // D8


/* ---------------- Thresholds ---------------- */
#define T_SAFE_MIN       20        // °C
#define T_SAFE_MAX       25
#define T_WARM_MIN       25
#define T_WARM_MAX       28 
#define H_LOW_MAX        70        // %RH

/* ---------------- Tick helper ---------------- */
#define TICKS(ms)   ((ms) / 10)

#endif // APP_CONFIG_H