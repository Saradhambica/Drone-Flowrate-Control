# Drone Flowrate Control System

## Description
This project implements real-time flowrate calculation for agricultural drone spraying based on ground speed and spray parameters.

## Key Features
- Real-time flowrate calculation
- Speed-based spray control
- Prevents over-application at low speeds
- Designed for UAV spraying systems

## Formula Used
Flowrate (L/min) = 60 × Swath Width × Spray Density × Speed

## Technical Details
- Ground speed obtained from AHRS
- Application rate converted from L/acre to L/m²
- Minimum speed threshold to avoid spraying when stationary

## Context
This logic was developed and tested within an ArduPilot SITL environment as part of drone spray system simulation.

## Future Improvements
- Parameter tuning via configuration
- Integration with real hardware sensors
- Logging and telemetry output
