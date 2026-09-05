# create docker network before running any of these 3 docker containers.
docker network create mynetwork1 

docker build -f DockerContainer_MS_SQL.dockerfile -t my-mssql-image .

docker run -d --platform linux/amd64 --name sql-server --network mynetwork1 -e "ACCEPT_EULA=Y" -e "SA_PASSWORD=YourStrong@Passw0rd" -p 1433:1433 -m 4g  my-mssql-image

# find the network on which the sql-server container is running.
docker inspect --format "{{json .NetworkSettings.Networks}}" sql-server

# find the containers of a network.
docker network inspect mynetwork1

docker build -f DockerContainer_Tomcat.dockerfile  -t my-tomcat-image .

docker run -d --name tomcat-container --network mynetwork1 -p 8081:8081 my-tomcat-image

docker cp sample.war tomcat-container:/usr/local/tomcat/webapps/

http://localhost:8081/sample/

# Build Image of Node.js Container
docker build -f DockerContainer_NodeJS.dockerfile -t nodejs-image .

# Run Container from Node.js Image
docker run -d --name nodejs-container --network mynetwork1 -p 3000:3000 nodejs-image

# Execute Shell inside the container 'nodejs-container'
docker exec -it nodejs-container sh

