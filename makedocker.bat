docker rm compiler
docker build -t ece466 .
docker run --rm --name compiler -d -i -t -v %cd%:/app ece466
docker exec -it compiler bash