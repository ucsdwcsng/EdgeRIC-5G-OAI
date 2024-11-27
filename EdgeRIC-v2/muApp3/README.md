# Run muApp3 Monitoring using Grafana
## Run Prometheus docker
```bash
cd docker/prometheus
docker compose up -d
```
## Run Grafana docker
```bash
cd docker/grafana
docker compose up -d
```
## Create and Connect monitoring network
```bash
docker network create monitoring
docker network connect monitoring prometheus
docker network connect monitoring grafana
```


