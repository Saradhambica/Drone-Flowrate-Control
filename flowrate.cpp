// Real-time flowrate calculation for agricultural drone spraying
// Developed and tested in ArduPilot SITL environment

void Copter::calculate_flowrate()
{
    uint32_t now = AP_HAL::millis();

    // Run calculation every 100 ms
    if (now - last_flowrate_calc_ms < 100) {
        return;
    }
    last_flowrate_calc_ms = now;

    // Agricultural spray parameters
    const float APPLICATION_RATE_L_PER_ACRE = 20.0f;  // L/acre
    const float SWATH_WIDTH_M = 3.0f;                 // meters
    const float MIN_SPRAY_SPEED = 2.0f;               // m/s

    // Stop spraying if motors are not armed
    if (!motors->armed()) {
        flowrate_lpm = 0.0f;
        return;
    }

    // Get current ground speed (m/s)
    float ground_speed_ms = ahrs.groundspeed();

    // Prevent spraying at low speeds (avoids over-application)
    if (ground_speed_ms < MIN_SPRAY_SPEED) {
        flowrate_lpm = 0.0f;
        return;
    }

    // Convert application rate from L/acre to L/m²
    float spray_density_l_per_m2 = APPLICATION_RATE_L_PER_ACRE / 4047.0f;

    // Flowrate formula:
    // Flow (L/min) = 60 × swath width × spray density × speed
    flowrate_lpm = 60.0f * SWATH_WIDTH_M * spray_density_l_per_m2 * ground_speed_ms;
}
