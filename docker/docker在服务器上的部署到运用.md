[TOC]

# docker在服务器上的部署到运用

通过尚硅谷的[docker三小时速通视频](https://www.bilibili.com/video/BV14WtLeDEit)学习了

## docker安装

在阿里云服务器上进行docker的安装

```docker
# 移除旧版本docker
sudo yum remove docker \
                  docker-client \
                  docker-client-latest \
                  docker-common \
                  docker-latest \
                  docker-latest-logrotate \
                  docker-logrotate \
                  docker-engine

# 配置docker yum源。
sudo yum install -y yum-utils
sudo yum-config-manager \
--add-repo \
http://mirrors.aliyun.com/docker-ce/linux/centos/docker-ce.repo


# 安装 最新 docker
sudo yum install -y docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin

# 启动& 开机启动docker； enable + start 二合一
systemctl enable docker --now

# 配置加速
sudo mkdir -p /etc/docker
sudo tee /etc/docker/daemon.json <<-'EOF'
{
    "registry-mirrors": [
        "https://mirror.ccs.tencentyun.com",
        "https://docker.m.daocloud.io"
    ]
}
EOF
sudo systemctl daemon-reload
sudo systemctl restart docker
```

* 学习过程中发现现在的Cent OS stream 9用的时新的包管理器dnf(也兼容yum)所以安装docker时还是得依照[docker官方文档]([CentOS | Docker Docs](https://docs.docker.com/engine/install/centos/))来安装

## 基础命令

对docker中的一些基础命令进行了熟悉

```docker
#查看运行中的容器
docker ps
#查看所有容器
docker ps -a
#搜索镜像
docker search nginx
#下载镜像
docker pull nginx
#下载指定版本镜像
docker pull nginx:1.26.0
#查看所有镜像
docker images
#删除指定id的镜像
docker rmi e784f4560448


#运行一个新容器
docker run nginx
#停止容器
docker stop keen_blackwell
#启动容器
docker start 592
#重启容器
docker restart 592
#查看容器资源占用情况
docker stats 592
#查看容器日志
docker logs 592
#删除指定容器
docker rm 592
#强制删除指定容器
docker rm -f 592
#后台启动容器
docker run -d --name mynginx nginx
#后台启动并暴露端口
docker run -d --name mynginx -p 80:80 nginx
#进入容器内部
docker exec -it mynginx /bin/bash

#提交容器变化打成一个新的镜像
docker commit -m "update index.html" mynginx mynginx:v1.0
#保存镜像为指定文件
docker save -o mynginx.tar mynginx:v1.0
#删除多个镜像
docker rmi bde7d154a67f 94543a6c1aef e784f4560448
#加载镜像
docker load -i mynginx.tar 

#登录 docker hub
docker login
#重新给镜像打标签
docker tag mynginx:v1.0 leifengyang/mynginx:v1.0
#推送镜像
docker push leifengyang/mynginx:v1.0
```

## 存储

同时也学会了docker容器存储的两种方式:

* 目录挂载： `-v /app/nghtml:/usr/share/nginx/html`

* 卷映射：`-v ngconf:/etc/nginx`

  示例如下

  ```dockerfile
  docker run -d -p 99:80 \
  -v /app/nghtml:/usr/share/nginx/html \
  -v ngconf:/etc/nginx \
  --name app03 \
  nginx
  ```

## 网络

  * 学会了创建自定义网络来实现主机名作为稳定域名访问,当然<u>由于没有学Redis有关知识所以没有用Redis作为例子去学习</u>,仅尝试了在服务器两容器间进行互相通过域名访问

    ```docker
    #自定义网络
    docker network create mynet
    #主节点
    docker run -d -p 6379:6379 \
    -v /app/rd1:/bitnami/redis/data \
    -e REDIS_REPLICATION_MODE=master \
    -e REDIS_PASSWORD=123456 \
    --network mynet --name redis01 \
    bitnami/redis
    
    #从节点
    docker run -d -p 6380:6379 \
    -v /app/rd2:/bitnami/redis/data \
    -e REDIS_REPLICATION_MODE=slave \
    -e REDIS_MASTER_HOST=redis01 \
    -e REDIS_MASTER_PORT_NUMBER=6379 \
    -e REDIS_MASTER_PASSWORD=123456 \
    -e REDIS_PASSWORD=123456 \
    --network mynet --name redis02 \
    bitnami/redis
    ```

## Docker Compose(批量管理容器)

    学习了通过命令行及编写yaml文件的形式启动特定配置的容器
    
    ### 命令式管理
    
    ```docker
    #创建网络
    docker network create blog
    
    #启动mysql
    docker run -d -p 3306:3306 \
    -e MYSQL_ROOT_PASSWORD=123456 \
    -e MYSQL_DATABASE=wordpress \
    -v mysql-data:/var/lib/mysql \
    -v /app/myconf:/etc/mysql/conf.d \
    --restart always --name mysql \
    --network blog \
    mysql:8.0
    
    #启动wordpress
    docker run -d -p 8080:80 \
    -e WORDPRESS_DB_HOST=mysql \
    -e WORDPRESS_DB_USER=root \
    -e WORDPRESS_DB_PASSWORD=123456 \
    -e WORDPRESS_DB_NAME=wordpress \
    -v wordpress:/var/www/html \
    --restart always --name wordpress-app \
    --network blog \
    wordpress:latest
    ```
    
    ### yaml管理
    
    * 六个顶层元素顶格写,重点写services,configs和secrets一般写的比较少

```docker
name: myblog
services:
  mysql:
    container_name: mysql
    image: mysql:8.0
    ports:
      - "3306:3306"
    environment:
      - MYSQL_ROOT_PASSWORD=123456
      - MYSQL_DATABASE=wordpress
    volumes:
      - mysql-data:/var/lib/mysql
      - /app/myconf:/etc/mysql/conf.d
    restart: always
    networks:
      - blog

  wordpress:
    image: wordpress
    ports:
      - "8080:80"
    environment:
      WORDPRESS_DB_HOST: mysql
      WORDPRESS_DB_USER: root
      WORDPRESS_DB_PASSWORD: 123456
      WORDPRESS_DB_NAME: wordpress
    volumes:
      - wordpress:/var/www/html
    restart: always
    networks:
      - blog
    depends_on:
      - mysql

volumes:
  mysql-data:
  wordpress:

networks:
  blog:
```

* yaml的编写不能使用制表符,格式也要严格与文档里对齐

## Dockerfile(打包成镜像)

以java为例

```dockerfile
FROM openjdk:17

LABEL author=leifengyang

COPY app.jar /app.jar

EXPOSE 8080

ENTRYPOINT ["java","-jar","/app.jar"]
```

dockerfile所有指令见文档([Dockerfile reference | Docker Docs](https://docs.docker.com/reference/dockerfile/))****

1. dockerfile常见指令 作用
2. FROM 指定镜像基础环境
3. RUN  运行自定义命令
4. CMD 容器启动命令或参数
5. LABEL 自定义标签
6. EXPOSE 指定暴露端口
7. ENV  环境变量
8. ADD  添加文件到镜像
9. COPY 复制文件到镜像
10. ENTRYPOINT 容器固定启动命令
11. VOLUME 数据卷
12. USER 指定用户和用户组
13. WORKDIR 指定默认工作目录
14. ARG  指定构建参数

然后用dockerfile构建(build)镜像

```
docker build -f Dockerfile -t myjavaapp:v1.0
```

或者直接看最新的[docker容器化文档](https://docs.docker.com/guides/)跟着操作一下就会了

## 没了

