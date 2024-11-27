## Run 5G core
``` bash
cd oai-cn5g
docker compose up -d
```
## Run 5G RAN
``` bash
cd openairinterface5g/cmake_targets
./build_oai -I
./build_oai --gNB
```
