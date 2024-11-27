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



