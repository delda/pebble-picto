# pebble-picto

A minimalist Picto-inspired Pebble watchface for **Gabbro (Pebble Round 2)**
and **Chalk (Pebble Time Round)**.
The black hand shows minutes; the orbiting black dot shows hours.

## Building & running

```sh
pebble build                          # builds Gabbro and Chalk watchfaces
pebble install --emulator chalk       # install on the Chalk emulator
pebble install --phone <ip>           # install to a paired phone
```

## Target platforms

This watchface targets **Gabbro** and **Chalk**. Each platform has a dedicated
profile for face dimensions and colours while sharing the same rendering code.

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
