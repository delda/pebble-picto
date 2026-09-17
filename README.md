# pebble-picto

A minimalist Picto-inspired Pebble watchface for **Gabbro (Pebble Round 2)**.
The black hand shows minutes; the orbiting black dot shows hours.

## Building & running

```sh
pebble build                          # builds the Gabbro watchface
pebble install --emulator gabbro      # install on the Gabbro emulator
pebble install --phone <ip>           # install to a paired phone
```

## Target platform

This watchface targets **Gabbro** only, whose 180 × 180 circular display is
used by the face geometry.

## Project layout

```
src/c/           C source for the watchapp
src/pkjs/        PebbleKit JS (phone-side) source, if any
worker_src/c/    Background worker source, if any
resources/       Images, fonts, and other bundled resources
package.json     Project metadata (UUID, platforms, resources, message keys)
wscript          Build rules — usually no need to edit
```

The project is already configured as a watchface.

## Documentation

Full SDK docs, tutorials, and API reference: <https://developer.repebble.com>
