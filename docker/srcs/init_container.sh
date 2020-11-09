service mysql start

#config Access
chown -R www-data /var/www/*
chmod -R 755 /var/www/*

#generate website folder
mkdir /var/www/mi_web_42 && touch /var/www/mi_web_42/index.php
echo "<?php phpinfo(); ?>" >> /var/www/mi_web_42/index.php

#ssl
mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/mi_web_42.pem -keyout /etc/nginx/ssl/mi_web_42.key -subj "/C=ES/ST=Madrid/L=Madrid/O=42/OU=lvintila/CN=certified_lvintila_mi_web_42"

#config nginx
mv ./tmp/nginx-conf /etc/nginx/sites-available/mi_web_42
ln -s /etc/nginx/sites-available/mi_web_42 /etc/nginx/sites-enabled/mi_web_42
rm -rf /etc/nginx/sites-enabled/default

#config mysql
echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

#phpmyadmin
mkdir /var/www/mi_web_42/phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.xz
tar -xvf phpMyAdmin-5.0.4-all-languages.tar.xz --strip-components 1 -C /var/www/mi_web_42/phpmyadmin
mv ./tmp/phpmyadmin.inc.php /var/www/mi_web_42/phpmyadmin/config.inc.php

#wordpress
cd /tmp/
wget -c https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
mv wordpress/ /var/www/mi_web_42
mv /tmp/wp-config.php /var/www/mi_web_42/wordpress/wp-config.php

service php7.3-fpm start
service nginx start
bash
