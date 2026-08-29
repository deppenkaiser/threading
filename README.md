# threading – Thread- und Synchronisations-Helfer

Dünner C-Wrapper um POSIX-Threads und Synchronisationsprimitiven.

## Umfang

- **Threads**: `threading_thread_create` / `threading_thread_join`
- **Sleep**: `threading_thread_sleep` mit wählbarer Zeitauflösung
  (`TTR_NANO/MICRO/MILLI/SECOND`)
- **Kritische Sektionen**: positix-Mutex als `threading_critical_section`
  (initialize/destroy/lock/unlock)
- **Semaphore**: POSIX-Semaphore als `threading_semaphore`
  (`initialize`, `increment`, `wait` mit Timeout, destroy) sowie benannte
  Semaphore (`open` mit `exclusive`/Wert, `close`, `unlink`)

## Nutzung

```c
#include <threading/threading.h>

void* worker(void* user_data) { /* ... */ return NULL; }

pthread_t t = threading_thread_create(worker, NULL);
threading_thread_join(t);
```

## Abhängigkeiten

- `string` (String-/Pfad-Helfer)

## Build

```bash
cmake -S . -B build
cmake --build build
```

In ein Projekt einbinden: `add_subdirectory(../../libraries/threading …)`,
Einbindung des Headers über den Include-Pfad `<threading/threading.h>`.

## Wiki

Dokumentation: [threading – Thread- und Synchronisations-Helfer](https://czybor.i234.me/wiki/sw-module/threading/) (Quartz-Wiki)