# Run muApp3 Monitoring using Grafana
## Run Prometheus docker
```bash
cd docker/prometheus
docker compose up -d
```
Check https://localhost:9090 to see whether Prometheus can run correctly.
## Run Grafana docker
```bash
cd docker/grafana
docker compose up -d
```
Check the website https://localhost:3000 to see whether Grafana can run correctly.
## Create and Connect monitoring network
```bash
docker network create monitoring
docker network connect monitoring prometheus
docker network connect monitoring grafana
```
## Monitor the Network
1. Login to grafana using username: admin password: admin
2. Import the json file to create the dashboard.
3. Use the side menu to connect data source
   - In Data source section choose add new data source and then choose Prometheus
   - In the connection field write http://prometheus:9090
   - Set Scrape interval to 25ms and Query timeout to 100ms
   - Save and test Data Source
``` bash
python3 muApp3_monitor_grafana.py
```
If you encounter any issues regarding monitoring, feel free to send an email to yij040@ucsd.edu




