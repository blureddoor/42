FROM 	debian:10

LABEL 	mantainer "lvintila lvintila@student.42madrid.com"

RUN		apt-get update && apt-get install; \
		apt-get upgrade; \
		apt-get install -y procps curl \
		nginx \
		mariadb-server \
		wget \
		php7.3-fpm php7.3-common php7.3-mysql php7.3-gmp php7.3-curl php7.3-intl php7.3-mbstring php7.3-xmlrpc \
		php7.3-gd php7.3-xml php7.3-cli php7.3-zip php7.3-soap php7.3-imap \
		vim;

COPY	./srcs/init_container.sh ./
COPY 	./srcs/nginx-conf ./tmp/nginx-conf
COPY	./srcs/phpmyadmin.inc.php ./tmp/phpmyadmin.inc.php
COPY 	./srcs/wp-config.php ./tmp/wp-config.php

CMD		bash init_container.sh

EXPOSE 	80 443
