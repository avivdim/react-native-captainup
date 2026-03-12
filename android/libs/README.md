# CaptainUp SDK JARs

Place the following JAR files in this directory (download from the CaptainUp SDK distribution):

- `framework.jar`
- `slf4j-api-1.7.24.jar`
- `nv-websocket-client-2.2.jar`
- `bolts-tasks-1.3.0.jar`

These are referenced automatically via `fileTree(dir: 'libs', include: ['*.jar'])` in `build.gradle`.
