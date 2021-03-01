docker build -t ft_server . 
docker run --name ft_server -d -p 80:80 -p 443:443 ft_server
docker exec -it ft_server bash