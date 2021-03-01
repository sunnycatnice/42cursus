# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmangola <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/21 16:22:49 by dmangola          #+#    #+#              #
#    Updated: 2021/02/21 16:22:50 by dmangola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Installa l'immagine di base
# Selezione l'immagine da Dockerhub - Debian Buster
FROM debian:buster

# Crea una variabile d'ambiente (ENV) per switchare l'autoindex on/off
ENV AUTOINDEX on

# Aggiorna lista pacchetti e installa i servizi, -y = auto "Yes"
RUN apt-get update && apt-get install -y \
	nginx \
	mariadb-server \
	php-fpm \
	php-mysql \
	php-mbstring \
	wget \
	&& rm -rf /var/lib/apt/lists/*

# NGINX run & copy
RUN     echo "daemon off;" >> /etc/nginx/nginx.conf && \ 
        rm var/www/html/index.nginx-debian.html
COPY	srcs/nginx/*.conf /tmp/

# PHPMyAdmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-english.tar.gz && \
    tar -xzvf phpMyAdmin-5.0.2-english.tar.gz && \
    mv phpMyAdmin-5.0.2-english/ /var/www/html/phpmyadmin && \
    rm -rf phpMyAdmin-5.0.2-english.tar.gz
COPY srcs/phpmyadmin/config.inc.php /var/www/html/phpmyadmin

# WordPress
RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xzvf latest.tar.gz && \
    mv wordpress /var/www/html/ && \
    rm -rf latest.tar.gz
COPY srcs/wordpress/wp-config.php /var/www/html/wordpress

# SSL certificato
RUN mkdir ~/mkcert && cd ~/mkcert && \
	wget https://github.com/FiloSottile/mkcert/releases/download/v1.4.1/mkcert-v1.4.1-linux-amd64 && \
	mv mkcert-v1.4.1-linux-amd64 mkcert && chmod +x mkcert && \
	./mkcert -install && ./mkcert localhost

# Dare a NGINX diritti di user e group sui file della pagina
RUN	chown -R www-data:www-data /var/www/html/*

# Copia tutti gli script dalla cartella srcs alla cartella ./ di Debian
COPY srcs/*.sh ./

EXPOSE 80 443

CMD bash start.sh