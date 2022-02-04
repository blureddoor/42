#!/bin/bash
docker stop mi_web
docker run --rm --env AUTOINDEX=on --name mi_web -d -p 443:443 -p 80:80 mi_web
