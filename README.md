## Run 5G core
``` bash
cd oai-cn5g
docker compose up -d
```
## Build 5G RAN
``` bash
cd openairinterface5g/cmake_targets
./build_oai -I
./build_oai --gNB
```
## Run 5G RAN simulation 
``` bash
cd openairinterface5g/cmake_targets/ran_build/build
sudo ./nr-softmodem -O ../../../targets/PROJECTS/GENERIC-NR-5GC/CONF/gnb.sa.band78.fr1.106PRB.usrpb210.conf --rfsim -E --sa
```
## Run 5G UE simulation
``` bash
cd ue_sim
docker compose up -d
```
### For runnig trafic
``` bash
docker exec -it rfsim5g-oai-nr-ue ifconfig
docker exec -it rfsim5g-oai-nr-ue iperf3 -s -B 10.0.0.6
docker exec -it oai-ext-dn iperf3 -u -t 86400 -i 1 -fk -B 192.168.70.135 -b 20M -c 10.0.0.8
```
