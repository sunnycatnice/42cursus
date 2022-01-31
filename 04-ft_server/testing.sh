docker build . -t ft_server
echo build ok
docker run --name ft_server -d -p 80:80 -p 443:443 ft_server:latest
echo run ok
docker exec -it ft_server bash
echo exec ok
