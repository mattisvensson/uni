# Dockerfile
FROM php:8.3-apache
WORKDIR /var/www/html
COPY ./src/ ./
EXPOSE 80

# Bauen
docker build -t myphp:1 .

# Starten
docker run -d --name web -p 8080:80 myphp:1

# Öffnen
http://localhost:8080
