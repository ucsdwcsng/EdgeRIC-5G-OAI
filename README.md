# Edgeric for OAI

- This project integrates EdgeRIC with OpenAirInterface (OAI).
- We developed a wrapper that enables seamless embedding of EdgeRIC into OAI.
- In addition, we have consolidated and refined the Docker configurations to simplify deployment and testing.
- Check our website for More information about EdgeRIC https://edgeric.github.io/

This repository is under development 
## Prerequisites
``` bash
sudo apt install libzmq3-dev
sudo apt install protobuf-compiler #version should be 3.21.12. you can download it form https://github.com/protocolbuffers/protobuf/tree/v3.21.12 
```
## Run 5G core
``` bash
cd oai-cn5g
docker compose up -d
```
## Build 5G RAN
``` bash
cd openairinterface5g/cmake_targets
./build_oai -I
./build_oai -I -w USRP  #if you need over-the-air mode
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
docker exec -it rfsim5g-oai-nr-ue iperf3 -s -B 10.0.0.x
docker exec -it oai-ext-dn iperf3 -u -t 86400 -i 1 -fk -B 192.168.70.135 -b 20M -c 10.0.0.x
```
If you encounter any issues regarding setting up simulation, feel free to send an email to qiz066@ucsd.edu or create an issue(preferred)

## Run 5G RAN Over the air
```bash
cd openairinterface5g/cmake_targets/ran_build/build
sudo ./nr-softmodem -O ../../../targets/PROJECTS/GENERIC-NR-5GC/CONF/gnb.sa.band78.fr1.162PRB.2x2.usrpn300.conf --sa --usrp-tx-thread-config 1
```
### Set up mobile phone
```bash
sudo ./program_uicc --adm 12345678 --imsi 001010000000001 --isdn 00000001 --acc 0001 --key fec86ba6eb707ed08905757b1bb44b8f --opc C42449363BBAD02B66D16BC975D77CC1 -spn "OpenAirInterface" --authenticate
#Use apn name "oai"
```
If you encounter any issues regarding setting up over-the-air mode, feel free to send an email to qiz066@ucsd.edu or create an issue(preferred)
